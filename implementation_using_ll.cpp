#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
      int data;
      Node* next;

      Node(int val)
      {
        data=val;
        next=NULL;
      }
};

class queue {
    Node* head;
    Node* tail;

public:
   queue(){
    head=tail=NULL;
   }   
   void push(int data)//insert data at tail of ll
   {
       Node* newNode = new Node(data);
       if(empty())
       {
        head = tail = newNode;
       }
       else{
        tail->next = newNode;
        tail = newNode;
       }






   }

   void pop()
   {
      if(empty())
      {
        cout<<"ll is empty"<<endl;

      }
      Node* temp=head;
      head = head->next;
      delete temp;

   }

   int front()
   {

       if(empty())
      {
        cout<<"ll is empty"<<endl;
        return -1;

      }
       return head->data;

   }

   bool empty()
   {
    return head == NULL;

   }

};

int main()
{

    queue q;
     q.push(1);
     q.push(2);
     q.push(3); 

     while(!q.empty())
     {
        cout<<q.front() << " ";
        q.pop();
     }

     cout<<endl;

    return 0;
}


