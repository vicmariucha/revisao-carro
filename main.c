#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente{
	char CPF[13];
	char nome[80];
	int numcar;
}cliente;

typedef struct carro{
	int regcar;
	int qcarro;
	char modelo;
	char marca[20];
	float valor;
}carro;

void aloca_carro(carro **p, int tam);
void aloca_cliente(cliente **p, int tam);
void cadastra_carro(carro *p, int tam);
void mostra_carro(carro *p, int tam);
void cadastra_cliente(cliente *p, carro *carros, int qtd_carros);
void encerra_revisao(cliente *p, int qtd_cliente, carro *carros, int qtd_carros);

int main(void){

	carro *carros = NULL; //inicialicacao do ponteiro do tipo carro
	cliente *clientes=NULL; //inicializacao do ponteiro do tipo cliente
	int qtd_carro=3,op, qtd_cliente;

	aloca_carro(&carros, qtd_carro);
	cadastra_carro(carros, qtd_carro);

	do{
		system("cls");

		printf("\n[1] Cadastro cliente\n[2] Encerra Revisao\n[3] Sair\n\nEscolha uma opcao: ");
		scanf("%i", &op);
		fflush(stdin);

		system("cls");
		switch(op){
			case 1:
				mostra_carro(carros,qtd_carro);
				aloca_cliente(&clientes, qtd_cliente+1);
				cadastra_cliente(clientes+qtd_cliente, carros, qtd_carro);
				qtd_cliente++;
				break;
			case 2:
				encerra_revisao(clientes, qtd_cliente, carros, qtd_carro);
				break;
			case 3:
				printf("\nSair...");
				break;
		}//switch case
		printf("\n\n");
		system("pause");
	} while(op!=3);
	
}//main

void aloca_carro(carro **p, int tam){
	if((*p=(carro*)realloc(*p, tam*sizeof(carro)))==NULL)
		exit(1);
}//aloca cliente

void aloca_cliente(cliente **p, int tam){
	if((*p=(cliente*)realloc(*p, tam*sizeof(cliente)))==NULL)
		exit(1);
}//aloca carro

void cadastra_carro(carro *p, int tam){
	int i;
	for(i=0; i<tam; i++, p++){
		system("cls");
		printf("\nMarca: ");
		gets(p->marca);
		fflush(stdin);

		printf("\nModelo:\n[P]equeno\n[M]edio\n[G]rande\nOpcao: ");
		scanf("%c", &(p->modelo));
		fflush(stdin);

		printf("\nValor: ");
		scanf("%f", &(p->valor));
		fflush(stdin);

		p->regcar = i+1;
		p->qcarro = 0;
	}//for
}//cadastra carro

void mostra_carro(carro *p, int tam){
	int i;
	for(i=0; i<tam; i++, p++){
		printf("\nMarca: %s", p->marca);
		printf("\nModelo: %c", p->modelo);
		printf("\nValor: %.2f \n", p->valor);
	}//for
}//mostra carro

void cadastra_cliente(cliente *p, carro *carros, int qtd_carros){
	char marca[20];
	char modelo;
	int i;

	printf("\nCPF do cliente: ");
	gets(p->CPF);
	fflush(stdin);

	printf("\nNome: ");
	gets(p->nome);
	fflush(stdin);

	printf("\nMarca do carro: ");
	gets(marca);
	fflush(stdin);

	printf("\nModelo do carro: ");
	scanf("%c", &modelo);
	fflush(stdin);

	for(i=0; i<qtd_carros; i++, carros++){
		if(strcmp(marca, carros->marca)==0){
			if(modelo == carros->modelo){//alguma coisa dando errado aqui
				printf("\nValor da revisao: %.2f", carros->valor);
			}//if comparacao modelo
		}//if comparacao marca
	}//for
}//cadastra cliente

void encerra_revisao(cliente *p, int qtd_cliente, carro *carros, int qtd_carros){
	char CPF[13];
	int i, j;

	printf("\nInsira o CPF do cliente: ");
	gets(CPF);
	fflush(stdin);

	for(i=0; i<qtd_cliente; i++, p++){
		if(strcmp(CPF, p->CPF)==0){
			printf("\nNome: %s", p->nome);
			printf("\nRegistro carro: %i", p->numcar);

			for(j=0; j<qtd_carros; j++, carros++){
				if(p->numcar == carros->regcar){
					printf("\nMarca: %s", carros->marca);
					printf("\nModelo: %c", carros->modelo);

					carros->qcarro--;
	
				}//if
			}//for carros

			p->numcar = -1;
			
		}//if comparacao CPF
		else{
			printf("\nCPF nao encontrado");
			exit(1);
		}//else - cpf invalido
	}//for aluno
}//encerra matricula




