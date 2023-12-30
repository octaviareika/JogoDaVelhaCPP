#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#include <limits>


using namespace std;

void iniciarJogo();




void menuInicial(){
     int opcao = 0;


    while (opcao < 1 || opcao > 3) {
        cout << ANSI_COLOR_RED << "Bem-vindo ao jogo da velha!!\n";
        cout << ANSI_COLOR_GREEN << "1 - Jogar\n";
        cout << ANSI_COLOR_GREEN << "2 - Sobre\n";
        cout << ANSI_COLOR_GREEN <<"3 - Sair\n";
        cout << ANSI_COLOR_RESET << "Digite uma opção\n";
        cin >> opcao;

        if(cin.fail()) {
            cin.clear(); // limpa o estado de erro
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignora a entrada inválida
            opcao = 0; // atribui 0 para que o loop continue
        }

        switch (opcao)
        {
        case 1:
            cout << "Jogo iniciado\n";
            iniciarJogo();
            
            break;
        
        case 2:

            cout << "Sobre o jogo\n";
            cout << "Jogo da velha é um jogo de tabuleiro em que dois jogadores jogam\n";
            cout << "um contra o outro, sendo um jogador 'X' e o outro 'O'.\n";
            cout << "O jogador que conseguir colocar três símbolos iguais em uma linha, coluna ou diagonal vence.\n";

            break;
        

        case 3:

            cout << "Adeus \o/. Até a próxima vida!!\n";

            break;
        

        default:
            cout << ANSI_COLOR_RED << "Opção inválida\n";
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
    int situacaoAtual = 1;
    int turnoDoJogador= 1; // turno do jogador vai intercalar
    int rodada = 0; // numero de rodadas

    int colunaJogada; 
    int linhaJogada;


    iniciandoTabuleiro(tabuleiro);
    while(rodada < 9 && situacaoAtual == 1){

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

        //// se algumas dessas opçoes ja tiverem sido ocupadas antes
        if (turnoDoJogador == 1){
            if (tabuleiro[linhaJogada][colunaJogada] == 'X' || tabuleiro[linhaJogada][colunaJogada] == 'O'){ 
                cout << "Jogada inválida\n";
                continue;
            }
            else {
                tabuleiro[linhaJogada][colunaJogada] = 'X';
                turnoDoJogador++; // vai pro jogador 2
            }
        }

        else {
            if (tabuleiro[linhaJogada][colunaJogada] == 'X' || tabuleiro[linhaJogada][colunaJogada] == 'O'){ 
                cout << "Jogada inválida\n";
                continue;
            }
            else {
                tabuleiro[linhaJogada][colunaJogada] = 'O';
                turnoDoJogador--; // vai pro jogador 1
            }
        }

        // verificar se o jogador venceu começando pela linha

        for (linha = 0; linha < 3; linha++){
            if (tabuleiro[linha][0] == 'X' && tabuleiro[linha][1] == tabuleiro[linha][0] && tabuleiro[linha][2] == tabuleiro[linha][1] ){
                cout <<  ANSI_COLOR_GREEN  << "O jogador 1 venceu!!\n ";
                situacaoAtual = 0;
            }
            else if (tabuleiro[linha][0] == 'O' && tabuleiro[linha][1] == tabuleiro[linha][0] && tabuleiro[linha][2] == tabuleiro[linha][1] ){
                cout <<  ANSI_COLOR_GREEN  << "O jogador 2 venceu!!\n";
                situacaoAtual = 0;
            }

        }

        //verificar começando pela coluna
        for (coluna = 0; coluna < 3; coluna++){
            if (tabuleiro[0][coluna] == 'X' && tabuleiro[1][coluna] == tabuleiro[0][coluna] && tabuleiro[2][coluna] == tabuleiro[1][coluna]){
                cout <<  ANSI_COLOR_GREEN  << "O jogador 1 venceu!!\n ";
                situacaoAtual = 0;
            }
            else if (tabuleiro[0][coluna] == 'O' && tabuleiro[1][coluna] == tabuleiro[0][coluna] && tabuleiro[2][coluna] == tabuleiro[1][coluna] ){
                cout <<  ANSI_COLOR_GREEN  << "O jogador 2 venceu!!\n";
                situacaoAtual = 0;
            }
        }
        
        //verificar as diagonais
        if (tabuleiro[0][0] == 'X' && tabuleiro[1][1] == tabuleiro[0][0] && tabuleiro[2][2] == tabuleiro[1][1]){
            cout <<  ANSI_COLOR_GREEN  << "O jogador 1 venceu!!\n ";
            situacaoAtual = 0;
        }
        else if (tabuleiro[0][0] == 'O' && tabuleiro[1][1] == tabuleiro[0][0] && tabuleiro[2][2] == tabuleiro[1][1] ){
            cout <<  ANSI_COLOR_GREEN << "O jogador 2 venceu!!\n";
            situacaoAtual = 0;

        }

        rodada = rodada + 1;// incrementa a rodada
    }

    exibirTabuleiro(tabuleiro);
    cout << "Fim do jogo!\n";
    menuInicial();

}


int main(){

    menuInicial();


    return 0;

}