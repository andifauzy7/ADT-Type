/* File          : ADT_SLL_INT.cpp */
/* Deskripsi     : ADT linked list dengan representasi fisik pointer (Dinamis) InfoType adalah Karakter */
/* Dibuat oleh   : Ade Chandra N. (Dosen JTK Polban) */
/* Modified oleh : Andi Fauzy D. JTK'18 */

#ifndef ADT_SLL_INT_H
#define ADT_SLL_INT_H

// Header yang dibutuhkan.
#include <stdio.h>
#include <malloc.h>

// Deklarasi konstanta sebagai boolean.
#define true 1
#define false 0
#define boolean unsigned char

// Kamus Data.
typedef char infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
 infotype info;
 address next;
 } ElmtList;

boolean isEmpty(address p);
// Tujuan : memeriksa apakah linked masih kosong

void Create_Node (address *p);
// Tujuan : memesan memory dengan alokasi dinamis
// Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL

void Isi_Node (address *p , infotype nilai);
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan

void Tampil_List (address p);
// Tujuan : Menampilkan seluruh isi Linked List
// Parameter : p (parameter input)

void Ins_Awal (address *p, address PNew);
// Tujuan : Insert 1 node baru (PNew) di awal Linked List
// Parameter : P (input-output)

void Ins_Akhir (address *p, address PNew);
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */

address Search (address p, infotype nilai);
/* Mencari apakah ada elemen list dengan Info(P) = nilai */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */

void InsertAfter (address * pBef, address PNew);
/* Tujuan : Menyambungkan 1 Node baru(PNew) stlah node tertentu(PBef) */
/* IS : pBef sudah dialokasi */
/* FS : Insert PNew sebagai elemen sesudah PBef */

void Del_Awal (address * p, infotype * X);
/* IS : P TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */

void Del_Akhir (address * p, infotype * X);
/* IS : P TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */

void Del_After (address * pBef, infotype * X);
/* IS : pBef TIDAK Kosong (hasil search posisi node sebelum yang didel)*/
/* FS : menghapus Node setelah pBef */
/* nilai info node yang dihapus disimpan pada X */

void DeAlokasi (address * p);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */

int NbElmt (address p);
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong (Recursif Mode) */

address BalikList (address p);
/* IS : p sembarang */
/* FS : Elemen List dibalik : elemen terakhir menjadi elemen pertama, dst
*/

#endif

