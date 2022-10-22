#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;

struct Node{
	KeyType Key;
	struct Node *Left, *Right;
};

typedef struct Node* Tree; // con tro, tro den nut goc

void makenullTree(Tree *pT){
	// struct Node* *pT
	(*pT) = NULL;
}

//Tree makenullTree(){
//	Tree T;
//	T = NULL;
//	return T;
//}

int emptyTree(Tree T){
	return T == NULL;
}

Tree leftChild(Tree N){
	if(N == NULL)
		return NULL;
	else 
		return N->Left;
		
}

Tree rightChild(Tree N){
	if(N != NULL)
		return N->Right;
	else return NULL;	
}

//int isLeaf(Tree N){
//	if(N == NULL)
//		return (N->Left == NULL) && (N->Right == NULL);
//	else return 0;
//}

int isLeaf(Tree N){
	if(!emptyTree(N))
		return (leftChild(N)== NULL) && (rightChild(N) == NULL);
	else return 0;
}

void preOrder(Tree T){ 
	if(T != NULL){
		printf("%d ", T->Key); // N
		preOrder(T->Left);     // L
		preOrder(T->Right);	   // R
	}
}

void inOrder(Tree T){ 
	if(T != NULL){
		inOrder(T->Left);		// L
		printf("%d ", T->Key);  // N
		inOrder(T->Right);		// R
	}		
}

void postOrder(Tree T){ //LRN
	if(T != NULL){
		postOrder(T->Left);     // L
		postOrder(T->Right);    // R
		printf("%d ", T->Key);  // N
	}
}

//// theo cai dat
//int nb_Nodes(Tree T){
//	if(T != NULL)
//		return 1+ nb_NodeS(T->Left)+ nb_Nodes(T->Right);
//	else return 0;	
//}

// theo to chuc luu tru
int nb_Nodes(Tree T){
	if(!emptyTree(T))
		return 1+ nb_Nodes(leftChild(T)) + nb_Nodes(rightChild(T));
	return 0;
}

// theo to chuc luu tru
int nb_leaves(Tree T){
	if(emptyTree(T))
		return 0;
	else if(isLeaf(T))
		return 1;
	else{
		return nb_leaves(leftChild(T)) + nb_leaves(rightChild(T));
	}
}

// dem so nut khong phai la so la

int not_nb_leaves(Tree T){
	if(emptyTree(T) || isLeaf(T))
		return 0;
	else 
		return 1+ nb_leaves(leftChild(T)) + nb_leaves(rightChild(T));
}

// tim phan tu;

int findElement(KeyType x, Tree T){
	if(emptyTree(T))
		return 0;
	else if(T->Key == x)
		return 1;
	else return findElement(x, T->Left) || findElement(x, T->Right);	
}

Tree findElement1(KeyType x, Tree T){
	if(emptyTree(T))
		return NULL;
	else if(T->Key == x)
		return T;
	else{
		Tree G = findElement1(x, T->Left);
		if (G = NULL)
			return findElement1(x, T->Right);
		return G;
	}	
}

// 

Tree search(KeyType x, Tree T){
	if(T == NULL)
		return NULL;
	else if(x < T->Key)
		return search(x, T->Left);
	else if(x > T->Key)
		return search(x, T->Right);
	else
		return T;
}

Tree search1(KeyType x, Tree T){
	if(emptyTree(T))
		return NULL;
	else if(x < T->Key)
		return search(x, leftChild(T));
	else if(x > T->Key)
		return search(x, rightChild(T));
	else 
		return T;
}

// them phan tu vao BST
void insertNode(KeyType x, Tree *pT){
	if((*pT) == NULL){
		(*pT) = (struct Node*)malloc(sizeof(struct Node));
		(*pT)->Key = x;
		(*pT)->Left = NULL;
		(*pT)->Right = NULL;
	}
	
	else if(x < (*pT)->Key)
		insertNode(x, &((*pT)->Left));
	else if(x > (*pT)->Key)
		insertNode(x, &((*pT)->Right));
		
}

Tree createTree(){
	Tree T;
	makenullTree(&T);
	KeyType x;
	int i,n;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &x);
		insertNode(x, &T);
	}	
}

KeyType deleteMin(Tree *pT){
	KeyType k;
	Tree tmp;
	if((*pT)->Left == NULL){
		k = (*pT)->Key;
		tmp =(*pT);
		(*pT) = (*pT)->Right;
		free(tmp);
		
		return k;
	}
	else return deleteMin(&((*pT)->Left));
}


void deleteNode(KeyType x, Tree *pT){
	if((*pT) == NULL);
	else if(x < (*pT)->Key)
		deleteNode(x, &((*pT)->Left));
	else if(x > (*pT)->Key)
		deleteNode(x, &((*pT)->Right));
	else {
		Tree tmp;
		// th khong con
		if ((*pT)->Left == NULL && (*pT)->Right == NULL){
			tmp = (*pT);
			(*pT) = NULL;
			free(tmp);
		} 
		//th co 1 con trai
		else if((*pT)->Left != NULL && (*pT)->Right == NULL){
			tmp = (*pT);
			(*pT)=(*pT)->Left;
			free(tmp);
		}
		// th co 1 con phai
		else if((*pT)->Left == NULL && (*pT)->Right != NULL){
			tmp =(*pT);
			(*pT) = (*pT)->Right;
			free(tmp);
		}
		// co ca 2 ben
		else (*pT)->Key = deleteMin(&((*pT)->Right));
	}
}

int main(){
	Tree T;
	T= createTree();
	inOrder(T);
	
	return 0;
}
