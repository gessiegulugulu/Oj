#include <iostream>
#include <vector>
using namespace std;

/**
 * 输入：
 * 第一行：c_max 偶数，车站的最大容量  N车站总数（小等500） S_p问题车站的序号（1~N）  M路径数
 * N个非负数（1~N）：当前站点的车辆数
 * M行：起点 终点  距离
 * 
 * 输出：
 * 要送的自行车 路径 带回去的车辆数（带回去最少的车辆为准）
 * */
//NOTE Dijkstra+DFS的用法！！

const int INF = 1000000000;
int G[510][510];
int visit[510] = {false};
vector<int> pre[510];
vector<int> path;
vector<int> tempPath;
int minSend = INF;
int minBack = INF;
int Cmax, N, Sp, M;
vector<int> bikes;

void dfs(int node)
{
    //递归边界
    if (node == 0)
    {
        //到达路径起点
        tempPath.push_back(node);
        int send = 0;
        int back = 0;
        int temp = 0;
        for (int i = 0; i < tempPath.size(); i++)
        {
            temp += bikes[tempPath[i]];
        }
        if(temp<=0){
            send=0-temp;
            back=0;
        }
        else{
            send=0;
            back=temp;
        }

        if(send<minSend){
            minSend=send;
            minBack=back;
            path=tempPath;
        }
        else if(send==minSend&&back<minBack){
            minBack=back;
            path=tempPath;
        }
        tempPath.pop_back();
        return;
    }
    //递归
    tempPath.push_back(node);
    for (int i = 0; i < pre[node].size(); i++)
    {
        dfs(pre[node][i]); //递归当前结点的前驱结点
    }
    tempPath.pop_back(); //遍历完全部前驱结点，删除当前结点
}

int main()
{
    //准备图、每个点的权值

    int v1, v2, L;
    cin >> Cmax >> N >> Sp >> M;
    bikes.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        int temp;
        cin >> temp;
        bikes[i] = temp - Cmax / 2;
    }
    fill(G[0], G[0] + 510 * 510, INF);
    for (int i = 0; i < M; i++)
    {
        cin >> v1 >> v2 >> L;
        G[v1][v2] = G[v2][v1] = L;
    }

    //dijkstra寻找最短路径
    // int weight[510]={0};
    int d[510] = {0};

    // path.resize(N+1);
    fill(d, d + 510, INF);
    d[0] = 0;
    for (int i = 0; i < N; i++)
    {
        int u = -1;
        int min = INF;
        for (int j = 0; j < N; j++)
        {
            if (visit[j] == false && d[j] < min)
            {
                u = j;
                min = d[j];
            }
            if (u == -1)
            {
                break;
            }
            visit[u] = true;
            for (int k = 0; k < N; k++)
            {
                if (visit[k] == false && G[u][k] != INF)
                {
                    if (G[u][k] + d[u] < d[k])
                    {
                        //经过u的d[k]更优
                        d[k] = G[u][k] + d[u];
                        pre[k].clear();
                        // path[k]=path[u];
                        pre[k].push_back(u);
                    }
                    else if (G[u][k] + d[u] == d[k])
                    {
                        pre[k].push_back(u);
                    }
                }
            }
        }
    }
    dfs(Sp);
    //path里面存储了最短路径
    cout<<minSend<<" ";
    for(int i=path.size()-2;i>=0;i--){
        cout<<"->"<<path[i];
    }
    cout<<" "<<minBack<<endl;

    return 0;
}