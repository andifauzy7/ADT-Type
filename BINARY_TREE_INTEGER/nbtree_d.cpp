#include <limits.h>
#include <malloc.h>
#include "nbtree_d.h"
#include "boolean.h"

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

nbAddr find_parents(nbAddr root, nbType value){
	if (root!=NULL){
		if (root->left->info==value || root->right->info==value)
			return root;
		else{
		    (value > root->info) ? find_parents(root->right,value) : find_parents(root->left,value);
		}
	}
	else{
		return NULL;
	}
}
/*
void nbUpgrade(nbAddr *root){
	nbAddr temp;
	temp=(*root)->nb;
	if ((*root)->fs==NULL){
        (*root)->fs=temp;
	} else {
        (*root)->fs->nb=temp;
	}
	while(temp!=NULL){
		temp->parent=*root;
		temp=temp->nb;
	}
}

void nbDelete(nbAddr *pDel, nbTree *pTree){
	nbAddr pCur;
	pCur=*pDel;

	// Jika yang dihapus adalah Root dan tidak memiliki son.
	if (pCur==pTree->root && pCur->fs==NULL){
		pTree->root=NULL;
		return;
    // Proses langsung keluar dari modul agar tidak memproses perintah dibawahnya.
	}

	while(pCur->fs!=NULL){
		pCur=pCur->fs;
	}

	if (pCur->parent!=NULL){
		pCur->parent->fs=pCur->fs;
	}
	if (pCur->fs!=NULL){
		pCur->fs->parent=pCur->parent;
	}
	if (pCur->parent==NULL){
		pTree->root=pCur;
	}
}

void delete_node(nbTree *pTree){
	nbAddr pdel, temp, sonbaru, ujungbrother;
	nbType value;
    printf("\nNode yg di delete : ");
	scanf("%d", &value);

	if(pTree->root != NULL){
	    pdel=nbSearch(pTree->root,value);
		if(pdel->fs != NULL){
		    // Jika yang dihapus memiliki son. Menandai First-an dari node tersebut.
            temp=pdel->fs;
            if(pdel->parent==NULL){
                pTree->root=temp;
                temp->parent=NULL;
            } else {
            temp->parent=pdel->parent;
            // Jika anak pertama sama dengan anak pertama dari kakek
            if(temp->parent->fs==pdel){
                pdel->parent->fs=temp;
            }
            }
            // Menyambungkan saudara yang lebih tua dari PDEL ke TEMP (Apabila Ada)
            if(nbSearchbefore(pTree->root, pdel)!=NULL){
                nbSearchbefore(pTree->root, pdel)->nb=temp;
            }
            // Menyimpan address brother temp, nanti akan dijadikan FS.
            if(temp->nb!=NULL){
                sonbaru=temp->nb;
                if(temp->fs==NULL){
                    temp->fs=sonbaru;
                } else {
                    ujungbrother=temp->fs;
                    while(ujungbrother->nb!=NULL){
                        ujungbrother=ujungbrother->nb;
                    }
                    ujungbrother->nb=sonbaru;
                }
                temp->nb=NULL;
                sonbaru->parent=temp;
            }
            // Menyambungkan saudara yang lebik muda dari PDEL ke TEMP (Apabila Ada)
            if(pdel->nb!=NULL){
                temp->nb=pdel->nb;
                pdel->nb=NULL;
            }
            pdel->fs=NULL;
            while(sonbaru->nb!=NULL){
                sonbaru->parent=temp;
                sonbaru=sonbaru->nb;
            }
		}
		else if(pdel->fs==NULL){
            // Menyimpan Parent dari Node yang akan dihapus.
			temp=pdel->parent;
			if(temp->fs==pdel){
			    // Apabila yang didelete adalah anak pertama.
			    // FS atau Anak pertama dari Node diubah ke NextBrother.
				temp->fs=pdel->nb;
			}
			else{
				temp=temp->fs;
				// Memindahkan temp ke anak pertama dari suatu node.
				while(temp->nb != NULL ){
					if(temp->nb==pdel){
                        // Memindahkan pointer ke anak sesudah sesudahnya.
						temp->nb = temp->nb->nb;
					}
					else{
						temp=temp->nb;
					}
				}
			}
		}
		free(pdel);
	}
	else{
		printf("Tree Kosong!");
	}
}

*/

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

