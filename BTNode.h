#ifndef BTNODE_H_
#define BTNODE_H_

template <typename E>
class BinNode {
public:
    virtual ~BinNode() { }
    virtual E& element() = 0;
    virtual void setElement(const E&) = 0;
    virtual BinNode* left() const = 0;
    virtual void setLeft(BinNode*) = 0;
    virtual BinNode* right() const = 0;
    virtual void setRight(BinNode*) = 0;
    virtual bool isLeaf() = 0;
};

// virtual function will adapt the object pointed to call the corrsponding modified function
// In real life, we define a base class pointer to point the derived classes
// we can just call ptr->func() to use the modified function
// if the function was not declared as virtual function, ptr->func() will call the base class method
// which is absolutely what we want to do.

template <typename Key, typename E>     // Key for internal node and E for leaf node
class BTNode: public BinNode<E> {
private:
    Key k;
    E it;
    BTNode* lc;
    BTNode* rc;

public:
    BTNode(): lc(nullptr), rc(nullptr) { }
    BTNode(Key K, E e, BTNode* l = nullptr, BTNode* r = nullptr):
        k(K), it(e), lc(l), rc(r) { }
    ~BTNode() { }

    E& element() { return it; }
    void setElement(const E& e) { it = e; }
    Key& key() { return k; }
    void setKey(const Key& K) { k = K; }

    // Functions to set and return the children
    inline BTNode* left() const { return lc; }
    // Pass BinNode<E> parameter is logical, derived class is a base class.
    // which expand the range of parameters 
    void setLeft(BinNode<E>* b) { lc = (BTNode*)b; }
    inline BTNode* right() const { return rc; }
    void setRight(BinNode<E>* b) { rc = (BTNode*)b;}

    bool isLeaf() { return (lc==nullptr) && (rc==nullptr); }
};
#endif