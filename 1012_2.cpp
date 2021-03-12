#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node
{
    unsigned int id;
    // int best;
    int score[4];
    int rank[4];
} node;

int flag = -1;

bool cmp(node a, node b)
{
    return a.score[flag] > b.score[flag];
}

bool cmp_id(node a, node b) { return (a.id < b.id); }

void search(vector<node> stu,unsigned int key_id)
{

    int low = 0;
    int size = stu.size();
    int high = size-1;
    char c[5]={'A','C','M','E'};

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (key_id == stu[mid].id)
        {
            for (int i = 0; i < 4; i++)
            {
                if (stu[mid].rank[i] == *min_element(stu[mid].rank, stu[mid].rank + size))
                {
                    cout << stu[mid].rank[i] << " " << c[i] << endl;
                    return;
                }
            }
        }
        else if (key_id > stu[mid].id)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "N/A" << endl;
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<node> stu(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stu[i].id >> stu[i].score[1] >> stu[i].score[2] >> stu[i].score[3];
        stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3;
    } //初始化分数系统

    for (flag = 0; flag < 4; flag++)
    {
        sort(stu.begin(), stu.end(), cmp); //不错
        stu[0].rank[flag] = 1;
        for (int i = 1; i < n; i++)
        {
            stu[i].rank[flag] = i + 1;
            if (stu[i].score[flag] == stu[i - 1].score[flag])
            {
                stu[i].rank[flag] = stu[i - 1].rank[flag];
            }
        }
    }

    unsigned int *keys = new unsigned int(m);

    for (int i = 0; i < m; i++)
    {
        //查找id
        // unsigned int key_id;
        cin >> keys[i];
        // cin>>key_id;
    }
    sort(stu.begin(), stu.end(), cmp_id);
    for (int i = 0; i < m; i++)
    {
        search(stu, keys[i]);
    }

    return 0;
}