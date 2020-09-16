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

arr = list(map(int, input('Enter the array: ').split()))
idx = int(input("Enter the idx: "))
new_arr = max_heapify(arr, idx, len(arr))
print(new_arr)
