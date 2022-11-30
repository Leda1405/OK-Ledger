#pragma once
#include<iostream>
using namespace std;
#include<iomanip>
#include<cstring>
#include <algorithm>
#include<string>
#include<fstream>
#include<windows.h>  
#define MAX_NAME 11 
#define MAX_DETAIL 21 
#define MENU_COUNT 9  

class Income
{
	friend class Payout;
public:
	Income(int Year = 0, int Month = 0,const char* Name = "",const char* Detail = "")
	{
		strncpy(name, Name, sizeof(name));		// 为了安全保障，指定长度拷贝字符串
		name[sizeof(name) - 1] = '\0';			// 对可能超长的字符串进行截断
		strncpy(detail, Detail, sizeof(detail));
		detail[sizeof(detail) - 1] = '\0';
	};
	Income(const Income& income)
	{
		year = income.year;
		month = income.month;
		money = income.money;
		strcpy(name, income.name);
		strcpy(detail, income.detail);
		next = income.next;
	};
	void add(Income*& head1);
	void search(Income*& head1);
	void remove(Income*& head1);
	void sort(Income*& head1);
	void show(Income* p[], int count);
	void Save(Income*& head1);
	void input(Income* p);
	Income* initialize_income();
	friend Income* get_last_income(Income*& head1);
	friend Income* get_previous_income(Income* p);
	static bool cmp(Income a, Income b) { return a.money > b.money; };
	friend void count_total();
	float money;
	int year, month;
	char name[MAX_NAME];
	char detail[MAX_DETAIL];
	Income* next;
private:

};
class Payout 
{
public:
	Payout(int Year = 0, int Month = 0, const char* Name = "", const char* Detail = "") :year(Year), month(Month)
	{
		strncpy(name, Name, sizeof(name));		// 为了安全保障，指定长度拷贝字符串
		name[sizeof(name) - 1] = '\0';			// 对可能超长的字符串进行截断
		strncpy(detail, Detail, sizeof(detail));
		detail[sizeof(detail) - 1] = '\0';
	};
	Payout(const Payout& payout)
	{
		year = payout.year;
		month = payout.month;
		money = payout.money;
		strcpy(name,payout.name);
		strcpy(detail, payout.name);
		next = payout.next;
	};
	void add(Payout*& head2);
	void search(Payout*& head2);
	void remove(Payout*& head2);
	void sort(Payout*& head2);
	void show(Payout* p[], int count);
	void Save(Payout*& head2);
	void input(Payout* p);
	Payout* initialize_payout();
	friend Payout* get_last_payout(Payout*& head2);
	friend Payout* get_previous_payout(Payout* p);
	friend void count_total();

	static bool cmp(Payout a, Payout b) { return a.money > b.money; };
	int year, month;
	float money;
	char name[MAX_NAME];
	char detail[MAX_DETAIL];
	Payout* next;
private:

};
void count_total(Income*& head1, Payout*& head2);
void quit();
void menu();