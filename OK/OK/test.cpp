#include<iostream>
#include"Finance.h"
using namespace std;
int main()
{
	Income income;
	Payout payout;
	Income* head1 = income.initialize_income();
	Payout* head2 = payout.initialize_payout();
	int selected = -1;
	while (1)
	{
		system("cls");//����
		menu();
		cout << ">��ѡ��Ҫ���еĲ���:[0 - 9]";
		cin >> selected;
		if (selected < 0 || selected > 9)
		{
			cout << ">��������!�����������";
			fflush(stdin);
			selected=getchar();
		}
		else
		{
			switch (selected)
			{
			case 1:
				income.add(head1);
				break;
			case 2:
				income.search(head1);
				break;
			case 3:
				income.remove(head1);
				break;
			case 4:
				income.sort(head1);
				break;
			case 5:
				payout.add(head2);
				break;
			case 6:
				payout.search(head2);
				break;
			case 7:
				payout.remove(head2);
				break;
			case 8:
				payout.search(head2);
				break;
			case 9:
				count_total(head1,head2);
				break;
			case 0:
				cout << "\n\n\n\t\t\t��лʹ��\n\n\n";
				quit();

			default:
				selected=getchar();
				cout << "\n\n\n\t��ʾ��û�����ѡ�����������!\n\n\n\n";

				system("pause");
				break;
			}
			system("pause");

		}

	}
	return 0;
}


