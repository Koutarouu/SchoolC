#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include "BST.h"

template <class T>
class NodeTree{
    private:
        T data;
        NodeTree<T> *lchild;
        NodeTree<T> *rchild;
    public:
        NodeTree(){
            lchild=NULL;
            rchild=NULL;
        }
    template<class U> friend class BST;
};

#endif // NODE_H_INCLUDED
