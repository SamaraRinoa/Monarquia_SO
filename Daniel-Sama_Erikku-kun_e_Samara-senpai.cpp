#include <bits/stdc++.h>

using namespace std;

typedef struct Memoria{
	int tamanho;
	int *vet;
}memoria;

memoria* criarMemoria(int tamanho){
	memoria *mem = new memoria;
	mem->tamanho=tamanho;
	mem->vet = new int [tamanho];
	return mem;
}

void limparMemoria(memoria *mem){
	for(int i=0; i<=mem->tamanho; i++){
		mem->vet[i]=0;
	}
}

void escreverMemoria(int conteudo, memoria *mem){
	for(int i=0; i<mem->tamanho; i++){
		mem->vet[i]=conteudo;
	}
}

void liberarMemoria(memoria *mem){
	delete mem->vet;
	delete mem;
}

int main(){
	return 0;
}
