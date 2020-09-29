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
   
        node *search(int current_data)
        {
          node *t=start;
          if(t==NULL)
              return NULL;
          else
          {      
            while(t != NULL)
            {
              if(t->item==current_data)
                return t;
              t=t->next;  
            }
          }
          return NULL;
        }

        void insert_after(int current_data, int item)
        {
          node *t=search(current_data);
          if(t==NULL)
            cout<<"data not exists";
          else 
          {
            node *n=new node;
            n->item=item;
            n->next=t->next;
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

      int delet_item_from_first()
      {
        if(start==NULL)
          {
            cout<<"Underflow";
            return 0;
          }

        node *r=start;
        if(start->next==NULL)
        {
          delete (start);
          start=NULL;
        }
        else
        {
          start=start->next;
          delete r;
        }
      return 1;

      }

      int delete_from_last()
      {
         if(start==NULL)
          {
            cout<<"Underflow";
            return 0;
          }

        node *r=start;
        if(start->next==NULL)
        {
          delete (start);
          start=NULL;
        }
        else
        {
          node *r2=r;
          while(r->next!=NULL)
          {
            r2=r;
            r=r->next;
          }
          delete r;
          r2->next=NULL;
        }
        return 1;
      }


      int delete_specific_item(int current_data)
      {
        node *r=start;
        if(start==NULL)
          delet_item_from_first();
        node *t=search(current_data);
        if(t->next ==NULL)
          delete_from_last();
        else
        {
          while(t->next!=NULL)
          {
          t->item=t->next->item;
          t=t->next;
          }
          delete_from_last();
        }
        return 1;
      }

      /*
       int LinkedListADT::deleteCurrentItem(int currentData)
{
    node *t=Search(currentData);
    if(t==NULL)
    {
        cout<<"Invalid";
        return 0;
    }
    if(t->next==NULL){
        deleteItemFromLast();
        return 1;
    }
    while(t->next != NULL){
         t->item=t->next->item;
            t=t->next;
    }
   deleteItemFromLast();
    return (1);

}
      */

};


int main() 
{
 linkedlist l1;
// l1.insert_at_last(25);
 l1.insert_at_start(5);
 l1.insert_at_last(10);
 l1.insert_at_last(15);
 l1.insert_after(10, 30);
 l1.viewList();
 l1.delet_item_from_first();
 l1.viewList();
 l1.delete_from_last();
 l1.viewList();
  l1.insert_at_start(25);
 l1.insert_at_last(35);
 l1.insert_at_last(45);
 l1.delete_specific_item(30);
 l1.viewList();
}
