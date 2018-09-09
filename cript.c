//imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int args, char *argv[]) {

	FILE *arq1, *arq2; // Declara os dois ponteiro de arquivos
	char *chave, *contador; // declara a chave a ser recebido por argumentos
	int c; // inteiro que ira indexar a chave

	// a chave sera o primeiro argumento
	chave = argv[1];

	if(*chave != '\0' && chave != "") { //certifica que o ponteiro nao esta nulo
		arq1 = fopen(argv[2], "rb"); // wb = GRAVAR - rb = LEITURA (b = binary(Vai ler bit a bit os caracteres ali dentro))
		if(arq1 != NULL){ // verifica se o arquivo existe
			arq2 = fopen(argv[3], "wb"); // abre o segundo arquivo em modo de gravação binaria
			if(arq2 != NULL){ // se o argumento do segundo arquivo for digitado
				while((c = getc(arq1)) !=EOF) { // obtém caracteres até o fim do arquivo
					//Esquação
					chave = argv[1];
					c = c - strlen(argv[1]);
					c = c ^ *(chave++); // usa a operação XOR nos caracteres do arq1 e da chave				 
					putc(c, arq2);	// inclui o caracter no arquivo criptografado
				}
				fclose(arq2); // fecha o arquivo 2
			} else {
				//erro, sem saida de arquivo
				printf("Entre com a saida do arquivo\n");
			} 
			fclose(arq1); // fecha o arquivo1 
		} else {
			//saida de erro de arquivo inexistente
			printf("Entre com o arquivo ou arquivo inexistente!\n");
		} 
	} 
	return 1;
}  