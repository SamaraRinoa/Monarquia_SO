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

typedef struct area {
	int inicio;
	int fim;
}area;

typedef struct area_sobreposicao {
	area areas;
	int id;
}area_sobreposicao;

typedef struct descricao_memoria{
	area principal;
	area sobreposicao;
}descricao_memoria;

typedef struct descricao_processo{
	area principal;
	area_sobreposicao *sobreposicao;
	int quantidade_sobreposicao;
}descricao_processo;

//Até aqui as estruturas (mistas)

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

//Até aqui Funções Parte I

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

//Até aqui Funções Parte II

memoria descricao_memoria (memoria m){
	return m;
}

processo descricao_processo (processo p){
	return p;
}

bool alocar_processo_sobreposicao(memoria mem, processo p){
	
}

bool alocar_processo_simples(memoria mem, processo p){
	escreverMemoria(p->regis_base,p->regis_limite,p->id,mem);
}

bool trocar_area_sobreposicao(memoria mem, processo p, int identificador){
	
}

//Até aqui Funções Parte III

int main(){
	return 0;
}
