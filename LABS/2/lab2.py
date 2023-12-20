import numpy as np
import sys

N = 5

a = np.zeros((N,N))
p = np.zeros((N,N))
x = np.zeros((N,N))
temp = np.zeros((N))


def fillMatrixColumns(f):
    for i in range(0, len(f)):
        for j in range(0, len(f)):
            f[i][j] = j+1

def createPMatrix(p, col1, col2):
    # swap all elements in col1 with elements in col2
    # in p[][] matrix
    for i in range(len(p)):
        if(i == col1):
            p[col2][i] = 1
        elif(i == col2):
            p[col1][i] = 1
        else:
            p[i][i] = 1
 
def showMatrix(s):
    for i in range(0, len(s)):
        for j in range(0, len(s)):
            print(s[i][j], end =" ")
        print()
     
def main():
    if(len(sys.argv) < 3):
        print("ERROR: not enough arguments")
        return
    col1 = int(sys.argv[1])
    col2 = int(sys.argv[2])
    if((col1 >= N or col1 < 0) or (col2 >= N or col2 < 0)):
         print("ERROR: Column 1 or 2 input is out of bounds")
         return
    if(col1 == col2):
        print("ERROR: Column 1 is equal to column 2")
        return
    fillMatrixColumns(a)
    print("Before Swap")
    showMatrix(a)
    print()
    print("After Swap")
    createPMatrix(p, col1, col2)
    x = np.matmul(a, p)
    showMatrix(x)
    

    

                
        

if __name__ == "__main__":

    main()
    
