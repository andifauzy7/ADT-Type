#include "nbtree_d.h"

void tampil(nbAddr root);
void insert_node_avl(nbAddr *root, nbAddr *original_root, int value);

int main(){

	nbAddr First,pertama;
	First=pertama=NULL;
	create_node(&First);

	insert_node_avl(&pertama,&First,20);
	insert_node_avl(&pertama,&First,15);
	insert_node_avl(&pertama,&First,30);
	insert_node_avl(&pertama,&First,10);
	insert_node_avl(&pertama,&First,18);
	insert_node_avl(&pertama,&First,25);
	insert_node_avl(&pertama,&First,40);
	insert_node_avl(&pertama,&First,17);
	insert_node_avl(&pertama,&First,35);
	insert_node_avl(&pertama,&First,38);
	insert_node_avl(&pertama,&First,50);

    tampil(First);
    tampil(pertama);

	Delete(First,40);
	tampil(First);



	return 0;
}

void tampil(nbAddr root){
    printf("Post Order\t: ");
	nbPost(root);
	printf("\n");
	printf("Pre Order\t: ");
	nbPre(root);
	printf("\n");
	printf("In Order\t: ");
	nbIn(root);
	printf("\n");
	printf("Lv Order\t: ");
	print_level(root);
	printf("\nDepth\t\t: "); printf("%d",nbDepth(root));
	printf("\n\n");
}

void insert_node_avl(nbAddr *root, nbAddr *original_root, int value){
    (*root) = input_node((*root),value);
    insert_node(&(*original_root),value);
}

