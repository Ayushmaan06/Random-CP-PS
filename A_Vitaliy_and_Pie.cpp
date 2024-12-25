#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    unordered_map<char, int> keys;  // To store the count of each key type
    int keys_needed = 0;

    for (int i = 0; i < s.length(); ++i) {
        if (i % 2 == 0) {
            // This is a key position
            keys[s[i]]++;
        } else {
            // This is a door position
            char door = s[i];
            char needed_key = door + 32;  // Convert uppercase door to lowercase key
            if (keys[needed_key] > 0) {
                keys[needed_key]--;  // Use the key
            } else {
                keys_needed++;  // Buy the key
            }
        }
    }

    cout << keys_needed << endl;

    return 0;
}
