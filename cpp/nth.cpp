#include <iostream>
using namespace std;

double nth(double x, int n)   // assume 0<=n
{
    double res = 1;
    int i = 0;
    while (i<n) {   // while-loop: do while the condition is true (§1.7.1)
        res*=x;
        ++i;
    }
    return res;
}


int main(void)
{
    //constexpr double x = 2;
    //constexpr int n = 5;
    double x;
    int n;
    cout << "Enter base: ";
    cin >> x;
    cout << "Enter multiplier: ";
    cin >> n;
    double nth_result = nth(x, n);
    cout << "nth ("<< x << ", "<< n <<") is "<< nth_result << endl;
    return 0;
}

