#include<iostream>
#define size 1000
using namespace std;
class Stack
{
    int top;
    int arr[size];
public:
    Stack()
    {
        top = -1;
    }
    void push(int x)
    {
        if(top == size)
            return;
       arr[++top] = x;
    }
    int pop()
    {
      if(top == -1)
        return -1;
      return arr[top--];
    }
    void display()
    {
        for(int i = top; i >=0 ;i--)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    Stack s;
    cout<<"ENTER"<<endl;
    cout<<"1. To Push an element into a stack"<<endl;
    cout<<"2. To pop an element from the stack"<<endl;
    cout<<"3. To view the complete stack"<<endl;
    cout<<"4. To exit"<<endl;
    int ch,data;
    do {
    cin>>ch;
    switch(ch)
    {
        case 1: cout<<"Enter the element"<<endl;
                cin>>data;
                s.push(data);
                continue;
        case 2: data = s.pop();
                if(data == -1){
                cout<<"Stack is Empty"<<endl;
                continue;
                }
                cout<<"The popped element is : "<<data<<endl;
                continue;
        case 3: cout<<"The whole stacks looks like "<<endl;
                s.display();
                continue;
        case 4: exit(0);
    }
    }while(ch != 4);
    return 0;
}
