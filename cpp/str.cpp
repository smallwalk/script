#include <iostream>
#include <string>

using namespace std;

int main() 
{
	char str[20] = "Hello ";
	cout << str << endl;

	string str2 = "Achiving success and ...";
	string str3 = "personal";
	str2+=str3;
	cout << str2 << endl;
	return 0;
}
