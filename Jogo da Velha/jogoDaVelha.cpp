#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h> 

using namespace std;


void limpaTela(){
    system("CLS");
}

void menuInicial(){

     //Opcao escolhida pelo usuario
    int opcao = 0;
    string nomeDoJogador;
    //enquanto nao digitar uma opcao valida mostra o menu novamente
    while(opcao < 1 || opcao> 3){
    limpaTela();
    cout << "Bem vindo ao Jogo da Velha";
    cout << "\n1 - Jogar Sozinho";
    cout << "\n2 - Sobre";
    cout << "\n3 - Sair";
    cout << "\nEscolha uma opcao e tecle ENTER";

    //Faz a leitura da opcao
    cin >> opcao;

    //Faz algo de acordo com a opcao escolhida
    switch(opcao){
        case 1:
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