// integer-trie.h
// Nathan Snyder

#ifndef INT_TRIE_
#define INT_TRIE_

#include <cstddef>

#include "IntTrieNode.h"

template<class T, size_t N>
class IntTrie {
public:
    IntTrie();
    void insert(T num);
private:
    IntTrieNode<T, N> *root;
    int size;
};

template<class T, size_t N>
IntTrie<T, N>::IntTrie() : root(nullptr), size(0) {
    if (N < 2)
        throw "The size must be greater than 1.";
    else
        root = new IntTrieNode<T, N>;
}

template<class T, size_t N>
void IntTrie<T, N>::insert(T num) {
    bool neg = false;
    if (num < 0) neg = true;

    IntTrieNode<T, N> *ptr = root;
    while (num != 0) {
        if (ptr->children == nullptr) ptr->setChildren();
        ptr->children[num % N] = new IntTrieNode<T, N>;
        ptr = ptr->children[num % N];
        num /= N;
    }
    if (neg) ptr->negInt = true;
    else ptr->posInt = true;

    ++size;
}

#endif // INT_TRIE_
