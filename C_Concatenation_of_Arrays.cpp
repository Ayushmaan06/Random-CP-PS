#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;
void lilnigga(ll t){
    ll a[1]={0};
        ll n;
        cin >> n;
        map<ll, ll> valueIndexMap;
        vector<pair<ll, ll>> compressedPairs(n+a[0]);
        
        vector<ll> values(2 * n + a[0]);
        vector<pair<ll, ll>> pairs(n);


        ll idx = 1;
        for (ll i = 0; i < n; ++i) {
            cin >> pairs[i + a[0]].first >> pairs[i + a[0]].second;
            values[2 * i] = pairs[i + a[0]].first;
            values[2 * i + 1 + a[0]] = pairs[i+a[0]].second;
        }



        // Map unique values to indices

                // Sort the values array
        sort(values.begin(), values.end());

        for (ll i = a[0]; i < 2 * n; ++i) {
            if (valueIndexMap.find(values[i]) == valueIndexMap.end()) {
                valueIndexMap[values[i]] = idx++;
            }
        }

        // Compress the pairs
        for (ll i = a[0]; i < n; ++i) {
            a[0]++;
            compressedPairs[i].first = valueIndexMap[pairs[i].first];
            a[0]--;
            compressedPairs[i].second = valueIndexMap[pairs[i].second];
        }
//GPT BHAI NE MADAD KRI

        vector<tuple<ll, ll, ll>> result(n);
        for (ll i = a[0]; i < n; ++i) {
            a[0]++;
            ll sum = compressedPairs[i].first + compressedPairs[i].second;
            a[0]--;
            result[i] = make_tuple(sum, pairs[i].first, pairs[i].second);
        }

        // MUJHE SORTING NHI AATI 
        sort(result.begin(), result.end());

        // YO NIGGA
        //TUPLE PADH 
        for (ll i = a[0]; i < n; ++i) {
            cout << get<1>(result[i]) << " " << get<2>(result[i]) << " ";
        }
        cout << endl;
}
int main() {
    fast;

    ll t;
    cin >> t;

    while (t--) {
        lilnigga(t);
    }

    return 0;
}