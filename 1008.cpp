/* ********************************
 * 输入：N N个正数
 * 输出：电梯运行的时间
 * 条件：
 * 1.上行6s,下行4s,停留5s
 * 2.初始在0，最后不必回到0
 * ******************************/

#include <iostream>
using namespace std;

int main(){
    int num;
    int time=0;
    int now=0;
    cin>>num;
    int *floors=new int[num];
    for(int i=0;i<num;i++){
        cin>>floors[i];
        if(floors[i]>now){
            time+=(floors[i]-now)*6;
        }
        else if(floors[i]<now){
            time+=(now-floors[i])*4;
        }
        now=floors[i];
        time+=5;
    }
    cout<<time<<endl;


    return 0;
}