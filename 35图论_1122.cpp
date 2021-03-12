#include <iostream>
#include <vector>
#include <set>
using namespace std;
/* **************************
 * 找到一个环路，包含图中每一个点
 * 判断给出的路是不是环路
 * 输入：
 * 第一行：两个正数：N 点数，M 无向图边数
 * M行：每边的两端点
 * 下一行：正整数K
 * K行
 * 
 * 输出：是、否
 * ************************/
int G[210][210];//图
bool visit[1010];//访问
int n;//无向图点数
int main(){
    int m;
    int v1,v2;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        cin>>v1>>v2;
        G[v1][v2]=1;
        G[v2][v1]=1;
    }

    int k;
    cin>>k;
    vector<bool> answers(k);
    for(int i=0;i<k;i++){
        int nk;
        cin>>nk;
        bool answer=true;
        vector<int> circle(nk);

        for(int i=0;i<nk;i++){
            cin>>circle[i];
        }
        //判断是不是哈密尔圈
        set<int> vertex(circle.begin(),circle.end());
        if(vertex.size()!=n||circle[0]!=circle[nk-1]||circle.size()!=vertex.size()+1){
            //没有包含图中每一个点||没构成环||只有首尾元素重复
            // cout<<"NO"<<endl;
            answer=false;
            // break;
        }

        for(int i=0;i<nk-1;i++){
            if(G[circle[i]][circle[i+1]]==0){
                //即为相邻的两个点不联通，不是哈密尔圈
                // cout<<"NO"<<endl;
                answer=false;
                break;
            }
        }
        
        answers[i]=answer;

    }

    for(int i=0;i<k;i++){
        cout<<(answers[i]?"YES":"NO")<<endl;
    }

    return 0;
}