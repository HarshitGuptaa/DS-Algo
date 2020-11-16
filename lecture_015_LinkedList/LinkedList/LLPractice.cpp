#include<iostream>

using namespace std;


class LL{

class Node{
    public:
    int data;
    Node* next = nullptr;
    
    Node(int data){
        this->data=data;
    }
};

private:
Node* head = nullptr;
Node* tail = nullptr;
int size=0;

public:

void display(){
    Node*temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

bool isEmpty(){
    return size==0;
}

void AddFirst(int data){
    Node* node = new Node(data);
    size++;
    if(head==nullptr){
        head=node;
        tail=node;
    }else{
        node->next = head;
        head=node;
    }
}

void AddLast(int data){
    Node* node = new Node(data);
    size++;
    if(tail==nullptr){
        head=node;
        tail=node;
    }else{
        tail->next = node;
        tail=node;
    }
}

Node* getAt(int idx){
    if(idx==0) return head;
    if(idx>size-1) return nullptr;
    Node* temp = head;
    while(idx-->0){
        temp=temp->next;
    }
    return temp;
}

void AddAt(int idx,int data){
    Node* node = new Node(data);
    
    if(idx>size){
        cout<<"Not poss to add here";
    }

    else if(idx==0){
        size++;
        head = node;
        tail=node;
    }
    
    else{
        size++;
    Node* prev = getAt(idx-1);
    Node* forw = prev->next;

    prev->next = node;
    node->next = forw;
    }

}

void RemoveFirst(){
    if(head==nullptr){
        cout<<"Empty";
    }else{
        head = head->next;
        size--;
    }
}

void RemoveLast(){
    if(tail==nullptr && head==nullptr) cout<<"Empty";
    
    else if(head==tail){
        size--;
        head=nullptr;
        tail=nullptr;
    }
    else{
        size--;
        Node* scndLast = getAt(size-2);
        tail = scndLast;
        tail->next=nullptr;
    } 
}

void RemoveAt(int idx){
    if(idx==0){
        size--;
        head=nullptr;
        tail=nullptr;
    }

    Node* prev = getAt(idx-1);
    Node* forw = prev->next->next;
    prev->next = forw;
}

Node* mid(){
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr && fast->next!=nullptr && fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node* reverseLL_(Node* head){
    Node* prev = nullptr;
    Node* curr = head;

    while(curr!=nullptr){
        Node* forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
}

void reverseLL(){
    Node* node = reverseLL_(head);
    tail = head;
    head = node;
}

bool isPalindrome(){
    Node* midNode = mid();
    Node* nhead = midNode->next;
    midNode->next=nullptr;

    Node* list1 = reverseLL_(nhead);
    Node* prev = list1;
    Node* list2 = head;
    bool flag = true;
    while(list1!=nullptr && list2!=nullptr){
        if(list1->data != list2->data) flag = false;
        list1 = list1->next;
        list2 = list2->next;
    }

    nhead = reverseLL_(prev);
    midNode->next = nhead;
}

void fold(){
    Node* midNode = mid();
    Node* nhead = midNode->next;
    midNode->next=nullptr;

    nhead = reverseLL_(nhead);
    Node* curr1 = head;
    Node* curr2 = nhead;
    while(curr2!=nullptr){
        Node* cn1 = curr1->next;
        Node* cn2 = curr2->next;

        curr1->next = curr2;
        curr2->next = cn1;

        curr1 = cn1;
        curr2 = cn2;
    }
    if(curr1==nullptr) tail = nhead;
    else tail = midNode;
}

void unfold(){
    Node* prev = head;
    Node* forw = prev->next;
    Node* list2 = forw;

    while(prev!=nullptr && forw!=nullptr){
        Node* cn1 = forw->next;
        Node* cn2 = cn1->next;

        prev->next = cn1;
        forw->next = cn2;

        prev = cn1;
        forw = cn2;
    }

    Node* nhead = reverseLL_(list2);
    tail->next = nhead;
    tail = list2;
}




};




int main(){
    LL ll;
    ll.AddLast(2);
    ll.AddLast(4);
    ll.AddFirst(1);
    ll.AddAt(2,3);
    ll.RemoveAt(3);
    //cout<<ll.getAt(2)->data;
    ll.display();
    return 0;
}