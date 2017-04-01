31/03/2017 - Sexta-Feira

# Árvore Rubro-Negra

* **Altura máxima**: `2log(n+1)`
* **Cor (1 bit)**: Vermelho ou preto
* **Pai**: Ponteiro que aponta para o nó pai. O campo pai do nó raíza aponta para nil
* Todo nó da árvore ou é vermelho ou é preto
* A raíz é preta
* Toda folha (nil) é preta
* Se um nó é vermelho, então ambos os filhos são pretos
* Para todo nó, todos os caminhos do nó até as folhas descendentes contêm o mesmo número de nós pretos

## Casos de Inserção

1. **Primeiro nó**: Deve ser preto
1. **Nó com um pai preto**: Insere normalmente
1. **Nó com um pai e um tio vermelho**: Troca a cor do pai, tio e avô
1. **Nó interno com um pai vermelho e tio preto**: Rotaciona a sub-árvore do pai
1. **Nó externo com um pai vermelho e tio preto**: Troca a cor do pai e avô e rotaciona a sub-árvore do avô
