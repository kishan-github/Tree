#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}node_t;

node_t* createNode(int data)
{
	node_t* temp_node = NULL;
	
	temp_node = malloc(sizeof(node_t));
	if(NULL == temp_node)
	{
		printf("ERROR : Memory allocation failed\n");
		return NULL;
	}
	
	temp_node->data = data;
	temp_node->left = temp_node->right = NULL;
	
	return temp_node;
}

void addElement(node_t** root, int data)
{
	if(NULL == *root)
	{
		*root = createNode(data);
		return;
	}
	
	node_t* temp_node = *root;
	node_t* prev_node = NULL;
	
	while(temp_node)
	{
		prev_node = temp_node;
		if(data < temp_node->data)
			temp_node = temp_node->left;
		else
			temp_node = temp_node->right;
	}
	
	if(data < prev_node->data)
		prev_node->left = createNode(data);
	else
		prev_node->right = createNode(data);
}

void inOrderTraversal(node_t* node)
{
	if(NULL == node)
		return;
	
	inOrderTraversal(node->left);
	printf("%d\t", node->data);
	inOrderTraversal(node->right);
}

int main()
{
	node_t* root = NULL;
	
	addElement(&root, 10);
	addElement(&root, 2);
	addElement(&root, 5);
	addElement(&root, 12);
	addElement(&root, 3);
	addElement(&root, 11);
	addElement(&root, 1);
	
	inOrderTraversal(root);
	
	return 0;
}
