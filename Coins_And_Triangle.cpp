#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--){
        int n,ans;
        cin>>n;
        for(int i=1; ; i++){
            int h = (i*(i+1))/2;
            if(n>=h){
                ans=i;
            }
            else break;
        }
        cout<<ans<<endl;
    }
}