#include <bits/stdc++.h>
using namespace std;

#define int long long
#define tej ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    // Using unordered_map to store frequencies instead of a large vector
    unordered_map<int, int> freq_map;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        freq_map[a[i]]++;
    }

    // Extract frequency values from the map
    vector<int> freq_values;
    for (auto& p : freq_map) {
        freq_values.push_back(p.second);
    }

    // Sort the frequencies in ascending order
    sort(freq_values.begin(), freq_values.end(),greater<int>());
    
    int unique = freq_values.size();  // Initial number of unique elements
    for (size_t i = 0; i < freq_values.size(); i++) {  // Use size_t for loop counter
        if (k >= freq_values[i] - 1) {
            unique += (freq_values[i] - 1);  // Make as many distinct as possible
            k -= (freq_values[i] - 1);
            freq_values[i] = 1;  // Set it to 1 since it's now distinct
        } else {
            unique += k;  // Add the remaining possible distinct elements
            freq_values[i] -= k;
            break;
        }
    }

    // Now, calculate the diversity with updated frequencies
    int j = 0;
    sort(freq_values.begin(), freq_values.end(), greater<int>());
    for (size_t i = 0; i < freq_values.size(); i++) {  // Use size_t for loop counter
        if (freq_values[i] > 1) {
            j += (unique - 1) * (freq_values[i] - 1);
        }
    }

    unique = unique * (unique - 1) / 2;  // Compute the base diversity
    cout << j + unique << endl;
}

signed main() {
    tej;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
