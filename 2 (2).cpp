#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;
int main(){
    ll n;
    cin>>n;
    ll sum=0;
    ll k;
    for(int i=0;i<n-1;i++){
        cin>>k;
        sum+=k;
    }
    n=n*(n+1)/2;
    cout<<n-sum;

}