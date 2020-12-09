#include "aa.h"

ZZ mod(ZZ a, ZZ n)
{
	ZZ temp = a / n;
	ZZ r = a - (temp * n);
	if (r < 0)
	{
		r += n;
	}
	return r;
}

ZZ euclidesExtendido(ZZ a, ZZ b, ZZ& x, ZZ& y)
{
	ZZ q, r1 = a, r2 = b, r, s1 = ZZ(1), s2 = ZZ(0), s, t1 = ZZ(0), t2 = ZZ(1), t;
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
	x = s1,	y = t1;

	return r1;
}

ZZ euclides(ZZ a, ZZ b)
{
	ZZ q, r;
	while (b > 0)
	{
		q = a / b;
		r = a - q * b;
		// A = Q * B + R
		a = b;
		b = r;
	}
	return a;
}

void ee(ZZ a, ZZ b)
{
	ZZ x, y;
	if (euclides(a, b) != 1)
		return;
	ZZ r = euclidesExtendido(a, b, x, y);
	cout << a << " * " << x << " + " << b << " * " << y << " = " << r << endl;
}

ZZ expmod(ZZ a, ZZ e, ZZ n)
{
	ZZ res = ZZ(1);
	ZZ x = mod(a, n);
	for (; e>ZZ(0); e /= ZZ(2))
	{
		if (mod(e, ZZ(2)) > ZZ(0))
			res = mod(res * x, n);
		x = mod(x * x, n);
	}
	return res;
}

ZZ inversa(ZZ a, ZZ n)
{
	ZZ x, y;
	euclidesExtendido(a, n, x, y);
	return mod(x, n);
}

//INFORME
/*
ZZ alg_1(ZZ a, ZZ p, ZZ n)
{
	ZZ r = ZZ(1);
	for (ZZ i = ZZ(1); i <= p; i++)
		r = mod(r * a, n);
	return r;
}

ZZ alg_2(ZZ g, ZZ A, ZZ N)
{
	ZZ a = g; ZZ b = ZZ(1);
	while (A > ZZ(0))
	{
		if (mod(A, ZZ(2)) == ZZ(1))
			b = mod(b * a, N);
		a = mod(a * a, N); A /= ZZ(2);
	}
	return b;
}

ZZ alg_2_bit(ZZ g, ZZ A, ZZ N)
{
	ZZ a = g; ZZ b = ZZ(1);
	bitset<16> bset(conv<int>(A));
	for (int i = 0; i < 16; i++)
	{
		if (bset[i])
			b = mod(b * a, N);
		a = mod(a * a, N);
	}
	return b;
}

void restochino(vector<ZZ> a_i, vector<ZZ> p_i)
{
	int tam = p_i.size(); ZZ x_0 = ZZ(0); ZZ P = ZZ(1); vector<ZZ> P_i(tam,ZZ(0)); vector<ZZ> q_i(tam, ZZ(0));

	if (!cooprimos(p_i))
		return;
	for (int i = 0; i < tam; i++)
		P *= p_i[i];
	for (int i = 0; i < tam; i++)
	{
		P_i[i] = P / p_i[i];
		q_i[i] = inversa(P_i[i], p_i[i]);
	}
	for (int i = 0; i < tam; i++) 
		x_0 += mod(a_i[i] * P_i[i] * q_i[i], P);
	x_0 = mod(x_0, P);
	cout << "X = " << x_0 << " + " << P << "k" << endl;
}

ZZ fastExp(ZZ a, ZZ p, ZZ n)
{
	ZZ t;
	if (p == ZZ(0))
		return ZZ(1);
	if (mod(p, ZZ(2)) == ZZ(0))
	{
		t = fastExp(a, p / ZZ(2), n);
		return mod(t * t, n);
	}
	t = fastExp(a, (p - ZZ(1)) / ZZ(2), n);
	return mod(a * mod(t * t, n), n);
}

ZZ modExp(ZZ a, ZZ b, ZZ n)
{
	ZZ c = ZZ(0); ZZ d = ZZ(1);
	vector<bool> b_k = ZZ_binario(b); int b_k_tam = b_k.size();
	for (int i = 0; i < b_k_tam; i++)
	{
		c *= ZZ(2);
		if (b_k[i])
		{
			c++;
			d = mod(d * a, n);
		}
		a = mod(a * a, n);
	}
	return d;
}

ZZ funExp(ZZ a, ZZ b, ZZ n) 
{
	ZZ exp = ZZ(1); ZZ x = mod(a, n);
	while (b > ZZ(0))
	{
		if (mod(b, ZZ(2)) == ZZ(1))
			exp = mod(exp * x, n);
		x = mod(x * x, n);
		b /= ZZ(2);
	}
	return exp;
}

bool cooprimos(vector<ZZ> a)
{
	int tam = a.size();
	for (int i = 0; i < tam - 1; i++)
	{
		for (int j = i + 1; j < tam; j++)
		{
			if (euclides(a[i], a[j]) != ZZ(1) || a[i] == a[j])
				return 0;
		}
	}
	return 1;
}

vector<bool> ZZ_binario(ZZ n)
{
	vector<bool> res;
	while (n != ZZ(0))
	{
		res.push_back(mod(n, ZZ(2))== ZZ(1));
		n /= ZZ(2);
	}
	return res;
}
*/
//////////////////////////////////////////////////////////////////////

string ZZ_to_STRING(const ZZ x)
{
	stringstream buffer;
	buffer << x;
	return buffer.str();
}

ZZ STRING_to_ZZ(string x)
{
	stringstream buffer(x);
	ZZ temp;
	buffer >> temp;
	return temp;
}

string addCero(string mensaje, int tam) 
{
	string b = "";
	int n = mensaje.length();
	while (n < tam) {
		b += "0";
		n++;
	}
	b += mensaje;
	return b;
}
int STRING_to_INT(string s) 
{
	stringstream geek(s);
	int x = 0;
	geek >> x;
	return x;
}

string cambio(string mensaje)
{
	cout << mensaje << endl;
	string tmp, tmp_2;
	int l = mensaje.length();
	for (int i = 0; i < l; i += 2)
	{
		tmp_2 = mensaje[i];
		tmp_2 += mensaje[i + 1];
		cout << tmp_2 << endl;;
		tmp += abc[STRING_to_INT(tmp_2)];
	}
	return tmp;
}