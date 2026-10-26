# DSA Basics

Implementations of fundamental data structures and algorithms in C++, written from scratch, together with a small set of classic problems for each structure.

The goal of this repository is to show a working understanding of the basics: how each structure is built, what its operations cost, and how it is used to solve well-known problems. It is not a collection of competitive programming solutions.

## Contents

| Topic | What is covered |
|---|---|
| [Arrays](Arrays/) | basic operations, searching and hashing, sorting, classic problems |
| [LinkedList](LinkedList/) | singly, doubly and circular lists, classic problems |
| [Stack](Stack/) | array and linked implementations, classic problems |
| [Queue](Queue/) | linear, circular, priority, deque and linked queues, classic problems |
| [Recursion](Recursion/) | factorial, Fibonacci, sum of natural numbers, Tower of Hanoi |
| [Trees](Trees/) | BST, AVL tree, min-heap, classic problems |
| [Graph](Graph/) | adjacency list and matrix, shortest paths, minimum spanning trees |

## How to compile and run

Every file is self-contained and has its own `main()` with a small demo.

```
g++ -std=c++17 Arrays/FamousProblems/twoSum.cpp -o out
./out
```

On Windows, run `out.exe` instead of `./out`.

## Repository structure

```
DSA_Basics/
├── Arrays/
│   ├── Arrays_Basics/
│   ├── ArraySearch/          searching and hash tables (collision handling)
│   ├── SortingAlgo/
│   └── FamousProblems/
├── LinkedList/
│   ├── Implementations/
│   └── FamousProblems/
├── Stack/
│   ├── Implementations/
│   └── FamousProblems/
├── Queue/
│   ├── Implementations/
│   └── FamousProblems/
├── Recursion/
├── Trees/
│   ├── Implementations/
│   └── FamousProblems/
└── Graph/
    └── Implementations/
```

## Implementations

**Arrays**
- Basic operations: [array.cpp](Arrays/Arrays_Basics/array.cpp)
- Searching: [search.cpp](Arrays/ArraySearch/search.cpp)
- Hash tables: [chaining](Arrays/ArraySearch/chaining.cpp), [linear probing](Arrays/ArraySearch/linearProbing.cpp), [quadratic probing](Arrays/ArraySearch/quadProbing.cpp), [double hashing](Arrays/ArraySearch/doubleHashing.cpp)
- Sorting: [bubble](Arrays/SortingAlgo/bubbleSort.cpp), [selection](Arrays/SortingAlgo/selectionSort.cpp), [insertion](Arrays/SortingAlgo/insertionSort.cpp), [merge](Arrays/SortingAlgo/mergeSort.cpp), [radix](Arrays/SortingAlgo/radixSort.cpp)

**Linked lists**
- [Singly](LinkedList/Implementations/singlyLinkedList.cpp), [doubly](LinkedList/Implementations/doublyLinkedList.cpp), [circular](LinkedList/Implementations/circularLInkedList.cpp), [circular doubly](LinkedList/Implementations/CDlinkedlist.cpp)

**Stack**
- [Array-based](Stack/Implementations/stackArray.cpp), [linked-list-based](Stack/Implementations/LinkedStack.cpp)

**Queue**
- [Linear](Queue/Implementations/linearQueue.cpp), [circular](Queue/Implementations/circularQueue.cpp), [priority](Queue/Implementations/priorityQueue.cpp), [deque](Queue/Implementations/deque.cpp), [linked](Queue/Implementations/linkedQueue.cpp)

**Trees**
- [Binary search tree](Trees/Implementations/binarySearchTree.cpp), [AVL tree](Trees/Implementations/selfBalancedAVL.cpp), [min-heap](Trees/Implementations/minHeap.cpp)

**Graph**
- Representations: [adjacency list](Graph/Implementations/graphAdjList.cpp), [adjacency matrix](Graph/Implementations/graphAdjMat.cpp)
- Shortest paths: [Dijkstra](Graph/Implementations/dijkstra.cpp), [Floyd-Warshall](Graph/Implementations/FloydWarshall.cpp)
- Minimum spanning tree: [Prim](Graph/Implementations/prim.cpp), [Kruskal](Graph/Implementations/kruskal.cpp)

## Problems

Time and space refer to the optimal approach in each file. Most files also include a brute force version for comparison, with both approaches described in the header comment.

| Problem | Technique | Time | Space | Code |
|---|---|---|---|---|
| Two Sum | hash map | O(n) | O(n) | [twoSum.cpp](Arrays/FamousProblems/twoSum.cpp) |
| Maximum Subarray | Kadane's algorithm | O(n) | O(1) | [maxSubArray.cpp](Arrays/FamousProblems/maxSubArray.cpp) |
| Sort 0s, 1s and 2s | Dutch national flag (three pointers) | O(n) | O(1) | [dutchFlag.cpp](Arrays/FamousProblems/dutchFlag.cpp) |
| Reverse a linked list | pointer reversal | O(n) | O(1) | [LinkedListReversal.cpp](LinkedList/FamousProblems/LinkedListReversal.cpp) |
| Detect a cycle | slow and fast pointers | O(n) | O(1) | [cycleDetect.cpp](LinkedList/FamousProblems/cycleDetect.cpp) |
| Middle of a linked list | slow and fast pointers | O(n) | O(1) | [middlePart.cpp](LinkedList/FamousProblems/middlePart.cpp) |
| Reorder list | middle, reverse, merge | O(n) | O(1) | [reorderList.cpp](LinkedList/FamousProblems/reorderList.cpp) |
| Polynomial addition | linked list of terms | O(n+m) | O(n+m) | [sumOfPol.cpp](LinkedList/FamousProblems/sumOfPol.cpp) |
| Polynomial multiplication | linked list of terms | O(nm^2) | O(n*m) | [mulOfPol.cpp](LinkedList/FamousProblems/mulOfPol.cpp) |
| Balanced parentheses | stack | O(n) | O(n) | [balanceParenthesis.cpp](Stack/FamousProblems/balanceParenthesis.cpp) |
| Palindrome check | stack | O(n) | O(n) | [pallindromeCheck.cpp](Stack/FamousProblems/pallindromeCheck.cpp) |
| Infix to postfix | stack | O(n) | O(n) | [postfixConv.cpp](Stack/FamousProblems/postfixConv.cpp) |
| Postfix evaluation | stack | O(n) | O(n) | [postfixEval.cpp](Stack/FamousProblems/postfixEval.cpp) |
| Next greater element | monotonic stack | O(n) | O(n) | [nextGreater.cpp](Stack/FamousProblems/nextGreater.cpp) |
| Min stack | stack of (value, minimum so far) pairs | O(1) per operation | O(n) | [minStack.cpp](Stack/FamousProblems/minStack.cpp) |
| Queue using two stacks | pour only when the output stack is empty | O(1) amortized | O(n) | [queueUsingStacks.cpp](Queue/FamousProblems/queueUsingStacks.cpp) |
| Binary numbers from 1 to N | queue (breadth-first pattern) | O(N log N) | O(N) | [generateBinary.cpp](Queue/FamousProblems/generateBinary.cpp) |
| First non-repeating character in a stream | queue and count array | O(n) | O(1) | [firstNonRepeating.cpp](Queue/FamousProblems/firstNonRepeating.cpp) |
| Tower of Hanoi | recursion | O(2^n) | O(n) | [towerOfHanoi.cpp](Recursion/towerOfHanoi.cpp) |
| Height of a binary tree | recursion | O(n) | O(h) | [heightOfTree.cpp](Trees/FamousProblems/heightOfTree.cpp) |
| Validate a BST | range passed down the recursion | O(n) | O(h) | [validateBST.cpp](Trees/FamousProblems/validateBST.cpp) |
| Lowest common ancestor of a BST | BST ordering | O(h) | O(1) | [LCA.cpp](Trees/FamousProblems/LCA.cpp) |
| Diameter of a binary tree | height plus best bend in one pass | O(n) | O(h) | [diameter.cpp](Trees/FamousProblems/diameter.cpp) |

`h` is the height of the tree.

## Conventions

- Each file starts with a header comment that names the problem, the approaches, and their time and space complexity.
- Results are printed by the functions themselves, and `main()` runs a single demonstration case.
- Code is written in plain C++ with the standard library, with one statement per line.
