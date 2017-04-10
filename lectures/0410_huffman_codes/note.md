04/10/2017 - Monday

# Huffman Codes

* **Uniquely Decodable Code** is a variable length code in which bit strings can always be uniquely decomposed into its codewords.
* **Prefix Codes** is a variable length code in which no codeword is a prefix of another word.
	* Can be viewed as a binary tree with symbol values at the leaves and `0` or `1s` on the edges.
* **Average Length**: A code `C` with associated probabilities `p(c)` the _average length_ is defined as: `ACL(C) = \sum{p(c)l(c)}`
	* Prefix code `C` is _optimal_ if for all prefix codes `C'`, `ACL(C) <= ACL(C')`
	* `l(c)`: length of the codeword `c` (a positive integer)
	* If `C` is an optimal prefix code for the probabilities `{p1, ..., pn}` then `pi < pj` implies `l(ci) <= l(cj)`
* **Huffman Codes** properties:
	* Generates optimal prefix codes
	* Cheap to generate codes
	* Cheap to encode and decode

## Huffman Algorithm

* Start with a forest of trees each consisting of a single vertex corresponding to a symbol `s` and with weight `p(s)`
* Repeat:
	* Select two trees with minimum weight roots `p1` and `p2`
	* Join into single tree by adding root with weight `p1 + p2`

### Example

* Breaking Bad
	* B 2
	* r 1
	* e 1
	* a 2
	* k 1
	* i 1
	* n 1
	* g 1
	* _ 1
	* d 1

* 2
	* r
	* e
* 2
	* k
	* i
* 2
	* n
	* g
* 2
	* _
	* d

* 4
	* B
	* .
		* r
		* e
* 4
	* .
		* k
		* i
	* a
* 4
	* .
		* n
		* g
	* .
		* _
		* d

* 8
	* .
		* .
			* k
			* i
		* a
	* .
		* .
			* n
			* g
		* .
			* _
			* d

`...`

* 12
	* .
		* .
			* .
				* n
				* g
			* .
				* _
				* d
		* .
			* .
				* k
				* i
			* a
	* .
		* B
		* .
			* r
			* e

* B 10
* r 110
* e 111
* a 011
* k 0100
* i 0101
* n 0000
* g 0001
* _ 0010
* d 0011

* 1011011101101000101000000010010100110011
