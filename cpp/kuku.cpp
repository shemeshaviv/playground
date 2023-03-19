#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Kuku
{
public:
   Kuku() : _i{0}, _s{"default"}
   {
      cout << "Kuku::C'tor(0) - default\n";
   }
   Kuku(int i) : _i{i}, _s{"default"}
   {
      cout << "Kuku::Kuku(" << _i << ")\n";
   }
   Kuku(int i, string s) : _i{i}, _s{s}
   {
      cout << "Kuku::Kuku(" << _i << "," << _s << ")\n";
   }
   Kuku(const Kuku &other) : _i{other._i}
   {
      cout << "Kuku::Copy(" << _i << ")\n";
   }
   Kuku &operator=(const Kuku &other)
   {
      _i = other._i;
      cout << "Kuku::operator=(" << _i << ")\n";
      return *this;
   }

   ~Kuku()
   {
      cout << "Kuku::D'tor(" << _i << ")\n";
   }

   int getI() const {
      return _i;
   }

private:
   int _i;
   string _s;
};

int main()
{
   Kuku k1(10);
   Kuku k2(k1);

   cout << "k2: " << k2.getI() << "\n";

   Kuku k3;
   k3 = k2;

   Kuku k4 = k2;

   vector<Kuku> v;
   v.push_back(Kuku(30));
   v.push_back(Kuku(30));

   vector<Kuku> v1{Kuku(10),Kuku(20)};

   vector<Kuku> v2{10,20,{30,"hello"}};

   return 0;
}

