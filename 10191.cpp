// Longest Nap （最长打盹时间）
// 将时间转换为整数来进行排序，再找出两个数间最大的空闲时间。
#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstdlib>
	
using namespace std;
	
#define MAXSIZE (100 + 2)	// 事件的数量 + 两个预先添加的事件。
	
struct time_format
{
	string time;	// 事件结束的时间。字符串表示。
	int start;	// 事件的开始时间，为小时数 * 60 + 分钟数。
	int end;	// 事件的结束时间，为小时数 * 60 + 分钟数。
};
	
bool cmp(time_format x, time_format y)
{
	if (x.start != y.start)
		return x.start < y.start;
	return x.end < y.end;
}
	
void reset(time_format t[])
{
	// 需要将时间对 10:00 10:00 与 18:00 18:00 预先添加到数组中。因为事件可能不是从
	// 10:00 开始，故在 10:00 和时间开始前有一段空闲时间，同样的对于 18:00 以前的的事件
	// 也有可能和 18:00 之间存在空闲时间。
	t[0].time = "10:00";
	t[0].start = 600;
	t[0].end = 600;
 
	t[1].time = "18:00";
	t[1].start = 1080;
	t[1].end = 1080;
}
	
int main(int ac, char *av[])
{
	time_format t[MAXSIZE];
	int cases = 0;
	int events;
	string line;
	
	while (cases++, cin >> events)
	{
		cin.ignore();
		int counter = 2;
	
		reset(t);
	
		while ((counter - 2) < events)
		{
			getline(cin, line);
 
			t[counter].start = atoi(line.substr(0, 2).data()) * 60; //從0開始提取2字符
			t[counter].start += atoi(line.substr(3, 2).data()); //從3開始提取2字符
			t[counter].end = atoi(line.substr(6, 2).data()) * 60;
			t[counter].end += atoi(line.substr(9, 2).data());
			t[counter].time = line.substr(6, 5);
 
			counter++;
		}
	
		// 排序。
		sort(t, t + events + 2, cmp);
	
		// 查找时间跨度最大的间隙。
		int longest_nap = 0;
		string longest_start;
	
		for (int i = 0; i < events + 1; i++)
			if ((t[i + 1].start - t[i].end) > longest_nap)
			{
				longest_start = t[i].time;
				longest_nap = t[i + 1].start - t[i].end;
			}
	
		// 输出最大打盹时间的开始时间和持续时间。
		cout << "Day #" << cases << ": the longest nap starts at ";
		cout << longest_start << " and will last for ";
		if (longest_nap < 60)
			cout << longest_nap;
		else
			cout << (longest_nap / 60) << " hours and " << (longest_nap % 60);
		cout << " minutes.\n";
	}
	
	return 0;
}