#include "nbtree_d.h"

int main(){

	nbAddr First;
	create_node(&First);
	insert_node(&First,20);
	insert_node(&First,15);
	insert_node(&First,30);
	insert_node(&First,10);
	insert_node(&First,18);
	insert_node(&First,25);
	insert_node(&First,40);
	insert_node(&First,17);
	insert_node(&First,35);
	insert_node(&First,38);
	insert_node(&First,50);

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
	printf("\n\n");

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
	printf("\n\n");

	/*
    //delete_node(&MyList);
    */

	return 0;
}
