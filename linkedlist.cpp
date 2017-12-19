#include<iostream>
using namespace std;

class Node {
public:
int info;
Node *next;
Node () { }
Node(int data){
  info = data;
  next = nullptr;
}
};

class LinkedList {

Node *head;
int siz;
public:

LinkedList ()
{
   head = nullptr;
   siz = 0;
}

void insertf(int);
void insertl(int);
void insertx(int,int);
void deletef();
void deletel();
void deletex(int);
void display();

};

void LinkedList::insertf(int info)
{
   Node *nyanode = new Node(info);
   nyanode->next = head;
   head = nyanode;
   siz++;
}

void LinkedList::insertl(int info)
{
   Node *temp = head;
   while(temp->next != nullptr)
   temp = temp->next;

   Node *nyanode = new Node(info);
   temp->next = nyanode;
   siz++;
}

void LinkedList::insertx(int loc,int info)
{
   if(loc > siz){
   cout<<"NOT POSSIBLE";
   return;
   }
   Node *temp = head;
   Node *prev = temp;
   while(loc > 0 && temp->next != nullptr){
   prev = temp;
   temp = temp->next;
   loc--;
   }

   if(prev == temp)
   insertf(info);
   else{
   Node *nyanode = new Node(info);
   prev->next = nyanode;
   nyanode->next = temp;
   }
   siz++;
}

void LinkedList::display()
{

Node *temp = head;
while(temp != nullptr)
{
  cout<<temp->info<<"--->";
  temp = temp->next;
}


}

void LinkedList::deletef()
{
  if(head == nullptr){
  cout<<"UNDERFLOW";
   return;
  }
  siz--;
  head = head->next;
}

void LinkedList::deletel()
{
   if(head == nullptr)
   {
     cout<<"UNDERFLOW";
     return;
   }
   else if(head->next == nullptr)
   {
     head = nullptr;
   }
   else
   {

      Node *temp = head;
      while(temp->next->next != nullptr)
      {
        temp = temp->next;
      }
      temp->next = nullptr;
    }

    siz--;
}

void LinkedList::deletex(int loc)
{
  if(siz == 0)
  {
    cout<<"UNDERFLOW";
    return;
  }

  Node *temp = head;
  Node *prev = temp;
  while(loc > 0 && temp->next != nullptr)
  {
    loc--;
    prev = temp;
    temp = temp->next;
  }

  prev->next = temp->next;
  temp = nullptr;
}

int main()
{

LinkedList l;
cout<<"Press 1. To insert an element at front of the linked-list"<<endl;
cout<<"      2. To insert an element at back of the linked-list"<<endl;
cout<<"      3. To insert an element at position x of the linked-list"<<endl;
cout<<"      4. To delete an element from front of the linked-list"<<endl;
cout<<"      5. To delete an element from back of the linked-list"<<endl;
cout<<"      6. To delete an element from position x of the linked-list"<<endl;
cout<<"      7. To display the linked-list"<<endl;
cout<<"      8. To exit"<<endl;

int ch,data,loc;

cin>>ch;
do {
switch(ch)
{
  case 1: cout<<"enter data"<<endl;
          cin>>data;
          l.insertf(data);
          break;
  case 2: cout<<"enter data"<<endl;
          cin>>data;
          l.insertl(data);
          break;
  case 3: cout<<"enter data"<<endl;
          cin>>data;
          cout<<"enter location"<<endl;
          cin>>loc;
          l.insertx(loc,data);
          break;
  case 4: l.deletef();
          break;
  case 5: l.deletel();
          break;
  case 6: cout<<"enter location"<<endl;
          cin>>loc;
          l.deletex(loc);
          break;
  case 7: cout<<"The linked-list looks like"<<endl;
          l.display();
          break;
  case 8: exit(0);
}
cin>>ch;
} while(ch != 8);

 return 0;

}
