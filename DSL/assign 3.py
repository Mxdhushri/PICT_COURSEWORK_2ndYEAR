class Matrix:
    def __init__(self):
        self.rows=0
        self.col=0
        self.matrix=[]

    def insertmatrix(self):
        self.rows=int(input("enter the no of rows:"))
        self.col=int(input("enter the number of columns:"))
        for i in range(self.rows):
            r=[]
            for j in range(self.col):
                ele=int(input("enter number:"))
                r.append(ele)
            self.matrix.append(r)
            print(self.matrix)

    def displaymatrix(self):
        for i in range(self.rows):
            for j in range(self.col):
                print(self.matrix[i][j], end=" ")
            print("|")

    def transpose(self):
        trans=Matrix()
        trans.rows=self.rows
        trans.col=self.col
        for i in range(self.rows):
            row=[]
            for j in range(self.col):
                row.append(self.matrix[j][i])
            trans.matrix.append(row)
        return trans

    def add(self,b):
        result=Matrix()
        result.rows=self.rows
        result.col=self.col
        for i in range(self.rows):
            r=[]
            for j in range(self.col):
                r.append(self.matrix[i][j]+b.matrix[i][j])
            result.matrix.append(r)
        return result

    def mul(self, b):
        result = Matrix()
        result.rows = self.rows
        result.col = b.col
        for i in range(self.rows):
            r = []
            sum=0
            for j in range(b.col):
                for k in range(b.rows):
                    sum += self.matrix[i][k]*b.matrix[k][j]
                r.append(sum)
                sum=0
            result.matrix.append(r)
        return result

while (True):
    print("*" * 10 + "Menu" + "*" * 10)
    print("""1 . Matrix Addition
2. Matrix Multiplication
3. Matrix Transpose
-1. EXIT """)
    choice = int(input("Enter number for the operation to be performed: "))
    m1 = Matrix()
    m2 = Matrix()
    m1.insertmatrix()
    m2.insertmatrix()
    m1.displaymatrix()
    m2.displaymatrix()
    if choice == 1:
        print('*' * 10)
        print("Addition")
        c = m1.add(m2)
        c.displaymatrix()

    if choice == 2:
        print('*' * 10)
        print("multiplication")
        d = m1.mul(m2)
        d.displaymatrix()

    if choice == 3:
        print('*' * 10)
        print("Transpose of Matrix 2")
        e = m2.transpose()
        e.displaymatrix()

    if choice == -1:
        print("Exit")
        break

'''m1=Matrix()
m2=Matrix()
m1.insertmatrix()
m2.insertmatrix()
m1.displaymatrix()
m2.displaymatrix()
e=m2.transpose()
e.displaymatrix()
c=m1.add(m2)
c.displaymatrix()
d=m1.mul(m2)
d.displaymatrix()'''









