/*
File	: nbtree_d.h
Author	: SN
Last Updt : 25-5-2011
*/

#ifndef nbtree_d_H
#define nbtree_d_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"

typedef struct nbTreeNode *nbAddr;
typedef int nbType;

typedef struct nbTreeNode{
	nbAddr left,right;
	nbType info;
}ElmtTree;

struct nbTree{
	nbAddr root;
};

/* ---------------- Alokasi node baru Tree ---------------- */
void create_node(nbAddr *root);
//Alokasi untuk membuat node baru

/* ---------------- Operasi-operasi Tree ---------------- */
void insert_node(nbAddr *root, nbType X);
// Menambah element pada node parent

nbAddr value_minimum(nbAddr root);
// Mencari Nilai Minimum untuk keperluan DELETE.

nbAddr find_parents(nbAddr root, nbType value);
nbAddr nbSearch(nbAddr root, nbType src);
// Mencari node dengan info ttn dan mengembalikan addressnya

void nbUpgrade(nbAddr *root);
// Mengupgrade parent dari beberapa node. (digunakan pada proses penghapusan)

void nbDelete(nbAddr *pDel, nbTree *pTree);
// Menghapus node tertentu dan digantikan oleh fs dari node tsb

int nbDepth(nbAddr root);
// Mengukur kedalaman suatu node dari root

/* ---------------- TRAVERSAL Tree ---------------- */
void nbPost(nbAddr root); // Postorder traversing
void nbPre(nbAddr root); // Preorder traversing
void nbIn(nbAddr root); // Inorder traversing
void nbLevelOrder(nbAddr root,int level); // Levelorder traversing
void print_level(nbAddr root);

void delete_node(nbTree *pTree);
/* Asumsi penghapusan node seperti silsilah kerajaan Inggris, dimana pewaris adalah son pertama,
   Apabila son pertama tidak ada, maka digunakanlah NEXT BROTHER sebagai pewaris sementara. */


#endif
