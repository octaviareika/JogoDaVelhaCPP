#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;


void limpaTela(){
    system("CLS");
}


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

/*Função para iniciar tabuleiro*/
void iniciandoTabuleiro(char tabuleiro[3][3]){

    int linha, coluna;

    for (linha = 0; linha < 3; linha++){
        for (coluna = 0; coluna < 3; coluna++){
            tabuleiro[linha][coluna] = '_';
        }
    }
}

void exibirTabuleiro(char tabuleiro[3][3]){
    int linha, coluna;

    for (linha = 0; linha < 3; linha++){
        for (coluna = 0; coluna <3; coluna++){
            cout << tabuleiro[linha][coluna];
        }

        cout << "\n";
    }
}

void iniciarJogo(){
    // criando um tabuleiro

    int linha;
    int coluna;
    char tabuleiro[3][3];
    int estadoDeJogo = 1;
    int turnoDoJogador=1; // turno do jogador vai intercalar

    int colunaJogada; 
    int linhaJogada;
    string nome;

    while(estadoDeJogo == 1){

        limpaTela();
        iniciandoTabuleiro(tabuleiro);
        exibirTabuleiro(tabuleiro);

        cout << "Insira seu nome\n";
        cin >> nome;
        cout << nome << "," << "digite uma linha\n";
        cin >> linhaJogada;
        cout << "Digite uma coluna\n";
        cin >> colunaJogada; 

        if (turnoDoJogador == 1){
            tabuleiro[linhaJogada][colunaJogada] = 'X';
            turnoDoJogador++; // vai pro jogador 2
        }

        else {
            tabuleiro[linhaJogada][colunaJogada] = 'O';
            turnoDoJogador--; // vai pro jogador 1
        }
    }





}


int main(){

    menuInicial();


    return 0;

}