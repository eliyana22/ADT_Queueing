#include <iostream>
#include <conio.h>
#include <windows.h>
#define MAX 5
using namespace std;

class MyQ{
private:
    int Q[MAX];
    int data;
    int front;
    int rear;
    int rear1;
    int count;
public:
    void makenull();
    void enqueue();
    void dequeue();
    int fronts();
    int menu();
    void display();
    bool isfull();
    bool isempty();
};

void MyQ::makenull(){
    int i;
    rear = -1;
    rear1 = -1;
    front = 0;
    count = 0;
    for(i=0;i<MAX;i++){
        Q[i]=0;
    }
}

void MyQ::enqueue(){
    if(isfull()){
        cout <<"QUEUE IS FULL!"<<endl;
        getch();
    }
    else{
        rear1++;  rear++; count++;
        cout<<"ENTER NUMBER: ";
        cin>>data;
        Q[rear] = data;

        if(rear1==MAX-1){
            rear = -1;
            rear1 = rear1 - (count-1);
        }
    }
}

void MyQ::dequeue(){
    if (isempty()){
        cout<<"QUEUE IS EMPTY!"<<endl;
        getch();
    }
    else{
        cout<<"\n"<<fronts()<<" WAS DEQUEUED"<<endl;
        rear1++;
        Q[front] = 0 ;
        front++; count--;
        if(front==MAX)
            front=0;
        getch();
    }
}

void MyQ::display(){
    int i,j=1;
    system("cls");
    if(isempty()){
        cout<<"QUEUE IS EMPTY!"<<endl;
    }else{
        for(i=0;i<MAX;i++){
            cout <<j++<<".) "<<Q[i]<<endl;
        }
    }
    system("pause");
}

int MyQ::fronts(){
    return(Q[front]);
}

bool MyQ::isempty(){
    return(count==0);
}

bool MyQ::isfull(){
    return(count==MAX);
}

int MyQ::menu(){
    int op;
    system("cls");
    cout<<"MENU"<< endl;
    cout<<"1. Enqueue"<<endl;
    cout<<"2. Dequeue"<<endl;
    cout<<"3. Display"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"SELECT NUMBER 1 TO 4: ";
    cin>>op;
    return(op);
}

int main(){
    MyQ que;
    que.makenull();
    while(true){
        switch(que.menu()){
        case 1 : system("cls");que.enqueue();break;
        case 2 : que.dequeue();break;
        case 3 : que.display();break;
        case 4 : exit(0);break;
        default: cout<<"SELECT NUMBER 1 TO 4 ONLY";getch();
        }
    }
    return 0;
}
