#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const int maxArrSize = 20;

struct data{	
	char heroName[20];
	char heroType[5]; //str agi int
	int lvl;
	
	struct data *next;
};

struct data *dataArr[maxArrSize];

int hashFunc(char heroName[]){
	
	//uses division hash function
	//you can modify as needed
	char first = heroName[0];
	char last = heroName[strlen(heroName)-1];
	char second = heroName[1];
	char last2 = heroName[strlen(heroName)-2];
	
	int res = ((first*second)/(last+last2)) % maxArrSize;
	
	return res;
}

void insert(char heroName[], char heroType[], int lvl){
	
	struct data *temp = (struct data*)malloc(sizeof(struct data));
	strcpy(temp->heroName, heroName);
	strcpy(temp->heroType, heroType);
	temp->lvl = lvl;
	temp->next = 0;
	
	//get hash value / key / index from hash function
	int idx = hashFunc(heroName);
	printf("%s %d\n",heroName, idx);
	
	//insert to hash table, apply chaining if needed
	//if current index in hash table is empty
	if(dataArr[idx] == 0){
		dataArr[idx] = temp;
	}
	//if current index in hash table is NOT empty
	else{
		struct data *curr = dataArr[idx];
		while(curr->next != 0){
			curr = curr->next;
		}
		curr->next = temp;
	}
}

void display(){
	for(int i=0; i<maxArrSize; i++){
		//if current idx is not empty
		if(dataArr[i] != 0){
			struct data *curr = dataArr[i];
			while(curr){
				printf("%s ->", curr->heroName);
				curr = curr->next;
			}
			printf("\n");
		}
	}
}

int main(){	
	
	insert("Youtube21", "str", 1);
	insert("noobmaster96", "int", 1);
	insert("xTyranx", "str", 1);
	insert("Revan789", "str", 1);
	insert("Mario", "str", 1);
	insert("RoboFox", "str", 1);
	insert("SnakeyBoy", "agi", 1);
	insert("Derp", "agi", 1);
	insert("Herpina", "str", 1);
	insert("DonChef", "int", 1);
		
	display();
	return 0;
}
