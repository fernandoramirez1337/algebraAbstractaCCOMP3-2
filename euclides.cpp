#include <iostream>
#include <string>

using namespace std;


int divisionEntera(int a, int n)
{
	int q = a / n;
	int r = a - (q * n);
	if (a < 0)
	{
		q--;
		r += n;
	}
	//cout << r << endl;
	cout << a << " = " << q << " * " << n << " + " << r << endl;
	return q;
}

int euclidesExtendido(int a, int b, int &x, int &y) 
	{
	int q, r1 = a, r2 = b, r, s1 = 1, s2 = 0, s, t1 = 0, t2 = 1, t;
	while (r2 > 0)
	{
		q = r1 / r2;

		r = r1 - q * r2;
		r1 = r2, r2 = r;

		s = s1 - q * s2;
		s1 = s2, s2 = s;

		t = t1 - q * t2;
		t1 = t2, t2 = t;
	}
	x = s1;
	y = t1;
	return r1;
	//cout << a << " * " << x << " + " << b << " * " << y << " = " << r1 << endl;
}


int euclides(int a, int b)
{
	int q, r, tmp;
	while (b>0)
	{
		q = a / b;
		r = a - q * b;
		// A = Q * B + R
		a = b;
		b = r;
	}
	return a;
}

void ee(int a, int b)
{
	int x, y;
	if (euclides(a, b) != 1)
		return;
	int r = euclidesExtendido(a, b, x, y);
	cout << a << " * " << x << " + " << b << " * " << y << " = " << r << endl;
}

int main()
{
    ee(250, 111);

    return 0;
}