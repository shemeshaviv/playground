// Exercise 3: Implement a class that represents insensitive case and includes
// Revision by comments of previous exercise.
// Implementation of additional constructors
// Overriding more operators
//

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class CaseInsensitive
{
    private:
        string _str;        // Contains original string
        string _lowercase;  // Contains case-insensitive representation of the original string as lower-case
        void setupCaseInsensitive()
        {
            _lowercase = _str;
            transform(_lowercase.begin(), _lowercase.end(), _lowercase.begin(), ::tolower);
        }
    public:
        CaseInsensitive()
        {
            cout << "//C'tor Default (_str is empty)\n";
        }

        CaseInsensitive(const string& s) : _str{s}
        {
            cout << "//C'tor of " << _str << endl;
            setupCaseInsensitive();
        }

        CaseInsensitive(string&& s) : _str{move(s)}
        {
            cout << "//Move C'tor of " << _str << endl;
            setupCaseInsensitive();
        }

        CaseInsensitive(const CaseInsensitive& other) : _str{other._str}, _lowercase{other._lowercase}
        {
            cout << "//Copy C'tor of " << _str << endl;
        }

        ~CaseInsensitive()
        {
            cout << "//Destructing " << _str << endl;
        }

        string getStr() const
        {
            return _str;   // Returns the original string
        }

        string getLowerCaseStr() const
        {
            return _lowercase;  // Returns the lower-case-insensitive string
        }

        void replaceStrTo(const string& newstr)
        {
            _str = newstr;
            setupCaseInsensitive();
        }

        bool operator<(const CaseInsensitive& other) const
        {
            return _lowercase < other._lowercase;
        }

        CaseInsensitive& operator=(const CaseInsensitive& other)
        {
            cout << "//Assignment (copy) of lvalue: "<< other.getStr() << endl;
            _str = other._str;
            _lowercase = other._lowercase;
            return *this;
        }

        CaseInsensitive& operator=(CaseInsensitive&& ci)
        {
            cout <<"//Assignment (move) of rvalue: " << ci.getStr() << endl;
            _str = move(ci._str);
            _lowercase = move(ci._lowercase);
            return *this;
        }
};

ostream &operator<<(ostream& os, const CaseInsensitive& ci)
{
    os << "'" << ci.getStr() << "'('" << ci.getLowerCaseStr() << "')";
    return os;
}

int main()
{
    cout << "============================= Part I: Constructors  =======================================\n";
    CaseInsensitive ci{};                            // C'tor Default (_str is empty)
    CaseInsensitive ci1{"HeLlo"}, ci2{"gOOdBye"};    // Move C'tor of HeLlo, Move C'tor of gOOdBye
    CaseInsensitive ci3{ci1};                        // Copy C'tor of HeLlo

    cout << "============================= Part II: Assignment  =======================================\n";
    CaseInsensitive ci4{"Old_Value"};                //Move C'tor of Old_Value
    CaseInsensitive ci5{"New_Value"};                //Move C'tor of New_Value
    ci4 = ci5;   // lvalue                           //Assignment (copy) of lvalue: New_Value
    cout << "CaseInsensitive ci4 after assignment: " << ci4 << endl;          //'New_Value'('new_value')
    ci5.replaceStrTo("Different_New_Value");
    cout << "CaseInsensitive ci4 should still remain: " << ci4 << endl;       //'New_Value'('new_value')
    ci4 = {"Even_more_NeWer"};   // rvalue           //Move C'tor of Even_more_NeWer, Assignment (move) of rvalue: Even_more_NeWer, Destructing
    cout << "CaseInsensitive ci4 is changed to: " << ci4 << endl;
    CaseInsensitive ci8{"Something_ELse"};
    ci4 = move(ci8);
    cout << "CaseInsensitive ci4 is changed (again) to: " << ci4 << endl;
    cout << "ci8: " << ci8 << endl;
    cout << "============================= Part III: Compare  =======================================\n";
    if(ci2<ci1) {
        cout << ci2 << " is prior to " << ci1 << "\n";
    }
    else {
        cout << ci2.getStr() << " is greater or equal than " << ci1.getStr() << "\n";
    }
    cout << "============================== Vector ===========================================\n";

    CaseInsensitive c1("apple"),c2("Berry"),c3("cherry"),c4("Date");
    vector<CaseInsensitive> vec = {c1,c2,c3,c4,CaseInsensitive{"Carrot"}};
    cout << "============================= SORTING ======================================\n";
    sort(vec.begin(),vec.end());
    cout << "============================= Part IV: Print Sorted Vector  =======================================\n";

    for(CaseInsensitive &item : vec) {
        cout << item.getStr() << " ";
    }
    cout << endl;
    cout << "============================================================================\n";
    return 0;
}

