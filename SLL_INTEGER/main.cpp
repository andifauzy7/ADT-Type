#include "ADT_SLL_INT.h"
int menu();

int main(){
    address First;
    Create_Node(&First);
    char nilai;
    for(;;){
        switch(menu()){
            case 1:{
            // Insert Node.
            printf("%d",isEmpty(First));
            }
            case 2:{

                break;
            }
            case 3:{

                break;
            }
            case 4:{

                break;
            }
            case 5:{

                break;
            }
            case 6:{

                break;
            }
            default:{
                printf("\n\tLakukan Input yang sesuai.");
                break;
            }
        }
        printf("\n\t");
        system("pause");
        system("cls");
    }
    return 0;
}

int menu(){
    int pilihan;
    awal:
    printf("\n\tADT - Single Linked List Tipe Karakter");
    printf("\n\tMenggunakan Alokasi Dinamis (Menyesuaikan Kebutuhan).");
    printf("\n\t1. Insert Node");
    // Terdapat Insert awal, akhir, dan after.
    printf("\n\t2. Delete Node");
    // Terdapat Delete awal, akhir, dan after.
    printf("\n\t3. Jumlah Node");
    printf("\n\t4. Cari Node");
    printf("\n\t5. Balik List");
    printf("\n\t6. Keluar");
    printf("\n\n\tPilihan = ");
    scanf(" %d",&pilihan);
    if(pilihan<=0 || pilihan>6){
        printf("\n\tLakukan Input yang sesuai.\n\t");
        system("pause");
        system("cls");
        goto awal;
    }
    return pilihan;
}
