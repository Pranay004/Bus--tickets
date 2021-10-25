#include<fstream.h>
#include<conio.h>
#include<string.h>
class TourBus
{
	int bid;
	char destination[200];
	char time[50];
	int max_seats;
	int booked;
	public:
	TourBus()
	{
	bid=0;
	max_seats=50;
	booked=0;
	strcpy(time,"9:10am");
	strcpy(destination,"");
	}
	void input();
	void show();
	void display();
	int getid()
	{
	return bid;
	}
	char* getdestination()
	{
	return destination;
	}
	char*getTime()
	{
	return time;
	}
	int getBooked()
	{
	return booked;
	}
	int getmax(){
	return max_seats;
	}
};
void TourBus::input()
{
	cout<<"Enter Bus id";
	cin>>bid;
	cout<"Enter Bus Destination";
	cin>>destination;
	cout<<"Enter time of bus";
	cin>>time;
}
void TourBus::display()
{
	cout<<"\t"<<destination<<"\t"<<time<<"\t"<<max_seats<<"\t"<<booked;
}
void TourBus::show()
{
}
void main()
{
	int ch;
	fstream F;
	TourBus b;
	do
	{
		cout<<"press 1 - Add a New Tour Bus"<<endl;
		cout<<"press 2 - show Selected Bus"<<endl;
		cout<<"press 3 - Display all Buses"<<endl;
		cout<<"press 4 - Delete a Bus"<<endl;
		cout<<"press 5 - Book a Ticket"<<endl;
		cout<<"press 6 - Exit"<<endl;
		cout<<"press 7 - Display booked tickets"<<endl;
		cout<<"Enter your choice";
		cin>>ch;
		switch(ch)
		{
		case 1:
			F.open("tour.dat",ios::app | ios::binary);
			b.input();
			F.write((char*)&b, sizeof(b));
			F.close();
			cout<<"Bus added Successfully"<<endl;
			getch();
			clrscr();

		break;
		case 3:
			F.open("tour.dat", ios::in | ios::binary);
			if(F.fail())
				cout<<"cant open file"<<endl;
			else
			{
				while(F.read((char*)&b,sizeof(b)))
					b.display();
			}
			F.close();
			cout<<"Press a Key to Continue";
			getch();
			clrscr();
		break;
	}while(ch!=7);
};

}

