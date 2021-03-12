#include <iostream>
#include <string>
using namespace std;

void num2english(int num){
    if(num==1){
        cout<<"one";
    }
    else if(num==2){
        cout<<"two";
    }
    else if(num==3){
        cout<<"three";
    }
    else if(num==4){
        cout<<"four";
    }
    else if(num==5){
        cout<<"five";
    }
    else if(num==6){
        cout<<"six";
    }
    else if(num==7){
        cout<<"seven";
    }
    else if(num==8){
        cout<<"eight";
    }
    else if(num==9){
        cout<<"nine";
    }
    else{
        cout<<"zero";
    }
}

int main(){
    string input;
    cin>>input;
    int sum=0;
    for(int i=0;i<input.size();i++){
        sum+=(int(input[i])-48);
        // cout<<"sum"<<i<<":"<<sum<<endl;
    }

    // cout<<"sum:"<<sum<<endl;
    string output=to_string(sum);
    // cout<<"output:"<<output<<endl;

    num2english(int(output[0])-48);

    for(int i=1;i<output.size();i++){
        cout<<" ";
        num2english(int(output[i])-48);
    }
    cout<<endl;

    return 0;

}

