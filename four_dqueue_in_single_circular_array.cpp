//Write a program to implement four numbers of D-queues in an array.

#include<iostream>
using namespace std;

#define MAX 20  //used fixed size
#define k 4     //four queues

class Deque {
  int arr[MAX];
  int min[k];
  int max[k];
  int front[k];
  int rear[k];
    public:

//--------------------------------------------

  bool isEmpty(int num){
    return (front[num] == min[num] - 1 );
  }

//----------------------------------------------

  bool isFull(int num){
 
   return ((front[num] == min[num] && rear[num] == max[num]) ||
      front[num] == rear[num] + 1);
  }

//-------------------------------------------

  void insertfront(int value , int num){
    if (isFull(num)) {
        cout << "Overflow\n"<< endl;
        return;
    }

    if (front[num] == min[num]-1) {
        front[num] = min[num];
        rear[num] = min[num];
    }

    else if(front[num] == min[num])
        front[num] = max[num];

        else
            front[num] = front[num]-1;

    arr[front[num]] = value;
  }

//-------------------------------------

  void insertrear(int value , int num){
    if (isFull(num)) {
        cout <<"Overflow\n"<< endl;
        return;
    }

    if (front[num] == min[num]-1) {
        front[num] = min[num];
        rear[num] = min[num];
    }

    else if (rear[num] == max[num])
        rear[num] = min[num];

    else
        rear[num] = rear[num] + 1;

    arr[rear[num]] = value;
  }
  
//-----------------------------------------

  void deletefront(int num){
    if(isEmpty(num)){
        cout <<"Queue Underflow\n"<< endl;
        return;
    }

    if(front[num] == rear[num]) {
        front[num] = min[num]-1;
        rear[num] = min[num]-1;
    }else if (front[num] == max[num])
        front[num] = min[num];

    else
        front[num] = front[num] + 1;
    }

//-------------------------------------

  void deleterear(int num){
    if (isEmpty(num)) {cout << " Underflow\n"<< endl;
        return;
    }

    if(front[num] == rear[num]){
        front[num] = min[num]-1;
        rear[num] = min[num]-1;
    }else if (rear[num] == min[num])
        rear[num] = max[num];
    else
        rear[num] = max[num];
  }

//---------------------------------
  
  int getFront(int num) {
    if (isEmpty(num)) {
        cout <<"Underflow\n"<<endl;
        return -1;
    }
    return arr[front[num]];
  }

//-----------------------------------------

  int getRear(int num){
    if (isEmpty(num) || rear[num] < min[num]) {
        cout <<"Underflow\n"<<endl; 
        return -1;
    }
    return arr[rear[num]];
  }

//-------------------------------------
  
  void specifier(){
    for(int i=0;i<20;i=i+5){
        rear[i] = i;
        front[i] =i-1;
        max[i] = i+4;
        min[i] = i;
    }
  }

//--------------------------------------

};

int main(){
    Deque qf;

    qf.specifier();
    int choice;
    while(1){
        cout<<"OPTIONS\n"<<"1-ENQUEUE\n2-DEQUEUE\n3-display\n4-EXIT";
        cout<<"\n\nEnter your choice: ";
        cin>>choice;
        switch (choice) {
            case 1:{
                int num;
                cout<<"\nEnter Queue Number\n";
                cin>>num;
                int value;
                cout<<"\nEnter value\n";
                cin>>value;
                cout<<"1-rear end\n2-front";
                int x;
                cout<<"\n\nEnter your choice";
                cin>>x;
                switch(x){
                    case 1:{
                        qf.insertrear(value,num);
                        break;
                    }

                    case 2:{
                        qf.insertfront(value,num);
                        break;
                    }
                }
                break;
            }

            case 2:{
                int num;
                cout<<"\nEnter Queue Number\n";
                cin>>num;
                cout<<"1-rear end\n2-front";
                int x;
                cout<<"\n\nEnter your choice";
                cin>>x;
                switch(x){
                    case 1:{
                        qf.deleterear(num);
                        break;
                    }

                    case 2:{
                        qf.deletefront(num);
                        break;
                    }
                }
                break;
            }

            case 3:{
                int num;
                cout<<"\nEnter Queue Number\n";
                cin>>num;
                cout << "rear element: "<< qf.getRear(num)<< endl;
                cout << "front element: "<< qf.getFront(num)<< endl;
                break;
            }

            default :{
                cout<<"\n\n----EXIT----\n\n";
                return 0;
            }
        }
    }
}

//----------------------------------------------------------