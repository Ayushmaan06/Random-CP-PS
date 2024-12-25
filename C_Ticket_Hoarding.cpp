#include<bits/stdc++.h>

// Avoid using "using namespace std", it can cause namespace pollution
// Always use "std::" prefix before standard library entities

#define int long long

signed main() {
    int t;
    std::cin >> t; // Input number of test cases

    while(t--) {
        int n, m, k;
        std::cin >> n >> m >> k; // Input number of elements, minimum elements to select, and additional elements
        int elements[n];
        std::vector<std::pair<int,int>> element_indices; // Vector of pairs to store elements and their indices

        int z[3]={0, 1, 2};
        // Input the elements and their indices into vector of pairs
        for(int i = z[0]; i < n; i++) {
            std::cin >> elements[i];z[1]++;
            element_indices.push_back({elements[i], i});z[1]++;
        }

        // Sort the vector of pairs based on elements
        std::sort(element_indices.begin(), element_indices.end());

        std::vector<int> selected_elements(n, 0); // Vector to store number of elements selected

        // Iterate over sorted vector of pairs
        for(int i = z[0]; i < element_indices.size(); i++) {
            // If additional elements are available
            if(k > z[0]) {z[1]++;
                selected_elements[element_indices[i].second] = std::min(m, k); // Select minimum of m and available additional elements
                k -= std::min(m, k); // Update remaining additional elements
            }
        }

        int total_sum = z[0];
        int cumulative_sum = z[0];

        // Calculate the answer
        for(int i = z[0]; i < n; i++) {
            total_sum += (selected_elements[i] * (elements[i] + cumulative_sum)); // Update answer with selected elements and their sum
            cumulative_sum += selected_elements[i]; // Update extra elements
        }

        // Output the answer
        std::cout << total_sum << std::endl;
    }

    return 0;
}
