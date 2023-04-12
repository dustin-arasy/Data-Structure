#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	
	struct node *next;
	struct node *prev;
}*head = 0, *tail = 0;

struct node *newNode(int val){
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->val = val;
//	temp->next = 0;- //bisa cara ini
//	temp->prev = 0;
	temp->next = temp->prev = 0; //atau cara ini
	return temp;
}

void insertTail(int val){
	struct node *temp = newNode(val);
	
	//if insert 1st data
	if(head == 0){
		head = tail = temp;
	}
	//if insert >= 2nd data
	else{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
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
	
	if(head == 0){
		printf("LL is empty\n");
		return;
	}
	
	//if delete the only node in double LL
	if(head->val == val && head == tail){
		free(head);
		head = tail = 0;
	}
	//if delete head node
	else if(head->val == val){
		head = head->next;
		free(head->prev);
		head->prev = 0;
	}
	//if delete tail node
	else if(tail->val == val){
		tail = tail->prev;
		free(tail->next);
		tail->next = 0;
	}
	//if delete not head or tail (somewhere in middle)
	else{
		while(curr->next != NULL && curr->next->val != val){
			curr = curr->next;
		}
		
		if(curr->next != NULL){
		struct node *del = curr->next;
		
		curr->next = del->next;
		del->next->prev = curr;
		free(del);
		}
	}
}

int main(){
	
	insertTail(40);
	insertTail(50);
	insertTail(60);
	insertTail(70);
	
	deleteNode(40);
	deleteNode(70);
	deleteNode(60);
	deleteNode(50);
	deleteNode(100);
	
	displayAll();
	
	return 0;
}
