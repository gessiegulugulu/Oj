#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int cnt = 0;
void dfs(int node, int temp[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << i << " " << j << " " << temp[i][j] << endl;
        }
    }

    for (int i = 0; i <=1 ; i++)
    {
        if (temp[node][i] != 0)
        {

            temp[node][i] = temp[i][node] = 0;
            dfs(i, temp);
        }
    }
}

int main()
{
    // int temp;
    // // cin >> temp;
    // // cout<<temp;
    // int a[2][2];
    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         a[i][j] = i + j;
    //     }
    // } 
    //  dfs(1, a);
	//  cout << "a" << endl;
    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         cout << i << " " << j << " " << a[i][j]<<endl;
    //     }
    // }


    string a="1.23400";

    return 0;
}