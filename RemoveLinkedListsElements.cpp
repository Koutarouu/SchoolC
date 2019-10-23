/*Remove Linked List Elements
Remove all elements from a linked list of integers that have value val.
Example:
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/
#include<iostream>
using namespace std;

struct ListNode {
    int val;
	ListNode *next;
	//ListNode(int x) : val(x), next(NULL) {}
};
						//ListNode** pointerToHead y volveria a ser void
ListNode* InsertBegi(ListNode* head, int val){ //es necesario el ListNode* para indicar que estamos retornando algo modificando el anterior
	ListNode* temp= new ListNode;
	temp->val = val;
	temp->next = NULL;
	if(head != NULL) temp->next = head; //si usamos referencia *head y temp->next = *head y despues *head = temp
	head = temp;
	return head;
}

void Print(ListNode* head){ //como la que llega es una copia no se modifica nada
	while(head != NULL){
		cout<<head->val<<' ';
		head=head->next;
	}
	cout<<endl;
}

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
        
        while(head->val == val){
            head = head->next;
            if(head == NULL) return NULL;
        }
        
        ListNode* temp = head;
        
        while(head->next != NULL){
            if(head->next->val == val){
                head->next = head->next->next;
            }else{
                head = head->next;
            }
            
        }
        return temp;
        }
};


int main(){
	Solution s;
	int n,i,x;
	ListNode* head =NULL;
	cout<<"How many numbers?"<<endl;
	cin>>n;
	for(i=0; i<n; i++){
		cout<<"Enter the number \n"<<endl;
		cin>>x;
		head = InsertBegi(head, x); //InsertBegi(&head, x);
		Print(head);
	}
	cout<<"Que elemento quiere eliminar: ";
	cin>>x;
	head = s.removeElements(head, x);
	Print(head);
	cout<<"Bien hecho.";
	return 0;
}

