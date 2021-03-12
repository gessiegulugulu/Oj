#include <iostream>
#include <vector>
using namespace std;
/**
 * 城市之间的距离、高速路费
 * 最短路径 最小花销
 * 
 * 输出
 * 沿线城市 距离 花销
 * */


int N,M,S,D;//城市个数，高速个数，开始城市，目标城市
int G[510][510];
bool visit[510]={false};
int weight[510][510];
int pre[510];
const int INF=1000000000;

void dfs(int node){
    if(node==S){
        cout<<node<<" ";
        return;
    }
    dfs(pre[node]);
    cout<<node<<" ";
}

int main(){
    cin>>N>>M>>S>>D;
    int v1,v2,tempDis,tempCost;
    fill(G[0],G[0]+510*510,INF);
    for(int i=0;i<M;i++){
        cin>>v1>>v2>>tempDis>>tempCost;
        G[v1][v2]=G[v2][v1]=tempDis;
        weight[v1][v2]=weight[v2][v1]=tempCost;
    }

    int d[510];
    fill(d,d+510,INF);
    d[S]=0;
    int cost[510];
    fill(cost,cost+510,INF);
    cost[S]=0;


    //dijkstra
    for(int i=0;i<N;i++){
        int u=-1;
        int min=INF;
        for(int j=0;j<N;j++){
            if(visit[j]==false&&d[j]<min){
                u=j;
                min=d[j];
            }
        }
        if(u==-1){
            break;
        }
        visit[u]=true;
        for(int v=0;v<N;v++){
            if(visit[v]==false&&G[u][v]!=INF){
                if(G[u][v]+d[u]<d[v]){
                    d[v]=G[u][v]+d[u];
                    cost[v]=weight[u][v]+cost[u];
                    pre[v]=u;
                }
                else if(G[u][v]+d[u]==d[v]){
                    if(weight[u][v]+cost[u]<cost[v]){
                        d[v]=G[u][v]+d[u];
                        cost[v]=weight[u][v]+cost[u];
                        pre[v]=u;
                    }
                }
            }
        }

    }

    dfs(D);
    cout<<d[D]<<" "<<cost[D]<<endl;

    return 0;
}