#include <iostream>
#include <vector>
#include <string>
using namespace std;
/**
 * 输入：
 * N
 * N行：用户名和密码 string小于10
 * 
 * 输出：
 * M要改的
 * M行：用户姓名 改后密码
 * n=1 is
 * n>1 are
 * 
 * */

int main()
{
    int N;
    cin >> N;
    int M = 0;
    string tempPassword;
    string input[1000][3];
    string toReplace[4] = {"1", "0", "l", "O"};
    string chars[4] = {"@", "%", "L", "o"};
    for (int i = 0; i < N; i++)
    {
        cin >> input[i][0] >> tempPassword;

        bool flag = false;
        for (int j = 0; j < 4; j++)
        {
            while (1)
            {
                if (tempPassword.find(toReplace[j]) != string::npos)
                {
                    flag = true;
                    int pos = tempPassword.find(toReplace[j]);
                    tempPassword.replace(pos, 1, chars[j]);
                }
                else
                {
                    break;
                }
            }
        }//NOTE 更好的方法：用switch case对字符串中每一个字符进行判断和替换
        if (flag)
        {
            input[i][2] = "true";
            M++;
        }
        else
        {
            input[i][2] = "false";
        }
        input[i][1] = tempPassword;
    }

    if (M == 0)
    {
        if (N == 1)
        {
            cout << "There is 1 account and no account is modified" << endl;
        }
        else
        {
            cout << "There are " << N << " accounts and no account is modified" << endl;
        }
    }
    else
    {
        cout << M << endl;
        for (int i = 0; i < N; i++)
        {
            if (input[i][2] == "true")
            {
                cout << input[i][0] << " " << input[i][1] << endl;
            }
        }
    }

    return 0;
}