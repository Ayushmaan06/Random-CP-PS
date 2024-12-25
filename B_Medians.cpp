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

FastInput input;
ostream &output = cout;

void solveTestCase(int testCase) {
    int n = input.nextLong();
    int k = input.nextLong();

    int maxOffset = min(k - 1, n - k);
    bool solutionFound = false;
    vector<int> positions;
    int medianCount = 0;

    for (int x = 1; x <= maxOffset; ++x) {
        int temp = k - 1 - x;
        if (temp < 0) continue;

        int parity = (temp % 2 == 0) ? 0 : 1;
        int minPos = min(k - 1 - x, n - k - x);

        if (parity > minPos) continue;

        int currentMedianCount = 1 + 2 * x;
        int leftLimit = k - parity - 1;
        int rightLimit = n - k - parity;

        if (leftLimit < x || rightLimit < x) continue;

        vector<int> tempPositions;
        int pos = 1;

        for (int i = 1; i < x; ++i) {
            tempPositions.push_back(pos);
            pos += 1;
        }

        if (x > 0) {
            tempPositions.push_back(pos);
            pos += (leftLimit - (x - 1));
        }

        tempPositions.push_back(pos);
        pos += (2 * parity + 1);

        for (int i = 1; i < x; ++i) {
            tempPositions.push_back(pos);
            pos += 1;
        }

        if (x > 0) {
            tempPositions.push_back(pos);
            pos += (rightLimit - (x - 1));
        }

        if (pos - 1 == n) {
            medianCount = currentMedianCount;
            positions = tempPositions;
            solutionFound = true;
            break;
        }
    }

    if (solutionFound) {
        output << medianCount << "\n";
        for (int i = 0; i < positions.size(); ++i) {
            output << positions[i] << (i < positions.size() - 1 ? ' ' : '\n');
        }
        return;
    }

    int singlePos = (n - 1) / 2;
    if (singlePos == k - 1) {
        output << "1\n1\n";
        return;
    }

    output << "-1\n";
}

signed main() {
    tej;
    int testCases = input.nextInt();
    while (testCases--) {
        solveTestCase(testCases);
    }
    return 0;
}