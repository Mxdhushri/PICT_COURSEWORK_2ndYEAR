class Sports:
    def __init__(self):
        self.sportsList = []
        self.listLength = 0
        self.acceptList()

    def acceptList(self):
        """Function that checks for the repeat inputs and
        creates a list which will have set properties from the data entered
        """
        self.listLength = int(input("Enter the length of the list "))
        for i in range(self.listLength):
            temp = input(f"Enter the element at {i+1} position ")
            while temp in self.sportsList:
                temp = input(f"Element already present in the list\nPlease re-enter the element at {i+1} position ")
            self.sportsList.append(temp)

def union(sport1, sport2):
    unionList = sport1.sportsList.copy()
    for i in range(sport2.listLength):
        if sport2.sportsList[i] not in unionList:
            unionList.append(sport2.sportsList[i])
    return unionList

def intersection(sport1, sport2):
    intersectionList = []
    for i in sport1.sportsList:
        if i in sport2.sportsList:
            intersectionList.append(i)
    return intersectionList

def substraction(list1, list2):
    substractionList = list1.copy()
    for i in list1:
        if i in list2:
            substractionList.remove(i)
    return substractionList

print("*"*15)
print("Enter data for Cricket")
cricket = Sports()

print("*"*15)
print("Enter data for football")
football = Sports()

print("*"*15)
print("Enter data for badminton")
badminton = Sports()

print("*"*15)

# cricket_union_badminton = cricket and badminton
print("List of students who play both cricket and badminton = ",
      intersection(cricket, badminton))

# cricket_union_badminton - cricket_intersection_badminton = either cricket or football but not both
print("List of students who play either cricket or badminton but not both",
      substraction(union(cricket, badminton), intersection(cricket, badminton)))

# football - football_Intersection_cricket - football_intersection_badminton = neither badminton nor cricket
print("List of students who play neither cricket nor badminton ",  substraction(substraction(
    football.sportsList, intersection(football, cricket)), intersection(football, badminton)))

# cricket_intersection_football - badminton
print("List of students who play cricket and football but not badminton ", substraction(
    union(cricket, football),  badminton.sportsList))





