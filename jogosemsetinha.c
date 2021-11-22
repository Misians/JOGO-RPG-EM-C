#include <stdio.h> //funções da linguagem c
#include <stdlib.h> // standard library
#include <conio.h> //usar o getch
#include <string.h> //usar strings
#include <windows.h> //No MS-Windows
#include <unistd.h> //No UNIX
#include <locale.h> //compilar sem erros ortográficos

int cap;
int opcao;
void funcaocap(){ //função pro kbhit cap pra usar getch
if(kbhit){
	cap=getch();
	}
}
struct atributos_inimigo_um{ //atributos do inimigo

    int hp;
};
struct atributos_inimigo_um inimigo;

struct atributos_do_personagem{ //atributos do player

    char nome[30];
    char raca[20];
	int hp;
	int str;
	int def;
	int esp;

};
struct atributos_do_personagem atributos;

void tutorial(){

    printf("O QUE É UM RPG? \n\n");
    printf("A sigla RPG nada mais é que “Role Playing Game”, \n ou seja, um jogo onde as pessoas interpretam seus personagens e \n criam narrativas que giram em torno de um enredo.");
    printf("O QUE EU PRECISO SABER PRA JOGAR UM RPG?\n \n");
    printf("Deve ver quais suas armas e ataques mais fortes, pois quanto mais rapido e forte \n for seus ataques, mais chances de ganhar dos inimigos e sair vivo \n ");
    printf("Deve saber também quais as caracteristicas do seu personagem, arqueiros são melhores a longo alcance por exemplo, já guerreiros nem tanto...");
    printf("Guerreiros tem muita vida e muita armadura, esse é um ponto forte, seus ataques são sempre físicos e com distancias curtas");
    printf("Magos dão dano mágico e tem skills bem desenvolvidas e algumas elementares, podem atacar a media distancia");
    printf("O QUE DEVO FAZER NESSE RPG?\n \n");
    printf("Muito simples, você irá escolher um personagem principal e sua história pelos reinos de Sylegar irá iniciar! \n");
    printf("O que obviamente não será tão fácil, se prepare aventureiro pois qualquer um dos caminhos que escolher \n terá grandes desafios");
    printf("Eu sou Artemísia, a mestra do jogo. Sejam bem vindos!");
}
void menuAtaque(){ //ataque normal ataque especial

    FILE *historiaguerreiro;
    historiaguerreiro = fopen("historia_guerreiro.txt", "r");

    if(historiaguerreiro == NULL){
        printf("Não foi possivel abrir o arquivo da historia do guerreiro");
        getchar();
        exit(0);
    }
    char historia_guerreiro_1[200];

    FILE *historiaarqueiro;
    historiaarqueiro = fopen("historia_arqueiro.txt", "r");

    if(historiaarqueiro == NULL){
        printf("Não foi possivel abrir o arquivo da historia do arqueiro");
        getchar();
        exit(0);
    }
    char historia_arqueiro_1[700];

    FILE *historiamago;
    historiamago = fopen("historia_mago.txt", "r");

    if(historiamago == NULL){
        printf("Não foi possivel abrir o arquivo da historia do mago");
        getchar();
        exit(0);
    }
    char historia_mago_1[700];


    system("cls");
	inimigo.hp=100;

	if(atributos.raca == "Mago"){
        while(fgets(historia_mago_1, 5000, historiamago)!= NULL){
        printf("%s",historia_mago_1);Sleep(200);
        }
    }
    else if(atributos.raca == "Guerreiro"){
        while(fgets(historia_guerreiro_1, 5000, historiaguerreiro)!= NULL){
        printf("%s",historia_guerreiro_1);Sleep(200);
        }
    }
    else if(atributos.raca == "Arqueiro"){
        while(fgets(historia_arqueiro_1, 5000, historiaarqueiro)!= NULL){
        printf("%s",historia_arqueiro_1);Sleep(200);
        }
    }
	printf("\n vida do inimigo: [%d]", inimigo.hp); //Indicar a vida Inicial do inimigo
    printf("\nAperte G para usar o ataque normal\nAperte H para usar o ataque especial");
	funcaocap();
	printf("\nAperte novamente a tecla");
    do{
		funcaocap();
		if (cap==103){


		inimigo.hp = inimigo.hp - atributos.str;
        printf("\n\n\n\n    SOFREU DANO!!\nVida: [%d]", inimigo.hp);
    	}else if (cap==104)
    	{


		inimigo.hp = inimigo.hp - atributos.esp;
        printf("\n\n\n\n    SOFREU DANO!!\nVida: [%d]", inimigo.hp);
    	}
	}while (inimigo.hp>0);
	return 0;
}
void menu_inicial(){ //menu do jogo iniciar e sair


    printf("\n 1- Jogar");
    printf("\n 2- Tutorial");
    printf("\n 3- Sair");
    printf("\n Apenas Aperte o numero da opcao para continuar");
    funcaocap();
    if(cap==49){
        menu_do_game();
	}
	else if(cap==50){
        tutorial();
	}
	else if(cap==51){

        printf ("\nSaindo do game...\n");
        system("pause");
	return 0;
	}
}
void menu_do_game(){ //escolha de raças (guerreiro, mago e arqueiro)

//ARQUIVOSSSSS
    FILE *char_gue;
    char_gue = fopen("char_guerreiro.txt", "r");

    if(char_gue == NULL){
        printf("Não foi possivel abrir o arquivo do guerreiro");
        getchar();
        exit(0);
    }
    char char_guerreiro[6700]; //mostra o guerreiro

 FILE *char_arq;
    char_arq = fopen("char_arqueiro.txt", "r");

    if(char_arq == NULL){
        printf("Não foi possivel abrir o arquivo do arqueiro");
        getchar();
        exit(0);
    }
    char char_arqueiro[6700]; //mostra o arqueiro

 FILE *char_mago;
    char_mago = fopen("char_mago.txt", "r");

    if(char_mago == NULL){
        printf("Não foi possivel abrir o arquivo do mago");
        getchar();
        exit(0);
    }
    char c_mago[6700]; //mostra o mago
//ARQUIVOS

    printf("\nDigite o nome do seu personagem:");
    scanf("%s", atributos.nome);

    printf ("\nEscolha sua Classe\n");
    printf ("\nGuerreiro, Arqueiro, Mago:\n");
    scanf ("%s", atributos.raca);

	system("cls");
    if (strcmp(atributos.raca,"Guerreiro")==0){
        printf ("Atributos do Guerreiro:");
        //guerreiroimagem();
///////////////////////////////////////////////////////////////////
while(fgets(char_guerreiro, 300, char_gue)!= NULL){
            printf("%s",char_guerreiro);Sleep(200);
          }
		atributos.hp=1200;
		atributos.str=14;
		atributos.def=5;
		atributos.esp=3;
		printf ("\nHP [%d]", atributos.hp);Sleep(1500);
		printf ("\nSTR [%d]", atributos.str);Sleep(1500);
		printf ("\nDEF [%d]", atributos.def);Sleep(1500);
		printf ("\nESP [%d]", atributos.esp);Sleep(1500);
        }
    else if (strcmp(atributos.raca,"Arqueiro")==0){
        printf ("Atributos do Arqueiro:");
        //arqueiroimagem();
///////////////////////////////////////////////////////////////////////////
        while(fgets(char_arqueiro, 300, char_arq)!= NULL){
            printf("%s",char_arqueiro);Sleep(200);
          }
        atributos.hp=600;
		atributos.str=8;
		atributos.def=3;
		atributos.esp=9;

		printf ("\nHP [%d]", atributos.hp);Sleep(1500);
		printf ("\nSTR [%d]", atributos.str);Sleep(1500);
		printf ("\nDEF [%d]", atributos.def);Sleep(1500);
		printf ("\nESP [%d]", atributos.esp);Sleep(1500);
        }
    else if (strcmp(atributos.raca,"Mago")==0){
        printf ("Atributos do Mago:");
        //maguinhoimagem();
//////////////////////////////////////////////////////////////////////////
        while(fgets(c_mago, 110, char_mago)!= NULL){
            printf("%s",c_mago);Sleep(200);
          }
        atributos.hp=300;
		atributos.str=3;
		atributos.def=2;
		atributos.esp=20;
		printf ("\nHP [%d]", atributos.hp);Sleep(1500);
		printf ("\nSTR [%d]", atributos.str);Sleep(1500);
		printf ("\nDEF [%d]", atributos.def);Sleep(1500);
		printf ("\nESP [%d]", atributos.esp);Sleep(1500);



	}
	printf("\nSeu nick:%s\n", atributos.nome);
    system("pause");

    FILE *historiaguerreiro;
    historiaguerreiro = fopen("historia_guerreiro.txt", "r");

    if(historiaguerreiro == NULL){
        printf("Não foi possivel abrir o arquivo da historia do guerreiro");
        getchar();
        exit(0);
    }
    char historia_guerreiro_1[900];

    FILE *historiaarqueiro;
    historiaarqueiro = fopen("historia_arqueiro.txt", "r");

    if(historiaarqueiro == NULL){
        printf("Não foi possivel abrir o arquivo da historia do arqueiro");
        getchar();
        exit(0);
    }
    char historia_arqueiro_1[900];

    FILE *historiamago;
    historiamago = fopen("historia_mago.txt", "r");

    if(historiamago == NULL){
        printf("Não foi possivel abrir o arquivo da historia do mago");
        getchar();
        exit(0);
    }
    char historia_mago_1[900];

	if(strcmp(atributos.raca, "Mago")==0){
        while(fgets(historia_mago_1, 5000, historiamago)!= NULL){
        printf("%s",historia_mago_1);Sleep(200);

        }system("pause");
    }
    else if(strcmp(atributos.raca,"Guerreiro")==0){
        while(fgets(historia_guerreiro_1, 5000, historiaguerreiro)!= NULL){

        printf("%s",historia_guerreiro_1);Sleep(200);


        }system("pause");
    }
    else if(strcmp(atributos.raca,"Guerreiro")==0){
        while(fgets(historia_arqueiro_1, 5000, historiaarqueiro)!= NULL){
        printf("%s",historia_arqueiro_1);Sleep(200);


        }system("pause");
    }
    menuAtaque();
}
int main(){
    setlocale(LC_ALL, "Portuguese");

    FILE *tracinho;
    tracinho = fopen("tracinhos.txt", "r");

    if(tracinho == NULL){
        printf("Não foi possivel abrir o arquivo do traço");
        getchar();
        exit(0);
    }
    char traco[200]; //mostra os tracinhos
    while(fgets(traco, 6700, tracinho)!= NULL){
        printf("%s",traco);Sleep(200);
          }
    menu_inicial();

return 0;
}
