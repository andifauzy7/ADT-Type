#include "ADT_SLL_INT.h"
int menu();
void insert_node(address *p);
void delete_node(address *p);
void search_node(address p);

int main(){
    address First;
    Create_Node(&First);
    char nilai;
    int pilihan;
    for(;;){
        switch(menu()){
            case 1:{
                // Insert Node.
                insert_node(&First);
                break;
            }
            case 2:{
                // Delete Node.
                delete_node(&First);
                break;
            }
            case 3:{
                // Jumlah Node.
                // Default adalah 1 Karena sebelumnya telah dibuat sebuah Node yang diisi NOL.
                printf("\n\tJumlah Node Dalam List : %d",NbElmt(First));
                break;
            }
            case 4:{
                // Cari Node.
                search_node(First);
                break;
            }
            case 5:{
                // Balik List.
                First=BalikList(First);
                break;
            }
            case 6:{
                // Tampil List.
                printf("\n\t");
                Tampil_List(First);
                break;
            }
            case 7:{
                exit(1);
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
    printf("\n\t6. Tampilkan List");
    printf("\n\t7. Keluar");
    printf("\n\n\tPilihan = ");
    scanf(" %d",&pilihan);
    if(pilihan<=0 || pilihan>7){
        printf("\n\tLakukan Input yang sesuai.\n\t");
        system("pause");
        system("cls");
        goto awal;
    }
    return pilihan;
}

void insert_node(address *p){
    infotype nilai, insertafter;
    int pilihan;
    address Second;
    if((*p)->next==NULL && (*p)->info==NULL){
        printf("\n\tMasukkan Nilai Node : ");
        scanf(" %c",&nilai);
        Isi_Node(&(*p),nilai);
        printf("\n\tINSERT NODE SUKSES!");
    } else {
        printf("\n\t1. Insert di Awal.");
        printf("\n\t2. Insert Sesudah Node Tertentu.");
        printf("\n\t3. Insert di Akhir.");
        pilihperilaku:
        printf("\n\tPilih Perilaku = ");
        scanf(" %d",&pilihan);
        printf("\n\tMasukkan Nilai Node : ");
        Create_Node(&Second);
        scanf(" %c",&nilai);
        Isi_Node(&Second,nilai);
        switch(pilihan){
            case 1:{
                Ins_Awal(&(*p),Second);
                printf("\n\tINSERT NODE SUKSES!");
                break;
            }
            case 2:{
                printf("\n\tInsert setelah Node : ");
                scanf(" %c",&insertafter);
                if(Search((*p),insertafter)!=NULL){
                    InsertAfter(&(*p),Second);
                    printf("\n\tINSERT NODE SUKSES!");
                } else {
                    printf("\n\tNode tidak ditemukan!\n\t");
                }
                break;
            }
            case 3:{
                Ins_Akhir(&(*p),Second);
                printf("\n\tINSERT NODE SUKSES!");
                break;
            }
            default:{
                printf("\n\tPilih menu sesuai.\n\t");
                system("pause");
                goto pilihperilaku;
                break;
            }
        }
    }
}

void delete_node(address *p){
    int pilihan;
    infotype X, deleteafter;
    address cari;
    if((*p)->info==NULL && (*p)->next==NULL){
        printf("\n\tLIST KOSONG.");
    } else {
        printf("\n\t1. Delete di Awal.");
        printf("\n\t2. Delete Sesudah Node Tertentu.");
        printf("\n\t3. Delete di Akhir.");
        printf("\n\tPilih Perilaku = ");
        scanf(" %d",&pilihan);
        switch(pilihan){
            case 1:{
                Del_Awal(&(*p),&X);
                break;
            }
            case 2:{
                printf("\n\tDelete setelah Node : ");
                scanf(" %c",&deleteafter);
                cari=Search((*p),deleteafter);
                if(cari!=NULL){
                    Del_After(&cari,&X);
                } else {
                    printf("\n\tNode tidak ditemukan!\n\t");
                }
            break;
            }
            case 3:{
                Del_Akhir(&(*p),&X);
                break;
            }
            default:{

            break;
            }
        }
    }
}

void search_node(address p){
    infotype cari;
    printf("\n\tNode yang ingin dicari : ");
    scanf(" %c",&cari);
    if(Search(p,cari)!=NULL){
        printf("\n\tNode Ditemukan!");
    } else {
        printf("\n\tNode Tidak Ditemukan!");
    }
}

