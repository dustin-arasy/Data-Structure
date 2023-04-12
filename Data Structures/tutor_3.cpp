#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data{
	char name[20];
	char NIM[4];
	float gpa;
	
	struct data *next;
}*head = 0, *tail = 0;

void push(char name[], char nim[], float gpa){
	
	//priority based on gpa desc
	
	struct data *temp = (struct data*)malloc(sizeof(struct data));
	strcpy(temp->name, name);
	strcpy(temp->NIM, nim);
	temp->gpa = gpa;
	temp->next = 0;
	
	//if ll is NULL / empty
	if(head == 0){
		head = tail = temp;
	}
	//if new node has higher prio than head
	else if(gpa > head->gpa){
		//insert head
		temp->next = head;
		head = temp;
	}
	//if new node has lower or same prio than tail
	else if(gpa<= tail->gpa){
		//insert tail
		tail->next = temp;
		tail = temp;
	}
	//if new node has prio somewhere in middle
	else{
		struct data *curr = head;
		while(curr->next->gpa >= gpa){
			curr = curr->next;
		}
		
		temp->next = curr->next;
		curr->next = temp;
	}
}

void display(){
	struct data *curr = head;
	while(curr != 0){
		printf("%s %s %f\n", curr->name, curr->NIM, curr->gpa);
		curr = curr->next;
	}
}

void pop(char name[], char nim[], float gpa){
	if(head == 0){
		printf("LL is empty!\n");
	}
	else{
		struct data *del = head;
		head = head->next;
		free(del);
	}
}

int main(){
	
	push("budi", "111", 3.0);
	push("wati", "112", 2.5);
	push("timo", "113", 3.5);
	push("tyre", "114", 4.0);
	push("bobb", "115", 3.2);
	push("boby", "116", 3.9);
	
	display();
	pop("boby", "116", 3.9);
	return 0;
}
