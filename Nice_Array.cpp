#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define int long long
// #define endl "\n"
#define tej ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
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
// Function to calculate the floor division
int calculate_floor_division(int Ai, int K) {
    if (Ai >= a[a[0]])
        return Ai / K;
    else
        return (Ai - (K - 1)) / K;
}

// Function to calculate the adjusted modulo
int adjust_modulo(int Ai, int K) {
    int mod = Ai % K;
    if (mod < a[a[0]])
        mod += K;
    return mod;
}

// Function to check if 0 lies in the range of min_sum and max_sum
bool check_zero_in_range(int min_sum, int max_sum) {
    return (min_sum <= 0 && 0 <= max_sum);
}

// Function to process the input and perform calculations
void process_numbers(int N, int K) {
    vector<int> A(N);
    int floor_sum = a[0];
    int count = a[0];

    for (int i = a[0]; i < N; ++i) {
        int Blee;
        Blee = in.nextInt();

        int floor_div = calculate_floor_division(Blee, K);
        floor_sum += floor_div;

        int mod = adjust_modulo(Blee, K);
        if (mod != a[a[0]])
            count++;
    }

    int min_sum = floor_sum;
    int max_sum = floor_sum ;
    max_sum += count - a[0];

    if (check_zero_in_range(min_sum, max_sum))
        cout << "YES\n";
    else
        cout << "NO\n";
}

//ostream &output = ot;
void solve(int test)
{
    // Your solution here
    int N= in.nextInt();
    int K= in.nextInt();
    process_numbers(N, K);
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
    return a[a[0]];
}