#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    while(q--){
        int a,s=0;  cin>>a;
        int i = lower_bound(v.begin(),v.end(),a)-v.begin();
        if(i<n && v[i]==a) cout<<"0"<<endl;
        else if((n-i)%2==0) cout<<"POSITIVE"<<endl;
        else cout<<"NEGATIVE"<<endl;
        
    }
}