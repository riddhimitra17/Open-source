#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    int data;
    Node* next;

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
class SinglyLinkedList{
    public:
    Node* head;

    SinglyLinkedList()
    {
        head = NULL;
    }
    SinglyLinkedList(Node *n) //passing the arguments
    {
        head = n;
    }
    //1. Checking if a node with same key exists or not
    Node* nodeExists(int k)
    {   //iterate through the entire linked list to find if the same key value exists or not
        Node* temp = NULL;

        Node* ptr = head; //address of the head pointer will be stored inside local pointer ptr
        while (ptr!=NULL)//to iterate through all the nodes. If there is some value in the list, head will not be null
        {
            if(ptr->key==k) //this will only only execute if the key value of the node which ptr is pointing to matches with the key value that is passed i.e. int k
            {
                temp = ptr; //temp node will store the address
            }
            ptr = ptr->next; // to go from the present node to the next node
        }
        return temp;
    }
    //2.Append a node to the list
    void appendNode(Node *n)
    {
        if(nodeExists(n->key) != NULL) // this code means that there exists a node having same key value as this new node has
        {
            cout<<"Node Already exists with key value: : "<<n->key <<". Append another node with different key value"<<endl;
        }
        else
        {
            if(head==NULL) //head pointer must not point to any of the node. Just checking that here
            {
                head = n; //Node we are appending must be the very first node in the linked list.
                cout<<"Node Appended"<< endl;
            }
            else //when head pointer is pointing to a particular object i.e. there is some value/nodes in the singlylinkedlist
            { //iterating through the list
                Node* ptr = head; //ptr is used to iterate through the list
                while(ptr->next!=NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next=n;
                cout<<"Node appended"<<endl;
            }
        }
    }
    //3. Prepend Node-Attach a node at the start
    void prependNode(Node *n)
    {
        if (nodeExists(n->key)!=NULL)
        {
            cout<<"Node already exists: "<<n->key<<". Append another node with different key value"<<endl;
        }
        else
        {
            n->next=head;//next pointer of the newly added node stores the address of head
            head=n;//head pointer will point to n
            cout<<"Node prepend"<<endl;
        }
    }
    //4. Insert a node after a particular node in the list
    void insertNodeAfter(int k, Node *n)//k is the key value after the node is to be insterted, Node *n is the address of the node
    {//checking if node with particular key k alreay exists or not
        Node* ptr = nodeExists(k); //if we get a value back will mean that the node exists
        if(ptr==NULL)
        {
            cout<<"No node exists with key value: "<<k<<endl;
        }
    
        else //Checking if the key value is unique
        {
            if(nodeExists(n->key)!=NULL)
            {
                cout<<"Node already exists: "<<n->key<<". Append another node with different key value"<<endl;
            }
            else
            { //idea is link n4 to n3 and link ptr(which is basically n2) to n4, n2->n4(new node)->n3
                n->next=ptr->next;  //the address stored in next of n must be same as in next of ptr & the next pointer inside ptr has the adress of n3, hence next of n4 has address of n3
                ptr->next=n;//link ptr(which is basically n2) to n4
            }
        }
    }
    // 5. Delete node by a particular key

    void deleteNodeByKey(int k)
    {
        if(head==NULL)
        {
            cout<<"Singly Linked List already empty. Can't delete"<<endl;
        }
        else if(head!=NULL) //else if section is used for removing the first node
        {
            if (head->key=k) //if head of key matches the key value we pass
            {
                head = head->next;//address of head pointer will be the address of the next node head is pointing to n1, head->next is n2 as n1 is pointing to n2. so address of n2 will be stored in head. Hence from the list we are unlinking n1
                cout<<"Node unlinked with key value"<<k<<endl;
            }
            else //for deleting a node from the middle
            {
                Node* temp = NULL; //creating a pointer temp which is storing null
                Node* prevptr = head; //created a previous pointer poiting to the head node
                Node* currentptr = head->next; //Current pointer is having the address next to the head
                while(currentptr!=NULL) //if address in current pointer is not null, keep moving forward
                {
                    if (currentptr->key==k)//if current pointer of key matches the key value we give
                    {
                        temp = currentptr; //a temp pointer is created pointing to the n2 node
                        currentptr = NULL; //current pointer is NULL bcs we got a match key==k
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }
                if (temp!=NULL) //temp will have the address of n2 on executing the if part above ie temp != NULL
                {
                    prevptr->next=temp->next; //adress of n3 (temp->next i,e n2->next) is stored in n1->next
                    cout<<"Node unlinked with key value"<<k<<endl;

                }
                else //it will be excuted if we do not find any same key in the while loop
                {
                    cout<<"Node doesnot exist with key value:"<<k<<endl;
                }
            }
        }
    
    }
    //6. Update node by key
    void updateNodeByKey(int k, int d) //We are accessing a node value ny its key k, and once we access it we will change its data value d
    {
        Node* ptr = nodeExists(k); //it will return a pointer to a node depending on if the key value exists or not
        if (ptr!=NULL) //If pointer is not NULL, it means there exists a value in the particular key
        { 
            ptr->data=d; //whatever data we have, we are over writing with d
            cout<<"Node data updated successfully"<<endl;
        }
        else
        {
            cout<<"Node doesn't exist with key value:"<<k<<endl;
        }
    }
    //7. Printing the enitire linekd list
    void printList() //traersing from one node to other and print the values
    {
        if(head==NULL) //check if head is NULL, if it was NULL means that there is no value in the linked list
        {
            cout<<"No nodes in the singly linked list"<<endl;
        }
        else
        {
            cout<<endl<<"Singly linked list values:";
            Node* temp = head; //Storing the value of the head in the temp pointer

            while(temp!=NULL) // till the value of temp is not null, the iteration will null. it will become null when we reach the last node
            {
                cout<<"("<<temp->key<<","<<temp->data<<") -->";
                temp = temp->next; //temp will store the address of temp of next
            }
        }
    }
};

int main() 
{
    SinglyLinkedList s;
    int option;
    int key1,k1,data1;
    do
    {
        //writing a menu driven program
        cout<<"\n what operation do you want to perform? Select option number. Enter 0 to exit."<<endl;
        cout<<"1. appendNode()"<<endl;
        cout<<"2. prependNode()"<<endl;
        cout<<"3. insertNodeAfter"<<endl;
        cout<<"4. deleteNodeByKey"<<endl;
        cout<<"5. updateNodeByKey"<<endl;
        cout<<"6. print()"<<endl;
        cout<<"7. Clear Screen"<<endl<<endl;

        cin>>option;
        Node* n1 = new Node(); //an object of node is created in the heap memory & n1 is pointer to that object in heap memory

        switch (option)
        {
            case 0:
                break;
        
            case 1:
                cout<<"Append Node Operation \nEnter key &data of the node to be appended"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                s.appendNode(n1);
                break;
            case 2:
                cout<<"Prepend Node Operation \nEnter key &data of the node to be prepended"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                s.prependNode(n1);
                break;
            case 3:
                cout<<"Insert After Operation \nEnter key of the existing node after which you want to insert"<<endl;
                cin>>k1;
                cout<<"Enter key & data of the new node first:"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                s.insertNodeAfter(k1,n1);
                break;
            case 4:
                cout<<"Delete Node by key Operation \nEnter key of the node to be deleted"<<endl;
                cin>>k1;
                s.deleteNodeByKey(k1);
                break;
            case 5:
                cout<<"Update Node by key Operation \nEnter key & new data to be updated"<<endl;
                cin>>key1;
                cin>>data1;
                s.updateNodeByKey(key1,data1);
                break;
            case 6:
                s.printList();
                break;
            case 7:
                system("cls");
                break;
            default:
                cout<<"Enter proper option number"<<endl;

        }
    } while (option!=0);
    

    return 0;
}