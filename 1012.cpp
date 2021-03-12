#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct student
{
    unsigned int id;
    // bool graded;
    int A;
    int rankA;
    int C;
    int rankC;
    int M;
    int rankM;
    int E;
    int rankE;
} student;

bool compare_A(student a, student b)
{
    return (a.A < b.A);
}
bool compare_C(student a, student b)
{
    return (a.C < b.C);
}
bool compare_M(student a, student b)
{
    return (a.M < b.M);
}
bool compare_E(student a, student b)
{
    return (a.E < b.E);
}
bool compare_id(student a, student b)
{
    return (a.id < b.id);
}

void search(vector<student> list, unsigned int key_id)
{
    sort(list.begin(), list.end(), compare_id);
    int low = 0;
    int high = list.size();
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (key_id == list[mid].id)
        {
            if (list[mid].rankA == min({list[mid].rankA, list[mid].rankC, list[mid].rankE, list[mid].rankM}))
            {
                cout << list[mid].rankA << " " << 'A' << endl;
                return;
            }
            if (list[mid].rankC == min({list[mid].rankA, list[mid].rankC, list[mid].rankE, list[mid].rankM}))
            {
                cout << list[mid].rankC << " " << 'C' << endl;
                return;
            }
            if (list[mid].rankM == min({list[mid].rankA, list[mid].rankC, list[mid].rankE, list[mid].rankM}))
            {
                cout << list[mid].rankM << " " << 'M' << endl;
                return;
            }
            if (list[mid].rankE == min({list[mid].rankA, list[mid].rankC, list[mid].rankE, list[mid].rankM}))
            {
                cout << list[mid].rankE << " " << 'E' << endl;
                return;
            }
        }
        else if(key_id>list[mid].id){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<"N/A"<<endl;
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<student> list(n);
    for (int i = 0; i < n; i++)
    {
        cin >> list[i].id >> list[i].C >> list[i].M >> list[i].E;
        list[i].A = (list[i].C + list[i].M + list[i].E) / 3;
        // list[i].graded=true;
    }
    sort(list.begin(), list.end(), compare_A);
    for (int i = n - 1; i >= 0; i--)
    {
        list[i].rankA = n - i;
    }
    sort(list.begin(), list.end(), compare_C);
    for (int i = n - 1; i >= 0; i--)
    {
        list[i].rankC = n - i;
    }
    sort(list.begin(), list.end(), compare_M);
    for (int i = n - 1; i >= 0; i--)
    {
        list[i].rankM = n - i;
    }
    sort(list.begin(), list.end(), compare_E);
    for (int i = n - 1; i >= 0; i--)
    {
        list[i].rankE = n - i;
    }

    unsigned int *keys=new unsigned int(m);

    for (int i = 0; i < m; i++)
    {
        //查找id
        // unsigned int key_id;
        cin>>keys[i];
        // cin>>key_id;
    }
    for(int i=0;i<m;i++){
        search(list,keys[i]);
    }

    return 0;
}