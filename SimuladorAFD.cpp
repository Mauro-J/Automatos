#include <iostream>
#include <string>
using namespace std;

void imprimeTbl();
void imprimeCL(string entrada, int estadoAtual, int posicao);
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

	int estadoFinal = 1;
	int tamEstados = 2;
	
	
	// string alfabeto("01");
	string alfabeto("01");

  string casoTeste("00010110");

  Regra Estado[tamEstados];
  
	// CASOS DE TESTES de exemplo
  //Cadeia com numero par de 0s
 
	Estado[1].transicao[0].simbolo = '0'; //Ex. Estado(1) com simbolo de transição 0 
	Estado[1].transicao[0].proximoEstado = 2; // continua no estado(1)
	Estado[1].transicao[1].simbolo = '1';
	Estado[1].transicao[1].proximoEstado = 1;

	Estado[2].transicao[0].simbolo = '0';
	Estado[2].transicao[0].proximoEstado = 1;
	Estado[2].transicao[1].simbolo = '1';
	Estado[2].transicao[1].proximoEstado = 2;


	cout << "----SIMULADOR DE AUTOMATO FINITO----\n" << endl;
	
	cout << "\n1. Informe os símbolos do alfabeto (sem espaços): " << endl;
	cin >> alfabeto;
	

	
	cout << "\n--- Alfabeto: {";
	for(int i = 0; i < alfabeto.length(); i++){
		cout << alfabeto[i];
		if(i != alfabeto.length() - 1){
			cout << " , ";
		}
	}
	cout << "} ---" <<endl;
	
	cout << "\n2. Informe a quatidade de Estados: " << endl;
	cin >> tamEstados;

	cout << "\n3. Digite o numero do estado correspondente ao ESTADO FINAL: " << endl;
	for(int i = 1;i <= tamEstados;i++){
		cout << "Estado(" << i << "): Digite " << i << endl;
	}
	cin >> estadoFinal;

	cout << "\n--- Estado Final: " << estadoFinal << " ---" << endl;

	cout << "\n--- Transições ---" << endl;

	
	

	cout << "\n4. Informe as transições de cada estado: " << endl;
	for(int i = 1;i <= tamEstados;i++){
		for(int j = 0; j < alfabeto.length(); j++){
			cout << "Estado "  << i << " com transição em \"" << alfabeto[j] << "\" muda para o Estado:" <<endl;
			// Estado[i].Alfabeto[j] = alfabeto[j];
			Estado[i].transicao[j].simbolo = alfabeto[j];
			cin >> Estado[i].transicao[j].proximoEstado;
		}
	}
	cout << "\n=============================" << endl;

	
	cout << "\n5. Informe o caso de teste: " << endl;
	cin >> casoTeste;

	cout << "\n--- Tamanho da entrada: " << casoTeste.length() << " ---\n" << endl;


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

	int posicao = 0, estadoAtual = 1;

	while(aceito){

		cout << "\n=== MUDANÇAS DE ESTADO ===" << endl;
		for(int i = 0; i <= casoTeste.length(); i++,posicao++){

			imprimeCL(casoTeste, estadoAtual, posicao);

			elemento = casoTeste[i];

			for(int j = 0; j < alfabeto.length(); j++){
				if(Estado[estadoAtual].transicao[j].simbolo == elemento){
					estadoAtual = Estado[estadoAtual].transicao[j].proximoEstado;
					//cout << "EstadoAtual: " << estadoAtual << endl;
				}
				if(posicao == casoTeste.length()){ //Fim do Teste
          if(estadoFinal == estadoAtual){
            cout << "=== Fim do teste ===" << endl;
            aceito = true;
            break;
          }else{
            cout << "=== Fim do teste ===" << endl;
            aceito = false;
            break;
          }
        }
			}
		}
		break;
	}
		
	Resultado(aceito,casoTeste);
 } // Fim Função AFD

void imprimeCL(string entrada, int estadoAtual, int posicao) {
	cout << posicao << ": ";
	for(int i = 0; i < posicao; i++){
		cout << entrada[i];
	}

	cout << "[q" << estadoAtual << "]";

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
