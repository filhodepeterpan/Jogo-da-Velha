#include <iostream>
#include <string>
#include <cctype>
#include "jdv.h"

using namespace std;

#define ESC "\033["
#define RGB "38;2;"
#define BLUE ESC RGB "0;0;255m"
#define PINK ESC RGB "247;79;191m"
#define GREEN ESC RGB "79;247;136m"
#define YELLOW ESC RGB "255;255;0m"
#define STANDARD ESC "0m"

string insereJogador(int numeroDoJogador) {
    string nome;
    cout << "Digite o nome do " << numeroDoJogador << "º jogador: ";
    getline(cin, nome);
    return nome;
}

void classificaJogador(string a, string b) {
    cout << "\n" << PINK << a << STANDARD << ", você é o " << PINK << "X" << STANDARD << ".";
    cout << "\n" << GREEN << b << STANDARD << ", você é o " << GREEN << "0" << STANDARD << ".\n\n";
}

string mudaTurno(int m, string t, string a, string b) {
    if (m % 2 != 0) {
        t = a;
    }
    else {
        t = b;
    }
    return t;
}

char mudaSimbolo(int m, char s) {
    if (m % 2 != 0) {
        s = 'X';
    }
    else {
        s = 'O';
    }
    return s;
}

void exibeTabuleiro(Casa A[], Casa B[], Casa C[]) {
    cout << "\n";
    cout << "   0   1   2\n";
    cout << "A  " << A[0].cor << A[0].simbolo << STANDARD << " | " << A[1].cor << A[1].simbolo << STANDARD << " | " << A[2].cor << A[2].simbolo << STANDARD << "\n";
    cout << "B  " << B[0].cor << B[0].simbolo << STANDARD << " | " << B[1].cor << B[1].simbolo << STANDARD << " | " << B[2].cor << B[2].simbolo << STANDARD << "\n";
    cout << "C  " << C[0].cor << C[0].simbolo << STANDARD << " | " << C[1].cor << C[1].simbolo << STANDARD << " | " << C[2].cor << C[2].simbolo << STANDARD << "\n";
}

void limpaTabuleiro(Casa A[3], Casa B[3], Casa C[3]) {
    for (int i = 0; i < 3; ++i) {
        A[i].simbolo = ' ';
        A[i].cor = STANDARD;

        B[i].simbolo = ' ';
        B[i].cor = STANDARD;

        C[i].simbolo = ' ';
        C[i].cor = STANDARD;
    }
}

bool identificaVencedor(Casa A[3], Casa B[3], Casa C[3], char simbolo) {
    return (
        (A[0].simbolo == simbolo && A[1].simbolo == simbolo && A[2].simbolo == simbolo) ||
        (B[0].simbolo == simbolo && B[1].simbolo == simbolo && B[2].simbolo == simbolo) ||
        (C[0].simbolo == simbolo && C[1].simbolo == simbolo && C[2].simbolo == simbolo) ||
        (A[0].simbolo == simbolo && B[0].simbolo == simbolo && C[0].simbolo == simbolo) ||
        (A[1].simbolo == simbolo && B[1].simbolo == simbolo && C[1].simbolo == simbolo) ||
        (A[2].simbolo == simbolo && B[2].simbolo == simbolo && C[2].simbolo == simbolo) ||
        (A[0].simbolo == simbolo && B[1].simbolo == simbolo && C[2].simbolo == simbolo) ||
        (A[2].simbolo == simbolo && B[1].simbolo == simbolo && C[0].simbolo == simbolo)
        );
}

void exibeVitorias(string nomeJogador1, string nomeJogador2, int* vitoriasJogador1, int* vitoriasJogador2, int empates) {
    cout << "\nPONTUAÇÃO:\n\n";
    cout << PINK << nomeJogador1 << STANDARD << ": " << *vitoriasJogador1 << "\n";
    cout << GREEN << nomeJogador2 << STANDARD << ": " << *vitoriasJogador2 << "\n";
    cout << YELLOW << "Empates" << STANDARD << ": " << empates << "\n\n";
}
