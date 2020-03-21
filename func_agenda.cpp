#include<stdio.h>
#include<stdlib.h>


typedef struct { //declarando o telefone
char ddd[2];
char numero[10];
int tipo;
}ttelefone;

typedef struct { //declarando o endereço
char logradouro[10];
char numero[10];
char bairro[10];
char cidade[10];
char estado[10];
}tendereco;

typedef struct { //declarado a pessoa completa
int codigo;
char nome[10];
tendereco endereco[3];
ttelefone telefone[2];
}tpessoa;


void inserir_contato(tpessoa *pessoa, int qtd){ //função para inserir nome e codigo

for(int i=0; i<qtd; i++){
printf("----------INSERIR CADASTRO E NOME----------\n");
printf("Insira o codigo: ");
scanf("%d",&pessoa[i].codigo);
printf("\nInsira o nome: ");
fflush(stdin);
gets(pessoa[i].nome);

system("cls");
}

printf("Contato inserido!!!\n\n\n\n");
system("pause");
system("cls");
}
void inserir_endereco(tpessoa *pessoa, int qtd){ //função para inserir endereço

int i,j,escolhe=0,codigo;
   printf("Insira o código da pessoa que deseja colocar o endereco: ");
   scanf("%i",&codigo);
    for(i=0;i<qtd;i++){
    	if(pessoa[i].codigo==codigo){
    		for(j=0;j<3;j++){
	printf("----------INSERIR ENDERECO----------\n");
	printf("\nInsira o logradouro: ");
	fflush(stdin);
	gets(pessoa[i].endereco[j].logradouro);
	printf("\nInsira o numero da residencia: ");
	fflush(stdin);
	gets(pessoa[i].endereco[j].numero);
	printf("\nInsira o bairro: ");
	fflush(stdin);
	gets(pessoa[i].endereco[j].bairro);
	printf("\nInsira a cidade: ");
	fflush(stdin);
	gets(pessoa[i].endereco[j].cidade);
	printf("\nInsira o estado: ");
	fflush(stdin);
	gets(pessoa[i].endereco[j].estado);
	system ("cls");
	printf("Deseja inserir mais um endereco?\n1 - SIM\n2 - NAO\n");
	scanf("%d", &escolhe);
	if(escolhe == 1){
		NULL;
		system("cls");
	}else{
		system("cls");
		break;
	}
}
}
  }
}
void inserir_telefone(tpessoa *pessoa, int qtd){//função para inserir telefone
  
  int i,j,escolhe=0,codigo;
 printf("Insira o código da pessoa que deseja colocar o endereco: ");
   scanf("%i",&codigo);
  for(i=0;i<qtd;i++){
  	if(pessoa[i].codigo==codigo){
  		for(j=0;j<3;j++){
printf("----------INSERIR TELEFONE----------\n");
  printf("\nInsira o DDD: ");
  fflush(stdin);
  scanf("%s",&pessoa[i].telefone[j].ddd);
  printf("\nInsira o numero do telefone: ");
  fflush(stdin);
  gets(pessoa[i].telefone[j].numero);
  printf("\nQual o tipo do telefone? \n\n1-Residencial\n2-Celular");
  fflush(stdin);
  scanf("%i",&pessoa[i].telefone[j].tipo);
  printf("Deseja inserir mais um telefone?\n1 - SIM\n2 - NAO\n");
	scanf("%d", &escolhe);
	if(escolhe == 1){
		NULL;
		system("cls");
	}else{
		system("cls");
		break;
	}
}
}
  }
    system("cls");
}
void mostrartodos(tpessoa pessoa[], int *qtd){//mostra todos contatos
for(int i=0; i<*qtd; i++){
 printf("-------------Mostrando todos da lista---------------------\n");
 printf("Cadastro: %d\n", pessoa[i].codigo);
 printf("Nome: %s\n", pessoa[i].nome);
	for(int j=0; j<3; j++){
  	printf("Logradouro: %s\n",pessoa[i].endereco[j].logradouro);
  	printf("Numero: %s\n",pessoa[i].endereco[j].numero);
  	printf("Bairro: %s\n",pessoa[i].endereco[j].cidade);
  	printf("Estado: %s\n",pessoa[i].endereco[j].estado);
 	}
 		for(int y=0;y<2;y++){
  		printf("DDD: %s\n",pessoa[i].telefone[y].ddd);
  		printf("Numero: %s\n",pessoa[i].telefone[y].numero);
  		printf("Tipo: %i\n",pessoa[i].telefone[y].tipo);
 	}
 	 printf("-------------------------------------------------------\n\n");
 	 system("pause");
  }
  system("cls");
}
void mostrar1(tpessoa pessoa[], int *one){//busca de um contato

int busca=0,j;

printf("Qual cadastro do aluno deseja procurar?\n");
scanf("%d", &busca);
system("cls");

printf("-------------Mostrando o escolhido da lista---------------------\n");
for(int b=0;b<*one;b++){	
 if(pessoa[b].codigo == busca){
 printf("Cadastro: %d\n", pessoa[b].codigo);
 printf("Nome: %s\n", pessoa[b].nome);
 for(j=0; j<3; j++){
  printf("Logradouro: %s\n", pessoa[b].endereco[j].logradouro);
  printf("Numero: %s\n", pessoa[b].endereco[j].numero);
  printf("Bairro: %s\n", pessoa[b].endereco[j].cidade);
  printf("Estado: %s\n", pessoa[b].endereco[j].estado);
 }
 for(j=0;j<2;j++){
  printf("DDD: %s\n", pessoa[b].telefone[j].ddd);
  printf("Numero: %s\n", pessoa[b].telefone[j].numero);
  printf("Tipo: %i\n", pessoa[b].telefone[j].tipo);
 	}
   }
printf("---------------------------------------------------------------\n");
system("pause");
system("cls");
}
}
void bubbleSort(tpessoa pessoa[], int *qtd){//ordenar
	
	int i=0;
	tpessoa help;

	for(int i=0;i<*qtd; i++){
		for(int x = i+1;x<*qtd;x++){
			if(pessoa[i].codigo > pessoa[x].codigo){
				help = pessoa[i];
                pessoa[i] = pessoa[x];
                pessoa[x] = help;
			}
		}
	}
		system("cls");
		printf("Organizado!\n");
		system("pause");
}
int escrever_ar(tpessoa pessoa[], int qtd){
	int i;
	FILE *arq;

	arq = fopen("dados.bin", "ab+");
	
	fseek(arq,0, SEEK_END);

	if(arq != NULL){
		for(i = 0; i < qtd ; i++)
		fwrite(&pessoa[i], sizeof(tpessoa), 1, arq);
		fclose(arq);
	}
	else
	{
		printf("\nErro ao abrir o arquivo para leitura!\n");
		exit(0);
	}
	system("cls");
	printf("Arquivo Gravado\n\n");
	system("pause");
}
int ler_arq(tpessoa pessoa[], int qtd){
			// abre o arquivo para leitura
	FILE * arq = fopen("dados.bin", "rb");
	tpessoa p;
	int indice = 0;
	
	fread(&p, sizeof(tpessoa), 1, arq);
	
	do {
		
        pessoa[indice] = p;;
        fread(&p, sizeof(tpessoa), 1, arq);
        indice++;
    } while (!feof(arq));

    fclose(arq);
    
    return indice;
}
