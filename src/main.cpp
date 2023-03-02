#include <iostream>
#include <source.h>
#include <iomanip>
#include <string>
#include <display.h>
#include <windows.h>
#include <stdio.h>
using namespace std;
char name[30];

void where_is_mine();
void checkin();
void out(int lsize);
void init();

struct NODE
{
	char owner[30];
	int car_num;
	int cat; /* 1--> bike  2--> private car  */
	int token;
	struct NODE *next;
} *head;
typedef struct NODE node;

int main()
{
	int key, avail = 50, checked = 0;
	disp();
	do
	{
		
		key = firstUI(avail, checked);
		system("cls");
		switch (key)
		{
		case 1:
			inUI();
			if (avail == 50)
				init();
			else
				checkin();
			avail--;
			checked++;
			system("cls");
			break;
		case 2:
			outUI();
			out(checked);
			Sleep(5000);
			system("cls");
			avail++;
			checked--;
			break;

		case 3:
			view();
			where_is_mine();
			system("cls");
			break;
		case 4:
			printf("\n\n\tUse only keypad and enter\n\n\tDon't give unwanted data \n\n\tbe careful about security key\n  no way to recover it if losses\n  need your driving licence and car licence to get car back\n\n");
			printf("\tfor any other info: \n\tcontact : mahi.odyssey@gmail.com\n\t\n\n\tthank you");
			cout << "\n  > Home";
			getchar();
			system("cls");
			break;

		default:
			break;
		}

	} while (key != 0);

	getchar();
	return 0;
}

/* DON'T TOUCH SECTION */
void out(int lsize)
{
againkey:
	int x, notfound = 0;

	int run = menu(1);
	if (run==0)
	{
		return;
	}
	else
	{
		cout << "  Enter Security Key : ";
		cin  >> x;
		if (head->token == x)
		{
			pay(head->cat);
			node *t;
			t = head;
			head = head->next;
			free(t);
		}
		else
		{
			node *p, *q;
			p = head;
			q = head->next;
			for (int i = 1; i < lsize; i++)
			{
				if (q->token == x)
				{
					notfound++;
					break;
				}
				p = p->next;
				q = q->next;
			}
			if (notfound == 1)
			{
				pay(q->cat);
				p->next = q->next;
				free(q);
			}
			else
			{
				goto againkey;
			}
		}
	}
	cout << "  going to main" << endl;
}

void checkin()
{
	int run = menu(1);
	if (run==0)
	{
		return;
	}
	else
	{
		node *newNode = (node *)malloc(sizeof(node));
		cout << "  Enter Your Name : ";
		cin.get(newNode->owner, 50);

		cout<< "\n  Select catagory : " << endl;
		cout<< "  press 1 > Bike " << endl
			<< "  press 2 > Private Car" << endl;
		cout<< "  ----: ";
		cin >> newNode->cat;

		cout << "\n  Car/Bike Number (Only last 4 digits) : ";

		int numinput;
		scanf("%4d", &numinput);
		newNode->car_num = numinput;
		newNode->token = token(numinput);

		newNode->next = NULL;
		node *temp;
		temp = head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;

		cout << "\n  Your security key : " << newNode->token;
		cout << "\n  Copy the code.\n  DON'T Share your code";
		cout << "\n  Checked In Complete" << endl; /* clearence */
		cout << endl
			<< endl
			<< endl
			<< "  > Home";
		getchar();
		getchar();
	}
}

void init()
{
	int run = menu(1);
	if (run==0)
	{
		return;
	}
	else
	{
		head = (node *)malloc(sizeof(node));
		cout << "  Enter Your Name : ";
		cin.get(head->owner, 50);
		cout << "\n  Select catagory : " << endl;
		cout << "  press 1 > Bike " << endl
			 << "  press 2 > Private Car" << endl;
		cout << "  ----:";
		cin >> head->cat;
		cout << "\n  Car/Bike Number (Only last 4 digits) : ";

		int numinput;
		scanf("%4d", &numinput);
		head->car_num = numinput;
		head->token = token(numinput);
		head->next = NULL;

		cout << "\n  Your security key : " << head->token;
		cout << "\n  Copy the code.\n  DON'T Share your code";
		cout << "\n  Checked In Complete" << endl; /* clearence */
		cout << endl
			<< endl
			<< endl
			<< " > Home";
		getchar();
		getchar();
	}
}

void where_is_mine()
{
	node *temp;
	temp = head;
	int fee, i = 1;

	while (temp != NULL)
	{
		if (temp->cat == 1)
		{
			fee = 80;
			printf("%6d   | %-20s | %03d   | %-11s| %03d\n", i++, temp->owner, temp->car_num, "Bike", fee);
		}
		else
		{
			fee = 100;
			printf("%6d   | %-20s | %03d   | %-11s| %03d\n", i++, temp->owner, temp->car_num, "Car", fee);
		}

		temp = temp->next;
	}
	cout << endl
		 << endl
		 << endl
		 << " > Home";
	getchar();
}