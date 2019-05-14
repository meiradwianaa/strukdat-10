/*
NAMA			: MEIRA DWIANA ANJANI
NPM				: 140810180015
KELAS			: A
TANGGAL BUAT	: 14 MEI 2019
NAMA PROGRAM	: EXERCISE01 PRAKTIKUM
*/
#include <iostream>

using namespace std;

const int maxElemen = 255;
struct Queue{
    char isi[maxElemen];
    int head; // depan
    int tail; // belakang
};
void CreateQueue(Queue& Q){
    Q.head = 0;
    Q.tail = -1;
}

void CreateElement(char& elemen){
    cout<<"Input: ";cin>>elemen;
}

void InsertQueue(Queue& Q, char elemen) {
    if (Q.tail==maxElemen-1){
        cout<<"Antrian sudah penuh"<<endl;
    }
    else {
        Q.tail=Q.tail + 1;
        Q.isi[Q.tail] = elemen;
    }
}

void DeleteQueue(Queue& Q, char& elemenHapus){
    if (Q.head>Q.tail){ // atau Q.tail=-1
        cout<<"Antrian kosong"<<endl;
    }
    else {
        elemenHapus= Q.isi[Q.head];
        cout << elemenHapus; //Q.head=0
        for (int i=0;i<Q.tail;i++){ // Geser ke depan
            Q.isi[i]=Q.isi[i+1];
        }
        Q.tail=Q.tail-1;
    }
}

void Reverse(Queue Q){
	int i;
	if (Q.head == - 1)
	cout<<"Queue is empty"<<endl;
	else {
    	for (int i = Q.tail; i >= Q.head; i--){
    		cout<<Q.isi[i];
        	if(i==Q.head)break;
        	cout<<",";
        }
    }
}

void Display(Queue Q){
    int i;
   if (Q.head == - 1)
   cout<<"Queue is empty"<<endl;
   else {
      for (int i = Q.head; i <= Q.tail; i++){
        cout<<Q.isi[i];
        if(i==Q.tail)break;
        cout<<",";
        }
    }
}

int main()
{
    Queue Q;
    char elemenHapus,elemen;
    int x;
    CreateQueue(Q);
    cout << "BANYAK ELEMEN : ";cin >> x;
    for(int i=0;i<x;i++){
        CreateElement(elemen);
        InsertQueue(Q,elemen);
    }
    cout << endl;
    cout << "POP ELEMEN :"<<endl;
    for(int i=0;i<x;i++){
        DeleteQueue(Q,elemenHapus);
        cout << endl;
    }
    return 0;
}


