#include "BTNode.h"
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

BTNode<string, int>* BuildTree() {
    int d;
    cin >> d;
    if (d == -1)
        return nullptr;
    BTNode<string, int>* root;
    root = new BTNode<string, int> ("NB", d);
    root->setLeft(BuildTree());
    root->setRight(BuildTree());
    return root;
}

void Preorder(BTNode<string, int>* root) {
    if (root == nullptr)
        return;
    cout << root->element() << endl;
    Preorder(root->left());
    Preorder(root->right());
}

void GivenLevel(BTNode<string, int>* root, int level) {
    if ( root == nullptr)
        return;
    if ( level == 0)
        cout << root->element() << endl;
    else {
        GivenLevel(root->left(), level - 1);
        GivenLevel(root->right(), level - 1);
    }
}

void LevelOrder(BTNode<string, int>* root) {
    for ( int level = 0; level <= 2; ++level )
        GivenLevel(root, level);
}

void InOrder(BTNode<string, int>* root) {
    if ( root == nullptr)
        return;
    if ( root->left() != nullptr)
        InOrder(root->left());
    cout << root->element() << endl;
    InOrder(root->right());
}

void PostOrder(BTNode<string, int>* root) {
    if (root == nullptr)
        return;
    if (root->left() != nullptr || root->right() != nullptr) {
        PostOrder(root->left());
        PostOrder(root->right());
    }
    cout << root->element() << endl;
}

void StackPreOrder(BTNode<string, int>* root) {
    stack<BTNode<string, int>*> tree;
    tree.push(root);
    while (!tree.empty()) {
        BTNode<string, int>* temp = tree.top();
        tree.pop();
        cout << temp->element() << endl;
        if (temp->right() != nullptr)
            tree.push(temp->right());
        if (temp->left() != nullptr)
            tree.push(temp->left());
    }
}

void QueuePreOrder(BTNode<string, int>* root) {
    queue<BTNode<string, int>*> tree;
    vector<BTNode<string, int>*> right_tree;
    tree.push(root);
    while(!tree.empty() || !right_tree.empty()) {
        BTNode<string, int>* temp;
        if (!tree.empty()) {
            temp = tree.front();
            tree.pop();
        }
        else {
            temp = *(right_tree.end() - 1);
            right_tree.pop_back();
        }
        cout << temp->element() << endl;
        if (temp->left() != nullptr)
            tree.push(temp->left());
        if (temp->right() != nullptr)
            right_tree.push_back(temp->right());
    }
}

void StackInorder(BTNode<string, int>* root) {
    stack<BTNode<string, int>*> tree;
    BTNode<string, int>* curr = root;
    while (curr != nullptr || !tree.empty()) {
        while (curr != nullptr) {
            tree.push(curr);
            curr = curr->left();
        }
        curr = tree.top();
        cout << curr->element() << endl;
        tree.pop();
        curr = curr->right();
    }
}

int main() {

    BTNode<string, int>* root;
    root = BuildTree();
    cout << "Preorder Tranversal: \n";
    Preorder(root);
    cout << "Stack Preorder Tranversal: \n";
    StackPreOrder(root);
    cout << "Queue Preorder Tranversal: \n";
    QueuePreOrder(root);
    cout << "Levelorder Tranversal: \n";
    LevelOrder(root);
    cout << "PostOrder Tranversal: \n";
    PostOrder(root);
    cout << "InOrder Tranversal: \n";
    InOrder(root);
    cout << "Stack Inorder Tranversal: \n";
    StackInorder(root);
    return 0;
}
