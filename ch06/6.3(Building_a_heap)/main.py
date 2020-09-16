def max_heapify(arr, i, size):
    r = 2 * (i+1)
    l = r - 1
    largest = i
    if(l < size and arr[l] > arr[i]):
        largest = l
    if(r < size and arr[r] > arr[largest]):
        largest = r
    if(largest != i):
        arr[i], arr[largest] = arr[largest], arr[i]
        return max_heapify(arr, largest, size)
    else:
        return arr
arr = list(map(int, input("Enter the array: ").split()))
size = len(arr)
start_idx = int(size / 2) - 1
for i in range(start_idx, -1, -1):
    arr = max_heapify(arr, i, size)
print(arr)
