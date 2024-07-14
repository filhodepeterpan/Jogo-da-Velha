#include <iostream>
#include <windows.h>
#include <string>
#include <cctype>
#include <locale>
#include "jdv.h"

using namespace std;

#define ESC "\033["
#define RGB "38;2;"
#define BLUE ESC RGB "0;0;255m"
#define PINK ESC RGB "247;79;191m"
#define GREEN ESC RGB "79;247;136m"
#define YELLOW ESC RGB "255;255;0m"
#define STANDARD ESC "0m"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    string jogador1, jogador2;
    string vezDoJogador;
    string vencedor;
    char simbolo=' ';
    char resposta=' ';
    Casa A[3];
    Casa B[3];
    Casa C[3];
    string linha;
    int coluna;
    int marcacoes = 1;
    int opcao;
    int vitoriasJogador1 = 0;
    int vitoriasJogador2 = 0;
    int empates = 0;
    bool novoJogo = true;

    cout << "Vamos jogar o " << BLUE << "Jogo da Velha" << STANDARD << "! Você precisa de 2 pessoas para jogar.\n\n";
  
    jogador1 = insereJogador(1);
    jogador2 = insereJogador(2);
    classificaJogador(jogador1, jogador2);

    while (novoJogo == true) {
        limpaTabuleiro(A, B, C);
        vencedor = "";

        while (marcacoes <= 9) {
            exibeTabuleiro(A, B, C);

            vezDoJogador = mudaTurno(marcacoes, vezDoJogador, jogador1, jogador2);
            simbolo = mudaSimbolo(marcacoes, simbolo);

            string corJogador = (vezDoJogador == jogador1) ? PINK : GREEN;
            string corSimbolo = (vezDoJogador == jogador1) ? PINK : GREEN;

            cout << "\n" << corJogador << vezDoJogador << STANDARD ", é a sua vez de jogar. Escolha o espaço que deseja preencher com " << corJogador << simbolo << STANDARD << ", começando pela linha: ";
            cin >> linha;

            while (linha != "A" && linha != "B" && linha != "C" && linha != "a" && linha != "b" && linha != "c") {
                cout << "Linha inválida. Escolha apenas A, B ou C: ";
                cin >> linha;
            }

            cout << "\nAgora escolha a coluna: ";
            cin >> coluna;

            while (coluna > 2 || coluna < 0 || !cin) {
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "Digite apenas um número: ";
                }
                else {
                    cout << "Coluna inválida. Escolha apenas 0, 1 ou 2: ";
                }
                cin >> coluna;
                cout << "\n";
            }

            if ((linha == "A" || linha == "a") && A[coluna].simbolo == ' ') {
                A[coluna].simbolo = simbolo;
                A[coluna].cor = (simbolo == 'X') ? PINK : GREEN;
            }
            else if ((linha == "B" || linha == "b") && B[coluna].simbolo == ' ') {
                B[coluna].simbolo = simbolo;
                B[coluna].cor = (simbolo == 'X') ? PINK : GREEN;
            }
            else if ((linha == "C" || linha == "c") && C[coluna].simbolo == ' ') {
                C[coluna].simbolo = simbolo;
                C[coluna].cor = (simbolo == 'X') ? PINK : GREEN;
            }
            else {
                cout << "\nEsse espaço já está preenchido. Tente novamente:\n";
                continue;
            }

            if (identificaVencedor(A, B, C, simbolo) == true) {
                vencedor = vezDoJogador;

                if (vencedor == jogador1) {
                    vitoriasJogador1++;
                }
                else if (vencedor == jogador2) {
                    vitoriasJogador2++;
                }
                break;
            }
            marcacoes++;
        }

        exibeTabuleiro(A, B, C);

        if (vencedor == vezDoJogador) {
            cout << "\nParabéns " << ((vencedor == jogador1) ? PINK : GREEN) << vencedor << STANDARD << ", você venceu o jogo!\n";
        }
        else {
            cout << "\nDeu velha! Vocês " << YELLOW << "empataram" << STANDARD << ".\n";
            empates++;
        }

        cout << "\nDeseja jogar novamente?\n\nSim - Digite S\nNão - Digite qualquer outra tecla\n\n";
        cin >> resposta;
        cout << "\n";

        if (resposta == 'S' || resposta == 's') {
            cout << "Digite a opção que deseja para iniciar um novo jogo:\n\n1 - Jogar com os mesmos jogadores\n2 - Inserir novos jogadores\n\n";
            cin >> opcao;

            while (opcao != 1 && opcao != 2 && isalpha(opcao)) {
                "\n\nOpção Inválida. Digite apenas 1 ou 2: ";
                cin >> opcao;
            }

            if (opcao == 1) {
                exibeVitorias(jogador1, jogador2, &vitoriasJogador1, &vitoriasJogador2, empates);
                novoJogo = true;
                marcacoes = 1;
                limpaTabuleiro(A, B, C);
            }
            else if (opcao == 2) {
                exibeVitorias(jogador1, jogador2, &vitoriasJogador1, &vitoriasJogador2, empates);
                novoJogo = true;
                marcacoes = 1;
                vitoriasJogador1 = 0;
                vitoriasJogador2 = 0;
                empates = 0;
                limpaTabuleiro(A, B, C);
                cin.ignore();
                cout << "\n";
                jogador1 = insereJogador(1);
                jogador2 = insereJogador(2);
                classificaJogador(jogador1, jogador2);
            }
        }
        else {
            exibeVitorias(jogador1, jogador2, &vitoriasJogador1, &vitoriasJogador2, empates);
            novoJogo = false;
        }
    }
    cout << "\nObrigado por jogar :)\n\nDesenvolvido por Douglas Soares\nGithub: @filhodepeterpan\n\n";
    cin.ignore(10000, '\n');
    cin.get();

    return 0;
}
