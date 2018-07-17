#include<stdio.h>

void tela(){//menu

system("cls");

printf("\t\t\tSISTEMA DE PESSOAS\n");

printf("1-adicionar pessoas\n");//

printf("2-listar todas as pessoas \n");

printf("3-alterar pessoas\n");

printf("4-excluir pessoas\n");

printf("0-sair\n");

printf("digite a opçao:\n");

}

void tela();//montar tela

main(){

FILE *arq;

char conteudo[80];

int i=-1,x,op=1,id;

struct sistem{

int codigo[80];

char nome[40];

int valor;

};

struct sistem pessoa[2];

arq=fopen("pessoas.txt","a");//abri ou criar

while(op!=0){

tela();//mostrar a tela

scanf("%d",&op);//ler a op

if(op==1){// adicionar pessoa

system("cls");//limpar tela

arq=fopen("pessoas.txt","a");

printf("\t\tINCLUIR PESSOA \n");

if(arq==NULL){// erro

printf("ERRO ao abrir o arquivo");

}else if(i<9){//entra -1 a 8.

i=i+1;//0,1,2,3,4,5,6,7,8,9.

printf("digite o nome da pessoa:%d",i);

scanf("%s",&pessoa[i].nome);//variavel struct nome de 0 a 9

printf("digite a codigo");

scanf("%d",&pessoa[i].codigo);//variavel struct idade

printf("digite a valor");

scanf("%d",&pessoa[i].valor);

fprintf(arq,"%d,%s,%d,%d\n",i,pessoa[i].nome,pessoa[i].codigo,pessoa[i].valor);// salvar no arquivo

fclose(arq);//fechar arquivo

}else{

printf("limite excedido\n");

}

printf("\ntecle entrer para voltar ao menu anterior\n");

getch();//voltar a tela inicial

}

if(op==2){//listar os pessoas

system("cls");

printf("\t\t lista completa\n ");

arq=fopen("pessoas.txt","r");//apenas leitura

if(arq==NULL){// erro no arquivo

printf("ERRO ao abrir o arquivo");

}else{

printf("\t\tarquivo\n");

while(fgets(conteudo,80,arq)!=NULL){//mostrar texto de arquivo

printf("%s\n",&conteudo);//escrever o arquivo

}//fim while

}

printf("\ntecle entrer para voltar ao menu anterior\n");

getch();//voltar ao menu

}

if(op==3){//alterar pessoa

system("cls");

arq=fopen("pessoas.txt","w");//apenas leitura

printf("\n\t\tpesquisar ID\n");

printf("\ndigite o id da pessoa desejada:\n");

scanf("%d",&id);

if(arq==NULL){// erro no arquivo

printf("ERRO ao abrir o arquivo");

}else if(id >= 0 && id <= 8){

if(id <= i){

printf("\nPessoa a ser alterada\n");

printf("\n%s \n%d\n%d\n",pessoa[id].nome,pessoa[id].codigo,pessoa[i].valor);//nome atual

printf("digite o nome da pessoa:%d",i);

scanf("%s",&pessoa[i].nome);//variavel struct nome

printf("digite a codigo");

scanf("%d",&pessoa[i].codigo);//variavel struct

printf("digite a valor");

scanf("%d",&pessoa[i].valor);

}else{

printf("\nID nao cadastrado");//id não cadastrado

}

}else{

printf("\nInvalido -ID nao existe");//id não existe

}

printf("\ntecle entrer para voltar ao menu anterior\n");

getch();//voltar ao menu

}//op3

if(op==4){

arq=fopen("pessoas.txt","w");//excluir conteudo

fclose(arq);//fechar arquivo

printf("conteudo excluido");

printf("\ntecle entrer para voltar ao menu anterior\n");

getch();//voltar a tela inicial

}//fim op4

}//fim while

}
