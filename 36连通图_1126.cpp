#include <iostream>
#include <vector>
using namespace std;

/**
 * eulerian路：经过图中每条边一次
 * eulerian圈：eulerian路，首尾衔接在同一点
 * eulerian图：所有点度数都为奇
 * 输入：
 * 第一行：N点数 M边数
 * M行：每边的两个顶点
 * 
 * 输出：
 * 每点的度数
 * 什么图
 * */

int M,N;
int G[510][510]={0};
int visit[510];
int cnt;
void dfs(int node){
    visit[node]=true;
    cnt++;
    for(int i=1;i<=N;i++){
        if(visit[i]==false&&G[node][i]==1){
            dfs(i);
        }
    }
}

int main(){
    fill(visit,visit+N+1,true);//NOTE：fill函数全局赋值
    int degree[510]={0};
    vector<int> even;
    int v1,v2;

    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>v1>>v2;
        G[v1][v2]=G[v2][v1]=1;
    }//存储图

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            degree[i]+=G[i][j];
        }
        
        cout<<degree[i]<<(i==N?"":" ");
        
        if(degree[i]%2==1){
            even.push_back(i);
        }
    }//1-N度数数组
    cout<<endl;

    //判断
    dfs(1);
    if(even.size()==0&&cnt==N){
        cout<<"Eulerian"<<endl;
    }
    else if(even.size()==2&&cnt==N){
        cout<<"Semi-Eulerian"<<endl;

    }
    else{
        cout<<"Non-Eulerian"<<endl;
    }



    return 0;
}