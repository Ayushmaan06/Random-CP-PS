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

int a[1]={0};
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
bool is_contiguous(const vector<int>& mismatches) {
    return mismatches.empty() || (mismatches.back() - mismatches[0] + 1 == mismatches.size());
}

// Function to determine if the string is almost alternating
bool is_almost_alternating(const string& S, int N) {
    // Generate alternating patterns
    string pattern_a, pattern_b;
    for (int i = 0; i < N; ++i) {
        pattern_a += (i % 2 == 0 ? '0' : '1');
        pattern_b += (i % 2 == 0 ? '1' : '0');
    }

    // Find mismatched indices for both patterns
    vector<int> mismatches_a, mismatches_b;
    for (int i = 0; i < N; ++i) {
        if (S[i] != pattern_a[i]) mismatches_a.push_back(i);
        if (S[i] != pattern_b[i]) mismatches_b.push_back(i);
    }

    // Check if mismatches are contiguous
    return is_contiguous(mismatches_a) || is_contiguous(mismatches_b);
}
void solve(int test)
{
    // Your solution here
    int t=in.nextInt();
    while(t--){
        int N=in.nextInt();
        string S;
        cin>>S;
        if (is_almost_alternating(S, N)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

// Main function
signed main() {
    tej;
    // #ifndef ONLINE_JUDGE
    //     ojs();
    // #endif

    int test=1;
    // cin >> test;
    while(test--) {
        solve(test);
    }
    return 0;
}