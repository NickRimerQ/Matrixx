#include "Header.h"
#include "Matrixx.cpp"

int main()
{
	//Matrix<int> a;
	//cin >> a;
	//cout << "------------------------" << endl;
	//cout << a;
	//cout << "________________________" << endl;
	Vector<int> a(3);
	cin >> a;
	Vector<int> b(a);
	Vector<int> c(3);
	cin >> c;
	cout << "------------------------" << endl;
	a = c;
	cout << (a == c) << endl;
	cout << a;
	cout << c;
	cout << b;
	return 0;
}