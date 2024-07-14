#pragma once

#ifndef JDV_H
#define JDV_H

#include <string>

using namespace std;

struct Casa {
    char simbolo;
    const char* cor;
};

string insereJogador(int);
void classificaJogador(string, string);
string mudaTurno(int, string, string, string);
char mudaSimbolo(int, char);
void exibeTabuleiro(Casa A[], Casa B[], Casa C[]);
void limpaTabuleiro(Casa A[3], Casa B[3], Casa C[3]);
bool identificaVencedor(Casa A[3], Casa B[3], Casa C[3], char simbolo);
void exibeVitorias(string, string, int*, int*, int);

#endif