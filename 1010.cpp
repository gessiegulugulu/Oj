#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//输入：两个数字，各自由0-9a-z构成 tag tag的进制
//输出:
//1 进制
//2 Impossible

int n2decimal(string n,int radix){
    //返回十进制数字
    int res=0;
    for(int i=n.size()-1;i>=0;i--){
        int a;
        if(int(n[i])>58){
            a=int(n[i])-int('a')+10;
        }
        else{
            a=int(n[i])-int('0');
        }
        res+=a*pow(radix,n.size()-1-i);
        // cout<<pow(radix,i)<<" ";
    }
    return res;
}
void compare(int standard,string n){
    //找到可能进制的最小值
    long long radix_min=0;
    for(long long i=0;i<n.size();i++){
        if(int(n[i])>radix_min){
            radix_min=int(n[i]);
        }
    }
    if(radix_min>57){
        radix_min=radix_min-int('a')+11;
    }
    else if(radix_min<57){
        radix_min=radix_min-int('0')+1;
    }
    // cout<<radix_min<<endl;

    long long low=radix_min;
    long long high=standard;
    while(low<=high){
        long long mid=(low+high)/2;
        if(standard==n2decimal(n,mid)){
            cout<<mid<<endl;
            return;
        }
        else if(standard>n2decimal(n,mid)){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }


    //循环增加进制比较
    // for(int i=radix_min;;i++){
    //     if(n2decimal(n,i)==standard){
    //         cout<<i<<endl;
    //         return;
    //     }
    //     if(n2decimal(n,i)>standard){
    //         cout<<"Impossible"<<endl;  
    //         return;
    //     }
    // }

    
    cout<<"Impossible"<<endl;    
}



int main(){
    string n1,n2;
    int tag;
    int radix_tag;
    cin>>n1>>n2>>tag>>radix_tag;
    int standard;//已知数的十进制
    if(tag==1){
        standard=n2decimal(n1,radix_tag);
        compare(standard,n2);
    }
    else if(tag==2){
        standard=n2decimal(n2,radix_tag);
        compare(standard,n1);
    }
    // cout<<standard<<endl;

    //a--97 9--48+9=57     

    return 0;
}