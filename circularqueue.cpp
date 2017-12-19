#include<iostream>
#define maxsize 3
using namespace std;

class CircularQueue {

int arr[maxsize];
int F;
int R;

public :
CircularQueue()
{
  F = -1;
  R = -1;
}

void enqueue(int);
void dequeue();
void display();

};

void CircularQueue::enqueue(int data)
{
  if((R+1)%maxsize == F){
  cout<<"OVERFLOW"<<endl;
  return;
  }
  R = (R+1)%maxsize;
  arr[R] = data;

  if(F == -1)
  F = 0;

}

void CircularQueue::dequeue()
{
   if(F == -1){
   cout<<"UNDERFLOW"<<endl;
   return;
   }

   cout<<"Popped Element is "<<arr[F]<<endl;

   if(F == R)
   F = R = -1;
   else
   F = (F+1)%maxsize;
}

void CircularQueue::display()
{
   if(F == -1)
   return;

   if(R > F)
   {
      for(int i=F ; i<=R ;i++)
      {
        cout<<arr[i]<<" ";
      }
      cout<<endl;

   }
   else
   {
      for(int i=F;i<maxsize;i++)
      {
         cout<<arr[i]<<" ";
      }

      for(int i=0;i<=R;i++)
      {
        cout<<arr[i]<<" ";
      }

      cout<<endl;

   }


}

int main() {
CircularQueue cq;
cout<<"Press 1. To insert an element in circular-queue"<<endl;
cout<<"      2. To delete an element from the circular-queue"<<endl;
cout<<"      3. To display the circular-queue"<<endl;
cout<<"      4. To exit"<<endl;

int ch,data;
cin>>ch;

do {
switch(ch)
{
  case 1: cout<<"enter data"<<endl;
          cin>>data;
          cq.enqueue(data);
          break;
  case 2: cq.dequeue();
          break;
  case 3: cout<<"The circular-queue looks like"<<endl;
          cq.display();
          break;
  case 4: exit(0);
}
cin>>ch;
} while(ch != 4);

 return 0;

}
