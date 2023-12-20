from array import array

N = 6

x = array ('i', [1, 3, 3, 5, 7, 7])
cnt = array ('i', [0] *  N)

def LTCountSorted (a, lt_count, n):
    count = 0
    for i in range (0, n):
        if (i == 0 or a[i] != last_value):
            last_count = count
            last_value = a[i]
        lt_count[i] = last_count
        count += 1

def main ():
    LTCountSorted (x, cnt, N)

    for i in range (0,N):
        print("%d %d" % (x[i], cnt[i]))



# scritp start-up

if (__name__ == "__main__"):
    main()