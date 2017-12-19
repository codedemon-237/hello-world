#include<iostream>
#define siz 1000
using namespace std;
class Queue
{
    int f,r;
    int c=0;
    long long arr[siz];
public:
    Queue()
    {
        f = -1;
        r = -1;
    }
    void enqueue(int x)
    {
        if(r == siz)
            return;
        if(f == -1 && r == -1)
        {
            f = r = 0;
            arr[f] = x;
            c++;
            return;
        }
       arr[++r] = x;
       c++;
    }
    int dequeue()
    {
      if(isEmpty()){
        f = r = -1;
        return -1;
      }

       c--;
      return arr[f++];
    }
    void display()
    {
        for(int i = f; i <= r ;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    bool isEmpty(){
     return c == 0;
    }
     bool isFull(){
     return c == siz;
     }
};
int main()
{
    Queue q;
    cout<<"ENTER"<<endl;
    cout<<"1. To Enqueue an element into the queue"<<endl;
    cout<<"2. To Dequeue an element from the queue"<<endl;
    cout<<"3. To view the complete queue"<<endl;
    cout<<"4. To exit"<<endl;
    int ch,data;
    do {
    cin>>ch;
    switch(ch)
    {
        case 1: cout<<"Enter the element"<<endl;
                cin>>data;
                q.enqueue(data);
                continue;
        case 2: data = q.dequeue();
                if(data == -1){
                cout<<"Stack is Empty"<<endl;
                continue;
                }
                cout<<"The popped element is : "<<data<<endl;
                continue;
        case 3: cout<<"The whole queue looks like "<<endl;
                q.display();
                continue;
        case 4: exit(0);
    }
    }while(ch != 4);
    return 0;
}
