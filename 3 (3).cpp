#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    
    string commands;
    cin >> commands;
    
    vector<pair<ll, ll>> leaves(N);
    unordered_map<ll, set<ll>> leaf_map;
    
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        leaves[i] = {x, y};
        leaf_map[x].insert(y);
    }
    
    ll current_x = leaves[0].first;
    ll current_y = leaves[0].second;
    leaf_map[current_x].erase(current_y);
    
    for (char command : commands) {
        ll new_x = current_x, new_y = current_y;
        bool found = false;
        
        for (int Z = 1; Z <= 1000000; ++Z) {
            if (command == 'A') {
                new_x = current_x + Z;
                new_y = current_y + Z;
            } else if (command == 'B') {
                new_x = current_x + Z;
                new_y = current_y - Z;
            } else if (command == 'C') {
                new_x = current_x - Z;
                new_y = current_y + Z;
            } else if (command == 'D') {
                new_x = current_x - Z;
                new_y = current_y - Z;
            }
            
            if (leaf_map.count(new_x) && leaf_map[new_x].count(new_y)) {
                current_x = new_x;
                current_y = new_y;
                leaf_map[current_x].erase(current_y);
                found = true;
                break;
            }
        }
        
        if (!found) {
            break;
        }
    }
    
    cout << current_x << " " << current_y << endl;
    return 0;
}