#include <iostream>
#include "Integer.h"
using namespace std;

int main() {
	cout << "Test 1. Constructors\n";
	cout << "Test 1-1. Construct with fundamental types\n";

	char a = -123;
	unsigned char b = 123;
	short c = 12345;
	unsigned long d = 3987654321;
	int e = 987654321;
	unsigned long long f = 314159265358979ULL;

	Integer int_a = a;
	Integer int_b = b;
	Integer int_c = c;
	Integer int_d = d;
	Integer int_e = e;
	Integer int_f = f;
	Integer int_g = 0;
	Integer int_h = -2718281828459;
	Integer int_i = -1357986420;
	Integer int_j = -1;
	Integer int_k;
	cout << (int)a << ' ' << int_a.size() << '\n';
	cout << (int)b << ' ' << int_b.size() << '\n';
	cout << c << ' ' << int_c.size() << '\n';
	cout << d << ' ' << int_d.size() << '\n';
	cout << e << ' ' << int_e.size() << '\n';
	cout << f << ' ' << int_f.size() << '\n';
	cout << "0" << ' ' << int_g.size() << '\n';
	cout << "-2718281828459" << ' ' << int_h.size() << '\n';
	cout << "-1357986420" << ' ' << int_i.size() << '\n';
	cout << "-1" << ' ' << int_j.size() << '\n';
	cout << "0" << ' ' << int_k.size() << '\n';

	cout << "Test 1-1 finished\n";
	cout << '\n';

	cout << "Test 1 finished\n";
	cout << '\n';

	cout << "Test 2. Compare\n";
	cout << "num1 num2 == != < > <= >=\n";
	cout << int_e.size() << ' ' << int_i.size() << ' '
	<< (int_e == int_i) << ' ' << (int_e != int_i) << ' '
	<< (int_e < int_i) << ' ' << (int_e > int_i) << ' '
	<< (int_e <= int_i) << ' ' << (int_e >= int_i) << '\n';
	
	cout << int_g.size() << ' ' << int_k.size() << ' '
	<< (int_g == int_k) << ' ' << (int_g != int_k) << ' '
	<< (int_g < int_k) << ' ' << (int_g > int_k) << ' '
	<< (int_g <= int_k) << ' ' << (int_g >= int_k) << '\n';

	return 0;
}