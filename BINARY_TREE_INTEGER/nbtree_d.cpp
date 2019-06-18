#include <limits.h>
#include <malloc.h>
#include "nbtree_d.h"
#include "boolean.h"

bool c=false;

void create_node(nbAddr *root){
    (*root) =(nbAddr) malloc(sizeof(ElmtTree));
    (*root)->info=NULL;
    (*root)->left=NULL;
    (*root)->right=NULL;
}

void insert_node(nbAddr *root, nbType X){
    if((*root)->info==NULL){
        (*root)->info=X;
    } else if(X > (*root)->info){
        if((*root)->right==NULL){
            create_node(&(*root)->right);
        }
        insert_node(&(*root)->right, X);
    } else {
        if((*root)->left==NULL){
            create_node(&(*root)->left);
        }
        insert_node(&(*root)->left, X);
    }
}

nbAddr value_minimum(nbAddr root){
    nbAddr temp=root;
    while(temp && temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

nbAddr nbSearch(nbAddr root, nbType src){
	if (root!=NULL){
		if (root->info==src)
			return root;
		else{
		    (src > root->info) ? nbSearch(root->right,src) : nbSearch(root->left,src);
		}
	}
	else{
		return NULL;
	}
}

int nbDepth(nbAddr root){
    if (root == NULL)
        return 0;
    else
    {
        int l_depth = nbDepth(root->left);
        int r_depth = nbDepth(root->right);

        if (l_depth > r_depth){
            return(l_depth + 1);
        }else {
            return(r_depth + 1);
        }
    }
}

int bHeight(nbAddr root){
    return nbDepth(root);
}

/* ---------------- TRAVERSAL Tree ---------------- */
void nbPost(nbAddr root){
	if (root!=NULL){
		nbPost(root->left);
		nbPost(root->right);
        printf("%d ", root->info);
	}
}

void nbPre(nbAddr root){
	if (root!=NULL){
		printf("%d ", root->info);
		nbPre(root->left);
		nbPre(root->right);
	}
}

void nbIn(nbAddr root){
	if (root!=NULL){
		nbIn(root->left);
		printf("%d ", root->info);
		nbIn(root->right);
	}
}

void nbLevelOrder(nbAddr root,int level){
	if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->info);
    else if (level > 1)
    {
        nbLevelOrder(root->left, level-1);
        nbLevelOrder(root->right, level-1);
    }
}

void print_level(nbAddr root){
    int i=0, depth=nbDepth(root);
    while(i<=depth){
        nbLevelOrder(root,i);
        i++;
    }
}

/* Modul Pembantu Untuk AVL Tree */


int height(struct Node *N){
	if (N == NULL)
		return 0;
	return N->height;
}

int max(int a, int b){
	return (a > b)? a : b;
}

struct Node* newNode(int key){
	struct Node* node = (struct Node*)
						malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially added at leaf
	return(node);
}

struct Node *rightRotate(struct Node *y){
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	// Return new root
	return x;
}

struct Node *leftRotate(struct Node *x){
	struct Node *y = x->right;
	struct Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	// Return new root
	return y;
}

int getBalance(struct Node *N){
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

struct Node* insert(struct Node* node, int key){
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else // Equal keys are not allowed in BST
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
						height(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

void preOrder(Node *root){
	if(root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void postOrder(Node *root){
	if(root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->key);
	}
}

void inOrder(Node *root){
	if(root != NULL)
	{
		inOrder(root->left);
		printf("%d ", root->key);
		inOrder(root->right);
	}
}

void lvOrder(Node *root,int level){
	if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->key);
    else if (level > 1)
    {
        lvOrder(root->left, level-1);
        lvOrder(root->right, level-1);
    }
}

void print_level_avl(Node *root){
    int i=0, depth=Depth_balance(root);
    while(i<=depth){
        lvOrder(root,i);
        i++;
    }
}

int Depth_balance(Node *root){
    if (root == NULL)
        return 0;
    else
    {
        int l_depth = Depth_balance(root->left);
        int r_depth = Depth_balance(root->right);

        if (l_depth > r_depth){
            return(l_depth + 1);
        }else {
            return(r_depth + 1);
        }
    }
}

nbAddr Delete(nbAddr root,int value)
{
	c=nbSearch(root,value);
	if(root==NULL)
		return root;
	else if(value< root->info)
	{
		root->left= Delete(root->left,value);
	}
	else if(value> root->info)
	{
		root->right= Delete(root->right,value);
	}

	// Node deletion
	else
	{
		//case 1: Leaf Node
		if(root->left==NULL&&root->right==NULL)
		{
			delete root;
			root=NULL;
			return root;
		}
		//case 2: one child
		else if(root->left==NULL)
		{
			struct nbTreeNode* temp=root;
			root=root->right;
			delete temp;
			return root;
		}
		else if(root->right==NULL)
		{
			struct nbTreeNode* temp=root;
			root=root->left;
			delete temp;
			return root;
		}
		//case 3: 2 child
		else
		{
			struct nbTreeNode*temp=value_minimum(root->right);
			root->info=temp->info;
			root->right=Delete(root->right,temp->info);
		}
	}
	return root;

}
