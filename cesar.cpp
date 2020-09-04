#include <iostream>
#include <string>

using namespace std;

int mod(int a, int n)
{
	if (!a) 
	{
		return 0;
	}
	int temp = a / n;
	int r = a - (temp * n);
	if (r < 0) 
	{
		r += n;
	}
	return r;
}

class cesar
{
private:
	int clave;
	string abc = "abcdefghijklmnopqrstuvwxyz ";

public:
	cesar(int clave)
	{
		this->clave = clave;
	}
	string cifrar(string txt) 
	{
		string mensaje;
		for (int i = 0; i < txt.size(); i++) 
		{
			int temp = abc.find(txt[i]) + clave;
			if (temp > abc.size()) 
			{
				temp = mod(temp, abc.size());
			}
			mensaje += abc[temp];
		}
		return mensaje;
	}
	string descifrar(string txt, int nclave)
	{
		string mensaje;
		for (int i = 0; i < txt.size(); i++) 
		{
			int temp = abc.find(txt[i]) - nclave;
			if (temp < 0) 
			{
				temp = mod(temp, abc.size());
			}
			mensaje += abc[temp];
		}
		return mensaje;
	}

};

int main()
{
	///*
	int clave1 = 679;
	int clave2 = 6779;
	cesar yo(clave1);
	cesar tu(clave2);
	string mensaje1 = yo.cifrar("bugatti");
	string mensaje2 = tu.descifrar(mensaje1, clave1);
	cout << mensaje1 << endl;
	cout << mensaje2 << endl;
	//*/
	
	return 0;
}