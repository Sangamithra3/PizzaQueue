/*IMPLEMENTATION OF CIRCULAR QUEUES IN A PIZZA SHOP*/

#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;
const int MAX=10;

struct Pizza
{
  string name;
  float price;
}pizza[10];

struct order
{
  int order_number;
  string order;
};

void PizzaMenu()
{
  pizza[0].name="Margherita";
  pizza[0].price=239;
  pizza[1].name="Farmhouse";
  pizza[1].price=339;
  pizza[2].name="Peppy Paneer";
  pizza[2].price=258;
  pizza[3].name="Veg Extravaganza";
  pizza[3].price=275;
  pizza[4].name="Veggie Paradise";
  pizza[4].price=345;
  pizza[5].name="Moroccan Spice Pasta Pizza - Veg";
  pizza[5].price=435;
  pizza[6].name="Creamy Tomato Pasta Pizza - Veg";
  pizza[6].price=385;
  pizza[7].name="Mexican Green Wave";
  pizza[7].price=350;
  pizza[8].name="Paneer Makhani";
  pizza[8].price=375;
  pizza[9].name="Cheese n Corn";
  pizza[9].price=379;
}

void displayMenu()
{
  system("cls");
  cout<<"\n SELECT YOUR PIZZA \n\n";
  for(int i=0;i<10;i++)
  {
    cout<<i+1<<")"<<" PIZZA:"<<pizza[i].name;
    cout<<"\n  PRICE: Rs."<<pizza[i].price;
    cout<<endl;
  }
}

class takingOrder
{
	int front,rear;
    order orders[MAX]; //queue
	public:
		takingOrder()
		{
			front=rear=-1;
			for(int i=0;i<MAX;i++)
            {
              orders[i].order_number=0;
              orders[i].order=" ";
            }
		}
		bool addOrder(int id,string pizza);
		void serveOrder();
		void generateBill();
		void display();
};

bool takingOrder::addOrder(int id,string pizza)  //enqueue
{
 	if(rear==-1)
 	{
 		front=rear=0;
 		orders[rear].order_number=id;
 		orders[rear].order=pizza;
        return true;
	 }
	 else
	 {
	 	int pos=(rear+1)%MAX;
	 	if(pos==front)
	 	{
	 		cout<<"\n\t CAFE IS FULL,PLEASE WAIT!\n";
	 		return false;
		 }
		 else
		 {
		 	rear=pos;
		 	orders[rear].order_number=id;
		    orders[rear].order=pizza;
		 	return true;
		 }
	 }
 }

 void takingOrder::serveOrder()  //dequeue
 {
 	if(front==-1)
 	{
 		cout<<"\n \t NO ORDERS ARE AVAILABLE!  \t\n";
 		return;
	 }
	 else
	 {
	 	cout<<"\n Order No. "<<orders[front].order_number<<" is processed.\n";
	 	generateBill();
	 	if(front==rear) //Q is empty
	 	{
	 		front=rear=-1;
		 }
		 else
		 {
		 	front=(front+1)%MAX;
		 }
	 }
 }

void takingOrder::generateBill()
{
  system("cls");
  cout<<"\n\t\t\t\t DHANU'S PIZZERIA ";
  cout<<"\n\n\t\t\t\t ORDER NUMBER : "<<orders[front].order_number;
  cout<<"\n\n\n\t\t\t\t---------------BILL--------------";
  for(int i=0;i<10;i++)
  {
    if(orders[front].order==pizza[i].name)
    {
      cout<<"\n \t\t\t\tORDER : "<<pizza[i].name;
      cout<<"\n \t\t\t\tAMOUNT : Rs."<<pizza[i].price;
      break;
    }
  }
  cout<<"\n\t\t\t\t-----------------------------------";
  getch();
}

void takingOrder::display()
 {
 	int i=0;
 	if(front==-1)
 	{
 		cout<<"\n\t NO ORDERS ARE PROCESSED CURRENTLY!\n";
 		return;
	 }
	 else
	 {
	 	cout<<"Order Id's: \n";
	 	for(i=front;i!=rear;i=((i+1)%MAX))
	 	{
	 		cout<<orders[i].order_number<<"  ";
	 		cout<<orders[i].order;
	 		cout<<endl;
        }
		 cout<<orders[rear].order_number<<"  ";
		 cout<<orders[rear].order;
	 }
 }

 void intro()
 {
     char name[50]={"\n \t\t\t\t\t\tDHANU'S PIZZERIA "};
 		for(int i=0;name[i]!='\0';i++)
	{
		Sleep(50);
		cout<<name[i];

	}
 }


 int main()
 {
    int i;
    int x,y;
    char password[30],username[30],c;
    cout<<"\n\n\t\t\tPLEASE PROVIDE LOGIN DETAILS:\n";
	cout<<"\n\n\t\t\t USERNAME  : ";
	cin>>username;
	cout<<"\n\n\t\t\t PASSWORD  : ";
	while((c=getch())!=13)
	{
       password[i++]=c;
       cout<<"*";
	}
   password[i] = '\0';
   x=strcmp(username,"sangu");
   y=strcmp(password,"dhanu");
   if(x!=0 || y!=0)
   {
     cout<<"\n\n\t\t\t ACCESS DENIED!\n";
     exit(1);
   }

 	int ch,id=0,num;
	takingOrder q;
	PizzaMenu();
	do
	{
		system("cls");
		cout<<"\n \t\t\t\t---------------------------------------------------";
	    intro();
		cout<<"\n \t\t\t\t---------------------------------------------------";
		cout<<"\n\n\n\t\t\t\t------------MENU-----------\n";
		cout<<"\t\t\t\t1. ACCEPT ORDER\n";
		cout<<"\t\t\t\t2. SERVE ORDER\n";
		cout<<"\t\t\t\t3. DISPLAY ORDERS\n";
		cout<<"\t\t\t\t4. EXIT";

		cout<<"\nChoice: ";
		cin>>ch;

		switch(ch)
		{
		case 1:
		       {
                 id++;
                 displayMenu();
                 cout<<"\n Enter your choice : ";
                 cin>>num;
                 if(q.addOrder(id,pizza[num-1].name))
				  {
                    cout<<"\n \t THANKYOU FOR ORDERING,PLEASE WAIT TILL YOUR ORDER GETS READY!";
                    cout<<"\n \t YOUR ORDER NUMBER IS :  "<<id;
                    getch();
                  }
				 else
				  {
					id--;
                  }
				break;
		       }

		case 2:
		       {
                  q.serveOrder();
                  getch();
				  break;
		       }

		case 3:
		       {
                  q.display();
                  getch();
				  break;
		       }
        default:
             break;
		}
	}while(ch!=4);

	cout<<"\n \t THANK YOU FOR VISITING! HAVE A NICE DAY! \n";

 }
