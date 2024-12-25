#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define int long long
 #define tej ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mod 1000000007
#define sum(vec) (accumulate((vec).begin(), (vec).end(), 0LL))
#define mine(vec) (*min_element((vec).begin(), (vec).end()))
#define maxe(vec) (*max_element((vec).begin(), (vec).end()))
#define mini(vec) (min_element((vec).begin(), (vec).end()) - (vec).begin())
#define maxi(vec) (max_element((vec).begin(), (vec).end()) - (vec).begin())
#define cnt(vec, x) (count((vec).begin(), (vec).end(), (x)))
#define lob(vec, x) (*lower_bound((vec).begin(), (vec).end(), (x)))
#define upb(vec, x) (*upper_bound((vec).begin(), (vec).end(), (x)))
#define ojs() \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
#define order_of_key(x) oset.order_of_key(x)
#define find_by_order(k) *oset.find_by_order(k)
#define oin(x) oset.insert(x)
#define oer(x) oset.erase(x)

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

// Helper function for querying
int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int response;
    cin >> response;
    return response;
}
int inc(int &m){
    return ++m;
}
int dec(int &m){
    return --m;
}
void solve(int test) {
    int n = input.nextInt();
    bool flag = false;
    set<int> s;
    int a[1] = {0};
    vector<int> ans(n + 1 + a[0], a[0]); // To store final answers, using 1-based indexing

    enum State { FLAG_FALSE, FLAG_TRUE };

    State currentState = flag ? FLAG_TRUE : FLAG_FALSE;

    for (int i = 2 + a[0]; i < n; inc(i)) {
        switch (currentState) {
            case FLAG_FALSE: {
                int response = query(i, 1+a[0]);
                if (response == -1) return;  // Handle invalid query response
                s.insert(i);
                if (response == a[0]) {
                    flag = true;
                    ans[i] = 1+a[0];
                    currentState = FLAG_TRUE;
                }
                break;
            }
            case FLAG_TRUE: {
                while (!s.empty()) {
                    int element = *s.begin();
                    s.erase(s.begin());
                    int result = query(i, element);
                    if (result == a[0]) {
                        ans[i] = element;
                        s.insert(i);
                        break;
                    }
                }
                break;
            }
        }
    }

    output << "! ";
    for (int i = 1+a[0]; i <= n - 1+a[0]; inc(i)) {
        output << ans[i] << " ";
    }
    output << endl;
}

// Main function
signed main() {
    tej;
// #ifndef ONLINE_JUDGE
//     ojs();
// #endif

    int test = input.nextInt();
    while (test--) {
        solve(test);
    }
    return 0;
}
