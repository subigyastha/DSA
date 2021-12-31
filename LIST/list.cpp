#include <iostream>
#define MAX 10
using namespace std;

int avail;
struct lists{
    int data;
    int next;
};

lists list[MAX];

void initial_list(){
    avail=0;
    for(int i=0;i<MAX;i++){
        list[i].next=i+1;
    }
    list[MAX-1].next=-1;
}
int getnode(){
    int p;
    if(avail==-1) { cout<<"OVERFLOW"<<endl; exit(1);}
    p=avail;
    avail=list[avail].next;
    return p;
}

void freenode(int p){
    list[p].next=avail;
    avail=p;
    return;
}

void insafter(int p, int x){
    //p is position x is value
    int q;
    if(p==-1){cout<<"invalid operation"<<endl; exit(1);}
    q=getnode();
    list[q].data=x;
    list[q].next=list[p].next;
    list[p].next=q;
    cout<<"data = "<< x<<" inserted at "<< q<<endl;
}

void delafter(int p,int *x){
    int q;
    if(p==-1||list[p].next==-1){cout<<"invalid deltion"<<endl; exit(1);}
    q=list[p].next;
    *x=list[q].data;
    list[p].next=list[q].next;
    freenode(q);
}

void lister(int start){
    while(list[start].next!=-1){
        cout<<"data = "<<list[start].data<<"next = "<<list[start].next<<endl;
        start=list[start].next;
    }
}


int main(){
    initial_list();
    int start=getnode();
    list[start].data=5;
    list[start].next=-1;
    insafter(start,5);
    insafter()
    lister(start);
    //cout<<getnode();
}
