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

void iniciaTabuleiro(char tabuleiro[10][10], char mascara[10][10]){
    int linha, coluna; // auxuliares da nave6gacao

    //Populando a matriz
    for (linha = 0; linha < 10; linha++){
        for (coluna = 0; coluna < 10; coluna++){
            tabuleiro[linha][coluna] = 'A';
            mascara[linha][coluna] = '*';
        }        
    }
}


void exibeMapa(){
    //Mapa indicador de colunas
    int cont;
    for(cont = 0; cont < 10; cont++){
        if(cont == 0){
            cout << "     ";
        }
        cout << cont << " ";
    }
    cout << "\n";
    for(cont = 0; cont < 10; cont++){
        if(cont == 0){
            cout << "     ";
        }
        cout << "| ";
    }
    cout << "\n";
 
}

void exibeTabuleiro(char tabuleiro[10][10], char mascara[10][10], bool mostraGabarito){

    char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
    char normal[] = { 0x1b, '[', '1', ';', '3', '9', 'm', 0 };

    int linha, coluna; // auxuliares da navegacao

    //Exibe o tabuleiro
    for (linha = 0; linha < 10; linha++){
        cout << linha << " - ";
        for (coluna = 0; coluna < 10; coluna++){
            switch(mascara[linha][coluna]){
                case 'A':
                    cout << blue << " " <<mascara[linha][coluna] << normal;
                    break;
                case 'P':
                    cout << green << " " <<mascara[linha][coluna] << normal;
                    break;
                default:
                    cout << " " <<mascara[linha][coluna];
                    break;
            }
        }        
        cout << "\n";
    }

    if(mostraGabarito == true){
        for(linha = 0; linha < 10; linha++){
             for(coluna = 0; coluna < 10; coluna++){
                 cout << " " <<tabuleiro[linha][coluna];
             }
             cout << "\n";
        }
    }

}



void posicionaBarcos(char tabuleiro[10][10]){

    //Coloca 10 barcos no tabuleiro
    int quantidadeDeBarcos, quantidade = 10, quantidadePosicionada = 0;

    //Verifica se ja posicionou todos os barcos
    while(quantidadeDeBarcos < quantidade){

    int linhaBarco = rand() % 10;  //gera numeros aleatorios 0 a 9
       int colunaBarco = rand() % 10; //gera numeros aleatorios 0 a 9

        if(tabuleiro[linhaBarco][colunaBarco] == 'A'){

        //Posiciona Barcos Aleatoriamente na minha matriz
        tabuleiro[linhaBarco][colunaBarco] = 'P';

        quantidadePosicionada ++;
        }
    }
    
}

void verificaTiro(char tabuleiro[10][10], int linhaJogada, int colunaJogada, int *pontos, string *mensagem){
    //Verifica pontos ao add
        switch (tabuleiro[linhaJogada][colunaJogada]){
        case 'P': *pontos += 10;
            break;
            *mensagem = "Voce acertou um barco pequeno";
        case 'A':
        *mensagem = "Voce acertou a agua";
        break;
        }
}
 
void jogo(string nomeDoJogador){

    char tabuleiro[10][10], mascara[10][10]; //Tabuleiro do jogo
    int linha, coluna; // auxuliares da navegacao
    int linhaJogada, colunaJogada;
    int estadoDeJogo = 1; // 1 = jogo acontecendo 0 igual a fim de jogo
    int pontos = 0;
    string mensagem;
    int tentivas, maxTentativas = 10;
    int opcao;

    //Chama funcao com parametro tabuleiro
    iniciaTabuleiro(tabuleiro, mascara);

    //Posiciona Barcos
    posicionaBarcos(tabuleiro);



    while(tentivas < maxTentativas){

        limpaTela();

        exibeMapa();

        //chama funcao para exiber o tabuleiro
        exibeTabuleiro(tabuleiro, mascara, false);

        cout << "\nPontos: " << pontos << ", Tentativas Restantes: " << maxTentativas - tentivas;
        cout << "\n" << mensagem;

        linhaJogada = -1;
        colunaJogada = -1;

        while((linhaJogada < 0 || colunaJogada < 0) || (linhaJogada > 9 || colunaJogada  > 9)){
            cout << "\n" << nomeDoJogador << ", Digite uma linha:";
            cin >> linhaJogada;
            cout << "\n" << nomeDoJogador << "Digite uma coluna:";
            cin >> colunaJogada;  
        }

        //Verifica oq aconteceu
        verificaTiro(tabuleiro, linhaJogada, colunaJogada, &pontos, &mensagem);
        tentivas ++;
        //Revela o que esta no tabuleiro
        mascara[linhaJogada][colunaJogada] = tabuleiro[linhaJogada][colunaJogada];
    }

    cout << "Fim de Jogo, o que deseja fazer?";
        cout << "\n1-Jogar novamente?";
        cout << "\n2-Ir para o Menu";
        cout << "\n3-Sair";
        cin >> opcao;
        switch (opcao){
        case 1:
            jogo(nomeDoJogador);
            break;
        case 2:
        menuInicial();
            break;
        }

}


void menuInicial(){

     //Opcao escolhida pelo usuario
    int opcao = 0;
    string nomeDoJogador;
    //enquanto nao digitar uma opcao valida mostra o menu novamente
    while(opcao < 1 || opcao> 3){
    limpaTela();
    cout << "Bem vindo ao Jogo de Batalha Naval";
    cout << "\n1 - Jogar Sozinho";
    cout << "\n2 - Sobre";
    cout << "\n3 - Sair";
    cout << "\nEscolha uma opcao e tecle ENTER";

    //Faz a leitura da opcao
    cin >> opcao;

    //Faz algo de acordo com a opcao escolhida
    switch(opcao){
        case 1:
        cout << "Qual e seu nome:";
        cin >> nomeDoJogador;
            jogo(nomeDoJogador);
            break;
        case 2:
            //Mostra informacoes do Jogo
            limpaTela();
            cout << "Jogo Desenvolvido por Mateus em 2022 Curso de Completo de linguagem C e C++ - Iniciante ao Avancado";
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