//Limitações:
//Não pega o pivo no inicio da lista, pega no final.
//Swap não faz com endereço faz com o valor.
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int chave;
	struct node *prox;
	struct node *ante;
}node;

typedef struct cabecalho{
	struct node *inicio;
	struct node *fim;
	int quantidade;
}cabecalho;

int main(){

	void cadastraFinal(cabecalho *cabecalho);
	void imprimeListaNormal(cabecalho *cabecalho);
	cabecalho *iniciaCabecalho();

	void quickSort(struct node* l, struct node *h, struct cabecalho * cabecalho);
	node *particao(node *l, node *h,struct cabecalho *cabecalho);

	cabecalho *cabecalho = iniciaCabecalho();

	int opcao;
	do{
			printf("\nmenu Cabecalho = %d\n", cabecalho->quantidade);
			printf("\n1- Cadastrar no fim");
			printf("\n2- Ver normal");
			printf("\n3- Sair");
			scanf("%d",&opcao);
			switch(opcao){
				case 1:{
					cadastraFinal(cabecalho);
					break;
				}
				case 2:{
					imprimeListaNormal(cabecalho);
					quickSort(cabecalho->inicio,cabecalho->fim, cabecalho);
					printf("\nOrdenada:");
					imprimeListaNormal(cabecalho);
				}
			}
	}while(opcao != 3);

	return 0;
}

cabecalho *iniciaCabecalho(){
	cabecalho *cabecalho;
	cabecalho = malloc(sizeof(cabecalho));
	cabecalho->inicio = NULL;
	cabecalho->fim = NULL;
	cabecalho->quantidade = 0;

	return cabecalho;
}


void swap ( node *a, node *b, struct cabecalho *cabecalho )
{/*
		if(a == cabecalho->inicio){
			cabecalho->inicio = b;
		}
		if(b == cabecalho->inicio){
			cabecalho->inicio = a;
		}
		node *aAnte = a->ante;
	  node *bAnte = b->ante;
		node *aProx = a->prox;
		node *bProx = b->prox;
		if(aAnte != NULL){
			aAnte->prox = b;
		}
		if(bAnte != NULL){
			bAnte->prox = a;
		}
		if(aProx != NULL){
			aProx->ante = b;
		}
		if(bProx != NULL){
			bProx->ante = a;
		}
		a->prox = bProx;
		a->ante = bAnte;
		b->prox = aProx;
		b->ante = aAnte;*/

		int t = a->chave;      a->chave = b->chave;       b->chave = t;
}

node* particao(node *l, node *h,struct cabecalho *cabecalho){
  int valor  = h->chave;
  node *i = l->ante;
	node *aux = NULL;
	node *j;

  for ( j = l; j != h; j = j->prox)
  {
    if (j->chave <= valor)
    {
        if(i == NULL){
					i = l;
				}else{
					i = i->prox;
				}
        swap(i, j, cabecalho);
    }
  }

	if(i == NULL){
		i = l;
	}else{
		i = i->prox;
	}
  swap(i, h, cabecalho);

	return i;
}

void quickSort(struct node* l, struct node *h, struct cabecalho * cabecalho)
{
    if (h != NULL && l != h && l != h->prox)
    {
        struct node *p = particao(l, h, cabecalho);
        quickSort(l, p->ante, cabecalho);
        quickSort(p->prox, h, cabecalho);
    }
}

void cadastraFinal(cabecalho *cabecalho){
	node *aux;

	int chave;
	aux = (node *) malloc(sizeof(node));

	printf("\nDigite a chave");
	scanf("%d",&chave);
	aux->chave = chave;
	if(cabecalho->quantidade == 0){
		cabecalho->inicio = aux;
		cabecalho->fim = aux;
		aux->prox = NULL;
		aux->ante = NULL;
		cabecalho->quantidade++;
	}
	else{
		aux->ante = cabecalho->fim;
		cabecalho->fim->prox = aux;
		cabecalho->fim = aux;
		cabecalho->fim->prox= NULL;
		cabecalho->quantidade++;
	}
}

void imprimeListaNormal(cabecalho *cabecalho){
	node *aux= cabecalho->inicio;

	while(aux != NULL){
		printf("\n Chave: %d", aux->chave);
		aux = aux->prox;
	}
}
