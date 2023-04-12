#include<stdio.h>
#include<string.h>

struct pc{
	char motherboard[30];
	char processor[30];
	char vga[30];
	int ram; // GB
	float price; // Rupiah
};

struct pc pcArr[30];
int currNumofPC = 0;

void insertData(char motherboard[30], char processor[30], char vga[30], int ram, float price){
	
	strcpy(pcArr[currNumofPC].motherboard, motherboard);
	strcpy(pcArr[currNumofPC].processor, processor);
	strcpy(pcArr[currNumofPC].vga, vga);
	pcArr[currNumofPC].ram = ram;
	pcArr[currNumofPC].price = price;
	
	currNumofPC++;
}

void menuDisplay(){
	
	if(currNumofPC == 0){
		printf("There is no data to display\n");
	} 
	else {
		printf("%s %-30s %-30s %-30s %-4s %-10s\n", "No.", "Motherboard",
				"Processor", "VGA", "RAM", "Price");
		
		for(int i=0; i<currNumofPC; i++){
			printf("%d. %-30s %-30s %-30s %-4d %-10f\n", i+1, pcArr[i].motherboard,
				pcArr[i].processor, pcArr[i].vga, pcArr[i].ram, pcArr[i].price);
		}
		
	}
	
}

void menuModify(){
	
	if(currNumofPC == 0){
		printf("There is no data to modify\n");
	}
	else {
		int n;
		menuDisplay();
		
		do{
		printf("enter number of data to modify: ");
		scanf("%d", &n); getchar();
		} while(n < 1 || n > currNumofPC);
		
		n--;
		
	char motherboard[30];
	char processor[30];
	char vga[30];
	int ram; // GB
	float price; // Rupiah
	
	printf("Input new motherboard: ");
	scanf("%[^\n]", motherboard); getchar();
	
	printf("Input new processor: ");
	scanf("%[^\n]", processor); getchar();
		
	printf("Input new vga: ");
	scanf("%[^\n]", vga); getchar();
	
	printf("Input new RAM size: ");
	scanf("%d", &ram); getchar();
	
	printf("Input new pc price: ");
	scanf("%f", &price); getchar();
	
	strcpy(pcArr[n].motherboard, motherboard);
	strcpy(pcArr[n].processor, processor);
	strcpy(pcArr[n].vga, vga);
	pcArr[n].ram = ram;
	pcArr[n].price = price;
	}
}

void menuInsert(){
	char motherboard[30];
	char processor[30];
	char vga[30];
	int ram; // GB
	float price; // Rupiah
	
	printf("Input motherboard: ");
	scanf("%[^\n]", motherboard); getchar();
	
	printf("Input processor: ");
	scanf("%[^\n]", processor); getchar();
	
	
	printf("Input vga: ");
	scanf("%[^\n]", vga); getchar();
	
	printf("Input RAM size: ");
	scanf("%d", &ram); getchar();
	
	printf("Input pc price: ");
	scanf("%f", &price); getchar();
	
	strcpy(pcArr[currNumofPC].motherboard, motherboard);
	strcpy(pcArr[currNumofPC].processor, processor);
	strcpy(pcArr[currNumofPC].vga, vga);
	pcArr[currNumofPC].ram = ram;
	pcArr[currNumofPC].price = price;
	
	currNumofPC++;
}

void menuDelete(){
	
	if(currNumofPC == 0){
		printf("There is no data to delete\n");
	}
	else {
		int n;
		menuDisplay();
		
		do{
		printf("Choose number of data to delete: ");
		scanf("%d", &n); getchar();
		}while(n < 1 || n > currNumofPC);
		
		n--;
		
		// misal hapus index 0
		for(int i=n; i<currNumofPC; i++){
			strcpy(pcArr[i].motherboard, pcArr[i+1].motherboard); // replcace motherboard index 0 with the next index
			strcpy(pcArr[i].processor, pcArr[i+1].processor); // replcace processor index 0 with the next index
			strcpy(pcArr[i].vga, pcArr[i+1].vga); // replcace vga index 0 with the next index
			pcArr[i].ram = pcArr[i+1].ram; // replcace ram index 0 with the next index
			pcArr[i].price = pcArr[i+1].price; // replcace price index 0 with the next index
		}
		currNumofPC--;
	}
}


int main(){
	
	int menu;
	
	insertData("asus tuf", "i5", "rtx 1050", 8, 100000000);
	insertData("asus tuf", "i7", "rtx 3050", 6, 185000000);
	insertData("asus tuf", "i2", "rtx 1020", 4, 122000000);
	
	do{
	printf("1. Display PC data\n");
	printf("2. Insert PC data\n");
	printf("3. Modify PC data\n");
	printf("4. Delete PC data\n");
	printf("5. Exit\n");
	printf("Choose: ");
	scanf("%d", &menu); getchar();
	
	switch(menu){
		
		case 1:
			menuDisplay();
			break;
		
		case 2:
			menuInsert();
			break;
			
		case 3: 
			menuModify();
			break;
			
		case 4: 
		menuDelete();
			break;
		
	}
	
	}while(menu != 5);
	
	return 0;
}
