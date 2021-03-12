#include <iostream>
#include <vector>
using namespace std;
/**
 * 输入：
 * 第一行 N城市数 M路数 C1当前所在城市 C2拯救城市
 * N个数：每个城市的救援队伍数量
 * M行：路的两端 L路的长度
 * 
 * 输出：
 * c1到c2的最短路径数量   能集和到的最多救援队伍数量
 * */
const int INF = 1000000000;
int G[510][510];
bool visit[510] = {false};
int dis[510];
vector<int> rescue; //救援队
int M, N;

int main()
{
    int c1, c2, L;
    int v1, v2;
    cin >> N >> M >> c1 >> c2;
    rescue.resize(N + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> rescue[i];
    }

    fill(G[0],G[0]+510*510,INF);//NOTE 带权值的图不可达为INF，注意fill的方式
    for (int i = 0; i < M; i++)
    {
        cin >> v1 >> v2 >> L;
        G[v1][v2] = G[v2][v1] = L;
    }

    fill(dis, dis + 510, INF);
    dis[c1] = 0;
    
    int count[510] = {0};  //计算重复的最短路径数量
    count[c1]=1;
    int weight[510] = {0}; //计算经过的点的权值，也就是救援队伍之和
    weight[c1]=rescue[c1];

    for (int i = 0; i < N; i++)
    {                  //循环n次
        int u = -1;    //u点使d[u]最小
        int min = INF; //min存最小的d[u]
        for (int j = 0; j < N; j++)
        {
            if (visit[j] == false && dis[j] < min)
            {
                //未访问顶点中d最小的，更新
                u = j;
                min = dis[j];
            }
        }
        if (u == -1)
        {
            break;
        }                //找不到最小的，说明剩下的不连通
        visit[u] = true; //标记u为已经访问
        for (int k = 0; k < N; k++)
        {
            if (visit[k] == false && G[u][k] != INF)
            {
                if (dis[u] + G[u][k] < dis[k])
                {
                    //若k未访问&&u能到达k&&经过u的话，d[k]更优
                    dis[k] = dis[u] + G[u][k];
                    count[k] = count[u]; //经过v的路径数和经过u的路径数一样
                    weight[k] = weight[u] + rescue[k];
                }
                else if (dis[u]+G[u][k]==dis[k])
                {
                    count[k]+=count[u];
                    if(weight[u]+rescue[k]>weight[k]){
                        weight[k]=weight[u] + rescue[k];
                    }
                }
            }
        }
    }

    cout<<count[c2]<<" "<<weight[c2]<<endl;

    return 0;
}