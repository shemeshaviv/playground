// Exercise 2: Implement a class that represents insensitive case.
// And apply the "<" operator for sorting it
//

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class CaseInsensitive
{
    private:
        string _str;   // Contains original string
        string _lowercase; // Contains case-insensitive representation of the original string as lower-case
    public:
        CaseInsensitive(const string &&s) : _str(move(s))
        {
            _lowercase = _str;
            transform(_lowercase.begin(), _lowercase.end(), _lowercase.begin(), ::tolower);
        }
        ~CaseInsensitive()
        {
        }
        string getStr()
        {
            return _str;   // Returns the original string
        }
        string getLowerCaseStr()
        {
            return _lowercase;  // Returns the lower-case-insensitive string
        }
        bool operator<(const CaseInsensitive &other) const
        {
            return _lowercase < other._lowercase;
        }
};

int main()
{
    CaseInsensitive ci1("HeLlo"), ci2("gOOdBye");
    if(ci2<ci1) {
        cout << ci2.getStr() << " is prior to " << ci1.getStr() << "\n";
    }
    else {
        cout << ci2.getStr() << " is greater or equal than " << ci1.getStr() << "\n";
    }

    CaseInsensitive c1("apple"),c2("Berry"),c3("cherry"),c4("Date");
    vector<CaseInsensitive> vec = {c1,c2,c3,c4,CaseInsensitive{"Carrot"}};
    sort(vec.begin(),vec.end());
    for(CaseInsensitive &item : vec) {
        cout << item.getStr() << " ";
    }
    cout << endl;

    return 0;
}

