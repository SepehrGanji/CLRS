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
#building the max heap
for i in range(start_idx, -1, -1):
    arr = max_heapify(arr, i, size)
#building the sorted array
sorted_array = []
heap_size = len(arr)
for i in range(len(arr) - 1, 0, -1):
    sorted_array.append(arr[0])
    arr[0], arr[i] = arr[i], arr[0]
    heap_size -= 1
    max_heapify(arr, 0, heap_size)
sorted_array.append(arr[0])
sorted_array.reverse()
print(sorted_array)
