#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

//第一个签名的开门，最后一个锁门
//已知：进出顺序
//求：谁开谁锁门
//id intime outtime

typedef struct person
{
	string id;
	float in;
	float out;
} person;

void person_assign(person a, person b)
{
	//将b赋给a
	a.id = b.id;
	a.in = b.in;
	a.out = b.out;
}

float time2float(string b)
{
	int a[8];
	for (int i = 0; i < 8; i++)
	{
		a[i] = b[i] - 48;
	}
	float res = 60 * (a[0] * 10 + a[1]) + a[3] * 10 + a[4] + (a[6] * 10 + a[7]) / 60.0;

	// cout<<a[0]<<a[1]<<" "<<a[3]<<a[4]<<" "<<a[6]<<a[7]<<" "<<res<<endl;
	return res;
}

bool comp_in(person a, person b) {
	return (a.in < b.in);
}
bool comp_out(person a, person b) {
	return (a.out < b.out);
}
int main()
{
	int num;
	cin >> num;
	vector<person> list(num);
	string in, out;
	for (int i = 0; i < num; i++)
	{
		cin >> list[i].id >> in >> out;
		list[i].in = time2float(in);
		list[i].out = time2float(out);
	}

	sort(list.begin(), list.end(), comp_in);
	cout << list[0].id;

	sort(list.begin(), list.end(), comp_out);
	cout << " " << list[num - 1].id;

	return 0;
}