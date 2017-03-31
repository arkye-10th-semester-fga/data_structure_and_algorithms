27/03/2017 - Segunda-Feira

# Árvores AVL (Balanceadas)

* A altura de uma árvore binária é o nível máximo de suas folhas (profundidade)
* Uma árvore binária balanceada (AVL) é uma árvore binária na qual as alturas das duas subárvores de todo nó nunca difere em mais de 1
* O balanceamento de um NÓ é definido como a altura da sua subárvore esquerda menos a altura de sua subárvore direita
* Cada nó numa árvore binária balanceada (AVL) tem balanceamento 1, -1 ou 0
* Se o valor do balanceamento do nó for diferente de 1, -1, e 0. Essa árvore não é balanceada (AVL)
* **Exemplo**:
	* -1
		* 1
			* 0
				* 0
				* 0
			* 0
		* 0
			* 1
				* 0
					* 0
					* 0
				* 0
			* -1
				* 0
				* 0
					* 0
					* 0
* **Duas Informações**: Fator de balanceamento e Altura
* Se a probabilidade de pesquisar um dado for a mesma para todos os dados, uma árvore binária balanceada determinará a busca mais eficiente
* Mas os algoritmos de inserção e remoção já vistos até agora não garantem que essa árvore permancerá balanceada
* **Exemplo**:
	* -1
		* 1
			* 0
				* 0
					* U1
					* U2
				* 0
					* U3
					* U4
			* 0
				* B
				* B
		* 0
			* 1
				* 0
					* 0
						* U5
						* U6
					* 0
						* U7
						* U8
				* 0
					* B
					* B
			* -1
				* 0
					* B
					* B
				* 0
					* 0
						* U9
						* U10
					* 0
						* U11
						* U12
* O desbalanceamento ocorre quando:
	* O NÓ inserido é um descendente esquerdo de um nó que tinha balanceamento de 1
	* O NÓ inserido é um descendente direito de um nó que tinha balanceamento -1
* Para manter uma árvore balanceada, é necessário fazer uma transformação na árvore tal que:
	* O percurso em ordem da árvore transformada seja o mesmo da árvore (isto é, a árvore transformada continue sendo uma árvore de busca binária)
	* A árvore transformada fique balanceada
* **Exemplo**:
	* A
		* B _(-2)_
			* D
				* H
					* **R** (Desbalanceou)
				* I
			* E
		* C
			* F
				* J
					* N
					* O
				* K
			* G
				* L
				* M
					* P
					* Q
* **Solução**: Rotação DIREITA
	* A
		* B
			* **D**
				* H
					* **R**
				* I
			* E
		* C
			* F
				* J
					* N
					* O
				* K
			* G
				* L
				* M
					* P
					* Q
* **Solução**: D passa a ser raíz da sub-árvore da esquerda
	* A
		* D
			* H
				* R
			* B
				* I
				* E
		* C
			* F
				* J
					* N
					* O
				* K
			* G
				* L
				* M
					* P
					* Q
* **Exemplo**:
	* A
		* B
			* D
				* H
				* I
			* E
		* C
			* F _(2)_
				* J
					* N
						* **R** (Desbalanceou)
					* O
				* K
			* G
				* L
				* M
					* P
					* Q
* **Solução**: Rotação ESQUERDA
	* A
		* B
			* D
				* H
				* I
			* E
		* C
			* F
				* J
					* N
						* **R** (Desbalanceou)
					* O
				* **K**
			* G
				* L
				* M
					* P
					* Q
* **Solução?**: K passa a ser raíz da sub-árvore de raíz F
	* A
		* B
			* D
				* H
				* I
			* E
		* C
			* K
				* F
					* J
					* N
						* **R** (Desbalanceou)
				* O
			* G
				* L
				* M
					* P
					* Q
* Rotação simples funciona apenas para galhos externos
* **Solução**: Rotação DUPLA (N passa a ser raíz da sub-árvore de K, DIREITA)
	* A
		* B
			* D
				* H
				* I
			* E
		* C
			* F _(2)_
				* **N**
					* R
					* K
						* **O** (Desbalanceou)
			* G
				* L
				* M
					* P
					* Q
* **Solução**: Rotação DUPLA (N passa a ser raíz da sub-árvore de F, ESQUERDA)
	* A
		* B
			* D
				* H
				* I
			* E
		* C
			* N
				* F
					* J
					* R
				* K
					* O
			* G
				* L
				* M
					* P
					* Q
* **Sinais iguais**: Rotação simples
	* **Exemplo 1**: -2, -1 (DIREITA)
* **Sinais distintos**: Rotação dupla
	* **Exemplo 2**: -2, +1 (DIREITA-ESQUERDA)

```C
void rot_dir(NODEPTR p)
{
	NODEPTR, q, temp;
	q = p->esq;
	temp = q->dir;
	q->dir = p;
	p->esq = temp;
	p = q;
}
```

```C
void rot_esq(NODEPTR p)
{
	NODEPTR, q, temp;
	q = p->dir;
	temp = q->esq;
	q->esq = p;
	p->dir = temp;
	p = q;
}
```

```C
void rot_esq_dir(NODEPTR p)
{
	rot_esq(p->esq);
	rot_dir(p);
}
```

```C
void rot_dir_esq(NODEPTR p)
{
	rot_dir(p->dir);
	rot_esq(p);
}
```

* **A.B.B.**
	* **Médio**:
		* **Busca**: `O(log(n))`
		* **Inserção**: `O(log(n))`
		* **Remoção**: `O(log(n))`
	* **Pior**: `O(n)`
* **AVL**
	* **Médio/Pior**:
		* **Busca**: `O(log(n))`
		* **Inserção**: `O(log(n))`
		* **Remoção**: `O(log(n))`
