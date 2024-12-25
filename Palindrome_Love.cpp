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

FastInput in;
//ostream &output = ot;
int cntDistinct(string str)
{
    unordered_set<char> s;
    for (int i = 0; i < str.size(); i++) {
        s.insert(str[i]);
    }
    return s.size();
}
bool isP(string s){
    int n=s.size();
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1]){
            return false;
        }
    }
    return true;
}
void solve(int test)
{
    int n;cin>>n;
    string s;cin>>s;
    if(isP(s)){
        cout<<0<<endl;
        return;
    }
    else if(n == 2)
    {
        cout << -1 << endl;
        return;
    }
    
    else if(n % 2 == 0)
    {
        int cnt = 1;
        for(int i = 0; i < n; i+=2)
        {
            if(s[i] != s[0])
            {
                cnt = 0;
                break;
            }
            if(i < n && s[i + 1] != s[1])
            {
                cnt = 0;
                break;
            }
        }                                          
        if(cnt == 1)
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << 1 << endl;
    
}

// Main function
signed main() {
    tej;
    // #ifndef ONLINE_JUDGE
    //     ojs();
    // #endif

    int test=1;
    cin >> test;
    while(test--) {
        solve(test);
    }
    return 0;
}