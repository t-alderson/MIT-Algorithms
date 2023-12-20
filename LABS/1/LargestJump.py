import time

list = [6, 20, 16, 2, 8, 6, 8, 4]

def insertion_sort(A, n):
	"""Sort a list or numpy array.

	Argument:
	A -- a list or numpy array
	n -- length of A
	"""
	# Traverse the list or array from index 1 to n-1.
	for i in range(1, n):
		key = A[i]

		# Insert A[i] into the sorted subarray a[0:i].
		# Compare stored key with the already sorted values to its left.
		# Move each item one position to the right until we find the 
		# position for the key or fall off the left end of the list or array.
		j = i - 1
		while j >= 0 and A[j] > key:
			A[j + 1] = A[j]
			j -= 1

		# Insert key at the correct position in the list or array.
		A[j + 1] = key



def largestJump(list, n):

    jump = 0
    for i in range(0, n-1):
        j = i + 1
        temp_jump = list[j] - list[i]

        if temp_jump > jump:
            jump = temp_jump
    return jump




if __name__ == "__main__":

    t0 = time.time()	
    list.sort()
    t1 = time.time()

    print("largest jump:", largestJump(list, len(list)))

    print("Time:", (t1-t0))

