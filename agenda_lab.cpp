#include<stdio.h>
#include<stdlib.h>
#include"func_agenda.cpp"

int main(){

int op_menu = 0, tamanho_ag=0, loop =2;

tpessoa vet_contato[tamanho_ag];

printf("Qual sera a quantidade de contatos?\n");
scanf("%d",&tamanho_ag);

system("cls");

while(true){
printf("------------------MENU------------------\n");
printf("\n1 - Incluir pessoa");
printf("\n2 - Incluir endereco");
printf("\n3 - Incluir telefone");
printf("\n4 - Mostrar todos da lista");
printf("\n5 - Mostrar contato escolhido");
printf("\n6 - Organizar");
printf("\n7 - Salvar em arquivo");
printf("\n8 - Le arquivo");
printf("\n9 - Mostrar salvo\n");
scanf("%d",&op_menu);
 switch(op_menu)
{

case 1:
	system("cls");
 	inserir_contato(vet_contato,tamanho_ag);
 	break;
case 2:
	system("cls");
 	inserir_endereco(vet_contato,tamanho_ag);
 	break;
case 3:
	system("cls");
 	inserir_telefone(vet_contato,tamanho_ag);
 	break;
case 4:
	system("cls");
 	mostrartodos(vet_contato,&tamanho_ag);
 	break;
case 5:
	system("cls");
 	mostrar1(vet_contato,&tamanho_ag);
 	break;
case 6:
	system("cls");
	bubbleSort(vet_contato,&tamanho_ag);
	break;
case 7:
	system("cls");
	escrever_ar(vet_contato,tamanho_ag);
	break;
case 8:
	system("cls");
	int o;
	tpessoa vet_contato0[10];
	o=ler_arq(vet_contato0,tamanho_ag);
	break;
case 9:
	system("cls");
	mostrartodos(vet_contato0,&o);
	break;
default:
	system("cls");
	printf("Opcao nao existe");
	return 0;
	break;
}
}
}
