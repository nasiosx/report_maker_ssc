/**
 * Developer : NASIOSX
 * Program name : Report Maker
 * Description : A simple program in c++ for making students report card
 * 
 * #pragma Optimise , #pragma taget: Code Optimisation 
 * 			See : https://www.geeksforgeeks.org/speed-up-naive-algorithms-in-competitive-coding-in-c-cpp/
 * 
 * <fstream> FILE I/O Operations , Eg: for storing input data to a text file
 * 			See : https://www.geeksforgeeks.org/file-handling-c-classes/
 * 
 * <ctime> Time header file , Retrieves localtime
 * 			See : https://www.geeksforgeeks.org/c-program-print-current-day-date-time/
 * 
 * Functions Overview :-
 * 
 * 	bool check(string arr)
 * 		data type bool , returns bool value (1/0) 
 * 		Argument type string, Accepts std::string data type variables for processing
 * 		Description : Check a string for the presence of numbers in it , returns true if found
 *			std::string See : https://www.geeksforgeeks.org/stdstring-class-in-c/ 	
 *	
 *  void Execute()
 * 		data type void , returns no value
 * 		Argument type void , doesn't accept any arguments
 * 		Description : Core function of the program , Ask user for inputs and store them into a file
 * 
 * 	void history(int n, char** arr)
 * 		data type void , returns no value
 * 		Argument type int , char** : Accepts a integer variable/value and char** which is pointer to char*
 * 			Reference for char** // https://stackoverflow.com/questions/13353807/what-is-char-in-c
 * 		Description : Accepts data from core function and store it to a log / history file 		
 * 
 * 	void manage(int n)
 * 		data type void , returns no value
 * 		Argument type int , Accepts integer variable/value
 * 		Description : Function to handle log / history file , Deleting log file and Reading log file are supported
 * 
 * 	void banner()
 * 		data type void , returns no value
 * 		Argument type void , doesn't accept any arguments
 * 		Description : Function to display ASCII ART 
 * 					Useful link for ascii arts : http://patorjk.com/software/taag/
 * 
 * 	void login(string uname, string pass)
 * 		data type void , returns no value
 * 		Argument type string , Accepts string value
 * 		Description : Function to validate username and password
 *  
 * 	int main()
 * 		data type int , returns integer value , return 0 on a successfull execution
 * 		Argument type void , doesn't accept any arguments
 * 		Description : Starting point of the program
 * */ 


#pragma Optimise("Ofast")
#pragma target("avx,avx2,fma")
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
void login(string uname, string pass);

struct students_details{ // Structure Declaration
		string name;
		int marks[6];
		int roll_num;
		int total = 0;
		float average;
		float percentage;
};
struct students_details ssc[64]; // Variable Declaration of structure , Here Array of Structures

// See : https://www.geeksforgeeks.org/structures-in-cpp/

int main()
{
	// Change Username and Password as you wish
	const string uname = "admin"; // constant Username
	const string pass = "admin"; // constant Password
	login(uname, pass);
	int op;
	banner(); // Call banner() , Display ASCII Art
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
			Execute(); // Call Execute() , program execution jumps into Execute() function
			break;
		case 2:
		case 3:
			manage(op); // Call manage() with integer arguement op
			break;
		case 4:
			cout << "\n\t\t\t\t Created by Nasi Nashid " << endl;
			cout << "\t\t\t\t Simple program to make report cards of students " << endl;
			cout << "\t\t\t\t History logs are stored in .report_history file and can be accessed using Option 3 in main menu " << endl;
			cout << "\t\t\t\t Thank you for using my program " << endl;
		default:
			cout << "\n\t\t\t\t Exiting Program , Thank you " << endl;
			exit(0); // Program control jumps to return 0
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
	
	// Character Pointer to hold subjects names

	cout << "\n\n\t\t\t\t STUDENTS MARKLIST SSC 2020 \t\t\n";
	cout << "\n\t\t Enter the number of reports : ";
	cin >> numberOfreports;
	for(int i=0; i < numberOfreports; i++) // Loop till i is not equal to numberOfreports
	{
		cout << "\n\t\t REPORT CARD " << i+1 << " :- " << std::endl;
		cout << "\t\t ----------------------------- \n";
		do{
			cout << "\t\t Enter the name of the student : ";
			cin >> ssc[i].name; // Accessing members of structure students_details
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
				fstream tFile;  // Declaring variable to hold data for storing to or reading from a file
				tFile.open("report.txt", ios::out);  // Open "report.txt" in Output Mode , Overwrites the file on each execution 
				tFile << "\n\t\t\t STUDENTS MARKLIST SSC 2020 \n\n"; // Datas inserted to tFile variable is stored into report.tx
				tFile.close(); // Store all content in tFile variable to "report.txt" and close the file
			}
			fstream outFile;
			outFile.open("report.txt", ios::out | ios::app); /** Open file in Output Mode and Append Mode , Append Mode stores contents of variable
															   * at the end of the file , Thus preventing Overwriting on each execution **/
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
		history(numberOfreports, subjects); // Calls history() with integer and char*
	}
	else{
		cout << "\n\t\t Exiting " << endl;
	}
}

bool check(string arr)
{
	for(int i=0; arr[i]!='\0'; i++) // Loop until the end of string
	{
		if(arr[i] >= '0' && arr[i] <= '9') // Check each character for between 0 and 9
		{
			return true; // if a character is a number , return true and exit the function
		}
	}
	return false; 
}

void history(int n, char** arr)
{
	time_t tt; // Declaring variable to store time
	struct tm * ti; // Declaring pointer variable for structure tm
	time(&tt); 
	ti = localtime(&tt); 
	fstream tempFile;
	tempFile.open(".report_history", ios::out | ios::app);
	for(int i=0; i < n ; i++)
	{
		if(i==0)
			tempFile << "\n DATE : " << asctime(ti) << endl; // Store time and date in human-readable form 
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
		string line; // String variable to store contents of a file
		fstream inFile; // Declaring variable to hold contents of file
		inFile.open(".report_history", ios::in);  // Open file in Input Mode / Read Mode
		if(!inFile) // If variable return 0 , Error in opening file
			cout << "\t\tUnable to open file , Maybe you are running this program for the first time , Thank You \n" << endl;
		while(inFile) // Loop until the end of file
		{
			getline(inFile, line); // retrieve contents from file variable to string variable
			cout << line << endl; // Display contents of string variable , That is , lines in the file
		}
		inFile.close(); // Close the file after Reading
		
	}
	else if(n == 3)
	{
		if(remove(".report_history")==0) // remove("file") , removes file named "file" in the current directory , returns 0 on successful remove 
			cout << "\n Logs Successfully Deleted " << endl;
		else
			cout << "\n Error while deleting file " << endl;;
		
	}
}

void login(string uname, string pass)
{
	string userName, passWord;
	cout << "\n Note : Default Username and Password = admin \n\n";
	cout << "\n Enter the username : ";
	cin >> userName;
	cout << "\n Enter the password : ";
	cin >> passWord;
	if(uname.compare(userName) == 0 && pass.compare(passWord) == 0)
	{
		cout << "\n Login Success " << endl;
		getchar();

		// Macros to Identify Operating System
		// See : https://sourceforge.net/p/predef/wiki/OperatingSystems/
		// Also : https://stackoverflow.com/questions/15580179/how-do-i-find-the-name-of-an-operating-system
		#ifdef _WIN32
			system("cls");
		#elif _WIN64
			system("cls");
		#elif __linux__
			system("clear");
		#endif
	}
	else
	{
		cout << "\n Invalid Username or Password , Please try again \n";
		exit(0);
	}
}