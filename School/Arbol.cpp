#include<stdlib.h>
#include<iostream>

using namespace std;

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
        int get_cardinality(NodeTree<T>* Apunt){
        	if (Apunt==NULL) return 0;
    		return 1 + get_cardinality(Apunt->lchild) + get_cardinality(Apunt->rchild);
		}
        void Preorden(NodeTree<T>*);
        void InOrden(NodeTree<T>*);
        void Postorden(NodeTree<T>*);
        int get_height(NodeTree<T>* Apunt){
        	int u, v;
        	if(Apunt==NULL) return -1;
        	u=get_height(Apunt->lchild); v = get_height(Apunt->rchild);
        	if (u>v) return u+1; else return v+1;
		}
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
        }
        root = Apunt;
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



using namespace std;

int main()
{
    int x,y;
	BST<int> arbol;
    int arr[10] = {710,689,2000,702,143,1024,3300,70,2099};

    for(int i=0; i<9; i++)
        arbol.push(arbol.returnRoot(), arr[i]);
    
    arbol.InOrden(arbol.returnRoot());
	//arbol.createTree();
    /*
    arbol.Preorden(arbol.returnRoot());
    cout<<endl;
    arbol.InOrden(arbol.returnRoot());
    cout<<endl;
    arbol.Postorden(arbol.returnRoot());
    */
    
    x=arbol.get_cardinality(arbol.returnRoot());
	cout<<"La cardinalidad del arbol es: "<<x<<endl;
	y=arbol.get_height(arbol.returnRoot());
	cout<<"La Altura del arbol es: "<<y;
	
    return 0;
}

/*
 x=arbol.get_cardinality(arbol.returnRoot());
cout<<"La cardinalidad del arbol es: "<<x;
*/
