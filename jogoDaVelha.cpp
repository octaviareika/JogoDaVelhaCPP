#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;


void menuInicial(){
     int opcao = 0;


    while (opcao < 1 || opcao > 3) {
        cout << "Bem-vindo ao jogo\n";
        cout << "1 - Jogar\n";
        cout << "2 - Sobre\n";
        cout << "3 - Sair\n";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Jogo iniciado\n";
            iniciarJogo();
            
            break;
        
        case 2:

            break;
        

        case 3:

            cout << "Adeus\n";

            break;
        

        default:
            cout << "Opção inválida\n";
            break;
        }
    }
}

void iniciarJogo(){
    // criando um tabuleiro

    int linha;
    int coluna;
    char tabuleiro[3][3];

    tabuleiro[0][0] = '_';
    tabuleiro[0][1] = '_';
    tabuleiro[0][2] = '_';
    tabuleiro[1][0] = '_';
    tabuleiro[1][1] = '_';
    tabuleiro[1][2] = '_';
    tabuleiro[2][0] = '_';
    tabuleiro[2][1] = '_';
    tabuleiro[2][2] = '_';

    for (linha = 0; linha < 3; linha++){
        for (coluna = 0; coluna <3; coluna++){
            cout << tabuleiro[linha][coluna];
        }

        cout << "\n";
    }





}


int main(){

    menuInicial();


    return 0;

}