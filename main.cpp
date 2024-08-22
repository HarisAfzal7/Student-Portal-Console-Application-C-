//Haris Afzal_F2020065010
//Student Portal
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <iomanip>

using namespace std;
class Account{
private:
    int Size;
    char Option,ADMISSIONoption;
    char temUserName[24];
    char UserName[20];
    char Password[30];
    char Email[50];
    bool TrueLogIn=false;
    bool flag;
    fstream Account;
public:
    int SignIn(){
        char userName[20];
        char password[30];
        system("CLS");
        system("color 8e");
        cout<<"\t\t\t\t\tEnter Username: ";cin.getline(userName,19);
        cout<<"\t\t\t\t\tEnter Password: ";
        int i=0;
        char a;
        for (i = 0;;){
            a = _getch();
            if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')){
                password[i] = a;
                ++i;
                cout << "*";
            }
            if (a == '\b' && i >= 1){
                cout << "\b \b";
                --i;
            }
            if (a == '\r'){
                password[i] = '\0';
                break;
            }
        }
        cout<<endl;
        SetPassword(password);
        ifstream file;
        file.open("UserID.txt",fstream::out|fstream::app);
        while(!file.eof()){
            char user_Name[20];
            char passWord[30];
            file>>user_Name;
            file>>passWord;
            if(0==strcmp(user_Name,userName)){
                if(0==strcmp(passWord,password)){
                    SetUserName(userName);
                    flag=true;
                    system("CLS");
                    SetUserName(userName);
                    cout<<"\t\t\t\t\t\1Welcome to the Student Portal:\1"<<endl;
                    SetOption('1');
                    TrueLogIn=true;
                    break;
                }
            }
        }
        if(flag==false){
            system("CLS");
            cout<<"there is no such user please first create an account: \n";
            return -1;
        }
        else{
            char fileTXT[5]=".txt";
            int Count=0;
            for (i=0;(!(UserName[i]==0));i++){
                temUserName[i]=UserName[i];
                Count++;
            }
            for(i=0;i<5;i++){
                temUserName[Count]=fileTXT[i];
                Count++;
            }
            //for(i=Count;i<20;i++){temUserName[i]='\0';}
            return 1;
        }
        file.close();
    }
    int SignUp(){
        char userName[20];
        char password[30];
        char fileTXT[5]=".txt";
        fstream file;
        START:
        cout<<"Enter Username: ";cin.getline(userName,19);
        SetUserName(userName);
        cout<<"\t\t\t\t\tEnter Password: ";
        int i=0;
        char a;
        for (i = 0;;){
            a = _getch();
            if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')){
                password[i] = a;
                ++i;
                cout << "*";
            }
            if (a == '\b' && i >= 1){
                cout << "\b \b";
                --i;
            }
            if (a == '\r'){
                password[i] = '\0';
                break;
            }
        }
        SetPassword(password);
        cout<<"\n\t\t\t\t\tEnter your Email ID: ";cin.getline(Email,49);
        int Count=0;
        for (i=0;(!(UserName[i]==0));i++){
            if(UserName[i]==32){
                system("CLS");
                cout<<"\t\t\tPlease Enter your UserName without Spaces: "<<endl;
                goto START;
                break;
            }
            temUserName[i]=UserName[i];
            Count++;
        }
        for(i=0;i<5;i++){
            temUserName[Count]=fileTXT[i];
            Count++;
        }
        //for(i=Count;i<20;i++){temUserName[i]='\0';}
        file.open(temUserName);
        if (true==file.is_open()){
            system("CLS");
            cout<<"\t\t\tThere is Already user with this username please enter another one: "<<endl;
            cout<<"\t\t\t\t\tPress 1 for Sign in: \n";
            cout<<"\t\t\t\t\tPress 2 for different Sign up: \n";
            char option;
            option=_getch();
            SetOption(option);
            if(option=='1'){return -1;}
            if(option=='2'){goto START;}
        }
        else {
            file.open(temUserName,fstream::out|fstream::app);
            file<<UserName<<endl;
            file<<Email<<endl;
            ofstream filePro;
            filePro.open("UserID.txt",fstream::out|fstream::app);
            filePro<<UserName<<endl;
            filePro<<Password<<endl;
            filePro.close();
            file.close();
            system("CLS");
            cout<<"\t\t\t\tyou have successfully sign up: "<<endl;
            return 1;
        }
        return 0;
    }
    void ForgetPassword(){
        int i=0;
        char Username[20];
        cout<<"\t\t\t\t\tEnter Your UserName: ";cin.getline(Username,19);
        strcpy(UserName,Username);
        //cout<<"username: "<<UserName<<endl;
        int length=strlen(Username);
        for(i=0;i<length;i++){
            temUserName[i]=Username[i];
        }
        temUserName[i]='.';
        temUserName[i+1]='t';
        temUserName[i+2]='x';
        temUserName[i+3]='t';
        temUserName[i+4]='\0';
        //cout<<"user: "<<temUserName<<endl;
        i = 0;
        Account.open(temUserName,fstream::in|fstream::out|fstream::app);
        if (true==Account.is_open()){
            Account.close();
            cout<<"\t\t\t\t\tEnter your New Password: ";
            int i=0;
            char a;
            char password[30];
            char AgainPassword[30];
            for (i = 0;;){
                a = _getch();
                if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')){
                    password[i] = a;
                    ++i;
                    cout << "*";
                }
                if (a == '\b' && i >= 1){
                    cout << "\b \b";
                    --i;
                }
                if (a == '\r'){
                    password[i] = '\0';
                    break;
                }
            }
            cout<<"\n\t\t\t\t\tConfirm Password: ";
                for (i = 0;;){
                a = _getch();
                if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')){
                    AgainPassword[i] = a;
                    ++i;
                    cout << "*";
                }
                if (a == '\b' && i >= 1){
                    cout << "\b \b";
                    --i;
                }
                if (a == '\r'){
                    AgainPassword[i] = '\0';
                    break;
                }
            }
            if (0==strcmp(password,AgainPassword)){
                char TemUserName[27];
                strcpy(TemUserName,temUserName);
                length=strlen(TemUserName);
                TemUserName[length-4]='T';
                TemUserName[length-3]='e';
                TemUserName[length-2]='m';
                TemUserName[length-1]='.';
                TemUserName[length]='t';
                TemUserName[length+1]='x';
                TemUserName[length+2]='t';
                TemUserName[length+3]='\0';
                cout<<"tem:"<<TemUserName<<endl;
                fstream file;
                char usernamE[20],passworD[30];
                Account.open("UserID.txt",fstream::in|fstream::out|fstream::app);
                file.open(TemUserName,fstream::in|fstream::out|fstream::app);
                while(!Account.eof()){
                    Account>>usernamE;
                    Account>>passworD;
                    if (Account.eof()){break;}
                    if (0!=strcmp(usernamE,UserName)){
                        file<<usernamE<<endl;
                        file<<passworD<<endl;
                    }
                    if (0==strcmp(usernamE,UserName)){
                        file<<usernamE<<endl;
                        file<<password<<endl;
                        //cout<<"use:"<<usernamE<<endl;
                    }
                }
                Account.close();
                file.close();
                system("CLS");
                cout<<"\t\t\t\tPassword has been successfully changed: "<<endl;
                remove("UserID.txt");
                rename(TemUserName,"UserID.txt");
            }
            else {system("CLS");cout<<"\t\t\t\tInvalid new and again password: \n";}
        }
        else{system("CLS");cout<<"\t\t\t\t\tInvalid UserName: \n";}
        Account.close();
    }
    void ChangePassword(){
        if (TrueLogIn){
            char password[30],a;
            int i,length;
            cout<<"\t\t\t\t\tEnter your Old Password: ";
            for (i = 0;;){
                a = _getch();
                if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')){
                    password[i] = a;
                    ++i;
                    cout << "*";
                }
                if (a == '\b' && i >= 1){
                    cout << "\b \b";
                    --i;
                }
                if (a == '\r'){
                    password[i] = '\0';
                    break;
                }
            }
            if (0==strcmp(password,GetPassword())){
                cout<<"\n\t\t\t\t\tEnter New Password: ";
                for (i = 0;;){
                    a = _getch();
                    if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')){
                        password[i] = a;
                        ++i;
                        cout << "*";
                    }
                    if (a == '\b' && i >= 1){
                        cout << "\b \b";
                        --i;
                    }
                    if (a == '\r'){
                        password[i] = '\0';
                        break;
                    }
                }
                char AgainPassword[30];
                cout<<"\n\t\t\t\t\tConfirm Password: ";
                    for (i = 0;;){
                    a = _getch();
                    if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')){
                        AgainPassword[i] = a;
                        ++i;
                        cout << "*";
                    }
                    if (a == '\b' && i >= 1){
                        cout << "\b \b";
                        --i;
                    }
                    if (a == '\r'){
                        AgainPassword[i] = '\0';
                        break;
                    }
                }
                if (0==strcmp(password,AgainPassword)){
                    char TemUserName[27];
                    strcpy(TemUserName,temUserName);
                    length=strlen(TemUserName);
                    TemUserName[length-4]='T';
                    TemUserName[length-3]='e';
                    TemUserName[length-2]='m';
                    TemUserName[length-1]='.';
                    TemUserName[length]='t';
                    TemUserName[length+1]='x';
                    TemUserName[length+2]='t';
                    TemUserName[length+3]='\0';
                    cout<<"tem:"<<TemUserName<<endl;
                    fstream file;
                    char usernamE[20],passworD[30];
                    Account.open("UserID.txt",fstream::in|fstream::out|fstream::app);
                    file.open(TemUserName,fstream::in|fstream::out|fstream::app);
                    while(!Account.eof()){
                        Account>>usernamE;
                        Account>>passworD;
                        if (Account.eof()){break;}
                        if (0!=strcmp(usernamE,UserName)){
                            file<<usernamE<<endl;
                            file<<passworD<<endl;
                        }
                        if (0==strcmp(usernamE,UserName)){
                            file<<usernamE<<endl;
                            file<<password<<endl;
                            cout<<"use:"<<usernamE<<endl;
                        }
                    }
                    Account.close();
                    file.close();
                    system("CLS");
                    cout<<"\t\t\t\tPassword has been successfully changed: "<<endl;
                    remove("UserID.txt");
                    rename(TemUserName,"UserID.txt");
                }
                else{system("CLS");cout<<"\t\t\tNew and Confirm Password does not match: "<<endl;}
            }
            else{system("CLS");cout<<"\t\t\t\t\tInvalid password: "<<endl;}
        }
    }
    void DisplayDetail(){
        if(GetTrueLogin()){
            Account.open(GetTemUserName(),fstream::in|fstream::out|fstream::app);
            string Line;
            if(true==Account.is_open()){
                while(!Account.eof()){
                    getline(Account,Line);
                    if(Line=="End"){
                        break;
                    }
                    //if(Account.eof()){break;}
                    cout<<Line<<endl;
                }
                Account.close();
            }
        }
    }
    void MenuOption(){
        char option;
        cout<<"\t\t\t\t\tPress any keyboard Button for the following Task: \n";
        cout<<"\t\t\t\t\t1. For Sign in: \n";
        cout<<"\t\t\t\t\t2. For Sign up: \n";
        cout<<"\t\t\t\t\t3. For Forget Password: \n";
        cout<<"\t\t\t\t\t4. For Exit: \n";
        do{
            cout<<"\t\t\t\t\t";
            option=_getch();
            if (option=='1'){}
            else if(option=='2'){}
            else if(option=='3'){}
            else if(option=='4'){}
            else {cout<<"\n\t\t\t\t\tEnter only 1/2/3/4/5: "<<endl;}
        }while(!(option>='1'&&option<='4'));
        SetOption(option);
        cout<<endl;
    }
    void MenuAfterLogin(){
        system("color 6e");
        cout<<"\n\t\t\t\t\t5.    For Change Password: \n";
        cout<<"\t\t\t\t\t6.    Taking Admission: \n";
        cout<<"\t\t\t\t\t7.    For View your Profile: \n";
        cout<<"\t\t\t\t\t8.    For Attendance: \n";
        cout<<"\t\t\t\t\tA.    For ASSESSMENT: \n";
        cout<<"\t\t\t\t\tT.    For TRANSCRIPT: \n";
        cout<<"\t\t\t\t\tEsc.  Press For Logout: \n";
        char option;
        do{
            cout<<"\t\t\t\t\t";
            option=_getch();
            if(option=='5'){SetAdmissionOption(option);}
            else if(option=='6'){SetAdmissionOption(option);}
            else if(option=='7'){SetAdmissionOption(option);}
            else if(option=='8'){SetAdmissionOption(option);}
            else if(option=='a'){option='A';SetAdmissionOption(option);}
            else if(option=='A'){SetAdmissionOption(option);}
            else if(option=='t'){option='T';SetAdmissionOption(option);}
            else if(option=='T'){SetAdmissionOption(option);}
            else if(option==27){SetAdmissionOption(option);}
            else {cout<<"\n\t\t\t\t\tEnter only 5/6/7/8/A/T/Esc: ";}
        }while(!((option>='5'&&option<='8')||option=='A'||option=='T'||option==27));
        cout<<endl;
    }
    void SetUserName(char * userName){strcpy(UserName,userName);}
    char * GetUserName(){return UserName;}
    void SetPassword(char * password){strcpy(Password,password);}
    char * GetPassword(){return Password;}
    void SetOption(char option){Option=option;}
    char GetOption(){return Option;}
    bool GetFlag(){return flag;}
    char *GetTemUserName(){return temUserName;}
    void SetAdmissionOption(char option){ADMISSIONoption=option;}
    char GetAdmissionOption(){return ADMISSIONoption;}
    bool GetTrueLogin(){return TrueLogIn;}
    ~Account(){}
};











class Admission{
private:
    char FirstName[15], LastName[15];
    char FatherFirstName[15], FatherLastName[15];
    char Address[50];
    char DegreeLevel[5];
    char Program[5];
    int MatricTotalMarks;
    float MatricPercentage;
    int FscTotalMarks;
    float FscPercentage;
    fstream admission;
public:
    Admission(){}
    int TakeStudentInformation(char *tem,bool trueLogin){
    if (trueLogin){
        admission.open(tem,fstream::in|fstream::out|fstream::app);
        int countlines=0;
        while(!admission.eof()){
            string line;
            admission>>line;
            if(line=="@"){
                cout<<"You are not eligible for the admission: "<<endl;
                admission.close();
                return -1;
            }
            if (countlines>5){
                cout<<"You already have applied for admission: "<<endl;
                return 2;
            }
            countlines++;
        }
        admission.close();
        cout<<"Get Register your self for the Admission: "<<endl;
        char Tem[20];
        strcpy(Tem,tem);
        char firstName[15], lastName[15];
        char fatherFirstName[15], fatherLastName[15];
        char address[50];
        char degreeLevel[5];
        char program[5];
        int matricTotalMarks;
        float matricPercentage;
        int fscTotalMarks;
        float fscPercentage;
        Account login;
        admission.open(Tem,fstream::in|fstream::out|fstream::app);
        //if(true==admission.is_open()){cout<<"well: " <<endl;}
            cout<<"Enter Your First Name: ";cin.getline(firstName,14);
            SetFirstName(firstName);
            cout<<"Enter Your Last Name: ";cin.getline(lastName,14);
            SetLastName(lastName);
            cout<<"Enter your Father First Name: ";cin.getline(fatherFirstName,14);
            SetFatherFirstName(fatherFirstName);
            cout<<"Enter you Father Last Name: ";cin.getline(fatherLastName,14);
            SetFatherLastName(fatherLastName);
            cout<<"Enter your Address: ";cin.getline(address,49);
            SetAddress(address);
            cout<<"Enter your Degree Level: ";cin.getline(degreeLevel,4);
            SetDegreeLevel(degreeLevel);
            cout<<"Enter your Program in short form eg. BSSE: ";cin.getline(program,4);
            SetProgram(program);
            cout<<"Enter your Matric Total Marks: ";cin>>matricTotalMarks;
            SetMatricTotalMarks(matricTotalMarks);
            cout<<"Enter your Matric Marks Percentage: ";cin>>matricPercentage;
            SetMatricPercentage(matricPercentage);
            cout<<"Enter your Fsc Total Marks: ";cin>>fscTotalMarks;
            SetFscTotalMarks(fscTotalMarks);
            cout<<"Enter your Fsc Marks Percentage: ";cin>>fscPercentage;
            SetFscPercentage(fscPercentage);

            if(GetMatricPercentage()<60 || GetFscPercentage()<60){
                admission<<"@"<<endl;
                admission<<"@"<<endl<<"@"<<endl;
                admission<<"Your marks is not enough to get admission so that is you are rejected by administration office:"<<endl;
                admission<<"requirement for to get admission is 60% marks in both level matric and fsc: "<<endl;
                admission<<"for more requirement visit out official eligibility policy page: "<<endl;
                admission<<"Click here to get access to eligibility policy :: https://eligiblity.policy.edu.pk.www"<<endl;
                admission<<endl<<endl;
                admission<<"Best of luck for the future: "<<endl;
                admission.close();
                return -2;
            }

            ///////////////////////////////
            fstream IDgenrator;
            IDgenrator.open("StudentID.txt",fstream::in|fstream::out|fstream::app);
            int StudentID;
            while(!IDgenrator.eof()){
                IDgenrator>>StudentID;
            }
            StudentID++;
            IDgenrator<<StudentID<<endl;
            admission<<StudentID<<endl;
            IDgenrator.close();
            admission<<"Name:         "<<GetFirstName()<<" ";
            admission<<GetLastName()<<endl;
            admission<<"Father Name:  "<<GetFatherFirstName()<<" ";
            admission<<GetFatherLastName()<<endl;
            admission<<"Address:      "<<GetAddress()<<endl;
            admission<<"Degree Level: "<<GetDegreeLevel()<<endl;
            admission<<"Program:      "<<GetProgram()<<endl;
            admission<<"Matric Marks: "<<GetMatricTotalMarks()<<endl;
            admission<<"Percentage:   "<<GetMatricPercentage()<<endl;
            admission<<"Fsc Marks:    "<<GetFscTotalMarks()<<endl;
            admission<<"Percentage:   "<<GetFscPercentage()<<endl;
            admission<<"End"<<endl;
            admission.close();
            ///////////////////////////////
            return 1;
        }
        //if(choice==)
        return 0;
    }
    ~Admission(){}
    void SetFirstName(char *firstName){strcpy(FirstName,firstName);}
    void SetLastName(char *lastName){strcpy(LastName,lastName);}
    void SetFatherFirstName(char *fatherFirstName){strcpy(FatherFirstName,fatherFirstName);}
    void SetFatherLastName(char *fatherLastName){strcpy(FatherLastName,fatherLastName);}
    void SetAddress(char *address){strcpy(Address,address);}
    void SetDegreeLevel(char *degreeLevel){strcpy(DegreeLevel,degreeLevel);}
    void SetProgram(char *program){strcpy(Program,program);}
    void SetMatricTotalMarks(int matricTotalMarks){MatricTotalMarks=matricTotalMarks;}
    void SetMatricPercentage(float percentage){MatricPercentage=percentage;}
    void SetFscTotalMarks(int fscTotalMarks){FscTotalMarks=fscTotalMarks;}
    void SetFscPercentage(float fscPercentage){FscPercentage=fscPercentage;}


    char *GetFirstName(){return FirstName;}
    char *GetLastName(){return LastName;}
    char *GetFatherFirstName(){return FatherFirstName;}
    char *GetFatherLastName(){return FatherLastName;}
    char *GetAddress(){return Address;}
    char *GetDegreeLevel(){return DegreeLevel;}
    char *GetProgram(){return Program;}
    int GetMatricTotalMarks(){return MatricTotalMarks;}
    float GetMatricPercentage(){return MatricPercentage;}
    int GetFscTotalMarks(){return FscTotalMarks;}
    float GetFscPercentage(){return FscPercentage;}
};











class Attendance{
    int TotalPresent,TotalAbsent,TotalAttendance;
    float PercentageOfPresent,PercentageOfAbsent;
    fstream attendance;
public:
    Attendance(){}
    void DisplayAttendance(char *tem,bool trueLogin){
        if(trueLogin){
            char choice;
            do{
                system("CLS");
                system("color 9e");
                cout<<"\n1. English Attendance: "<<endl;
                cout<<"2. Object Oriented Program Attendance: "<<endl;
                cout<<"3. Calculus Attendance: "<<endl;
                cout<<"4. Microeconomics Attendance: "<<endl;
                cout<<"5. Object Oriented Program Lab Attendance: "<<endl;
                cout<<"6. Simulation and Modeling Attendance: "<<endl;
                cout<<"7. Break: "<<endl;
                do{
                    choice = _getch();
                    if(choice<'1'&&choice>'7'){cout<<"you can only press 1/2/3/4/5/6 : \nPress Again: "<<endl;}
                }while(!(choice>='1' && choice<='7'));
                if(choice=='1'){
                    attendance.open(tem,fstream::in|fstream::app);
                    TotalPresent=0;
                    TotalAbsent=0;
                    TotalAttendance=0;
                    string subject;
                    while(!attendance.eof()){
                        attendance>>subject;
                        if(subject=="English"){
                            //cout<<"Subject: English"<<"Teacher: ";
                            //int i = 1;
                            do{
                                attendance>>subject;
                                if(subject=="P"){
                                    cout<<"Attendance:   "<<subject<<endl;
                                    AddPresent();
                                    AddTotalAttendance();
                                }
                                if(subject=="A"){
                                    cout<<"Attendance:   "<<subject<<endl;
                                    AddAbsent();
                                    AddTotalAttendance();
                                }
                            }while(subject=="P"||subject=="A");
                            break;
                        }
                    }
                    float Percent;
                    Percent=TotalPresent*100;
                    Percent=Percent/TotalAttendance;
                    SetPercentageOfPresent(Percent);
                    Percent=TotalAbsent*100;
                    Percent=Percent/TotalAttendance;
                    SetPercentageOfAbsent(Percent);
                    cout<<"Your Presence Percentage is: "<<GetPercentageOfPresent()<<"%"<<endl;
                    cout<<"Your Absences Percentage is: "<<GetPercentageOfAbsent()<<"%"<<endl;
                    attendance.close();
                    system("pause");
                }
                if(choice=='2'){
                    attendance.open(tem,fstream::in|fstream::out|fstream::app);
                    TotalPresent=0;
                    TotalAbsent=0;
                    TotalAttendance=0;
                    string subject;
                    while(!attendance.eof()){
                        attendance>>subject;
                        if(subject=="OOP"){
                            //cout<<"Subject: English"<<"Teacher: ";
                            //int i = 1;
                            do{
                                attendance>>subject;
                                if(subject=="P"){
                                    cout<<"Attendance:   "<<subject<<endl;
                                    AddPresent();
                                    AddTotalAttendance();
                                }
                                if(subject=="A"){
                                    cout<<"Attendance:   "<<subject<<endl;
                                    AddAbsent();
                                    AddTotalAttendance();
                                }
                            }while(subject=="P"||subject=="A");
                            break;
                        }
                    }
                    float Percent;
                    Percent=TotalPresent*100;
                    Percent=Percent/TotalAttendance;
                    SetPercentageOfPresent(Percent);
                    Percent=TotalAbsent*100;
                    Percent=Percent/TotalAttendance;
                    SetPercentageOfAbsent(Percent);
                    cout<<"Your Presence Percentage is: "<<GetPercentageOfPresent()<<"%"<<endl;
                    cout<<"Your Absences Percentage is: "<<GetPercentageOfAbsent()<<"%"<<endl;
                    attendance.close();
                    system("pause");
                }
                if(choice=='3'){
                    attendance.open(tem,fstream::in|fstream::out|fstream::app);
                    TotalPresent=0;
                    TotalAbsent=0;
                    TotalAttendance=0;
                    string subject;
                    while(!attendance.eof()){
                        attendance>>subject;
                        if(subject=="Calculus"){
                            //cout<<"Subject: English"<<"Teacher: ";
                            //int i = 1;
                            do{
                                attendance>>subject;
                                if(subject=="P"){
                                    cout<<"Attendance:   "<<subject<<endl;
                                    AddPresent();
                                    AddTotalAttendance();
                                }
                                if(subject=="A"){
                                    cout<<"Attendance:   "<<subject<<endl;
                                    AddAbsent();
                                    AddTotalAttendance();
                                }
                            }while(subject=="P"||subject=="A");
                            break;
                        }
                    }
                    float Percent;
                    Percent=TotalPresent*100;
                    Percent=Percent/TotalAttendance;
                    SetPercentageOfPresent(Percent);
                    Percent=TotalAbsent*100;
                    Percent=Percent/TotalAttendance;
                    SetPercentageOfAbsent(Percent);
                    cout<<"Your Presence Percentage is: "<<GetPercentageOfPresent()<<"%"<<endl;
                    cout<<"Your Absences Percentage is: "<<GetPercentageOfAbsent()<<"%"<<endl;
                    attendance.close();
                    system("pause");
                }
                if(choice=='4'){
                    attendance.open(tem,fstream::in|fstream::out|fstream::app);
                    TotalPresent=0;
                    TotalAbsent=0;
                    TotalAttendance=0;
                    string subject;
                    while(!attendance.eof()){
                        attendance>>subject;
                        if(subject=="Microeconomics"){
                            //cout<<"Subject: English"<<"Teacher: ";
                            //int i = 1;
                            do{
                                attendance>>subject;
                                if(subject=="P"){
                                    cout<<"Attendance:   "<<subject<<endl;
                                    AddPresent();
                                    AddTotalAttendance();
                                }
                                if(subject=="A"){
                                    cout<<"Attendance:   "<<subject<<endl;
                                    AddAbsent();
                                    AddTotalAttendance();
                                }
                            }while(subject=="P"||subject=="A");
                            break;
                        }
                    }
                    float Percent;
                    Percent=TotalPresent*100;
                    Percent=Percent/TotalAttendance;
                    SetPercentageOfPresent(Percent);
                    Percent=TotalAbsent*100;
                    Percent=Percent/TotalAttendance;
                    SetPercentageOfAbsent(Percent);
                    cout<<"Your Presence Percentage is: "<<GetPercentageOfPresent()<<"%"<<endl;
                    cout<<"Your Absences Percentage is: "<<GetPercentageOfAbsent()<<"%"<<endl;
                    attendance.close();
                    system("pause");
                }
                if(choice=='5'){
                    attendance.open(tem,fstream::in|fstream::out|fstream::app);
                    TotalPresent=0;
                    TotalAbsent=0;
                    TotalAttendance=0;
                    string subject;
                    while(!attendance.eof()){
                        attendance>>subject;
                        if(subject=="OOPLab"){
                            //cout<<"Subject: English"<<"Teacher: ";
                            //int i = 1;
                            do{
                                attendance>>subject;
                                if(subject=="P"){
                                    cout<<"Attendance:   "<<subject<<endl;
                                    AddPresent();
                                    AddTotalAttendance();
                                }
                                if(subject=="A"){
                                    cout<<"Attendance:   "<<subject<<endl;
                                    AddAbsent();
                                    AddTotalAttendance();
                                }
                            }while(subject=="P"||subject=="A");
                            break;
                        }
                    }
                    float Percent;
                    Percent=TotalPresent*100;
                    Percent=Percent/TotalAttendance;
                    SetPercentageOfPresent(Percent);
                    Percent=TotalAbsent*100;
                    Percent=Percent/TotalAttendance;
                    SetPercentageOfAbsent(Percent);
                    cout<<"Your Presence Percentage is: "<<GetPercentageOfPresent()<<"%"<<endl;
                    cout<<"Your Absences Percentage is: "<<GetPercentageOfAbsent()<<"%"<<endl;
                    attendance.close();
                    system("pause");
                }
                if(choice=='6'){
                    attendance.open(tem,fstream::in|fstream::out|fstream::app);
                    TotalPresent=0;
                    TotalAbsent=0;
                    TotalAttendance=0;
                    string subject;
                    while(!attendance.eof()){
                        attendance>>subject;
                        if(subject=="SandM"){
                            //cout<<"Subject: English"<<"Teacher: ";
                            //int i = 1;
                            do{
                                attendance>>subject;
                                if(subject=="P"){
                                    cout<<"Attendance:   "<<subject<<endl;
                                    AddPresent();
                                    AddTotalAttendance();
                                }
                                if(subject=="A"){
                                    cout<<"Attendance:   "<<subject<<endl;
                                    AddAbsent();
                                    AddTotalAttendance();
                                }
                            }while(subject=="P"||subject=="A");
                            break;
                        }
                    }
                    float Percent;
                    Percent=TotalPresent*100;
                    Percent=Percent/TotalAttendance;
                    SetPercentageOfPresent(Percent);
                    Percent=TotalAbsent*100;
                    Percent=Percent/TotalAttendance;
                    SetPercentageOfAbsent(Percent);
                    cout<<"Your Presence Percentage is: "<<GetPercentageOfPresent()<<"%"<<endl;
                    cout<<"Your Absences Percentage is: "<<GetPercentageOfAbsent()<<"%"<<endl;
                    attendance.close();
                    system("pause");
                }
                if(choice=='7'){break;}
            }while(!(choice=='7'));
        }
    }
    ~Attendance(){}
private:
    void AddPresent(){TotalPresent=GetPresent()+1;}
    int GetPresent(){return TotalPresent;}
    void AddAbsent(){TotalAbsent=GetAbsent()+1;}
    int GetAbsent(){return TotalAbsent;}
    void AddTotalAttendance(){TotalAttendance=GetTotalAttendance()+1;}
    int GetTotalAttendance(){return TotalAttendance;}
    void SetPercentageOfPresent(float percentage){
        PercentageOfPresent=percentage;
    }
    void SetPercentageOfAbsent(float percentage){
        PercentageOfAbsent=percentage;
    }
    float GetPercentageOfPresent(){return PercentageOfPresent;}
    float GetPercentageOfAbsent(){return PercentageOfAbsent;}
};











class Assessment{
    char SubjectName[50];
    char AssignmentName[30];
    int TotalMarks;
    int ObtainedMarks;
    float Percentage;
    fstream assessment;
public:
    Assessment(){}
    void ShowAssessment(char *tem,bool trueLogin){
        if(trueLogin){
            char choice;
            do{
                system("CLS");
                system("color 8f");
                cout<<"\n1. English Attendance: "<<endl;
                cout<<"2. Object Oriented Program Attendance: "<<endl;
                cout<<"3. Calculus Attendance: "<<endl;
                cout<<"4. Microeconomics Attendance: "<<endl;
                cout<<"5. Object Oriented Program Lab Attendance: "<<endl;
                cout<<"6. Simulation and Modeling Attendance: "<<endl;
                cout<<"7. Break: "<<endl;
                do{
                    choice = _getch();
                    if(choice<'1'&&choice>'7'){cout<<"you can only press 1/2/3/4/5/6 : \nPress Again: "<<endl;}
                }while(!(choice>='1' && choice<='7'));
                if(choice=='1'){
                    string assignment;
                    assessment.open(tem,fstream::in|fstream::out|fstream::app);
                    while(!assessment.eof()){
                        assessment>>assignment;
                        if(assignment=="English&"){
                            cout<<left;
                            cout<<setw(25)<<"Name: "<<setw(15)<<"Total Marks: "<<setw(15)<<"Obtained Marks: "<<endl;
                            do{
                                assessment>>AssignmentName;
                                assessment>>TotalMarks;
                                assessment>>ObtainedMarks;
                                if(!(0==strcmp(AssignmentName,"EndOfEnglish"))){
                                    cout<<setw(25)<<AssignmentName;
                                    cout<<setw(15)<<TotalMarks;
                                    cout<<setw(15)<<ObtainedMarks<<endl;
                                }
                            }while(!(0==strcmp(AssignmentName,"EndOfEnglish")));
                            assessment.close();
                            break;
                        }
                    }
                    system("pause");
                }
                if(choice=='2'){
                    string assignment;
                    assessment.open(tem,fstream::in|fstream::out|fstream::app);
                    while(!assessment.eof()){
                        assessment>>assignment;
                        if(assignment=="OOP&"){
                            cout<<left;
                            cout<<setw(25)<<"Name: "<<setw(15)<<"Total Marks: "<<setw(15)<<"Obtained Marks: "<<endl;
                            do{
                                assessment>>AssignmentName;
                                assessment>>TotalMarks;
                                assessment>>ObtainedMarks;
                                if(!(0==strcmp(AssignmentName,"EndOfOOP"))){
                                    cout<<setw(25)<<AssignmentName;
                                    cout<<setw(15)<<TotalMarks;
                                    cout<<setw(15)<<ObtainedMarks<<endl;
                                }
                            }while(!(0==strcmp(AssignmentName,"EndOfOOP")));
                            assessment.close();
                            break;
                        }
                    }
                    system("pause");
                }
                if(choice=='3'){
                    string assignment;
                    assessment.open(tem,fstream::in|fstream::out|fstream::app);
                    while(!assessment.eof()){
                        assessment>>assignment;
                        if(assignment=="Calculus&"){
                            cout<<left;
                            cout<<setw(25)<<"Name: "<<setw(15)<<"Total Marks: "<<setw(15)<<"Obtained Marks: "<<endl;
                            do{
                                assessment>>AssignmentName;
                                assessment>>TotalMarks;
                                assessment>>ObtainedMarks;
                                if(!(0==strcmp(AssignmentName,"EndOfCalculus"))){
                                    cout<<setw(25)<<AssignmentName;
                                    cout<<setw(15)<<TotalMarks;
                                    cout<<setw(15)<<ObtainedMarks<<endl;
                                }
                            }while(!(0==strcmp(AssignmentName,"EndOfCalculus")));
                            assessment.close();
                            break;
                        }
                    }
                    system("pause");
                }
                if(choice=='4'){
                    string assignment;
                    assessment.open(tem,fstream::in|fstream::out|fstream::app);
                    while(!assessment.eof()){
                        assessment>>assignment;
                        if(assignment=="Microeconomics&"){
                            cout<<left;
                            cout<<setw(25)<<"Name: "<<setw(15)<<"Total Marks: "<<setw(15)<<"Obtained Marks: "<<endl;
                            do{
                                assessment>>AssignmentName;
                                assessment>>TotalMarks;
                                assessment>>ObtainedMarks;
                                if(!(0==strcmp(AssignmentName,"EndOfMicroeconomics"))){
                                    cout<<setw(25)<<AssignmentName;
                                    cout<<setw(15)<<TotalMarks;
                                    cout<<setw(15)<<ObtainedMarks<<endl;
                                }
                            }while(!(0==strcmp(AssignmentName,"EndOfMicroeconomics")));
                            assessment.close();
                            break;
                        }
                    }
                    system("pause");
                }
                if(choice=='5'){
                    string assignment;
                    assessment.open(tem,fstream::in|fstream::out|fstream::app);
                    while(!assessment.eof()){
                        assessment>>assignment;
                        if(assignment=="OOPLab&"){
                            cout<<left;
                            cout<<setw(25)<<"Name: "<<setw(15)<<"Total Marks: "<<setw(15)<<"Obtained Marks: "<<endl;
                            do{
                                assessment>>AssignmentName;
                                assessment>>TotalMarks;
                                assessment>>ObtainedMarks;
                                if(!(0==strcmp(AssignmentName,"EndOfOOPLab"))){
                                    cout<<setw(25)<<AssignmentName;
                                    cout<<setw(15)<<TotalMarks;
                                    cout<<setw(15)<<ObtainedMarks<<endl;
                                }
                            }while(!(0==strcmp(AssignmentName,"EndOfOOPLab")));
                            assessment.close();
                            break;
                        }
                    }
                    system("pause");
                }
                if(choice=='6'){
                    string assignment;
                    assessment.open(tem,fstream::in|fstream::out|fstream::app);
                    while(!assessment.eof()){
                        assessment>>assignment;
                        if(assignment=="SandM&"){
                            cout<<left;
                            cout<<setw(25)<<"Name: "<<setw(15)<<"Total Marks: "<<setw(15)<<"Obtained Marks: "<<endl;
                            do{
                                assessment>>AssignmentName;
                                assessment>>TotalMarks;
                                assessment>>ObtainedMarks;
                                if(!(0==strcmp(AssignmentName,"EndOfSandM"))){
                                    cout<<setw(25)<<AssignmentName;
                                    cout<<setw(15)<<TotalMarks;
                                    cout<<setw(15)<<ObtainedMarks<<endl;
                                }
                            }while(!(0==strcmp(AssignmentName,"EndOfSandM")));
                            assessment.close();
                            break;
                        }
                    }
                    system("pause");
                }
            }while(!(choice=='7'));
        }
    }
    ~Assessment(){}

};











class Transcript{
    char Grade[2];
    float CreditHour,SGPA,TotalCreditHour,TotalPoints;
    char NameOfTheSubject[30];
    char GradeCharacter[30];
    fstream transcript;
public:
    Transcript(){}
    void CalculateGrade(char *tem,bool trueLogin){
        if(trueLogin){
            transcript.open(tem,fstream::in|fstream::app);
            while(!transcript.eof()){
                transcript>>GradeCharacter;
                if(0==strcmp(GradeCharacter,"Grades")){
                    TotalCreditHour=0;
                    TotalPoints=0;
                    system("CLS");
                    system("color 4e");
                    cout<<"\nYour Transcript is: "<<endl;
                    cout<<left;
                    cout<<setw(25)<<"Subject: ";
                    cout<<setw(15)<<"Credit Hour";
                    cout<<setw(20)<<"Grade Obtained: "<<endl;
                    do{
                        transcript>>NameOfTheSubject;
                        transcript>>Grade;
                        transcript>>CreditHour;
                        if(transcript.eof()){break;}
                        cout<<setw(25)<<NameOfTheSubject;
                        cout<<setw(15)<<CreditHour;
                        cout<<setw(5)<<Grade<<endl;
                        if(0==strcmp(Grade,"A+")){
                            TotalCreditHour=TotalCreditHour+CreditHour;
                            CreditHour=CreditHour*4;
                            TotalPoints=TotalPoints+CreditHour;
                        }
                        if(0==strcmp(Grade,"A-")){
                            TotalCreditHour=TotalCreditHour+CreditHour;
                            CreditHour=CreditHour*3.7;
                            TotalPoints=TotalPoints+CreditHour;
                        }
                        if(0==strcmp(Grade,"B+")){
                            TotalCreditHour=TotalCreditHour+CreditHour;
                            CreditHour=CreditHour*3.3;
                            TotalPoints=TotalPoints+CreditHour;
                        }
                        if(0==strcmp(Grade,"B")){
                            TotalCreditHour=TotalCreditHour+CreditHour;
                            CreditHour=CreditHour*3.0;
                            TotalPoints=TotalPoints+CreditHour;
                        }
                        if(0==strcmp(Grade,"B-")){
                            TotalCreditHour=TotalCreditHour+CreditHour;
                            CreditHour=CreditHour*2.7;
                            TotalPoints=TotalPoints+CreditHour;
                        }
                        if(0==strcmp(Grade,"C+")){
                            TotalCreditHour=TotalCreditHour+CreditHour;
                            CreditHour=CreditHour*2.3;
                            TotalPoints=TotalPoints+CreditHour;
                        }
                        if(0==strcmp(Grade,"C")){
                            TotalCreditHour=TotalCreditHour+CreditHour;
                            CreditHour=CreditHour*2.0;
                            TotalPoints=TotalPoints+CreditHour;
                        }
                        if(0==strcmp(Grade,"C-")){
                            TotalCreditHour=TotalCreditHour+CreditHour;
                            CreditHour=CreditHour*1.7;
                            TotalPoints=TotalPoints+CreditHour;
                        }
                        if(0==strcmp(Grade,"D+")){
                            TotalCreditHour=TotalCreditHour+CreditHour;
                            CreditHour=CreditHour*1.3;
                            TotalPoints=TotalPoints+CreditHour;
                        }
                        if(0==strcmp(Grade,"D")){
                            TotalCreditHour=TotalCreditHour+CreditHour;
                            CreditHour=CreditHour*1.0;
                            TotalPoints=TotalPoints+CreditHour;
                        }
                        if(0==strcmp(Grade,"F")){
                            TotalCreditHour=TotalCreditHour+CreditHour;
                            CreditHour=CreditHour*0.0;
                            TotalPoints=TotalPoints+CreditHour;
                        }
                    }while(!(transcript.eof()));
                    cout<<"\n\nTotal Credit in a semester:             "<<TotalCreditHour<<endl;
                    cout<<"Total Grade Point in a semester:        "<<TotalPoints<<endl;
                    cout<<"Semester Grade Point Average(SGPA):     "<<(TotalPoints/TotalCreditHour)<<endl<<endl<<endl;
                    break;
                }
            }
        }
    }
    ~Transcript(){}
};











int main()
{
    system("color 5e");
    cout<<"\t\t\t\t\t================================="<<endl;
    cout<<"\t\t\t\t\t \1Welcome to the Student Portal\1"<<endl;
    cout<<"\t\t\t\t\t================================="<<endl;
    Account account;
    Admission admission;
    Attendance attendance;
    Assessment assessment;
    Transcript transcript;
    account.MenuOption();
    do{
        if (account.GetOption()=='1'){
            int SignInReturn;
            SignInReturn=account.SignIn();
            if(SignInReturn==-1){cout<<"Please Register User self First: \n";account.MenuOption();}
            if(account.GetFlag()){account.SetOption('0');account.MenuAfterLogin();}
        }
        if(account.GetOption()=='2'){
            int SignUpReturn;
            SignUpReturn=account.SignUp();
            if(SignUpReturn==-1){
                cout<<"Please Sign in: \n";
                account.SignIn();
            }
            if(SignUpReturn==1){cout<<"\t\t\t\tNow you can Login your ID:\n";account.MenuOption();}
        }
        if(account.GetOption()=='3'){
            account.ForgetPassword();
            account.MenuOption();
        }
        if(account.GetAdmissionOption()=='5'){
            account.ChangePassword();
            account.MenuAfterLogin();
        }
        if (account.GetAdmissionOption()=='6'){
            admission.TakeStudentInformation(account.GetTemUserName(),account.GetTrueLogin());
        }
        if(account.GetAdmissionOption()=='7'){
            account.DisplayDetail();
            system("pause");
            system("CLS");
            account.MenuAfterLogin();
        }
        if(account.GetAdmissionOption()=='8'){
            attendance.DisplayAttendance(account.GetTemUserName(),account.GetTrueLogin());
            system("pause");
            system("CLS");
            account.MenuAfterLogin();
        }
        if(account.GetAdmissionOption()=='A'){
            assessment.ShowAssessment(account.GetTemUserName(),account.GetTrueLogin());
            system("pause");
            system("CLS");
            account.MenuAfterLogin();
        }
        if(account.GetAdmissionOption()=='T'){
            transcript.CalculateGrade(account.GetTemUserName(),account.GetTrueLogin());
            system("pause");
            system("CLS");
            account.MenuAfterLogin();
        }
        if(account.GetAdmissionOption()==27){cout<<"\n\t\t\t\t\t\t\1 Thank You! \1\n\n";break;}
        /*if (strlen(account.GetUserName())!=0){
            account.MenuAfterLogin();
        }*/
    }while(!(account.GetOption()=='4') || account.GetAdmissionOption()==27);
    return 0;
}
