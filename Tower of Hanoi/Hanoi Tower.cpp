#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<windows.h>

void to(int qd, char i, char f, char ar);
void re();
void mov(int x);

int main(){
	
	int qd;
	int op=8;
	int z;
	
	do{
	
		printf("BEM VINDO A TORRE DE HANOI");
		printf("\n\n|1| Regras");
		printf("\n|2| Calculo de quantidade de movimentos");
		printf("\n|3| Instrucao dos movimentos");
		printf("\n|0| Sair");
		printf("\n\nEscolha uma das opcoes: ");
		scanf("%d", &op);

		if(op==0){
			printf("\nTCHAU!");
		}

		switch(op){

			case 0:{
				break;
			}

			case 1:{

				re();
				printf("\n\ninsira 0 para voltar ao menu: ");
				scanf("%d", &z);
				if(z==0){
					system("cls");
				}

				break;
				
			}

			case 2:{

				printf("\n\nInsira a quantidade de discos: ");
				scanf("%d", &qd);
				
				mov(qd);
				
				printf("\n\ninsira 0 para voltar ao menu: ");
				scanf("%d", &z);
				if(z==0){
					system("cls");
				}

				break;
		
			}

			case 3:{

				printf("\n\nInsira a quantidade de discos: ");
				scanf("%d", &qd);
				printf("\n");

				to(qd, 'A', 'C', 'B');

				printf("\n\ninsira 0 para voltar ao menu: ");
				scanf("%d", &z);
				if(z==0){
					system("cls");
				}

				break;
				
			}

			default:{

				printf("\nVOCE INSERIU UM NUMERO INVALIDO!");
				Sleep(2000);
				system("cls");

				break;
				
			}

		}
	
	}while(op!=0);
	
}

void to(int qd, char i, char f, char ar){
	
	if(qd==1){
		printf("\npasse o disco 1 da torre (%c) para a torre (%c)", i, f);
		return;
	}
	
	else{
		to(qd-1, i, ar, f);
		printf("\npasse o disco %d da torre (%c) para a torre (%c)", qd, i, f);
		to(qd-1, ar, f, i);
	}
	
}

void re(){
	
	printf("\n\n        -------------------------------------------------REGRAS-------------------------------------------------");
	printf("\n        | (1) O disco do topo em qualquer um dos pinos pode ser movido para qualquer um dos outros dois pinos. |");
	printf("\n        | (2) Apenas um disco pode ser movido por vez                                                          |");
	printf("\n        | (3) Um disco maior nunca pode ser colocado sobre um disco menor.                                     |");
	printf("\n        --------------------------------------------------------------------------------------------------------");
	
}

void mov(int x){

	int m;
	m=(pow(2,x))-1;
	printf("\nNumero de discos: %d", x);
	printf("\nNumero de movimentos necessarios: %d", m);
	
}
