03/10/2017 - Friday

# Searching Algorithms

## Interpolation Search

* Keys must be uniformly distributed
* Complexity: `O(log(log(n)))`
* Disadvantages: Keys commonly are not uniformly distributed

## Tree Search

* Pre-ordinary: print -> search(l) -> search(r) [left]
* In-ordinary: search(l) -> print -> search(r) [below]
* Pos-ordinary: search(l) -> search(r) -> print [right]

# Ordenation Algorithms

## Selection Sort

* Swap the lesser value with the first position
* Swap the second lesser value with the second position
* Swap the `n` lesser value with the `n` position
* Complexity: `O(n²)`

```Java
public static void selectionSort(int[] v) {
	int index_min;
	int aux;

	for(int i = 0; i < v.length; i++) {
		index_min = i;
		for (int j = i + 1; j < v.length; j++) {
			if(v[j] < v[index_min]) {
				index_min = j;
			}
		}
		if(index_min != 1) {
			aux = v[index_min];
			v[index_min] = v[i];
			v[i] = aux;
		}
	}
}
```

## Insertion Sort

* Complexity: `O(n²)`
* The best `O(n)` algorithm if the array is already ordened
* The ordenation is stable

```C
void insertionSort(int v[], int tam)
{
	int i, j, aux;
	
	for(i = 1; i < tam; i++)
	{
		j = 1;
		while((j!=0) && (v[j] < v[j-1]))
		{
			aux = v[j];
			v[j] = v[j-1];
			v[j-1] = aux;
			j--;
		}
	}
}
```

## Bubble Sort

* Compare the next value with the current value, if the next value is lesser, swap.
* The last value will be the bigger value and can be disconsidered in the next array iteration.
* Do it until no changes were made after comparing the array

```Portugol
procedimento bubble_sort(ve)
{
	inteiro i, n;
	Vetor v = ve;
	booleano troca;
	faça
	{
		troca = falso;
		para(i = 0; i <= n-2; i++)
		{
			se(v[i] > v[i+1])
			{
				troca = verdadeiro;
				inteiro aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
			}
		}
		n--;
	} enquanto (troca == verdadeiro)
}
```
