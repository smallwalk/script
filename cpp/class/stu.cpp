#include <iostream>
#include <string>

using namespace std;

class CBase {
	public:
		CBase (string s1, string s2) : name(s1) , id("base-" + s2) {
			cout << "Hello" << endl;
		}
		void show() {
			cout << "name: " << name << endl;
			cout << "id: " << id << endl;
		}
	private:
		string id;
		string name;
};

class CDerive : public CBase {
	public:
		CDerive(string s1, int a, string s2) : age(a), id("Derive-" + s2), CBase(s1, s2) {}
		void show() {
			cout << "id: " << id << endl;
			cout << "age: " << age << endl;

			CBase::show();
		}
	private:
		int age;
		string id;
};

int main() 
{
	CDerive d("chaoguo", 27, "101211");
	d.show();

	cout << "---------------------------------" << endl;

	d.CBase::show();
	return 0;
}
