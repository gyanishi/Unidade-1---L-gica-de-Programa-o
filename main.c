#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define maxVei 10
#define MARCA 100
#define MODELO 150
#define PLACA 100

// inplementar sistema de armazenagem em txt, sistema de checagem de entrada no cadastro(n consegui)

typedef struct {
	char marca[MARCA], modelo[MODELO], placa[PLACA], entSistema_Modelo[MODELO];
	int anofab, existencia;
}veiculo;
veiculo	Veiculo[maxVei];

int menup();
int lista();
int cadVec();
int excVec();
int listaC();
int listaAe();
int listaM();

int main() {
	setlocale(LC_ALL, "Portuguese");
	menup();
	return 0;
}

int menup() {
	int selecao;
	do {
		system("cls");
		printf("Digite o número correspondente para selecionar a opção\n");
		printf("1 - Listar veículos cadastrados\n");
		printf("2 - Cadastro de um novo veículo\n");
		printf("3 - Excluir um veículo\n");
		printf("4 - Sair\n");
		printf("Opção: ");
		scanf("%d", &selecao);
		getchar();
		
		switch (selecao) {
			case 1 :
				lista();
				break;
			case 2 :
				cadVec();
				break;
			case 3 :
				excVec();
				break;
			case 4 :
				exit(0);
			default :
				system("cls");
				printf("Por favor, selecione uma opção valida\n\n");
				selecao = 0;
				return main(2);
		}
	} while (selecao != 4);
}

int lista (){
	system("cls");
	int selecaol;
	do {
		system("cls");
		printf("Digite o número correspondente para selecionar o tipo de listagem\n");
		printf("1 - Ordem crescente por ordem de cadastro\n");
		printf("2 - Listar veículos a partir do ano especificado\n");
		printf("3 - Listagem por modelo\n");
		printf("4 - Voltar\n");
		printf("5 - Sair\n");
		printf("Opção: ");
		scanf("%d", &selecaol);
		
		getchar();
		switch (selecaol) {
			case 1 :
				listaC();
				break;
			case 2 :
				listaAe();
				break;
			case 3 :
				listaM();
				break;
			case 4 :
				system("cls");
				return menup(0);
				getchar();
				break;
			case 5 :
				exit(0);
			default :
				printf("Por favor, selecione uma opção valida");
				return lista(1);
				system("cls");
		}
		getchar();
	} while (selecaol != 5);
	
}

int listaC() {
	system("cls");
	int selecaoA;
	printf("Lista de veículos ordenados pelo número do veículo\n");
	do {
		system("cls");
		int i;
		for(i = 0; i < maxVei; i++) {
			if(Veiculo[i].existencia == 1){
				printf("============================\nNúmero do Veículo - %d\n", i + 1);
				printf("Ano de Fabricação: %d\n", Veiculo[i].anofab);
				printf("Marca: %s", Veiculo[i].marca);
				printf("Modelo: %s", Veiculo[i].modelo);
				printf("Placa: %s", Veiculo[i].placa);
			}
		}
		printf("============================\n");
		printf("1 - Voltar\n");
		printf("Opção: ");
		fflush(stdin);
		scanf("%d", &selecaoA);
	} while (selecaoA != 1);
	
}

int listaAe() {
	int selecaoAe;
	do {
		system("cls");
		printf("Lista de veículos a partir do Ano de Fabricação\n");
		printf("Ano de fabricação a ser pequisado: ");
		int ano, i;
		scanf("%d", &ano);
		for(i = 0; i < maxVei; i++) {
			if(Veiculo[i].existencia == 1){
				if (ano < Veiculo[i].anofab) {
					printf("============================\nNúmero do Veículo - %d\n", i + 1);
					printf("Ano de Fabricação: %d\n", Veiculo[i].anofab);
					printf("Marca: %s", Veiculo[i].marca);
					printf("Modelo: %s", Veiculo[i].modelo);
					printf("Placa: %s", Veiculo[i].placa);
				}
			}
		}
		printf("============================\n");
		printf("1 - Fazer outra pesquisa\n");
		printf("2 - Sair\n");
		printf("Opção: ");
		scanf("%d", &selecaoAe);
	} while (selecaoAe != 2);
}

int listaM() {
	system("cls");
	char modeloo[MODELO], entUsuario[MODELO], entSistema[MODELO], s1[MODELO], s2[MODELO];
	int selecaoM, k	;
	do {
		system("cls");
		printf("Digite o modelo do veículo a ser pesquisado: ");
		fflush(stdin);
		fgets(modeloo, sizeof(modeloo), stdin);
		
		int t = 0;
		while(modeloo[t] != '\0') {
			entUsuario[t] = tolower(modeloo[t]);
			t++;
		}
		entUsuario[t] = '\0';
		
		for (k = 0; k < maxVei; k++) {
			if(Veiculo[k].existencia == 1){
				int r = 0;
				while(Veiculo[k].modelo[r] != '\0') {
					Veiculo[k].entSistema_Modelo[r] = tolower(Veiculo[k].modelo[r]);
					r++;
				}
				Veiculo[k].entSistema_Modelo[r] = '\0';
			}
		}
		
		int i;
		for (i = 0; i < maxVei; i++) {
			if(Veiculo[i].existencia == 1){
				if (strcmp(Veiculo[i].entSistema_Modelo, entUsuario) == 0) {
					printf("============================\nNúmero do Veículo - %d\n", i + 1);
					printf("Ano de Fabricação: %d\n", Veiculo[i].anofab);
					printf("Marca: %s", Veiculo[i].marca);
					printf("Modelo: %s", Veiculo[i].modelo);
					printf("Placa: %s", Veiculo[i].placa);
				}
			}
		}
		
		printf("============================\n");
		printf("1 - Fazer outra pesquisa\n");
		printf("2 - Sair\n");
		printf("Opção: ");
		scanf("%d", &selecaoM);
	} while (selecaoM != 2);
}

int cadVec (){
	system("cls");
	char marcac[MARCA], modeloc[MODELO], placac[PLACA];
	int anofabc, selecaoc = 1;
	
	do {
		system("cls");
		printf("Marca: ");
		getchar();
		fgets(marcac, sizeof(marcac), stdin);
		printf("Modelo: ");
		fgets(modeloc, sizeof(modeloc), stdin);
		printf("Placa: ");
		fgets(placac, sizeof(placac), stdin);
		printf("Ano de Fabricação: ");
		scanf("%d", &anofabc);
		
		int i;
		for (i = 0; i < maxVei; i++) {
			if(Veiculo[i].existencia == 0) {
				strcpy(Veiculo[i].marca, marcac);
				strcpy(Veiculo[i].modelo, modeloc);
				strcpy(Veiculo[i].placa, placac);
				Veiculo[i].anofab = anofabc;
				Veiculo[i].existencia = 1;
				system("cls");
				printf("Cadastrado com sucesso\n");
				break;
			}
			if(i == maxVei-1) {
				system("cls");
				printf("Quantidade máxima de veículos cadastrados atingido\n");
			}
		}
		
		printf("============================\n");
		printf("1 - Cadastrar outro veículo\n");
		printf("2 - Sair\n");
		printf("Opção: ");
		scanf("%d", &selecaoc);
	}while (selecaoc != 2);
}

int excVec() {
	int selecaox = 2;
	int confirmacao;
	do {
		system("cls");
		int exist, Vexis;
		int i;
		for(i = 0; i < maxVei; i++) {
			if(Veiculo[i].existencia == 1){
				printf("============================\nNúmero do Veículo - %d\n", i + 1);
				printf("Ano de Fabricação: %d\n", Veiculo[i].anofab);
				printf("Marca: %s", Veiculo[i].marca);
				printf("Modelo: %s", Veiculo[i].modelo);
				printf("Placa: %s", Veiculo[i].placa);
			}
		}
		printf("============================\n");
		printf("Digite o número do veículo a ser removido\n");
		printf("Opção: ");
		scanf("%d", &Vexis);
		exist = Vexis - 1;
		getchar ();
		system("cls");
		do {
			system("cls");
			printf("Tem certeza que deseja apagar o veículo %d permanentemente?\n", Vexis);
			printf("1 - Confirmar ação\n");
			printf("2 - Cancelar ação\n");
			printf("Opção: ");
			scanf("%d", &confirmacao);
			if (confirmacao == 1){
				Veiculo[exist].existencia=0;
				system("cls");
				printf("Veículo removido\n");
				break;
			} else {
				system("cls");
				printf("Ação de exclusão do veículo %d cancelado, os dados do veículo irá permanecer na base de dados\n", Vexis);
			}
		} while (confirmacao != 2);
		printf("============================\n");
		printf("1 - Selecionar outro veículo a ser removido\n");
		printf("2 - Sair\n");
		printf("Opção: ");
		scanf("%d", &selecaox);	
		getchar();
	} while (selecaox != 2);
	return 0;
}
