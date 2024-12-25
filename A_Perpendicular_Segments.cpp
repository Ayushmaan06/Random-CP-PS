#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;
int main(){
    fast;
    int t;
    cin>>t;
    while(t--){
        int X, Y, K;
        cin >> X >> Y >> K;
        int w =min(X,Y);
        int Ax = 0, Ay = 0, Bx = w, By = w;
        
        int Cx = 0, Cy = w, Dx = w, Dy = 0;
        
        
        cout << Ax << " " << Ay << " " << Bx << " " << By << endl;
        cout << Cx << " " << Cy << " " << Dx << " " << Dy << endl;
    }
}