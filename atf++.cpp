#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    
    unordered_map<int, int> remainderIndex;
    remainderIndex[0] = -1; // To handle the case when the subarray starts from index 0
    
    int prefixSum = 0;
    int maxLength = 0;
    
    for (int i = 0; i < N; ++i) {
        prefixSum += arr[i];
        int remainder = ((prefixSum % K) + K) % K; // Handle negative remainders
        
        if (remainderIndex.find(remainder) != remainderIndex.end()) {
            maxLength = max(maxLength, i - remainderIndex[remainder]);
        } else {
            remainderIndex[remainder] = i;
        }
    }
    
    cout << maxLength << endl;
    return 0;
}