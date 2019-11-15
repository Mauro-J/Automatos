#include <iostream>
#include <string>

using namespace std;

void imprimeCL(string entrada, int estado, int posicao);
void imprimeTbl();

int aceitacao[] = {1};

// estados = 0,1,2,...
//alfabeto = 0,1
int transicao[2][2] = {{0,1},{1,0}};
int estadoInicial = 0;

int main() {
	string entrada;
	int estado = estadoInicial;
	int posicao = 0;

	imprimeTbl();

	cout << "Digite a palavra: " << endl;
	cin >> entrada;
	cout << "tamanho da entrada: " << entrada.length() << endl;

	while(posicao < entrada.length()) {
		imprimeCL(entrada, estado, posicao);

		char elemento = entrada[posicao];

		if(estado == 0 && elemento =='0') {
			estado = 0;
		} else if(estado == 0 && elemento == '1') {
			estado = 1;
		} else if(estado == 1 && elemento == '0') {
			estado = 1;
		} else if(estado == 1 && elemento == '1') {
			estado = 0;
		}
		
		posicao ++;
	}
	imprimeCL(entrada, estado, posicao);

	if(estado == 1) {
		cout << "Aceito!" << endl;
	} else if(estado == 0) {
		cout << "Não Aceito!"<< endl;
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
	cout << "Regras de transição: " << endl;
	cout << "   | 0 | 1 " << endl;
	cout << ">q0| q0| q1" << endl;
	cout << "*q1| q1| q0\n" << endl ;
}

