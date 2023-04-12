#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data{
	int val;
	
	struct data *left;
	struct data *right;
} *root = NULL;

struct data *createData(int val){
	struct data *temp = (struct data*)malloc(sizeof(struct data));
	temp->val = val;
	temp->left = temp->right = NULL;
	return temp;
}

void insert(struct data *curr, int newVal){
	if(root == NULL){
		root = createData(newVal);
	}
	else{
		if(newVal < curr->val && curr->left == NULL){
			curr->left = createData(newVal);
			
		}else if(newVal > curr->val && curr->right == NULL){
			curr->right = createData(newVal);
			
		}else if(newVal < curr->val){
			insert(curr->left , newVal);
			
		}else if(newVal > curr->val){
			insert(curr->right , newVal);
		}
	}
}

void displayInfix(struct data *curr){
	
	if(curr->left != NULL) displayInfix(curr->left);
	printf("%d " , curr->val);
	if(curr->right != NULL) displayInfix(curr->right);
}

void find(struct data *curr, int val){
	if(curr==NULL){
		printf("%d is not found in BST\n",val);
		return;
	}
	else if(curr->val == val){
		printf("%d is found in BST\n",val);
		return;
	}
	//jika val lebih kecil dari curr node , rekursif ke kiri
	else if(val < curr->val){
		find(curr->left , val);
	}
	//jika val lebih besar dari curr node , rekursif ke kanan
	else if(val > curr->val){
		find(curr->right, val);
	}
}

struct data *delRecursive(struct data *parent, struct data *curr){
	// jika node leaf / if curr is LEAF
	if(curr->left == NULL && curr->right == NULL){
		//if there is only 1 node in BST
		if(root == curr)
			root = 0;
		
		free(curr);
		return 0 ; 
	}
	
	// jika node hanya memiliki left child
	else if(curr->left != NULL && curr->right == NULL){
		return curr->left;
		
	}
	
	//jika node hanya memiliki right child
	else if(curr->left == NULL && curr->right!= NULL){
		return  curr->right;
	}
	
	//jika node memiliki 2 anak
	else{
		//find successor (rightmost child of left subtree)
		struct data *t = curr->left;
		struct data *tp = curr;
		while(t->right){
			tp = t;
			t= t->right;
		}
		//copy value from t (successor) to node to be deleted
		curr->val = t->val;
		//delete successor node
		t = delRecursive(tp, t);
		return curr;
	}
}

struct data *parent = NULL;
void del(struct data *curr, int delVal){
	//if we found NULL spot / delVal is not in BST
	if (curr == NULL){
		printf("%d is not available in BST\n",delVal);
		return;
	}
	
	//if we found delVal in BST
	if(curr->val == delVal){
		//do deletion
		curr = delRecursive(parent,curr);
//		if(delVal > parent->val) parent->right = curr;
//		else parent->left = curr;
		return;
	}
	
	//if delVal is smaller than curr->val, recursive to left
	if(delVal < curr->val){
		parent =  curr;
		del(curr->left , delVal);
	}
	//if delVal is smaller than curr->val, recursive to right
	else if(delVal > curr->val){
		parent = curr;
		del(curr->right , delVal);
	}
}



int main(){
	
	insert(root, 10);
	insert(root, 20);
	insert(root, 9);
	insert(root, 5);
	insert(root, 11);
	insert(root, 1);
	insert(root, 12);
	insert(root, 25);
	insert(root, 30);
	insert(root, 35);
	insert(root, 40);

	displayInfix(root);
	printf("\n");
	
	return 0;
}
