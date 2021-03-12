#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
    // int data;
    int kchild;
    vector<int> child;
}Tree[100];
//树的结点数组，data是数据，child指向子结点
//Node
int Nnode;
int Mnleaf;

int main(){

    cin>>Nnode>>Mnleaf;
    //建立树
    for(int i=0;i<Mnleaf;i++){
        char temp[2];
        cin >> temp;
        int index=temp[0]*10+temp[1];
        cin>>Tree[index].kchild;
        for(int j=0;j<Tree[index].kchild;j++){
            char data_child[2];
            cin>>data_child;
            Tree[index].child.push_back(data_child[0]*10+data_child[1]);
        }
    }

    //对树进行层序遍历，每层都输出没有子节点的结点个数
    return 0;
}

void LayerOrder(){
    queue<int> Q;
    Q.push(1);
    while(!Q.empty()){
        int front=Q.front();
        Q.pop();
        for(int i=0;i<Tree[front].kchild;i++){
            int child=Tree[front].child[i];
            
        }
    }
    return;
}
