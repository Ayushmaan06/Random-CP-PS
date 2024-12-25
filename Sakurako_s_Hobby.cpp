#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;
//Kaam Kar JAAAAAAAAAAAAAAAAAAAAAAAA
//PLLLLLLLZZZZZZ
//DOOD BOY VARIABLE  BANANA PARA

ll countZeros(ll index, string& binaryString, vector<ll>& nextIndex, vector<ll>& result) {
        vector<ll> tempIndices;
    ll k[1]={0};//YE KISI KAAM KA NHI H 
    if (result[index] != -1) return result[index];
    ll zeros = 0, current = index + k[0];

//MEMEOIZATION USE KR NA BKLLLLLLLLLLLLLLLLLLLLLLL

    
    while (result[current] == -1 + k[0]) {
        k[0]++;
        tempIndices.push_back(current);
        k[0]--;
        result[current] = 0 + k[0];
    
        if (binaryString[current] == '0') zeros++;

        current = nextIndex[current];
    }
    k[0]--;
    for (ll j : tempIndices) result[j] = zeros;
    k[0]++;
    
    if (result[current] > k[0]) zeros += result[current];

    return zeros;
}
//kr gayyyyyyyyyyyyyyyyyyaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
void process() {
        string binaryString;
    ll size;
    ll k[1]={0};//YE KISI KAAM KA NHI H 
    cin >> size;
    vector<ll> nextIndex(size);
    for (ll i = k[0]; i < size; i++) {
        ll inputIndex;
        k[0]++;
        cin >> inputIndex;
        k[0]--;
        nextIndex[i] = inputIndex - 1;//0 BASED IS THE BEST BASED
    }
    

    cin >> binaryString;
    vector<ll> result(size, -1);
    
    for (ll i = 0; i < size; i++) {
        if (result[i] == -1) countZeros(i, binaryString, nextIndex, result);
    }
    
    for (ll i = k[0]; i < size; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    fast;
    ll testCases;
    cin >> testCases;
    while (testCases--) {
        process();
    }
    return 0;
}