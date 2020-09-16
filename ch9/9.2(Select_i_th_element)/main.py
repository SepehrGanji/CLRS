import random
import time

def randomized_partition(A, l, r):
    random.seed(time.time())
    pivot = random.randrange(l, r)
    piv_el = A[pivot]
    A[0], A[pivot] = A[pivot], A[0]
    i = 1
    for j in range(1, r):
        if(A[j] <= piv_el):
            A[i],A[j] = A[j],A[i]
            i += 1
    i -= 1
    A[0], A[i] = A[i], A[0]
    return i

def randomized_select(A, l, r, ith):
    if(l == r - 1):
        return A[l]
    m = randomized_partition(A, l, r)
    k = m - l + 1
    if(k == ith):
        return A[m]
    elif(ith < k):
        return randomized_select(A, l, m, ith)
    else:
        return randomized_select(A, m + 1, r, ith - k)

arr = list(map(int, input("Enter the array: ").split()))
ith = int(input("Enter i: "))
ith_el = randomized_select(arr, 0, len(arr), ith)
print("The " + str(ith) + "th elemnt of array is : " + str(ith_el))
