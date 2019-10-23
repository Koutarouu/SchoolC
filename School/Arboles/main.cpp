#include <iostream>
#include "BST.h"
#include "Node.h"

using namespace std;

int main()
{
    BST<int> arbol;
    int arr[] = {710,689,2000,702,143,1024,3300,70,2099};

    for(int i=0; i<9; i++)
        arbol.push(arbol.returnRoot(), arr[i]);
    
    arbol.InOrden(arbol.returnRoot());

    /*arbol.createTree();
    arbol.Preorden(arbol.returnRoot());
    cout<<endl;
    arbol.InOrden(arbol.returnRoot());
    cout<<endl;
    arbol.Postorden(arbol.returnRoot());
    */
    return 0;
}

/*
 x=arbol.get_cardinality(arbol.returnRoot());
cout<<"La cardinalidad del arbol es: "<<x;
*/
