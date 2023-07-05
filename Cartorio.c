#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaçpo na memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca que cuida das strings

int registro()//Função responsável por cadastrar usuários
{
	setlocale(LC_ALL, "Portuguese"); //definição de idioma
	
	printf("Você escolheu a opção para registrar nome.\n\n");
	
	//início da criação de varáves/string	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletar informação do usuário
	scanf("%s", cpf); //%s se refere a string
	
	strcpy(arquivo, cpf); //está copiando o valor da string cpf para arquivo
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo no banco de dados
	fprintf(file, cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ", "); //insere virgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletar informação do usuário
	scanf("%s", nome); //%s se refere a string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo no banco de dados
	fprintf(file, nome); //salva o valor na variável nome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ", "); //insere virgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletar informação do usuário
	scanf("%s", sobrenome); //%s se refere a string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo no banco de dados
	fprintf(file, sobrenome); //salva o valor na variável sobrenome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ", "); //insere virgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletar informação do usuário
	scanf("%s", cargo); //%s se refere a string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo no banco de dados
	fprintf(file, cargo); //salva o valor na variável cargo
	fclose(file); //fecha o arquivo
	
	system("pause"); //pasa o programa aguardando o usuário
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definição de idioma
	
	printf("Você escolheu a opção para consultar nome.\n\n"); 
	
	//início da criação de varáves/string	
	char cpf[40];
	char conteudo[200];
	//final da criação de variáveis/string
	
	printf("Digite o número de CPF a ser consultado: "); //Coletar informação do usuário
	scanf("%s", cpf); //salva o valor na variável cpf
	
	FILE *file; //referencia o arquivo no banco de dados
	file = fopen(cpf, "r"); //lê o arquivo informado pelo usuário no banco de dados
	
	if(file == NULL) //condição se for um valor que não existe
	{
		printf("Não localizado!\n");
	}
	while(fgets(conteudo,200,file) != NULL) //laço para pegar todas as variáveis da string e, assim, trazer todas as informações registradas da consulta
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo); //mostra para o usuário as informações contidas na string conteudo
		printf("\n\n");
	}
	
	system("pause"); //pausa na tela para o usuário ver a informação
}


int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //definição de idioma
	
	printf("Você escolheu a opção para deletar nome.\n\n");
	
	char cpf[40]; //criação de string
	
	printf("Digite o número de CPF a ser deletado: ");
	scanf("%s", cpf); //salva o valor na variável cpf
	
	remove(cpf); //remove cpf
	
	
	FILE *file;
	file = fopen(cpf, "r"); //informa o arquivo a ser lido
	
	if(file==NULL) //se for um valor não encontrado no banco de dados
	{
		printf("`\nUsuário não foi encontrado no sistema!\n\n"); //informa que o usuário não foi encontrado
		system("pause");
	}
	else //se for um valor encontrado no banco de dados
	{
		printf("\nUsuário deletado com sucesso.\n\n"); //informa que apagou o usuário
		system("pause");
	}
}

int main()
{
	int opcao=0; //defnição de variável
	int laco=1; //definição de variável do laço de repetição inicial
	
	for(laco=1;laco=1;) //laço de repetição inicial
	{
		system("cls");
		
		
		setlocale(LC_ALL, "Portuguese"); //definição de idioma
	
		printf("### Cartório da EBAC ###\n\n"); //início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nome\n");
		printf("\t2 - Consultar nome\n");
		printf("\t3 - Deletar nome nome\n");
		printf("\t4 - Sair do sistema\n");
		printf("\nDigite apenas o número: "); //final do menu
	
		scanf("%d", &opcao); //escolha do usuário
	
		system("cls");
		
		switch(opcao) //início da seleção
		{
			case 1:
				registro(); //chamada de função
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
				printf("Essa opção não está disponível!\n\n");
				system("pause");
			break;
		} //final da seleção
	
	}//final do laço de repetição
	printf("\n\nEsse software é de livre uso dos alunos\n");
	
}
