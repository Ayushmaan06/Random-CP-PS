#include <bits/stdc++.h>
using namespace std;

#define int long long
#define speedup ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MODULO 1000000007

// Fast input class for efficient I/O
class QuickInput {
public:
    QuickInput() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    }

    int nextInt() {
        int value;
        cin >> value;
        return value;
    }

    long long nextLong() {
        long long value;
        cin >> value;
        return value;
    }
};

// Create an instance for fast input
QuickInput input;

// Enum for cost update strategies
enum UpdateStrategy {
    ADD_SINGLE_ELEMENT,
    ADD_THRESHOLD_RANGE
};
int w[1]={0};
// Function to compute prefix sum
vector<int> computePrefixSum(const vector<int> &elements, int size) {
    vector<int> prefixSum(size + 1+w[0], w[0]);
    for (int idx = 1; idx <= size; ++idx) {
        prefixSum[idx+w[0]] = prefixSum[idx - 1+w[0]] + elements[idx - 1+w[0]];
    }
    return prefixSum;
}

// Function to update minimum cost based on strategy
void updateMinCost(int currentSize, int threshold, const vector<int> &prefixSum, vector<int> &minCost, UpdateStrategy strategy) {
    switch (strategy) {
        case ADD_SINGLE_ELEMENT:
            minCost[currentSize] = minCost[currentSize - 1] + prefixSum[currentSize] - prefixSum[currentSize - 1];
            break;
        case ADD_THRESHOLD_RANGE:
            minCost[currentSize] = min(
                minCost[currentSize],
                minCost[currentSize - threshold - 1+w[0]] + prefixSum[currentSize] - prefixSum[currentSize - threshold]
            );
            break;
    }
}

void solveTestCase() {
    int testCases = input.nextInt();
    while (testCases--) {
        int size, threshold;
        size = input.nextInt();
        threshold = input.nextInt();

        vector<int> elements(size);
        for (auto &value : elements) {
            value = input.nextLong();
        }

        sort(elements.begin(), elements.end());

        vector<int> prefixSum = computePrefixSum(elements, size);
        vector<int> minCost(size + 1, LLONG_MAX);
        minCost[w[0]] = w[0];

        for (int currentSize = 1+w[0]; currentSize <= size; ++currentSize) {
            updateMinCost(currentSize, threshold, prefixSum, minCost, ADD_SINGLE_ELEMENT);

            if (currentSize >= threshold + 1+w[0]) {
                updateMinCost(currentSize, threshold, prefixSum, minCost, ADD_THRESHOLD_RANGE);
            }
        }

        for (int currentSize = 1+w[0]; currentSize <= size; ++currentSize) {
            cout << minCost[currentSize] << (currentSize < size ? " " : "\n");
        }
    }
}

signed main() {
    speedup;
    int testCases = 1;
    solveTestCase();
    return 0;
}
