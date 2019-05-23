# Final Assignment

In this assignment I gathered all the previous assignments into one file and compiled it with one step using CMake.

## The Assignment Contains :

Assignment | Week
---------- | -----
Basics | week 1
Memory | week 2
Arrays | week 3, 4
LL, Stack, Queue | week 5
BST, Set, Map | week 7
Heap | week 8
Hash Table | week 9
Sorting | week 10
OOP Struct | STL

## How to Compile :
* I used CMake to make the compiling easier and less time consuming.
1. create a ```build``` folder and open it.
2. open the terminal.
3. write  ```cmake ..```
4. write  ```make ```

## How to Run :

Executable | Summary | How to Run
---------- | ------ | ----------
basic | Does some basic operations |  ```./basic```
memory | Does some simple operations using pointers and heap memory | ```./memory```
calc | Works as a calculator | ```./calc "first number" "operation" "second number"```
heron | Calculates the area of a triangle by its three lengths | ```./heron "the three lengths of triangle"```
ecg | Analyzes ECG data | ```./ecg ../data/ecg_data.txt```
dna1 | Analyzes DNA data | ```./dna1 ../data/hepatitis_c_virus_genome.txt```
area | Calculates the area of any shape |```./area "shape" "parameters of the shape"``` 
euclidean | Calculates the length between any two points | ```./euclidean "x-coordinate of p1" "y-coordinate of p1" "x-coordinate of p2" "y-coordinate of p2"``` 
point | Determines whether or not a point is inside a certain shape |  ```./area "shape"``` 
dna2 | Analyzes DNA data using OOP | ```./dna2 ../data/hepatitis_c_virus_genome.txt```
comp_dna | Transform DNA data to its complementary DNA data | ```./comp_dna ../data/hiv1_envelope_gene.fasta```
trans_dna | Translates DNA data to its corresponding protien data | ```./trans_dna ../data/hiv1_envelope_gene.fasta```
tree | Tests how trees work | ```./tree```
uniquewords | Uses a set to determine unique words in a data file | ```./uniquewords ../data/carl_sagan.txt```
countdna | Uses a map to count DNA data | ```./countdna ../data/genetic_data.txt```
countwords | Uses a map to count words in a data file | ```./countwords ../data/carl_sagan.txt```
heap | Tests how heaps work | ```./heap```
hash | Uses a hash table to count DNA data | ```./hash ../data/genetic_data.txt```
merge | Sorting a bunch of numbers using merge sort | ```./merge```
quick | Sorting a bunch of numbers using quick sort | ```./quick```
insertion | Sorting a bunch of numbers using insertion sort | ```./insertion```
