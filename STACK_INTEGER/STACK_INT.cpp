/* File          : STACK_INT.cpp */
/* Deskripsi     : ADT Stack / Tumpukan dengan representasi fisik pointer (Dinamis) InfoType adalah Integer */
/* Dibuat oleh   : Ade Chandra N. (Dosen JTK Polban) */
/* Modified oleh : Andi Fauzy D. JTK'18 */

#include "STACK_INT.h"

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
    (*p)->info=NULL;
    (*p)->next=NULL;
}

void Isi_Node (address *p , infotype nilai){
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
    (*p)->info=nilai;
    (*p)->next=NULL;
}

void Tampil_List (address p){
// Tujuan : Menampilkan seluruh isi Linked List
     while(p->next != NULL) {
          printf("%d ", p->info);
          p = p->next;
     }
    printf("%d", p->info);
}

void Ins_Awal (address *p, address PNew){
// Tujuan : Insert 1 node baru (PNew) di awal Linked List
    PNew->next=*p;
    *p=PNew;
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
            if(bantu->info==nilai){
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

void Del_Awal (address * p, infotype * X){
/* IS : P TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
    address bantu;
    bantu=*p;
    if(bantu->next!=NULL){
        *p=bantu->next;
        *X=bantu->info;
        free(bantu);
        printf("\n\tDELETE NODE SUKSES!");
    } else {
        printf("\n\tNode hanya 1, Tambah Node Terlebih Dahulu");
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
