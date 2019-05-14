/*
NAMA			: MEIRA DWIANA ANJANI
NPM				: 140810180015
KELAS			: A
TANGGAL BUAT	: 14 MEI 2019
NAMA PROGRAM	: EXERCISE02 PRAKTIKUM
*/

#include<iostream>
using namespace std;

struct ElemenQueue {
    char info;
    ElemenQueue* next;
};
typedef ElemenQueue* pointer;
typedef pointer List;

struct Queue {
    List Head;
    List Tail;
};
Queue Q;

void CreateList(Queue& Q){
	Q.Head = NULL;
    Q.Tail = NULL;
}

void CreateElemt(pointer& pBaru){
	pBaru=new ElemenQueue;
	cout<<"Input : ";
	cin>>pBaru->info;
	pBaru->next=NULL;
}

void Cetak(Queue Q){
    pointer pBantu=Q.Head;
    if(Q.Head == NULL && Q.Tail == NULL){
        cout << "\n\t***Data masih kosong***" << endl;
    }else{
        while(pBantu != NULL){
            cout << pBantu->info;
            pBantu=pBantu->next;
        }
    }
}


void InsertQueue( Queue& Q, pointer pBaru){
    if (Q.Head==NULL && Q.Tail==NULL) { // kosong
        Q.Head = pBaru;
        Q.Tail = pBaru;
    }
    else { // ada isi
        Q.Tail->next = pBaru;
        Q.Tail = pBaru;
    }
}

void DeleteQueue(Queue& Q, pointer& pHapus){
    if (Q.Head==NULL && Q.Tail==NULL) { //kasus kosong
        pHapus=NULL;
        cout<<"List Queue kosong "<<endl;
    }
    else if (Q.Head->next==NULL) { // kasus isi 1 elemen
        pHapus=Q.Head;
        cout << "\nElemen yang dihapus\t" << pHapus->info<< endl;
        Q.Head=NULL;
        Q.Tail=NULL;
    }
    else { // kasus > 1 elemen
        pHapus=Q.Head;
        cout << "\nElemen yang dihapus\t" << pHapus->info<< endl;
        Q.Head=Q.Head->next;
        pHapus->next=NULL;
    }
}

int main(){
    Queue Q;
    pointer pBaru,pHapus;
    List l;
    int x;

    CreateList(Q);
    cout<<"BANYAK ELEMEN : ";cin>>x;
    for(int i=0; i<x; i++)
    {
        CreateElemt(pBaru);
        InsertQueue(Q,pBaru);
    }
    cout <<endl;
    cout << "POP ELEMEN : "<<endl;
    for(int i=0;i<x;i++){
    DeleteQueue(Q,pHapus);
    }
}

