#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

/**
 * 旅行者问题：遍历图的最短路径（首尾衔接）
 * 输入：
 * 第一行：两个正数 N（城市数2~200） M（无向图边数）
 * M行：v1 v2 距离
 * 正数K
 * K行：path n v1v2..
 * 
 * 输出：
 * k行：
 * Path X：
 * 路径总长、NA
 * （属性：iscycle？issimple？）
 * */

int G[210][210] = {0};
int main()
{
    int Nv, Ne;
    int v1, v2, distance;
    cin >> Nv >> Ne;
    for (int i = 0; i < Ne; i++)
    {
        cin >> v1 >> v2 >> distance;
        G[v1][v2] = G[v2][v1] = distance;
    }

    int k;
    cin >> k;
    int shortestDist[2] = {1, 99999999};
    //NOTE：C++中int的最大值为INT_MAX
    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;
        vector<int> path(n);
        set<int> passCity;
        int totalDist = 0;
        bool isNA = false;

        if(n==1){
            cout<<"Path "<<i+1<<": "<<"NA (Not a TS cycle)"<<endl;
            continue;
        }

        cin >> path[0];
        passCity.insert(path[0]);
        for (int i = 1; i < n; i++)
        {
            cin >> path[i];
            if (G[path[i - 1]][path[i]] == 0)
            {
                isNA = true;
            }
            totalDist += G[path[i - 1]][path[i]]; //路径总长
            passCity.insert(path[i]);
        }

        bool isCircle = true; //is a circle visit every city
        bool isSimple = true; //is simple

        cout << "Path " << i + 1 << ": " << (isNA ? "NA" : (to_string(totalDist))) << " (";
        //判断？遍历环路
        if (path[0] != path[n - 1] || passCity.size() != Nv || isNA)
        {
            //首尾不相接||经过的城市不够||中间没有路
            isCircle = false;
            cout << "Not a TS cycle)" << endl;
        }
        if (isCircle == false)
        {
            continue;
        }

        if (totalDist < shortestDist[1])
        {
            shortestDist[0] = i + 1;
            shortestDist[1] = totalDist;
        }
        //判断？simple
        if (n != Nv+1)
        {
            //重复的城市不止一个
            isSimple = false;
            cout << "TS cycle)" << endl;
        }
        else
        {
            cout << "TS simple cycle)" << endl;
        }
    }
    cout << "Shortest Dist(" << shortestDist[0] << ") = " << shortestDist[1] << endl;

    return 0;
}