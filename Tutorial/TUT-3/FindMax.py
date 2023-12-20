



def FindMax(A, start, end):
    if(start == end):
        return A(start)
    
    midpoint = (end + start)/2
    left_max = FindMax(A, start, midpoint)
    right_max = FindMax(A, midpoint + 1, end)
    if (left_max > right_max):
        return left_max
    else:
        return right_max
    




if (__name__ == "__main__"):

    FindMax()