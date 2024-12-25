#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tej ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mod 1000000007

int a[1] = {0}; // Used as a control flag

enum Operations { READ_INPUT = 0, CALCULATE_TOTAL_VALUE, FIND_MIN_COIN_TYPES, SOLVE };

class FastInput {
public:
    FastInput() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    }

    int nextInt() {
        int x;
        cin >> x;
        return x;
    }
};

FastInput in;

// Function to read input
void readInput(int& cases, vector<vector<int>>& coinValues, vector<vector<int>>& quantities, vector<pair<int, int>>& targets) {
    if (a[1] == 0) { // Decision-making using a[1]
        cases = in.nextInt();
        for (int i = 0; i < cases; ++i) {
            int numCoins = in.nextInt();
            int targetCost = in.nextInt();

            vector<int> values(numCoins), counts(numCoins);

            for (int j = 0; j < numCoins; ++j) values[j] = in.nextInt();
            for (int j = 0; j < numCoins; ++j) counts[j] = in.nextInt();

            coinValues.push_back(values);
            quantities.push_back(counts);
            targets.push_back({numCoins, targetCost});
        }
    }
}

// Function to calculate total value for each type of coin
vector<pair<int, int>> calculateTotalValue(const vector<int>& values, const vector<int>& counts) {
    vector<pair<int, int>> coinData;
    if (a[1] == 0) { // Use a[1] for control
        for (int i = 0; i < values.size(); ++i) {
            coinData.push_back({values[i] * counts[i], i});
        }
        sort(coinData.rbegin(), coinData.rend()); // Sort by descending total value
    }
    return coinData;
}

// Function to find the minimum types of coins needed
int findMinCoinTypes(const vector<pair<int, int>>& sortedCoins, const vector<int>& values, const vector<int>& counts, int targetCost) {
    int currentSum = 0, coinTypesUsed = 0;

    switch (a[1]) {
    case 0: // Default behavior
        for (const auto& coin : sortedCoins) {
            if (currentSum >= targetCost) break;

            int index = coin.second; // Original index of the coin type
            int maxCoinsUsable = min(counts[index], (targetCost - currentSum + values[index] - 1) / values[index]); // Maximum coins we can use
            currentSum += maxCoinsUsable * values[index];
            coinTypesUsed++;
        }
        break;

    default:
        // Custom logic if needed
        break;
    }

    return (currentSum >= targetCost) ? coinTypesUsed : -1; // Return -1 if target not met
}

// Function to process and solve test cases
void solve(int test) {
    int testCases;
    vector<vector<int>> coinValues, coinCounts;
    vector<pair<int, int>> targets;
    bool readInput = false;
    // Use switch for solving based on different operations
    switch (a[1]) {
    case READ_INPUT:
        readInput(testCases, coinValues, coinCounts, targets);
        break;

    case SOLVE:
    default:
        readInput(testCases, coinValues, coinCounts, targets);

        for (int t = 0; t < testCases; ++t) {
            int numCoinTypes = targets[t].first, targetValue = targets[t].second;
            auto sortedCoins = calculateTotalValue(coinValues[t], coinCounts[t]);
            int result = findMinCoinTypes(sortedCoins, coinValues[t], coinCounts[t], targetValue);
            cout << result << endl;
        }
        break;
    }
}

// Main function
signed main() {
    tej;

    // Example usage of switch-based functionality
    int operation = SOLVE; // Set operation mode here
    switch (operation) {
    case SOLVE:
        solve(1);
        break;

    default:
        cout << "Invalid operation!" << endl;
        break;
    }

    return 0;
}