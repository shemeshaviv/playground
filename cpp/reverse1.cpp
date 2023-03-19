// Exercise: Save and print reversed string and vector. Reverse them by using iterators
// void rev_str(string &s);
// void rev_vec(vector <int> &v);

#include <string>
#include <vector>
#include <iostream>
using namespace std;


void rev_str(string &s)
{
    auto ptr = end(s);
    char rev[sizeof(s)];
    int i = 0;
    do
    {
        ptr=prev(ptr);
        rev[i] = *ptr;
        i++;
    } while(ptr != begin(s));
    s = rev;
}

int main()
{
    string st = "abcdefg";
    cout << "The string is '" << st << "'" << endl;
    rev_str(st);
    cout << "Reversed string: '"<< st << "'" << endl;
    return 0;
}

// Remarks:
// Use s.length() instead of sizeof(s)
// Try not to use an extra buffer
// Check what happens when the string is of length zero, or one
//

