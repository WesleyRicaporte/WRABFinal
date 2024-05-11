#pragma once
#include "node.h"

template <class T1>
class BST
{
    private:
    Node<T1>* _root;
    Node<T1>* insertNode(Node<T1>*, T1);
    void inOrderPrint(Node<T1>*);
    Node<T1>* searchData(Node<T1>*, T1);
    Node<T1>* removeData(Node<T1>*, T1);
    Node<T1>* minVal(Node<T1>*);
    void destroyTree(Node<T1>* root);


    public:
    void insert(T1);
    void inOrder();
    bool search(T1);
    void remove(T1);
    void increment(T1);
    ~BST();
};

// Destructor, should check if root exists and then delete it. Each node will handle deleting its leaf nodes.
template <class T1>
BST<T1>::~BST()
{
    destroyTree(_root);
}

// Public method that takes in some data and passes that into the removeData method. Don't forget to update _root as you may end up deleting the original root.
template <class T1>
void BST<T1>::remove(T1 data)
{
    // take the root and set it = to removing root and data
    _root= removeData(_root , data);
}

// Private method to recursively walk the tree until the data is found.
// Then using the process built in class, check if there is only one leaf, if so then move that leaf into the root position.
// If there are two leafs, find the smallest value in the right subtree (or the largest value in the left subtree but you would have to rename minVal method) and then replace
// the current node with that.
// Don't forget to clean up your memory!
template <class T1>
Node<T1>* BST<T1>::removeData(Node<T1>* root, T1 data)
{
    
    //check if root is empty first
    if (root==nullptr){
        return nullptr;
    }
    // check the data compared to the root data if it is smaller go left bigger go right like in search
    if(root->getData()> data){
        Node <T1>* ltemp = removeData(root->getLeft() , data);
        root->setLeft(ltemp);
    }
    else if (root->getData() < data){
        Node <T1>* rtemp = removeData(root->getRight() , data);
        // walk through the tree
        root->setRight(rtemp);
    }
    else{
        // removing if there is only one leaf if right is empty but left is a child
        if(root->getRight()== nullptr){
            Node <T1>* temp = root->getLeft(); 
            delete root;
            return temp;
        }
        // same but left now
        else if(root->getLeft()== nullptr){
            Node <T1>* temp = root->getRight(); 
            delete root;
            return temp;
        }
        // remove and fix bst finding the smallest in the right
        //I move to the right first then find the min val and set it to that
        Node <T1>* temp =minVal(root->getRight());
        root->setData(temp->getData());
        // remove that node and clean needs two inputs in remove data
        root->setRight(removeData(root->getRight(), temp->getData()));

    }
    
    return root;
}

// Given a node, find the smallest value in that subtree. Return that node
template <class T1>
Node<T1>* BST<T1>::minVal(Node<T1>* root)
{
     Node<T1>* temp = root;
    // keep going left until null to get smallest
    while(temp->getLeft()!=nullptr){
        temp = temp->getLeft();
    }
    return temp;
}

// Given data and a node, recursively walk the tree to find that node if it exists.
template <class T1>
Node<T1>* BST<T1>::searchData(Node<T1>* root, T1 data)
{
    // 3 if statements the first to check if the root is the data
    // the other two are to check if the left and right leaf
    if (root==nullptr){
        return nullptr;
    }
    if (root->getData() == data ){
        return root;
    }
    if (root->getData() < data){
        return searchData(root->getRight(), data);
    }
        return searchData(root->getLeft(), data);
   
}

// Wrapper function for searchData. Pass data, root into searchData and return true if data found, return false if data not found.
template <class T1>
bool BST<T1>::search(T1 data)
{
    Node <T1>* temp = searchData(_root , data);
    if(temp!=nullptr && temp->getData() == data){
    return true;
    }
    return false;
}

// Given a node, recursively walk the tree to print out the inOrder format. That's left->root->right.
// Make sure you cout with a space separating each value as I based my tests on that!
// For example, you would end up cout (do not add the "): "1 2 3 4 5 "
// Notice that there is an extra space at the end.
template <class T1>
void BST<T1>::inOrderPrint(Node<T1>* root)
{
    // make sure it is not a nullptr
    if (root!=nullptr){
        // write 3 statments to get the left and right data
        inOrderPrint (root->getLeft());
        cout << root->getData() << " ";
         inOrderPrint (root->getRight());
    }
}

// Wrapper for inOrderPrint
template <class T1>
void BST<T1>::inOrder()
{
    inOrderPrint(_root);
}


// Give some data and a node, recursively walk the tree until you get to a nullptr and store the value there.
// You should ensure that if data < the current node's data, you walk the left. If data > current node's data, walk right.
// You should check if the value already exists and say so (it's just adding an else with a cout).
template <class T1>
Node<T1>* BST<T1>::insertNode(Node<T1>* root, T1 data)
{
    // if it is a null we will create a new node and set its data
    if (root==nullptr){
    Node<T1>* temp = new Node<T1>();
    // passing in data given
    temp->setData(data);
    return temp;
    }
    // check data to walk left or right
    if(root->getData()> data){
        Node <T1>* ltemp = insertNode(root->getLeft() , data);
        root->setLeft(ltemp);
    }
    else if (root->getData() < data){
        Node <T1>* rtemp = insertNode(root->getRight() , data);
        root->setRight(rtemp);
    }
    return root;
}

// Wrapper for insertNode. Take in data to pass that and _root to insertNode. Ensure you update _root since if the tree is empty, that would be the new _root.
template <class T1>
void BST<T1>::insert(T1 data)
{
     if(_root== nullptr){
    _root = new Node<T1>();
     _root->setData(data);
    
    } 
    else{
    insertNode(_root , data);
    }
}

// Search for the word by calling searchData passing in _root and data.
// If node is found, setData on that node with getData++
template <class T1>
void BST<T1>::increment(T1 data)
{
    Node<T1>* result = searchData(_root, data);
    if (result->getData() == data)
    {
        result->setData(result->getData()++);
        return;
    }
   
}
