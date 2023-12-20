import random
import time

N = 80000

A = [0]*N

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


# Testing
if __name__ == "__main__":

	

	for i in range(1, (N-1)):
		A[i] = random.randint(0,3*N)

	
	# print("Lab 1 - insetion sort:\n")
	# print("List Prier to Sorting")
	# print(*A, sep="\t")

	t0 = time.time()
	insertion_sort(A, N)
	t1 = time.time()


	# print("List after to Sorting")
	# print(*A, sep = "\t")
	
	
	print("Time:", (t1-t0))

