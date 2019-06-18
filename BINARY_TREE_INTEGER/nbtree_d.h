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
	nbType info,height;
}ElmtTree;


/* ---------------- Alokasi node baru Tree ---------------- */
void create_node(nbAddr *root);             // Untuk BST Mode.
nbAddr build_node(nbType value);            // Untuk AVL Mode.

/* ---------------- Operasi-operasi Tree ---------------- */
void insert_node(nbAddr *root, nbType X);   // Procedure untuk merubah Root.
nbAddr input_node(nbAddr node, int value);  // Membuat Node dengan Rekursif Mode dengan auto Balancing.

nbAddr value_minimum(nbAddr root);          // Mencari Nilai Minimum untuk keperluan DELETE.

nbAddr nbSearch(nbAddr root, nbType src);   // Mencari node dengan info ttn dan mengembalikan addressnya

int nbDepth(nbAddr root);
int height_node(nbAddr root);               // Mengukur kedalaman suatu node dari root

nbAddr Delete(nbAddr root, int value);
// Menghapus sebuah node

/* ---------------- TRAVERSAL Tree ---------------- */
void nbPost(nbAddr root);                   // Postorder traversing
void nbPre(nbAddr root);                    // Preorder traversing
void nbIn(nbAddr root);                     // Inorder traversing
void nbLevelOrder(nbAddr root,int level);   // Levelorder traversing
void print_level(nbAddr root);

/* Modul Pembantu */

int max(int a, int b);                      // Mencari nilai tertinggi dari 2 bilangan. (Untuk node kiri dan kanan)
nbAddr rotasi_kanan(nbAddr y);              // Rotasi Tree ke kanan
nbAddr rotasi_kiri(nbAddr x);               // Rotasi Tree ke kiri
int get_different(nbAddr N);                // Mencari selisih antara 2 node kiri dan kanan untuk keperluan Balancing.

#endif
