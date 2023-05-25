#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h> //Para gerar palavras aleatorias

using namespace std;

void limpaTela(){
    system("CLS");
}

string retornaPalavrasAleatorias(){
        //Vetor com palavras disponiveis
    string palavra[3] = ("abacaxi", "manga" , "morango");

    //Indices gerado intervalo {0,1,2}
    int indiceAleatorio = rand() % 3;

    return palavra[indiceAleatorio];
    
}

string retornaPalavraComMascara(string palavra, int tamanhodaPalavra){

    //Criando mascara da Palavra
    int cont = 0;
    string palavracomMascara;

    //Coloca uma mascara
    while(cont < tamanhodaPalavra){
        palavracomMascara += "_";
        cont ++;
    }
    return palavracomMascara;
}

void exibeStatus(string palavraComMascara, int tamanhodaPalavra, int tentativasRestantes, string letrasJaArriscadas){

    
    cout << "\nPalavra:" << palavraComMascara << "(Tamanho:" << tamanhodaPalavra << ")";
    cout << "\nTentativas Restantes:" << tentativasRestantes;

    //Exibe as letras ja arriscadas
    int i;
    cout << "Letras arriscadas:";
    for (i = 0; i < letrasJaArriscadas.size(); i++){
        cout << letrasJaArriscadas[i] << ", ";
    }
    


}


void jogaSozinho(){
    ///Variaveis Principais
    int tentativas = 0, maximodeTentativas = 5; // numeros de tentativas e erros
    int i = 0; //auxiliar para lacos de repeticao
    char letra; //letra arriscada pelo usuario
    string letrasJaArriscadas; //Acumulas as tentativas do jogador 
    bool jaDigitouLetra; //auxiliar para saber se a letra foi digitada

    //Palavra a ser adivinhada
    string palavra = retornaPalavrasAleatorias();
    
    //Tamanho da palavra
    int tamanhodaPalavra =  palavra.size();

    //Palavra Mascarada
    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhodaPalavra);


      while (palavra != palavraComMascara && maximodeTentativas - tentativas > 0){

        

        //Exibe Status atual do jogo
        exibeStatus(palavraComMascara, tamanhodaPalavra, maximodeTentativas - tentativas, letrasJaArriscadas);

        //le uma palpite
        cout << "\nDigite uma letra: ";
        cin >> letra;

        //Percorre as letras ja arriscadas
        for (i = 0; i < tentativas; i++){

            //Se encontrar a letra    
            if(letrasJaArriscadas[i] == letra){
                
                cout << "Essa letra ja foi digitada!";

                //Indica com  a palavra booleana
                jaDigitouLetra = true;
            }
        }
        
        //Se for uma letra nova
        if(jaDigitouLetra == false){

                letrasJaArriscadas += letra;
                

                //Percorre a palavra real e se a letra existir muda a palavraComMascara
                for (i = 0; i < tamanhodaPalavra; i++){

                    //Se a letra existir na palavra escondida
                    if(palavra[i] == letra){
                        //faco a letra aparecer
                        palavraComMascara[i] = palavra[i];
                    }
                }
                //aumenta uma tentativa realizada
                tentativas ++;
            }

            if(palavra == palavraComMascara){
                limpaTela();
                cout << "Parabens, Voce venceu";
            }else{
                cout << "Voce perdeu";
            }
    }
}

void menuInicial(){

     //Opcao escolhida pelo usuario
    int opcao = 0;
    //enquanto nao digitar uma opcao valida mostra o menu novamente
    while(opcao < 1 || opcao> 3){
    limpaTela();
    cout << "Bem vindo ao Jogo";
    cout << "\n1 - Jogar";
    cout << "\n2 - Sobre";
    cout << "\n3 - Sair";
    cout << "\nEscolha uma opcao e tecle ENTER";

    //Faz a leitura da opcao
    cin >> opcao;

    //Faz algo de acordo com a opcao escolhida
    switch(opcao){
        case 1:
            //Inicia o jogo
            jogaSozinho();
            break;
        case 2:
            //Mostra informacoes do Jogo
            cout << "Informacoes do jogo";
            break;
        case 3:
            cout << "Ate mais";
            break;
        }
    }
}



int main(){

    //Para gerar numeros realmente aleatorios
    srand ( (unsigned)time(NULL));

    menuInicial();
    
    return 0;
}