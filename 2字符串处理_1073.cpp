#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    // double a;
    // float num = 0;
    int p = 0;
    string aScientific;
    cin >> aScientific;
    if (aScientific[0] == '-')
    {
        cout << "-";
    }
    // num += (aScientific[1] - '0');
    int pos = aScientific.find("E", 3); //NOTE string.find(str2,pos);从pos位开始匹配
    // for (int i = 3; i < pos; i++)
    // {
    //     num += (aScientific[i] - '0') * pow(0.1, i - 2);
    // }
    // cout << num << endl;

    for (int i = aScientific.size() - 1; i > pos + 1; i--)
    {
        p += (aScientific[i] - '0') * pow(10, aScientific.size() - 1 - i);
    }

    // if(aScientific[pos+1]=='-'){
    //     p=0-p;
    // }
    // cout<<p<<endl;

    if (aScientific[pos + 1] == '-')
    {
        cout << "0.";
        for (int i = 0; i < p-1; i++)
        {
            cout << "0";
        }
        cout << aScientific[1];
        for (int i = 3; i < pos; i++)
        {
            cout << aScientific[i];
        }
        cout<<endl;
        return 0;
    }
    else
    {
        if (p < pos - 3)
        {
            //原数字都保留
            cout << aScientific[1];
            for (int i = 3; i < pos; i++)
            {
                if(i==p+3){
                    cout<<".";
                }
                cout << aScientific[i];
            }
            cout<<endl;
            return 0;
        }
        else{
                        cout << aScientific[1];
            for (int i = 3; i < pos; i++)
            {
                cout << aScientific[i];
            }
            for(int i=0;i<p-pos+3;i++){
                cout<<"0";
            }
            cout<<endl;
            return 0;
        }
    }

    // a = num * pow(10, p);
    // cout << a << endl;

    return 0;
}