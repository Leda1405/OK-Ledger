#include<iostream>
#include"Finance.h"
using namespace std;
#include<iomanip>
#include<string.h>
#include <algorithm>
#include<string>
#include<fstream>
#include<windows.h> 

void count_total(Income*& head1, Payout*& head2)
{
	float total_income = 0.0;
	float total_payout = 0.0;
	Income* p1 = head1;
	Payout* p2 = head2;
	while (NULL != p1)
	{
		total_income += p1->money;
		p1 = p1->next;

	}
	while (NULL != p2)
	{
		total_payout += p2->money;
		p2 = p2->next;
	}
	cout << "+------------+------------+------------+\n";
	cout << "|  合计收入  |  合计支出  |    结余    |\n";
	printf("|%12.2f|%12.2f|%12.2f|\n", total_income, total_payout, total_income - total_payout);
	cout << "+------------+------------+------------+\n";
	cout << ">按任意键返回主菜单...";
	fflush(stdin);
	getchar();
}
void menu()
{
	cout << "| 家庭财务管理系统                            |" << endl
		<< "+--------------------------------------------------+" << endl
		<< "| 收入管理                                    |" << endl
		<< "|      <1> 添加收入                           |" << endl
		<< "|      <2> 查询收入明细                       |" << endl
		<< "|      <3> 删除收入                           |" << endl
		<< "|      <4> 排序收入                           |" << endl
		<< "| 支出管理                                    |" << endl
		<< "|      <5> 添加支出                           |" << endl
		<< "|      <6> 查询支出明细                       |" << endl
		<< "|      <7> 删除支出                           |" << endl
		<< "|      <8> 排序支出                           |" << endl
		<< "| 统计                                        |" << endl
		<< "|      <9> 统计总收入总支出                   |" << endl
		<< "+--------------------------------------------------+" << endl
		<< "| 输入 <0> 退出系统                           |" << endl
		<< "+--------------------------------------------------+" << endl;
}


void quit()
{
	exit(0);
}