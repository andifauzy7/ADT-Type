#include "nbtree_d.h"

void insert_node_avl(nbAddr *root, nbAddr *original_root, int value){
    (*root) = input_node((*root),value);
    insert_node(&(*original_root),value);
}

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

	printf("\nSebelum Dilakukan Balancing.\n");
    printf("Post Order\t: ");
	nbPost(First);
	printf("\n");
	printf("Pre Order\t: ");
	nbPre(First);
	printf("\n");
	printf("In Order\t: ");
	nbIn(First);
	printf("\n");
	printf("Lv Order\t: ");
	print_level(First);
	printf("\nDepth\t\t: "); printf("%d",nbDepth(First));
	printf("\n\n");


	printf("\nSesudah Dilakukan Balancing.\n");
    printf("Post Order\t: ");
	nbPost(pertama);
	printf("\n");
	printf("Pre Order\t: ");
	nbPre(pertama);
	printf("\n");
	printf("In Order\t: ");
	nbIn(pertama);
	printf("\n");
	printf("Lv Order\t: ");
	print_level(pertama);
	printf("\nDepth\t\t: "); printf("%d",nbDepth(pertama));
	printf("\n\n");



	return 0;
}
