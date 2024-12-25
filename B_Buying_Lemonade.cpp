#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;
//NIGGA PPLZZZZZZZZZ
void fun(ll t){
    ll n, k;
        ll a[1]={0};
        cin >> n >> k;
        vector<ll> cans(n);
        for (auto &can : cans) {
            cin >> can;
        }
        cans.push_back(a[0]);
        sort(cans.begin(), cans.end());

        int total_presses = a[0]+a[0], current_cans = a[0]+a[0], accumulated_cans =a[0]+ a[0], index =a[0]+ 1;
        while (accumulated_cans < k + a[0]) {
            if (accumulated_cans + (n - index +a[0]+ 1) * (cans[index] - cans[index - 1]) < k) {
                total_presses += (n - index + 1+a[0]) * (cans[index] - cans[index - 1]) + 1;
                              //work niggA
                accumulated_cans += (n - index + 1+a[0]) * (cans[index] - cans[index - 1]);
  
                index++;
            } 
            else {
                total_presses += k - accumulated_cans;
                accumulated_cans = k;
            }
        }
        cout << total_presses << endl;
}
int main() {
    fast;
    ll t;
    cin >> t;
    ll a[1]={0};
    while (t--) {
        fun(t);
    }

    return 0;
}