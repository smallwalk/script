#include <iostream>
#include <string>

int main()
{
    using namespace std;

    string name="01234 5678";
    int pos = name.find(" ", 0);
    cout << name << " \npos=" << pos << endl;

    string s=name.substr(0, pos);
    string n=name.substr(pos + 1, name.size());
    cout << "0~" << pos << "is " << s << endl;
    cout << pos  << "+1 is " << n << endl;
    cout << name.size() << endl;
    string l=name.substr(name.size()-1, name.size());
    cout << l << endl;
    return 0;
}
