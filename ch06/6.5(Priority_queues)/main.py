def heap_maximum(A):
    return A[0]

def max_heapify(A, i, size):
    r = 2 * (i+1)
    l = r - 1
    largest = i
    if(l < size and A[l] > A[i]):
        largest = l
    if(r < size and A[r] > A[largest]):
        largest = r
    if(largest != i):
        A[i], A[largest] = A[largest], A[i]
        return max_heapify(A, largest, size)
    else:
        return A

def heap_extract_max(A):
    if(len(A) < 1):
        print("Heap UnderFlow")
        exit(-1)
    max = A[0]
    A[0] = A[len(A)-1]
    A.pop()
    max_heapify(A, 0, len(A))
    return max

def heap_increase_key(A, i, key):
    if(key < A[i]):
        print("New key is smaller than current key")
        return
    A[i] = key
    while(i > 0 and A[int((i+1)/2)-1] < A[i]):
        A[int((i+1)/2)-1], A[i] = A[i], A[int((i+1)/2)-1]
        i = int((i+1)/2)-1

def heap_insert(A, key):
    A.append(key)
    heap_increase_key(A, len(A) - 1, key)

arr = [15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, -5]
size = len(arr)
start_idx = int(size / 2) - 1
#building the max heap
for i in range(start_idx, -1, -1):
    arr = max_heapify(arr, i, size)
#testing
print(arr)
print(heap_maximum(arr))
heap_extract_max(arr)
print(heap_maximum(arr))
heap_extract_max(arr)
print(arr)
heap_increase_key(arr, len(arr) - 1, 10)
print(arr)
heap_insert(arr, 8)
print(arr)
heap_insert(arr, 66)
print(heap_maximum(arr))
