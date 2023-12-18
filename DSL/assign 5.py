def insertionSort(arr):
    for i in range(1,len(arr)):
        key=arr[i]
        j=i-1
        while j>=0 and key<arr[j]:
            arr[j+1]=arr[j]
            j -=1
        arr[j+1] = key

def shellSort(arr,n):
    gap=n//2
    while gap>0:
        for i in range(gap,n):
            temp=arr[i]
            j=i
            while j>= gap and arr[j-gap]>temp:
                arr[j]=arr[j-gap]
                j -= gap
            arr[j]=temp
        gap//=2

n=int(input("Enter total numbers = "))
arr = []
for i in range(0,n):
    arr.append(int(input("Enter number : ")))
insertionSort(arr)
lst=[]
for i in range(len(arr)):
    lst.append(arr[i])
print("Sorted array is by insertion sort: ",lst)
shellSort(arr,n)
print("Sorted array is by shell sort: ",arr)

def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
        print("Pass",i," : ",arr)


def shellSort(arr, n):
    gap = n // 2
    c = 1
    while gap > 0:
        j = gap
        while j < n:
            i = j - gap
            while i >= 0:
                if arr[i + gap] > arr[i]:
                    break
                else:
                    arr[i + gap], arr[i] = arr[i], arr[i + gap]
                    print("Pass", c, " : ", arr)
                i = i - gap
                c += 1
            j += 1
        gap = gap // 2

subjects = int(input("Enter number of subjects : "))
print("Enter second year percentage : ")
per = []
for i in range(subjects):
    per.append(input())

print("List of percentage is : ", per)

while(True):
    print("""
    Enter You Choice :
    1. Insertion Sort
    2. Shell Sort
    0. To Exit
    """)
    ch = input("Choice : ")
    if ch == '1':
        insertionSort(per)
        print(per)
    elif ch == '2':
        shellSort(per, len(per))
        print(per)
    elif ch == '0':
        print("Thank You")
        break
    else:
        print("Entered Wrong choice, please enter correct choice")
        break

