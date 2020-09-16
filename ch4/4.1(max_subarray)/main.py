from math import inf as INFINITY

def max_subarray(A, low, high):
    if(low + 1 == high):
        return (low, low, A[low])
    mid = (low + high) // 2
    left_low, left_high, left_sum = max_subarray(A, low, mid)
    right_low, right_high, right_sum = max_subarray(A, mid, high)
    cross_low, cross_high, cross_sum = max_crossing_subarray(A, low, mid, high)
    if(left_sum >= right_sum and left_sum >= cross_sum):
        return(left_low, left_high, left_sum)
    elif(right_sum >= left_sum and right_sum >= cross_sum):
        return(right_low, right_high, right_sum)
    else:
        return(cross_low, cross_high, cross_sum)

def max_crossing_subarray(A, low, mid, high):
    left_sum = -INFINITY
    left_idx = mid - 1
    sum = 0
    for i in range(mid - 1, low - 1, -1):
        sum += A[i]
        if(sum > left_sum):
            left_sum = sum
            left_idx = i
    right_sum = -INFINITY
    right_idx = mid
    sum = 0
    for i in range(mid, high):
        sum += A[i]
        if(sum > right_sum):
            right_sum = sum
            right_idx = i
    return(left_idx, right_idx + 1, left_sum + right_sum)

arr = list(map(int, input().split()))
result = max_subarray(arr, 0, len(arr))
print("Start index: ", result[0])
print("End index(included): ", result[1] - 1)
print("Max sum: ", result[2])
