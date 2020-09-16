arr = list(map(int, input("Enter the array").split()))
for i in range(1, len(arr)):
    el = arr[i]
    j = i - 1
    while(j >= 0 and el < arr[j]):
        arr[j + 1] = arr[j]
        j -= 1
    arr[j + 1] = el
print(arr)

