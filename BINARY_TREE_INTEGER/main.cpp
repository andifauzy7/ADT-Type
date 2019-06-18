#include "nbtree_d.h"

int main(){

	nbAddr First;
	struct Node *First2 = NULL;
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

	nbAddr pertama=NULL;
	pertama = input_node(pertama,20);
	pertama = input_node(pertama,15);
	pertama = input_node(pertama,30);
	pertama = input_node(pertama,10);
	pertama = input_node(pertama,18);
	pertama = input_node(pertama,25);
	pertama = input_node(pertama,40);
	pertama = input_node(pertama,17);
	pertama = input_node(pertama,35);
	pertama = input_node(pertama,38);
	pertama = input_node(pertama,50);

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
