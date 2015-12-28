== Genetic VM

=== Goal
Creation of a VM with a defined bytecode that can be manipulated in a manner similar to genes, for use in a genetic algorithm for solving a given problem. The bytecode represents the genome and the running program represents the phenotype.

=== Execution Pipeline

Unknown problem -> set of inputs
The set of inputs is supplied to the VM, and random bytecode is generated to mimic the random emergence of DNA sequences

Fitness factor -> set of expected outputs
For a given set of inputs, calculate the root mean squared error of the outputs, select for minimization

Sort candidates -> Selection and Breeding
For set of candidate functions, produce new population using crossover, mutation and replication

=== Requirements
* Standardize instruction set
* Clean up code
* Move SP and IP to being selectable registers within the program to allow further manipulation
* Write Root-Mean-Squared-Error function for 
