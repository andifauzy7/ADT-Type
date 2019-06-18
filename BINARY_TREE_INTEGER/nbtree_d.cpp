#include <limits.h>
#include <malloc.h>
#include "nbtree_d.h"
#include "boolean.h"

void create_node(nbAddr *root){
    (*root) =(nbAddr) malloc(sizeof(ElmtTree));
    (*root)->info=NULL;
    (*root)->height=1;
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

/* Modul Pembantu */
int nilai_max(int a, int b){
	return (a > b)? a : b;
}

int height(nbAddr *N){
	if (N == NULL)
		return 0;
	return (*N)->height;
}

nbAddr Node_baru(int value){
    nbAddr node;
	node = (nbAddr) malloc(sizeof(ElmtTree));
	node->info = value;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}

nbAddr rotasi_kanan(nbAddr *y){
	nbAddr x = (*y)->left;
	nbAddr T2 = x->right;

	// Perform rotation
	x->right = (*y);
	(*y)->left = T2;

	// Update heights
	(*y)->height = nilai_max(height(&(*y)->left), height(&(*y)->right))+1;
	x->height = nilai_max(height(&x->left), height(&x->right))+1;

	return x;
}

nbAddr rotasi_kiri(nbAddr *x){
	nbAddr y = (*x)->right;
	nbAddr T2 = y->left;

	// Perform rotation
	y->left = (*x);
	(*x)->right = T2;

	// Update heights
	(*x)->height = nilai_max(height(&(*x)->left), height(&(*x)->right))+1;
	y->height = nilai_max(height(&y->left), height(&y->right))+1;

	// Return new root
	return y;
}

int selisih_balance(nbAddr N){
	if (N == NULL)
		return 0;
	return height(&N->left) - height(&N->right);
}

nbAddr insert_avl(nbAddr *node, int value){
	/* 1. Perform the normal BST insertion */
	if ((*node) == NULL)
		return(Node_baru(value));

	if (value < (*node)->info)
		(*node)->left = insert_avl(&(*node)->left, value);
	else if (value > (*node)->info)
		(*node)->right = insert_avl(&(*node)->right, value);
	else // Equal keys are not allowed in BST
		return (*node);

	/* 2. Update height of this ancestor node */
	(*node)->height = 1 + nilai_max(height(&(*node)->left),height(&(*node)->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = selisih_balance(*node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && value < (*node)->left->info)
		return rotasi_kanan(&(*node));

	// Right Right Case
	if (balance < -1 && value > (*node)->right->info)
		return rotasi_kiri(&(*node));

	// Left Right Case
	if (balance > 1 && value > (*node)->left->info)
	{
		(*node)->left = rotasi_kiri(&(*node)->left);
		return rotasi_kanan(&(*node));
	}

	// Right Left Case
	if (balance < -1 && value < (*node)->right->info)
	{
		(*node)->right = rotasi_kanan(&(*node)->right);
		return rotasi_kiri(&(*node));
	}

	/* return the (unchanged) node pointer */
	return (*node);
}
