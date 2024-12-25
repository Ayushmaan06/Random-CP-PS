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
void solve(int test)
{
    // Your solution here
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
typedef long long ll;

// Function to compute mex of a vector of integers
int compute_mex(const vector<int>& vec) {
    unordered_set<int> s(vec.begin(), vec.end());
    int mex = 0;
    while(s.find(mex) != s.end()) mex++;
    return mex;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        // Build adjacency list
        vector<vector<int>> adj(n+1, vector<int>());
        for(int i=1;i<=n;i++){
            adj[i].push_back(i==1?n:i-1);
            adj[i].push_back(i==n?1:i+1);
        }
        // Add chord
        adj[x].push_back(y);
        adj[y].push_back(x);
        // Initialize labels
        vector<int> a(n+1, -1);
        // Assign a[x]=0, a[y]=1
        a[x] = 0;
        a[y] = 1;
        // Initialize queue
        queue<int> q;
        q.push(x);
        q.push(y);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(auto &v: adj[u]){
                if(a[v]==-1){
                    // Collect labels of neighbors
                    vector<int> labels;
                    for(auto &nei: adj[v]){
                        if(a[nei]!=-1){
                            labels.push_back(a[nei]);
                        }
                    }
                    // Compute mex
                    int mex = 0;
                    unordered_set<int> s(labels.begin(), labels.end());
                    while(s.find(mex)!=s.end()) mex++;
                    a[v] = mex;
                    q.push(v);
                }
            }
        }
        // Assign 0 to any remaining nodes
        for(int i=1;i<=n;i++) if(a[i]==-1) a[i]=0;
        // Output
        for(int i=1;i<=n;i++) cout << a[i] << (i<n?" ":"\n");
    }
}
