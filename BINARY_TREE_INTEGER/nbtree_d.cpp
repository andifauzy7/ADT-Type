#include <limits.h>
#include <malloc.h>
#include "nbtree_d.h"
#include "boolean.h"

bool c=false;

void create_node(nbAddr *root){
    (*root) =(nbAddr) malloc(sizeof(ElmtTree));
    (*root)->info=NULL;
    (*root)->left=(*root)->right=NULL;
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
    else {
        int l_depth = nbDepth(root->left);
        int r_depth = nbDepth(root->right);

        if (l_depth > r_depth){
            return(l_depth + 1);
        }else {
            return(r_depth + 1);
        }
    }
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
    else if (level > 1){
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

int max(int a, int b){
	return (a > b)? a : b;
}

nbAddr build_node(nbType value){
	nbAddr node = (nbAddr)malloc(sizeof(ElmtTree));
	node->info = value;
	node->left = node->right = NULL;
	node->height = 1;
	return(node);
}

int height_node(nbAddr root){
	if (root == NULL)
		return 0;
	return root->height;
}

nbAddr rotasi_kanan(nbAddr y){
	nbAddr x = y->left;
	nbAddr T2 = x->right;

	x->right = y;
	y->left = T2;

    // Melakukan Update Height karena ada perubahan dari rotasi.
	y->height = max(height_node(y->left), height_node(y->right))+1;
	x->height = max(height_node(x->left), height_node(x->right))+1;
	return x;
}

nbAddr rotasi_kiri(nbAddr x){
	nbAddr y = x->right;
	nbAddr T2 = y->left;

	y->left = x;
	x->right = T2;

	// Melakukan Update Height karena ada perubahan dari rotasi.
	x->height = max(height_node(x->left), height_node(x->right))+1;
	y->height = max(height_node(y->left), height_node(y->right))+1;
	return y;
}

int get_different(nbAddr N){
	if (N == NULL)
		return 0;
	return height_node(N->left) - height_node(N->right);
}

nbAddr input_node(nbAddr node, int value){
	// Umumnya Proses Input sama seperti BST, Perbedaan pada modul ini yaitu melakukan otomatis Balancing setelah Input.
	if (node == NULL)
		return(build_node(value));
	if (value < node->info)
		node->left = input_node(node->left, value);
	else if (value > node->info)
		node->right = input_node(node->right, value);
	else
		return node;

	// Melakukan Update Height setelah proses input kedalam tree.
	node->height = 1 + max(height_node(node->left),height_node(node->right));

	// Mendapatkan selisih antara node kiri dan kanan.
	int balance = get_different(node);

	// Left Left Case
	if (balance > 1 && value < node->left->info)
		return rotasi_kanan(node);

	// Right Right Case
	if (balance < -1 && value > node->right->info)
		return rotasi_kiri(node);

	// Left Right Case
	if (balance > 1 && value > node->left->info){
		node->left = rotasi_kiri(node->left);
		return rotasi_kanan(node);
	}

	// Right Left Case
	if (balance < -1 && value < node->right->info){
		node->right = rotasi_kanan(node->right);
		return rotasi_kiri(node);
	}

	return node;
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
