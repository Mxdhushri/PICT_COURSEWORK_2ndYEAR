class Records:
    def __init__(self):
        # l->no of elements of the list
        self.l = int(input("Enter the number of elements in the list :"))
        # empty list
        self.list = []

    # function for getting input to the list
    def Getvalue(self):
        for i in range(self.l):
            ele = int(input("Enter the element :"))
            if (ele not in self.list):  # to avoid duplicate entries
                self.list.append(ele)

    # function for print the list
    def PrintList(self):
        print("Your entered list is :", self.list)

    # function for linear search
    def LinearSearch(self):
        key = int(input("Enter the element you are searching :"))
        for j in range(self.l):
            if (self.list[j] == key):
                index = j
                print(key, "is present in the list at index", index)
                break
        else:
            print(key, "is not present in the list.")

    # function for sentinel search
    def SentinelSearch(self):
        key = int(input("Enter the element you are searching :"))
        self.list.append(key)
        i = 0
        while (self.list[i] != key):
            i = i + 1
            index = i
        if (index == self.l):
            print(key, "is not present in the list.")
        else:
            print(key, "is present in the list at index", index)

    def BinarySearch(self):
        start = 0
        end = self.l - 1

        key = int(input("Enter the element you are searching :"))
        self.list.sort()
        print("Sorted list is :", self.list)
        while (start <= end):
                mid = (start + end) // 2
                if (key == self.list[mid]):
                    index = mid
                    print(key, "is present at index", index, "in the sorted list",self.list)
                    break
                elif (key > self.list[mid]):
                    start = mid + 1
                elif (key < self.list[mid]):
                    end = mid - 1
        else:
            print(key, "is not present in the list")

    def fibonaccisearch(self):
        key=int(input("Enter the entry you are searching for :"))
        self.list.sort()
        check=0
        if self.l==1:
            if(key==self.list):
                print(key,"is present in the record at the index ",0)
            else:
                print(key,"is not present in the record.")
        else:
            fm2=0
            fm1=1
            fm=fm1+fm2

            while(fm<self.l ):
                fm2=fm1
                fm1=fm
                fm=fm1+fm2

            offset=-1
            i=0
            while(fm1>=1 and i<self.l):

                if(key==self.list[i]):
                    index=i
                    check=1
                    break;

                elif (key>self.list[i]):
                    fm=fm1
                    fm1=fm2
                    fm2=fm-fm1
                    offset=i
                    i = min((fm2 + offset), self.l)
                elif(key<self.list[i]):
                    fm=fm2
                    fm1=fm1-fm2
                    fm2=fm-fm1
                    i = min((fm2 + offset), self.l)

            else:
                if(self.list[-1]!=key):
                    print(key ,"is not present in the record")
                elif(self.list[-1]==key):
                    print(key,"is present in record at the index ",-1)

        if(check==1):
                print(key,"is present at the index ",index,"in the record")

presentStulist = Records()

while (True):
    print("MENU")
    print("1.To entering entries to the record :")
    print("2.To display the record :")
    print("3.To search an entry in the record by linear search:")
    print("4.To search an element by using binary search : ")
    print("5.To search an entry in the record by sentinel search :")
    print("6.To search an entry in the record by fibonacci search :")
    print("7.EXIT")
    choice = int(input("Enter your choice :"))
    if (choice == 1):
        presentStulist.Getvalue()
    elif (choice == 2):
        presentStulist.PrintList()
    elif (choice == 3):
        presentStulist.LinearSearch()
    elif (choice == 4):
        presentStulist.BinarySearch()
    elif (choice == 5):
        presentStulist.SentinelSearch()
    elif (choice == 6):
         presentStulist.fibonaccisearch()
    elif (choice == 7):
        print("EXIT")
        break
    else:
        print("Enter the valid choice !!!")


def LinearSearch(arr, key, count):
    found = False
    position = -1
    index = 0
    while index < count and found == False:
        if key == arr[index]:
            found = True
            position = index
            break
        index += 1
    return position


def SentinalSearch(arr, x, n):
    last = arr[n - 1]
    arr[n - 1] = x
    i = 0
    while arr[i] != x:
        i += 1
    arr[n - 1] = last
    if i < n - 1 or x == arr[n - 1]:
        print(x, "is present at index", i)
    else:
        print("Not Found")


# def BinarySearch(arr, x, count):
#     low = 1
#     high = count
#     while low <= high:
#         mid = (low + high)//2
#         if arr[mid] == x:
#             return mid
#         elif arr[mid] < x:
#             low = mid + 1
#         else:
#             high = mid - 1
#     return -1

# Using Recursion
def BinarySearch(arr, x, count, low, high):
    if low <= high:
        mid = (low + high) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] < x:
            low = mid + 1
            return BinarySearch(arr, x, count, low, high)
        else:
            high = mid - 1
            return BinarySearch(arr, x, count, low, high)
    else:
        return -1


def Fibo(n):
    if n == 0:
        return 0
    elif n == 1 or n == 2:
        return 1
    else:
        return Fibo(n - 1) + Fibo(n - 2)


def FibonacciSearch(arr, x, N):
    m = 0
    while Fibo(m) < N:
        m += 1
    offset = -1
    while Fibo(m) > 1:
        mid = min(offset + Fibo(m - 2), N - 1)
        if x > arr[mid]:
            m -= 1
            offset = mid
        elif x < arr[mid]:
            m -= 2
        else:
            return mid
    if Fibo(m - 1) == False and arr[offset + 1] == x:
        return offset + 1
    return -1


# count = int(input("Enter Number of students"))
students = []
count = int(input("Enter number of students : "))
while count:
    t = int(input())
    if t in students:
        print(t, "Student already exist. Continue ")
    else:
        students.append(t)
        count -= 1
print(students)
num = int(input("Enter a roll number to find : "))

print("""
Please select your sort type:
1. Linear search
2. Sentinel Search
3. Binary Search
4.Fibonacci Search
0. Exit
""")

while True:
    sec = input("Select your section : ")
    if sec == '1':
        p = LinearSearch(students, num, count)
        if p == -1:
            print("Not found")
        else:
            print("Student", num, "found at positon", p)
    elif sec == '2':
        SentinalSearch(students, num, count)
    elif sec == '3':
        students.sort()
        low = 1
        high = count
        p = BinarySearch(students, num, count, low, high)
        if p == -1:
            print("Not found")
        else:
            print("Student", num, "found at positon", p)
    elif sec == '4':
        students.sort()
        p = FibonacciSearch(students, num, count)
        if p == -1:
            print("Not found")
        else:
            print("Student", num, "found at positon", p)
    elif sec == '0':
        print("Thank You, Programme Endded")
        break
    else:
        print("Enter vaild selection")



