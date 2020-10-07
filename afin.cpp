#include <iostream>
#include <string>
#include <time.h>

using namespace std;

const string abc = "abcdefghijklmnopqrstuvwxyz";
int abc_tam = abc.size();


int mod(int a, int n)
{
	int temp = a / n;
	int r = a - (temp * n);
	if (r < 0)
	{
		r += n;
	}
	return r;	
}

int divisionEntera(int a, int n)
{
	int q = a / n;
	int r = a - (q * n);
	if (a < 0)
	{
		q--;
		r += n;
	}
	//cout << a << " = " << q << " * " << n << " + " << r << endl;
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
	int q, r;
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

class afin
{
private: 
	int clave_a, clave_b, x;
	int generar_x()
	{
		int x, y;
		euclidesExtendido(clave_a, abc_tam, x, y);
		return mod(x,abc_tam);
	}
	void generar_claves()
	{
		srand(time(NULL));
		clave_a = mod(rand(), abc_tam);
		while (euclides(clave_a, abc_tam) != 1)
		{
			clave_a = mod(rand(), abc_tam);
		}
		clave_b = mod(rand(), abc_tam);
	}
public:
	afin()
	{
		generar_claves();
		x = generar_x();
	}
	afin(int clave_a, int clave_b)
	{
		this->clave_a = clave_a;
		this->clave_b = clave_b;
		x = generar_x();
	}

	string cifrar(string txt)
	{
		string mensaje;
		int txt_size = txt.size();
		for (int i = 0; i < txt_size; i++)
		{
			int temp = mod(clave_a*abc.find(txt[i])+clave_b,abc_tam);
			mensaje += abc[temp];
		}
		return mensaje;
	}
	string descifrar(string txt)
	{
		string mensaje;
		int txt_size = txt.size();
		for (int i = 0; i < txt_size; i++)
		{
			int temp = mod(x * (abc.find(txt[i]) - clave_b), abc_tam);
			mensaje += abc[temp];
		}
		return mensaje;
	}	
	int geta() { return clave_a; }
	int getb() { return clave_b; }
	void claves() { cout << "a = " << clave_a << ", b = " << clave_b << endl; }

};


int main()
{

	afin yo;
	yo.claves();
	afin tu(yo.geta(),yo.getb());
	string msg_1 = yo.cifrar("itscool");
	string msg_2 = tu.descifrar(msg_1);

	cout << msg_1 << endl;
	cout << msg_2 << endl;

	return 0;
}
