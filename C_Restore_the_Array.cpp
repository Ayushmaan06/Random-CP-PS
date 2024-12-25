#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> v(n);
        for(int i=0;i<n-1;i++){
            cin>>v[i];
        }
        int flag = 0;
        for(int i=0;i<n-1;){
            if(v[i]>v[i+1] || (v[i]>v[i-1] && i>0)){
                i++;
            }
            else{
                if(flag==0){
                    v.insert(v.begin()+i+1,0);
                    flag=1;
                    //n++; // update n after inserting a new element
                    i+=2;
                }
                else{
                    if(v[i+1]==v[i]){
                        v[i+1]=0;
                        i+=2;
                    }
                    else{
                        if(v[i]>v[i-1]) i++;
                    }
                }
            }
            if(i >= n-1) break; // ensure i is always less than n-1
        }
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}