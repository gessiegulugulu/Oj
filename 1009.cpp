#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int k1,k2;
    cin>>k1;

    int temp;
    int max1,max2;
    cin>>max1;//第一个多项式的最高次数
    float *poly1=new float[max1+1];
        for(int i=0;i<max1+1;i++){
        poly1[i]=0.0;
    }
	// int poly1[2];
    cin>>poly1[max1];
    for(int i=0;i<k1-1;i++){
        cin>>temp;
        cin>>poly1[temp];
    }

    cin>>k2;
    cin>>max2;
    float *poly2=new float[max2+1];
            for(int i=0;i<max2+1;i++){
        poly2[i]=0.0;
    }
    cin>>poly2[max2];
    for(int i=0;i<k2-1;i++){
        cin>>temp;
        cin>>poly2[temp];
    }

    float *poly3=new float[max1+max2+1];
    for(int i=0;i<max1+max2+1;i++){
        poly3[i]=0.0;
    }

    int count=0;//计数非0项
    for(int i=0;i<=max1;i++){
        for(int j=0;j<=max2;j++){
            float sum=poly1[i]*poly2[j];
            if(poly3[i+j]==0.0&&sum+poly3[i+j]!=0.0){
                count++;//从0变成非0
            }
            else if(poly3[i+j]!=0.0&&sum+poly3[i+j]==0.0){
                count--;//从非0变成0
            }
            poly3[i+j]+=sum;
        }
    }

    // for(int i=max1+max2;i>=0;i--){
    //     if(poly3[i]!=0.0){
    //         count++;
    //     }
    // }
    //count单独放在外面就通过了第一个测试点
    //那我原来的问题出在哪呢？？
    //可能加上--就好了？

    cout<<count;
    for(int i=max1+max2;i>=0;i--){
        if(poly3[i]!=0.0){
            cout<<" "<<i<<" "<<fixed<<setprecision(1)<<poly3[i];
        }
    }
    cout<<endl;

    return 0;
}