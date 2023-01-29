#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Mohann Scarlett
*991616041
*Thursday, November 11, 2021
*Program to create, print, and search items in a binary tree to terminal and file
*const int N is input size for both binary Trees
*/

//generic node structure
typedef struct Node{
	int data;
	struct Node *leftChild;
	struct Node *rightChild;
	
}Node, *NodePtr;

//tree root structure
typedef struct Tree{
	NodePtr root;
}Tree, *TreePtr;

//allocate memory for tree structure and assign default values
TreePtr initializeTree(){
	TreePtr tree;
	tree = (TreePtr) malloc(sizeof(Tree));
	tree->root = NULL;
	return tree;
}

//allocate space for a node with a data value, and two empty pointers
NodePtr createNode (int x){
	NodePtr node;
	node = (NodePtr) malloc(sizeof(Node));
	node->data = x;
	node->leftChild = NULL;
	node->rightChild = NULL;
	return node;
}

/*Function to search tree for a specific value within
*If the value of x is equal to the node that is being checked, break out of loop
*If the value of x is less than the value of the node that is being checked, check the left child
*If the value of x is greater than the value of the node that is being checked, check the right child
*Iterate until we reach a leaf / external node
*Return the value of the last node that was being checked
*/
NodePtr treeSearch(TreePtr tree, int x){
	
		NodePtr curr = tree->root; //point towards a specific node in tree
		while((curr->leftChild != NULL) || (curr->rightChild != NULL)){
		if(curr->data == x){
			break;
		}else if(x < curr->data){
			if(curr->leftChild == NULL){
				break;
			}
			curr = curr->leftChild;
		}else {
			if(curr->rightChild == NULL){
				break;
			}
			curr = curr->rightChild;
		}
	}
		if(curr->data != x){
		//	printf("%d not found", x); //Used for troubleshooting
			
		}else{
		//	printf("%d already exists in list", x);  //Used for troubleshooting
		}
		return(curr);
}

/*Insert a value given into appropriate spot in inserted binary tree
*If value is a duplicate, do not insert
*Otherise insert value to be a child of a node returned by treeSearch function
*/
NodePtr insertIntoTree(TreePtr tree, int x){

	NodePtr insertionPoint = treeSearch(tree, x);
	if(insertionPoint->data == x){
		return tree->root;
	}else{
		if(x < insertionPoint->data){
			insertionPoint->leftChild = createNode(x);
			return tree->root;
		}else {
			insertionPoint->rightChild = createNode(x);
			return tree->root;
		}
	}
	}
	
void inOrderPrinter(NodePtr curr, FILE *filePtr){
	if (curr != NULL) 
    { 
        inOrderPrinter(curr->leftChild, filePtr); 
        fprintf(filePtr, "%d ", curr->data);
        inOrderPrinter(curr->rightChild, filePtr);
    } 
}

int main() {
	const int N = 40000; //input size of both binary tree
	printf("Tree input size: %d\n", N);
	TreePtr binaryTree; // sorted binary tree
	TreePtr binaryTreeTwo; //unsorted binary tree
	
	binaryTree = initializeTree();
	binaryTreeTwo = initializeTree();
	
	binaryTree->root = createNode(-1); //create a default root for binary tree so the root is not null
	binaryTreeTwo->root = createNode(-1); //create a default root for binary tree so the root is not null
	
	clock_t insertSortedStartTime = clock(); // time how long binaryTree takes to insert elements
	
	//code to insert values 1 - N to sorted binary tree
	for(int i = 1; i <= N; i++){
		if(binaryTree->root->data == -1){
		binaryTree->root->data = i;
		}else{
		insertIntoTree(binaryTree, i);
		}
	}
	clock_t insertSortedEndTime = clock();
	double seconds = (double)(insertSortedEndTime - insertSortedStartTime) / CLOCKS_PER_SEC; //end time to insert elements into binaryTree
	
	//Code to write sorted binary tree elements to sorted.txt
	FILE * sortWritefPointer;
    sortWritefPointer = fopen("sort.txt", "w");
    clock_t printSortedStartTime = clock(); // time how long binaryTree takes to insert elements
	inOrderPrinter(binaryTree->root, sortWritefPointer);
	clock_t printSortedEndTime = clock(); 
	double secondsThree = (double)(printSortedEndTime - printSortedStartTime) / CLOCKS_PER_SEC; //end time to insert elements into binaryTree
	fclose(sortWritefPointer);
	
	clock_t insertUnsortedStartTime = clock(); //time how long binaryTreeTwo one takes to insert elements
	//code to read elements from dataToBuildDS.txt and insert into unsorted binary tree
	FILE * readfPointer;
	int temp =0;
	for(int i = 1; i <= N; i++){
		temp = rand();
		if(binaryTreeTwo->root->data == -1){
		binaryTreeTwo->root->data = temp;
		}else{
		insertIntoTree(binaryTreeTwo, temp);
		}
	}		
		clock_t insertUnsortedEndTime = clock();
		double secondsTwo = (double)(insertUnsortedEndTime - insertUnsortedStartTime) / CLOCKS_PER_SEC;//end time to insert elements into binaryTreeTwo
	
		//code to write unsorted binary tree elements to unsorted.txt
		FILE * unsortWritefPointer;
    	unsortWritefPointer = fopen("unsorted.txt", "w");
    	clock_t printUnsortedStartTime = clock(); // time how long binaryTree takes to insert elements
    	inOrderPrinter(binaryTreeTwo->root , unsortWritefPointer);
    	clock_t printUnsortedEndTime = clock(); 
		double secondsFour = (double)(printUnsortedEndTime - printUnsortedStartTime) / CLOCKS_PER_SEC; //end time to insert elements into binaryTree
    	fclose(unsortWritefPointer);
    	
    	printf("Time to insert into sorted binary tree: %.10lf \nTime to insert into unsorted binary tree: %.10lf", seconds, secondsTwo);
    	printf("\n\nTime to print into textfile sorted binary tree: %.10lf \nTime to print into textfile unsorted binary tree: %.10lf", secondsThree, secondsFour);
}
