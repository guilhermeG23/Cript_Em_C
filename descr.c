#include <stdio.h>
#include<string.h>

int main(int args, char *argv[]) {
	FILE *arq1, *arq2; // Declara os dois ponteiro de arquivos
	char *chave; // declara a chave a ser recebido por argumentos
	int c, i, j; // inteiro que ira indexar a chave

	chave = argv[1]; // a chave sera o primeiro argumento
	if(*chave != '\0'){ //certifica que o ponteiro nao esta nulo
		arq1 = fopen(argv[2], "rb"); // wb = GRAVAR - rb = LEITURA (b = binary(Vai ler bit a bit os caracteres ali dentro))
		if(arq1 != NULL){ // verifica se o arquivo existe
			arq2 = fopen(argv[3], "wb"); // abre o segundo arquivo em modo de gravação binaria
			if(arq2 != NULL){ // se o argumento do segundo arquivo for digitado
				while((c = getc(arq1)) !=EOF) { // obtém caracteres até o fim do arquivo
					if(!*chave) chave = argv[1]; // referenciu o ponteiro da chave usando o primeiro argumento
					c = c ^ *(chave++); // usa a operação XOR nos caracteres do arq1 e da chave
					c = c + strlen(argv[1]);
					 
					putc(c, arq2);	// inclui o caracter no arquivo criptografado
				}
				fclose(arq2); // fecha o arquivo 2
			}
			fclose(arq1); // fecha o arquivo1 
		}
	}
	return 1; 
}	












