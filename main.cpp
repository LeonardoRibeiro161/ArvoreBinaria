#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include "arvore.h"
#include <windows.h>
using namespace std;

int main() 
{	
	int qteNo, num, opcao, raiz,noExcluir,resp;
	FILE *p_arq;
	char diretorio[50]  = "C:\\Users\\Leonardo\\Desktop\\numeros.txt";
	int conteudo[10];
	int i;
		
	cout<<"-------------------------------------------"<<endl;
	cout<<"            Arvore Binaria em C"<<endl;
	cout<<"-------------------------------------------"<<endl;
	
	cout<<"Informe o no raiz:";
	cin>>raiz;
	PontNo noArvore = criaNo(raiz);
	
	//Menu Principal
	do
	{	
		cout<<"[1] - Criar arvore binaria"<<endl;
		cout<<"[2] - Inserir elementos na arvore"<<endl;
		cout<<"[3] - Remover elemento"<<endl;
		cout<<"[4] - Inserir elemento por arquivo"<<endl;
		cout<<"[5] - Buscar um elemento"<<endl;
		cout<<"[6] - Visualizar Pre Ordem/Em Ordem/Pos Ordem da arvore"<<endl;
		cout<<"[7] - Sair"<<endl;
		cout<<"--> Opcao:";
		cin>>opcao;
		switch(opcao)
		{
			//Criar arvore informando a quantidade de elementos
			case 1:
				{
					system("cls");
					
					cout<<"Informe a quantidade de no:";
					cin>>qteNo;
			
					cout<<"Arvore criada com sucesso com "<<qteNo<<" nos. Pressione Enter"<<endl;
					system("pause>>NULL");
					break;
				}
			//Inserir elementos na arvore
			case 2:
				{		
					system("cls");
					for(int i = 0; i < qteNo;i++)
					{
						cout<<"Informe o "<<i<<" no:";
						cin>>num;
						InserirNo(num, noArvore);
					}
					cout<<"Nos inseridos com sucesso, pressione Enter"<<endl;
					system("pause>>NULL");
					break;
				}
			//Remover um elemento na arvore
			case 3:
				{
					system("cls");
					cout<<"Informe o no a ser excluir:";
					cin>>noExcluir;
					RemoverNo(noExcluir, noArvore);
					cout<<"Elemento removido com sucesso, pressione Enter"<<endl;
					system("pause>>NULL");
					break;
				}
			//Inserir nos da arvore por arquivo
			case 4:
				{
					system("cls");
					p_arq = fopen(diretorio, "rb");
					if(p_arq != NULL)
					{
						
						while(!feof(p_arq))
						{
							if(fscanf(p_arq, "%d", &conteudo[i]))
							{
								InserirNo(conteudo[i],noArvore);
							}
							i++;
							
						}
						cout<<"Nos inseridos com sucesso, pressione Enter"<<endl;	
					}
					else
					{
						cout<<"Erro ao abrir o  arquivo no diretorio "<<endl;
					}
					system("pause>>NULL");
					break;
				}
			//Buscar elemento na arvore
			case 5:
				{
					system("cls");
					cout<<"Informe o valor que deseja buscar:";
					cin>>num;
					if(busca(num,noArvore))
					{
						cout<<"O numero "<<num<<"  foi encontrado na arvore";
					}
					else
					{
						cout<<"O numero "<<num<<" nao foi encontrado na arvore";
					}
					
					system("pause>>NULL");
					break;
				}
			//Ordenamento da arvore em Pre Ordem, Em Ordem e Pos ordem
			case 6:
				{	
					system("cls");
					cout<<"\nPre Ordem:"<<endl;
					ArvorePreOrdem(noArvore);
					cout<<"\n--------------------------"<<endl;
					cout<<"\nEm Ordem:"<<endl;
					ArvoreEmOrdem(noArvore);
					cout<<"\n--------------------------"<<endl;
					cout<<"\nPos Ordem:"<<endl;
					ArvorePosOrdem(noArvore);
					cout<<"\n--------------------------"<<endl;
					system("pause>>NULL");
					break;
				}
			//Finalizar programa
			case 7:
				{
					cout<<"Para finalizar o programa, pressione qualquer tecla.\n";
					system("pause>>NULL");
					break;
					exit(1);
				}
				
			default:
					cout<<"Opcao incorreta \n";
		}
		Sleep(1000);
		system("cls");		
	}
	while(opcao);
}


