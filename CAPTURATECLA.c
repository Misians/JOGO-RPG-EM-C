#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;


//Declaração das funcoes a serem utilizadas <>
void Clicar(int x, int y);
void ClicarDireito(int x, int y);
void ClicarMeio(int x, int y);
void Digitar(char letra);
//Fim da declaração de funções </>

int main(int argc, char * argv[]){

//Declaracao das Variáveis a Serem Usadas <>
int n = 1;
int x;
int y;
int times;
int done = 0;
int sleepy;
int botao;
string choice;

unsigned long tempoEspera = 0;
unsigned long tempoEsperaClique = 0;
bool bPause = false;

//Fim da Declaração de Variáveis </>


start:

//Inicio da coleta de dados <>
cout << "BOT_AutoClick Version 2.1" << endl;
cout << "   " << endl;

cout << "Quantas Vezes Deseja Clicar?" << endl;
cout << " : ";
cin >> times;

cout << "Quanto tempo deve ter entre os click? (Em Milisegundos)" << endl;
cout << "(MS): ";
cin >> sleepy;

cout << "Qual o botao a ser clicado : 1 - left / 2 - middle / 3 - right" <<     endl;
cout << " : ";
do{
cin >> botao;
}while( botao < 1 || botao > 3);

done = 0;
//Fim da Coleta de dados </>

//Contagem Regressiva para posicionar o mouse <>
cout << "starting in 5..." << endl;
Sleep(1000);
cout << "starting in 4..." << endl;
Sleep(1000);
cout << "starting in 3..." << endl;
Sleep(1000);
cout << "starting in 2..." << endl;
Sleep(1000);
cout << "starting in 1..." << endl;
Sleep(1000);
//Fim da Contagem Regressiva para posicionar o mouse </>



//Estrutura de Decisao para clicker C++ <>
if (botao == 1){

    while (done <= times)
    {
        if(GetAsyncKeyState('v') & 0x8000)
        {
            if( tempoEspera < GetTickCount() )
            {
                tempoEspera = GetTickCount() + 350; //esperar 350 milisegundos
                bPause = !bPause; //troca de true pra false ou false pra true
            }
        }
        if(bPause == false && tempoEsperaClique < GetTickCount())
        {
            tempoEsperaClique = GetTickCount() + sleepy;
            Clicar(x, y); //Para Ver Função do click descer codigo
            done++;
        }
    }
}

if (botao == 2){

    while (done <= times)
    {
        if(GetAsyncKeyState('v') & 0x8000)
        {
            if( tempoEspera < GetTickCount() )
            {
                tempoEspera = GetTickCount() + 350; //esperar 350 milisegundos
                bPause = !bPause; //troca de true pra false ou false pra true
            }
        }
        if(bPause == false && tempoEsperaClique < GetTickCount())
        {
            tempoEsperaClique = GetTickCount() + sleepy;
            ClicarMeio(x, y); //Para Ver Função do click descer codigo
            done++;
        }
    }
}

    if (botao == 3){


        while (done <= times){

        if(GetAsyncKeyState('v') & 0x8000)
        {
            if( tempoEspera < GetTickCount() )
            {
                tempoEspera = GetTickCount() + 350; //esperar 350 milisegundos
                bPause = !bPause; //troca de true pra false ou false pra true
            }
        }
             if(bPause == false && tempoEsperaClique < GetTickCount())
            {
            tempoEsperaClique = GetTickCount() + sleepy;
            ClicarDireito(x, y); //Para Ver Função do click descer codigo
            done++;
            }
        }
    }
    //Fim da Estrutura de Decisão do Clicker </>

    cout << "Processo Concluido com Sucesso!." << endl;
    cout << "BOT Autoclick - Criado por Mazurco066." << endl;
    cout << "    " << endl;
    Sleep(1000);
    cout << "Denovo?   sim(y) or nao(n)" << endl;
    cin >> choice;

    if (choice == "y")
    {

        system("cls");
        goto start;
    }

    cin.get();

}

void Clicar(int x, int y){

    mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
}

void ClicarDireito(int x, int y){

    mouse_event(MOUSEEVENTF_RIGHTDOWN, x, y, 0, 0);
    mouse_event(MOUSEEVENTF_RIGHTUP, x, y, 0, 0);
}

void ClicarMeio(int x, int y){

    mouse_event(MOUSEEVENTF_MIDDLEDOWN, x, y, 0, 0);
    mouse_event(MOUSEEVENTF_MIDDLEUP, x, y, 0, 0);
}

void Digitar(char letra){

    keybd_event(VkKeyScan(letra),0x9e,0,0);
}
