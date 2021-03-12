#include <iostream>
#include <string>
using namespace std;

string res = "";
void funDay(char a)
{
    switch (a)
    {
    case 'A':
    {
        res += "MON";
        break;
    };
    case 'B':
    {
        res += "MON";
        break;
    };
    case 'C':
    {
        res += "MON";
        break;
    };
    case 'D':
    {
        res += "MON";
        break;
    };
    case 'E':
    {
        res += "MON";
        break;
    };
    case 'F':
    {
        res += "MON";
        break;
    };
    case 'G':
    {
        res += "MON";
        break;
    };
    }
}

int main()
{
    string input[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> input[i];
    }
    int i = 0;
    char chars[3];
    string days[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    while (1)
    {
        if (input[1][i] == input[0][i] && 'A' <= input[0][i] && input[0][i] <= 'G')
        {
            // chars[0] = input[0][i];
            res+=days[input[0][i]-'A'];
            break;
        }
        i++;
    }
    i++;

    while (1)
    {
        if (input[1][i] == input[0][i] ){
            if('0' <= input[0][i] && input[0][i] <= '9'){
                res+=" 0";
                res+=to_string(input[0][i]-'0');
                break;
            }
            else if('A' <= input[0][i] && input[0][i] <= 'N'){
                // cout<<input[0][i]<<endl;
                res+=" ";
                res+=to_string(input[0][i]-'A'+10);
                break;
            }
        }
        i++;
    }
    res+=":";

    i = 0;

    while (1)
    {
        if (input[2][i] == input[3][i] &&
            (('a' <= input[2][i] && input[2][i] <= 'z') ||
             ('A' <= input[2][i] && input[2][i] <= 'Z')))
        {
            chars[2] = input[0][i];
            if(i<10){
                res+="0";
                res+=to_string(i);
            }
            else{
                res+=to_string(i);
            }
            break;
        }
        i++;
    }
    cout<<res<<endl;
    return 0;
}