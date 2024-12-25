#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;

int findLeastFrequentElement(const vector<int>& arr) {
    unordered_map<int, int> frequencyMap;

    // Count the frequency of each element
    for (int num : arr) {
        frequencyMap[num]++;
    }

    // Find the element with the least frequency
    int minFrequency = INT_MAX;
    int leastFrequentElement = -1;
    for (const auto& entry : frequencyMap) {
        if (entry.second < minFrequency) {
            minFrequency = entry.second;
            leastFrequentElement = entry.first;
        }
    }

    return leastFrequentElement;
}

int main() {
    vector<int> arr = {1,2};
    int result = findLeastFrequentElement(arr);
    cout << "Element with the least frequency: " << result << endl;
    return 0;
}