#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n ;
        cin>>n;
        if(n%3==1 || n%3==2)cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }
}