#include<iostream>
#define MAX_SIZE 500

using namespace std;

template <class T>
class Queue{
    private:
        int front,rear;
        T data[MAX_SIZE];
        int size=0;
    public:
    Queue();
    Queue(int s);
    void enqueue(T a);
    T dqueue();
    T peek();
    void out();
    bool is_full();
    bool is_empty();
};
template<class T>
bool Queue<T>::is_empty(){
    if(front<0|| front>rear) return true;
    else return false;
}
template<class T>
bool Queue<T>::is_full(){
    //incomplete
    if(rear==(size-1)) return true;
    else return false;
}
template <class T>
Queue<T>::Queue(){
    front=0;
    rear=-1;
    size=MAX_SIZE;
    cout<<"QUEUE CREATED SUCESSFULLY"<<endl;
}
template<class T>
Queue<T>::Queue(int s){
    front=0;
    rear=-1;
    size=s;
    cout<<"QUEUE CREATED SUCESSFULLY"<<endl;

}
template<class T>
void Queue<T>::enqueue(T a){
    //check if the queue is full
    if(is_full()){
        cout<<"ERROR::QUEUE IS FULL"<<endl;
    }
    else{
        rear++;
        data[rear]=a;
        cout<<"QUEUED"<<endl;
    }
}
template<class T>
T Queue<T>::dqueue(){
    if(is_empty()){
        cout<<"ERROR::QUEUE EMPTY"<<endl;
    }
    else{
        front++;
    }
}
template<class T>
T Queue<T>::peek(){
    return data[front];
}
template <class T>
void Queue<T>::out()
{
     for (int i = front; i <= rear; i++)
    {
        if(i==front) cout<<"[";
        if(i!=rear){
        cout << data[i] << ",";
        }
        else
        cout<<data[i]<<"]";
    }
    cout<<endl;
}


int main(){
    Queue<int> a(5);
    a.dqueue();
    cout<<a.peek()<<endl;
    a.enqueue(1);//1
    cout<<a.peek()<<endl;
    a.enqueue(2);//2
    cout<<a.peek()<<endl;
    a.enqueue(3);//3
    cout<<a.peek()<<endl;
    a.enqueue(4);//5
    cout<<a.peek()<<endl;
    a.dqueue();
    a.enqueue(5);//5
    cout<<a.peek()<<endl;
    a.enqueue(6);//6
    cout<<a.peek()<<endl;
    a.enqueue(7);//7
    cout<<a.peek()<<endl;
    a.dqueue();
    a.enqueue(8);//8
    cout<<a.peek()<<endl;
    a.out();
    return 0;
}
