#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin>>n;
    vector<int> v(n);
    vector<int> prefix(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    prefix[0] = v[0];
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1] + v[i];
        if(prefix[i] == 0){
            
        }
    }
}