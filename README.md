# Data Structures and Algorithms Lab — Experiments 1–10

C programs based on the first 10 experiments in the provided DSA Lab Manual.

## Experiments
1. Array operations (insertion, deletion, traversal)
2. Dynamic employee records using structures and pointers
3. Infix-to-postfix conversion using a stack
4. Postfix expression evaluation using a stack
5. Simple queue using an array
6. Priority queue using an unordered array (lower number = higher priority)
7. Singly linked list (insert, delete, traverse)
8. Circular queue using a linked list
9. Binary search tree traversals (in-order, pre-order, post-order)
10. Graph traversal using BFS and DFS

## Compile and run
Use GCC from a terminal in this folder:

```sh
gcc -std=c11 -Wall -Wextra -pedantic 01_array_operations.c -o exp01
./exp01
```

For Experiment 4, link the math library on Linux/macOS GCC:
`gcc -std=c11 -Wall -Wextra -pedantic 04_postfix_evaluation.c -o exp04 -lm`

Each program is standalone. Input is read from the terminal. These implementations include basic input validation and memory-allocation checks.
