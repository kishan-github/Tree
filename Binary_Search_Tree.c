#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}node_t;

node_t* delete(node_t* root, int data)
{
	if(root == NULL)
		return root;

	if(data < root->data)
	{
		root->left = delete(root->left, data);
		return root;
	}
	else if(data > root->data)
	{
		root->right = delete(root->right, data);
		return root;
	}

		// element found at this node.
		if(root->left == NULL)
		{
			node_t* temp = root->right;
			free(root);
			return temp;
		}
		if(root->right == NULL)
		{
			node_t* temp = root->left;
			free(root);
			return temp;
		}
		// node have both child.
		node_t* parent = root;
		node_t* succ = root->right;
		
		while(succ->left != NULL)
		{
			parent = succ;
			succ = succ->left;
		}
		
		if(root != parent)
			parent->left = succ->right;
		else
			parent->right = succ->right;
		
		root->data = succ->data;
		
		free(succ);
	
	return root;
}

node_t* create(int data)
{
    node_t* temp;
    
    temp = malloc(sizeof(node_t));
    
    temp->data = data;
    temp->left = temp->right = NULL;
    
    return temp;
}

node_t* add(node_t* root, int data)
{
	if(root == NULL)
		return create(data);
	
	if(data < root->data)
		root->left = add(root->left, data);
	else
		root->right = add(root->right, data);
    
	return root;
}

void display(node_t* root)
{
	if(root == NULL)
		return;
	
	display(root->left);
	printf("%d\t", root->data);
	display(root->right);
}

int main()
{
    node_t* root = NULL;
    
    root = add(root, 10);
	root = add(root, 5);
	root = add(root, 3);
	root = add(root, 7);
	add(root, 15);
	add(root, 13);
	add(root, 17);
	add(root, 2);
	add(root, 1);
	add(root, 4);

	display(root);
	
	root = delete(root, 1);
	
	display(root);

    return 0;
}
