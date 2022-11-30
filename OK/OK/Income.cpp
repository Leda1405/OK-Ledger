#include<iostream>
#include"Finance.h"
using namespace std;
#include<iomanip>
#include<string.h>
#include <algorithm>
#include<string>
#include<fstream>
#include<windows.h>
Income* Income::initialize_income() 
{
	Income* head = NULL, * p = NULL, * q = NULL;
	ifstream f1;
	f1.open("income.txt");
	if (!f1)
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		return NULL;
	}
	while (f1.peek() != EOF)
	{
		p = new Income;
		f1 >> p->month;
		f1 >> p->detail;
		f1 >> p->money;
		if (head == NULL) head = p;
		else {
			q->next = p;
		}
		q = p;
	}
	if (head != NULL) q->next = NULL;
	f1.close();
	return head;
}
void Income::input(Income* p)
{
	cout << ">�������·�:";
	fflush(stdin);
	cin >> p->month;
	cout << ">�����뱸ע����󳤶�Ϊ%d):";
	fflush(stdin);
	cin >> p->detail;
	cout << ">�������";
	fflush(stdin);
	cin >> p->money;
}
void Income::add(Income*&head1) 
{

	Income* p = new Income;
	if (NULL == p) cout << ("�ڴ�����ʧ��...\n");
	p->next = NULL;
	input(p);
	if (NULL == head1)
		{
		head1 = p;
	}
	else
	{
		get_last_income(head1)->next = p;
	}
	Income::Save(head1);
 }

void Income::Save(Income*& head1)
{
	ofstream fout1;
	fout1.open("income.txt", ios_base::binary);
	Income* p = head1;
	while (NULL != p)
	{
		if (p->next != NULL)
		{
			fout1 << p->month << " " << p->detail << " " << p->money << endl;

		}
		else
		{
			fout1 << p->month << " " << p->detail << " " << p->money;
		}
		p = p->next;
	}
	fout1.close();
};

void Income::search(Income*& head1)
{
	int Month = 0;
	Income* p = NULL;
	Income* result[9] = { NULL };
	int count = 0;
	char input = ' ';

	while (1)
	{
		cout << ">������Ҫ��ѯ���·�";
		fflush(stdin);
		cin >> Month;
		if (Month < 1 or Month > 12)
		{
			cout << ">��������" << endl;
		}
		else
		{
			p = head1;
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
						cout << ">����ո񲢻س���ҳ,���������˳�....";
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
				cout << ">û���ҵ�����..." << endl;
			}
			cout << ">���������������ݣ���Y or N��";
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


void Income::remove(Income*& head1)
{
	int Month = 0;
	Income* p = NULL;
	Income* pre = NULL;
	Income* result[9] = { NULL };
	int count = 0;
	char input = ' ';
	int i = 0;

	while (1)
	{
		cout << ">������Ҫ��ѯ���·ݣ�";
		cin >> Month;
		fflush(stdin);
		if (Month < 1 or Month > 12)
		{
			cout << ">��������" << endl;
		}
		else
		{
			p = head1;
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
						cout << ">����ո񲢻س���ҳ.�����Ӧ�����ɾ��.�������˳�.�����룺";
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
							pre = get_previous_income(result[i]);
							if (NULL == pre)
							{
								head1 = head1->next;
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
							printf(">ɾ���ɹ�!\n");
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
				cout << ">�����Ӧ�����ɾ��.�������˳�.�����룺";
				fflush(stdin);
				input = getchar();
				if (input >= '1' && input <= 48 + count)
				{
					i = input - 48 - 1;
					pre = get_previous_income(result[i]);
					if (pre == NULL)
					{
						head1 = head1->next;
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
					cout << ">ɾ���ɹ�..." << endl;
				}
			}
			else
			{
				cout << ">û���ҵ�����..." << endl;
			}
			cout << ">���������������ݣ���Y or N)";
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
	Income::Save(head1);

}
void Income::sort(Income*& head1)
{
	int Month = 0;
	Income* p = NULL;
	Income* temp;
	Income* result[100] = { NULL };
	int count = 0;
	char input = ' ';
	int n;

	while (1)
	{
		cout << ">��1����ָ���·��˵�" << endl;
		cout << ">��2���������˵�" << endl;
		cin >> n;
		if (n == 1)
		{
			cout << ">������Ҫ��ѯ���·�";
			fflush(stdin);
			cin >> Month;
			if (Month < 1 or Month > 12)
			{
				cout << ">��������" << endl;
			}
			else
			{
				p = head1;
				count = 0;
				memset(result, 0, sizeof(Income*));
				while (NULL != p)
				{
					if (p->month == month)
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
					printf("|No.|  �·�   |         ��ע           |   �� ��  |\n");
					printf("+---+---------+------------------------+----------+\n");
					for (i; i < count; i++)
					{
						printf("|%2d |  %2d     |  %-20s  |%8.2f  |\n",
							i + 1,
							result[i]->month,
							result[i]->detail,
							result[i]->money);
						printf("+---+---------+------------------------+----------+\n");
					}
				}
				else
				{
					cout << ">û���ҵ�����..." << endl;
				}
				cout << ">���������������ݣ���Y or N��";
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
			p = head1;
			count = 0;
			memset(result, 0, sizeof(Income*));
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
				printf("|No.|  �·�   |           ��ע         |   �� ��  |\n");
				printf("+---+---------+------------------------+----------+\n");
				for (i; i < count; i++)
				{
					printf("|%2d |  %2d     |  %-20s  |%8.2f  |\n",
						i + 1,
						result[i]->month,
						result[i]->detail,
						result[i]->money);
					printf("+---+---------+------------------------+----------+\n");
				}
			}
			else
			{
				cout << ">û���ҵ�����..." << endl;
			}
			cout << ">���������������ݣ���Y or N��";
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
Income* get_last_income(Income*& head1)
{
	Income* p = head1;
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
Income* get_previous_income(Income* p)
{
	Income* previous1 = p;
	while (previous1 != NULL)
	{
		if (previous1->next == p)
		{
			break;
		}
		previous1 = previous1->next;
	}

	return previous1;
}
void Income::show(Income* p[], int count)
{
	int i = 0;
	printf("+---+---------+------------------------+----------+\n");
	printf("|No.|  �·�   |          ��ע          |   �� ��  |\n");
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
