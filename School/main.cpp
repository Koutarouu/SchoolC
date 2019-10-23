/*
Integrantes: 
Dominguez Aguilar Diego Francisco Y Jose Pablo Granados Escamilla.
Grupo: "2 - 3".
*/
#include <iostream>
#include<queue>

using namespace std;
class NodeTree{
    private:
        char data;
        NodeTree *lchild;
        NodeTree *rchild;
    public:
        NodeTree(){
            lchild=NULL;
            rchild=NULL;
        }
    friend class BST;
};


class BST{
    private:
        NodeTree *root;
    public:
        BST(){
        	root = NULL;
		}
		
        void createTree(){
        	char res;
		    NodeTree* Apunt = new NodeTree;
		    cout<<"\nType your data to save: ";
		    cin>>Apunt->data;
		
		    cout<<"\n"<<Apunt->data<<" the left node exists? (s/n): ";
		    cin>>res;
		    if(res=='s'){
		        createTree();
		        Apunt->lchild = root;
		    }
		
		    cout<<"\n"<<Apunt->data<<" Have right child? (s/n): ";
		    cin>>res;
		    if(res=='s'){
		        createTree();
		        Apunt->rchild = root;
		    }
    		root = Apunt;
		}

        void lvlOrden(){
        	if(root==NULL) cout<<"Empty Tree";
		    else{
		    	queue<NodeTree*> q;
		    	q.push(root);
		    	while(!q.empty()){
		    		NodeTree* t = q.front();
		    		q.pop();
		    		if(t->lchild) q.push(t->lchild);
		    		if(t->rchild) q.push(t->rchild);
		    		cout<<t->data<<endl;
				}
			}
		}
};


int main(){
	BST arbol;
	arbol.createTree();
	arbol.lvlOrden();
	return 0;
}

