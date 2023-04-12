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
	// priority based on name descending
	struct data *temp = (struct data*)malloc(sizeof(struct data));
	strcpy(temp->name, name);
	strcpy(temp->NIM, nim);
	temp->gpa = gpa;
	temp->next = 0;
	
	//if LL is NULL / empty
	if (head == NULL){
		head = tail = temp;
	}
	
	//if new node has higher prio than head
	else if (strcmpi (name, head->name) > 0){
		//insert head
		temp->next = head;
		head = temp;
	}
	//if new node has lower or some prio than tail
	else if(strcmpi (name, tail->name) <= 0){
		//insert tail
		tail->next = temp;
		tail = temp;
	}
	//if new node has prio somewhere in middle
	else{
		struct data* curr = head;
		while(strcmpi (curr->next->name, name) >= 0){
			curr = curr->next;
		}
	}
	
}


void (display)(){
	struct data *curr = head;
	while (curr != NULL){
		printf ("%s %s %f\n", curr->name, curr->NIM, curr->gpa);
		curr = curr->next;
	}
}

void pop(){
	struct data * del = head;
	head= head->next;
	free(del);
}

int main(){
	push ("Ani", "111", 3.3);
	push ("Bimo", "112", 3.0);
	push ("Lili", "113", 2.5);
	push ("Tino", "114", 3.5);
	push ("Xave", "115", 4.0);

	display();
	pop();
	pop();
	printf ("\n");
	display();
	return 0;
}
