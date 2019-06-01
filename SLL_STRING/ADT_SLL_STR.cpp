/* File          : ADT_SLL_STR.cpp */
/* Deskripsi     : ADT linked list dengan representasi fisik pointer (Dinamis) InfoType adalah String */
/* Dibuat oleh   : Ade Chandra N. (Dosen JTK Polban) */
/* Modified oleh : Andi Fauzy D. JTK'18 */

#include "ADT_SLL_STR.h"

boolean isEmpty(address p){
// Tujuan : memeriksa apakah linked masih kosong
	if(p==NULL){
		true;
	} else {
		false;
	}
}

void Create_Node (address *p){
// Tujuan : memesan memory dengan alokasi dinamis
    *p=(address)malloc(sizeof(ElmtList));
    strcpy((*p)->info,"0");
    (*p)->next=NULL;
}

void Isi_Node (address *p , infotype nilai){
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
    strcpy((*p)->info,nilai);
    (*p)->next=NULL;
}

void Tampil_List (address p){
// Tujuan : Menampilkan seluruh isi Linked List
     while(p->next != NULL) {
          printf("%s, ", p->info);
          p = p->next;
     }
    printf("%s", p->info);
}

void Ins_Awal (address *p, address PNew){
// Tujuan : Insert 1 node baru (PNew) di awal Linked List
    PNew->next=*p;
    *p=PNew;
}

void Ins_Akhir (address *p, address PNew){
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */
         address bantu;
         bantu=*p;
         while(bantu->next!=NULL){
            bantu=bantu->next;
         }
         bantu->next=PNew;
         PNew->next=NULL;
}

address Search (address p, infotype nilai){
/* Mencari apakah ada elemen list dengan Info(P) = nilai */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
    address bantu;
    boolean ketemu;
        ketemu=false;
        bantu=p;
        while(!ketemu && bantu!=NULL){
            if(strcmp(bantu->info,nilai)==0){
                ketemu=true;
            } else {
                bantu=bantu->next;
            }
        }
        if(ketemu==true){
            return bantu;
        } else {
            return NULL;
        }
}

void InsertAfter (address * pBef, address PNew){
/* Tujuan : Menyambungkan 1 Node baru(PNew) stlah node tertentu(PBef) */
    address bantu;
    bantu=*pBef;

    PNew->next=bantu->next;
    bantu->next=PNew;
}

void Del_Awal (address * p, infotype * X){
/* IS : P TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
    address bantu;
    bantu=*p;
    if(bantu->next!=NULL){
        *p=bantu->next;
        strcpy(*X,bantu->info);
        free(bantu);
        printf("\n\tDELETE NODE SUKSES!");
    } else {
        printf("\n\tNode hanya 1, Tambah Node Terlebih Dahulu");
    }
}

void Del_Akhir (address * p, infotype * X){
/* IS : P TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
    address bantu,bantu2;
    bantu=*p;
    if(bantu->next!=NULL){
        while(bantu->next->next!=NULL){
            bantu=bantu->next;
        }
        bantu2=bantu->next;
        bantu->next=NULL;
        strcpy(*X,bantu2->info);
        free(bantu2);
        printf("\n\tDELETE NODE SUKSES!");
    } else {
        printf("\n\tNode hanya 1, Tambah Node Terlebih Dahulu");
    }
}

void Del_After (address * pBef, infotype * X){
/* IS : pBef TIDAK Kosong (hasil search posisi node sebelum yang didel)*/
/* FS : menghapus Node setelah pBef */
/* nilai info node yang dihapus disimpan pada X */
    address bantu;
    bantu=*pBef;
    if(bantu->next!=NULL){
        *pBef=bantu->next;
        strcpy(*X,bantu->next->info);
        bantu->next=bantu->next->next;
        pBef=NULL;
        free(pBef);
        printf("\n\tDELETE NODE SUKSES!");
    } else {
        printf("\n\tTidak Memiliki Node Setelahnya!");
    }

}

void DeAlokasi (address * p){
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
free(*p);
*p=NULL;
}

int NbElmt (address p){
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong */
if(p==NULL){
    return 0;
}
return 1 + NbElmt(p->next);
}

address BalikList (address p){
/* IS : p sembarang */
/* FS : Elemen List dibalik : elemen terakhir menjadi elemen pertama, dst */
    address awal_head, head2, isi;
    awal_head=p;
    if(awal_head->next!=NULL){
        Create_Node(&head2);
        Isi_Node(&head2,awal_head->info);
        while(awal_head->next!=NULL){
            awal_head=awal_head->next;
            Create_Node(&isi);
            Isi_Node(&isi,awal_head->info);
            Ins_Awal(&head2,isi);
        }
        printf("\n\tBALIK LIST BERHASIL!");
        return head2;
    } else {
        printf("\n\tHanya Memiliki 1 Node (Tidak Bisa Dibalik)");
        return 0;
    }
}

