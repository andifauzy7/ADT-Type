/* File          : ADT_SLL_INT.cpp */
/* Deskripsi     : ADT linked list dengan representasi fisik pointer (Dinamis) InfoType adalah Karakter */
/* Dibuat oleh   : Ade Chandra N. (Dosen JTK Polban) */
/* Modified oleh : Andi Fauzy D. JTK'18 */

#include "ADT_SLL_INT.h"

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
          printf("%c ", p->info);
          p = p->next;
     }
    printf("%c", p->info);
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
    *p=bantu->next;
    *X=bantu->info;
    free(bantu);
}

void Del_Akhir (address * p, infotype * X){
/* IS : P TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
    address bantu;
    address bantu2;
    int i=1;
    bantu=*p;
    while(bantu->next!=NULL){
        bantu=bantu->next;
        i++;
    }
    bantu=*p;
    int n=1;
    while(n<=i-2 && bantu->next!=NULL){
        bantu=bantu->next;
        n++;
    }
    bantu2=bantu;
    bantu2->next=NULL;
    *X=bantu->info;
    free(bantu);
}

void Del_After (address * pBef, infotype * X){
/* IS : pBef TIDAK Kosong (hasil search posisi node sebelum yang didel)*/
/* FS : menghapus Node setelah pBef */
/* nilai info node yang dihapus disimpan pada X */
    address bantu;
    bantu=*pBef;
    *pBef=bantu->next;
    *X=bantu->next->info;
    bantu->next=bantu->next->next;
    pBef=NULL;
    free(pBef);
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
    address q, sebelum, sesudah;
    sebelum=NULL;
    sesudah=NULL;
    q=p;
    while(q!=NULL){
        sesudah=q->next;
        q->next=sebelum;
        sebelum=q;
        q=sesudah;
    }
    p=sebelum;
    return p;
}
