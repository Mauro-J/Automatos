#include <iostream>
#include <string>

using namespace std;

void imprimeTbl();
bool aceita(int estados[]);

int aceitacao[] = {2};
int estadoInicial = 0;

int transicao[][] = {{{0,1}, {0}},{{},     {2}},{{},     {}}};

int main() {
  

	string entrada;

	int estados[] = {estadoInicial};

	int estadosFinais[] = testa(entrada, estados, 0);
	
	if(aceita(estadosFinais)){
		cout << "Cadeia Aceita!" << endl;
	} else {
		cout << "Cadeia Rejeitada!" << endl;
	}
}

int testa(string entrada, int estados[], int posicao){
	if(posicao == entrada.length()){
		imprimeCI(entrada, estados[0], posicao);
		if(aceita(estados)) {
			return estados[];
		}
		cout << "<<backtraking>> Fim da Cadeia" << endl;
		return NULL;
	}

	int elemento = stoi(entrada[posicao]);
	for(int i:estados){
		imprimeCI(entrada, i, posicao);
		int novosEstados[] = transicao[i][elemento];
		
		if(novosEstados.length()){
			imprimeCI(entrada, novosEstados[0], posicao);
			cout << "<<backtracking>> Sem opções" << endl;
			return NULL;
		}
		int transicoes[] = testa(entrada, novosEstados, posicao+1);
		if(transicoes != NULL) {
			return transicoes;
		}
	}
	return NULL;
}

bool aceita(int estados[]){
	if(estados == NULL) return false;
	for(int i:estados){
		for(int j:aceitacao){
			if(i == j){
				return true;
			}
		}
	}
	return false;
}

void imprimeCI(string entrada, int estado, int posicao){
	for(int i = 0; int < posicao;i ++){
		cout << entrada[i];
	}
	cout << "[q" << estado << "]";
	for(int i = posicao; i <= entrada.length();i ++){
		cout << entrada[i];
	}
	cout << endl;
}

void imprimeTbl(){
	cout << "Regras de transição: DFA que reconhece cadeias com número ímpar de 1s:" << endl;
	cout << "   | 0 | 1 " << endl;
	cout << ">q0| {q0,q1} | q1" << endl;
	cout << " q1| q1| q0\n" << endl ;
	cout << "*q2| ";
}