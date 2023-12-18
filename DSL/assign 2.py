str = input("enter the string:")
class Str_operations:
    def __init__(self,str):
        self.str=str

    def list(self):
        t=" "
        temp=""
        self.list=[]
        for i in self.str:
            if i==t:
                self.list.append(temp)
                temp=""
            else:
                temp=temp+i
        self.list.append(temp)
        print("the given list is :",self.list)

    def count(self):
        count=0
        for i in self.list:
            count=count+1
        print("number of elements in list:",count)

    def long_word(self):  #use len keyword
        max_len = 0
        for ele in self.list:
            if len(ele)>max_len:
                max_len=len(ele)
                self.a=ele
        print("longest word is:",self.a)

    def occurance(self):
        count=0
        n=input("enter character:")
        list=[]
        for i in self.str:
            if i!=" ":
                list.append(i)
        for i in list:
            if i==n:
                count=count+1
        print("number of times",n,"has occured is",count)

    def palindrome(self):
        s=input("enter word to check if it is a palindrome or not:")
        if s==s[::-1]:
            print("given word is palindrome")
        else:
            print("given word is not palindrome")

    def sub_str(self):
        count=0
        self.w=input("enter substring:")
        for i in self.list:
            if self.w==i:
                count=count+1
        print("number of times",self.w,"is present in string is:",count)

    def index(self):
        A=[]
        a=self.w[0]
        for i in range(len(self.str)): #we use i in range as len is parameter
            if self.w[0]==self.str[i]:
                break
        print("index of first occurance of",self.w[0],"in the string is",i)

str=Str_operations(str)
str.list()
str.count()
str.long_word()
str.occurance()
str.palindrome()
str.sub_str()
str.index()







