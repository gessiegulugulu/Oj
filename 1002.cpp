#include <iostream>
using namespace std;

int main()
{
    float res[1001] = {0.0};
    int k1, k2;
    cin >> k1;
    if (k1 < 1||k1 > 10)
        return 0;
    int pos;
    float key;
    for (int i = 0; i < k1; i++)
    {
        cin >> pos;
        cin >> key;
        res[pos] += key;
    }
    cin >> k2;
    if (k2 < 1 || k2 > 10)
        return 0;
    for (int i = 0; i < k2; i++)
    {
        cin >> pos;
        cin >> key;
        res[pos] += key;
    }
    int count = 0;
    for (int i = 0; i < 1001; i++)
    {
        if (res[i] != 0.0)
            count++;
    }
    cout << count;
    for (int i = 1000; i >= 0; i--)
    {
        if (res[i] != 0)
        {
            cout << " " << i << " " << res[i];
        }
    }
    cout << endl;

    return 0;
}