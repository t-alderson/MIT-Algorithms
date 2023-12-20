from array import array

N = 6

x = array ('i', [7, 5, 3, 1, 7, 3])
cnt = array ('i', [0] *  N)

def LTCount (a, lt_count, n):
    for i in range (0,n):
        lt_count[i] = 0
        for j in range (0,n):
            if (i != j):
                if (a[j] < a[i]):
                    lt_count[i] = lt_count[i] + 1                 


def main ():
    LTCount (x, cnt, N)

    for i in range (0,N):
        print("%d %d" % (x[i], cnt[i]))



# scritp start-up

if (__name__ == "__main__"):
    main()