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

void solve(int test)
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a.begin(), a.end());
    int k=(a.end() - a.begin())/2;
    int l = accumulate(a.begin(),a.begin()+ k, 0LL);
    int r = accumulate(a.begin()+k, a.end(), 0LL);
    int j=l-r;
    if(j<0)
        j*=-1;
    cout<<j<<endl;
}

// Main function
signed main() {
    tej;
// #ifndef ONLINE_JUDGE
//     ojs();
// #endif

    int test=1;
    cin>>test;
    while(test--)
    {
        solve(test);
    }
    return 0;
}