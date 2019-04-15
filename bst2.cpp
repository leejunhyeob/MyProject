#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	struct Node* left;
	int data;
	struct Node* right;
}Node;

Node* insert(Node* root, int data)
{
	if(root == NULL)
	{
		root = (Node*)malloc(sizeof(Node));
		root->left = NULL;
		root->right = NULL;
		root->data = data;
		return root;
	}
	else
	{
		if(root->data > data)
		{
			root->left = insert(root->left,data);
		}
		else if(root->data < data)
		{
			root->right = insert(root->right,data);
		}
		else
		{
			printf("동일값 삽입불가");
		}
	}
	return root; 
}

void print(Node* root)
{
	if(root == NULL)
	{
		return;
	}
	print(root->left);
	printf("%d ",root->data);
	print(root->right);
	
}

Node* search(Node* root,int data)
{
	if(root==NULL)
	{
		printf("값이 없습니다.\n");
		return 0; 
	}
	else if(root->data >data)
	{
		root = search(root->left,data);
	}
	else if(root->data < data)
	{
		root = search(root->right,data);
	}
	else if(root->data == data)
	{
		printf("search data: %d \n",root->data);
		return root;
	}
	return 0;
}

int main(void)
{
	int check;
	int data;
	Node* root = NULL;
	
	while(1)
	{
	printf("\n");
	printf("1.Insert DATA\n");
	printf("2.Print DATA\n");
	printf("3.Search DATA\n");
	printf("Enter the Number: ");
	scanf("%d",&check);
	printf("\n");
	if(check==1)
	{
		printf("plz enter the number: ");
		scanf("%d",&data);
		root= insert(root,data);
	}
	else if(check == 2)
	{
		print(root);
		printf("\n");
	}
	else if(check == 3)
	{
		printf("plz enter the number: ");
		scanf("%d",&data);
		root= search(root,data);
	}
	}
}
