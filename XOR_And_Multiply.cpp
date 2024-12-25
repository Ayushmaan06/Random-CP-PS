#include <iostream>

void solve(int X) {
    // For any X, a solution is always (X, X)
    // because (X & X) = X and (X ^ X) = 0, both of which are divisible by X
    std::cout << X << " " << X << "\n";
}

int main() {
    int T;
    std::cin >> T;
    for(int t = 0; t < T; t++) {
        int X;
        std::cin >> X;
        solve(X);
    }
    return 0;
}