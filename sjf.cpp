#include<iostream>
#include<algorithm>
#include<vector>
#define num 4  // 定义任务数量为4
#define col 3  // 定义列数为3
using namespace std;
//int data[num][col] = { {1,0,120},  // 任务数据，每行代表一个任务，第一列表示任务编号，第二列表示任务到达时间，第三列表示任务服务时间
//                      {2,50,50},
//                      {3,60,10},
//                      {4,110,20}};
int systime = 0;  // 系统时间初始化为0
int minservertime = 999;  // 最小服务时间初始化为999

// 定义按短作业优先(SJF)算法排序任务的函数
void sort_sjf(int data[][col]) {
	for (int i = 0; i < num - 1; i++)  // 外层循环遍历任务
		for (int j = i + 1; j < num; j++) {  // 内层循环遍历任务
			if (data[i][1] > data[j][1])  // 如果后一个任务的到达时间小于前一个任务的到达时间
				swap(data[i], data[j]);  // 交换两个任务的位置，按到达时间从小到大排序
		}
	systime = data[0][1] + data[0][2];  // 计算第一个任务的结束时间
	for (int i = 1; i < num; i++) {  // 遍历除第一个任务外的所有任务
		for (int j = i; j < num; j++) {  // 从当前任务开始遍历所有任务
			if (data[j][1] < systime && data[j][2] < minservertime) {  // 如果任务的到达时间小于系统时间且服务时间小于最小服务时间
				minservertime = data[j][2];  // 更新最小服务时间
			}
		}
		for (int k = i; k < num; k++) {  // 从当前任务开始遍历所有任务
			if (minservertime == data[k][2]) {  // 如果找到最小服务时间的任务
				swap(data[i], data[k]);  // 将当前任务与最小服务时间的任务交换位置
			}
		}
		systime += minservertime;  // 更新系统时间
		minservertime = 999;  // 重置最小服务时间
	}
}

// 定义计算数组元素平均值的函数
double sum_array(double a[]) {
	int i = 0;
	double sumf = 0;
	while (i < num) {  // 遍历数组元素
		sumf = sumf + a[i];  // 累加数组元素值
		i++;
	}
	return sumf / num;  // 返回数组元素平均值
}

// 主函数
int main() {
	int data[num][col] = { {1,0,120},  // 任务数据，每行代表一个任务，第一列表示任务编号，第二列表示任务到达时间，第三列表示任务服务时间
{2,50,50},
{3,60,10},
{4,110,20} };
	int systime = 0;  // 系统时间初始化为0
	int minservertime = 999;  // 最小服务时间初始化为999
	sort_sjf(data);  // 调用SJF算法排序任务
}
