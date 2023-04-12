#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const int maxArrSize = 20;

struct data{	
	char heroName[20];
	char heroType[5]; //str agi int
	int lvl;
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
	
	//get hash value / key / index from hash function
	int idx = hashFunc(heroName);
	printf("%s %d\n", heroName, idx);
	//insert into hash table, linear probing if needed
	//if current index is NULL
	if(dataArr[idx] == 0){
		dataArr[idx] = temp;
	}
	//if current index is NOT NULL
	else{
		int currIdx = idx;
		//Loop untill found is empty spot
		while(dataArr[currIdx] != 0){
			currIdx++;
			if(currIdx >= maxArrSize) currIdx = 0;
			if(currIdx == idx) break;
		}
		
		//if array is full
		if(currIdx == idx) printf("array is full\n");
		//if found empty spot
		else{
			dataArr[currIdx] = temp;
		}
		
	}

}

void display(){
	for(int i=0; i<maxArrSize; i++){
		if(dataArr[i] != 0){
		printf("%s \n", dataArr[i]->heroName);
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
