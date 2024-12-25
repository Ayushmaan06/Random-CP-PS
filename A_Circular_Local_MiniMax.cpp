#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        vector<int> v(a);
        vector<int> v1(a);
        for(int i=0;i<a;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int k = a/2, j=0;
        for(int i=0;i<a;i++){
            if(i%2==0 && j<a/2){
                v1[i] = v[j];
                j++;
            }
            else{
                v1[i] = v[k];
                k++;
            }
        }
        int flag=0;
        for(int i=1;i<a-1;i++){
            if(!((v1[i]<v1[i-1] && v1[i]<v1[i+1])||(v1[i]>v1[i-1] && v1[i]>v1[i+1]))){
                flag=1;
            }
        }
        if(flag==1){
            cout<<"NO"<<endl;
        }
        else{
            if(((v1[0]<v1[a-1] && v1[0]<v1[1])||(v1[0]>v1[a-1] && v1[0]>v1[1]))||((v1[a-1]<v1[a-2] && v1[a-1]<v1[0])||(v1[a-1]>v1[a-2] && v1[a-1]>v1[0]))){
                cout<<"YES"<<endl;
                for(int i=0;i<a;i++){
                    cout<<v1[i]<<" ";
                }
                cout<<endl;
            }
        }
    }
}