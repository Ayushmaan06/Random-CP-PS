#include <bits/stdc++.h>
#define OPTIMIZE std::ios::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define LL long long
#define MODULO 998244353

using namespace std;

LL fastExponentiation(int exp) {
    LL result = 1;
    LL base = 2;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % MODULO;
        base = (base * base) % MODULO;
        exp /= 2;
    }
    return result;
}

int main() {
    OPTIMIZE;
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int size;
        cin >> size;

        vector<int> elements(size);
        int zeroCount = 0, oneCount = 0, twoCount = 0;

        for (int i = 0; i < size; ++i) {
            cin >> elements[i];
            if (elements[i] == 0) zeroCount++;
            else if (elements[i] == 1) oneCount++;
            else if (elements[i] == 2) twoCount++;
        }

        // The number of all non-empty subsequences of size n
        LL totalSubsequences = fastExponentiation(size) - 1;

        // Calculate the contributions from MEX = 0, MEX = 1, and MEX = 2
        LL pow2_zeros = fastExponentiation(zeroCount);
        LL pow2_ones = fastExponentiation(oneCount);
        LL pow2_twos = fastExponentiation(twoCount);

        LL mex1Contribution = (pow2_zeros - 1 + MODULO) % MODULO;
        LL mex2Contribution = (pow2_zeros - 1) * (pow2_ones - 1) % MODULO;
        LL mex3Contribution = (pow2_zeros - 1) * (pow2_ones - 1) % MODULO * (pow2_twos - 1) % MODULO;

        // Sum up the contributions
        LL finalResult = (mex1Contribution + mex2Contribution + mex3Contribution) % MODULO;
        
        // Output the final result for this test case
        cout << finalResult << endl;
    }

    return 0;
}
