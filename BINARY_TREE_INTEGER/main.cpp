#include "nbtree_d.h"

int main(){

	nbAddr First;
	struct Node *First2 = NULL;
	create_node(&First);

	insert_node(&First,20);
	First2 = insert(First2, 20);
	insert_node(&First,15);
	First2 = insert(First2, 15);
	insert_node(&First,30);
	First2 = insert(First2, 30);
	insert_node(&First,10);
	First2 = insert(First2, 10);
	insert_node(&First,18);
	First2 = insert(First2, 18);
	insert_node(&First,25);
	First2 = insert(First2, 25);
	insert_node(&First,40);
	First2 = insert(First2, 40);
	insert_node(&First,17);
	First2 = insert(First2, 17);
	insert_node(&First,35);
	First2 = insert(First2, 35);
	insert_node(&First,38);
	First2 = insert(First2, 38);
	insert_node(&First,50);
	First2 = insert(First2, 50);

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
	postOrder(First2);
	printf("\n");
	printf("Pre Order\t: ");
	preOrder(First2);
	printf("\n");
	printf("In Order\t: ");
	inOrder(First2);
	printf("\n");
	printf("Lv Order\t: ");
    print_level_avl(First2);
    printf("\nDepth\t\t: "); printf("%d",Depth_balance(First2));
	printf("\n\n");

	return 0;
}
