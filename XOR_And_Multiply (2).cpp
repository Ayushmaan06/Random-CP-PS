#include <bits/stdc++.h>
using namespace std;
# define int long long
signed main() {
	int t;
	cin>>t;
	while(t--){
	    int x;cin>>x;
	    int k = log2(x)+1;
	    int ans=x<<k;
	    cout<<ans<<" "<<ans+x<<endl;
	}

}
