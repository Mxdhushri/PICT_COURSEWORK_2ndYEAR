class Student:
    def partition(self,array,low,high):
        pivot = array[high]
        i = low - 1
        for j in range(low, high):
            if array[j] <= pivot:
                i = i + 1
                (array[i], array[j]) = (array[j], array[i])
        (array[i + 1], array[high]) = (array[high], array[i + 1])
        return i + 1

    def quickSort(self,array,low,high):
        if low < high:
            pi = self.partition(array,low,high)
            self.quickSort(array,low,pi - 1)
            self.quickSort(array,pi + 1, high)

S=Student()

while(True):
    n=int(input("\nEnter total number of studets : "))
    print("\nEnter percentages : ")
    arr=[]
    for i in range(n):
        arr.append(float(input(f"Student {i+1} : ")))
    print("\nPercentage List : ",arr)
    S.quickSort(arr,0,n-1)
    print("\nSorted Percentage List : ",arr)
    c=input("\nDo you want to repeat ? Y/N  ")
    if c=='Y':
        continue
    else:
        break