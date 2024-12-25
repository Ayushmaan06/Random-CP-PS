# Function to find minimum number of operations required to increase median
def min_operations_to_increase_median(n, arr):
    arr.sort()  # Sort the array
    median_index = (n + 1) // 2  # Calculate the index of the current median
    
    # Iterate from the current median to the end of the array
    operations = 0
    for i in range(median_index, n):
        if arr[i] <= arr[median_index - 1]:
            operations += arr[median_index - 1] - arr[i] + 1  # Increment to make it greater than the current median
    
    return operations+1

# Input number of test cases
t = int(input())

# Iterate through each test case
for _ in range(t):
    # Input length of the array and the array itself
    n = int(input())
    arr = list(map(int, input().split()))
    
    # Output the minimum number of operations required to increase the median
    print(min_operations_to_increase_median(n, arr))
