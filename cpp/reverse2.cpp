// Exercise: Save and print reversed string and vector. Reverse them by using iterators
// void rev_str(string &s);
// void rev_vec(vector <int> &v);
//
// Take 2: Not using an extra buffer
//
//

#include <string>
#include <vector>
#include <iostream>
using namespace std;


void rev_str(string &s)
{
    int i=0;              // Item in the string moving forward
    int j=s.length()-1;   // Item in the string moving backward (calulated from i)
    while(i<j)
    {
        char tmp = s[i];         // Keep current item in a temporary char
        s[i++] = s[j];           // Replace with item going backwards
        s[j--] = tmp;            // Use the temporary char
    }
}

void rev_vector(vector<int> &v)
{
    int i=0;              // Item in the vector moving forward
    int j=v.size()-1;     // Item in the vector moving backward (calulated from i)
    while(i<j)
    {
        int tmp = v[i];         // Keep current item in a temporary int
        v[i++] = v[j];           // Replace with item going backwards
        v[j--] = tmp;            // Use the temporary int
    }
}

void print_vector(vector<int> vec) {
    cout << "[";
    for(int i=0; i < vec.size(); i++) {
        cout << vec[i];
        if(i != vec.size()-1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main()
{
    cout << "=============== PART I: Strings ===================\n";
    vector<string> strings={"","a","abcdefg","abcdefgh"};

    for(string st : strings) {
        cout << "The original string is '" << st << "' length is " << st.length() << endl;
        rev_str(st);
        cout << "Reversed string: '"<< st << "'" << endl;
    }

    cout << "=============== PART II: Vectors ===================\n";
    vector<vector<int>> victors={{12,34,56,78},{123,456,789},{12345},{}};
    for(vector<int> vic : victors) {
        cout << "Original Vector: ";
        print_vector(vic);
        rev_vector(vic);
        cout << "Reversed Vector: ";
        print_vector(vic);
    }
    return 0;
}

// Remarks:
// Use s.length() instead of sizeof(s)  <- done
// Try not to use an extra buffer       <- done
// Check what happens when the string is of length zero, or one  <- done
//

