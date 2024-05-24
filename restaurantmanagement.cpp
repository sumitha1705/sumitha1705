//Restaurant Managment System
#include <iostream>
#include <string>
#include<windows.h>
#include<iomanip>
#include<fstream>

using namespace std;
class RESTAURANT           //base class
 {     	
protected:
	
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	//member variables of RESTAURANT
    int Table_Num[30];
    int menu[30];
    static string menu_name[30];
    static int price[30];
    int total=0;
    static int max;
public:
	
	 //member function of RESTAURANT
    void view_menu();
    void view_menu_in_file();

};

string RESTAURANT::menu_name[30]={" ","Knorr Hot and sour soup","Tomato Cheddarb Soup","Creamy Cheese Soup","Chicken Corn Soup","Mushroom Soup","Caesar Salad","Fruit Salad","Panner Tikka","Paneer Fried Rice","Palak Paneer","Aloo Mutter","Pulao","Veg Meals","Mushrrom Curry","Dal Fry","Veg Briyani+Gobi+Fries","Thalappakatti Briyani","Malabar Briyani","Dragan Chicken","Mutton Chukka","Mutton Ghee Roast","Kadhai Prawn","Waffles","Black Forest Cake","Mojito","Smoothie"};
int RESTAURANT::price[30]={0,400,290,450,380,290,450,160,350,290,400,250,150,300,200,110,550,600,580,220,190,180,310,225,500,120,100};
int RESTAURANT::max=0;
class ADMIN:public RESTAURANT   //derived class 1 of base clas
{
private:
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	//member variables of derived class 1 (ADMIN)
    string id;
    string password;
    
public:
	
	//member function of derived class 1(ADMIN)
	
	ADMIN()
	{
		//cout<<"(Default constructor is called)\n";	
	}
	~ADMIN()    
	{
		cout<<"Object for ADMIN class is destroyed!..."<<endl;	
	}
    void admin();
    void add_item();
    void remove_item();
    
};

void ADMIN::admin() 	//Definiton of admin() outside the class
{
    int p, option;
    do {
    	
    	//menu driven for member functions of ADMIN class
    	
        cout<<"\n\t\t\t\t______________________________________\n\n";
        cout <<"\t\t\t\t  User id  :  ";
        cin >> id;
        cout <<"\t\t\t\t  Password : ";
        cin >> password;
        cout<<"\t\t\t\t______________________________________\n";
        if ((id == "71762305049@cit.edu.in" || id == "71762305051@cit.edu.in" ||
             id == "71762305060@cit.edu.in" || id == "71762305062@cit.edu.in") && password == "CIT@2024") {
            cout<<"\t\t\t\t  User id  : "<<id<<endl;
            cout<<"\t\t\t\t  Password : C******4"<<endl;
            
            cout << "\n\t\t\t\t  You are logged in as ADMIN!!.........\n\n";
            do {
            	SetConsoleTextAttribute(h,5);
            	cout<<"\n\t\t\t\t*********************\n";
            	cout<<"\t\t\t\t*                   *\n";
                cout<<"\t\t\t\t*  1. Add Item      *\n";
				cout<<"\t\t\t\t*  2. Remove Item   *\n";
				cout<<"\t\t\t\t*  3. View Menu     *\n";
				cout<<"\t\t\t\t*  4. Logout        *\n";
				cout<<"\t\t\t\t*                   *\n";
				cout<<"\t\t\t\t*********************\n";
			    SetConsoleTextAttribute(h,3);
                cout<<"->";
                cin >> option;
                
                switch (option) {
                    case 1:
                        add_item();
                        break;
                        
                    case 2:
                        remove_item();
                        break;
                        
                    case 3:
                        view_menu();
                        break;
                        
                    case 4:
                    	SetConsoleTextAttribute(h,7);//white
                    	cout<<"\nCome back soon!.....\n";
                        return;
                        
                    default:
                    	SetConsoleTextAttribute(h,7);//white
                        cout << "Option Unavailable!\n       Enter again\n";
                }
            } while (option != 4);
        }
		else
		{
            cout << "\t\t\t\t  Invalid User id or password!..\n";
            cout<<"Press 0 to proceed again : ";
            cin >> p;
        }
    } while (p == 0);
}

void ADMIN::add_item()    //definition of add_item() outside the clas
{
     string added_item;
     int added_price;
     cout<<"Enter Item to be added  : ";
     cin.ignore();
     getline(cin,added_item);
     cout<<"Enter Price of the item : ";
     cin>>added_price;
     SetConsoleTextAttribute(h,7);//white
     cout<<"\n"<<added_item<<" which costs "<<added_price<<" /- has added to the Menu successfully! ";
     cout<<"\n______________________________________________________________\n";
     max++;
     menu_name[26+max]=added_item;
     price[26+max]=added_price;
}
void ADMIN::remove_item()   //definiton of remove_item() outside the class
{
    int remove_index;
    cout << "Enter the index of the item to be removed: ";
    cin >> remove_index;

    if (remove_index >= 1 && remove_index <= 26 + max) 
	{
		SetConsoleTextAttribute(h,7);//white
        cout << menu_name[remove_index] << " has been removed from the menu.\n";
        for (int i = remove_index; i < 26 + max; ++i)
		{
            menu_name[i] = menu_name[i + 1];
            price[i] = price[i + 1];
        }
        max--; // Decrease the maximum index
    } 
    else
	{
        cout << "Invalid index!\n";
    }
    cout<<"\n___________________________________________________________\n";
}
class CUSTOMER : public RESTAURANT //derived class 2 of base class ADMIN
{ 
private:
	
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	//member variables of derived class 2 (CUSTOMER)
    string name[30];
    string phone[30];
    string mail[30];
    int Table_Num[30];

public:
	
	//member function of derived class 2 (CUSTOMER)
	CUSTOMER()
	{
		//cout<<"(Default constructor is called)"<<endl;
			
	}
	~CUSTOMER()
	{
		cout<<"Object for the CUSTOMER class is destoryed"<<endl;	
	}
    void customer();
    void generate_bill();
    void Table_reserve();
    int check(int r);
    void order_food();
    
};

void CUSTOMER::customer() 	//definition of customer outside the class
{
    int choice;
    do {        //menu driven for member function of customer class
        SetConsoleTextAttribute(h,5);//purple
        cout<<"\n\t\t\t\t**********************\n";
        cout<<"\t\t\t\t*  ENTER YOUR CHOICE *\n";
        cout<<"\t\t\t\t*  1.Table Reserve   *\n";
        cout<<"\t\t\t\t*  2.View Menu       *\n";
        cout<<"\t\t\t\t*  3.Order Food      *\n";
        cout<<"\t\t\t\t*  4.Generate Bill   *\n";
        cout<<"\t\t\t\t*  5.Exit            *\n";
        cout<<"\t\t\t\t**********************\n";
        SetConsoleTextAttribute(h,3);//skyblue
        cout<<"->";
        cin >> choice;
        switch (choice)
        {
            case 1:
                Table_reserve();
                break;
            case 2:
                view_menu();
                break;
            case 3:
                order_food();
                break;
            case 4:
                generate_bill();
                break;
            case 5:
            	 return;
            	 /*SetConsoleTextAttribute(h,4);//red
                 cout<<"\n\n\n\t\t_____________________________________\n";
                 cout<<"\t\t\tThe project is presented By\n\n";
                 cout<<"\t\t\tTEAM NO ALT+X: \n";
                 cout<<"\t\t\t\t   K SARASWATHI \n";
                 cout<<"\t\t\t\t   P SATHIYA \n";
                 cout<<"\t\t\t\t   I SUMITHA \n";
                 cout<<"\t\t\t\t   P THIRISHA \n";
                 cout<<"\t\t_____________________________________\n";
                exit(0);*/
                break;
            default:
            	SetConsoleTextAttribute(h,7);//white
                cout << "Invalid choice!!";
        }
    } while (true);
}
void CUSTOMER::Table_reserve()   // defintion of Table_reserve outside the class
         {
            int r,flag;
            SetConsoleTextAttribute(h,6);//yellow
            cout<<"\t\tTABLE RESERVATION!...\n";
	        cout<<"___________________________________________________________\n";
         	cout<<"\t\tAc      :1 to 10\n";
         	cout<<"\t\tNon-Ac  :11 to 20\n";
         	cout<<"\t\tOutdoor :21 to 30\n";
         	cout<<"___________________________________________________________\n\n";
         	 SetConsoleTextAttribute(h,3);//skyblue
	        cout<<"Which table would you like to book ? ";
            cin>>r;
            try  // try block of  Exception Handling 
            {
                if(r>0 && r<30)
                {
                	flag=check(r);
                	if(flag)
                		{
                			SetConsoleTextAttribute(h,7);//white
                	     cout<<"OOPS TABLE ALREADY BOOKED!.."<<endl;
                	     cout<<"___________________________________________________________\n\n";
                	 }
                	     
                    else
                    {
                    	Table_Num[r]=r;
                    	cout<<"ENTER THE FOLLOWING DETAILS\n";
						cout<<"NAME         : ";
						cin>>name[r];
						cout<<"PHONE NUMBER : ";
						cin>>phone[r];
						cout<<"MAIL ID      : ";
						cin>>mail[r];
						SetConsoleTextAttribute(h,7);//white
						cout<<"TABLE BOOKED!!!!\n";
						cout<<"___________________________________________________________\n";
						cout<<"\n";
					}   		 
				}
				else	// throw block of exceptional handling 
					throw "INVALID TABLE NUMBER";
            }
            catch(const char* msg)
            {	
                SetConsoleTextAttribute(h,7);//white
            		//catch block of exceptional handling
				cout<<"EXCEPTION: "<<msg<<endl; }
         	}      
void CUSTOMER::order_food() //definition of order_food outside the class
{
    int r;
    cout<<"Enter the index of the food you wish to order : ";
    cout<<"\nPress 0 when you are finished : \n";
    do
	{
		cin>>r;
		menu[r]=1;
	}while(r!=0);
	 SetConsoleTextAttribute(h,7);//white
	cout<<"YOUR ORDER HAS BEEN PLACED!\n";
	cout<<"YOUR FOOD WILL BE SERVED SOON.PLEASE WAIT UNTIL THEN.\n\n";
}
void RESTAURANT::view_menu() //definition of view_menu outside the class
 {
 	SetConsoleTextAttribute(h,6);//yellow
    cout << "MENU:\n";
    cout << "_________________________________________________________________________________\n";
    cout << "|S.NO.\t\t\t\t\t   ITEM\t\t\t\t PRICE   |\n";
    cout << "_________________________________________________________________________________\n";
    
    for(int i = 1; i < 27 + max; i++) 
	{
        cout << "|"<<setw(6) << i << ".\t\t\t" << setw(30) << left << menu_name[i];
        cout << setw(13) << right <<"Rs."<<price[i]<<"   |" << endl;
    }
    cout << "_________________________________________________________________________________\n\n";
    view_menu_in_file();
 }
void RESTAURANT::view_menu_in_file() //definition of view_menu outside the class
 {
 	ofstream outfile("AltX.txt");
    outfile<< "_______________________________________________________________________________\n";
    outfile<< "|S.NO.\t\t\t\t\t   ITEM\t\t\t\t PRICE   |\n";
    outfile<< "_______________________________________________________________________________\n";
    
    for(int i = 1; i < 27 + max; i++) 
	{
        outfile<< "|"<<setw(6) << i << ".\t\t\t" << setw(30) << left << menu_name[i];
        outfile<< setw(13) << right<<"Rs."<< price[i]<<"   |" << endl;
    }
    outfile<< "_______________________________________________________________________________\n\n";
    outfile.close();
}
void CUSTOMER::generate_bill() //definition of generate_bill outside the class
{
	int choice,discount;
	SetConsoleTextAttribute(h,6);//yellow
    cout<<"Here is your Bill Ma'am/Sir \n\n";
    SetConsoleTextAttribute(h,4);//red
    cout<<"____________________________________________________________________\n";
    cout<<"\t\t\t\tINDIAN RESTAURANT\n";
    cout<<"____________________________________________________________________\n";
    SetConsoleTextAttribute(h,6);//yellow
    cout<<"                              BILL \n\n";
    for(int i=1;i<27+max;i++)
    {
        if(menu[i]==1)
        {
           // cout<<menu_name[i]<<" : "<<price[i]<<endl;
             cout << setw(6) << i << ".\t\t\t" << setw(30) << left << menu_name[i];
        cout << setw(10) << right <<"Rs."<< price[i] << endl;
       
            total+=price[i];
        }
    }
    cout<<"_____________________________________________________________________\n";
    cout<<"\t\t\t\t\t\t    TOTAL : Rs."<<total<<"  -"<<endl;
    if(total>=1500 && total<=3000) 
    {     
	      discount=0.10*total;
	      cout<<"\t\t\t\t\t\t\t\t"<<discount<<endl;
	      cout<<"\t\t\t         After 10% Discount TOTAL : Rs."<<0.90*total<<endl;
	}
    else if(total>3000 && total<=4500)
    {     
	    discount=0.20*total;
	    cout<<"\t\t\t\t\t\t\t\t"<<discount<<endl;
	    cout<<"\t\t\t         After 20% Discount TOTAL : Rs."<<0.80*total<<endl;
	}
    else if(total>4500)
    {
	     discount=0.30*total;
	     cout<<"\t\t\t\t\t\t\t\t"<<discount<<endl;
         cout<<"\t\t\t         After 30% Discount TOTAL : Rs."<<0.70*total<<endl;
	}
     
	cout<<"_____________________________________________________________________\n";
	SetConsoleTextAttribute(h,5);//purple
	do{
	cout<<"Please Select your payment mode :\n ";
	cout<<"\t1.Debit Card\n";
	cout<<"\t2.Credit Card\n";
	cout<<"\t3.Cash            \n";
	SetConsoleTextAttribute(h,3);//skyblue
	cout<<"->";
	cin>>choice;
	switch(choice)
	{
		  SetConsoleTextAttribute(h,7);//white
          case 1:
                    cout<<"Payment has been done via Debit card successfully\n";
                    break;   
          case 2:
                    cout<<"Payment has been done via Credit card successfully\n";
                    break;
          case 3:
                    cout<<"Payment has been done via Cash successfully\n";
                    
                    break;
            default:
            	   cout<<"Invalid payment mode ";
	} 
}while(choice!=1 && choice!=2 && choice!=3);
	 SetConsoleTextAttribute(h,1);//blue
	cout<<"\n\n\t\t\t\t\t********\n";         
    cout<<"\n\t\t\t THANK YOU FOR COMING,VISIT AGAIN\n";
    cout<<"\t\t\t\t HAVE A NICE DAY!!\n";
	cout<<"\t\t\t\t\t********\n\n";          
    return;
}

int CUSTOMER::check(int r)
 {
    return Table_Num[r] != 0 ? 1 : 0;
}



int main() {
    int choice,proceed;
    ADMIN *admin_obj;
    admin_obj=new ADMIN;
    CUSTOMER *customer_obj;
    customer_obj=new CUSTOMER;
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,4);//red
    cout<<"_________________________________________________________________________________________\n\n";
	cout<<"\t\t\t\t\tINDIAN RESTAURANT\n";
    cout<<"\t\t\t\t\t  \n";
    cout<<"_________________________________________________________________________________________\n\n";
    
	do {
    	SetConsoleTextAttribute(h,7);
        cout << "\n\nYOUR DESIGNATION (ADMIN[1]/CUSTOMER[2])  : ";
        cin >> choice;
        SetConsoleTextAttribute(h,3);//skyblue
        switch (choice) {
            case 1: {
                admin_obj->admin();
                delete admin_obj;
                break;
            }
            case 2: {
                customer_obj->customer();
                SetConsoleTextAttribute(h,7);//white
                delete customer_obj;
                SetConsoleTextAttribute(h,4);//red
                 cout<<"\n\n\n\t\t_____________________________________\n";
                 cout<<"\t\t\tThe project is presented By\n\n";
                 SetConsoleTextAttribute(h,6);//red
                 cout<<"\t\t\tTEAM NO ALT+X: \n";
                 SetConsoleTextAttribute(h,4);//red
                 cout<<"\t\t\t\t   K SARASWATHI \n";
                 cout<<"\t\t\t\t   P SATHIYA \n";
                 cout<<"\t\t\t\t   I SUMITHA \n";
                 cout<<"\t\t\t\t   P THIRISHA \n";
                 cout<<"\t\t_____________________________________\n";
                exit(0);
                break;
            }
            default:
                cout << "Invalid Choice!!";
        }
        cout<<"Press 0 to proceed : ";
        cin>>proceed;
    } while (proceed==0);
    return 0;

}
