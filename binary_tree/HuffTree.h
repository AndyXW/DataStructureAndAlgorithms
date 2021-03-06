#ifndef HUFFTREE_H_
#define HUFFTREE_H_

#include <algorithm>
// Huffman tree node abstract base class
template <typename E> class HuffNode {
public:
    virtual ~HuffNode() { }
    virtual int weight() = 0;
    virtual bool is Leaf() = 0;
};

template <typename E>
class LeafNode: public HuffNode<E> {
private:
    E it;
    int wgt;
public:
    LeafNode(const E& val, int freq): it(val), wgt(freq){}
    int weight() { return wgt; }
    E val() { return it; }
    bool isLeaf() { return true; }
};

template <typename E>
class IntlNode: public HuffNode<E> {
private:
    HuffNode<E>* lc;
    HuffNode<E>* rc;
    int wgt;
public:
    IntlNode(HuffNoe<E>* l, HuffNode<E>* r){
        wgt = l->weight() + r->weight();
        lc = l;
        rc = r;
    }
    int weight() { return wgt; }
    bool isLeaf() { return false; }
    HuffNode<E>* left() const { return lc; }
    void setLeft(HuffNode<E>* b) { lc = (HuffNode<E>*)b; }
    HuffNode<E>* right() const { return rc; }
    void setRight(HuffNode<E>* b) { rc = (HuffNode<E>*)b; }
};

// HuffTree is a template of two parameters: the element type being coded and a comparator for two such elements
template <typename E>
class HuffTree {
private:
    HuffNode<E>* Root;
public:
    HuffTree(E& val, int freq) {
        Root = new LeafNode<E>(val, freq);
    }
    HuffTree(HuffTree<E>* l, HuffTree<E>* r) {
        Root = new IntlNode<E>(l->root(), r->root());
    }
    ~HuffTree() {}
    HuffNode<E>* root() { return Root; }
    int weight() { return Root->weight(); }
};

struct cmp {
    bool operator ()(int x, int y) { return x > y; }
};

template <typename E> HuffTree<E>*
buildHuff(HuffTree<E>** TreeArray, int count) {
    
}
#endif