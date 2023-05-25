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

void exibeStatus(string palavraComMascara, int tamanhodaPalavra, int tentativasRestantes, string letrasJaArriscadas, string mensagem){

    
    cout << mensagem;
    cout << "\nPalavra:" << palavraComMascara << "(Tamanho:" << tamanhodaPalavra << ")";
    cout << "\nTentativas Restantes:" << tentativasRestantes;

    //Exibe as letras ja arriscadas
    int i;
    cout << "\nLetras arriscadas:";
    for (i = 0; i < letrasJaArriscadas.size(); i++){
        cout << letrasJaArriscadas[i] << ", ";
    }
    

}


int Jogar(int numeroDeJogadores){

    //Palavra a ser adivinhada
    string palavra;

    ///Variaveis Principais
    int tentativas = 0, maximodeTentativas = 10; // numeros de tentativas e erros
    int i = 0; //auxiliar para lacos de repeticao
    int opcao; //opcao finais
    char letra; //letra arriscada pelo usuario
    string letrasJaArriscadas; //Acumulas as tentativas do jogador 
    string mensagem = "Bem vindo ao Jogo!"; // mensagens do jogo
    string palavraArriscada; //Tentativa de arriscar a palavra Completa
    bool jaDigitouLetra, acertouletra; //auxiliar para saber se a letra foi digitada

    //confere o numero de jogadores
    if(numeroDeJogadores == 1){

        //Palavra a ser adivinhada
        palavra = retornaPalavrasAleatorias();
    }else{

        cout << "\nDigite uma palavra: ";
        cin >> palavra;
    }

    
    //Tamanho da palavra
    int tamanhodaPalavra =  palavra.size();

    //Palavra Mascarada
    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhodaPalavra);


      while (palavra != palavraComMascara && maximodeTentativas - tentativas > 0){

        limpaTela();

        //Exibe Status atual do jogo
        exibeStatus(palavraComMascara, tamanhodaPalavra, maximodeTentativas - tentativas, letrasJaArriscadas, mensagem);

        //le uma palpite
        cout << "\nDigite uma letra (Ou digite 1 para arruscar a palavra): ";
        cin >> letra;

        //Se digitar 1 deixa o usuario arriscar a palavra inteira
        if(letra== '1'){
            cin >> palavraArriscada;
            if(palavraArriscada == palavra){
                palavraComMascara = palavraArriscada;
            } else {
                tentativas = maximodeTentativas;
            }
        }

        //Percorre as letras ja arriscadas
        for (i = 0; i < tentativas; i++){

            //Se encontrar a letra    
            if(letrasJaArriscadas[i] == letra){
                
                mensagem = "Essa letra ja foi digitada!";

                //Indica com  a palavra booleana
                jaDigitouLetra = true;
            }
        }
        
        //Se for uma letra nova
        if(jaDigitouLetra == false){

                //Incrementa as Letras Ja Arriscadas
                letrasJaArriscadas += tolower(letra);
                

                //Percorre a palavra real e se a letra existir muda a palavraComMascara
                for (i = 0; i < tamanhodaPalavra; i++){

                    //Se a letra existir na palavra escondida
                    if(palavra[i] == tolower(letra)){ // serve para transformar em letra minuscula
                        //faco a letra aparecer
                        palavraComMascara[i] = palavra[i];

                        acertouletra = true;
                    }
                }

             if(acertouletra == false){

                    mensagem = "Voce errou uma letra";
                } else {
                    mensagem = "Voce acertou uma letra";
                    acertouletra = false;
                }

                //aumenta uma tentativa realizada
                tentativas ++;
            }

            //reinicia auxiliares
            jaDigitouLetra = false;
            acertouletra = false;
        }

    if(palavra == palavraComMascara){
 
        limpaTela();
        cout << "Parabens, voce venceu!";
        cout << "\nDeseja reiniciar?";
        cout << "\n1-Sim";
        cout << "\n2-Nao";
        cin >> opcao;
        return opcao;
 
    }else{
 
        limpaTela();
        cout << "Voce perdeu!";
        cout << "\nDeseja reiniciar?";
        cout << "\n1-Sim";
        cout << "\n2-Nao";
        cin >> opcao;
        return opcao;
    }
}

void menuInicial(){

     //Opcao escolhida pelo usuario
    int opcao = 0;
    //enquanto nao digitar uma opcao valida mostra o menu novamente
    while(opcao < 1 || opcao> 3){
    limpaTela();
    cout << "Bem vindo ao Jogo";
    cout << "\n1 - Jogar Sozinho";
    cout << "\n2 - Jogar em Dupla";
    cout << "\n3 - Sobre";
    cout << "\n4 - Sair";
    cout << "\nEscolha uma opcao e tecle ENTER";

    //Faz a leitura da opcao
    cin >> opcao;

    //Faz algo de acordo com a opcao escolhida
    switch(opcao){
        case 1:
            //Inicia o jogo
            if(Jogar(1) == 1){
                menuInicial();
            }
            break;
        case 2:
            //Inicia o jogo em dupla
            if(Jogar(2) == 1){
                menuInicial();
            }
            break;
        case 3:
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
        case 4:
            cout << "Ate mais";
            break;
        }
    }
}



int main(){

    //Para gerar numeros realmente aleatorios
    srand ((unsigned)time(NULL));

    menuInicial();
    
    return 0;
}