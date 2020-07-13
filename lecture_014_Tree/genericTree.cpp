#include<iostream>
#include<vector>
#include<stdio.h>
#include<stack>
#include<queue>

using namespace std;

class Node{
    public:
    int data;
    vector<Node*>childs;
    Node(int data){
        this->data=data;
    }
};

int size(Node* root){
    int s=0;
    for(Node*child:root->childs){
        s+=size(child);
    }
    return s+1;
}

int height(Node*root){
    int h=-1;
    for(Node*child:root->childs){
        h=max(height(child),h);
    }
    return h+1;
}

bool find(Node*node,int data){
    if(node->data==data) return true;

    bool res = false;

    for(Node*child:node->childs){
        res=res||find(child,data);
    }
    return res;
}

Node * createTree(vector<int>&arr){
    stack<Node*>st;

    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]==-1){
            Node*node = st.top();
            st.pop();
            st.top()->childs.push_back(node);
        }else{
            st.push(new Node(arr[i]));
        }
    }
    return st.top();
}

void display(Node*root){
    string ans="";
    ans+=to_string(root->data)+"->";
    for(Node*child:root->childs){
        ans+=to_string(child->data)+", ";
    }
    cout<<ans<<endl;

    for(Node*child:root->childs){
        display(child);
    }
}

bool nodeToRootPath_(Node* node, int data, vector<Node*>& path){
    if(node->data==data){
        path.push_back(node);
        return true;
    }
    bool res=false;
    
    for(Node*child:node->childs){
        res = res || nodeToRootPath_(child,data,path);
    }

    if(res) path.push_back(node);
    return res;
}

vector<Node*>nodeToRootPath(Node* node, int data){
    if(node->data==data){
        vector<Node*> base;
        base.push_back(node);
        return base;
    }
    for(Node*child:node->childs){
        vector<Node*>list=nodeToRootPath(child,data);
        if(list.size()!=0){
            list.push_back(node);
            return list;
        }
    }
        vector<Node*> ans;  //this is for returning null
        return ans;
}

Node* LCA(Node*node,int data1,int data2){
    vector<Node*>list1 = nodeToRootPath(node,data1);
    vector<Node*>list2 = nodeToRootPath(node,data2);

    int i=list1.size()-1;
    int j=list2.size()-1;

    Node*prev = nullptr;
    while(i>=0 || j>=0){
        if(list1[i]->data!=list2[j]->data){
            break;
        }
        prev = list1[i];
        i--;
        j--;
    }
    return prev;
}

// a ques: shortest dist bw 2 nodes: list1.size(root to node dist) + list2.size - 2*LCA(lca tak ka dist root se)



void kAway(Node* node,Node* avoid,int level){
        if(node==avoid) return;
        if(level==0){
            cout<<node->data<<" ";
            return;
        }

        for(Node*child:node->childs){
            kAway(child,avoid, level-1);
        }
        
}
    
void kFar(Node *node,int data,int k){
        vector<Node *> list = nodeToRootPath(node,data);
        Node* avoid =nullptr;
        for(int i=0; i<list.size();i++){
            kAway(list[i], avoid, k-i);
            avoid = list[i];
        }
    }

void levelOrderLineWise(Node *node){
    queue<Node *> que;
    que.push(node);
    int level = 0;

    while (que.size() != 0){
        int size = que.size();

        cout << "Level: " << level << " -> ";
        while (size-- > 0){
            Node *rnode = que.front(); que.pop();
            cout << rnode->data << ", ";

            for (Node *child : rnode->childs) 
                que.push(child);
            
        }

        level++;
        cout << endl;
    }
    cout << endl;
}

bool isSymmetricTree_(Node *node1, Node *node2){ //only based on structure
    if (node1->childs.size() != node2->childs.size())
        return false;

    for (int i = 0, j = node1->childs.size() - 1; i <= j; i++, j--)
    {
        Node *child1 = node1->childs[i];
        Node *child2 = node2->childs[j];

        if (!isSymmetricTree_(child1, child2))
            return false;
    }

    return true;
}

void isSymmetricTree(Node *node){
    cout << isSymmetricTree_(node, node) << endl;
}

bool isMirror(Node *node1, Node *node2){  //mirror in middle of tree , based on data too

    if (node1->childs.size() != node2->childs.size() || node1->data != node2->data)
        return false;

    for (int i = 0, j = node1->childs.size() - 1; j >= 0; i++, j--)
    {
        Node *child1 = node1->childs[i];
        Node *child2 = node2->childs[j];
        if(!isMirror(child1,child2)) return false;
    }

    return true;
}

Node* gettail(Node* node){
    if(node->childs.size()==0){
        return node;
    }
    return gettail(node->childs[0]);
}

void linearize(Node*node){    //O(n^2)
    for(Node*child:node->childs){
        linearize(child);
    }

    for(int i=node->childs.size()-2;i>=0;i--){
        Node* tail = gettail(node->childs[i]);
        tail->childs.push_back(node->childs[i+1]);
        node->childs.pop_back();
    }
}

 
Node* linearizeTree(Node* node){
    if(node->childs.size()==0) return node;

    int n = node->childs.size();
    Node* lastTail = linearizeTree(node->childs[n-1]);

    for(int i=n-2;i>=0;i--){
        Node* secondLastTail = linearizeTree(node->childs[i]);
        secondLastTail->childs.push_back(node->childs[i+1]);
        node->childs.pop_back();
    }
    return lastTail;
}

//flatten
void flatten(Node* node){
    vector<Node*> nchilds;

    for(Node* child:node->childs){ //apne sb childs ko bolo flatten ho aye
        flatten(child);

        nchilds.push_back(child); //child ko new arr m push kro
        for(Node* ch:child->childs){
            nchilds.push_back(ch); //fir uske childs ko push kro
        }
        child->childs.clear(); //arr m agye hai to main tree m se remove kro
    }
    node->childs.clear(); //main node ke childs ko bhi remove kro
    node->childs = nchilds; //root ke aage puri list jod do
}

int main(int args,char**argv){
        vector<int> arr= {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,
        -1,-1,90,-1,-1,40,100,-1,-1,-1};

    Node* node = createTree(arr);
    display(node);
    // vector<Node*>ans = nodeToRootPath(node,80);
    // for(Node* n:ans){
    //     cout<<n->data<<" ";
    // }

    vector<Node*>path;
    nodeToRootPath_(node,80,path);
    for(Node* n:path){
        cout<<n->data<<" ";
    }
    //kFar(node,30,2);
    //linearize(node);
    //display(node);
}






//=========practice==========

// Node* createTree(vector<int>&arr){
//     stack<Node*>st;

//     for(int i=0;i<arr.size();i++){
//         if(arr[i]==-1){
//             Node* node = st.top();
//             st.pop();
//             st.top()->childs.push_back(node);
//         }else{
//             st.push(new Node(arr[i]));
//         }

//     }
//     return st.top();
// }