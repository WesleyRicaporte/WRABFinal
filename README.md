# Word Indexer

Reads a plain-text file, tokenizes and normalizes the words, counts occurrences, then prints an alphabetical list with counts. Implemented in C++ using a binary search tree.

## What it does
- Lowercases text and removes punctuation at word boundaries
- Inserts tokens into a BST keyed by the word string
- Produces a in order A–Z output with count

## Repository contents
- `main.cpp`  (program entry)
- `word.h`    (word record, such as `text` and `count`)
- `node.h`    (tree node that stores a `Word` plus child pointers)
- `tree.h`    (insert, find, traverse, print)
- `Makefile`  (build rules)
- `input.txt`, `test1.txt`, `test2.txt`  (sample inputs)
