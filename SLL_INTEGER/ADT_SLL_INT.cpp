/* File : H_KSLLA07.cpp */
/* Deskripsi : ADT linked list dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* InfoType adalah char */
/* Dibuat oleh : Ade Chandra Nugraha */

#include "ADT_SLL_INT.h"

boolean isEmpty(address p){
// Tujuan : memeriksa apakah linked masih kosong
// Linked list kosong , jika Head == NULL
	if(p==NULL){
		true;
	} else {
		false;
	}
}

void Create_Node (address *p){
// Tujuan : memesan memory dengan alokasi dinamis
// Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL
// Parameter : P (parameter Output)
    *p=(address)malloc(sizeof(ElmtList));
    (*p)->info=NULL;
    (*p)->next=NULL;
}
void Isi_Node (address *p , infotype nilai){
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
// Periksa keberadaan P, Nilai diisi jika P tidak NULL
// *p.next diisi NULL
// Parameter : P (parameter Input-Output); Nilai (parameter Input)
    (*p)->info=nilai;
    (*p)->next=NULL;
}
void Tampil_List (address p){
// Tujuan : Menampilkan seluruh isi Linked List
// Parameter : p (parameter input)
     while(p->next != NULL) {
          printf("%c ", p->info);
          p = p->next;
     }
    printf("%c", p->info);
}
void Ins_Awal (address *p, address PNew){
// Tujuan : Insert 1 node baru (PNew) di awal Linked List
// Parameter : P (input-output)
// PNew (input)
    PNew->next=*p;
    *p=PNew;
}
void Ins_Akhir (address *p, address PNew){
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */
/* IS : p mungkin Kosong */
/* FS : menyambungkan elemen baru (PNew) di akhir Linked List */
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
/* Menggunakan variabel bertype boolean */
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
/* IS : pBef sudah dialokasi */
/* FS : Insert PNew sebagai elemen sesudah PBef */
/* Asumsi : pBef adalah posisi insert */
    address bantu;
    bantu=*pBef;

    PNew->next=bantu->next;
    bantu->next=PNew;
}
void Del_Awal (address * p, infotype * X){
/* IS : P TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* dan alamat elemen pertama di dealokasi */
    address bantu;
    bantu=*p;
    *p=bantu->next;
    *X=bantu->info;
    free(bantu);
}
void Del_Akhir (address * p, infotype * X){
/* IS : P TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* dan alamat elemen terakhir di dealokasi */
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
/* dan alamat elemen setelah pBef di dealokasi */
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
/* Melakukan dealokasi / pengembalian address P ke system */
free(*p);
*p=NULL;
}
int NbElmt (address p){
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong */
// Recursif Mode
if(p==NULL){
    return 0;
}
return 1 + NbElmt(p->next);
}

address BalikList (address p){
/* IS : p sembarang */
/* FS : Elemen List dibalik : elemen terakhir menjadi elemen pertama, dst
*/
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

