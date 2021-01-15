#include <iostream>
#include <cmath>

using namespace std;

int fibonacci(int n);

int main()
{
    double golden_ratio = (1.0 + sqrt(5.0)) / 2.0; // theoretical golden ratio
    double error_margin = 0.0000000001; // targeted maximum error margin
    bool in_error_margin = false;

    int counter = 1;
    int previous = fibonacci(0);
    int current = fibonacci(0);
    double ratio = 0.0;
    double diff = 0.0;
    
    while (!in_error_margin) { // continue until result is in error margin
        current = fibonacci(counter);
        
        if (previous > 0) { // skip if "divide by zero" expected 
            
            ratio = (double) current / (double) previous;
            diff = abs(ratio - golden_ratio);
            cout << "current " << current << ", previous " << previous << ", ratio " << ratio << ", diff " << diff << endl;
            
            if (diff < error_margin) {
                in_error_margin = true;
                break;
            }
        }
        previous = current;
        counter++;
    }
    
    if (in_error_margin) {
        cout << "result " << current << endl;
    }
    
    return 0;
}

// recursive fibonacci implementation
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    
    if (n == 1) {
        return 1;
    }
    
    return fibonacci(n - 1) + fibonacci(n - 2);
}
