#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include<iostream>

#include "Node.h"
using namespace std;

template <class T>
class BST{
    private:
        NodeTree<T> *root;
    public:
        BST();
        void push(NodeTree<T>* root, T x);
        NodeTree<T> *returnRoot();
        void createTree();
        void delt();
        int get_cardinality(NodeTree<T>*);
        void Preorden(NodeTree<T>*);
        void InOrden(NodeTree<T>*);
        void Postorden(NodeTree<T>*);
};

template <class T>
BST<T>::BST(){
    root = NULL;
}

template <class T>
void BST<T>::push(NodeTree<T>* Apunt, T x){
    if(Apunt){
        if(x < Apunt->data){
            push(Apunt->lchild, x);
            Apunt->lchild = root;
        }else{
            if(x > Apunt->data){
                push(Apunt->rchild, x);
                Apunt->rchild = root;
            }
            root = Apunt;
        }
    }else{
        NodeTree<T> *ApAux = new NodeTree<T>;
        ApAux->data = x;
        root = ApAux;
    }
}


template <class T>
NodeTree<T>* BST<T>::returnRoot(){
    return root;
}

template <class T>
void BST<T>::createTree(){
    bool res;
    NodeTree<T>* Apunt = new NodeTree<T>;
    cout<<"\nType your data to save: ";
    cin>>Apunt->data;

    cout<<"\n"<<Apunt->data<<" the left node exists? (s/n): ";
    cin>>res;
    if(res){
        createTree();
        Apunt->lchild = root;
    }

    cout<<"\n"<<Apunt->data<<" Have right child? (s/n): ";
    cin>>res;
    if(res){
        createTree();
        Apunt->rchild = root;
    }

    root = Apunt;
}

template <class T>
void BST<T>::Preorden(NodeTree<T>* Apunt){
    if(Apunt!=NULL){
        cout<<Apunt->data<<endl;
        Preorden(Apunt->lchild);
        Preorden(Apunt->rchild);
    }
}

template <class T>
void BST<T>::InOrden(NodeTree<T>* Apunt){
    if(Apunt!=NULL){
        InOrden(Apunt->lchild);
        cout<<Apunt->data<<endl;
        InOrden(Apunt->rchild);
    }
}

template <class T>
void BST<T>::Postorden(NodeTree<T>* Apunt){
    if(Apunt!=NULL){
        Postorden(Apunt->lchild);
        Postorden(Apunt->rchild);
        cout<<Apunt->data<<endl;
    }
}

/*template <class T>
int BST<T>::get_cardinality(NodeTree* Apunt){
	if (Apunt==NULL) return 0;
    return 1 + get_cardinality(Apunt->lchild) + get_cardinality(Apunt->rchild);
    
}*/

#endif // BST_H_INCLUDED
