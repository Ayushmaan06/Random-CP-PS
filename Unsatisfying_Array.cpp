#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define int long long
// #define endl "\n"
#define tej ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
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

// Enum for states
enum ValueState {
    ONE = 1,
    TWO = 2
};

// Fast Input Class
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

FastInput input;

void solve(int test_case) {
    int testCases = input.nextInt();
    while (testCases--) {
        int arraySize = input.nextInt();
        int constraints = input.nextInt();
        vector<tuple<int, int, int>> conditions;

        // Reading constraints
        for (int i = 0; i < constraints; i++) {
            int leftIndex = input.nextInt();
            int rightIndex = input.nextInt();
            int valueConstraint = input.nextInt();
            conditions.push_back(make_tuple(leftIndex - 1, rightIndex - 1, valueConstraint));
        }

        vector<int> arrayValues(arraySize, ONE); // Initialize array with `ONE`
        bool isInvalid = true;

        // Processing constraints
        for (auto &[left, right, targetValue] : conditions) {
            isInvalid = false;

            for (int index = left; index <= right; index++) {
                switch (arrayValues[index]) {
                    case ONE:
                        if (targetValue == ONE) {
                            arrayValues[index] = TWO;
                            isInvalid = true;
                        }
                        break;

                    case TWO:
                        if (targetValue == TWO) {
                            arrayValues[index] = ONE;
                            isInvalid = true;
                        }
                        break;

                    default:
                        break;
                }
            }

            if (!isInvalid) {
                cout << "-1" << endl;
                break;
            }
        }

        // Output result
        if (isInvalid) {
            for (int value : arrayValues) {
                cout << value << " ";
            }
            cout << endl;
        }
    }
}

// Main Function
signed main() {
    tej;

    int testCases = 1;
    // Uncomment if test cases need to be provided
    // cin >> testCases;
    while (testCases--) {
        solve(testCases);
    }
    return 0;
}
