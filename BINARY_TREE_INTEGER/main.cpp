#include "nbtree_d.h"

void tampil(nbAddr root);
void insert_node_avl(nbAddr *root, nbAddr *original_root, int value);
int menu();

int main(){
    int value;
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

	printf("\n\tTree Pertama - Tanpa Balancing\n");
    tampil(First);
    printf("\n\tTree Kedua - Sudah Dilakukan Balancing\n");
    tampil(pertama);

    printf("\n\tMelakukan Input Sendiri ...\n\t");
    system("pause");
    system("cls");

    for(;;){
        switch(menu()){
            case 1:{
                printf("\n\tMasukkan Nilai : ");
                scanf(" %d",&value);
                insert_node_avl(&pertama,&First,value);
                printf("\n\tTree Pertama - Tanpa Balancing\n");
                tampil(First);
                printf("\n\tTree Kedua - Sudah Dilakukan Balancing\n");
                tampil(pertama);
                system("pause");
                system("cls");
                break;
            }
            case 2:{
                printf("\n\tMasukkan Nilai Delete : ");
                scanf(" %d",&value);
                if(nbSearch(First,value)==NULL){
                    printf("\tNilai Tidak Ditemukan\n\t");
                } else {
                    Delete(First,value);
                    Delete(pertama,value);
                    printf("\tDelete Berhasil\n\t");
                }
                printf("\n\tTree Pertama - Tanpa Balancing\n");
                tampil(First);
                printf("\n\tTree Kedua - Sudah Dilakukan Balancing\n");
                tampil(pertama);
                system("pause");
                system("cls");
                break;
            }
            case 3:{
                exit(1);
                break;
            }
            default:{
                break;
            }
            printf("\n\t");
        }

    }

	return 0;
}

void tampil(nbAddr root){
    printf("\tPost Order\t: ");
	nbPost(root);
	printf("\n");
	printf("\tPre Order\t: ");
	nbPre(root);
	printf("\n");
	printf("\tIn Order\t: ");
	nbIn(root);
	printf("\n");
	printf("\tLv Order\t: ");
	print_level(root);
	printf("\n\tDepth\t\t: "); printf("%d",nbDepth(root));
	printf("\n\n");
}

void insert_node_avl(nbAddr *root, nbAddr *original_root, int value){
    (*root) = input_node((*root),value);
    insert_node(&(*original_root),value);
}

int menu(){
    int nilai;
    awal:
    printf("\n\tProgram Binary Tree - AVL\n");
    printf("\t1A - D3 Teknik Informatika\n");
    printf("\t> Andi Fauzy Dewantara 181511007\n");
    printf("\t> Fahmi Widianto       181511012\n");
    printf("\n\t1.Input Tree");
    printf("\n\t2.Delete Tree");
    printf("\n\t3.Keluar");
    printf("\n\tPilihan Anda : ");
    scanf(" %d",&nilai);
    if(nilai<=0 || nilai>3){
        system("cls");
        goto awal;
    } else {
        return nilai;
    }
}
