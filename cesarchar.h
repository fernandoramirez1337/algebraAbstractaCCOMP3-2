#include <iostream>

using namespace std;

const char* abcchar = "abcdefghijklmnopqrstuvwxyz ";
int abclen = 26;

void printchar(char* txt, int l)
{
	for (int i = 0; i < l; i++)
		cout << txt[i];
	cout << endl;
}

class cesarchar
{
private:
	int clave;
	int findchar(char val)
	{
		for (int i = 0; i < abclen; i++)
		{
			if (abcchar[i] == val)
				return i;
		}
		return 0;
	}

public:
	cesarchar(int clave)
	{
		this->clave = clave;
	}
	char* cifrar(char* txt, int l)
	{
		//int l = 7;
		char* mensaje = new char(l-1);
		for (int i = 0; i < l; i++)
		{
			int tmp = findchar(txt[i]) + clave;
			if (tmp > abclen)
				tmp = mod(tmp, abclen);
			mensaje[i] = abcchar[tmp];
			//txt[i] = abcchar[tmp];
		}
		return mensaje;
	}
	char* descifrar(char* txt, int clave)
	{
		int l = 7;
		char* mensaje = new char(l);
		for (int i = 0; i < l; i++)
		{
			int tmp = findchar(txt[i]) - clave;
			if (tmp < 0)
				tmp = mod(tmp, abclen);
			mensaje[i] = abcchar[tmp];
		}
		return mensaje;
	}
};

int main()
{

	int clave1 = 679;
	int clave2 = 6779;

	cesarchar p1(clave1);
	cesarchar p2(clave2);
	char bugatti[] = {'b','u','g' ,'a' ,'t' ,'t' ,'i' };
	int tam = 7;
	char* mensaje3 = p1.cifrar(bugatti,tam);
	printchar(mensaje3,tam);
	char* mensaje4 = p2.descifrar(mensaje3, clave1, tam);
	printchar(mensaje4,tam);

	return 0;
}
