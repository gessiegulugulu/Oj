#include <iostream>
using namespace std;
//输入：k个数
//输出：最大和 和最大的连续子列首尾

int main()
{
    int num;
    cin >> num;
    int *q = new int[num];
    int negative = 0;
    for (int i = 0; i < num; i++)
    {
        cin >> q[i];
        if (q[i] < 0)
        {
            negative++;
        }
    }

    if (negative == num)
    {
        cout << "0 " << q[0] << " " << q[num - 1];
        return 0;
    }

    // int window = num;
    int sum[3] = {-999999, 0, 0};
    for (int i = 0; i < num; i++)
    {
        int sum_window = 0;
        for (int j = i; j < num; j++)
        {
            sum_window += q[j];

            if (sum_window > sum[0])
            {
                sum[0] = sum_window;
                sum[1] = i;
                sum[2] = j;
            }
            else if (sum_window == sum[0])
            {
                if (sum[1] >= i &&  sum[2] >= j)
                {
                    sum[0] = sum_window;
                    sum[1] = i;
                    sum[2] = j;
                }
            }
        }
    }

    cout << sum[0] << " " << q[sum[1]] << " " << q[sum[2]] << endl;

    return 0;
}