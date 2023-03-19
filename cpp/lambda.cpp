// Implementation of lambda functions. Using it to calculate the maximal and minimal values in an int vector

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

int main()
{
    int max = INT8_MIN;
    int min = INT8_MAX;
    vector<int> vec = {30,50,20,10};
    for_each(begin(vec), end(vec), [&max](int item){if(item>max) {max=item;}});
    for_each(begin(vec), end(vec), [&min](int item){if(item<min) {min=item;}});
    cout << "Maximal value is " << max << endl;
    cout << "Minimal value is " << min << endl;
    return 0;
}

