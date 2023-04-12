#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	
	struct node *next;
}*head = NULL;

struct node *newNode(int val){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->val = val; //set value dalam node ke yg diinginkan
	temp->next = NULL; //set akhiran gerbong null
	return temp;
};
 
void insertNode(int val){
	struct node *temp = newNode(val);
	
	//if inserting the first data
	if(head == NULL){   //berarti head bagian awal masih kosong
		head = temp;  //set head diisi dengan temp yg ada data di awal
	}
	//if inserting the second or more data
	else{
		temp->next = head;
		head = temp;
	}
}

void displayAll(){
	struct node *curr = head;
	while(curr != NULL){
		printf("%d\n", curr->val);
		curr = curr->next;
	}	
}

void deleteNode(int val){
	struct node *curr = head;
	
	//if value to delete is in head
	if(head->val == val){
		head = curr->next;
		free(curr);
	}
	//if value to delete is in middle or last of linked list
	else{
		while(curr->next != NULL && curr->next->val != val){
			curr = curr->next;
		}
		
		struct node *del = curr->next;
		curr->next = del->next;
//		curr->next = del->next->next;
		free(del);
	}
}

int main(){
	
	insertNode(15);
	insertNode(20);
	insertNode(25);
	insertNode(5);
	
	deleteNode(5);
	deleteNode(15);
	
	displayAll();
	
	return 0;
}
