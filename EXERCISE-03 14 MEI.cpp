/*
NAMA			: MEIRA DWIANA ANJANI
NPM				: 140810180015
KELAS			: A
TANGGAL BUAT	: 14 MEI 2019
NAMA PROGRAM	: EXERCISE03 PRAKTIKUM
*/

#include<iostream>
using namespace std;

struct Simpul{
    int info;
    Simpul* left;
    Simpul* right;
};
typedef Simpul* pointer;
typedef pointer Tree;

void createSimpul(pointer& pBaru){
    pBaru=new Simpul;
    cin>>pBaru->info;
    pBaru->left=NULL;
    pBaru->right=NULL;
}
void insertBST (Tree& Root, pointer pBaru){
    if(Root==NULL){
        Root=pBaru;
    }
    else if (pBaru->info < Root->info){
        insertBST(Root->left,pBaru);
    }
    else if (pBaru->info > Root->info){
        insertBST(Root->right,pBaru);
    }
    else{
        cout<<"Sudah ada"<<endl;
    }
}
void preOrder (Tree Root) {
    if (Root != NULL){
        cout<< Root->info <<" ";
        preOrder(Root->left);
        preOrder(Root->right);
    }
}
void inOrder (Tree Root) {
    if (Root != NULL){
        inOrder(Root->left);
        cout<< Root->info <<" ";
        inOrder(Root->right);
    }
}
void postOrder (Tree Root) {
    if (Root != NULL){
        postOrder(Root->left);
        postOrder(Root->right);
        cout<< Root->info <<" ";
    }
}

void notKurung(Tree Root){
	if (Root != NULL){
	    cout << "(" << Root->info << " ";
	    notKurung(Root->left);
	    notKurung(Root->right);
	    cout << ")";
	}
}


int main(){	
	Tree Root;
    pointer p;
    Root=NULL;
    
    for (int i=0;i<9;i++){
    	cout<<"Input : ";
        createSimpul(p);
        insertBST(Root,p);
	}
	cout<<"Notasi Kurung : ";notKurung(Root);cout<<endl;
	cout<<"Pre Order : ";preOrder(Root);cout<<endl;
	cout<<"In Order : ";inOrder(Root);cout<<endl;
	cout<<"Post Order : ";postOrder(Root);cout<<endl;
}
