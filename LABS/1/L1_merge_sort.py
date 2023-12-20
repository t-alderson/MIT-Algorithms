import random
import numpy as np
import time


I = 80000

x = np.array([0]*I)

def merge(A, p, q, r):
	"""Merge two sorted sublists/subarrays to a larger sorted sublist/subarray.

	Arguments:
	A -- a list/array containing the sublists/subarrays to be merged
	p -- index of the beginning of the first sublist/subarray
	q -- index of the end of the first sublist/subarray;
	the second sublist/subarray starts at index q+1
	r -- index of the end of the second sublist/subarray
	"""
	# Copy the left and right sublists/subarrays.
	# If A is a list, slicing creates a copy.
	if type(A) is list:
		left = A[p: q+1]
		right = A[q+1: r+1]
	# Otherwise a is a np.array, so create a copy with list().
	else:
		left = list(A[p: q+1])
		right = list(A[q+1: r+1])

	i = 0    # index into left sublist/subarray
	j = 0    # index into right sublist/subarray
	k = p    # index into a[p: r+1]

	# Combine the two sorted sublists/subarrays by inserting into A
	# the lesser exposed element of the two sublists/subarrays.
	while i < len(left) and j < len(right):
		if left[i] <= right[j]:
			A[k] = left[i]
			i += 1
		else:
			A[k] = right[j]
			j += 1
		k += 1

	# After going through the left or right sublist/subarray, copy the 
	# remainder of the other to the end of the list/array.
	if i < len(left):  # copy remainder of left
		A[k: r+1] = left[i:]
	if j < len(right):  # copy remainder of right
		A[k: r+1] = right[j:]


def merge_sort(A, p=0, r=None):
	"""Sort the elements in the sublist/subarray a[p:r+1].

	Arguments:
	A -- a list/array containing the sublist/subarray to be merged
	p -- index of the beginning of the sublist/subarray (default = 0)
	r -- index of the end of the sublist/subarray (default = None)
	"""
	# If r is not given, set to the index of the last element of the list/array.
	if r is None:
		r = len(A) - 1
	if p >= r:  # 0 or 1 element?
		return
	q = (p+r) // 2            # midpoint of A[p: r]
	merge_sort(A, p, q)       # recursively sort A[p: q]
	merge_sort(A, q + 1, r)   # recursively sort A[q+1: r]
	merge(A, p, q, r)         # merge A[p: q] and A[q+1: r] into A[p: r]


# Testing
if __name__ == "__main__":
	
	for i in range(1, (I-1)):
		x[i] = random.randint(0,3*I)

	# print("Lab 1 - merge sort:\n")
	# print("List Prier to Sorting")
	# print(*N, sep="\t")

	t0 = time.time()
	merge_sort(x)
	t1 = time.time()

	print("Time:", (t1-t0))


	# print("List after to Sorting")
	# print(*N, sep = "\t")

