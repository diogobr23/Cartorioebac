#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�po na mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca que cuida das strings

int registro()//Fun��o respons�vel por cadastrar usu�rios
{
	setlocale(LC_ALL, "Portuguese"); //defini��o de idioma
	
	printf("Voc� escolheu a op��o para registrar nome.\n\n");
	
	//in�cio da cria��o de var�ves/string	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletar informa��o do usu�rio
	scanf("%s", cpf); //%s se refere a string
	
	strcpy(arquivo, cpf); //est� copiando o valor da string cpf para arquivo
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo no banco de dados
	fprintf(file, cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ", "); //insere virgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletar informa��o do usu�rio
	scanf("%s", nome); //%s se refere a string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo no banco de dados
	fprintf(file, nome); //salva o valor na vari�vel nome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ", "); //insere virgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletar informa��o do usu�rio
	scanf("%s", sobrenome); //%s se refere a string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo no banco de dados
	fprintf(file, sobrenome); //salva o valor na vari�vel sobrenome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ", "); //insere virgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletar informa��o do usu�rio
	scanf("%s", cargo); //%s se refere a string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo no banco de dados
	fprintf(file, cargo); //salva o valor na vari�vel cargo
	fclose(file); //fecha o arquivo
	
	system("pause"); //pasa o programa aguardando o usu�rio
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //defini��o de idioma
	
	printf("Voc� escolheu a op��o para consultar nome.\n\n"); 
	
	//in�cio da cria��o de var�ves/string	
	char cpf[40];
	char conteudo[200];
	//final da cria��o de vari�veis/string
	
	printf("Digite o n�mero de CPF a ser consultado: "); //Coletar informa��o do usu�rio
	scanf("%s", cpf); //salva o valor na vari�vel cpf
	
	FILE *file; //referencia o arquivo no banco de dados
	file = fopen(cpf, "r"); //l� o arquivo informado pelo usu�rio no banco de dados
	
	if(file == NULL) //condi��o se for um valor que n�o existe
	{
		printf("N�o localizado!\n");
	}
	while(fgets(conteudo,200,file) != NULL) //la�o para pegar todas as vari�veis da string e, assim, trazer todas as informa��es registradas da consulta
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); //mostra para o usu�rio as informa��es contidas na string conteudo
		printf("\n\n");
	}
	
	system("pause"); //pausa na tela para o usu�rio ver a informa��o
}


int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //defini��o de idioma
	
	printf("Voc� escolheu a op��o para deletar nome.\n\n");
	
	char cpf[40]; //cria��o de string
	
	printf("Digite o n�mero de CPF a ser deletado: ");
	scanf("%s", cpf); //salva o valor na vari�vel cpf
	
	remove(cpf); //remove cpf
	
	
	FILE *file;
	file = fopen(cpf, "r"); //informa o arquivo a ser lido
	
	if(file==NULL) //se for um valor n�o encontrado no banco de dados
	{
		printf("`\nUsu�rio n�o foi encontrado no sistema!\n\n"); //informa que o usu�rio n�o foi encontrado
		system("pause");
	}
	else //se for um valor encontrado no banco de dados
	{
		printf("\nUsu�rio deletado com sucesso.\n\n"); //informa que apagou o usu�rio
		system("pause");
	}
}

int main()
{
	int opcao=0; //defni��o de vari�vel
	int laco=1; //defini��o de vari�vel do la�o de repeti��o inicial
	
	for(laco=1;laco=1;) //la�o de repeti��o inicial
	{
		system("cls");
		
		
		setlocale(LC_ALL, "Portuguese"); //defini��o de idioma
	
		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nome\n");
		printf("\t2 - Consultar nome\n");
		printf("\t3 - Deletar nome nome\n");
		printf("\t4 - Sair do sistema\n");
		printf("\nDigite apenas o n�mero: "); //final do menu
	
		scanf("%d", &opcao); //escolha do usu�rio
	
		system("cls");
		
		switch(opcao) //in�cio da sele��o
		{
			case 1:
				registro(); //chamada de fun��o
			break;
			case 2:
				consulta();
			break;
			case 3:
				deletar();
			break;
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
			break;
						
			default:
				printf("Essa op��o n�o est� dispon�vel!\n\n");
				system("pause");
			break;
		} //final da sele��o
	
	}//final do la�o de repeti��o
	printf("\n\nEsse software � de livre uso dos alunos\n");
	
}
