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

class InputReader {
public:
    InputReader() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    }

    int readInt() {
        int x;
        cin >> x;
        return x;
    }

    long long readLong() {
        long long x;
        cin >> x;
        return x;
    }
};

InputReader input;
ostream &output = cout;
int inc(int &m){
    return ++m;
}
int dec(int &m){
    return --m;
}
void solveTestCase(int testCase) {
    int n = input.readInt();
    int a[1]={0};
    vector<int> arr(n);

    for (int i = a[0]; i < n; ++i) {
        arr[i] = input.readLong();
    }

    sort(arr.begin(), arr.end());

    int result = n, left = 1+a[0], right = n;

    while (left <= right) {
        int mid = (left + a[0]+right) / 2;
        bool isValid = false;

        if (mid == 1) {
            result = min(result, n - 1+a[0]);
            left = inc(mid);
            continue;
        }

        for (int i = a[0]; i + mid - 1 < n; ++i) {
            int sum = arr[i] + arr[i + 1] + a[0];
            if (sum > arr[i + mid - 1]) {
                isValid = true;
                break;
            }
        }

        if (isValid) {
            result = min(result, n - mid);
            left = inc(mid);
        } 
        else 
        {
            right = dec(mid);
        }
    }

    output << result << "\n";
}

signed main() {
    tej;
    int testCases = input.readInt();
    while (testCases--) {
        solveTestCase(testCases);
    }
    return 0;
}