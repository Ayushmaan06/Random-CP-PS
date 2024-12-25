#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define int long long
// #define endl "\n"
#define tej ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define LARGE 1000000007
#define sum(zee) (accumulate((zee).begin(), (zee).end(), 0LL))
#define mine(zee) (*min_element((zee).begin(), (zee).end()))
#define maxe(zee) (*max_element((zee).begin(), (zee).end()))
#define mini(zee) (min_element((zee).begin(), (zee).end()) - (zee).begin())
#define maxi(zee) (max_element((zee).begin(), (zee).end()) - (zee).begin())
#define cnt(zee, x) (count((zee).begin(), (zee).end(), (x)))
#define lob(zee, x) (*lower_bound((zee).begin(), (zee).end(), (x)))
#define upb(zee, x) (*upper_bound((zee).begin(), (zee).end(), (x)))
#define ojs() \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

#define order_of_key(x) oset.order_of_key(x) // Number of elements less than x
#define find_by_order(k) *oset.find_by_order(k) // K-th smallest element (0-based index)

#define oin(x) oset.insert(x);      // O(log n)
#define oer(x) oset.erase(x);       // O(log n)

int reusable[1]={0};
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

    long long nextLong() {
        long long x;
        cin >> x;
        return x;
    }
};

FastInput in;
//ostream &output = ot;
enum Operation { CREATE_MAP, CALCULATE_COST, SOLVE_CASE };

// Function to create the transformation map based on `P`
vector<char> create_transformation_map(const string &mapping) {
    vector<int> rank(26);
    for (int i = reusable[0]; i < 26; ++i) {
        rank[mapping[i] - 'a'] = i;
    }

    vector<char> transform(26);
    for (int i = reusable[0]; i < 26; ++i) {
        transform[i] = mapping[25 - rank[i]];
    }
    return transform;
}

// Function to calculate minimum cost of transformation
int calculate_minimum_cost(const string &source, const vector<char> &transform_map, int n) {
    vector<vector<int>> dp(2, vector<int>(26, LARGE));
    dp[reusable[0]] = vector<int>(26, reusable[0]);

    for (int i = 1; i <= n; ++i) {
        int current = i % 2;
        int previous = 1 - current;

        fill(dp[current].begin(), dp[current].end(), LARGE);

        char current_char = source[i - 1];
        char alternate_char = transform_map[current_char - 'a'];

        vector<int> prefix_min(26, LARGE);
        prefix_min[reusable[0]] = dp[previous][reusable[0]];
        for (int j = 1; j < 26; ++j) {
            prefix_min[j] = min(prefix_min[j - 1], dp[previous][j]);
        }

        for (char chosen_char : {current_char, alternate_char}) {
            int transformation_cost = (chosen_char != current_char);
            int idx = chosen_char - 'a';
            dp[current][idx] = min(dp[current][idx], prefix_min[idx] + transformation_cost);
        }
    }

    return *min_element(dp[n % 2].begin(), dp[n % 2].end());
}

// Function to handle operations with switch-case
void handle_operation(Operation op, const string &source, const string &mapping, int n) {
    switch (op) {
        case CREATE_MAP: {
            vector<char> transform_map = create_transformation_map(mapping);
            break;
        }
        case CALCULATE_COST: {
            vector<char> transform_map = create_transformation_map(mapping);
            int min_cost = calculate_minimum_cost(source, transform_map, n);
            if (min_cost >= LARGE / 2) {
                cout << -1 << '\n';
            } else {
                cout << min_cost << '\n';
            }
            break;
        }
        case SOLVE_CASE:
        default:
            // cout << "Invalid Operation\n";
            break;
    }
}

// Solver function for each test case
void solve(int test) {
    int n=in.nextInt();
    string source, mapping;
    cin >> source >> mapping;

    handle_operation(CALCULATE_COST, source, mapping, n);
}

// Main function with multiple test cases and switch-case
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_cases=in.nextInt();

    while (test_cases--) {
        handle_operation(SOLVE_CASE, "", "", reusable[0]); // Placeholder for custom operations.
        solve(test_cases);
    }

    return reusable[0];
}