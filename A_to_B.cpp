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
int min_steps(int x1, int y1, int z1, int x2, int y2, int z2, int K) {
    // Calculate the differences in x, y, z coordinates
    int delta_x = abs(x2 - x1);
    int delta_y = abs(y2 - y1);
    int delta_z = abs(z2 - z1);

    // Calculate the total Manhattan distance
    int total_diff ;

    // Identify the maximum difference
    int max_diff = max({delta_x, delta_y, delta_z});
    int s = delta_x + delta_y + delta_z-max_diff;
    int b = (max_diff+K-1)/K;
    if(s>=b-1) total_diff= delta_x + delta_y + delta_z;
    // If the largest difference can fit into steps of size K
    if (max_diff <= K) {
        return total_diff;
    }

    // Otherwise, handle the case where chunks of K steps are required for the largest difference
    int remaining_diff = total_diff - max_diff;

    // Calculate the minimum number of steps required
    return max_diff + (remaining_diff + K - 1) / K;
}
void solve(int test)
{
    // Your solution here
    int t = in.nextInt();
    while(t--){
        int x1 = in.nextInt(), y1 = in.nextInt(), z1 = in.nextInt();
        int x2 = in.nextInt(), y2 = in.nextInt(), z2 = in.nextInt();
        int K = in.nextInt();

                int dx = abs(x2 - x1);
        int dy = abs(y2 - y1);
        int dz = abs(z2 - z1);

        int c1 = max({dx, dy, dz});
        int S = dx + dy + dz - c1;
        int B = (c1 + K - 1) / K;
        int steps = dx + dy + dz;

        if (S <= B - 1) {
            // No additional steps required
        } else {
            int extra = S - (B - 1);
            if (extra > 0 && extra % 2 == 1) {
                steps += extra + 1;
            } else {
                steps += extra;
            }
        }

        results.push_back(steps);
    }

    for (int result : results) {
        cout << result << endl;
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