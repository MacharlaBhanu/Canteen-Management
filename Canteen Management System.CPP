#include<iostream>
#include<fstream>
#include<windows.h>
#include<cstdlib>
#include<conio.h>


/*
1: Blue
2: Green
3: Cyan
4: Red
5: Purple
6: Yellow (Dark)
7: Default white
8: Gray/Grey
9: Bright blue
10: Brigth green
11: Bright cyan
12: Bright red
13: Pink/Magenta
14: Yellow
15: Bright white*/


using namespace std;

void menu();//shows the menu for purchase
void password();//to check the password
void changepassword();
void setcolor(int);//to set the colour of the text on the output screen
void welcome();//displays the welcome screen
void name();//displays our project name
void upgradestockmanual();//to update the stock by the user
void purchase();//the main function which performs the purchase of the product
void updatebalance(int,int);//to update the customer balance
void checkstock();//displays the stock
void menu1();//displays the menu without prices
void upgradestock(int,int&,int);//updates the stock after a purchase is made
void thanks();//the end screen
void getbalance(int);//displays the balance of a particular customer
void account(int,int);//updates their due amount after the purchase
void displayorder(int,int);//displays the order at the side while making the purchase
int vp=15,ep=20,sw=30,vr=25,cpz=70,don=30,sam=10, chib=30,crmb=15,chocof=50;//the prices of the item
int sum,add,i,j,e,f,g,h,k,l,w,x,y,z,choice,admn,main1,serial,newamnt1,option1,func,d;
int m=0,n=0,o=0,p=0,q=0,r=0,s=0,t=0,u=0,v=0,m1=0,n1=0,o1=0,p1=0,q1=0,r1=0,s1=0,t1=0,u1=0,v1=0;//maintains the

char pu1[50],pu,d1[50],serial1[50];
int main()
 {
  setcolor(10);
  welcome();
  setcolor(12);
  password();
  do
  {
  system("cls");
  name();
  setcolor(15);
  cout<<"\a";

  cout<<"\n\n\n\t\t\t  1.MENU & PURCHASE";
  cout<<"\n\n\n\t\t\t  2.CHECK CUSTOMER DUE AMOUNT";
  cout<<"\n\n\n\t\t\t  3.UPDATE CUSTOMER DUE AMOUNT";
  cout<<"\n\n\n\t\t\t  4.CHECK STOCK";
  cout<<"\n\n\n\t\t\t  5.UPDATE STOCK";
  cout<<"\n\n\n\t\t\t  6.CHANGE PASSWORD";
  cout<<"\n\n\n\t\t\t  7.EXIT";
  cout<<"\n\n\n\t\t\t  ENTER YOUR CHOICE(1-7): ";
  cin>>d1;
  d=atoi(d1);
  system("cls");
  name();
  switch(d)
  {
     case 1:purchase();
              break;


     case 2:system("cls");
              name();
              cout<<"\n\n  Enter your admission no. : ";
              cin>>admn;
              getbalance(admn);
              break;

     case 3:system("cls");name();
              cout<<"\n\n  Enter your Admission No.: ";
              cin>>admn;
              cout<<"\n\n  Enter the amount paid : ";
              cin>>sum;
              updatebalance(admn,sum);
              break;

     case 4:checkstock();
              break;

     case 5:upgradestockmanual();
              break;

     case 6:changepassword();
              break;

	 case 7:main1=0;
	          thanks();
              break;
              break;

     default: cout<<"\n\n\n\t\t\t Your choice is wrong"<<"\n\n\n\t\t\t";
              system("pause");
              main1=1;
  }
  }while(main1==1);
 }

 void getbalance(int w)
 {
     int flag=0;
     int bal[10];
     int checkroll[10];
     int loop=0;
     ifstream f3;
     f3.open("balance.txt");
     while(!f3.eof())
     {
         f3>>checkroll[loop];
         f3>>bal[loop];
         loop++;
     }
     f3.close();
     do
     {
     for(int check=0;check<10;check++)
     {
         if(checkroll[check]==w)
         {
             flag=1;
             break;
         }
         if(check==9)

         {
             cout<<"\n\n\n  You have entered the wrong admn no.";
             cout<<"\n\n  Enter admission no. : ";
             cin>>w;
             break;
         }
     }
     }while(flag==0);
     ifstream f4;
     f4.open("name.txt");
     char checkname[10][10];
     loop=0;
     while(!f4.eof())
     {
         f4>>checkroll[loop];
         f4>>checkname[loop];
         loop++;
     }
     f4.close();
     for(int loop3=0;loop3<10;loop3++)
     {
         if(checkroll[loop3]==w)
         {
             system("cls");name();
             cout<<"\n\n\n\t\tWelcome "<<checkname[loop3];
             cout<<"\n\n\t\tYour current due amount is: "<<bal[loop3]<<endl;
             cout<<"\n\n\t\t";
             break;
         }
     }
     main1=1;
     system("pause");
 }

 void menu()
{
    setcolor(14);
      cout<<"\n\n";
      cout<<"\n Sno.   ITEMS                 RATE(RS)";
      cout<<"\n\n\n  1    Veg Puff                 "<<vp;
      cout<<"\n\n  2    Egg Puff                 "<<ep;
      cout<<"\n\n  3    Sandwich                 "<<sw;
      cout<<"\n\n  4    Veg Roll                 "<<vr;
      cout<<"\n\n  5    Cheese Pizza             "<<cpz;
      cout<<"\n\n  6    Doughnut                 "<<don;
      cout<<"\n\n  7    Samosa                   "<<sam;
      cout<<"\n\n  8    Chilli Bun               "<<chib;
      cout<<"\n\n  9    Cream Bun                "<<crmb;
      cout<<"\n\n  10   Chocolate Fudge          "<<chocof;
}

void account(int x,int money)
{
 system("cls");name();
 int flag=0;
 ifstream file1;
 file1.open("name.txt");
 char name[10][20];
 int admn1[10];
 int j=0;
 while(!file1.eof())
 {
	file1>>admn1[j];
	file1>>name[j];
	j++;
}
 do
 {
     for(int check=0;check<10;check++)
     {
         if(admn1[check]==x)
         {
             flag=1;
             break;
         }
         if(check==9)
         {
             cout<<"\n\n\n  You have entered the wrong admn no.";
             cout<<"\n\n  Enter admission no. : ";
             cin>>x;
             break;
         }
     }
 }while(flag==0);
 system("cls");

 for(int i=0;i<10;i++)
 {
     if(x==admn1[i])
     {
      //name();
      cout<<"\n\n\n\n\t\tWelcome  "<< name[i]<<endl;
      break;
     }
 }
 ifstream file2;
 file2.open("balance.txt");
 int balance[10];
 j=0;
 while(!file2.eof())
 {
   file2>>admn1[j];
   file2>>balance[j];
   j++;
 }
 file2.close();
 std::ofstream f2;
 f2.open("balance.txt",std::ofstream::out|std::ofstream::trunc);
 f2.close();
 for(int k=0;k<10;k++)
 {
     if(x==admn1[k])
     {
         balance[k]=balance[k]+money;
         cout<<"\n\n\t"<<name[k]<<" your total due amount is Rs. "<<balance[k]<<endl;
         cout<<"\n\n\tThis amount has been updated in our database"<<endl;
         break;
     }

 }
 ofstream f1;
 f1.open("balance.txt");
 for(int l=0;l<10;l++)
 {
     f1<<admn1[l]<<"  ";
     f1<<balance[l]<<"\n";
 }
 cout<<"\n\n";
 main1=1;
 system("pause");
}

void welcome()
{
    cout<<"\n\n\t\t\t  WELCOME TO BITS AND BYTES";
    cout<<"\n\t\t\t  _________________________";
    cout<<"\n\n\n\n\n\n\t\t\t   PROJECT DONE BY \n\n\t\t\t   ABHIJIT AND HARSHIT";
    cout<<"\n\t\t\t   *******     *******";
    cout<<"\n\n\t\t\t   CLASS XII - B"<<endl;
    cout<<"\n\t\t   ";
    system("pause");
}

void purchase()
{
      setcolor(12);
      do
      {
      system("cls");
      name();
      menu();
      setcolor(12);
      cout<<"\n\n\n\n  DO YOU WANT TO PURCHASE(Y/N)... ";
      cin>>pu1;
      pu=pu1[0];
      if(pu!='n'&&pu!='y'&&pu!='Y'&&pu!='N')
      {
          cout<<"\n  Your choice is wrong"<<endl;
          system("pause");
      }
      }while(pu!='n'&&pu!='y'&&pu!='Y'&&pu!='N');
	 while(pu=='Y'||pu=='y')
	{
	  system("cls");
	  name();
	  menu();
	  setcolor(12);
      char choice1[10];
      int check;
	  do
      {
	  cout<<"\n\n\n  Enter the serial no.(1-10): ";
	  cin>>choice1;
	  choice=atoi(choice1);
	  for(int i=1;i<11;i++)
      {
          if(choice==i)
          {
              check=1;
          }
      }
      if(check!=1)
      {
          cout<<"\n  INVALID SERIAL NO\n\n  PLEASE ENTER VALID SERIAL NO.";
          cout<<"\n\n";
          system("pause");
          system("cls");
          name();
          menu();
      }
      }while(check!=1);
      cout<<"\n\n";
	  switch(choice)
	  {
	   case 1: cout<<"  How many Veg Puff : ";
		   cin>>m;
		   m=m+m1;
		   upgradestock(1,m,2);
		   break;
	   case 2: cout<<"  How many Egg Puff : ";
		   cin>>n;
		   n=n+n1;
		   upgradestock(2,n,2);
		   break;
	   case 3: cout<<"  How many Sandwich : ";
		   cin>>o;
		   o=o+o1;
		   upgradestock(3,o,2);
		   break;
	   case 4: cout<<"  How many Veg Roll : ";
		   cin>>p;
		   p=p+p1;
		   upgradestock(4,p,2);
		   break;
	   case 5: cout<<"  How many Cheese Pizza : ";
		   cin>>q;
		   q=q+q1;
		   upgradestock(5,q,2);
		   break;
	   case 6: cout<<"  How many Doughnut : ";
		   cin>>r;
		   r=r+r1;
		   upgradestock(6,r,2);
		   break;
	   case 7: cout<<"  How many Samosa : ";
		   cin>>s;
		   s=s+s1;
		   upgradestock(7,s,2);
		   break;
	   case 8: cout<<"  How many Chilli Bun : ";
		   cin>>t;
		   t=t+t1;
		   upgradestock(8,t,2);
		   break;
	   case 9: cout<<"  How many Cream Bun : ";
		   cin>>u;
		   u=u+u1;
		   upgradestock(9,u,2);
		   break;
	  case 10: cout<<"  How many Chocolate Fudge : ";
		   cin>>v;
		   v=v+v1;
		   upgradestock(10,v,2);
		   break;
	  default : cout<<"\n  Wrong Choice";
	  }
	  cout<<"\n\n  Do you want to purchase more items(Y/N)...  ";
	  cin>>pu1;
	  pu=pu1[0];
      system("cls");
      name();
	   m1=m;
	   n1=n;
	   o1=o;
	   p1=p;
	   q1=q;
	   r1=r;
	   s1=s;
	   t1=t;
	   u1=u;
	   v1=v;
	}
	  cout<<"\n";
	    e=m*vp;
		f=n*ep;
		g=o*sw;
		h=p*vr;
		k=q*cpz;
		l=r*don;
		w=s*sam;
		x=t*chib;
		y=u*crmb;
		z=v*chocof;
		sum=e+f+g+h+k+l+w+x+y+z;
		add=m+n+o+p+q+r+s+t+u+v;
		if(add!=0)
        {
	     system("cls");
	     name();
	     setcolor(15);
	     cout<<"\n\n\t\t\t\tHUS CANTEEN\n";
	     cout<<"\n\n\t\t\t\t  CASH MEMO\n";
	     cout<<"===============================================================================";
	     cout<<"\nITEMS"            <<"              QUANTITY                 PRICE(Rs.)";
	     cout<<"\n===============================================================================";
	     if(m>0)
	     cout<<"\n\nVeg Puff              "<<m<<"                      Rs."<<m*vp;
	     if(n>0)
         cout<<"\n\nEgg Puff              "<<n<<"                      Rs."<<n*ep;
	     if(o>0)
	     cout<<"\n\nSandwich              "<<o<<"                      Rs."<<o*sw;
	     if(p>0)
	     cout<<"\n\nVeg Roll              "<<p<<"                      Rs."<<p*vr;
	     if(q>0)
         cout<<"\n\nCheese Pizza          "<<q<<"                      Rs."<<q*cpz;
         if(r>0)
	     cout<<"\n\nDoughnut              "<<r<<"                      Rs."<<r*don;
	     if(s>0)
	     cout<<"\n\nSamosa                "<<s<<"                      Rs."<<s*sam;
	     if(t>0)
	     cout<<"\n\nChilli Bun            "<<t<<"                      Rs."<<t*chib;
	     if(u>0)
	     cout<<"\n\nCream Bun             "<<u<<"                      Rs."<<u*crmb;
         if(v>0)
	     cout<<"\n\nChocolate Fudge       "<<v<<"                      Rs."<<v*chocof;
	     cout<<"\n===============================================================================";
	     cout<<"\nTOTAL:                "<<add<<"                      Rs."<<sum;
          m=0,n=0,o=0,p=0,q=0,r=0,s=0,t=0,u=0,v=0;
          m1=0,n1=0,o1=0,p1=0,q1=0,r1=0,s1=0,t1=0,u1=0,v1=0;//to clear the buffer
         do
         {
	     cout<<"\n\n  Do you want to add the bill amount to your account(y/n)...";
	     cin>>pu1;
	     pu=pu1[0];
	     if(pu!='y'&&pu!='Y'&&pu!='n'&&pu!='N')
         {
            cout<<"\n\n  Your choice is wrong"<<endl;
            system("pause");
         }
         }while(pu!='y'&&pu!='Y'&&pu!='n'&&pu!='N');
         if(pu=='y'||pu=='Y')
         {
         cout<<"\n\n\n  Enter your Admission No.: ";
	     cin>>admn;
	     account(admn,sum);
         }
         else if(pu=='n'||pu=='N')
         {
          main1=1;
         }
         }
         main1=1;//if no purchase is done
}



void thanks()
{
    system("cls");name();
	cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t   THANKS";
	Sleep(500);
	system("cls");name();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   THANKS";
	Sleep(500);
	system("cls");name();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   THANKS";
	Sleep(500);
	system("cls");name();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   THANKS";
	Sleep(500);
	system("cls");name();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   THANKS";
	Sleep(500);
	system("cls");name();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   THANKS";
	Sleep(500);
	system("cls");name();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   THANKS";
	Sleep(500);
	system("cls");name();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   THANKS";
	Sleep(500);
	system("cls");name();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   THANKS";
}
void password()
{
        main1=1;
    ifstream f1;
    f1.open("login.txt");
    int loginid[3];
    char password[3][10];
    int k=0;
    while(!f1.eof())
    {
        f1>>loginid[k];
        f1>>password[k];
        k++;
    }
    int login,flag,pos;
    char login1[10];
    do
    {
        system("cls");
        name();
        cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\tLOGIN ID : ";
        cin>>login1;
        login=atoi(login1);
        for(int i=0;i<3;i++)
        {
            if(login==loginid[i])
            {
                flag=1;
                pos=i;
            }
        }
        if(flag!=1)
        {
            cout<<"\n\n\t\t\t\tINVALID LOGIN ID.\n\n\t\t\t\tPLEASE TRY AGAIN";
            cout<<"\n\n\t\t\t\t";
            system("pause");
        }

    }while(flag!=1);
    char pass[100];
    do
    {
        cout<<"\n\n\t\t\t\tPASSWORD : ";
         for(int j=0; j<10;j++)
    {
        pass[j]=getch();
        cout<<"*";

        if(pass[j]=='\r')//check if enter key is pressed
        {
            pass[j]='\0';
            break;
        }
        else if(pass[j]=='\b')
            {
            if(j==0)
                cout<<"\b"<<" "<<"\b";
            else if(j>=1)
                {
                pass[j-1]='\0';//make the previous byte null if backspase is pressed
                j=j-2;
                cout<<"\b"<<" "<<"\b\b"<<" "<<"\b";
                }

             }
    }
    flag=strcmp(pass,password[pos]);
    if(flag!=0)
    {
        cout<<"\n\n\t\t\t\tINVALID PASSWORD.\n\n\t\t\t\tPLEASE TRY AGAIN";
        cout<<"\n\n\t\t\t\t";
        system("pause");
    }
    }while(flag!=0);
}

void checkstock()
{
    system("cls");name();
    int loop4=0;
    ifstream f5;
    int st[10],sn[10];
    f5.open("stock.txt");
    while(!f5.eof())
    {
        f5>>sn[loop4];
        f5>>st[loop4];
        loop4++;
    }
    cout<<"\n\n\n\t\t";
    setcolor(14);
      cout<<"\n Sno.   ITEMS              STOCK";
      cout<<"\n\n\n  1    Veg Puff  "<<"           "<<st[0];
      cout<<"\n\n  2    Egg Puff    "<<"         "<<st[1];
      cout<<"\n\n  3    Sandwich    "<<"         "<<st[2];
      cout<<"\n\n  4    Veg Roll    "<<"         "<<st[3];
      cout<<"\n\n  5    Cheese Pizza"<<"         "<<st[4];
      cout<<"\n\n  6    Doughnut    "<<"         "<<st[5];
      cout<<"\n\n  7    Samosa      "<<"         "<<st[6];
      cout<<"\n\n  8    Chilli Bun  "<<"         "<<st[7];
      cout<<"\n\n  9    Cream Bun   "<<"         "<<st[8];
      cout<<"\n\n  10   Chocolate Fudge"<<"      "<<st[9];
    cout<<"\n\n  ";
    system("pause");
    main1=1;
}

void upgradestock(int check1,int &newamnt,int option)
{
    ifstream f4;
    int sn[10],loop4=0;
    char me[10][40];
    f4.open("menu.txt");
    while(!f4.eof())
    {
        f4>>sn[loop4];
        f4>>me[loop4];
        loop4++;
    }
    loop4=0;
    ifstream f5;
    int st[10];
    f5.open("stock.txt");
    while(!f5.eof())
    {
        f5>>sn[loop4];
        f5>>st[loop4];
        loop4++;
    }
    f4.close();
    f5.close();
    if(option==2)
    {
    for(int i=0;i<10;i++)
    {
        if(check1==sn[i])
        {
            if(newamnt>st[i])
            {
                cout<<"\n\n  SORRY!!!  INSUFFICIENT QUANTITY";
                cout<<"\n\n  We have only "<<st[i]<<" in our stock"<<"\n\n  ";
                system("pause");
                newamnt=0;
                purchase();
                break;
            }
            st[i]=st[i]-newamnt;
            break;
        }
    }
    }
 std::ofstream f6;
 f6.open("stock.txt",std::ofstream::out|std::ofstream::trunc);
 f6.close();
 ofstream f7;
 f7.open("stock.txt");
 for(int j=0;j<10;j++)
 {
     f7<<sn[j]<<" ";
     f7<<st[j]<<"\n";
 }
 f7.close();
 main1=1;
}

void upgradestockmanual()
{
    system("cls");name();
    ifstream f9;
    int sn1[10],loop5=0;
    char me1[10][40];
    f9.open("menu.txt");
    while(!f9.eof())
    {
        f9>>sn1[loop5];
        f9>>me1[loop5];
        loop5++;
    }
    loop5=0;
    ifstream f10;
    int st1[10];
    f10.open("stock.txt");
    while(!f10.eof())
    {
        f10>>sn1[loop5];
        f10>>st1[loop5];
        loop5++;
    }
    f9.close();
    f10.close();
    int check2,option1,newamnt1,flag;
    char option2[100],newamnt[100];
    do
    {
      system("cls");
      name();
      menu1();
      cout<<"\n\n\t\tEnter the serial no of the product : ";
      cin>>serial1;
      check2=atoi(serial1);
      for(int i=0;i<10;i++)
      {
          if(check2==i+1)
          {
              flag=1;
              cout<<"\n\n\t\tThere are "<<st1[i]<<" "<<me1[i]<<" in stock";
          }
      }
      if(flag!=1)
      {
         cout<<"\n\n\t\tINVALID SERIAL NO.\n\n\t\tPLEASE TRY AGAIN";
         cout<<"\n\n\t\t";
         system("pause");
      }
    }while(flag!=1);
    do
    {
    cout<<"\n\n\t\tThe quantity is to be\n\n\t\t1.ADDED\n\n\t\t2.DEDUCTED ";
    cout<<"\n\n\t\t(1/2).... ";
    cin>>option2;
    option1=atoi(option2);
    if(option1!=1&&option1!=2)
    {
        cout<<"\n\n\t\tINVALID OPTION\n\n\t\tPLEASE TRY AGAIN";
        system("pause");
    }
    }while(option1!=1&&option1!=2);
    do
    {
    cout<<"\n\n\t\tEnter the quantity : ";
    cin>>newamnt;
    if(isdigit(newamnt[0]))
    {
        newamnt1=atoi(newamnt);
        flag=0;
    }
    else
    {
        cout<<"\n\n\t\tINVALID QUANTITY\n\n\t\tPLEASE TRY AGAIN";
    }
    }while(flag!=0);
    if(option1==1)
    {
    for(int i=0;i<10;i++)
    {
        if(check2==sn1[i])
        {
            st1[i]=st1[i]+newamnt1;
            cout<<"\n\n\t\tSTOCK UPDATED!!!!!";
            cout<<"\n\n\t\tThere are "<<st1[i]<<" "<<me1[i]<<" in stock";
            cout<<"\n\n\t\t";
            system("pause");
            break;
        }
    }
    }
    if(option1==2)
    {
    for(int i=0;i<10;i++)
    {
        if(check2==sn1[i])
        {
            if(newamnt1>st1[i])
            {
                cout<<"\n\n  SORRY!!!  INSUFFICIENT QUANTITY";
                cout<<"\n\n  We have only "<<st1[i]<<" in our stock"<<"\n\n  ";
                cout<<"\n\n  GOING TO MAIN MENU";
                cout<<"\n\n  ";
                main1=1;
                system("pause");
                break;
            }
            st1[i]=st1[i]-newamnt1;
            cout<<"\n\n\t\tSTOCK UPDATED!!!!!!";
            cout<<"\n\n\t\tThere are "<<st1[i]<<" "<<me1[i]<<" in stock";
            cout<<"\n\n\t\t";
            system("pause");
            break;
        }
    }
    }
 std::ofstream f11;
 f11.open("stock.txt",std::ofstream::out|std::ofstream::trunc);
 f11.close();
 ofstream f12;
 f12.open("stock.txt");
 for(int j=0;j<10;j++)
 {
     f12<<sn1[j]<<" ";
     f12<<st1[j]<<"\n";
 }
 main1=1;
}

void setcolor(int value)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);
}

void menu1()
{
    setcolor(14);
      cout<<"\n Sno.   ITEMS";
      cout<<"\n\n\n  1    Veg Puff  ";
      cout<<"\n\n  2    Egg Puff    ";
      cout<<"\n\n  3    Sandwich    ";
      cout<<"\n\n  4    Veg Roll    ";
      cout<<"\n\n  5    Cheese Pizza";
      cout<<"\n\n  6    Doughnut    ";
      cout<<"\n\n  7    Samosa      ";
      cout<<"\n\n  8    Chilli Bun  ";
      cout<<"\n\n  9    Cream Bun   ";
      cout<<"\n\n  10   Chocolate Fudge";
}


void updatebalance(int x,int money)
{
 system("cls");name();
 int flag=0;
 ifstream file1;
 file1.open("name.txt");
 char name1[10][20];
 int admn1[10];
 int j=0;
 while(!file1.eof())
 {
	file1>>admn1[j];
	file1>>name1[j];
	j++;
}
 do
 {
     for(int check=0;check<10;check++)
     {
         if(admn1[check]==x)
         {
             flag=1;
             break;
         }
         if(check==9)
         {
             cout<<"\n  You have entered the wrong admn no.";
             cout<<"\n\n  Enter admission no. : ";
             cin>>x;
             break;
         }
     }
 }while(flag==0);
 system("cls");
 name();
 for(int i=0;i<10;i++)
 {
     if(x==admn1[i])
     {
      //name();
      cout<<"\n\n\t\tWelcome  "<< name1[i]<<endl;
      break;
     }
 }
 ifstream file2;
 file2.open("balance.txt");
 int balance[10];
 j=0;
 while(!file2.eof())
 {
   file2>>admn1[j];
   file2>>balance[j];
   j++;
 }
 file2.close();
 std::ofstream f2;
 f2.open("balance.txt",std::ofstream::out|std::ofstream::trunc);
 f2.close();
 for(int k=0;k<10;k++)
 {
     if(x==admn1[k])
     {
         balance[k]=balance[k]-money;
         cout<<"\n\n\t"<<name1[k]<<" your total due amount is Rs. "<<balance[k]<<endl;
         cout<<"\n\n\tThis amount has been updated in our database"<<endl;
         break;
     }

 }
 ofstream f1;
 f1.open("balance.txt");
 for(int l=0;l<10;l++)
 {
     f1<<admn1[l]<<"  ";
     f1<<balance[l]<<"\n";
 }
 cout<<"\n\n";
 main1=1;
 system("pause");
}

void name()
{
    setcolor(12);
    cout<<"\n\n\n\t\t\t\tBITS AND BYTES";
    cout<<"\n\t\t\t\t______________";
}

void changepassword()
{
    ifstream f1;
    f1.open("login.txt");
    int loginid[3];
    char password[3][10];
    int k=0;
    while(!f1.eof())
    {
        f1>>loginid[k];
        f1>>password[k];
        k++;
    }
    f1.close();
    int login,flag,pos;
    char login1[10];
    do
    {
        system("cls");
        name();
        cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\tLOGIN ID : ";
        cin>>login1;
        login=atoi(login1);
        for(int i=0;i<3;i++)
        {
            if(login==loginid[i])
            {
                flag=1;
                pos=i;
            }
        }
        if(flag!=1)
        {
            cout<<"\n\n\t\t\t\tINVALID LOGIN ID.\n\n\t\t\t\tPLEASE TRY AGAIN";
            cout<<"\n\n\t\t\t\t";
            system("pause");
        }

    }while(flag!=1);
    char pass[100];
    do
    {
        cout<<"\n\n\t\t\t\tENTER YOUR OLD PASSWORD : ";
         for(int j=0; j<10;j++)
    {
        pass[j]=getch();
        cout<<"*";

        if(pass[j]=='\r')//check if enter key is pressed
        {
            pass[j]='\0';
            break;
        }
        else if(pass[j]=='\b')
            {
            if(j==0)
                cout<<"\b"<<" "<<"\b";
            else if(j>=1)
                {
                pass[j-1]='\0';//make the previous byte null if backspase is pressed
                j=j-2;
                cout<<"\b"<<" "<<"\b\b"<<" "<<"\b";
                }

             }
    }
    flag=strcmp(pass,password[pos]);
    if(flag!=0)
    {
        cout<<"\n\n\t\t\t\tINVALID PASSWORD.\n\n\t\t\t\tPLEASE TRY AGAIN";
        cout<<"\n\n\t\t\t\t";
        system("pause");
    }
    }while(flag!=0);
    system("cls");
    name();
    char pass1[10],pass2[10];
    do
    {
        cout<<"\n\n\n\n\n\n\n\n\t\t\t\tENTER YOUR NEW PASSWORD : ";
        for(int j=0; j<10;j++)
    {
        pass1[j]=getch();
        cout<<"*";

        if(pass1[j]=='\r')//check if enter key is pressed
        {
            pass1[j]='\0';
            break;
        }
        else if(pass1[j]=='\b')
            {
            if(j==0)
                cout<<"\b"<<" "<<"\b";
            else if(j>=1)
                {
                pass1[j-1]='\0';//make the previous byte null if backspase is pressed
                j=j-2;
                cout<<"\b"<<" "<<"\b\b"<<" "<<"\b";
                }

             }
    }
    cout<<"\n\n\t\t\t\tCONFIRM YOUR NEW PASSWORD : ";
        for(int j=0; j<10;j++)
    {
        pass2[j]=getch();
        cout<<"*";

        if(pass2[j]=='\r')//check if enter key is pressed
        {
            pass2[j]='\0';
            break;
        }
        else if(pass2[j]=='\b')
            {
            if(j==0)
                cout<<"\b"<<" "<<"\b";
            else if(j>=1)
                {
                pass2[j-1]='\0';//make the previous byte null if backspase is pressed
                j=j-2;
                cout<<"\b"<<" "<<"\b\b"<<" "<<"\b";
                }

             }
    }
    flag=strcmp(pass1,pass2);
    if(flag!=0)
    {
        cout<<"\n\n\t\t\t\tPASSWORDS DONT MATCH.\n\n\t\t\t\tPLEASE TRY AGAIN";
        cout<<"\n\n\t\t\t\t";
        system("pause");
        system("cls");
        name();
    }
    }while(flag!=0);
    std::ofstream f6;
    f6.open("login.txt",std::ofstream::out|std::ofstream::trunc);
    f6.close();
     ofstream f7;
    f7.open("login.txt");
    for(int j=0;j<3;j++)
    {
     f7<<loginid[j]<<" ";
     if(j==pos)
        f7<<pass1<<"\n";
     else
     f7<<password[j]<<"\n";
    }
    f7.close();
    cout<<"\n\n\t\t\t\tPASSWORDS CHANGED SUCCESSFULLY";
    cout<<"\n\n\n\t\t\t\t";
    system("pause");
    main1=1;
}


