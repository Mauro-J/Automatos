#include <iostream>
#include <string>
using namespace std;

struct Transicao{
	string estadoAtual;
	string Alfabeto;
	string proximoEstado;
};
int tamAlfabeto = 2;
string estadoFinal = "q1";
int tamEstados = 2;
void imprimeTbl();

int main() {
	imprimeTbl();
}

void imprimeTbl(){
	//char alfabeto[tamAlfabeto];
	string alfabeto[] = {"a","b"};

	cout << "----SIMULADOR DE AUTOMATO FINITO----\n" << endl;
	cout << "\n1. Informe o tamanho do alfabeto: " << endl;

	
	//cin >> tamAlfabeto;

	
	cout << "\n2. Informe os símbolos do alfabeto: " << endl;
	char aux;
	/*for(int i = 0;i < tamAlfabeto;i++){
		cin >> aux;
		if(aux != '0'){
			alfabeto[i] = aux;
		}else{
			break;
		}
	}*/

	cout << "\nAlfabeto: {";
	for(int i = 0; i < tamAlfabeto; i++){
		cout << alfabeto[i];
		if(i != tamAlfabeto - 1){
			cout << " , ";
		}
	}
	cout << "}" <<endl;
	
	cout << "\n3. Informe o número de estados: " << endl;
	
	//cin >> tamEstados;

	cout << "\n4. Digite o numero do estado correspondente ao ESTADO FINAL: " << endl;
	for(int i = 0;i < tamEstados;i++){
		cout << "q" << i << ": " << i+1 << endl;
	}

	
	//cin >> estadoFinal;
 estadoFinal = tamEstados;

	Transicao transicoes[tamEstados];

	cout << "\n5. Informe as transições de cada estado: " << endl;
	for(int i = 0;i < tamEstados;i++){
		for(int j = 0; j <tamAlfabeto; j++){
			cout << "q" << i << " com transição em \"" << alfabeto[j] << "\" vai para q" <<endl;
			transicoes[i].estadoAtual = j;
			transicoes[i].Alfabeto = alfabeto[j];
			cin >> transicoes[i].proximoEstado;

		}
	}
	cout << "\n=============================" << endl;

	for(int i = 0;i < tamEstados;i++){
		for(int j = 0; j <tamAlfabeto; j++){
			cout << "q" << transicoes[i].estadoAtual << endl;
			cout << transicoes[j].Alfabeto << endl;
			cout << "q" << transicoes[i].proximoEstado << endl;
		}
		cout << "===" << endl;
	}

	string EstadoAtual = "q0";
	for(int i = 0;i < tamEstados;i++){
		if(transicoes[i].estadoAtual == EstadoAtual && transicoes[i].Alfabeto == alfabeto[i]){
			EstadoAtual = transicoes[i].proximoEstado;
		}
		
	}
	if(estadoFinal == EstadoAtual){
		cout << "Aceito!" <<endl;
	}else{
		cout << "Rejeitado!" <<endl;
	}
	
	
}
