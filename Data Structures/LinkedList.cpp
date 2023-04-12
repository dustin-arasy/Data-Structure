#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
	char name[20];
	int age;
	
	struct data *next;
}*head = 0;

void push(char name[], int age){
	//create new node
	struct data *temp = (struct data*)malloc(sizeof (struct data));
	//fill the new node with required data
	temp->age = age;
	temp->next = 0;
	strcpy(temp->name, name);
	
	//check if stack / linked list is null / empty
	if(head == 0){
		head = temp;
	}
	else{
		temp->next = head;
		head = temp;
	}
}

void display(){
	struct data *curr = head;
	while(curr != 0){
		printf("%s %d\n", curr->name, curr->age);
		curr = curr->next;
	}
}

void popHead(){
	if(head == 0){
		printf("stack is empty!\n");
	}
	else{
		struct data *del = head;
		head = head->next;
		free(del);
	}
}

int main(){
	push("yesun", 25);
	push("kawang", 20);
	push("kefos", 24);
	push("albert", 24);
	
	display();
	
	popHead();
	popHead();
//	popHead();
//	popHead();
//	popHead();
	
	printf("\n");
	display();
	
	return 0;
}
