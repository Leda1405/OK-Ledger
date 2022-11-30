#include<iostream>
#include"Finance.h"
using namespace std;
#include<iomanip>
#include<string.h>
#include <algorithm>
#include<string>
#include<fstream>
#include<windows.h>  
Payout* Payout::initialize_payout()
{
	Payout* head = NULL, * p = NULL, * q = NULL;
	ifstream f2;
	f2.open("payout.txt");
	if (!f2)
	{
		cout << "打开文件失败！" << endl;
		return NULL;
	}
	while (f2.peek() != EOF)
	{
		p = new Payout;
		f2 >> p->month;
		f2 >> p->detail;
		f2 >> p->money;
		if (head == NULL) head = p;
		else {
			q->next = p;
		}
		q = p;
	}
	if (head != NULL) q->next = NULL;
	f2.close();
	return head;
}
void Payout::input(Payout* p)
{
	cout << ">请输入月份:";
	fflush(stdin);
	cin >> p->month;
	cout << ">请输入备注（最大长度为%d):";
	fflush(stdin);
	cin >> p->detail;
	cout << ">请输入金额：";
	fflush(stdin);
	cin >> p->money;
}

void Payout::add(Payout*& head2)
{

	Payout* p = new Payout;
	if (NULL == p) cout << ("内存申请失败...\n");
	p->next = NULL;
	input(p);
	if (NULL == head2)
	{
		head2 = p;
	}
	else
	{
		get_last_payout(head2)->next = p;
	}
	Payout::Save(head2);
}
void Payout::Save(Payout*& head2)
{
	ofstream fout;
	fout.open("payout.txt", ios_base::binary);
	Payout* p = head2;
	while (NULL != p)
	{
		if (p->next != NULL)
		{
			fout << p->month << " " << p->detail << " " << p->money << endl;

		}
		else
		{
			fout << p->month << " " << p->detail << " " << p->money;
		}
		p = p->next;
	}
	fout.close();
};

void Payout::search(Payout*& head2)
{
	int Month = 0;
	Payout* p = NULL;
	Payout* result[9] = { NULL };
	int count = 0;
	char input = ' ';

	while (1)
	{
		cout << ">请输入要查询的月份";
		fflush(stdin);
		cin >> Month;
		if (Month < 1 or Month > 12)
		{
			cout << ">输入有误！" << endl;
		}
		else
		{
			p = head2;
			count = 0;
			memset(result, 0, sizeof(Payout*));
			while (NULL != p)
			{
				if (p->month == Month)
				{
					if (count < 9)
					{
						result[count] = p;
						count++;
					}
					else
					{
						show(result, count);
						cout << ">输入空格并回车翻页,按其它键退出....";
						fflush(stdin);
						input = getchar();
						if (input == ' ')
						{
							memset(result, 0, sizeof(Payout*));
							count = 0;
							result[count] = p;
							count++;
						}
						else
						{
							break;
						}
					}
				}
				p = p->next;
			}
			if (0 != count)
			{
				show(result, count);
			}
			else
			{
				cout << ">没有找到数据..." << endl;
			}
			cout << ">继续查找其它数据？（Y or N）";
			fflush(stdin);
			input = getchar();
			if (input == 'y' || input == 'Y')
			{
				continue;
			}
			else
			{
				break;
			}
		}
	}
}


void Payout::remove(Payout*& head2)
{
	int Month = 0;
	Payout* p = NULL;
	Payout* pre = NULL;
	Payout* result[9] = { NULL };
	int count = 0;
	char input = ' ';
	int i = 0;

	while (1)
	{
		cout << ">请输入要查询的月份：";
		cin >> Month;
		fflush(stdin);
		if (Month < 1 or Month > 12)
		{
			cout << ">输入有误！" << endl;
		}
		else
		{
			p = head2;
			count = 0;
			memset(result, 0, sizeof(Payout*));
			while (NULL != p)
			{
				if (p->month == Month)
				{
					if (count < 9)
					{
						result[count] = p;
						count++;
					}
					else
					{
						show(result, count);
						cout << ">输入空格并回车翻页.输入对应的序号删除.其它键退出.请输入：";
						fflush(stdin);
						input = getchar();
						if (input == ' ')
						{
							memset(result, 0, sizeof(Payout*));
							count = 0;
							result[count] = p;
							count++;
						}
						else if (input >= '1' && input <= 48 + count)
						{
							i = input - 49;
							pre = get_previous_payout(result[i]);
							if (NULL == pre)
							{
								head2 = head2->next;
							}
							else
							{
								pre->next = result[i]->next;
							}
							free(result[i]);
							for (; i < count - 1; i++)
							{
								result[i] = result[i + 1];
							}
							result[i] = p;
							printf(">删除成功!\n");
						}
						else
						{
							break;
						}
					}
				}

				p = p->next;
			}
			if (0 != count)
			{
				show(result, count);
				cout << ">输入对应的序号删除.其它键退出.请输入：";
				fflush(stdin);
				input = getchar();
				if (input >= '1' && input <= 48 + count)
				{
					i = input - 48 - 1;
					pre = get_previous_payout(result[i]);
					if (pre == NULL)
					{
						head2 = head2->next;
					}
					else {
						pre->next = result[i]->next;
					}
					free(result[i]);
					for (; i < count - 1; i++)
					{
						result[i] = result[i + 1];
					}
					result[i] = NULL;
					count--;
					cout << ">删除成功..." << endl;
				}
			}
			else
			{
				cout << ">没有找到数据..." << endl;
			}
			cout << ">继续查找其它数据？（Y or N)";
			fflush(stdin);
			input = getchar();
			if (input == 'y' || input == 'Y')
			{
				continue;
			}
			else
			{
				break;
			}
		}
	}
	Payout::Save(head2);

}
void Payout::sort(Payout*& head2)
{
	int Month = 0;
	Payout* p = NULL;
	Payout* temp;
	Payout* result[100] = { NULL };
	int count = 0;
	char input = ' ';
	int n;
	while (1)
	{
		cout << ">按1排序指定月份账单" << endl;
		cout << ">按2排序所有账单" << endl;
		cin >> n;
		if (n == 1)
		{
			cout << ">请输入要查询的月份";
			fflush(stdin);
			cin >> Month;
			if (Month < 1 or Month > 12)
			{
				cout << ">输入有误！" << endl;
			}
			else
			{
				p = head2;
				count = 0;
				memset(result, 0, sizeof(Payout*));
				while (NULL != p)
				{
					if (p->month == Month)
					{
						result[count] = p;
						count++;
					}
					p = p->next;

				}
				if (0 != count)
				{
					for (int i = 0; i < count; i++)
					{
						for (int j = 0; j < count; j++)
							if (result[i]->money > result[j]->money)
							{
								temp = result[j];
								result[j] = result[i];
								result[i] = temp;
							}
					}
					int i = 0;
					printf("+---+---------+------------------------+----------+\n");
					printf("|No.|  月份   |          备注          |   金 额  |\n");
					printf("+---+---------+------------------------+----------+\n");
					for (i = 0; i < count; i++)
					{
						printf("|%2d |  %2d     |    %-20s| %8.2f |\n",
							i + 1,
							result[i]->month,
							result[i]->detail,
							result[i]->money);
						printf("+---+---------+------------------------+----------+\n");
					}
				}
				else
				{
					cout << ">没有找到数据..." << endl;
				}
				cout << ">继续查找其它数据？（Y or N）";
				fflush(stdin);
				input = getchar();
				if (input == 'y' || input == 'Y')
				{
					continue;
				}
				else
				{
					break;
				}
			}
		}
		if (n == 2)
		{
			p = head2;
			count = 0;
			memset(result, 0, sizeof(Payout*));
			while (NULL != p)
			{
				result[count] = p;
				count++;
				p = p->next;
			}
			if (0 != count)
			{
				for (int i = 0; i < count; i++)
				{
					for (int j = 0; j < count; j++)
						if (result[i]->money > result[j]->money)
						{
							temp = result[j];
							result[j] = result[i];
							result[i] = temp;
						}
				}
				int i = 0;
				printf("+---+---------+------------------------+----------+\n");
				printf("|No.|  月份   |          备注          |   金 额  |\n");
				printf("+---+---------+------------------------+----------+\n");
				for (i = 0; i < count; i++)
				{
					printf("|%2d |  %2d     |    %-20s| %8.2f |\n",
						i + 1,
						result[i]->month,
						result[i]->detail,
						result[i]->money);
					printf("+---+---------+------------------------+----------+\n");
				}
			}
			else
			{
				cout << ">没有找到数据..." << endl;
			}
			cout << ">继续查找其它数据？（Y or N）";
			fflush(stdin);
			input = getchar();
			if (input == 'y' || input == 'Y')
			{
				continue;
			}
			else
			{
				break;
			}
		}

	}
}
Payout* get_last_payout(Payout*& head2)
{
	Payout* p = head2;
	if (p == NULL)
	{
		return p;
	}
	while ((NULL != p) && (NULL != p->next))
	{
		p = p->next;
	}
	return p;
}
Payout* get_previous_payout(Payout* p)
{
	Payout* previous2 = p;
	while (previous2 != NULL)
	{
		if (previous2->next == p)
		{
			break;
		}
		previous2 = previous2->next;
	}

	return previous2;
}
void Payout::show(Payout* p[], int count)
{
	int i = 0;
	printf("+---+---------+------------------------+----------+\n");
	printf("|No.|  月份   |          备注          |   金 额  |\n");
	printf("+---+---------+------------------------+----------+\n");
	for (i = 0; i < count; i++)
	{
		printf("|%2d |  %2d     |  %-20s  |%8.2f  |\n",
			i + 1,
			p[i]->month,
			p[i]->detail,
			p[i]->money);
		printf("+---+---------+------------------------+----------+\n");
	}
}