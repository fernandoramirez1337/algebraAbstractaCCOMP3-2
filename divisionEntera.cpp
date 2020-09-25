#include <iostream>
using namespace std;

int divisionEntera(int a, int n)
{
	int q = a / n;
	int r = a - (q * n);
	if (a<0)
	{
		q--;
		r += n;
	}
	//cout << r << endl;
	return q;
}

int main()
{
	
	cout << divisionEntera(255, 11) << endl;
	cout << divisionEntera(-255, 11) << endl;
    
	return 0;

}
