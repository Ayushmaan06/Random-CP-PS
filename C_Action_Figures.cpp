#include <bits/stdc++.h>
#define optimize_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int64 long long
using namespace std;

// Helper function to display the result
void display_result(int64 outcome) {
    cout << outcome << '\n';
}

// Core function to calculate cumulative score
void calculate_total_score(int64 len, const string &binString) {
    vector<int64> pos_zero, pos_one;

    // Track '0' and '1' positions in the binary string (except final character)
    for (int64 idx = 0; idx < len - 1; idx++) {
        if (binString[idx] == '0')
            pos_zero.push_back(idx);
        else
            pos_one.push_back(idx);
    }

    // Reverse one_positions for backward iteration
    reverse(pos_one.begin(), pos_one.end());

    int64 last_pos_zero = pos_zero.size() - 1;
    int64 last_pos_one = pos_one.size() - 1;

    // Starting total score calculation
    int64 cumulative_sum = len * (len + 1) / 2;

    // Backward loop from the last index
    for (int64 idx = len - 1; idx >= 0; idx--) {
        // Update last_pos_zero to ignore positions after current index
        while (last_pos_zero >= 0 && pos_zero[last_pos_zero] >= idx)
            last_pos_zero--;

        // Update last_pos_one to ignore positions after current index
        while (last_pos_one >= 0 && pos_one[last_pos_one] >= idx)
            last_pos_one--;

        // Deduct score if the current character is '1' under position conditions
        if (binString[idx] == '1') {
            if (last_pos_zero >= 0) {
                cumulative_sum -= (idx + 1);  // Adjust cumulative sum
                last_pos_zero--;
            } else if (last_pos_one >= 0) {
                cumulative_sum -= (idx + 1);  // Adjust cumulative sum
                last_pos_one--;
            }
        }
    }

    // Print the final outcome
    display_result(cumulative_sum);
}

// Function to manage multiple test cases
void handle_cases() {
    int64 case_count;
    cin >> case_count;
    while (case_count--) {
        int64 len;
        cin >> len;
        string binString;
        cin >> binString;
        calculate_total_score(len, binString);  
    }
}

int main() {
    optimize_io;
    handle_cases();
    return 0;
}