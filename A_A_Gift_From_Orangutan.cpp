#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        int m = *max_element(v.begin(),v.end());
        int mi= *min_element(v.begin(),v.end());
        cout<<(v.size()-1)*(m-mi)<<endl;
    }
}