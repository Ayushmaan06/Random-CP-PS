import sys

# Function to perform Depth-First Search (DFS)
def dfs(node, parent, adj_list, subtree_sizes):
    size = 1
    for neighbor in adj_list[node]:
        if neighbor != parent:
            size += dfs(neighbor, node, adj_list, subtree_sizes)
    subtree_sizes[node] = size
    return size

# Function to check if it's possible to remove k edges such that each component has size at least x
def is_feasible(x, k, subtree_sizes):
    components = 0
    for size in subtree_sizes:
        components += size // x
    return components >= k

# Binary search for the maximum possible size x
def binary_search_max_size(k, subtree_sizes):
    left, right = 1, max(subtree_sizes)
    while left < right:
        mid = (left + right + 1) // 2
        if is_feasible(mid, k, subtree_sizes):
            left = mid
        else:
            right = mid - 1
    return left

# Main function to process input and output
def main():
    t = int(input().strip())  # Number of test cases
    for _ in range(t):
        n, k = map(int, input().split())  # Number of vertices, edges to be removed
        adj_list = [[] for _ in range(n)]
        for _ in range(n - 1):
            v, u = map(int, input().split())  # Edge information
            adj_list[v - 1].append(u - 1)
            adj_list[u - 1].append(v - 1)
        
        subtree_sizes = [0] * n
        dfs(0, -1, adj_list, subtree_sizes)  # Perform DFS to compute subtree sizes
        
        max_size = binary_search_max_size(k, subtree_sizes)
        print(max_size)

if __name__ == "__main__":
    main()
