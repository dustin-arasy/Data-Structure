#include<stdio.h>
#include<stdlib.h>

struct data{
	int val;
	int height;
	
	struct data *left, *right;
}*root = 0, *temp;

int max(int a, int b){
	return a > b ? a : b;
}

int getHeight(struct data *curr){
	if(curr == 0){
		return 0;
	}
	return curr->height;
}

int getBF(struct data *curr){
	if(curr == 0){
		return 0;
	}
	return getHeight(curr->left) - getHeight(curr->right);
}

struct data *rightRotation(struct data *t){
	struct data *s = t->left;
	struct data *b = s->right;
	
	t->left = b;
	s->right = t;
	
	//update height
	t->height = 1 + max(getHeight(t->left), getHeight(t->right));
	s->height = 1 + max(getHeight(s->left), getHeight(s->right));
	
	return s;
}

struct data *leftRotation(struct data *t){
	struct data *s = t->right;
	struct data *b = s->left;
	
	t->right = b;
	s->left = t;
	
	//update height
	t->height = 1 + max(getHeight(t->left), getHeight(t->right));
	s->height = 1 + max(getHeight(s->left), getHeight(s->right));
	
	return s;
}

struct data *createData(int val){
	temp = (struct data*)malloc(sizeof(struct data));
	temp->val = val;
	temp->height = 1;
	temp->left = temp->right = 0;
	
	return temp;
}

struct data *insertData(struct data *curr, int val){
	if(curr == 0){
		return createData(val);
	}
	else if(val < curr->val){
		curr->left = insertData(curr->left, val);
	}
	else if(val > curr->val){
		curr->right = insertData(curr->right, val);
	}
	else{
		return curr;
	}
	
	// update height
	curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));
	
	//count bf
	int bf = getBF(curr);
	
	//left left
	if(bf > 1 && getBF(curr->left) >= 0){
		return rightRotation(curr);
	}
	
	//right right
	if(bf < -1 && getBF(curr->right) <= 0){
		return leftRotation(curr);
	}
	
	//left right
	if(bf > 1 && getBF(curr->left) < 0){
		curr->left = leftRotation(curr->left);
		return rightRotation(curr);
	}
	
	//right left
	if(bf < -1 && getBF(curr->right) > 0){
		curr->right = rightRotation(curr->right);
		return leftRotation(curr);
	}
	
	return curr;
}

void display(struct data *curr){
	if(curr){
		printf("%d ", curr->val);
		display(curr->left);
		display(curr->right);
	}	
}

struct data *deleteData(struct data *curr, int val){
	if(curr == 0){
		return 0;
	}
	else if(val < curr->val){
		curr->left = deleteData(curr->left, val);
	}
	else if(val > curr->val){
		curr->right = deleteData(curr->right, val);
	}
	else{
		// if node has no child
		if(!curr->left && !curr->right){
			free(curr);
			return 0;
		}
		//if node only has left child
		else if(curr->left && !curr->right){
			temp = curr->left;
			free(curr);
			return temp;
		}
		//if node only has right child
		else if(!curr->left && curr->right){
			temp = curr->right;
			free(curr);
			return temp;
		}
		//if node has 2 children
		else{
			temp = curr->left;
			
			while(temp->right){
				temp = temp->right;
			}
			
			curr->val = temp->val;
			curr->left = deleteData(curr->left, temp->val);
		}
	}
	
	// update height
	curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));
	
	//count bf
	int bf = getBF(curr);
	
	//left left
	if(bf > 1 && getBF(curr->left) >= 0){
		return rightRotation(curr);
	}
	
	//right right
	if(bf < -1 && getBF(curr->right) <= 0){
		return leftRotation(curr);
	}
	
	//left right
	if(bf > 1 && getBF(curr->left) < 0){
		curr->left = leftRotation(curr->left);
		return rightRotation(curr);
	}
	
	//right left
	if(bf < -1 && getBF(curr->right) > 0){
		curr->right = rightRotation(curr->right);
		return leftRotation(curr);
	}
	
	return curr;
}

void peek(){
	if(root){
		printf("\nRoot: %d\n\n", root->val);
	}
}

int main(){
	
	root = insertData(root, 70);
	root = insertData(root, 80);
	root = insertData(root, 90);
	root = insertData(root, 100);
	root = insertData(root, 50);
	
	display(root);
	peek();
	
	root = deleteData(root, 80);
	display(root);
	peek();
	
	root = deleteData(root, 50);
	display(root);
	peek();
	
	root = deleteData(root, 90);
	display(root);
	peek();
	return 0;
}
