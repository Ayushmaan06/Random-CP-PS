import heapq

MOD = 10**9+7

t = int(input().strip())
for _ in range(t):
    n, k = map(int, input().strip().split())
    a = list(map(int, input().strip().split()))
    a = [-i for i in a]  # Python's heapq is a min-heap, so we negate all elements to simulate a max-heap
    heapq.heapify(a)
    sum = 0
    for _ in range(k):
        max_element = -heapq.heappop(a)
        sum = (sum + max_element) % MOD
        heapq.heappush(a, -max_element//2)
    print(sum)