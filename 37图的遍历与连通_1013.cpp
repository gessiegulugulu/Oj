#include <iostream>
using namespace std;
int G[1010][1010];//图
bool visit[1010];//是否访问
int n;

void dfs(int node){
    visit[node]=true;
    for(int i=1;i<=n;i++){
        if(visit[i] == false && G[node][i] == 1)
            dfs(i);
    }
}

int main(){
    int m,k;
    int a,b;//路的两端
    cin>>n>>m>>k;//城市、路、check的城市数量
    for(int i=0;i<m;i++){
        cin>>a>>b;
        G[a][b]=G[b][a]=1;
    }//存图

    for(int i=0;i<k;i++){
        fill(visit,visit+1010,false);
        cin>>a;
        int count=0;
        visit[a]=true;
        for(int i=1;i<=n;i++){
            if(visit[i]==false){
                dfs(i);
                count++;
            }
        }
        cout<<count-1<<endl;
     }

    
    
    return 0;
}