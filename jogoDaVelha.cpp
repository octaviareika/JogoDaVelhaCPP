#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

void iniciarJogo();

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
            tabuleiro[linha][coluna] = '-';
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
    int rodada = 0; // numero de rodadas

    int colunaJogada; 
    int linhaJogada;

    limpaTela();
    iniciandoTabuleiro(tabuleiro);
    while(rodada < 9 && estadoDeJogo == 1){

        exibirTabuleiro(tabuleiro);


        //cout << "Insira seu nome\n";
        //cin >> nome;
        cout << "TURNO DO JOGADOR " << turnoDoJogador << "\n";
        cout << "\n" << "RODADA: " << rodada << "\n"; 
        cout << "Digite uma linha\n";
        cin >> linhaJogada;
        linhaJogada = linhaJogada - 1;
        cout << "Digite uma coluna\n";
        cin >> colunaJogada; 
        colunaJogada = colunaJogada - 1;

        if (turnoDoJogador == 1){
            tabuleiro[linhaJogada][colunaJogada] = 'X';
            turnoDoJogador = 2; // vai pro jogador 2
        }

        else {
            tabuleiro[linhaJogada][colunaJogada] = 'O';
            turnoDoJogador = 1; // vai pro jogador 1
        }

        // verificar se o jogador venceu 

        for (int linha = 0; linha < 3; linha++){
            if (tabuleiro[linha][0] == 'X' && tabuleiro[linha][1] == tabuleiro[linha][0] && tabuleiro[linha][2] == tabuleiro[linha][0] ){
                cout << "O jogador 1 venceu!!\n ";
            }
            else if (tabuleiro[linha][0] == 'O' && tabuleiro[linha][1] == tabuleiro[linha][0] && tabuleiro[linha][2] == tabuleiro[linha][0] ){
                cout << "O jogador 2 venceu!!\n";
            }

        }
        

        rodada = rodada + 1;
    }

    cout << "Fim do jogo!";

}


int main(){

    menuInicial();


    return 0;

}