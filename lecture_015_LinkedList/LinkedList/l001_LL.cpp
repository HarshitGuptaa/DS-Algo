#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;


class LRU{
    list<int>ll;
    unordered_map<int,int> map;
    int defaultSize = 4;

    void set(int key,int value){

        if(map.find(key) == map.end()){   //key not present
            if(ll.size() == defaultSize){
                int lastKey = ll.back();
                ll.pop_back();
                map.erase(lastKey);
            }
            ll.push_front(key);
            map[key]=value;

        }else{
            ll.remove(key);
            ll.push_front(key);
            map[key]=value;
        }
    }

    int get(int key){
        if(map.find(key) == map.end()){
            return -1;
        }else{
            ll.remove(key);
            ll.push_front(key);
            return key;
        }
    }
};



class linkedList
{

class Node{
    public:
    int data=0;
    Node *next = NULL;

    Node(int data){
        this->data = data;
    }
};

private:
Node*head = NULL;
Node*tail = NULL; 
int size=0;


public:

    ~linkedList(){              //destructor
        Node* temp=head;
        while(head!=NULL){            //NULL= nullptr
            head=head->next;
            delete(temp);
            temp=head;
        }
    }

    void print(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }


    bool isEmpty(){
        return head==NULL && tail==NULL;
    }

    void addFirst(int data){
        Node *node = new Node(data);
        size++;
        if(head==NULL){
            head = node;
            tail = node;
                    
        }else{
            node->next=head;
            head = node;
            
        }
    }

    void addLast(int data){
        
        Node* node = new Node(data);
        size++;
        if(tail==NULL){
            head=node;
            tail=node;
        }else{
            tail->next = node;
            tail=node;
        }
    }

    int removeFirst(){
        
        if(head==tail){
            tail=NULL;
            size--;
        }
        Node* rn ;
        
        if(head!=NULL){
            rn = head;
            head=head->next;
            size--;
        }

        int data =head==NULL?-1: rn->data;
        delete(rn);
        return data;
    }

    Node* getAt(int idx){
        if(idx==0) return head;  //if(idx<0) throws new NullPointerException(); - Java
        Node* temp = head;
        while(idx!=0){
            temp=temp->next;
            idx--;
        }
        return temp;
    }

    int removeLast(){
        Node* rn = NULL;
        if(size==1){
            rn = head;
            head=NULL;
            tail=NULL;
            size--;
        }else if(size>1){
            Node* temp = getAt(size-2);
            rn=temp->next;
            tail=temp;
            size--;
        }

        int data = size!=0?rn->data:-1;
        delete(rn);
        return data;
    }

    void addAt(int idx,int data){
        if(idx>size || idx<0) return;
        if(idx==0) addFirst(data);
        else if(idx==size) addLast(data);

        else{
        Node* node = new Node(data);

        Node* temp = getAt(idx-1);

        node->next=temp->next;
        temp->next = node;
        }

    }

    int removeAt(int idx){
        if(idx>=size || idx<0) return 0;
        if(idx==0) removeFirst();
        else if(idx==size-1) removeLast();
        else{
        
        Node* temp = getAt(idx-1);
        Node* forward = getAt(idx);
        temp->next = forward->next;
        delete(forward);
        }
    }

    Node* mid(){
        Node*slow = head;
        Node*fast = head;

        while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    //REVERSE

//1. Iterative method reversing data  O(n^2)
void reverseData(){
    int i = 0,j=size-1;
    while(i!=j){
        swap(getAt(i)->data,getAt(j)->data);
        i++;
        j--;
    }
}

//2. recursive method reversing data  O(n) (rec not adviced as cant handle large LL) 
private:
class pairReve{
    public:
    Node* prevNode = NULL;
};

void reverseData(Node* node, pairReve* prev, int level){   //this will be called using another func 
                                                    // as main cant access node, prev
    if(node==NULL){
        return;
    }
    reverseData(node->next,prev,level+1);

    if(level > this->size/2){
        int temp = prev->prevNode->data;
        prev->prevNode->data = node->data;
        node->data = temp;

        prev->prevNode = prev->prevNode->next;
    }
}

public:
void reverseDataRecurr(){
    pairReve* prev = new pairReve();
    prev->prevNode = head;
    reverseData(head,prev,0);

}


//REVERSE USING POINTER REVERSAL
//O(n)
private:
Node* reverseList_(Node* node){
    Node*prev = NULL;
    Node*curr = node;

    while(curr!=nullptr){
        Node* forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
}

public:
void reverseList(){
    Node* prev = reverseList_(head);
    tail = head;
    head = prev;
}

    bool isPlaindrome()  //this is also reverselist method where only data is reversed not the pointer as above
    {
        Node *midNode = mid();
        Node *nhead = midNode->next;
        midNode->next = nullptr;

        Node *prev = reverseList_(nhead);

        Node *list1 = prev;
        Node *list2 = head;
        bool flag = true;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->data != list2->data)
                flag = false;

            list1 = list1->next;
            list2 = list2->next;
        }

        prev = reverseList_(prev);
        midNode->next = nhead;

        return flag;
    }

//reorder list leetcode
    void fold(){
        Node *midNode = mid();
        Node *nhead = midNode->next;
        midNode->next = nullptr;

        Node *prev = reverseList_(nhead);

        Node *curr2 = prev;
        Node *curr1 = head;

        
        while(curr2 !=NULL){
        Node *cn1 = curr1->next;
        Node *cn2 = curr2->next;

        curr1->next = curr2;
        curr2->next = cn1;

        curr1= cn1;
        curr2=cn2;
        }
        
        if(curr1==nullptr) tail = nhead;
        else tail = curr1;
    }


    void unfold(){
        Node* prev = head;
        Node* forw = prev->next;
        Node* list2 = forw;
        while(prev!=nullptr || forw!=nullptr){
            Node* cn1 = forw->next;
            Node* cn2 = cn1->next;

            prev->next = cn1;
            forw->next = cn2;

            prev = cn1;
            forw = cn2;

        }
        Node* nhead = reverseList_(list2);
        tail->next = nhead;
        tail=list2;
    }


    private:
    Node *detectCycle_()
    {

        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return slow;
        }

        return nullptr;
    }
public:
    bool detectCycle()
    {
        return detectCycle_() != nullptr;
    }

    int intersectionPoint()
    {
        Node *node1 = detectCycle_();

        if (node1 != nullptr)
        {
            Node *node2 = head;
            while (node2 != node1)
            {
                node1 = node1->next;
                node2 = node2->next;
            }

            return node1->data;
        }
        return -1;
    }

    struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

    ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
        if(A==nullptr) return B;
        if(B==nullptr) return A;       

        ListNode* head=new ListNode(-1); //dummy node
        ListNode* curr=head;

        while(A->next!=nullptr || B->next!=nullptr){
            if(A->val <= B->val){
                curr->next=A;
                A=A->next;
            }else{
                curr->next=B;
                B=B->next;
            }
            curr=curr->next;
        }

        if(A->next==nullptr) curr->next=B;
        else curr->next=A;

        return head->next;
    }


};

void solve(){
    linkedList li ;
    li.addFirst(3);
    li.addFirst(2);
    li.addFirst(1);

    li.addLast(4);
    li.addLast(5);  //12345
    
    li.addLast(6);
    li.addLast(7);
    //cout<<li.isPlaindrome();

    li.fold();
    //li.unfold();
    //li.reverseData();
    //li.removeAt(2);  // = 1245
    //li.removeAt(1);  // = 145
    
    //li.reverse();
    
    //cout<<li.mid();

    li.print();
    
}

int main(int argc, char const *argv[])
{
    solve();
    return 0;
}
