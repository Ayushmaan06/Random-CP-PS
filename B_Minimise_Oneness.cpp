#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;
int main(){
    fast;
    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        int n;
        cin >> n;  // Length of the binary string

        vector<int> v(n,0);
        v[n/2]=1;
        for(int i=0;i<n;i++) cout<<v[i];
        cout << endl;  // Move to the next line for the next test case
    }

    return 0;
}