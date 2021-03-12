#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;

/**
 * AB打电话的时长=边的权值
 * gang:两个人以上，互相都相邻，权值之和大于K
 * 
 * 也就是判断每个连通分量的个数，如果连通分量中的总权值大于k那么符合要求
 * */

int G[1010][1010];
int temp[1010][1010];
bool visit[1010];
map<string, int> string2int;
map<int, string> int2string;
map<string, int> res;
set<int> path;

int roadLength = 0;
int id = 0;

int funString2int(string name)
{
    if (string2int[name] == 0)
    {
        id++;
        string2int[name] = id;
        int2string[id] = name;
        return id;
    }
    else
    {
        return string2int[name];
    }
}

void dfs(int node)
{
    path.insert(node);
    visit[node] = true;
    for (int i = 1; i <= id; i++)
    {
        if (temp[node][i] != 0)//NOTE：没用visit数组表示访问过的点，而是权值不为0 
        {
            roadLength += temp[node][i];
            temp[node][i] = temp[i][node] = 0; //NOTE:dfs时归零为了遍历所有的路，并防止回路死循环
            dfs(i);
        }
    }
}//TODO 递归调用数组形参，能不能在递归里面改变，main函数里面不变

int main()
{

    int N, K, time;
    string name1, name2;
    cin >> N >> K; //电话数（小等1000），电话时长
    for (int i = 0; i < N; i++)
    {
        cin >> name1 >> name2 >> time;
        int n1 = funString2int(name1);
        int n2 = funString2int(name2);
        G[n1][n2] = G[n2][n1] += time;
        temp[n1][n2] = temp[n2][n1] += time;
    }

    //处理
    int cnt = 0;
    for (int i = 1; i <= id; i++)
    {

        if (visit[i] == false)
        {
            path.clear();
            roadLength = 0;
            dfs(i);
            // cout << "dfs:" << i << " " << roadLength << endl;
            if (roadLength > K && path.size() > 2)
            {
                cnt++; //计数

                int maxLength = 0;
                int head = 0;

                // /////////////////////////////////////
                // for (set<int>::iterator j = path.begin(); j != path.end(); j++)
                // {
                //     cout << i << "sdfsf" << *j << endl;
                // }
                // ////////////////////////////////////

                for (set<int>::iterator j = path.begin(); j != path.end(); j++)
                {
                    int totalLength = 0;
                    for (set<int>::iterator k = path.begin(); k != path.end(); k++)
                    {
                        totalLength += G[*j][*k];
                        // cout << "headaa" << *j << " " << *k << " " << G[*j][*k] << endl;
                    }
                    if (totalLength > maxLength)
                    {
                        maxLength = totalLength;
                        head = *j;
                    }
                }
                // cout << "head" << head << endl;
                res[int2string[head]] = path.size();
            }
        }
    }

    cout << cnt << endl;
    if (cnt == 0)
    {
        return 0;
    }
    else
    {
        for (map<string, int>::iterator i = res.begin(); i != res.end(); i++)
        {
            cout << (i->first) << " " << (i->second) << endl;
        }
    }
    return 0;
}