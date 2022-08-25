
// Student Report Card System Project





#include<bits/stdc++.h>
using namespace std;

void intro();   // this is introduction of our project
void entry_menu();// its a part of main menu..and the following (1-5) functions are under of it
void create_student(); // 1
void display_all_student(); //2
void search_student(int n,string sem);  //3
void modify_student();       //4
void delete_student(); //5
void delete_all_student();       //6
void result();  // its another part of main menu..and the following (6-7) functions are under of it
void class_result(string sem);  // 7
void display_Sreport( int id,string sem);  // 8
void print();// its just for checking the output


struct student    // creating a structure type student variable according to our needs
{
    int id;
    string name;
    string semester;
    string subjects[20];
    int marks[100];
    int subnum;
    int sum;
    int attend;
    double prcntg;
    float grade;

} S;



FILE *f;

void intro()
{

    cout<<endl<<endl<<endl<<"                  ================DATA STRUCTURE FINAL PROJECT===============";
    cout<<endl<<endl<<endl;
    cout<<"                                               STUDENT                              "<<endl<<endl;
    cout<<"                                             REPORT CARD                            "<<endl<<endl;
    cout<<"                                               PROJECT                              "<<endl<<endl;
    cout<<endl<<endl<<"                  ===========================================================";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<endl<<"------------------------------------------------------------------------------------------";
    cout<<endl<<" MADE BY     : Tehsim Fariha ";
    cout<<endl<<" SEMESTER     : 4th ";
    cout<<endl<<" INSTITUTION : International Islamic University Chittagong   ";
    cout<<endl<<"------------------------------------------------------------------------------------------";
    cout<<endl<<endl<<endl;


}

void entry_menu()
{

    int n;
    system("CLS");

    cout<<endl<<endl<<endl<<"\tENTRY MENU";
    cout<<endl<<endl<<"\t1.CREATE STUDENT RECORD";
    cout<<endl<<endl<<"\t2.DISPLAY ALL STUDENTS RECORDS";
    cout<<endl<<endl<<"\t3.SEARCH STUDENT RECORD ";
    cout<<endl<<endl<<"\t4.MODIFY OR EDIT STUDENT RECORD";
    cout<<endl<<endl<<"\t5.DELETE A STUDENT RECORD";
    cout<<endl<<endl<<"\t6.DELETE ALL STUDENT RECORD";
    cout<<endl<<endl<<"\t7.BACK TO MAIN MENU";
    cout<<endl<<endl<<"\tPlease Enter Your Choice (1-7) ";

    cin>>n;

    switch(n)
    {
    case 1:
        system("CLS");
        create_student();
        break;
    case 2:
        display_all_student();
        break;
    case 3:
    {
        int num;
        string sem;
        system("CLS");
        cout<<endl<<endl<<"\tPlease Enter The ID number : ";
        cin>>num;
        cout<<endl<<endl<<"\tEnter the Semester of Student : ";
        cin>>sem;
        search_student(num,sem);
    }
    break;
    case 4:
        modify_student();
        break;
    case 5:
        delete_student();
        break;
    case 6:
        delete_all_student();
        break;
    case 7:
        break;

    default:
        cout<<"\a";  //it means alarm...
        entry_menu();
    }


}

void print()
{

    cout << "SUBJECTNAME" << setw(13) << "MARKS" << endl;
    for (int i = 0; i<S.subnum; i++)
    {
        cout <<endl<<S.subjects[i] << setw(14) << S.marks[i] <<endl;
    }

}

void create_student()
{

    f=fopen("student_report_card.dat","ab"); // ab means, a=append b=binary mode,B append mane binary text add kora ektar por ekta //opens a text file for appending. (appending means to add text at the end)

    cout<<endl<<"Please Enter The New Details of student........ "<<endl;
    cout<<endl<<"Enter The ID number of student : ";
    cin>>S.id;
    fflush(stdin); // it helps to stop output buffering ...by clearing output buffer
    cout<<endl<<"Enter The Name of student : ";
    getline(cin,S.name);

    cout<<endl<<"Semester of the student : ";
    cin>>S.semester;
    cout<<endl<<"How many subjects the student have taken ? ";
    cin>>S.subnum;
    cout<<endl<<"How many days the student attend in the class ?";
    cin>>S.attend;
    fflush(stdin);



    for(int i = 0; i<S.subnum; i++)
    {

        cout<<endl<<"Enter the subjects name : ";
        getline (cin, S.subjects[i]);

        cout<<endl<<"Enter the subject marks  : ";
        cin>> S.marks[i];

        while(S.marks[i]<0 || S.marks[i]>100)
        {
            cout<<endl<<"Invalid marks!!!"<<endl;
            cout<<endl<<"Please Enter the student marks again : ";
            cin>> S.marks[i];
        }
        fflush(stdin);
    }

    //print();



    cout<<endl<<endl<<"Student Record Has Been Created ";
    cout<<endl;

    S.sum=0;

    for(int i=0; i<S.subnum; i++)
    {
        S.sum=S.sum+S.marks[i];
    }

    S.prcntg=(S.sum/S.subnum);



    if(S.prcntg>=80 && S.prcntg<=100)
    {
        S.grade=4.00;
    }

    else if(S.prcntg>=75 && S.prcntg<=79)
    {
        S.grade=3.75;
    }

    else if(S.prcntg>=70 && S.prcntg<=74)
    {
        S.grade=3.5;
    }

    else if(S.prcntg>=65 && S.prcntg<=69)
    {
        S.grade=3.25;
    }

    else if(S.prcntg>=60 && S.prcntg<=64)
    {
        S.grade=3.00;
    }

    else if(S.prcntg>=55 && S.prcntg<=59)
    {
        S.grade=2.50;
    }

    else if(S.prcntg>=50 && S.prcntg<=54)
    {
        S.grade=2.00;
    }

    else if(S.prcntg>=40 && S.prcntg<=49)
    {
        S.grade=1.00;
    }

    else
    {
        S.grade=0.00;
    }

    fwrite(&S,sizeof(S),1,f);
    fclose(f);
    system("PAUSE");
    system("CLS");

}

void display_all_student()
{

    system("CLS");
    system("PAUSE");
    cout<<endl<<endl<<endl<<"\t\tDISPLAY ALL RECORD !!!"<<endl<<endl;

    f=fopen("student_report_card.dat","rb"); //r=opens a text file for reading in binary mode

    //fread() function is used to read bytes form the file.
    //fread( S, int size, int n, FILE *f );
    //S : S is the reference of an array or a structure where data will be stored after reading.
    //size : size is the total number of bytes to be read from file.
    //n : n is number of times a record will be read. (tai amra 1 diyechi ,jate 1 ta record 1 bar e pori) That is why we used 1 so that at once we read 1 record
    // FILE* : FILE* is a file where the records will be read.

    while((fread(&S,sizeof(S),1,f))>0)  //structure type variable er size jotokhn porjnto 0 theke boro hbe totokhn prjntoi true hbe
    {

        cout<<endl<<endl<<"Id Number of Student : "<<S.id;
        cout<<endl<<endl<<"Name of student : "<<S.name;
        cout<<endl<<endl<<"Semester of the Student : "<<S.semester;
        cout<<endl<<endl<<"Taken subjects No : "<<S.subnum;
        cout<<endl<<endl<<"Total Attendance : "<<S.attend;
        cout<<endl<<endl<<endl<<"Subjects                "<<"Marks        "<<endl;
        for (int i = 0; i<S.subnum; i++)
        {
            cout<<endl<<S.subjects[i] <<"                       "<<S.marks[i]<<endl;
        }

        cout<<endl<<endl<<"===================================="<<endl;
        system("PAUSE");
        system("CLS");
    }

    fclose(f);
    system("CLS");


}

void search_student(int n,string sem)
{

    int flag=0;
    f=fopen("student_report_card.dat","rb");

    while((fread(&S,sizeof(S),1,f))>0)
    {
        if(S.id==n && S.semester==sem)
        {

            system("CLS");
            cout<<endl<<endl<<"Id Number of Student : "<<S.id;
            cout<<endl<<endl<<"Name of student : "<<S.name;
            cout<<endl<<endl<<"Semester of the Student : "<<S.semester;
            cout<<endl<<endl<<"Taken subjects No : "<<S.subnum;
            cout<<endl<<endl<<"Total Attendance : "<<S.attend;
            cout<<endl<<endl<<endl<<"Subjects                "<<"Marks        "<<endl;
            for (int i = 0; i<S.subnum; i++)
            {
                cout<<endl<<S.subjects[i] <<"                       "<<S.marks[i]<<endl;
            }

            flag=1;
        }
    }

    fclose(f);
    if(flag==0)
        cout<<endl<<endl<<"Record not exist"<<endl<<endl;

    system("PAUSE");
    system("CLS");

}

void modify_student()
{

    int num,fnd=0;
    system("CLS");

    cout<<endl<<endl<<"\tEdit the student Record again...... ";
    cout<<endl<<endl<<"\tPlease Enter The Id number of student : ";
    cin>>num;

    f=fopen("student_report_card.dat","rb+"); //r+=opens a text file for reading and writing

    while((fread(&S,sizeof(S),1,f))>0 && fnd==0)
    {

        if(S.id==num)

        {


            cout<<endl<<endl<<"Please Enter The New Details of student........ "<<endl;
            cout<<endl<<endl<<"Enter The ID number of student : ";
            cin>>S.id;
            fflush(stdin); // it helps to stop output buffering ...by clearing output buffer
            cout<<endl<<endl<<"Enter The Name of student : ";
            getline(cin,S.name);
            fflush(stdin);
            cout<<endl<<endl<<"Semester of the student :  ";
            cin>>S.semester;
            cout<<endl<<endl<<"How many subjects the student have taken ? ";
            cin>>S.subnum;
            cout<<endl<<"How many days the student attend in the class ?";
            cin>>S.attend;
            fflush(stdin);



            for(int i = 0; i<S.subnum; i++)
            {

                cout<<endl<<endl<<"Enter the subjects name : ";
                getline (cin, S.subjects[i]);

                cout<<endl<<endl<<"Enter the subject marks  : ";
                cin>> S.marks[i];

                while(S.marks[i]<0 || S.marks[i]>100)
                {
                    cout<<endl<<endl<<"Invalid marks!!!"<<endl;
                    cout<<endl<<endl<<"Please Enter the student marks again : ";
                    cin>> S.marks[i];
                }
                fflush(stdin);
            }


            S.sum=0;

            for(int i=0; i<S.subnum; i++)
            {
                S.sum=S.sum+S.marks[i];
            }

            S.prcntg=(S.sum/S.subnum);



            if(S.prcntg>=80 && S.prcntg<=100)
            {
                S.grade=4.00;
            }

            else if(S.prcntg>=75 && S.prcntg<=79)
            {
                S.grade=3.75;
            }

            else if(S.prcntg>=70 && S.prcntg<=74)
            {
                S.grade=3.5;
            }

            else if(S.prcntg>=65 && S.prcntg<=69)
            {
                S.grade=3.25;
            }

            else if(S.prcntg>=60 && S.prcntg<=64)
            {
                S.grade=3.00;
            }

            else if(S.prcntg>=55 && S.prcntg<=59)
            {
                S.grade=2.50;
            }

            else if(S.prcntg>=50 && S.prcntg<=54)
            {
                S.grade=2.00;
            }

            else if(S.prcntg>=40 && S.prcntg<=49)
            {
                S.grade=1.00;
            }

            else
            {
                S.grade=0.00;
            }

            fseek(f,-(long)sizeof(S),1);// function is used to move the cursor in the file to the desired position.
            fwrite(&S,sizeof(S),1,f);
            //fseek(fp,sizeof(struct student)*records,SEEK_SET);

            cout<<endl<<"\t Record Updated";
            fnd=1;
        }
    }

    fclose(f);

    if(fnd==0)
        cout<<endl<<endl<<"Record Not Found ";

    system("CLS");

}



void delete_student()
{


    FILE *f3;
    int no;
    system("CLS");
    cout<<endl<<endl<<endl<<"  For Deleting Specific Student Record";
    cout<<endl<<endl<<endl<<"  Please Enter The Id number of the student You Want To Delete :  ";
    cin>>no;

    f=fopen("student_report_card.dat","rb");

    f3=fopen("modify.dat","wb");
    //rewind(f3);

    while((fread(&S,sizeof(S),1,f))>0)
    {
        if(S.id!=no)
        {
            fwrite(&S,sizeof(S),1,f3);
        }
    }

    fclose(f3);
    fclose(f);

    remove("student_report_card.dat");
    rename("modify.dat","student_report_card.dat");

    cout<<endl<<endl<<" \tRecord Deleted .."<<endl<<endl;
    system("PAUSE");
    system("CLS");

}

void delete_all_student()//it will delete all the student ,but can not delete individual
{

    FILE *f2;

    system("CLS");
    cout<<endl<<endl<<endl<<"\t For Deleting All Student Record";

    f=fopen("student_report_card.dat","rb");

    f2=fopen("delete.dat","wb");
    rewind(f2);

    fclose(f2);
    fclose(f);

    remove("student_report_card.dat");
    rename("delete.dat","student_report_card.dat");

    cout<<endl<<endl<<" \tRecord Deleted .."<<endl<<endl;
    system("PAUSE");
    system("CLS");

}

void result()
{
    int n,Ino;
    char ans;
    string sem;

    system("CLS");

    cout<<endl<<endl<<endl<<"     RESULT MENU   ";
    cout<<endl<<endl<<endl<<"     1. Class Result";
    cout<<endl<<endl<<"     2. Student Report Card";
    cout<<endl<<endl<<"     3. Back to Main Menu";
    cout<<endl<<endl<<endl<<"     Enter Your Choice From (1-3)? ";
    cout<<"    :";
    cin>>n;

    switch(n--)
    {

    case 1 :
        system("CLS");
        cout<<endl<<endl<<"   Enter the Semester Of Student : ";
        cin>>sem;
        class_result(sem);
        break;
    case 2 :
    {
        do
        {

            system("CLS");

            cout<<endl<<endl<<"   Enter ID Number Of Student : ";
            cin>>Ino;
            cout<<endl<<endl<<"   Enter the Semester Of Student : ";
            cin>>sem;
            display_Sreport(Ino,sem);
            cout<<endl<<endl<<"   Do you want to See More Result (y/n)?";
            cout<<"     :";
            cin>>ans;
        }
        while(ans=='y'||ans=='Y');
        break;
    }
    case 3:
        break;
    default:
        cout<<"\a";
    }
}

void class_result(string sem)
{
    system("CLS");
    system("PAUSE");
    f=fopen("student_report_card.dat","rb");
    if(f==NULL)
    {
        cout<<endl<<"ERROR!!! FILE COULD NOT BE OPEN"<<endl<<endl<<"Go To Entry Menu to create File";
        cout<<endl<<endl<<endl<<" Program is closing ....";
        system("CLS");
        exit(0);
    }

    cout<<endl<<endl<<"\t\tALL STUDENTS RESULT "<<endl<<endl;
    cout<<"==========================================================================="<<endl;
    cout<<"ID.No    Name            Semester        Total-Marks       %         CGPA    "<<endl;
    cout<<"==========================================================================="<<endl;

    while((fread(&S,sizeof(S),1,f))>0)
    {
        if(S.semester==sem)
        {

            cout<<S.id<<"      "<<S.name<<"          "<<S.semester<<"          "<<S.sum<<"            "<<S.prcntg<<"%"<<"          "<<S.grade<<endl<<endl;

        }
    }
    cout<<endl<<endl<<endl;
    fclose(f);
    system("PAUSE");
    system("CLS");

}


void display_Sreport(int id,string sem)
{

    int flag=0;
    f=fopen("student_report_card.dat","rb");
    while((fread(&S,sizeof(S),1,f))>0)
    {
        if(S.id==id && S.semester==sem)
        {
            cout<<endl<<endl<<"Id Number of the Student : "<<S.id;
            cout<<endl<<endl<<"Name of the student : "<<S.name;
            cout<<endl<<endl<<"Semester of the Student : "<<S.semester;
            cout<<endl<<endl<<"Total attendance of the student  : "<<S.attend<<endl<<endl;


            for (int i = 0; i<S.subnum; i++)
            {
                cout<<endl<<"Marks in  "<<S.subjects[i] <<"   ==   "<<S.marks[i]<<endl;
            }

            cout<<endl<<endl<<"Average marks of the student is  : "<<setprecision(2)<<S.prcntg<<"%";
            cout<<endl<<endl<<"CGPA of student is : "<<S.grade;
            cout<<endl<<endl<<"=========================================="<<endl;
            system("PAUSE");
            system("CLS");

            flag=1;
        }
    }
    fclose(f);
    if(flag==0)
    {
        cout<<endl<<endl<<"record not exist"<<endl;
    }

    system("CLS");

}


int main()
{

    int n;
    system ("color 9"); //for blue color
    intro();
    system ("PAUSE");// wait for keystroke...


    do
    {

        system("CLS");//clear the screen
        cout<<endl<<endl<<endl<<"\tMAIN OPTION ";
        cout<<endl<<endl<<"\t01. ENTRY MENU ";
        cout<<endl<<endl<<"\t02. RESULT MENU ";
        cout<<endl<<endl<<"\t03. EXIT ";
        cout<<endl<<endl<<"\tPlease Select Your Option (1-3) ";

        cin>>n;

        switch(n)
        {
        case 1:
            entry_menu();
            break;
        case 2:
            system("CLS");
            result();
            break;
        case 3:
            exit(0);
        default :
            cout<<"\a";
        }
    }
    while(n!=3);

    return 0;
}
