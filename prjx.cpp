#include <iostream>
#include<string.h>
#include <fstream>
#include<stdlib.h>
using namespace std;

bool login()
{
	char id[11], pas[11];
	char i[11]="admin", p[11]="1212";
	cout<<"Enter id: ";
	cin.getline(id,11);
	cout<<"Enter password: ";
	cin.getline(pas,11);
	
	if(strcmp(id,i) == 0 && strcmp(pas,p) == 0) return true;
	cout<<"Invalid credentials";
	return false;
}

void find(char data[],int type)
{
	ifstream i("dtx.txt");
	int m = 0;
	while(!i.eof())
	{
		char name[101];
		i.getline(name,101);
		char mass[101];
		i.getline(mass,101);
		char pin[101];
		i.getline(pin,101);
		char stat[101];
		i.getline(stat,101);
		//i.getline();
	
		switch(type)
		{
			case 1:
				if(strcmp(data,pin) == 0)
				m += atoi(mass);
			case 2:
				if(strcmp(data,name) == 0)
				m += atoi(mass);
		}
	}
	cout<<m;
}

main()
{
	if(! login()) return 0;
	system("cls");
	
	
	int choice;
	do
	{
		cout<<"1. Find using pincode."<<endl<<"2. Find using user-name."<<endl<<"3. Exit."<<endl;
		cout<<"Enter a choice"<<endl;
		cin>>choice;
		system("cls");
		//cout<<endl;
		
		switch(choice)
		{
			case 1:
				char pc[7];
				cout<<"Enter pincode: ";
				cin>>pc;
				find(pc,choice);
				break;
			case 2:
				char nm[7];
				cout<<"Enter user-name: ";
				cin>>nm;
				find(nm,choice);
				break;
			case 3:
				break;
			default:
				cout<<"Invalid input.";
		}
	}while(choice != 3);
	/*ifstream i("dtx.txt");
	
	char name[101];
	i.getline(name,101);
	char mass[101];
	i.getline(mass,101);
	char pin[101];
	i.getline(pin,101);
	char stat[101];
	i.getline(stat,101);
	
	
	
	cout<<"Name: "<<name;
	cout<<"\nMass: "<<mass;
	cout<<"\nPincode: "<<pin;
	cout<<"\nStatus: "<<stat;
	i.close();*/
}
