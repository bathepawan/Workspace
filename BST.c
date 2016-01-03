#include<stdio.h>
#include<stdlib.h>

struct Node {
int data;
struct Node *left;
struct Node *right;
};

// Function declaration

struct Node *root=NULL;
struct Node * insertNode(struct Node * node,int d);
void inorder(struct Node *node);
void preorder(struct Node *node);
void postorder(struct Node *node);
int maxDepth(struct Node *node);
int size(struct Node *node);
int getMin(struct Node *node);
int hasPathSum(struct Node *node,int sum);
//Mirror

void mirror(struct Node* node) {
if (node==NULL) {
return;
}
else {
struct Node* temp;
// do the subtrees
mirror(node->left);
mirror(node->right);
// swap the pointers in this node
temp = node->left;
node->left = node->right;
node->right = temp;
}
}
/*
Returns true if a binary tree is a binary search tree.
*/
/*
int isBST(struct node* node) {
if (node==NULL) return(1);
// false if the min of the left is > than us
if (node->left!=NULL && minValue(node->left) > node->data)
return(0);
// false if the max of the right is <= than us
if (node->right!=NULL && maxValue(node->right) <= node->data)
return(0);
// false if, recursively, the left or right is not a BST
if (!isBST(node->left) || !isBST(node->right))
return(0);
// passing all that, it's a BST
return(true);
}
*/
/*
**
Given two trees, return true if they are
structurally identical.
*/
/*
int sameTree(struct node* a, struct node* b) {
// 1. both empty -> true
if (a==NULL && b==NULL) return(true);
// 2. both non-empty -> compare them
else if (a!=NULL && b!=NULL) {
return(
a->data == b->data &&
sameTree(a->left, b->left) &&
sameTree(a->right, b->right)
);
}
// 3. one empty, one not -> false
else return(false);
}
*/
// Main Function
int main()
{
int choice=0,item,sum=0;

do{
	printf("=====================================================================================================================");
	printf("\n Welcome to BST : \n 1.Insert Element \n 2. Inoder \n 3.Preorder \n 4.Postorder \n 5.Size \n 6.Maximum Depth");
	printf("\n 7.Minimum Element in Tree \n 8. HasPathOf sum  \n 999.Exit \n Choice?:  ");
	scanf("%d",&choice);
	printf("======================================================================================================================");
	switch(choice)
	{
		case 1:
			printf("\nEnter Item to be inserted : \n  ");
			scanf("%d",&item);
			root=insertNode(root,item);
		break;
		case 2:
			printf("\nInorder Traversal \n");
			inorder(root);
			printf("\n");
		break;
		case 3:
			printf("\n Preorder Traversal \n");
			preorder(root);
			printf("\n");
		break;
		case 4:
			printf("\n Post Order Traversal \n");
			postorder(root);
			printf("\n");
		break;
		case 5:
			printf("\nSize is %d \n",size(root));
                break;
                case 6:
			printf("\n Maxmimum Depth of tree is %d", maxDepth(root));
		break;
		case 7:
			printf("\n Minimum Element is %d \n",getMin(root));
		case 8:
			printf("\n Enter Sum :");
			scanf("%d",&sum);
			if(hasPathSum(root,sum))
			printf("\n Has Path with sum =%d \n",sum);
			else
			printf("\n No such path exists \n");		
		case 9:
			mirror(root);
			printf("Tree Mirrored and Inorder is :");
			inorder(root);
		default:
                break;

	}

}while(choice!=999);
}

//Insert Node
struct Node * insertNode(struct Node *rootnode,int d)
{
struct Node *node;
node=(struct Node *)malloc(sizeof(struct Node));
node->data=d;
node->left=NULL;
node->right=NULL;

if(rootnode==NULL)
rootnode=node;
else if(rootnode->data >= d)
rootnode->left=insertNode(rootnode->left,d);
else
rootnode->right=insertNode(rootnode->right,d);
return rootnode;
}
//Inorder 
void inorder(struct Node *r)
{
struct Node *cur=r;
if(cur==NULL) return;
else{
	inorder(cur->left);
	printf("%d \t",cur->data);
	inorder(cur->right);
    }
}

//Preorder
void preorder(struct Node *r)
{
struct Node *cur=r;
if(cur==NULL) return;
else{
        printf("%d \t",cur->data);
	preorder(cur->left);
        preorder(cur->right);
    }
}

//Post order
void postorder(struct Node *r)
{
struct Node *cur=r;
if(cur==NULL) return;
else{
        postorder(cur->left);
        postorder(cur->right);
	printf("%d \t",cur->data);

    }
}


//size

int size(struct Node *r)
{
int c=0;
if(r==NULL)
return 0;
else
return (size(r->left)+size(r->right)+1);
}


//max depth
int maxDepth(struct Node *node)
{
int lD=0,rD=0;
if(node==NULL) return 0;
else 
	{
	lD=maxDepth(node->left);
	rD=maxDepth(node->right);
	if(lD>rD) return lD+1;
	else return rD+1;
	}
}

//GetMinimum

int getMin(struct Node *node )
{
if(node==NULL) return 0;
else if(node->left==NULL)
	return node->data;
else
	return getMin(node->left);
}


/*
Given a tree and a sum, return true if there is a path from the root
down to a leaf, such that adding up all the values along the path
equals the given sum.
http://cslibrary.stanford.edu/110/
BinaryTrees.html
Page: 12Binary Trees
Strategy: subtract the node value from the sum when recurring down,
and check to see if the sum is 0 when you run out of tree.
*/
int hasPathSum(struct Node* node, int sum) {
// return true if we run out of tree and sum==0
if (node == NULL) {
return(sum == 0);
}
else {
// otherwise check both subtrees
int subSum = sum - node->data;
return(hasPathSum(node->left, subSum) ||
hasPathSum(node->right, subSum));
}
}
