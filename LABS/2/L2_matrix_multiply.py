import numpy as np
import time

N = 800

a = np.zeros((N,N))
b = np.zeros((N,N))
c = np.zeros((N,N))


def matrix_multipy():
    for i in range(0, N):
        for j in range(0, N):
            for k in range(0, N):
                c[i][j] = c[i][j] + a[i][k] * b[k][j]


def main():
    
    t0 = time.time()
    matrix_multipy()
    t1 = time.time()
    print("Problem Size =", N)
    print("Time required = ", t1-t0)

if __name__ == "__main__":
    main()