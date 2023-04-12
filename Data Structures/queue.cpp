#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data{
	char name[20];
	int age;
	
	struct data *next;
}*head = 0, *tail = 0;

void push(char name[], int age){
	struct data *temp = (struct data*)malloc(sizeof (struct data));
	temp->age = age;
	temp->next = 0;
	strcpy(temp->name, name);
	
	//if queue or linked list is empty
	if(tail == 0){
		head = tail = temp;
	}
	else{
		tail->next = temp;
		tail = temp;
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
		printf("queue is empty\n");
	}
	else{
		struct data *del = head;
		head = head->next;
		free(del);
	}
}

int main(){
	
	push("jul", 20);
	push("stephen", 20);
	push("marvel", 20);
	push("marlen", 20);
	
	display();
	
	popHead();
	popHead();
	popHead();

	
	printf("\n");
	display();
	return 0;
}
