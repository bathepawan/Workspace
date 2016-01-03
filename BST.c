#include<stdio.h>
#include<stdlib.h>

struct Node {
int data;
struct Node *left;
struct Node *right;
};

struct Node *root=NULL;
struct Node * insertNode(struct Node * node,int d);
void inorder(struct Node *node);
void preorder(struct Node *node);
void postorder(struct Node *node);
int size(struct Node *node);

int main()
{
int choice=0,item;
//root=(struct Node *)malloc(sizeof(struct Node));
//root=NULL;
//root->left=NULL;
//root->right=NULL;
do{
	printf("\n Welcome to BST : \n 1.Insert Element \n 2. Inoder \n 3.Preorder \n 4.Postorder \n 5.Size \n 999.Exit");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("Enter Item to be inserted : \n  ");
			scanf("%d",&item);
			root=insertNode(root,item);
		break;
		case 2:
			printf("\nInorder Traversal \n");
			inorder(root);
		break;
		case 3:
			printf("\n Preorder Traversal \n");
			preorder(root);
		break;
		case 4:
			printf("\n Post Order Traversal \n");
			postorder(root);
		break;
		case 5:
		printf("Size is %d",size(root));
                break;
                default:
                break;

	}

}while(choice!=999);
}

struct Node * insertNode(struct Node *rootnode,int d)
{
struct Node *node;
//rootnode=(struct Node *)malloc(sizeof(struct Node));
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

void inorder(struct Node *r)
{
struct Node *cur=r;
//printf("Inorder\n");
if(cur==NULL) return;
else{
	inorder(cur->left);
	printf("%d \t",cur->data);
	inorder(cur->right);
    }
}

void preorder(struct Node *r)
{
struct Node *cur=r;
//printf("Inorder\n");
if(cur==NULL) return;
else{
        printf("%d \t",cur->data);
	preorder(cur->left);
        preorder(cur->right);
    }
}


void postorder(struct Node *r)
{
struct Node *cur=r;
//printf("Inorder\n");
if(cur==NULL) return;
else{
        postorder(cur->left);
        postorder(cur->right);
	printf("%d \t",cur->data);

    }
}




int size(struct Node *r)
{
int c=0;
if(r==NULL)
return 0;
else
return (size(r->left)+size(r->right)+1);
}
