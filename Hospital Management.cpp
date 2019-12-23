#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string>

int menu();
void Doctor();
void View();
void Add();
void Modify();
void Delete();
void Patient();
void Admit();
void Show();
void Remove();
void Change();


using namespace std;
int main()
{
    cout<<"\t\t\t\t\t Welcome To Our Hospital "<<endl;
     cout<<"\t\t\t\t\t*************************"<<endl;
     cout<<"\t\t\t\t\tFriends And Family Hospital      "<<endl;
     cout<<"\t\t\t\t\t    Dhaka, Bangladesh        "<<endl;
     cout<<"\t\t\t\t\t     Treatment First       "<<endl;
     cout<<"\t\t\t\t\twebsite : www.fnfh.org         "<<endl;
     cout<<"\t\t\t\t\t  Phone : 01711112222         \n\n "<<endl;
    menu();
    return 0;
}
int menu()
{
    int n,c;
   {
     cout<<"Press 1 for Doctor  :  "<<endl;
     cout<<"Press 2 for Patient :  "<<endl;
     cout<<"Press 3 for Exit    :  "<<endl;
     cout<<endl;
     cin>>n;
     if(n==1)
     {
        Doctor();
     }
     if(n==2)
     {
         Patient();
     }
      if(n==3)
      {
        cout<<"-------------Thank you :)----------------"<<endl;
        cout<<"\n\n"<<endl;
      }
}
return n;
}
void Doctor()
{
    int c;
    cout<<"--------Welcome to the Doctors unit-------- "<<endl;
    while(c!=5)
     {
     cout<<"\n"<<endl;
     cout<<"Press 1 for View Doctor List:  "<<endl;
     cout<<"Press 2 for New Doctor      :  "<<endl;
     cout<<"Press 3 for Change Doctor   :  "<<endl;
     cout<<"Press 4 for Remove Doctor   :  "<<endl;
     cout<<"Press 5 for Main Menu       :  "<<endl;
     cout<<"\n\n"<<endl;
     cin>>c;
     if(c==1)
     {
         View();
     }
     if(c==2)
     {
         Add();
     }
     if(c==3)
     {
         Modify();
     }
     if(c==4)
     {
      Delete();
     }
     if(c==5)
     {
        menu();
     }
}
}
void View()
{
    int id,room,c;
     string name,specialist;
              ifstream output;
     cout<<"ID-------Name------Specialist--------Room"<<endl;

     output.open("Doctor.txt");
     while(!output.eof())
     {
         if( output>>id>>name>>specialist>>room)
         {
         cout<<id<<"   "<<name<<"   "<<specialist<<"   "<<room<<endl;
         c++;
         cout<<"\n";
         }
     }
     output.close();
}

void Add()
{
    int id,room,c;
     string name,specialist;
             ofstream input;
     cout<<"Enter Id          :";
     cin>>id;
     cout<<"Enter name        : ";
     cin>>name;
     cout<<"Enter Specialist  : ";
     cin>>specialist;
     cout<<"Enter Room        :";
     cin>>room;
     input.open("Doctor.txt",ios::app);

     input<<id<<"   "<<name<<"  "<<specialist<<"  "<<room<<endl;
     input.close();
     cout<<"\n"<<endl;
}
void Modify()
{
    int id,room,find,c;
    string name, specialist;
    ifstream file;
    ofstream outfile;

    file.open("Doctor.txt");
    while(!file.eof())
    {
        if(file>>id>>name>>specialist>>room)
        {
         cout<<id<<"   "<<name<<"   "<<specialist<<"   "<<room<<endl;
        }
    }
    file.close();
     file.open("Doctor.txt");
    cout<<"Which doctor do you want to change?"<<endl;
    cin>>find;
    outfile.open("kowsar.txt");
    while(!file.eof())
    {
        if(file>>id>>name>>specialist>>room)
        {
            if(find==id)
            {

                 cout<<"Enter Doctor's name: "<<endl;
                 cin>>name;
                 cout<<"Enter specialist   : "<<endl;
                 cin>>specialist;
                 cout<<"Enter Room No.     : "<<endl;
                 cin>>room;
             outfile<<"   "<<id<<"   "<<name<<"   "<<specialist<<"   "<<room<<endl;

            }
            else
            {
                outfile<<"  "<<id<<"  "<<name<<"  "<<specialist<<"  "<<room<<endl;
            }
        }
    }
    file.close();
    outfile.close();
     if( remove("Doctor.txt") != 0 )
                perror( "Error deleting file" );
            else
                puts( "New doctor has appointed successfully!!!" );
            rename("kowsar.txt" ,"Doctor.txt");
            cout<<"\n";

         }
void Delete()
{
    int id,room,find,c;
    string name, specialist;
    ifstream file;
    ofstream outfile;

    file.open("Doctor.txt");
    while(!file.eof())
    {
        if(file>>id>>name>>specialist>>room)
        {
         cout<<id<<"   "<<name<<"   "<<specialist<<"   "<<room<<endl;
        }
    }
    file.close();
     file.open("Doctor.txt");
    cout<<"Which doctor do you want to remove?\n Enter the id => "<<endl;
    cin>>find;
    outfile.open("kowsar.txt");
    while(!file.eof())
    {
        if(file>>id>>name>>specialist>>room)
        {
            if(find==id)
            {


            }
            else
            {
                outfile<<" "<<id<<" "<<name<<" "<<specialist<<" "<<room<<endl;
            }
        }
    }
    file.close();
    outfile.close();
     if( remove("Doctor.txt") != 0 )
                perror( "Error deleting file" );
            else
                puts( "Doctor has successfully removed !!!" );
            rename("kowsar.txt" ,"Doctor.txt");
cout<<"\n";
}
void Patient()
{
    int p;
    while(p!=5)
     {
     cout<<"--------Welcome to the Patients unit-------- \n"<<endl;
     cout<<"Press 1 for View Patient List:  "<<endl;
     cout<<"Press 2 for Admitting Patient:  "<<endl;
     cout<<"Press 3 for Release Patient  :  "<<endl;
     cout<<"Press 4 for Replace Patient  :  "<<endl;
     cout<<"Press 5 for Main Menu        :  "<<endl;
     cin>>p;
     cout<<"\n";
     if(p==1)
     {
         Show();
     }
     if(p==2)
     {
         Admit();
     }
     if(p==3)
     {
        Remove();
     }
     if(p==4)
     {
      Change();
     }
     if(p==5)
     {
        menu();
     }
}
}
void Admit()
{
     int id,cabin,p;
     string name,problem;
     ofstream input;
     cout<<"Enter Id       :";
     cin>>id;
     cout<<"Enter name     :";
     cin>>name;
     cout<<"Enter Problem  :";
     cin>>problem;
     cout<<"Enter Cabin No.:";
     cin>>cabin;
     input.open("patient.txt",ios::app);

     input<<id<<"    "<<name<<"    "<<problem<<"    "<<cabin<<endl;
     input.close();
     cout<<"\n";

}
void Show()
{
  int id,cabin,c=0,p;
     string name,problem;

     ifstream output;
     cout<<"ID-----Name----Problem---Cabin"<<endl;

     output.open("patient.txt");
     while(!output.eof())
     {
         if( output>>id>>name>>problem>>cabin)
         {
         cout<<id<<"   "<<name<<"   "<<problem<<"   "<<cabin<<endl;
         c++;
         cout<<"\n";
         }
     }
     output.close();
}
void Remove()
{
int id,cabin,find,day,bill;
    string name, problem;
    ifstream file;
    ofstream outfile;

    file.open("patient.txt");
    while(!file.eof())
    {
        if(file>>id>>name>>problem>>cabin)
        {
         cout<<id<<"   "<<name<<"   "<<problem<<"   "<<cabin<<endl;
        }
    }
    file.close();
     file.open("patient.txt");
    cout<<"Which Patient do you want to Release?\n Enter Id => "<<endl;
    cin>>find;
    outfile.open("kowsar.txt");
    while(!file.eof())
    {
        if(file>>id>>name>>problem>>cabin)
        {
            if(find==id)
            {



            }
            else
            {
                outfile<<" "<<id<<" "<<name<<" "<<problem<<" "<<cabin<<endl;
            }
        }
    }
    file.close();
    outfile.close();
     if( remove("patient.txt") != 0 )
                perror( "Error deleting file" );
            else
                puts( "\t\tPlease Pay the bill,Sir." );
            rename("kowsar.txt" ,"patient.txt");
            cout<<"\n How many days you have stayed????"<<endl;
            cin>>day;
            bill=1000*day+500*day;
            cout<<"Your total bill is :"<<bill<< " taka"<<endl;
            cout<<"------Thank You for paying the bill------\n"<<endl;

}
void Change()
{
int id,cabin,find;
    string name, problem;
    ifstream file;
    ofstream outfile;

    file.open("patient.txt");
    while(!file.eof())
    {
        if(file>>id>>name>>problem>>cabin)
        {
         cout<<id<<"   "<<name<<"   "<<problem<<"   "<<cabin<<endl;
        }
    }
    file.close();
     file.open("patient.txt");
    cout<<"Which Patient do you want to Replace?"<<endl;
    cin>>find;
    outfile.open("kowsar.txt");
    while(!file.eof())
    {
        if(file>>id>>name>>problem>>cabin)
        {
            if(find==id)
            {

                 cout<<"Enter name    : "<<endl;
                 cin>>name;
                 cout<<"Enter problem : "<<endl;
                 cin>>problem;
                 cout<<"Enter cabin   : "<<endl;
                 cin>>cabin;
             outfile<<" "<<id<<" "<<name<<" "<<problem<<" "<<cabin<<endl;

            }
            else
            {
                outfile<<" "<<id<<" "<<name<<" "<<problem<<" "<<cabin<<endl;
            }
        }
    }
    file.close();
    outfile.close();
     if( remove("patient.txt") != 0 )
                perror( "Error deleting file" );
            else
                puts( "Patient has successfully released!!!" );
            rename("kowsar.txt" ,"patient.txt");
            cout<<"\n";

}

