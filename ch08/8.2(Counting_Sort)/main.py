arr = list(map(int, input("Enter the array: ").split()))
up = int(input("Enter upper bound: "))
up += 1
c = []
for i in range(0, up):
    c.append(0)
for i in range(0, len(arr)):
    c[arr[i]] += 1
for i in range(1, up):
    c[i] += c[i-1]
b = []
for i in range(0, len(arr)):
    b.append(0)
for i in range(len(arr) - 1, -1, -1):
    b[c[arr[i]]-1] = arr[i]
    c[arr[i]] -= 1
print(b)
