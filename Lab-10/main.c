#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node Node;

struct Node
{
	int data;
	Node *left;
	Node *right;
	int getBalance : 2;
};

Node *ROOT;

int max(int a, int b)
{
	return (a >= b) ? a : b;
}

int getHeight(Node* root)
{
    if(root == NULL)
        return -1;
    else
        return 1 + max(getHeight(root->left), getHeight(root->right));
}

int getBalance(Node *N)
{
    if(N == NULL)
        return 0;
    return (getHeight(N->left) - getHeight(N->right));
}

Node *findParent(Node *Root, Node *Z)
{
	if(Root != NULL)
	{
		if(Root->left == Z || Root->right == Z)
			return Root;
		if(Z->data <= Root->data && Root->left)
			return findParent(Root->left, Z);
		if(Z->data > Root->data && Root->right)
			return findParent(Root->right, Z);
	}
}

Node *rotate(Node *Root, Node *X, Node *Y, Node *Z)
{
	//Find parent of Z
	Node *parent;
	parent = findParent(Root, Z);
	
	Node *a, *b, *c, *temp, *T0, *T1, *T2, *T3;
	Node *P = X, *Q = Y, *R = Z;
	
	if(X->data > Y->data)
	{
		//swap X, Y
		temp = X;
		X = Y;
		Y = temp;
	}
	if(Y->data > Z->data)
	{
		temp = Y;
		Y = Z;
		Z = temp;
	}
	if(X->data > Y->data)
	{
		//swap X, Y
		temp = X;
		X = Y;
		Y = temp;
	}
	a = X;
	b = Y;
	c = Z;
	
	X = P;
	Y = Q;
	Z = R;
	
	T0 = a->left;
	T3 = c->right;
	
	if(a->right != b && a->right != c)
		T1 = a->right;
	else
		T1 = b->left;
	
	if(b->right != c && b->right != a)
		T2 = b->right;
	else
		T2 = c->left;
		
	if(parent == NULL)
		parent = b;
	else if(parent->left == Z)
		parent->left = b;
	else if(parent->right == Z)
		parent->right = b;
	b->left = a;
	b->right = c;
	a->left = T0;
	a->right = T1;
	c->left = T2;
	c->right = T3;
	
	return b;
}

Node *add(Node *root, int data)
{
	Node *X, *Y, *Z, *parent;
	if(root == NULL)
	{
		Node *new = (Node *)malloc(sizeof(Node));
		new->data = data;
		new->left = NULL;
		new->right = NULL;
		new->getBalance = 0;
		return new;
	}
	else
	{
		if(data <= root->data)
			root->left = add(root->left, data);
		else
			root->right = add(root->right, data);
	}
	
	int balance = getBalance(root);
	
	//left left case
    	if(balance > 1 && data < root->left->data)
    	{
    	    return rotate(ROOT, root->left->left, root->left, root);
    	}
    
    	//left right case
    	if(balance > 1 && data > root->left->data)
    	{
    	    return rotate(ROOT, root->left->right, root->left, root);
    	}
    
    	//right right case
    	if(balance < -1 && data > root->right->data)
    	{
    	    return rotate(ROOT, root->right->right, root->right, root);
    	}
    
   	 //right left case
 	if(balance < -1 && data < root->right->data)
  	{
            return rotate(ROOT, root->right->left, root->right, root);
    	}	
	return root;
}

bool find(Node *root, int data)
{
	if(root == NULL)
		return false;
	if(root->data == data)
		return true;
	if(data < root->data)
		return find(root->left, data);
	else
		return find(root->right, data);
}

Node *minValueNode(Node *node)
{
	Node *cur = node;
	while(cur->left != NULL)
		cur = cur->left;
	return cur;
}

//deletes the key and returns the new root
Node *delete(Node *root, int data)
{
	if(root == NULL)
		return root;
	if(data < root->data)
		root->left = delete(root->left, data);
	else if(data > root->data)
		root->right = delete(root->right, data);
	else
	{
		if(root->left == NULL)
		{
			Node *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			Node *temp = root->left;
			free(root);
			return temp;
		}
		
		//find inorder successor
		Node *succ = minValueNode(root->right);
		root->data = succ->data;
		root->right = delete(root->right, succ->data);
	}
	return root;
}

//Exer-2 (a) Rank Query
void inorder(Node *root, int *k)
{
	//printf("%d\n", *k);
	if(root == NULL || *k < 0)
		return;
	inorder(root->left, k);
	(*k)--;
	if(*k == 0)
	{
		printf("%d\n", root->data);
		return;
	}
	inorder(root->right, k);
}

void preOrder(Node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

//Exer-2 (b) Range Query
int p;

void rangeSearch(Node *root, int k1, int k2, int *arr)
{
	//base case
	if(root == NULL || k1 > k2)
		return;
	//recursive case
	if(root->data > k2)
		rangeSearch(root->left, k1, k2, arr);
	else if(root->data < k1)
		rangeSearch(root->right, k1, k2, arr);
	else
	{
		rangeSearch(root->left, k1, root->data, arr);
		arr[p++] = root->data;
		rangeSearch(root->right, root->data, k2, arr);
	}
}

int main()
{
    Node *root = NULL;  
    
    ROOT = root;
      
    /*
    root = add(root, 10);  
    root = add(root, 20);  
    root = add(root, 30);  
    root = add(root, 40);  
    root = add(root, 50);  
    root = add(root, 25);   
      
    The constructed AVL Tree would be  
                30  
            / \  
            20 40  
            / \ \  
        10 25 50  
    */
 
    
    root = add(root, 9); 
    root = add(root, 5); 
    root = add(root, 10); 
    root = add(root, 0); 
    root = add(root, 6); 
    root = add(root, 11); 
    root = add(root, -1); 
    root = add(root, 1); 
    root = add(root, 2); 
  
    /* The constructed AVL Tree would be 
            9 
           /  \ 
          1    10 
        /  \     \ 
       0    5     11 
      /    /  \ 
     -1   2    6 
    */
    
    preOrder(root);  
    printf("\n");
    
    int temp = 3;
    inorder(root, &temp);
    
    temp = 4;
    inorder(	root, &temp);
    
    temp = 5;
    inorder(root, &temp);
    
    p = 0;
    
    int *arr = (int *)malloc(25 * sizeof(int));
    rangeSearch(root, 3, 9, arr);
    
    for(int i = 0; i < p; i++)
    	printf("%d ", arr[i]);
    printf("\n");
    
    return 0;  
}