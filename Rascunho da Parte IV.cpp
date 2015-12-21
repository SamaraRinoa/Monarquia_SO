
#include <bits/stdc++.h>

using namespace std;

//Inicio das estruturas

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

typedef struct Memoria{
	int tamanho;
	int *vet;
	descricao_memoria descricaom;
}memoria;

typedef struct Processo{
	int regis_base;
	int regis_limite;
	int id;
	int tamanho;
	descricao_processo descricaop;
}processo;

//Fim das estruturas

//Inicio da Parte I

memoria* criarMemoria(int tamanho){
	memoria *mem = new memoria;
	mem->tamanho = tamanho;
	mem->vet = new int [tamanho];
	return mem;
}

void limparMemoria(memoria *mem){
	for(int i=0; i<=mem->tamanho; i++){
		mem->vet[i] = 0;
	}
}

void escreverMemoria(int in,int fi,int conteudo, memoria *mem){
	for(int i=in; i<fi; i++){
		mem->vet[i] = conteudo;
	}
}

void liberarMemoria(memoria *mem){
	delete mem->vet;
	delete mem;
}

//Fim da Parte I

//Inicio da Parte II

processo* criarProcesso(int regis_limite, int regis_base, int id, int tamanho){
	processo *pro = new processo;
	pro->regis_limite = regis_limite;
	pro->regis_base = regis_base;
	pro->tamanho = tamanho;
	pro->id = id;
	return pro;
}

void liberarProcesso(processo *pro){
	delete pro;
}

void escreverProcesso (memoria *mem, processo *pro){
	escreverMemoria(pro->regis_base, pro->regis_limite, pro->id, mem);
}

void guardarProcesso (memoria *mem, processo *pro,int cont){
	escreverMemoria(pro->regis_base, pro->regis_limite, cont, mem);
}

void retiraProcesso (memoria *mem, processo *pro){
	escreverMemoria(pro->regis_base, pro->regis_limite, 0, mem);
}

//Fim da Partedescricao_memoria II

//Inicio da Parte III

descricao_memoria get_da_descricao_memoria(memoria *mem){
	return mem->descricaom;
}

descricao_processo get_da_descricao_processo(processo *pro){
	return pro->descricaop;
}

bool alocar_processo_sobreposicao(memoria *mem, processo *pro){
	mem->descricaom.principal.inicio = 0;
	mem->descricaom.principal.fim = (mem->tamanho*3)/4;
	mem->descricaom.sobreposicao.inicio = mem->descricaom.principal.fim+1;
	mem->descricaom.sobreposicao.fim = mem->tamanho-1;
	pro->descricaop.principal.inicio = mem->descricaom.principal.inicio;
	pro->descricaop.principal.fim = mem->descricaom.principal.fim;
	pro->descricaop.sobreposicao->areas.inicio = pro->descricaop.principal.fim+1;
	pro->descricaop.sobreposicao->areas.fim = pro->tamanho-1;
	pro->descricaop.quantidade_sobreposicao = (pro->tamanho - pro->descricaop.principal.fim)/(mem->tamanho - mem->descricaom.principal.fim);
	escreverMemoria(mem->descricaom.principal.inicio, mem->descricaom.principal.fim, pro->id, mem);
	escreverMemoria(mem->descricaom.sobreposicao.inicio, mem->descricaom.sobreposicao.fim, pro->descricaop.sobreposicao->id, mem);
	return  true;	
}

bool alocar_processo_simples(memoria *mem, processo *pro){
	if(pro->tamanho <= mem->tamanho){
		escreverProcesso(mem, pro);
		return true;
	}
	return false;
}

bool trocar_area_sobreposicao(memoria *mem, processo *pro, int id){
	escreverMemoria(mem->descricaom.sobreposicao.inicio, mem->descricaom.sobreposicao.fim, id, mem);
}

//Fim da Parte III



/*Inicio da Parte IV (estatica)

void particionar(memoria *mem){
	
}

descricao_memoria retornar_particionamento(memoria *mem){
	return get_da_descricao_memoria(memoria *mem);
}

void alocar_processo (processo *pro, memoria *mem, int op){
	if (op==1){
		alocar_processo_simples(*mem, *pro);
	}else if (op==2){
		alocar_processo_sobreposicao(*mem, *pro);
	}
}

void remover_processo (memoria *mem, processo *pro){
	retiraProcesso (*mem, *pro);
}

void listar_processo (processo *pro){
	descricao_processo get_da_descricao_processo(*pro);
}

processo espacos_em_fragmentacao(){
	
}

Fim da Parte IV (estatica)*/



/*Inicio da Parte IV (dinamica)

void alocar_processo (processo *pro, memoria *mem, int op){
	
}

void remover_processo (memoria *mem, processo *pro){
	
}

void listar_processo (processo *pro){
	
}

processo listar_espacos_em_fragmentacap(){
	
}

//Fim da Parte IV (dinamica)
//Aleluia! Xaramanaia Esbagassubia! #ForaCorruPTos #JBPresidente

*/

int main(){
	return 0;
}