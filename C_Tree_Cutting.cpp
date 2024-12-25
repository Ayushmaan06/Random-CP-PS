#include<bits/stdc++.h>
using namespace std;

pair<int, int> calculateSegments(vector<vector<int>>& tree, int node, int parent, int x) {
    pair<int, int> result = { 0,0 };

    for (auto& child : tree[node]) {
        if (child != parent) {
            auto childResult = calculateSegments(tree, child, node, x);
            result.second += childResult.second;
            result.first += childResult.first;
        }
    }

    result.first++;
    if (result.first >= x) {
        result.first = 0;
        result.second++;
    }

    return result;
}

bool isPossibleToFormSegments(vector<vector<int>>& tree, int x, int k) {
    pair<int, int> segmentAndRemainder = calculateSegments(tree, 0, -1, x);
    if (segmentAndRemainder.second > k)
        return true;
    if (segmentAndRemainder.second == k && segmentAndRemainder.first >= x)
        return true;
    return false;
}

int main() {
    int testCases;
    cin >> testCases;
    
    while (testCases--) {
        int nodes, k;
        cin >> nodes >> k;

        vector<vector<int>> adjacencyList(nodes);
        for (int i = 0; i < nodes - 1; i++) {
            int node1, node2;
            cin >> node1 >> node2;
            node1--;
            node2--;
            adjacencyList[node1].push_back(node2);
            adjacencyList[node2].push_back(node1);
        }

        int low = 1, high = nodes;
        int answer = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossibleToFormSegments(adjacencyList, mid, k)) {
                answer = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        cout << answer << endl;
    }
    return 0;
}
