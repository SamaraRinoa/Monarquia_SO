#include <bits/stdc++.h>

using namespace std;

typedef struct Memoria{
	int tamanho;
	int inicio;
	int fim;
	int conteudo;
}memoria;

memoria criarMemoria(int tamanho, memoria mem){
	memoria *pontmem = new mem[tamanho];
}

void limparMemoria(memoria mem*, int i){
	mem.inicio[i]=0;
	mem.fim[i]=0;
	mem.conteudo[i]=0;
}

void escreverMemoria(int inicio, int fim, int conteudo, memoria mem*, int i){
	mem.inicio[i]=inicio;
	mem.fim[i]=fim;
	mem.conteudo[i]=conteudo;
}

void liberarMemoria(int i, memoria mem){
	memoria *pontmem = delete mem[i];
}

int main(){
	return 0;
}
