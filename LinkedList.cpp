#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

bool isEmpty(Node* start){
    return start==nullptr;
}

Node* push(int value, Node* start){
    if(isEmpty(start))
    {
        start = new Node;
        start->data = value;
        start->next = NULL;
        return start;
    }
    else
    {
        Node *new_node = new Node;
        new_node->data = value;
        new_node->next = start;
        start = new_node;
        return start;
    }
}

Node* pop(Node* start){
    if(isEmpty(start))
    {
        cout<<"List is empty"<<endl;
        return NULL;
    }
    else{
        int del_num;
        bool first = false;
        cout<<"Enter a number to delete: ";
        cin>>del_num;
        Node* temp = start;
        Node* temp_last = start;
        while(temp!=nullptr){
            if(temp->data == del_num){
                temp_last->next=temp->next;
                delete temp;
                return start;
            }
            temp=temp->next;
            if(first != true)
                temp_last=temp_last->next;
            first = true;
        }
        return start;
    }
}

Node* sort(Node* start){
    bool swapped;
    Node *ptr1;
    Node *lptr;
    lptr = NULL;
    do{
        swapped = false;
        ptr1 = start;
        while(ptr1->next != lptr)
        {
            if(ptr1->data > ptr1->next->data)
            {
                swap(ptr1->data,ptr1->next->data);
                swapped = true;
                
            }
            ptr1=ptr1->next;
        }
        lptr = ptr1;
    }while(swapped);
    return start;
}

void display(Node* start)
{
    if(isEmpty(start))
    {
        cout<<"List is empty"<<endl;
    }
    else{
        Node *temp = start;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}

int main()
{
    //Node *start;
    Node *start = new Node;
    start = NULL;
    int input;
    while(input!=-1)
    {
        
        cout<<"Enter a Number (-1 to stop): ";
        cin>>input;
        if(input != -1)
        {
            start = push(input,start);
        }
    }
    string option;
    cout<<"Do you want to pop? (yes or no):";
    cin>>option;
    if(option == "yes")
    {
        pop(start);
    }

    cout<<"Original Linked List: ";
    display(start);

    start = sort(start);

    cout<<"Linked List After Sorting: ";
    display(start);


    return 0;
}