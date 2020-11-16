#include<iostream>
#include<vector>

#define vi vector<int>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
    }

    Node(int data,Node* left,Node* right){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

int idx=0;
Node* createTree(vi &arr){
    if(idx==arr.size() || arr[idx]==-1){
        idx++;
        return nullptr;
    }

    Node* node = new Node(arr[idx]);
    idx++;
    node->left = createTree(arr);
    node->right = createTree(arr);

    return node;
}

void display(Node* node){
    if(node==nullptr) return;

    string ans="";
    ans+=node->left!=nullptr?to_string(node->left->data):".";
    ans+="<- " + to_string(node->data) + " ->"; 
    ans+=node->right!=nullptr?to_string(node->right->data):".";

    cout<<ans<<endl;
    display(node->left);
    display(node->right);
}

bool findData(Node* node,int data){
    if(node==nullptr) return false;
    if(node->data == data) return true;

    bool res = false;
    res = res || findData(node->left,data);
    res = res || findData(node->right,data);

    return res;
}

int height(Node* node){
    return node==nullptr?-1:max(height(node->left),height(node->right))+1;
}

int size(Node* node){
    return node==nullptr?0:size(node->left)+size(node->right)+1;
}

int maxEle(Node* node){
    if(node==nullptr) return -1e8;
    return max(max(node->left->data,node->right->data),node->data);
}

bool nodeToRootPath(Node* node,vi &ans,int data){
    if(node==nullptr) return false;
    if(node->data==data){
        ans.push_back(data);
        return true;
    }

    bool res = false;
    res = res || nodeToRootPath(node->left,ans,data);
    res = res || nodeToRootPath(node->right,ans,data);

    if(res) ans.push_back(node->data);
    return res;
}

int LCA(Node* node,int data1,int data2){
    vi list1 ;
    vi list2;
    nodeToRootPath(node,list1,data1);
    nodeToRootPath(node,list2,data2);

    int prev;
    int i=list1.size()-1;
    int j=list2.size()-1;

    while(i>=0 && j>=0){

        if(list1[i]!=list2[j]) break;

        prev=list1[i];
        i--;
        j--;
    } 

    return prev;
}

int diameter(Node* node){
    if(node==nullptr) return 0;

    int ld =diameter(node->left);
    int rd =diameter(node->right);

    int lh=height(node->left);
    int rh=height(node->right);

    int myDia = lh+rh+2;
    return max(max(ld,rd),myDia);
}

int maxSum = -1e8; // we cant make this global for various test cases as it needs to be initialized again n again
int leafToleafMaxSum(Node* node){
    if(node->left ==nullptr && node->right==nullptr) return node->data;

    int leftnodetoleaf = leafToleafMaxSum(node->left);
    int rightnodetoleaf = leafToleafMaxSum(node->right);
    
    if(node->left !=nullptr && node->right!=nullptr){
        int sum = leftnodetoleaf + rightnodetoleaf + node->data;
        maxSum = max(maxSum,sum);
        return max(leftnodetoleaf,rightnodetoleaf) + node->data;
    }

    return node->left==nullptr?rightnodetoleaf:leftnodetoleaf + node->data;
}


//BST in java


int main(){
    vi arr ={10,20,40,60,-1,-1,70,-1,-1,50,80,
           -1,-1,-1,30,90,-1,110,150,-1,-1,-1,100,120,-1,-1,-1};
    Node* node = createTree(arr);
    display(node);
    cout<<endl;
    //cout<<height(node)<<endl;
    //cout<<size(node)<<endl;
    // vi ans;
    // nodeToRootPath(node,ans,70);
    // for(int ele: ans){
    //     cout<<ele<<" ";
    // }
    cout<<LCA(node,60,70);
return 0;
}