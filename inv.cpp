#include <iostream>
using namespace std;

// Function to implement the Extended Euclidean Algorithm
int extended_gcd(int x, int b, int &a, int &y) {
    if (x == 0) {
        a = 0;
        y = 1;
        return b;
    }

    int a1, y1;  
    int gcd = extended_gcd(b % x, x, a1, y1);

    a = y1 - (b / x) * a1;
    y = a1;

    return gcd;
}


int find_a(int x, int b) {
    int a, y;  
    int gcd = extended_gcd(x, b, a, y);

    if (gcd != 1) {
        throw invalid_argument("No modular inverse exists, x and b are not coprime.");
    }


    return (a % b + b) % b;
}

int main() {
    int x, b;
    cout << "Enter values for x and b: ";
    cin >> x >> b;

    try {
        int a = find_a(x, b);
        cout << "The value of a such that (a * x) % b = 1 is: " << a << endl;
    } catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }

    return 0;
}
