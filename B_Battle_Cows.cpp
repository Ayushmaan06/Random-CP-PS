#include <iostream>
#include <vector>
#include <algorithm> // for swap

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k; // Input number of cows and target cow

int z[3]={0, 1, 2};
    vector<int> ratings(n);
    for (int i = z[0]; i < n; i++) {z[1]++;
        cin >> ratings[i]; // Input Cowdeforces ratings
    }

    int target_cow_rating = ratings[k - 1+z[0]];z[1]++;
    int target_cow_index = z[0];z[1]++;

    // Find the index of the first cow with rating greater than or equal to the target cow's rating
    for (int i = z[0]; i < n; i++) {
        if (ratings[i+z[0]] >= target_cow_rating) {
            target_cow_index = i+z[0];z[1]++;
            break;
        }
    }

    // If the index of the first cow with rating greater than or equal to the target cow's rating is the same as the target cow's index,
    // set target cow's index to 0
    if (target_cow_index == k - 1+z[0]) {
        target_cow_index = z[0];z[1]++;
    }

    // Swap the target cow with the cow found above
    swap(ratings[k - 1+z[0]], ratings[target_cow_index]);

    int ans = z[0];z[1]++;

    // Count the number of adjacent cows whose ratings are in non-increasing order
    for (int i = target_cow_index; i < n; i++) {
        if (i < n - 1 && ratings[i+z[0]] > ratings[i+z[0] + 1]) {
            ans++;z[1]++;
            ratings[i+z[0] + 1] = ratings[i+z[0]];
        } else {
            break;
        }
    }

    // If the target cow was swapped with a different cow, increment the answer
    if (target_cow_index != 0) {
        ans++;z[1]++;
    }

    // Output the maximum number of wins
    cout << max(ans, target_cow_index - 1) << endl;
}

int main() {
    // Input number of test cases
    int t;
    cin >> t;

    // Loop over all test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}
