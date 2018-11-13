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

void change(char work[],char data[], int type)
{
    ofstream of("tmp.txt");
    ifstream iff("dtx.txt");

    char k[101];
    while(!iff.eof())
    {
        iff.getline(k,101);
        of<<k<<endl;
    }

    iff.close();
    of.close();

    ifstream i("tmp.txt");
    ofstream o("dtx.txt");

    char n[101];
    char ms[11];
    char p[8];
    char s[11];
    char pend[8] = "pending";

    while(!i.eof())
    {
        i.getline(n,101);
        i.getline(ms,101);
        i.getline(p,101);
        i.getline(s,101);

        o<<n<<endl;
        o<<ms<<endl;
        o<<p<<endl;
        int fnd = 0;

        switch(type)
        {
            case 1:
                if(strcmp(data,p) == 0)
                {
                    fnd = 1;
                    if(strcmp(pend,s) == 0)
                        o<<work<<endl;
                }
                break;
            case 2:
                if(strcmp(data,n) == 0)
                {
                    fnd = 1;
                    if(strcmp(pend,s) == 0)
                        o<<work<<endl;
                }
                break;
        }

        if(fnd == 0) o<<pend<<endl;
    }


    o.close();
    i.close();

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
	cout<<"Total mass: "<<m<<endl<<endl;

	cout<<"1. Accept all applications."<<endl<<"2. Reject all applications."<<endl<<"3. Cancel."<<endl;
	cout<<"Enter a choice: ";
	int c;
	cin>>c;
	switch(c)
	{
		case 1:
			// accept code is yet to be written
			change("accepted",data,type);
			cout<<"Accepted"<<endl<<endl;
			break;
		case 2:
			// reject code is yet to be written

			change("rejected",data,type);
			cout<<"Rejected"<<endl<<endl;
			break;
		case 3:
			break;
		default:
			cout<<"Invalid input."<<endl<<endl;
			break;
	}
}

main()
{
	if(! login()) return 0;
	system("cls");


	int choice;
	do
	{
		cout<<"1. Find using pincode."<<endl<<"2. Find using user-name."<<endl<<"3. Exit."<<endl;
		cout<<"Enter a choice: "<<endl;
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
}
