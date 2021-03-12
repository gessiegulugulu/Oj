#include <iostream>
#include <iomanip>
using namespace std;
/* *********************
 * 输入：三场比赛的赔率
 * 输出：压在啥上以及盈利
 * *********************/
char num2result(int n)
{
    if (n == 0)
    {
        return 'W';
    }
    if (n == 1)
    {
        return 'T';
    }

    return 'L';
}

int main()
{
    float odd[3][3] = {0};
    int max[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> odd[i][j];
            if (odd[i][j] > odd[i][max[i]])
            {
                max[i] = j;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        cout << num2result(max[i]) << " ";
    }
    cout << fixed << setprecision(2) << (odd[0][max[0]] * odd[1][max[1]] * odd[2][max[2]] * 0.65 - 1.0) * 2.0 << endl;
    return 0;
}