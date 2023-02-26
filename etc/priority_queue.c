/**
 * Implementasi ADT PriorityQueue menggunakan Linked List
 * [default: minimum priority]
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C
 * 
 * !!NOTE!!
 * cara menggunakan lihat pada fungsi main()
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct{
    int prio_penyakit,isnjeroruang;
    char nama[6];
}Pasien;

typedef struct pqueueNode_t {
    Pasien data;
    struct pqueueNode_t *next;
} PQueueNode;

/* Struktur ADT PriorityQueue menggunakan Linked List */

// Prioritas default: nilai minimum
typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

/* Function prototype */

void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, Pasien value);
void pqueue_pop(PriorityQueue *pqueue);
Pasien  pqueue_top(PriorityQueue *pqueue);
int  comp(Pasien *x, Pasien *y);

/* Function definition below */

int comp(Pasien *x, Pasien *y){
    return(
        !x->isnjeroruang &&
        x->prio_penyakit >= y->prio_penyakit &&
        strcmp(x->nama,y->nama) < 0
    );
}

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, Pasien value)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if(comp(&value, &pqueue->_top->data)){
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }

    // if (value < pqueue->_top->data) {
    //     newNode->next = pqueue->_top;
    //     pqueue->_top = newNode;
    // }

    else {
        while (temp->next != NULL && comp(&temp->next->data,&value))       
        // while ( temp->next != NULL && 
        //         temp->next->data < value)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

Pasien pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->data;
    // else return NULL;
}

int main(int argc, char const *argv[])
{
    // Buat objek PriorityQueue
    PriorityQueue myPque;

    // PENTING! Jangan lupa diinisialisasi
    pqueue_init(&myPque);
    Pasien pasien;
    int ruang,q,tersedia,jumlahpenyakit[5];
    char penyakit[50],nama[6];
    scanf("%d",&ruang);
    Pasien inRuang[ruang];
    tersedia = ruang;
    memset(jumlahpenyakit,0,sizeof(jumlahpenyakit));
    while (scanf("%d",&q))
    {
        if(q==1){
            scanf("%s%s",nama,penyakit);
            if(*penyakit=='p') pasien.prio_penyakit = 4;
            else if(*penyakit=='d') pasien.prio_penyakit = 3;
            else if(*penyakit=='m') pasien.prio_penyakit = 2;
            else if(*penyakit=='f') pasien.prio_penyakit = 1;
            jumlahpenyakit[pasien.prio_penyakit]++;
            pasien.isnjeroruang = 0;
            printf("Pasien atas nama %s terdaftar dalam database\n",nama);
            strcpy(pasien.nama,nama);
            if(tersedia){
                tersedia--;
                //print langsung masuk
                pasien.isnjeroruang = 1;
                printf("Pasien atas nama %s langsung masuk.\n",pasien.nama);
            } else {
                //print antri
                printf("Pasien atas nama %s mengantri.\n",pasien.nama);
            }
            pqueue_push(&myPque,pasien);
        } else {
            tersedia++;
            pasien = pqueue_top(&myPque);
            if(pasien.isnjeroruang){
                if(pasien.prio_penyakit==1)
                    printf("Pasien atas nama %s sudah selesai konsultasi mengenai flu",pasien.nama);
                else if(pasien.prio_penyakit==2)
                    printf("Pasien atas nama %s sudah selesai konsultasi mengenai maag",pasien.nama);
                else if(pasien.prio_penyakit==3)
                    printf("Pasien atas nama %s sudah selesai konsultasi mengenai diare",pasien.nama);
                else if(pasien.prio_penyakit==4)
                    printf("Pasien atas nama %s sudah selesai konsultasi mengenai pusingkebanyakantugas",pasien.nama);
                if( myPque._size > (ruang - tersedia) ){
                    printf
                }
            }
            //print sudah selesai
            pqueue_pop(&myPque);
        }
    }
    
    return 0;
}