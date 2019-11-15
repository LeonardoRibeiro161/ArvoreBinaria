#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include "arvore.h"


using namespace std;

int main() 
{

	
	int qteNo, num;
	cout<<"Informe quantos nos arvore";
	cin>>qteNo;
	
	PontNo noArvore = criaNo(qteNo);
	
	for(int i = 0; i <= qteNo;i++)
	{
		cout<<"Informe o no:";
		cin>>num;
		InserirNo(num, noArvore);
	}

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
	
		
	cout<<"\nPre Ordem:"<<endl;
	ArvorePreOrdem(noArvore);
	cout<<"\n--------------------------"<<endl;
	cout<<"\nEm Ordem:"<<endl;
	ArvoreEmOrdem(noArvore);
	cout<<"\n--------------------------"<<endl;
	cout<<"\nPos Ordem:"<<endl;
	ArvorePosOrdem(noArvore);
	cout<<"\n--------------------------"<<endl;
}


