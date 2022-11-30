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
	cout << "|  �ϼ�����  |  �ϼ�֧��  |    ����    |\n";
	printf("|%12.2f|%12.2f|%12.2f|\n", total_income, total_payout, total_income - total_payout);
	cout << "+------------+------------+------------+\n";
	cout << ">��������������˵�...";
	fflush(stdin);
	getchar();
}
void menu()
{
	cout << "| ��ͥ�������ϵͳ                            |" << endl
		<< "+--------------------------------------------------+" << endl
		<< "| �������                                    |" << endl
		<< "|      <1> �������                           |" << endl
		<< "|      <2> ��ѯ������ϸ                       |" << endl
		<< "|      <3> ɾ������                           |" << endl
		<< "|      <4> ��������                           |" << endl
		<< "| ֧������                                    |" << endl
		<< "|      <5> ���֧��                           |" << endl
		<< "|      <6> ��ѯ֧����ϸ                       |" << endl
		<< "|      <7> ɾ��֧��                           |" << endl
		<< "|      <8> ����֧��                           |" << endl
		<< "| ͳ��                                        |" << endl
		<< "|      <9> ͳ����������֧��                   |" << endl
		<< "+--------------------------------------------------+" << endl
		<< "| ���� <0> �˳�ϵͳ                           |" << endl
		<< "+--------------------------------------------------+" << endl;
}


void quit()
{
	exit(0);
}