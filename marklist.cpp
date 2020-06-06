#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <ctime>
using namespace std;

bool check(string arr);
void Execute();
void history(int n, char** arr);
void manage(int n);
void banner();
void login();

struct students_details{
		string name;
		int marks[6];
		int roll_num;
		int total = 0;
		float average;
		float percentage;
} ssc[63];

int main()
{
	bool lnx;
	#ifdef __linux__
		lnx = true;
	#elif __unix
		lnx = true;
	#endif

	if(!lnx)
	{
		cout << "\n Sorry, This program Only Supports Linux \n";
		exit(0);
	}
	int op;
	banner();
	cout << "\n\t\t\t\t 1. Create a New Report " << endl;
	cout << "\t\t\t\t 2. Check the Report log "  << endl;
	cout << "\t\t\t\t 3. Delete the Report log " << endl;
	cout << "\t\t\t\t 4. About the program " << endl;
	cout << "\t\t\t\t 0. Exit the program " << endl;;
	cout << "\t\t\t\t Enter a option to continue : ";
	cin >> op;
	switch(op)
	{
		case 1:
			Execute();
			break;
		case 2:
		case 3:
			manage(op);
			break;
		case 4:
			cout << "\n\t\t\t\t Created by Nasi Nashid " << endl;
			cout << "\t\t\t\t Simple program to make report cards of students " << endl;
			cout << "\t\t\t\t History logs are stored in .report_history file and can be accessed using Option 3 in main menu " << endl;
			cout << "\t\t\t\t Thank you for using my program " << endl;
		default:
			cout << "\n\t\t\t\t Exiting Program , Thank you " << std::endl;
			exit(0);
	}
	return 0;
}

void banner()
{
	
cout << "\t\t\t                      __________________________ "  << endl;
cout << "\t\t\t _____________________    __|__ \\_  __ \\_|__ \\_  __ \\ " << endl;
cout << "\t\t\t __  ___/_  ___/  ___/    ____/ /  / / /___/ /  / / / " << endl;
cout << "\t\t\t _(__  )_(__  )/ /__      _  __// /_/ /_  __// /_/ /  " << endl;
cout << "\t\t\t /____/ /____/ \\___/      /____/\\____/ /____/\\____/  " << endl;
                                                    
                                                                 
}

void Execute()
{
	
	int numberOfreports;
	
	char* subjects[] = {" Chemistry : ",
						" Physics : ",
						" Maths : ",
						" Computer Science : ",
						" English : ",
						" First Language : "};
	
	cout << "\n\n\t\t\t\t STUDENTS MARKLIST SSC 2020 \t\t\n";
	cout << "\n\t\t Enter the number of reports : ";
	cin >> numberOfreports;
	for(int i=0; i < numberOfreports; i++)
	{
		cout << "\n\t\t REPORT CARD " << i+1 << " :- " << std::endl;
		cout << "\t\t ----------------------------- \n";
		do{
			cout << "\t\t Enter the name of the student : ";
			cin >> ssc[i].name;
			if(check(ssc[i].name))
				cout << "\n\t\t Name cannot contain numbers , Please enter the name again in  correct format " << std::endl;
		}while(check(ssc[i].name));
		cout << "\t\t Enter the roll number : ";
		cin >> ssc[i].roll_num;
		for(int j = 0; j < 6; j++)
		{
			cout << "\t\t Enter the mark of" << subjects[j];
			cin >> ssc[i].marks[j];
			ssc[i].total = ssc[i].total + ssc[i].marks[j];
		}
		ssc[i].average = ssc[i].total/6;
		ssc[i].percentage = ((float)ssc[i].total/600.0)*100.0;
	}
	char ch;
	cout << "\n\t\t Store this report to a file ? (y/n) : ";
	cin >> ch;
	if(ch == 'y')
	{
		for(int j=0; j < numberOfreports; j++)
		{
			if(j==0)
			{
				fstream tFile;
				tFile.open("report.txt", ios::out);
				tFile << "\n\t\t\t STUDENTS MARKLIST SSC 2020 \n\n";
				tFile.close();
			}
			fstream outFile;
			outFile.open("report.txt", ios::out | ios::app);
			outFile << "\n\n REPORT CARD " << j+1 << "\n";
			outFile << " ------------------------ \n\n";
			outFile << " Name : " << ssc[j].name << endl;
			outFile << " Roll Number : " << ssc[j].roll_num << endl;
			outFile << " Total Mark : " << ssc[j].total << endl;
			outFile << " Average Mark : " << ssc[j].average << endl;
			outFile << " Percentage : " << ssc[j].percentage << "%" << endl;
			outFile.close();
		
		}
		cout << "\n\t\t Done , Check report.txt in the current Directory !" << endl;
		history(numberOfreports, subjects);
	}
	else{
		cout << "\n\t\t Exiting " << endl;
	}
}

bool check(string arr)
{
	for(int i=0; arr[i]!='\0'; i++)
	{
		if(arr[i] >= '0' && arr[i] <= '9')
		{
			return true;
		}
	}
	return false;
}

void history(int n, char** arr)
{
	time_t tt;
	struct tm * ti;
	time(&tt);
	ti = localtime(&tt);
	fstream tempFile;
	tempFile.open(".report_history", ios::out | ios::app);
	for(int i=0; i < n ; i++)
	{
		if(i==0)
			tempFile << "\n DATE : " << asctime(ti) << endl;
		tempFile << " REPORT CARD " << i+1 << endl;
		tempFile << " ----------------------- " << endl;
		tempFile << " Name : " << ssc[i].name << endl;
		tempFile << " Roll Number : " << ssc[i].roll_num << endl;
		for(int j=0;j<6;j++)
		{
			tempFile << arr[j] << ssc[i].marks[j] << ",";
		}
		tempFile << endl;
		tempFile << " Total Mark : " << ssc[i].total << endl;
		tempFile << " Average Mark : " << ssc[i].average << endl;
		tempFile << " Percentage : " << ssc[i].percentage << "% \n" << endl; 
	}
}

void manage(int n)
{
	if(n == 2)
	{
		string line;
		ifstream inFile;
		inFile.open(".report_history");
		if(!inFile)
			cout << "\t\tUnable to open file , Maybe you are running this program for the first time , Thank You \n" << endl;
		while(inFile)
		{
			getline(inFile, line);
			cout << line << endl;
		}
		inFile.close();
		
	}
	else if(n == 3)
	{
		system("rm .report_history > /dev/null");
		cout << "\n Logs Successfully Deleted " << endl;
	}
}

void login()
{
	string uname,pass,format,inf,tinf,crypt;
	cout << "\n Enter username : ";
	cin >> uname;
	cout << "\n Enter password : ";
	cin >> pass;
	format.append(uname);
	format.append(",");
	format.append(pass);
	crypt.append("echo \"");
	crypt.append(format);
	crypt.append("\" | sha1sum > tmp");
	const char *command = crypt.c_str();
	system(command);
	ifstream inFile("hash");
	ifstream tFile("tmp");
	if(!inFile)
		cout << "\n Error \n";
	else
	{
		while(inFile)
		{
			getline(inFile, inf);
			getline(tFile, tinf);
			if(tinf == inf)
			{
				cout << "\n Success " << endl;
				break;
			}
		}
		inFile.close();
		tFile.close();
		system("rm tmp");
	}

}