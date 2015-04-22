#include <iostream>

using namespace std;

int max(int a, int b)
{
	return a > b ? b : a;
}

int main()
{
	
	int a = 5;
	int b = 3;
	int c = max(a, b);
	cout << "max:" << c << endl;
	return 0;
}
