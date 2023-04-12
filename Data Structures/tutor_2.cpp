#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	
	struct node *next;
}*head = 0, *tail = 0;

struct node *newNode(int val){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->val = val;
	temp->next = 0;
	
	return temp;
}

void insertHead(int val){
	struct node *temp = newNode(val);
	
	if(head == NULL){
		head = tail = temp;
	}
	else{
		temp->next = head;
		head = temp;
	}
}

void insertTail(int val){
	struct node *temp = newNode(val);
	
	//if insert 1st data
	if(tail == NULL){
		head = tail = temp;
	}
	
	//if insert >= 2nd data
	else{
		tail->next = temp;
		tail = temp;
	}
}

void insertMiddleAsc(int val){
	
	//decide between insert ascending or insert descending
	
	struct node *temp = newNode(val);
	struct node *curr = head;
	
	//insert value ascending
	while(curr->next->val < val){
		curr = curr->next;
	}
	
	temp->next = curr->next;
	curr->next = temp;
}

void insertMiddleDsc(int val){
	struct node *temp = newNode(val);
	struct node *curr = head;
	
	//insert value descending
	while(curr->next->val > val){
		curr = curr->next;
	}
	
	temp->next = curr->next;
	curr->next = temp;
}

void displayAll(){
	struct node *curr = head;
	
	while(curr != 0){
		printf("%d -> ", curr->val);
		curr = curr->next;
	}
}

void insertDataAsc(int val){
	
	//if LL is empty
	if(head == 0){  	//bisa juga tail == 0
		//choose either insert head or insert tail
		insertHead(val);
//		insertTail(val);
	}
	//if new val is lower than head value
	else if(val < head->val){
		insertHead(val);
	}
	//if new val is higher than tail value
	else if(val > tail->val){
		insertTail(val);
	}
	//if new val is somewhere in middle
	else{
		insertMiddleAsc(val);
	}
}

void insertDataDsc(int val){
	
	//if LL is empty
	if(head == 0){  	//bisa juga tail == 0
		//choose either insert head or insert tail
		insertHead(val);
//		insertTail(val);
	}
	//if new val is lower than head value
	else if(val < tail->val){
		insertTail(val);
	}
	//if new val is higher than tail value
	else if(val > head->val){
		insertHead(val);
	}
	//if new val is somewhere in middle
	else{
		insertMiddleDsc(val);
	}
}

int main(){
	
	// test insertMiddle ascending
//	insertTail(20);
//	insertTail(30);
//	insertTail(40);
//	insertTail(50);
//	
//	insertMiddle(45);
//	insertMiddle(46);
//	insertMiddle(25);
//	insertMiddle(31);
	
	//test insertMiddle descending
//	insertTail(50);
//	insertTail(40);
//	insertTail(30);
//	insertTail(20);2
//	
//	insertMiddleDsc(25);
//	insertMiddleDsc(35);
//	insertMiddleDsc(21);
	
	//test insert all data Asc
	insertDataDsc(40);
	insertDataDsc(10);
	insertDataDsc(29);
	insertDataDsc(50);
	insertDataDsc(1);
	insertDataDsc(24);
	
	displayAll();
	
	return 0;
}
