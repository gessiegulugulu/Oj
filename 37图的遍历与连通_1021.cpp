#include <iostream>
#include <vector>
#include <set>
using namespace std;

/**
 * 将图看成树，树的高度取决于选哪个点作为根。找到树最高的根
 * 输入：
 * 第一行：结点数量N
 * N-1行：边的两个端点
 * 
 * 输出：
 * 树最高的根节点
 * Error: K components 不是树的情况
 * 
 * */

int N;
int G[10010][10010];
bool visit[10010];
int components = 0;
int maxH = 0;
vector<int> vertexs;
set<int> roots; //最深树的根

void dfs(int node, int h)
{
    if (h > maxH)
    {
        vertexs.clear();         //清空之前的结点
        vertexs.push_back(node); //放进去当前的结点
        maxH=h;
    }
    else if (h == maxH)
    {
        vertexs.push_back(node);
    }
    visit[node] = true;

    for (int i = 1; i <= N ; i++)
    {
        if (visit[i] == false && G[node][i] == 1)
        {
            dfs(i, h + 1);
        }
    }
}
//NOTE:dfs的应用：用dfs找到最深的叶子结点

int main()
{
    cin >> N;
    int v1, v2;
    int height[2] = {0, N};
    for (int i = 0; i < N - 1; i++)
    {
        cin >> v1 >> v2;
        G[v1][v2] = G[v2][v1] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        // 从1开始深度搜索，相联通的点都被标记true
        //下一次循环还false的就是下一个连通分量的开始
        if (visit[i] == false)
        {
            dfs(i, 1);
            components++;
            if (i == 1)
            {
                //获取到第一次dfs得到的最深的叶节点
                for (int j = 0; j < vertexs.size(); j++)
                {
                    roots.insert(vertexs[j]);
                }
            }
        }
    }

    if (components >= 2)
    {
        cout << "Error: " << components << " components" << endl;
    }
    else
    {
        //可以转换成树  从之前的叶节点中反向dfs
        fill(visit, visit + 10010, false);
        vertexs.clear();

        dfs(*roots.begin(), 1);

        for (int j = 0; j < vertexs.size(); j++)
        {
           
            roots.insert(vertexs[j]);
        }

        for (set<int>::iterator i = roots.begin(); i != roots.end(); i++)
        {
            cout << (*i) << endl;
        }
    }

    return 0;
}