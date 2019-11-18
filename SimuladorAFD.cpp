#include <iostream>
#include <string>
using namespace std;

void imprimeTbl();
void imprimeCL(string entrada, int estado, int posicao);
void Resultado(bool aceito, string casoTeste);

struct Transicao{
	char simbolo;
	int proximoEstado;
};

struct Regra{
	string Alfabeto;
	Transicao transicao[];
};

//***
int main() {
	imprimeTbl();

	return 0;
}
//***

void imprimeTbl(){

	int tamAlfabeto = 0;
	int estadoFinal = 0;
	int tamEstados = 0;
	
	
	// char alfabeto[tamAlfabeto];
	// string alfabeto("01");
	string alfabeto;


	cout << "\n\n----SIMULADOR DE AUTOMATO FINITO----\n" << endl;

	cout << "\n1. Informe o tamanho do alfabeto: " << endl;
	cin >> tamAlfabeto;

	
	cout << "\n2. Informe os símbolos do alfabeto (sem espaços): " << endl;
	cin >> alfabeto;
	
	/*
	char aux;
	for(int i = 0;i < tamAlfabeto;i++){
		cin >> aux;
		if(aux != '0'){
			alfabeto[i] = aux;
		}else{
			break;
		}
	}
	*/
	
	cout << "\n--- Alfabeto: {";
	for(int i = 0; i < alfabeto.length(); i++){
		cout << alfabeto[i];
		if(i != alfabeto.length() - 1){
			cout << " , ";
		}
	}
	cout << "} ---" <<endl;
	
	cout << "\n3. Informe o número de Estados: " << endl;
	cin >> tamEstados;

	cout << "\n4. Digite o numero do estado correspondente ao ESTADO FINAL: " << endl;
	for(int i = 0;i < tamEstados;i++){
		cout << "Estado(" << i << "): Digite " << i+1 << endl;
	}
	cin >> estadoFinal;

	cout << "\n--- Estado Final: " << estadoFinal << " ---" << endl;

 	//estadoFinal = tamEstados;

	cout << "\n--- Transições ---" << endl;

	Regra regra[tamEstados];
	// CASOS DE TESTES
 /*
	regra[0].transicao[0].simbolo = '0';
	regra[0].transicao[0].proximoEstado = 0;
	regra[0].transicao[1].simbolo = '1';
	regra[0].transicao[1].proximoEstado = 1;

	regra[1].transicao[0].simbolo = '0';
	regra[1].transicao[0].proximoEstado = 1;
	regra[1].transicao[1].simbolo = '1';
	regra[1].transicao[1].proximoEstado = 0;
	*/

	cout << "\n5. Informe as transições de cada estado: " << endl;
	for(int i = 0;i < tamEstados;i++){
		for(int j = 0; j < alfabeto.length(); j++){
			cout << "Estado "  << i << " com transição em \"" << alfabeto[j] << "\" muda para o Estado:" <<endl;
			// regra[i].Alfabeto[j] = alfabeto[j];
			regra[i].transicao[j].simbolo = alfabeto[j];
			cin >> regra[i].transicao[j].proximoEstado;
		}
	}
	cout << "\n=============================" << endl;

	// CASO DE TESTE
	string casoTeste("0000111");
	cout << "\n6. Informe o caso de teste: " << endl;
	cin >> casoTeste;

	cout << "\n--- Tamanho da entrada: " << casoTeste.length() << " ---\n" << endl;


	//alfabeto = "01";

	char elemento;
	
	bool aceito = false;
	int encontrado = 0;

	for(int i = 0; i < casoTeste.length(); i++){
		elemento = casoTeste[i];
		
		encontrado = alfabeto.find(elemento);
	
		if(encontrado  >= 0){
			//cout << i << ": " << elemento << " ENCONTRADO" << endl;
			aceito = true;
		}else{
			cout << "O Elemento: \"" << elemento << "\" Não pertence ao alfabeto informado!" << endl;
			aceito = false;
			break;
		}
	}

	int posicao = 0, estadoAtual = 0;

	while(aceito){

		cout << "\n=== MUDANÇAS DE ESTADO ===" << endl;
		for(int i = 0; i < casoTeste.length() && aceito == true; i++,posicao++){

			imprimeCL(casoTeste, estadoAtual, posicao);

			elemento = casoTeste[i];

			for(int j = 0; j < alfabeto.length(); j++){
				if(regra[estadoAtual].transicao[j].simbolo == elemento){
					estadoAtual = regra[estadoAtual].transicao[j].proximoEstado;
					//cout << "EstadoAtual: " << estadoAtual << endl;
				}
				if(true){}
			}
		}
		imprimeCL(casoTeste, estadoAtual, posicao);
		break;
	}
		
	Resultado(aceito,casoTeste);


	/*
	for(int i = 0;i < tamEstados;i++){
		for(int j = 0; j <alfabeto.length(); j++){
			// cout << regra[j].Alfabeto << endl;
			if(i == regra[i].transicao.proximoEstado){
			cout << "ESTADO "<< i << " com \"" << alfabeto[j] << "\" fica no Estado: " << regra[i].transicao.proximoEstado << endl;
			}else{
			cout << "ESTADO "<< i << " com \"" << alfabeto[j] << "\" vai para o Estado: " << regra[i].transicao.proximoEstado << endl;
			}
		}
		cout << "===" << endl;
	}
	*/
 } //

void imprimeCL(string entrada, int estado, int posicao) {
	cout << posicao << ": ";
	for(int i = 0; i < posicao; i++){
		cout << entrada[i];
	}

	cout << "[q" << estado << "]";

	for(int j = posicao; j <= entrada.length(); j++){
		cout << entrada[j];
	}
	cout << endl;
}

void Resultado(bool aceito, string casoTeste){
	if(aceito){
		cout << "\n === A Entrada: {"<< casoTeste << "} foi ACEITA pelo Automato! ===" << endl;
	}else{
		cout << "\n === A Entrada: {"<< casoTeste << "} NÃO FOI ACEITA pelo Automato! ===" << endl;
	}
}
