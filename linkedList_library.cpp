#include<stdio.h>
#include<iostream>

using namespace std;
class linkedlist
{
  private:
            struct node
            {
               int item;
               node *next; 
            };
            node *start;

  public:

        //constructor
        linkedlist()
        {
          start=NULL;
        }

        void insert_at_start(int data)
        {
          node *n= new node;
          n->item=data;
          n->next=start;
          start=n;
        }



        void insert_at_last(int data)
        {
          node *n=new node, *t=start;
          n=new node;
          n->item=data;
          n->next=NULL;
          if(t==NULL)
            insert_at_start(data);
          else
            {
              while(t->next !=NULL)
              {
                t=t->next;
              }
              
              t->next=n;
            }  
        }

       void viewList()
      {
        node *t=start;
        while(t->next != NULL)
        {
          cout<<t->item<<endl;
          t=t->next;
        }
        cout<<t->item<<endl;
      }

};


int main() 
{
 linkedlist l1;
// l1.insert_at_last(25);
 l1.insert_at_start(5);
 l1.insert_at_last(10);
 l1.insert_at_last(15);
 l1.viewList();  
}