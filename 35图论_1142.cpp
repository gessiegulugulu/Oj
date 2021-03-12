#include <iostream>
#include <vector>
using namespace std;

/**
 * clique是无向图中点vertice的子集，集和中任意两个顶点都可达
 * 最大连通图:再多一个点就不联通了
 * 判断给出的点集是不是最大连通图
 * 输入：
 * 第一行：两个正数Nv≤ 200:顶点数 Nb：边数
 * 接下来Ne行：边的两个端点
 * 
 * ≤100的正整数M
 * M行：正整数K（≤Nv） k个顶点
 * 
 * 输出：Yes最大连通图
 *      Not Maximal 联通不最大
 *      Not a Clique 不联通
 * */

int main()
{
    int G[210][210]; //图
    int Nv;
    int Ne;
    cin >> Nv >> Ne;
    int v1, v2;
    for (int i = 0; i < Ne; i++)
    {
        cin >> v1 >> v2;
        G[v1][v2] = G[v2][v1] = 1;
    } //存图

    int M; //M 组点集
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int k;
        int flag = 2; //1不连通 2最大联通 0联通不最大
        //NOTE：最好按照判断指标使用bool变量看属性

        cin >> k;     //子集和中点的个数
        vector<int> clique(k);
        bool subset[210] = {false};

        for (int i = 0; i < k; i++)
        {
            cin >> clique[i];
            subset[clique[i]] = true;
        }
        //判断是不是联通？最大？
        //联通图中的边数n*(n-1)/2

        //联通？
        for (int i = 0; i < k; i++)
        {
            if (flag == 1)
            {
                break; //NOTE：!重要！多层循环外面套一个判断break，减少时间
            }
            for (int j = i + 1; j < k; j++)
            {
                if (G[clique[i]][clique[j]] != 1)
                {
                    flag = 1;
                    break;
                }
            }
        }
        //最大？
        if (flag == 2)
        {
            for (int i = 1; i <= Nv; i++)
            {
                if (subset[i] == false)
                {
                    int res = 1;
                    for (int j = 0; j < k; j++)
                    {
                        res = res & G[i][clique[j]];
                    }
                    if (res == 1)
                    {
                        flag = 0;
                        break;
                    }
                }
            }
        }
        cout << (flag == 1 ? "Not a Clique" : (flag == 0 ? "Not Maximal" : "Yes")) << endl;
    }

    return 0;
}