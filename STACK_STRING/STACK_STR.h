/* File          : STACK_STR.h */
/* Deskripsi     : ADT Stack / Tumpukan dengan representasi fisik pointer (Dinamis) InfoType adalah String */
/* Dibuat oleh   : Ade Chandra N. (Dosen JTK Polban) */
/* Modified oleh : Andi Fauzy D. JTK'18 */

#ifndef STACK_STR_H
#define STACK_STR_H

// Header yang dibutuhkan.
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// Deklarasi konstanta sebagai boolean.
#define true 1
#define false 0
#define MAX 30
#define boolean unsigned char

// Kamus Data.
typedef char infotype[30];
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

address Search (address p, infotype nilai);
/* Mencari apakah ada elemen list dengan Info(P) = nilai */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */

void Del_Awal (address * p, infotype * X);
/* IS : P TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */

void DeAlokasi (address * p);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */

int NbElmt (address p);
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong (Recursif Mode) */

#endif

