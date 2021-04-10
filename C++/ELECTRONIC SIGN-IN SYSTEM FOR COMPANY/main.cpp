#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;


v <vector <string> > supervisorsList={{"John Doe","JD"},{"Albert Einstein","AE"}};//HOLDS SUPERVISORS TABLE
vector<vector <string> > employeesList={{"Nelson Mandela","1"},{"Martin Luther King","2"}}; //HOLDS EMPLOYEES TABLE
int signingTabSize=2;
vector<vector <string> > signingTable(signingTabSize,vector<string>(8,"empty"));

int SignInStatSize=2;
vector<vector<int> > SignInStatus(2,vector<int>(2,0));   // determines wether employee already signed-in or not

int BreakOutStatSize=2;
vector<vector<int> > BreakOutStatus(2,vector<int>(2,0)); // determines wether employee already broke-out or not

int BreakInStatSize=2;
vector<vector<int> > BreakInStatus(2,vector<int>(2,0));  // determines wether employee already broke-in or not

void MainMenu();
//defines a class that holds all company information(only the owner of the company has access to this database)
class OWNER{
    string PASSWORD="HCC2019";
   
public:
    //OWNER MENU is displayed if user's choice is O or o (OWNER)
    void ownerMenu(){
        int ownerChoice=00000;
  string password="";
        do  {
            cout<<"OWNER INTERFACE:\n---------------\n\nPlease enter your PASSWORD(the password is HCC2019): ";
            cin>>password;
            if(password != PASSWORD) cout<<"\nIncorrect Password!\n";
        } while(password != PASSWORD);
        
        
        do {cout<<"OWNER MENU:\n----------\n\nWhich task would you like to perform?(type your selection and press Enter)\n\n\t(1): Add a supervisor\n\t(2): Add an employee\n\t(3): Print Supervisors Table\n\t(4): Print Employees Table\n\t(5): Exit\n\nYour choice: ";
            cin>>ownerChoice;
            if(ownerChoice!=1 && ownerChoice!=2 && ownerChoice!=3 && ownerChoice!=4 && ownerChoice!=5)
                cout<<"\nInvalid Choice\n";
        } while(ownerChoice!=1 && ownerChoice!=2 && ownerChoice!=3 && ownerChoice!=4 && ownerChoice!=5);
        
            if (ownerChoice == 1){
                system("CLS");
                string supName="";
                string supPass="";
                vector<string> temp(2,"");
                cout<<"\nEnter new supervisor's name and press Enter: ";
                cin.ignore();
                getline(cin,supName);
                cout<<"\nEnter new supervisor's password and press Enter: ";
                getline(cin,supPass);
                temp[0]=supName;
                temp[1]=supPass;
                supervisorsList.push_back(temp);
                cout<<endl;
                ownerMenu();
                }
           else if (ownerChoice == 2)
            {system("CLS");
               this->addEmployee();
               this->ownerMenu();
            }
        
           else if (ownerChoice == 3)
            {system("CLS");
                this->printSup();
                this->ownerMenu();
            }
        
           else if (ownerChoice == 4)
           {system("CLS");
               this->printEmp();
               this->ownerMenu();
           }
        
            else if (ownerChoice == 5)
            {system("CLS");
                MainMenu();
            }
        
    }
    
//defines a funtion that prints supervisors' table
    void printSup(){
        cout<<" ------------------------------------------------\n";
        cout<<"|               SUPERVISORS TABLE                |\n";
        cout<<" ------------------------------------------------\n";
        cout<<"|         NAME          ||        PASSWORD       |\n";
        cout<<" ------------------------------------------------";
        for(int i=0; i< supervisorsList.size();i++){
            cout<<endl;
            for(int j=0; j<2; j++)
                cout<<"|"<<setw(22)<<supervisorsList[i][j]<<" |";
            cout<<"\n ------------------------------------------------";
            };
        cout<<endl;
    }
    
public:
    
//defines function to add employee information
    void addEmployee(){
        string empName="",empID="";
        vector<string> temp(2,"");
        cout<<"\nEnter new employee's name and press Enter: ";
        cin.ignore();
        getline(cin, empName);
        cout<<"\nEnter new employee's ID and press Enter: ";
        getline(cin,empID);
        temp[0]=empName;
        temp[1]=empID;
        employeesList.push_back(temp);
        signingTabSize++;
        signingTable.resize(signingTabSize,vector<string>(8,"empty"));
        SignInStatSize++;
        SignInStatus.resize(SignInStatSize,vector<int>(2,0));
        BreakOutStatSize++;
        BreakOutStatus.resize(BreakOutStatSize,vector<int>(2,0));
        BreakInStatSize++;
        BreakInStatus.resize(BreakInStatSize,vector<int>(2,0));
        
        cout<<endl;
    }

//defines function to print employees' table
    void printEmp(){
        cout<<" ------------------------------------------------\n";
        cout<<"|                 EMPLOYEES TABLE                |\n";
        cout<<" ------------------------------------------------\n";
        cout<<"|         NAME          ||          ID           |\n";
        cout<<" ------------------------------------------------";
        for(int i=0; i< employeesList.size();i++){
            cout<<endl;
            for(int j=0; j<2; j++)
                cout<<"|"<<setw(22)<<employeesList[i][j]<<" |";
            cout<<"\n ------------------------------------------------";
        };
        cout<<endl;
    }
};
//defines a class that holds tasks that can be performed by supervisor
class Supervisor : public OWNER{
    string supName="",supPass="";
    
   
public:
    void supMenu(){
        int supChoice=0000;
        bool notMember=true;
        bool wrongPass=true;
        int num2=0000;
        do   {

            cout<<"SUPERVISOR INTERFACE:\n--------------------\n\nPlease, enter your name(use:Albert Einstein) :";
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');}
        getline(cin,supName);
            for(int i =0; i<supervisorsList.size(); i++){
                if (supName == supervisorsList[i][0])
                { notMember=false;
                    num2=i;
                }
            };
            if (notMember)
                cout<<"Sorry, the name entered doesn't exist in our database\n\n";
        } while (notMember);
        
        do   {
            cout<<"Please, enter your password(use: AE):";
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');}
            getline(cin,supPass);
                if (supPass == supervisorsList[num2][1])
                    wrongPass=false;
            if(wrongPass) cout<<"\nIncorrect Password!\n";
        } while (wrongPass);
        
        do{       cout<<"\nSUPERVISOR MENU:\n---------------\n\nWhich task would you like to perform?(type your selection and press Enter)\n\n\t(1): Add an employee\n\t(2): Print Employees Table\n\t(3): Edit Signing Table\n\t(4): Print Signing Table\n\t(5): Exit\n\nYour choice: ";
            cin>>supChoice;
            if(supChoice!=1 && supChoice!=2 && supChoice!=3 && supChoice!=4 && supChoice!=5)
                cout<<"\nInvalid Choice\n";         }
        while(supChoice!=1 && supChoice!=2 && supChoice!=3 && supChoice!=4 && supChoice!=5);
        cout<<endl;
        
        if(supChoice==1){
            addEmployee();
            char c;
            cout<<"Employee information successfuly saved!\n Would you like to go to the previous menu?\n\tY/y: Yes\n\tN/n: Go to Main Menu\nYour Choice: ";
            cin.ignore();cin.clear();
            cin>>c;
            while(c!='Y' && c!='y' && c!='N' && c!='n')
            {cout<<"Invalid Choice!\n";
                cout<<"  \n Would you like to go to the previous menu?\n\tY/y: Yes\n\tN/n: Go to Main Menu\nYour Choice: ";
                cin.ignore();cin.clear();
                cin>>c;cin.ignore();cin.clear();
            }
            if (c=='Y' || c== 'y')
                {cin.clear();cin.ignore();
                this->supMenu();}
            else if (c=='N' || c=='n')
            {cin.clear();cin.ignore();
                MainMenu();}
                }
        
        else if(supChoice==2){
            printEmp();
            char c;
            cout<<"\n Would you like to go to the previous menu?\n\tY/y: Yes\n\tN/n: Go to Main Menu\nYour Choice: ";
            cin.ignore();cin.clear();
            cin>>c;cin.ignore();cin.clear();
            while(c!='Y' && c!='y' && c!='N' && c!='n')
            {cout<<"Invalid Choice!\n";
                cout<<"  \n Would you like to go to the previous menu?\n\tY/y: Yes\n\tN/n: Go to Main Menu\nYour Choice: ";
                cin.ignore();cin.clear();
                cin>>c;cin.ignore();cin.clear();
            }
            if (c=='Y' || c== 'y')
                this->supMenu();
            else if (c=='N' || c=='n')
                MainMenu();
            
        }
        
         else if(supChoice==3){ //DEAR PROFESSOR,THIS OPTION HAS BEEN LEFT OUT BECAUSE OF LACK OF TIME.I WILL COMPLETE IT AND SUBMIT IT TO YOU LATER. THANK YOU
             cout<<"\nDEAR PROFESSOR,THIS OPTION HAS BEEN LEFT OUT BECAUSE OF LACK OF TIME. I WILL COMPLETE IT AND SUBMIT IT TO YOU LATER. THANK YOU\n";
             cin.ignore();cin.clear();
             this->supMenu();
         }
        else if(supChoice==4){
            printSignTable();
            cout<<endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            this->supMenu();
        }
        
        else if(supChoice==5)
            MainMenu();
    }
    
    void printSignTable(){
        cout<<" ----------------------------------------------------------------------------------------------------\n|\t\t\t\t\t\t\t\t\t\t\tSIGNING TABLE\t\t\t\t\t\t\t\t\t\t\t |\n ----------------------------------------------------------------------------------------------------\n";
        cout<<left<<setw(22
                         )<<"|  Name"<<"||"<<left<<setw(5)<<"ID"<<"||"<<left<<setw(12)<<"Date"<<"||"<<left<<setw(10)<<"Sign-In"<<"||"<<left<<setw(10)<<"Break-Out"<<"||"<<left<<setw(10)<<"Break-In"<<"||"<<left<<setw(10)<<"Sign-Out"<<"||"<<left<<setw(8)<<"Lock"<<"|\n";
        cout<<" ----------------------------------------------------------------------------------------------------\n";
        for(int i=0; i<signingTable.size();i++){
            cout<<"| ";
            int a=20;
            for(int j=0; j<8;j++){
                cout<<left<<setw(a)<<signingTable[i][j];
                if(j==0)
                    a=5;
                else if(j==1)
                    a=12;
                else if( j==2 || j== 3 || j==4 || j==5 )
                    a=10;
                else if(j==6)
                    a=8;
                
                if(j==0 ||j==1 ||j==2 || j== 3 || j==4 || j==5 || j==6)
                    cout<<"||";
                else if(j==7)
                    cout<<"|";
            }
            cout<<endl;
            cout<<" ----------------------------------------------------------------------------------------------------\n";
        }
    }
};

//defines a class that holds employee information
class Employee : public Supervisor{
    string empName="", empID="";
public:
    void empMenu(){
        int empChoice=0000;
        bool notMember=true;
        bool wrongID=true;
        int num=0000;

        do   {
            
             num=0000;
            cout<<"EMPLOYEE INTERFACE:\n------------------\n\nPlease, enter your name(use: Nelson Mandela):";
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');}
            getline(cin,empName);
            for(int i =0; i<employeesList.size(); i++){
                if (empName == employeesList[i][0]){
                     num=i;
                notMember=false;
                    signingTable[num][0]=empName;
                }
            };
            if (notMember)
                cout<<"Sorry, the name entered doesn't exist in our database\n\n";
        } while (notMember);
        
        do   {
            cout<<"Please, enter your employee ID(use: 1) :";
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');}
            getline(cin,empID);
            
                if (empID == employeesList[num][1]){
                    wrongID=false;
                    signingTable[num][1]=empID;}
                
            if(wrongID) cout<<"\nIncorrect ID!\n";
        } while (wrongID);
        cout<<endl;
        do{       cout<<"EMPLOYEE MENU\n-------------\n Please,type your selection and press Enter\n\n\t(1): Sign-in\n\t(2): Break-out\n\t(3): Break-In\n\t(4): Sign-out\n\t(5): Go back to Main Menu\n\nYour choice: ";
            cin>>empChoice;
            if(empChoice!=1 && empChoice!=2 && empChoice!=3 && empChoice!=4 && empChoice!=5)
                cout<<"\nInvalid Choice\n";         }
        while(empChoice!=1 && empChoice!=2 && empChoice!=3 && empChoice!=4 && empChoice!=5);
        cout<<endl;
        
        if(empChoice == 1 || empChoice == 2 ||empChoice == 3 ||empChoice == 4){
            time_t now = time(0); //Generates current time
            tm *ltm = localtime(&now); // formats time using local time format (ltm)
            
            
            if(empChoice==1){
                string date;
                cout<<"Please enter date and press Enter(use MM/DD/YYYY format): ";
                cin.ignore();cin.clear();
                getline(cin,date);
                signingTable[num][2]=date;
                int time_hour=ltm->tm_hour; //saves sign-in hour
                int time_min=ltm->tm_min;   //saves sign-in minute
                int time_sec=ltm->tm_sec;   //saves sign-in second
                string hour=to_string(time_hour);
                string min=to_string(time_min);
                string sec=to_string(time_sec);
                string signIn = hour + ":" + min + ":" + sec;
                signingTable[num][3]=signIn;
                
                cout<<endl;
                cout<<"Sign-In successful!\n\n";
                SignInStatus[num][1]=1;
                MainMenu();
                }
            
            else if(empChoice==2){
                while(SignInStatus[num][1]!=1 ){
                    cin.ignore();cin.clear();
                    cout<<"ERROR!!!\nThere is no sign-in record associated with this name/ID\nPlease, sign-in first.\n\n ";
                    empMenu();
                }
                int time_hour=ltm->tm_hour; //saves break-out hour
                int time_min=ltm->tm_min;   //saves break-out minute
                int time_sec=ltm->tm_sec;   //saves break-out second
                string hour=to_string(time_hour);
                string min=to_string(time_min);
                string sec=to_string(time_sec);
                string breakOut = hour + ":" + min + ":" + sec;
                signingTable[num][4]=breakOut;
                cout<<endl;
                cout<<"Break-out successful!\n\n";
                BreakOutStatus[num][1]=1;
                MainMenu();
            }
            
            else if(empChoice==3){
                while(BreakOutStatus[num][1]!=1 ){
                    cin.ignore();cin.clear();
                    cout<<"ERROR!!!\nThere is no break-out record associated with this name/ID\nPlease, break-out first.\n\n ";
                    empMenu();
                }
                int time_hour=ltm->tm_hour; //saves break-in hour
                int time_min=ltm->tm_min;   //saves break-in minute
                int time_sec=ltm->tm_sec;   //saves break-in second
                string hour=to_string(time_hour);
                string min=to_string(time_min);
                string sec=to_string(time_sec);
                string breakIn = hour + ":" + min + ":" + sec;
                signingTable[num][5]=breakIn;
                cout<<endl;
                cout<<"Break-in successful!\n\n";
                BreakInStatus[num][1]=1;
                MainMenu();
            }
            
            else if(empChoice==4){
                while(BreakInStatus[num][1]!=1 && SignInStatus[num][1]!=1  ){
                    cin.ignore();cin.clear();
                    cout<<"ERROR!!!\nThere is no sign-in or break-in record associated with this name/ID\nPlease, sign-in or break-in first.\n\n ";
                    empMenu();
                }
                int time_hour=ltm->tm_hour; //saves sign-out hour
                int time_min=ltm->tm_min;   //saves sign-out minute
                int time_sec=ltm->tm_sec;   //saves sign-out second
                string hour=to_string(time_hour);
                string min=to_string(time_min);
                string sec=to_string(time_sec);
                string signOut = hour + ":" + min + ":" + sec;
                signingTable[num][6]=signOut;
                
                cout<<endl;
                cout<<"Sign-out successful!\n\n";
                SignInStatus[num][1]=0;
                BreakOutStatus[num][1]=0;
                BreakInStatus[num][1]=0;
                string lock="Locked";
                signingTable[num][7]=lock;
                
                MainMenu();
            }
            }
            
          else if(empChoice==5)
            MainMenu();
        
    }
    
};


void MainMenu(){
    char mainMenuChoice;

    do  { cout<<"MAIN MENU:\n Owner: O/o \t\tSupervisor: S/s \t\tEmployee: E/s\n\nPlease type your selection and press Enter: ";
        cin>>mainMenuChoice; cin.clear();cin.ignore();
        if(mainMenuChoice !='O' && mainMenuChoice !='o'&& mainMenuChoice !='S'&& mainMenuChoice !='s'&& mainMenuChoice !='E'&& mainMenuChoice!='e')
            cout<<"\nInvalid Choice!\n";
    } while (mainMenuChoice !='O' && mainMenuChoice !='o'&& mainMenuChoice !='S'&& mainMenuChoice !='s'&& mainMenuChoice !='E'&& mainMenuChoice!='e');
    cout<<endl;
    if (mainMenuChoice=='O' || mainMenuChoice=='o')
    {OWNER owner;
        owner.ownerMenu();}
    else if (mainMenuChoice=='S' || mainMenuChoice=='s')
    {Supervisor sup;
        sup.supMenu();
    }
    else if (mainMenuChoice=='E' || mainMenuChoice=='e')
    {Employee emp;
        emp.empMenu();
    
    };
}


int main(){
    MainMenu();
    
    return 0;
}
