#include <bits/stdc++.h>

using namespace std;

typedef struct Memoria{
	int tamanho;
	int *vet;
}memoria;

typedef struct Processo{
	int regis_base;
	int regis_limite;
	int id;
	int tamanho;
}processo;

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

void escreverMemoria(int in,int fi,int conteudo, memoria *mem){
	for(int i=in; i<fi; i++){
		mem->vet[i]=conteudo;
	}
}

void liberarMemoria(memoria *mem){
	delete mem->vet;
	delete mem;
}

//Até aqui é o da memória

processo* criarProcesso(int regis_limite, int regis_base, int id, int tamanho){
	processo *pro = new processo;
	pro->regis_limite = regis_limite;
	pro->regis_base = regis_base;
	pro->tamanho = tamanho;
	return pro;
}

void liberarProcesso(processo *pro){
	delete pro;
}

void escreverProcesso (memoria *mem, processo *pro){
	escreverMemoria(pro->regis_base,pro->regis_limite,pro->id,mem);
}

void guardarProcesso (memoria *mem, processo *pro,int cont){
	escreverMemoria(pro->regis_base,pro->regis_limite,cont,mem);
}

void retiraProcesso (memoria *mem, processo *pro){
	escreverMemoria(pro->regis_base,pro->regis_limite,0,mem);
}

//Até aqui é o do processo

int main(){
	return 0;
}
