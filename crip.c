#include <stdio.h>
#include <stdlib.h>
#include <locale.h> /* Biblioteca necessaria para utilizar comando "setlocale()" */
#include <math.h>  /* Para efetuar Outros Calculos */
#include <string.h> /* Serve para Manipulação de String*/

// Programa para criptografar em tabela ASCII -> strlen -> calcular o número de caracteres em uma string (enquanto a soma dos caracteres)

int main(void) {
	setlocale(LC_ALL, "Portuguese");
	
    char arquivo[200][2];
	char op;
    int x;
    
    void menu() {
    	system("cls");
    	printf("\n\tMenu principal\n\n");
    	printf("-------------------------------------\n");
		printf(" c - Criptografar\n");
		printf(" d - Descriptografar\n");
		printf(" s - Sair\n");
    	printf("-------------------------------------\n\n");
		printf("Opção: ");
    	scanf("%c", &op);
	}
    //Menu De opções
    void menu1() {
    	menu();
    	fflush(stdin);
		//Seleção de opções
    	if(op=='c' || op=='C' || op=='d' || op=='D') {
    		system("cls");
			printf("\nConfirmado comando %c \n\nContinuando...\n", op);
			system("timeout /t 2");
		} else if (op=='s' || op=='S') {
			system("cls");
			printf("Saindo...");
			exit(0);
		} else {
			printf("\nOpção inválida\n");
			system("timeout /t 1");
			system("cls");
			menu1();
		}
	}

	//Chamada do menu
	menu1();
	fflush(stdin);
    
	/* Criptografar */
	if (op=='c' || op=='C') {
	system("cls");
	arquivo[x][0]= 0;
	printf("\nCriptografe o Arquivo\n");
   	printf("\nNome do Arquivo: ");
    scanf("%[^\n]s", &arquivo);    
	if(strlen(arquivo) == 1) {
		arquivo[x][0] += 8;
	} else if(strlen(arquivo) > 1) {
	    for( x = 0; x < strlen(arquivo) - x - 1; x++ ) {
			arquivo[x][0] += 3;
			arquivo[x][1] += x - 1 * 20;
		}
		} else if(strlen(arquivo) <= 0){
	    	printf("\nNada a criptografar!\n");
	    	exit(0);
		}
	printf(">> Nome criptografado: %s\n\n ", arquivo);
	} 
	
	/* Descriptografar */
	if (op=='d' || op=='D') {
	system("cls");
	arquivo[x][0]= 0;
	printf("\nDescriptografe o Arquivo\n");
	printf("\nNome do Arquivo: ");
    scanf("%[^\n]s", &arquivo); 
    if(strlen(arquivo) == 1) {
    	arquivo[x][0] -= 8;
	} else if(strlen(arquivo) > 1) {
    	for( x = 0; x < strlen(arquivo) - x - 1; x++ ){
			arquivo[x][0] -= 3;
			arquivo[x][1] -= x - 1 * 20;
		}
    	} else if(strlen(arquivo) <= 0){
	    	printf("\nNada a Descriptografar!\n");
	    	exit(0);
		}
	printf(">> Nome descriptografado: %s\n\n ", arquivo[0]);
	}		 

	return 0;
}
