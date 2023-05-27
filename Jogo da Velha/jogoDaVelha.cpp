#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h> 

using namespace std;

void menuInicial();

void limpaTela(){
    system("CLS");
}

void iniciaTabuleiro(char tabuleiro[3][3]){
    int linha, coluna;

     for (linha = 0; linha < 3; linha++){
        for (coluna = 0; coluna < 3; coluna++){
            tabuleiro[linha][coluna] = '-';
            }
        }    

}

void exibeTabuleiro(char tabuleiro[3][3]){

    int linha, coluna;
    cout << "\n" ;
    for (linha = 0; linha < 3; linha++){
        for (coluna = 0; coluna < 3; coluna++){
            cout << tabuleiro[linha][coluna];
            }
            cout << "\n";
        }        
}

int confereTabuleiro(char tabuleiro[3][3]){

    int linha, coluna;



    //Confere linhas
        for (linha = 0; linha < 3; linha++){
            if(tabuleiro[linha][0] == 'X' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){
                return 1;
            } else if (tabuleiro[linha][0] == 'O' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]) {
                return 2;

            }
        }

        //Cofere Colunas
        for (coluna = 0; coluna < 3; coluna++){
            if(tabuleiro[0][coluna] == 'X' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
                return 1;
            } else if (tabuleiro[0][coluna] == 'O' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]) {
               return 2;
            }
        }

        //Diagonal Primaria
        if(tabuleiro[0][0] != '-' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){
            if(tabuleiro[0][0] == 'X'){
                return 1;
            } else{
                return 2;
            }
        }

        //Diagonal Secundaria
        if(tabuleiro[0][2] != '-' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){
            if(tabuleiro[0][2] == 'X'){
                return 1;
            } else{
                return 2;
            }
        }
    return 0;
}

void exibeInstrucoes(){
    cout << "\nMapa de posicoes:";
    cout << "\n 7 | 8 | 9";
    cout << "\n 4 | 5 | 6";
    cout << "\n 1 | 2 | 3";

}

void  jogo(string nomeUm,string nomeDois, int pontuacaoUm, int pontuacaoDois){

    string nomeAtual;
    char tabuleiro [3][3]; // tabuleiro do jogo
    int linha, coluna;
    int linhaJogada, colunaJogada, posicaoJogada;
    int estadoDeJogo = 1;
    int turnoDoJogador = 1; // 1=x 2=O
    int rodada = 0;
    int opcao;
    bool posiciona;

    //Coloca os - no tabuleiros para indicar o vazio
    iniciaTabuleiro(tabuleiro);

    //serve para mudar a posicao do vetor nas linhas e colunas digitadas pelo o usuario
    while(rodada < 9 && estadoDeJogo == 1){

        limpaTela();

        cout << "\nRodada: " << rodada << "\n";
        cout << "Pontuacao: " << nomeUm << " " << pontuacaoUm << "x" << pontuacaoDois << " " << nomeDois;

        exibeTabuleiro(tabuleiro);
        exibeInstrucoes();

        //Ataliza o nome do jogador
        if(turnoDoJogador == 1){

            nomeAtual = nomeUm;
            //Posicao desejada 
        } else {
            nomeAtual = nomeDois;
        }

        posiciona = false;

        //Matriz de posicoes
        int posicoes[9][2] = {{2,0},{2,1},{2,2},{1,0},{1,1},{1,2},{0,0},{0,1},{0,2}};

        while(posiciona == false){

        cout << "\n" << nomeAtual << " Digite uma posicao conforme o mapa acima: ";
        cin >> posicaoJogada;

        linhaJogada = posicoes[posicaoJogada-1][0];
        colunaJogada = posicoes[posicaoJogada-1] [0];

        if(tabuleiro[linhaJogada][colunaJogada] == '-'){

            posiciona = true;

            if(turnoDoJogador == 1){
            tabuleiro[linhaJogada][colunaJogada] = 'X';
            turnoDoJogador = 2;
            } else {
            tabuleiro[linhaJogada][colunaJogada] = 'O';
            turnoDoJogador = 1;
            }
         }

        

        }

        if(confereTabuleiro(tabuleiro) == 1){
            cout << "O jogador X venceu!";
            pontuacaoUm ++;
            estadoDeJogo = 0;
        } else if (confereTabuleiro(tabuleiro) == 2){
            cout << "O jogador O venceu!";
            pontuacaoDois ++;
            estadoDeJogo = 0;
        }

        rodada ++;       
    }
    exibeTabuleiro(tabuleiro);
    cout << "Fim de Jogo, o que deseja fazer?";
        cout << "\n1-Continuar Jogando?";
        cout << "\n2-Ir para o Menu";
        cout << "\n3-Sair";
        cin >> opcao;
        switch (opcao){
        case 1:
            jogo(nomeUm, nomeDois, pontuacaoUm, pontuacaoDois);
            break;
        case 2:
            menuInicial;
            break;
        case 3:
            break;
        }
 
}

void menuInicial(){

     //Opcao escolhida pelo usuario
    int opcao = 0;
    string nomeUm;
    string nomeDois;
    //enquanto nao digitar uma opcao valida mostra o menu novamente
    while(opcao < 1 || opcao> 3){
    limpaTela();
    cout << "Bem vindo ao Jogo da Velha";
    cout << "\n1 - Jogar";
    cout << "\n2 - Sobre";
    cout << "\n3 - Sair";
    cout << "\nEscolha uma opcao e tecle ENTER";

    //Faz a leitura da opcao
    cin >> opcao;

    //Faz algo de acordo com a opcao escolhida
    switch(opcao){
        case 1:
        cout << "Digite o nome do jogador 1:";
        cin >> nomeUm;
        cout << "Digite o nome do jogador 2:";
        cin >> nomeDois;
        jogo(nomeUm, nomeDois, 0, 0);
            break;
        case 2:
            //Mostra informacoes do Jogo
            limpaTela();
            cout << "Jogo Desenvolvido por Mateus em 2023 Curso de Completo de linguagem C e C++ - Iniciante ao Avancado";
            cout << "\n1 - Voltar";
            cout << "\n2 - Sair";
            cin >> opcao;
            if(opcao == 1){
                menuInicial();
            }
            break;
        case 3:
            cout << "Ate mais";
            break;
        }
    }
}

int main(){

    srand ((unsigned)time(NULL));
    menuInicial();
    
    return 0;
}