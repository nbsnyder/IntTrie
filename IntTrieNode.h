// IntTrieNode.h
// Nathan Snyder

#ifndef INT_TRIE_NODE_
#define INT_TRIE_NODE_

#include <cstddef>

template<class T, size_t N>
class IntTrieNode {
public:
    IntTrieNode();
    ~IntTrieNode();

    bool posInt;
    bool negInt;
    IntTrieNode** children;

    void setChildren();
};

template<class T, size_t N>
IntTrieNode<T, N>::IntTrieNode() : posInt(false), negInt(false), children(nullptr) {
    if (N < 2)
        throw "The size must be greater than 1.";
}

template<class T, size_t N>
IntTrieNode<T, N>::~IntTrieNode() {
    if (children != nullptr) {
        for (IntTrieNode *i : children)
            delete i;

        delete[] children;
        children = nullptr;
    }
}

template<class T, size_t N>
void IntTrieNode<T, N>::setChildren() {
    this->children = new IntTrieNode*[N];
    for (int i = 0; i < N; i++)
        this->children[i] = nullptr;
}

#endif // INT_TRIE_NODE_
