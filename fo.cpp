#include <iostream>
#include <string>

class MathOperations {
public:
    // Inline function to add two integers
    inline int add(int a, int b) {
        return a + b;
    }

    // Inline function to add three integers
    inline int add(int a, int b, int c) {
        return a + b + c;
    }

    // Inline function to add two doubles
    inline double add(double a, double b) {
        return a + b;
    }

    // Inline function to concatenate two strings
    inline std::string add(const std::string& a, const std::string& b) {
        return a + b;
    }
};

int main() {
    MathOperations math;

 
    int sum1 = math.add(10, 20);          
    int sum2 = math.add(10, 20, 30);      
    double sum3 = math.add(10.5, 20.3);   
    std::string concat = math.add("Hello, ", "World!"); 


    return 0;
}