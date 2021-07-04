
                     ///-------------------------------------///
                    ///******STUDENT MANAGEMENT SYSTEM******///
                   ///-------------------------------------///

///Header Files///

#include<iostream>
#include<fstream>  ///this header file is for file manipulation
#include<conio.h>
#include<cstdlib>
#include<string>

using namespace std;

class student
{
private:

    string name,add,email,course;

    int cno,rno; ///cno=contact number & rno=roll number

public:

    void insert_data(); ///insert_d means insert data

    void display_data();

    void modify_data();

    void search_data();

    void delete_data();
};

void student::insert_data() /// To Add student details
{
    system("cls");   ///clear screen
    fstream file;
    cout<<"\n-----------------------------------------------------------------------------";
    cout<<"\n-----------------------------Add Student Record------------------------------";
    cout <<"\nEnter Student Name:";
    cin>>name;
    cout <<"\nEnter Student Roll Number:";
    cin>>rno;
    cout <<"\nEnter Student Address:";
    cin>>add;
    cout <<"\nEnter Student Course:";
    cin>>course;
    cout <<"\nEnter Student E-mail:";
    cin>>email;
    cout <<"\nEnter Student Contact Number:";
    cin>>cno;
    file.open("StudentsRecord.txt",ios::app | ios::out);                            ///write file and store data into them
    file<<" "<<name<<" "<<rno<<" "<<course<<" "<<email<<" "<<cno<<" "<<add<<"\n";
    file.close();                                                                  ///file close by close() function
}

 void student::display_data()  /// for displaying students data
 {
     system("cls");
     int total=1;  ///initialize the number of students and their data present in file
    fstream file;
    cout<<"\n-----------------------------------------------------------------------------";
    cout<<"\n-----------------------------Students Record display-------------------------";
    file.open("StudentsRecord.txt",ios::in);  ///this will read all the data from files.
    if(!file)
    {
        cout<<"\nOpps...!!!\n";
        cout<<"  No data is present!\n";
        file.close();                            ///file close
    }
      else
    {
        file >> name >> rno >> course >> email >> cno >> add;
        while(!file.eof())
        {
            cout<<"\n\n\t\t Student Number:"<<total++<<endl;  ///total++ is for increment of students found in file
            cout<<"\t\t Student Name:"<<name<<endl;
            cout<<"\t\t Student Roll Number:"<<rno<<endl;
            cout<<"\t\t Student Course:"<<course<<endl;
            cout<<"\t\t Student E-mail:"<<email<<endl;
            cout<<"\t\t Student Contact Number:"<<cno<<endl;
            cout<<"\t\t Student Address:"<<add<<endl;
            file >> name >> rno >> course >> email >> cno >> add;
        }
        if(total==0)
        {
            cout<<"Oopps...!!!\n";
            cout<<"  No data is present!\n";
        }
    }
      file.close();
 }

void student::modify_data() /// to modify data of students
 {
     system("cls");

     int roll_no;

     int found=0;                 ///initialize the number of students and their data present in file

     fstream file,file1;

     cout<<"\n-----------------------------------------------------------------------------";
     cout<<"\n----------------------------- Modify Students Record ------------------------";
     file.open("StudentsRecord.txt",ios::in);

     if(!file)
     {
         cout<<"\n Opps...!!!\n";
         cout<<"  No data is present!\n";
         file.close();
     }
     else
     {
         cout<<"\nEnter Students Roll Number Which You Want To Modify:";
         cin>>roll_no;
         file1.open("StudentsRecord.txt",ios::app | ios::out);
         file >> name >> rno >> course >> email >> cno >> add;
         while(!file.eof())
         {
             if(rno!=roll_no)
             {
                 file1<<" "<<name<<" "<<rno<<" "<<course<<" "<<email<<" "<<cno<<" "<<add<<"\n";
             }
             else
             {
                 cout <<"\nEnter Student Name:";
                 cin>>name;
                 cout <<"\nEnter Student Roll Number:";
                 cin>>rno;
                 cout <<"\nEnter Student Address:";
                 cin>>add;
                 cout <<"\nEnter Student Course:";
                 cin>>course;
                 cout <<"\nEnter Student E-mail:";
                 cin>>email;
                 cout <<"\nEnter Student Contact Number:";
                 cin>>cno;
                 file1<<" "<<name<<" "<<rno<<" "<<course<<" "<<email<<" "<<cno<<" "<<add<<"\n";
                 found++;
             }
             file >> name >> rno >> course >> email >> cno >> add;
             if(found==0)
             {
                 cout<<" \n\n\t\t Student Roll Number is not found.";
             }
         }
         file1.close();

         file.close();
     }
 }

  void student::search_data()
  {
     system("cls");

     int found=0;

     fstream file;

     file.open("StudentsRecord.txt",ios::in);
     if(!file)
     {
         cout<<"\n-----------------------------------------------------------------------------";
         cout<<"\n----------------------------- Search Students Record ------------------------";
         cout<<"\n Opps...!!!\n";
         cout<<"  No data is present!\n";
     }
     else
     {
         int rollno;

         cout<<"\n-----------------------------------------------------------------------------";
         cout<<"\n----------------------------- Search Students Record ------------------------";
         cout<<"\n Enter Roll Number You Want To Search:";
         cin>>rollno;

         file >> name >> rno >> course >> email >> cno >> add;
         while(!file.eof())
         {
             if(rollno==rno)
             {
                 cout<<"\n\t\t ----------------------------------";
                 cout<<"\n\t\t Student Name:"<<name<<endl;
                 cout<<"\n\t\t Student Roll Number:"<<rno<<endl;
                 cout<<"\n\t\t Student Course:"<<course<<endl;
                 cout<<"\n\t\t Student E-mail:"<<email<<endl;
                 cout<<"\n\t\t Student Contact Number:"<<cno<<endl;
                 cout<<"\n\t\t Student Address:"<<add<<endl;
                 found++;
             }
             file >> name >> rno >> course >> email >> cno >> add;
         }
          if(found==0)
             {
                 cout<<" \n\n\t\t Student Roll Number is not found.";
             }
             file.close();
     }
  }

   void student::delete_data()
   {
         system("cls");
         fstream file,file1;
         int rollno;
         int found=0;
          cout<<"\n-----------------------------------------------------------------------------";
          cout<<"\n----------------------------- Delete Students Record ------------------------";
         file.open("StudentsRecord.txt",ios::in);
         if(!file)
         {
         cout<<"\n Opps...!!!\n";
         cout<<"  No data is present!\n";
         file.close();
         }
         else
         {
             cout<<"\n Enter Roll Number You Want To Delete:";
             cin>>rollno;
             file1.open("StudentsRecord.txt",ios::app | ios::out);
             file >> name >> rno >> course >> email >> cno >> add;
             while(!file.eof())
             {
                 if(rollno!=rno)
                 {
                      file1<<" "<<name<<" "<<rno<<" "<<course<<" "<<email<<" "<<cno<<" "<<add<<"\n";
                 }
                 else
                 {
                     found++;
                     cout<<"\n\t\t\t Delete Successfully:";
                 }
                   file >> name >> rno >> course >> email >> cno >> add;
             }
             if(found==0)
             {
                 cout <<"\n\t\t\t Student Roll Number Not Found....";
             }
             file1.close();
             file.close();
             remove("StudentsRecord.txt");
             rename("Record.txt","StudentsRecord.txt");
         }
   }

int main()
{
    student project;

    char a;

     menustart:
    {
     int choice;
     system("cls");

    cout<<"\n\t\t\t\t---------------------------\n";
    cout<<"\t\t\t\t|Student Management System|\n";
    cout<<"\t\t\t\t---------------------------\n";
    cout<<"\n\t\t\t 1. Enter New Record.";
    cout<<"\n\t\t\t 2. Display Record.";
    cout<<"\n\t\t\t 3. Modify Record.";
    cout<<"\n\t\t\t 4. Search Record.";
    cout<<"\n\t\t\t 5. Delete Record.";
    cout<<"\n\t\t\t 6. Exit.";
    cout<<"\n\n\t\t\t\t---------------------------\n";
    cout<<"\t\t\t\t|Choose Option:[1/2/3/4/5/6]|\n";
    cout<<"\t\t\t\t---------------------------\n";
    cout<<"Enter your choice:";
    cin>>choice;

        switch(choice)
        {
          case 1:
             do
             {
             project.insert_data();
             cout<<"\n\t\t\tDo You Want To Add Another Student Details:(y/n)"<<endl;
             cin>>a;
             }while(a=='Y'|| a=='y');
             break;

           case 2:
               project.display_data();
               break;

           case 3:
               project.modify_data();
               break;

            case 4:
               project.search_data();
               break;

            case 5:
               project.delete_data();
               break;

            case 6:
               exit(0);

            default:

            cout<<"!!!!!.....Invalid input.......!!!\n";
            cout<<" Please Enter valid choice";
        }

        getch();

        goto menustart;
    }

    project.insert_data();

    project.display_data();

    project.modify_data();

    project.search_data();

    project.delete_data();

    return 0;

}

