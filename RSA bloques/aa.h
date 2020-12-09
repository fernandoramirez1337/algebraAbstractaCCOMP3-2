#pragma once
#include <NTL/ZZ.h>
#include <bitset> 
#include <string>
#include <vector>
#include <NTL/vector.h>
#include <cmath>
#include <stdlib.h>
#include <sstream>
#include <fstream>

using namespace std;
using namespace NTL;

using namespace std;
using namespace NTL;

const string abc = "abcdefghijklmnopqrstuvwxyz().0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ,+-";
const int abc_tam = abc.size();

ZZ mod(ZZ, ZZ);

ZZ euclidesExtendido(ZZ, ZZ, ZZ&, ZZ&);

ZZ euclides(ZZ, ZZ);

void ee(ZZ, ZZ);

ZZ expmod(ZZ, ZZ, ZZ);

ZZ inversa(ZZ, ZZ);

//INFORME
/*
ZZ alg_1(ZZ, ZZ, ZZ);

ZZ alg_2(ZZ, ZZ, ZZ);

ZZ alg_2_bit(ZZ, ZZ, ZZ);

void restochino(vector<ZZ>, vector<ZZ>);

ZZ fastExp(ZZ, ZZ, ZZ);

ZZ modExp(ZZ, ZZ, ZZ);

ZZ funExp(ZZ, ZZ, ZZ);

bool cooprimos(vector<ZZ>);

vector<bool> ZZ_binario(ZZ);
*/
////////////////////////////////////////////////////////

string ZZ_to_STRING(const ZZ);

ZZ STRING_to_ZZ(string);

string addCero(string, int);

string cambio(string);


