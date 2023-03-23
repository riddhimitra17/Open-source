#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    int data;
    Node* next;
    Node* previous;

    Node(){
        key=0;
        data=0;
        next=NULL;
        previous=NULL;
    }
    Node(int k, int d)
    {
        key= k;
        data=d;
    
    }
};
class DoublyLinkedList{

    public:
    Node* head;

    DoublyLinkedList()
    {
        head=NULL;
    }
    DoublyLinkedList(Node *n)
    {
        head=n;
    }

    //1.Check if node exists with key value
    Node* checkIfNodeExists(int k) //Node* is the return type of the method CheckIfNodeExists. If node exists with the particular key, it will return address to that object.
    {
        Node* temp = NULL; //creating a temporary pointer of class node and string null
        Node* ptr = head; //address of head will be stored in temporary pointer

        //using ptr to traverse throught the entire list
        while (ptr!=NULL) //it ensures that ptr is having some address
        {
            if(ptr->key==k)//we are using pointer to access the object's key. We are seeing if the object's key = to the key we passed k
            {
                temp=ptr; //if we find a match, the address will be stored in the temp pointer
            
            }
            ptr=ptr->next; // ptr will point to the next object which will be stored in the ptr pointer. At the end of the list, ptr will have an address of null and iteration will stop
        }
        return temp; //we are returning the address of the temp pointer
    }

    //2. Append a node to the list

    void appendNode(Node* n)
    {
        if (checkIfNodeExists(n->key)!=NULL) //we are accessing a key of that object. If the address exixts in the linked list, the check method will not return a value of NULL
        {
            cout <<"Node already exits with key value:"<<n->key<<" . Append another node with a different key value."<<endl;
        }
        else
        { //if head pointer is having null
            if (head==NULL)
            { 
                head = n; //the address n will be stored in the head class
                cout<<"Node appended as head node"<<endl;
            }
            else
            { //we have to traverse will the end
                Node* ptr=head;//in the temporary pointer, we are storing the address stored in the head
                while(ptr->next!=NULL) //if head is pointer to n1, then ptr is also pointed to n1. To access the next pointer inside n1, we say ptr->next
                { //This loop will run until the next value is not NULL
                    ptr=ptr->next; //n1 next has the address of n2 stored, so in this way, we move from n1 to n2. ptr is now pointed to n2
                }
                ptr->next=n; //ptr is pointing to n3 which is the last node. n is the node we wnted to append n3 is now connected to the new node n        
                n->previous=ptr; //the new node also needs to point back to the previous node
                cout<<"Node appended"<<endl;
            }
        }
    }
    //3.Prepend node-Attach a node at the start
    void prependNode(Node* n)
    {
        if(checkIfNodeExists(n->key)!=NULL)
        {
            cout <<"Node already exits with key value:"<<n->key<<" . Prepend another node with a different key value."<<endl;
        }
        else
        {
            if (head==NULL)
            { 
                head = n; //the address n will be stored in the head class
                cout<<"Node Prepended as head node"<<endl;
            }
            else
            {
                head->previous=n;//previous pointer of n1 will store the address of new node
                n->next=head; //newly passed node will point to n1
                head=n; //head will become the new node that is passed
                cout<<"Node prepended"<<endl;
            }
        }
    }

    //4. Insert a node after a particular node in the list
    void insertNodeAfter(int k, Node *n)
    {
        Node* ptr = checkIfNodeExists(k); //passing the key and chceking if the node exists in the key. the adress will be stored in ptr
        if(ptr==NULL) //it means no node exists with the particular key
        {
            cout<<"No node exists with the key value:"<<k<<endl;
        }
        else
        {
            if(checkIfNodeExists(n->key)!=NULL) //checking the keys and seeing if this newly passed node has the same key or not
            {
                cout <<"Node already exits with key value:"<<n->key<<" . Insert another node with a different key value."<<endl;
            }
            else
            {
                Node *nextNode = ptr->next;

                //inserting at the end
                if(nextNode==NULL) //if this condition satisfies, we kow that we are at the end of the list
                {
                    ptr->next = n; //n3 of next is the new node n where the address is stored
                    n->previous=ptr; //new node's previous points back to n3
                    cout<<"Node inserted at the end"<<endl;
                }
                //inserting in between
                else //when the previous if is not satisfied, SAY inserting the new node n4 btwn n2 and n3
                {
                    n->next=nextNode; //next pointer of n4 will point to n3 
                    nextNode->previous=n; //previous of n3 will point to n4, back linking is also done
                    n->previous=ptr; //n4.previous points to n2, hence back linking is done
                    ptr->next=n; //next of n2 is pointed to n4
                    cout<<"Node inserted in between"<<endl;
                }
            }
        }
    }
    //5. Delete node by key. Basically delinking and not delete
    void deleteNodeByKey(int k)
    {
        Node* ptr = checkIfNodeExists(k); //checking if the particular node exists or not
        if(ptr==NULL) //this means no node exists in the list
        {
            cout<<"No node exists with key value"<<k<<endl;
        }
        else
        {
  
            if(head->key==k) //checking if key of the head node is matchng wwith the passed key
            {
                head = head->next; //the new head now points to the next node. in this way, we just unlinked the first node
                cout<<"Node unlinked with key values"<<k<<endl;
            }
            else
            {
                Node *nextNode = ptr->next; //n3 of next is null. so null will be stored in the next node
                Node *prevNode = ptr->previous; //n3->previous is n2. Address of n2 will be stored in the previous node
                //deleting at the end
                if(nextNode==NULL) //when next pointer is null, we know that we are at the end of the list
                {
                    prevNode->next=NULL; //n2 of next=null. so the link b/w n2 is n3 is broken as the next pointer is becoming null
                    cout<<"Node deleted at the end"<<endl;
                }
                //deleting in between
                else
                {
                    prevNode->next=nextNode; //n1->next=n3
                    nextNode->previous=prevNode; //n3->previous=n1
                    cout<<"Node deleted in between"<<endl;
                }
            }
            
        }
    }
    //5. Update node by key
    void updateNodeByKey(int k, int d) //taking key and a data value
    {
        Node* ptr = checkIfNodeExists(k);
        if (ptr!=NULL)
        {
            ptr->data=d; //we give the new data value
            cout<<"Node data Updated Successfully"<<endl;

        }
        else
        {
            cout<<"Node doesn't exist with key value: "<<k<<endl;
        }
    }
    //7. printing
    void printList()
    {
        if (head==NULL)
        {
            cout<<"No nodes in the doubly linked list";
        }
        else
        {
            cout<<endl<<"doubly linked list values:";
            Node* temp = head; //storing the address in the temp pointer

            while (temp!=NULL) //using the temp pointer to iterate through the doubly linked list
            {
                cout<<"("<<temp->key<<","<<temp->data<<") <-->";
                temp = temp->next; //temp will point to next node
            }
        }
        
    }

};

int main()
{
    DoublyLinkedList s;
    int option; //opition variable for do while loop
    int key1,k1,data1;
    do
    {
        //writing a menu driven program
        cout<<"\n What operation do you want to perform? Select option number. Enter 0 to exit."<<endl;
        cout<<"1. appendNode()"<<endl;
        cout<<"2. prependNode()"<<endl;
        cout<<"3. insertNodeAfter"<<endl;
        cout<<"4. deleteNodeByKey"<<endl;
        cout<<"5. updateNodeByKey"<<endl;
        cout<<"6. print()"<<endl;
        cout<<"7. Clear Screen"<<endl<<endl;

        cin>>option; //taking option from user
        Node* n1 = new Node(); //an object of node is created in the heap memory & n1 is pointer to that object in heap memory
        //Node n1
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