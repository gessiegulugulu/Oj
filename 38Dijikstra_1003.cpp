#include <iostream>
#include <vector>
using namespace std;

const int INF=1e6;
int ncity,mroad,c1,c2;
int count_roads=0;
int count_rescue=0;//更大时更新
vector<int> Pass;

int main(){
    /******************
     * 最短路径问题 dijkstra&floyd
     * dijkstra 路径矩阵不断更新
     * floyd 图的路径不断更新
     * ****************/
    cin>>ncity>>mroad>>c1>>c2;

    vector<vector<int>> G(ncity,vector<int>(ncity));
    int *rescues=new int(ncity);
    for(int i=0;i<ncity;i++){
        cin>>rescues[i];
    }
    //初始化临界表
    for(int i=0;i<ncity;i++){
        for(int j=0;j<ncity;j++){
            if(i==j){
                G[i][j]=0;
            }
            else{
                G[i][j]=INF;
            }
        }
    }

    //邻接表填充数据
    for(int i=0;i<mroad;i++){
        int a,b,c;
        cin>>a>>b>>c;
        G[a][b]=c;
        G[b][a]=c;
    }

    int dis=INF;//更小时更新

 

    bool *visit=new bool(ncity);
    visit={false};
    int length=0;

    dfs(G,c1,c2,visit,length);
    

    return 0;
}

void dfs(vector<vector<int>> G,int from,int to,bool visit[],int length){

    visit[from]=true;
    // if(from==to){
    //     if(G[from][i])
    // }

    for(int i=0;i<ncity;i++){
        if(G[from][i]<INF&&G[from][i]>0&&visit[i]==false){
            Pass.push_back(i);
            length+=G[from][i];
            dfs(G,i,to,visit,length);
        }
    }

}

void Dijkstra(int s,int d[],bool vis[],vector<vector<int>> G,vector<int> Pass){//s为起点
    // for(int i=0;i<ncity;i++){
    //     d[i]=INF;
    // }//整体距离数组赋值为最大值
    
    for(int i=0;i<ncity;i++){
        int u=-1;
        int MIN=INF;
        //寻找权值最小的点u
        for(int j=0;j<ncity;j++){
            if(vis[j]==false&&d[j]<MIN){
                u=j;
                MIN=d[j];
            }
        }
        vis[u]=true;
        Pass.push_back(u);
        for(int i=0;i<ncity;i++){
            //对于每一个u可达的v来说
            if(G[u][i]<INF){
                if(d[i]>d[u]+G[u][i]){
                    d[i]=d[u]+G[u][i];
                }
            }
        }
    }

    

}