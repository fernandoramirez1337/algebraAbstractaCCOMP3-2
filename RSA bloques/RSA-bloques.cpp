#include "RSA-bloques.h"

RSAbloques::~RSAbloques()
{

}

RSAbloques::RSAbloques(string txt)
{
    vector <string> a;
    string b;

    ifstream file_;
    file_.open(txt);

    while (getline(file_, b))
    {
        a.push_back(b);
    }
    p = STRING_to_ZZ(a[0]);
    q = STRING_to_ZZ(a[1]);
    N = STRING_to_ZZ(a[2]);
    e = STRING_to_ZZ(a[3]);
    d = STRING_to_ZZ(a[4]);
}

RSAbloques::RSAbloques(int bits)
{
    p = GenPrime_ZZ(bits);
    q = GenPrime_ZZ(bits);

    while (p == q) q = GenPrime_ZZ(bits);

    N = p * q;

    ZZ phiN = (p - 1) * (q - 1);

    e = RandomBnd(phiN);

    while (euclides(e, phiN) != ZZ(1)) e = RandomBnd(phiN);

    d = mod(inversa(e, phiN), N);
}

RSAbloques::RSAbloques() 
{
    vector <string> a;
    string b;

    ifstream file_;
    file_.open("clavespublicas.txt");

    while (getline(file_, b))
    {
        a.push_back(b);
    }
    e = STRING_to_ZZ(a[0]);
    N = STRING_to_ZZ(a[1]);
}

ZZ RSAbloques::resto_chino(ZZ C) 
{
    ZZ Dp = expmod(C, mod(d, p - 1), p);
    ZZ Dq = expmod(C, mod(d, q - 1), q);
    
    ZZ q1 = inversa(q, p);
    ZZ q2 = inversa(p, q);

    return mod(mod(Dp * q * q1, N) + mod(Dq * p * q2, N), N);
}

string RSAbloques::cifrar()
{
    ifstream file("plaintxt.txt");
    string str, mensaje;
    while (getline(file, str))
    {
        mensaje += str;
        mensaje.push_back(' ');
    }

    string bits;

    bits = ZZ_to_STRING(N);
    int bit = bits.length();

    string cifrado;

    int mensaje_length = mensaje.length();

    for (int i = 0; i < mensaje_length; i++)
    {
        int pos = abc.find(mensaje[i]);
        string c;
        stringstream x;
        x << pos;
        x >> c;
        c = addCero(c, 2);
        cifrado += c;
    }
    while (mod(ZZ(cifrado.length()), ZZ(bit - 1)) != ZZ(0)) cifrado += "39";

    string temp;
    string cifTemp;

    int l = cifrado.length() / (bit - 1);

    for (int i = 0; i < l; i++) 
    {
        for (int j = 0; j < (bit - 1); j++) 
        {
            int pos = j + (i * (bit - 1));
            temp += cifrado[pos];
        }

        ZZ g = STRING_to_ZZ(temp);

        temp = "";

        ZZ h = expmod(g, e, N);

        temp = ZZ_to_STRING(h);

        temp = addCero(temp, bit);

        cifTemp += temp;

        temp = "";

    }

    cifrado = cifTemp;

    ofstream file_;
    file_.open("cifrado.txt");
    file_ << cifrado;
    file_.close();

    return cifrado;
}

string RSAbloques::descifrar() 
{
    string bits, decifrado, temp, cifTemp;

    bits = ZZ_to_STRING(N);
    int bit = bits.length();

    string b;
    ifstream file_;
    file_.open("cifrado.txt");
    getline(file_, b);

    int l = b.length() / (bit);

    for (int i = 0; i < l; i++) 
    {
        for (int j = 0; j < bit; j++) 
        {
            int pos = j + (i * bit);
            temp += b[pos];
        }

        ZZ g = STRING_to_ZZ(temp);

        temp = "";

        ZZ h = resto_chino(g);

        temp = ZZ_to_STRING(h);

        temp = addCero(temp, bit - 1);

        cifTemp += temp;

        temp = "";
    }
    cifTemp = cambio(cifTemp);
    ofstream file__;
    file__.open("descifrado.txt");
    file__ << cifTemp;
    file__.close();

    return cifTemp;

}

void RSAbloques::guardar_claves()
{
    ofstream file_;
    file_.open("aqui_no_estan_mis_claves.txt");
    file_ << p << endl << q << endl << N << endl << e << endl << d;
    file_.close();
}