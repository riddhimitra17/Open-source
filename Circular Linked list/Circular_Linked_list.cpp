#include<iostream>
using namespace std;

class Node{
    public:
        int key; //key which identifies the node object
        int data; //data member which stores the data
        Node* next; //pointer of the same class which points to the next node

        Node()
        {
            key = 0;
            data = 0;
            next = NULL;
        }
        Node(int k, int d)
        {
            key = k;
            data = d;
        }
};

class CircularLinkedList
{
    public:
    Node* head;

    CircularLinkedList()
    {
        head = NULL;
    }

    //1.check if node exists with key value
    Node* nodeExists(int k){ //we  pass the key of the node

    Node* temp = NULL;
    Node* ptr = head;
    
    if (ptr==NULL)
    {
        return temp;
    }
    else
    {
        do
        {
            if(ptr->key==k) //if the pointer's key = the key we passed
            {
                trmp=ptr;
            }
            ptr = ptr->next; //ptr is pointing to n1. So n1->next = n2
        } while (ptr!=head): //the last node will point to head as it is circular linked list
        return temp; 
        
    }

    //2. append node to the list
    void appendNode(Node *new_node)
    {
        if(nodeExists(new_node->key)!=NULL) //checking if there is any other node in the circular linked list with the same key value
        {
            cout<<"Node already exists with key value:"<<new_node->key<<". Append another node with a different key value."<<endl;
        }
        else
        {
            if(head==NULL)
            {
                head = new_node; //head will point to the new node which will basically be the 1st node
                new_node->next=head; // the next pointer of the new node will point to itself as it is only the first and the last node
                cout<<"Node appended at the first head position"<<endl;
            }
            else //we have some nodes in the circular linked list
            {

                Node* ptr = head; //ptr is now pointing to n1
                while(ptr->next!=head)
                {
                    ptr = ptr->next; //n2 is the new ptr. In this way it goes on traversing
                }
                ptr->next=new_node; //next of n3 = n4
                new_node->next=head; //next of n4 will point to head
                cout<<"Node appended"<<endl;
            }
        }

    }
    //3. Prepend node - Attach a node at the start
    void prependNode(Node* new_node)
    {
        if(nodeExists(new_node->key)!=NULL)
        {
            cout<<"Node already exists with key value:"<<new_node->key<<". Prepend another node with a different key value."<<endl;
        }
        else
        {
            if(head==NULL)
            {
                head = new_node; //head will point to the new node which will basically be the 1st node
                new_node->next=head; // the next pointer of the new node will point to itself as it is only the first and the last node
                cout<<"Node prepended at the first head position"<<endl;
            }
            else
            {
                Node* ptr = head; //we are storing the address of the head in a node pointer
                while(ptr->next != head)
                {
                    ptr = ptr-> next;
                }
                ptr->next=new_node; //let the nodes be n1,n2, n3. New node is n4. The next of n3 will now point to n4 and not n1
                new_node->next = head; //next of n4 = n1. n1 is the head
                head = new_node; //address of head will now become n4
                cout<<"Node prepended"<<endl;
            }
        }
    }

    //4. Insert node after a particular node in the list
    void insertNodeAfter(int k, Node *new_node)//k is the node after which you want to enter a node
    {
        Node* ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout<<"No node exists with the key value of :"<<k<<endl;
        }
        else
        {
            if(nodeExists(new_node->key)!=NULL)
            {
                cout<<"Node already exists with key value:"<<new_node->key<<". Prepend another node with a different key value."<<endl;
            }
            else
            {
                if(ptr->next==head) //inserting node at the end. ptr is now pointing to n3 as we passed k=3
                {
                    new_node->next=head; //next of n4 now points to n1
                    ptr->next=new_node;//n3 of next =  n4
                    cout<<"Node inserted in between"<<endl;
                }
                else
                { //for inserting node in between. Suppose we give k=2. this means we will insert node between n2 and n3
                    new_node->next=ptr->next; //n4 of next = n3 
                    ptr->next=new_node; //n2 next = n4
                    cout<<"Node inserted in between"<<endl;
                }
            }
        }
    }
    //5.Delete node by key
    void deleteNodeByKey(int k)
    {
        Node* ptr = nodeExists(k)
        if (ptr == NULL)
        {
            cout<<"No node exists with key value of:"<<k<<endl;
        }
        else //executed when we want to delink the head node
        {
            if(ptr == head)
            {
                if (head->next==NULL)
                {
                    head = NULL;
                    cout<<"Head node unlinked...list empty";
                }
                //if we have more nodes in the circular linked list
                else
                {
                    Node* ptr1 = head; //creating a new pointer as ptr 1
                    while(ptr1->next!=head) //traversing till the end using the while loop concept
                    {
                        ptr1 = ptr1->next;
                    }
                    ptr1->next = head->next; //n3->next = n2
                    head=head->next;
                    cout<<"Node unlinked with key values:"<<k<<endl;
                }
            }
            else
            {
                Node* temp = NULL;
                Node* prevptr = head; //previous ponter pointing to head (n1)
                Node* currentptr = head->next; //current ptr points to head->next (n2)
                while(currentptr!=NULL)
                {
                    if (currentptr->key==k)
                    {
                        temp = currentptr;
                        currentptr = NULL; //currentptr is set to NULL to exit the while loop
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }
                //now temp will point to n3 & prev pointer to n2
                prevptr->next=temp->next; //n2->next=n3->next (i.e n1)
                cout<<"Node UNLINKED with key values: "<<k<<endl;
            }
        }
    }
    //6. Update Node by key
    void updateNodeByKey(int k, int new_data)
    {
        Node* ptr = nodeExists(k);
        if(ptr!=NULL)
        {
            ptr->data=new_data;
            cout<<"Node data updated successfully"<<endl;
        }
        else  
        {
            cout<<"Node doesn't exists with key value:"<<k<<endl;
        }
    }
    //7. Printing
    void printList()
    {
        if(head==NULL)
        {
            cout<<"No node exits";

        }
        else
        {
            cout<<endl<<"head address : "<<head<<endl;
            cout<<"Values:"<<endl;

            Node* temp = head;
            do
            {
                cout<<"("<<temp->key<<","<<temp->data<<","<<temp->next<<") -->";
                temp=temp->next;
            } while (temp!=head);
            
        }
    }
}