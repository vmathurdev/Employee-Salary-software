// The below program calculates the employee's salaries based on their yearly performance as well as gives the summary statistics of employee


#include <iostream> // Standard library function in C++ to invoke functions which are used oftenly
#include <sstream>  //providing string stream classes (input and output)
#include <string>   // providing the use of string data type
#include <iomanip>  // I/O manipulators

using namespace std;

// creating a class as employee with objects like salary, rating, performance, etc
class Employee
{
	public: // access modifiers that tells the accessibility of class members
		string Name;
		int Salary;
		int Rating[4];
		float OverallRating;  // Using float data type to accomodate decimal values in the rating
		float ExpextedSalary; // Using float data type to accomodate decimal values in the rating
		string Performance;
};

class Helper
{
	public:
		int TakeInput(string message) 
		{
			string line;
			int n = 0;
			
		    while (getline(cin, line)) 
			{
		        if (!parse_int(line, n))
            		cout << "Inavlid input. \n"<<message;
        		else
    				break;      			
		    }
		    
		    return n;
		}
		
		bool parse_int(const std::string& str, int& n) // parsing a string 
		{
		    std::istringstream sin(str);  // returns a string object
		    return sin >> n >> std::ws && sin.eof();  // reach end of file
		}
};

int main()  
{	
	int employeeCount, largestName;
	string input;
	Employee temp;
	Helper helper;
	cout << "Enter the number of Employees: ";                             // To print the number of employees
	employeeCount = helper.TakeInput("Enter the number of Employees: ");
	
	Employee Employees[employeeCount];
	
	for(int i = 0; i <employeeCount; i++)
	{
		Employee employee;
		float amountIncreased;
		
		cout<<"Enter the name of employee "<< i + 1 << ": ";
		getline(cin, employee.Name);           // get characters from the string 
		
		cout<<"Enter "<< employee.Name <<"'s current salary: ";
		employee.Salary = helper.TakeInput("Enter " + employee.Name + "'s current salary: ");  // invoking the take-input method from helper class
		
		cout<<"Enter the rating "<< employee.Name <<" received for Q1: ";
		employee.Rating[0] = helper.TakeInput("Enter the rating " + employee.Name + " received for Q1: ");		
		
		cout<<"Enter the rating "<< employee.Name <<" received for Q2: ";
		employee.Rating[1] = helper.TakeInput("Enter the rating " + employee.Name + " received for Q2: ");
		
		cout<<"Enter the rating "<< employee.Name <<" received for Q3 ";
		employee.Rating[2] = helper.TakeInput("Enter the rating " + employee.Name + " received for Q3 ");
		
		cout<<"Enter the rating "<< employee.Name <<" received for Q4: ";
		employee.Rating[3] = helper.TakeInput("Enter the rating " + employee.Name + " received for Q4: ");
		
		
		// Mathematical calculations to calculate the expected salary for next year based on performance 

		employee.OverallRating = (employee.Rating[0]  + employee.Rating[1] + employee.Rating[2]+ employee.Rating[3] )/4.0;
		amountIncreased = employee.Salary * employee.OverallRating / 100.0;	
		employee.ExpextedSalary = employee.Salary + amountIncreased;
		
		
		//Defining conditions for ratings of the employee
		if(employee.OverallRating >= 7)
		{
			employee.Performance = "Best";	
		}
		else if(employee.OverallRating >=5 && employee.OverallRating < 7)
		{
			employee.Performance = "Average";	
		}
		else		
		{
			employee.Performance = "On-track";	
		}
		
		cout<<"\n";
				
		Employees[i] = employee;
	}
	
	cout<<"\n";
	
	for(int i=0; i<employeeCount; i++)
	{		
		for(int j =i+1;j<employeeCount;j++)
		{
			// Sort the records based on overall rating
			if(Employees[i].OverallRating < Employees[j].OverallRating)
			{
				temp = Employees[i];
				Employees[i]=Employees[j];
				Employees[j]=temp;
			}
		}
	}
	
	cout<<setw(10)<<"Names"  // set the field width, for ex- if name is Andy, so it will utilize 4 fields rest 6 fields are kept blank 
		<<setw(10)<<"Q1"
		<<setw(10)<<"Q2"
		<<setw(10)<<"Q3"
		<<setw(10)<<"Q4"
		<<setw(20)<<"Overall Rating"
		<<setw(20)<<"Expected Salary"
		<<setw(20)<<"Performance\n";
	
	cout<<"-------------------------------------------------------------------------------------------------------------------";
	
	for(int i = 0; i <employeeCount; i++) // loop to print the employee names, ratings obtained from Q1 to Q4, overall rating and the indicators
	{
		cout<<"\n";
		
	

		cout<<setw(10)<<Employees[i].Name
			<<setw(10)<<Employees[i].Rating[0]
			<<setw(10)<<Employees[i].Rating[1]
			<<setw(10)<<Employees[i].Rating[2]
			<<setw(10)<<Employees[i].Rating[3]
			<<setw(20)<<Employees[i].OverallRating
			<<setw(20)<<Employees[i].ExpextedSalary
			<<setw(20)<<Employees[i].Performance;
	}	
}

