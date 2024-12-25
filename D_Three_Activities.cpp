#include <bits/stdc++.h>

using namespace std;

pair<vector<int>, vector<int>> findThreeMaxElements(const vector<int>& vec) {
    vector<int> maxElements(3, INT_MIN);
    vector<int> indices(3, -1);

    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] > maxElements[0]) {
            maxElements[2] = maxElements[1];
            indices[2] = indices[1];
            maxElements[1] = maxElements[0];
            indices[1] = indices[0];
            maxElements[0] = vec[i];
            indices[0] = i;
        } else if (vec[i] > maxElements[1]) {
            maxElements[2] = maxElements[1];
            indices[2] = indices[1];
            maxElements[1] = vec[i];
            indices[1] = i;
        } else if (vec[i] > maxElements[2]) {
            maxElements[2] = vec[i];
            indices[2] = i;
        }
    }

    return make_pair(maxElements, indices);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v1(n);
        vector<int> v2(n);
        vector<int> v3(n);
        for (int i = 0; i < n; i++) {
            cin >> v1[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> v2[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> v3[i];
        }

        auto p1 = findThreeMaxElements(v1);
        auto p2 = findThreeMaxElements(v2);
        auto p3 = findThreeMaxElements(v3);

        int maxFriends = INT_MIN;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (p1.second[i] != p2.second[j] && p1.second[i] != p3.second[k] && p2.second[j] != p3.second[k]) {
                        int sum = p1.first[i] + p2.first[j] + p3.first[k];
                        maxFriends = max(maxFriends, sum);
                    }
                }
            }
        }

        cout << maxFriends << endl;
    }

    return 0;
}