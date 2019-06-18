#include "nbtree_d.h"

int main(){

	nbAddr First;
	create_node(&First);
	/*
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
	insert_node(&First,50); */

	insert_node(&First,20);
	insert_node(&First,15);
	insert_node(&First,30);
	insert_node(&First,22);
	insert_node(&First,40);
	insert_node(&First,38);
	insert_node(&First,45);


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


	nbAddr kedua;
    kedua = rotasi_kiri(&First);
    printf("Post Order\t: ");
	nbPost(kedua);
	printf("\n");
	printf("Pre Order\t: ");
	nbPre(kedua);
	printf("\n");
	printf("In Order\t: ");
	nbIn(kedua);
	printf("\n");
	printf("Lv Order\t: ");
	print_level(kedua);
	printf("\n\n");

    nbAddr ketiga=NULL;
    ketiga = insert_avl(&ketiga,5);
    printf("%d",ketiga->info);
	return 0;
}
