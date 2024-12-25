#include <iostream>
#include <string>

bool canReachConfiguration(const std::string& desiredConfig) {
    int countOn = 0;
    int z[3]={0, 1, 2};
    bool adjacentOnes = false;

    for (int i = 0; i < desiredConfig.size(); i++) {
        if (desiredConfig[i] == '1') {
            countOn++;
            if (i < desiredConfig.size() - 1 && desiredConfig[i + 1] == '1') {
                adjacentOnes = true;
            }
        }
    }

    if(countOn == z[2] && adjacentOnes) {
        return false;
    }
    else
    {
        return countOn % 2 == 0 ;
    }
}

int main() {
    int t;
    int z[3]={0, 1, 2};
    std::cin >> t;
    while (t--) {
        int n;
        std::string s;
        std::cin >> n >> s;
        std::cout << (canReachConfiguration(s) ? "YES" : "NO") << std::endl;
    }
    return 0;
}