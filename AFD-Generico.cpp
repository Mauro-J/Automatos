#include <iostream>
#include <string>

using namespace std;

void imprimeCL(string entrada, int estado, int posicao);
void imprimeTbl();

int estadoAceitacao[] = {1};

int transicao[2][2] = {{0,1},{1,0}};
int estadoInicial = 0;

int main() {
	string entrada;
	int estado = estadoInicial;
	int posicao = 0;
	
	int elementoInt;
	
	imprimeTbl();

	cout << "Digite a palavra: " << endl;
	cin >> entrada;
	cout << "\nTamanho da entrada: " << entrada.length() << endl;

	while(posicao < entrada.length()) {
		imprimeCL(entrada, estado, posicao);

		string elemento = {entrada[posicao]};

		elementoInt = stoi(elemento);

		estado = transicao[estado][elementoInt];

		
		posicao ++;
	}
	imprimeCL(entrada, estado, posicao);

	bool aceita = false;
	for(int i:estadoAceitacao){
		if(estado ==1 ) aceita = true;
	}

	if(estado == 1) {
		cout << "\nAceito!" << endl;
	} else {
		cout << "\nNão Aceito!"<< endl;
	}
}

void imprimeCL(string entrada, int estado, int posicao) {
	for(int i = 0; i < posicao; i++){
		cout << entrada[i];
	}

	cout << "[q" << estado << "]";

	for(int i = posicao; i <= entrada.length(); i++){
		cout << entrada[i];
	}
	cout << endl;
}

void imprimeTbl(){
	cout << "Regras de transição: DFA que reconhece cadeias com número ímpar de 1s:" << endl;
	cout << "   | 0 | 1 " << endl;
	cout << ">q0| q0| q1" << endl;
	cout << "*q1| q1| q0\n" << endl ;
}

