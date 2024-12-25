#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    vector<int> v;
    unordered_map<char, int> m;
    for(int i=0; i<s.size(); i++){
        m[s[i]]++;
    }
    for(auto& pair : m){
        v.push_back(pair.second);
    }
    while(v.size()>2){
        int k = (v.size()+1)/2;
        for(int i=0; i<k; i++){
            if(i != v.size()-1-i){
                v[i] += v[v.size()-1-i];
                if(v[i]>9){
                    v[i] = v[i]/10 + v[i]%10;
                    
                }
            }
        }
        v.resize(k);
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}