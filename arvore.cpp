#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include "arvore.h"

using namespace std;

typedef int Tipo;

typedef struct no
{
	Tipo num;
	struct no *esquerda;
	struct no *direita;
	
}NoArvore, *PontNo;


//Funcao para achar o valor max
int max(int a, int b)
{
	if(a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

//Funcao para localicar elementos 
PontNo busca(Tipo chave, PontNo raiz)
{
	if(!raiz)
	{
		return NULL;
	}
	else if(raiz->num == chave)
	{
		return raiz;
	}
	else if(raiz->num < chave)
	{
		busca(chave, raiz->direita);
	}
	else
	{
		busca(chave, raiz->esquerda);	
	}
}

// Funcao para criar um No na arvore
PontNo criaNo(Tipo chave)
{
	PontNo novoNo = (PontNo)malloc(sizeof(NoArvore));
	novoNo->esquerda = NULL;
	novoNo->direita = NULL;
	novoNo->num = chave;
	return novoNo;
}

//Funcao para inserir um no na arvore
bool InserirNo(Tipo chave, PontNo no)
{
	PontNo aux;
	while(no != NULL)
	{
		aux = no;
		if(no->num < chave)
		{
			no = no->direita;
		}
		else
		{
			no = no->esquerda;
		}
	}
	no = criaNo(chave);
	if(aux->num < chave)
	{
		aux->direita = no;
	}
	else
	{
		aux->esquerda = no;
	}
	return true;
}

//Funcao de busca no NoRaiz
PontNo buscaRaiz(Tipo chave, PontNo no)
{
	PontNo noPai = no;
	
	while(no != NULL)
	{
		if(no->num == chave)
		{
			return noPai;
		}
		else if(no->num < chave)
		{
			no = no->direita;
		}
		else
		{
			no = no->esquerda;
		}
	}
	return noPai;
}

// Funcao de PreOrdem
void ArvorePreOrdem(PontNo no)
{
	if(no != NULL)
	{
		cout<<no->num<<" ";
		ArvorePreOrdem(no->esquerda);
		ArvorePreOrdem(no->direita);
	}
}

//Funcao para Ordem
void  ArvoreEmOrdem(PontNo no)
{
	if(no != NULL)
	{
		ArvoreEmOrdem(no->esquerda);
		cout<<no->num <<" ";
		ArvoreEmOrdem(no->direita);	
	}	
}

//Funcao em PosOrdem
void ArvorePosOrdem(PontNo no)
{
	if(no != NULL)
	{
		ArvorePosOrdem(no->esquerda);
		ArvorePosOrdem(no->direita);
		cout<<no->num <<" ";
	}
}

PontNo maiorEsq(PontNo no)
{
	no = no->esquerda;
	while(no->direita != NULL)
	{
		no = no->direita;
	}
	return no;
}

bool RemoverNo(Tipo chave, PontNo raiz)
{
	PontNo noAtual, noPai, aux, auxPai;
	aux = NULL;
	noAtual = busca(chave, raiz);
	//N�o encontrou o no 
	if(noAtual == NULL) 
	{
		return false;
	}
	noPai = buscaRaiz(chave, raiz);
	if(noAtual->esquerda == NULL || noAtual->direita == NULL)
	{
		if(noAtual->esquerda == NULL)
		{
			aux = noAtual->direita;
		}
		else
		{
			aux = noAtual->esquerda;
		}
		if(noPai == NULL)
		{
			raiz = aux;
		}
		else
		{
			if(chave < noPai->num)
			{
				noPai->esquerda = aux;
			}
			else
			{
				noPai->direita = aux;
			}	
		}
		free(noAtual); //libera o ponteiro para o noAtual	
		}
		else
		{
			aux = 	maiorEsq(noAtual);
			noAtual->num = aux->num;
			if(aux->esquerda != NULL)
			{
				noAtual->esquerda = aux->esquerda;
			}
			else
			{
				noAtual->esquerda = NULL;
			}
			free(aux);
		}
		return true;
}


