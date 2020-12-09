#pragma once
#include "aa.h"

class RSAbloques
{
    ZZ e;
public:
    ZZ d, p, q, N;
    RSAbloques(int);
    RSAbloques(string);
    RSAbloques();
    virtual ~RSAbloques();
    ZZ resto_chino(ZZ);
    string cifrar();
    string descifrar();
    void guardar_claves();
};