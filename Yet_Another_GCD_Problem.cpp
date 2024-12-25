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
vector<int> generate_primes(int N) {
    vector<int> primes;
    vector<bool> is_prime(2 * 1000000 + 1, true);
    for (int i = 2; i <= 2 * 1000000 && primes.size() < N; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= 2 * 1000000; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}
int find_max_x(int k, int n) {
    int left = 1, right = n, result = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long pairs = (long long)mid * (mid - 1) / 2;
        if (pairs < k) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}
void solve(int test)
{
    int N = in.nextInt();
    int K = in.nextInt();
    int max_pairs = N * (N - 1) / 2;
        vector<int> primes = generate_primes(100000); // Generate enough primes for the largest N
        if (K > max_pairs || K < N - 1) {
            cout << -1 << endl;
        }
        else{
            vector<int> result;

            if (K == max_pairs) {
                result = vector<int>(primes.begin(), primes.begin() + N);
            } else {
                int x = find_max_x(K, N);

                result = vector<int>(primes.begin(), primes.begin() + x);
                int w = K - x*(x-1)/2;
                int j = N-x;
                if(w%(x-1)==0){

                }
                result.push_back(extra);
            }

            for (int num : result) {
                cout << num << " ";
            }
            cout<<endl;
        }
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