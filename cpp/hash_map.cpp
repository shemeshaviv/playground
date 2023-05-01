#include <iostream>
#include <map>
using namespace std;

int main(int argc, char* argv[])
{
    map<string, int> m;
    m["a"] = 10;
    m["b"] = 20;
    m["c"] = 30;

    // Direct addressing key->value without testing
    cout << "Key b, value is: " << m["b"] << endl;
    // Finding using iterator
    map<string, int>::iterator i = m.find("c");
    if(i != m.end())
        cout << "Key " << i->first << ", value is: " << i->second << endl;
    // No key found
    i = m.find("z");
    if(i == m.end())
        cout << "Key z not found as expected" << endl;
    return 0;
}
