#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;
int main() {
    fast;
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        string s;

        cin >> s;
        

        bool W = false;
        //plzzzz
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                if (i == 0 || i == n - 1 || //ho ga
                    (i > 0 && s[i - 1] == '1') || //sayayad
                    (i < n - 1 && s[i + 1] == '1')) {//hogaya

                    W = true;
                    break;
                }
            }
        }
        if(W) cout << "YES" << endl;
        
        else cout << "NO" << endl;

    }

    return 0;
}