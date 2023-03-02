#include <windows.h>
#include <cmath>
#include <source.h>
#include <iostream>
#include <iomanip>

using namespace std;

void pay(int cat)
{

    int tk, pmathod, fee;
    (cat == 1) ? fee = 80 : fee = 100;
payagain:
    cout << "  You've to pay : " << fee << endl;
    cout << "  Pay with -\n\t1. Bkash\n\t2. World Bank\n\t3. Bangladesh Bank" << endl;
    cout << "  Select option : ";
    cin  >> pmathod;
    cout << "  Enter Amount : ";
    cin  >> tk;
    if (tk == fee)
    {
        cout << "\n      !!! Payment Successful !!!" << endl;
        cout << "  ! Have a safe journey..Thank you !" << endl;
    }
    else
    {
        cout << "  PAYMENT RETURNED ! \n  ENTER CORRECT AMOUNT ";
        goto payagain;
    }
}


int firstUI(int a, int c)
{
    cout<< setw(44) << "_______________________" << endl
		<< setw(45) << endl
		<< setw(44) << "| Keep Your Car Secure|" << endl
		<< setw(44) << "| Digital Parking Lot |" << endl
		<< setw(44) << "_______________________" << endl
		<< endl;

	cout<< setw(27) << "_______________________"<<"         "<<"_______________________"<< endl
			<<endl;
	cout<< setw(27) << "|Space :               "<<"         "<<"|rent rate per hour :  "<< endl
		<< endl
		<< setw(27) << "|# Available space : "<< a <<"         "<<"|-- Bike  : 80 $       "<< endl
		<< setw(27) << "|# Currently using : "<< c <<"         "<<" |-- Car   : 100 $      "<< endl
		<< setw(27) << "_______________________"<<"         "<<"_______________________"<< endl
		<< endl;

	cout<< setw(27) << "        (N.B. : Please use keypad 0-9 to select options)       "<< endl
		<< endl
		<< "  Press-1 > Check in.."
		<< endl
		<< "  Press-2 > Check out.."
		<< endl
		<< "  Press-3 > Where is mine ?"
		<< endl
		<< "  Press-4 > Help"
		<< endl;
	cout<< "  Your choice : ";
    int key;
    cin >> key;
    cin.ignore();
    system("cls");
    return key;
}

void inUI()
{
    cout<< setw(44) << "_______________________" << endl
        << setw(45) << endl
        << setw(44) << "| Digital Parking Lot |" << endl
        << setw(44) << "|      Check In       |" << endl
        << setw(44) << "_______________________" << endl
        << endl;

    cout<< setw(27) << "    ________________________________________________________    " << endl
        << endl;

}

void view()
{
	cout<< setw(44) << "_______________________" << endl
        << setw(45) << endl
        << setw(44) << "| Digital Parking Lot |" << endl
        << setw(44) << "|    All Vehicles     |" << endl
        << setw(44) << "_______________________" << endl
        << endl;

    cout<< setw(27) << "    ________________________________________________________    " << endl
        << endl;
    cout<< setw(27)<< "     Sl. |         NAME         |  Id   |  Catagory  | FEE       "  << endl;
    cout<< setw(27) << "    ________________________________________________________    " << endl
        << endl;

}

void outUI()
{
    cout<< setw(44) << "_______________________" << endl
        << setw(45) << endl
        << setw(44) << "| Digital Parking Lot |" << endl
        << setw(44) << "|     Check Out       |" << endl
        << setw(44) << "_______________________" << endl
        << endl;

    cout<< setw(27) << "    ________________________________________________________    " << endl
        << endl;
}

int token(int car_num)
{
    int temp = car_num;
    int s_key = 0;
    int rem;
    while (temp!=0)
    {
        rem = temp%10;
        s_key = s_key*10 + rem;
        temp/=10;
    }
    return s_key;
    
}

int menu(int p)
{
    int menu;
    string page;
    (p==1)?page="In":page="Out";
	cout << "  Press-0 > Go to home. \n";
	cout << "  Press-1 > Check "<< page <<" : \n";
	cout << "  Your choice : ";
	cin  >> menu;
    cin.ignore();
	if (menu == 0)
	{
		cout << "  going to main" << endl;
		Sleep(700);
		return 0;
	}
    else
    {
        return 1;
    }
}
