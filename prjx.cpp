#include <iostream>
#include<string.h>
#include <fstream>
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

main()
{
	if(! login()) return 0;
	system("cls");
	
	
	int choice;
	do
	{
		cout<<"1. Find using pincode."<<endl<<"2. Find using user-name."<<endl<<"3. Exit."<<endl;
		cout<<"Enter a choice"<<endl
		cin>>choice;
		system("cls");
		//cout<<endl;
		
		switch
	}
	ifstream i("dtx.txt");
	
	//cout<<line;
	/*char * name;
	name = strtok(line, "\t");
	char * mass;
	mass = strtok(line, "\t");
	char * pin;
	pin = strtok(line, "\t");
	char * stat;
	stat = strtok(line, "\t");
	*/
	
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
	
	i.close();
}
