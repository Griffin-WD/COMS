// Name: Griffin Dunlap
// Prior program that we've converted to OOP
// 10/16/2024

#include<iostream>
#include<string>
#include<vector>
#include<fstream> 
#include<iomanip>

using namespace std;

// Creating class
class employee 
{
// Public functions for the class
public:
	void fileCheck(ifstream& iFile)
	{
		if (!iFile.is_open())
		{
			cout << "Input file not found" << endl;
			exit(1);
		}
	}

	void getData(ifstream& iFile, vector<employee>& atu)
	{
		employee temp;
		while (!iFile.eof())
		{
			getline(iFile, temp.fName);
			getline(iFile, temp.lName);
			getline(iFile, temp.jobTitle);
			getline(iFile, temp.empNum);
			iFile >> temp.hoursWorked;
			iFile >> temp.wage;
			iFile >> temp.ded;
			iFile.ignore();
			atu.push_back(temp);
		}
	}

	void calcOverTime(vector<employee>& atu)
	{
		for (int a = 0; a < atu.size(); a++)
		{
			if (atu[a].hoursWorked > 40)
			{
				atu[a].oTHours = atu[a].hoursWorked - 40;
				atu[a].oTWage = atu[a].wage * 1.5;
				atu[a].oTPay = atu[a].oTHours * atu[a].oTWage;
				atu[a].grossPay = 40 * atu[a].wage + atu[a].oTPay;
			}
			else
			{
				atu[a].oTHours = 0;
				atu[a].oTWage = 0;
				atu[a].oTPay = 0;
				atu[a].grossPay = atu[a].hoursWorked * atu[a].wage;
			}
		}
	}

	void calcTax(vector<employee>& atu)
	{
		for (int a = 0; a < atu.size(); a++)
		{
			if (atu[a].ded <= 0)
				atu[a].tax = .35;
			else if (atu[a].ded == 1)
				atu[a].tax = .30;
			else if (atu[a].ded == 2)
				atu[a].tax = .25;
			else if (atu[a].ded == 3)
				atu[a].tax = .20;
			else
				atu[a].tax = .15;
		}
	}

	void calcNetPay(vector<employee>& atu)
	{
		for (int a = 0; a < atu.size(); a++)
		{
			atu[a].tax = atu[a].tax * atu[a].grossPay;
			atu[a].netPay = atu[a].grossPay - atu[a].tax;
		}
	}

	void salaryCalculation(vector<employee>& atu) {
		// Local variables for calculations
		double totalSalary = 0;
		double averageSalary = 0;
		double medianSalary = 0;
		// Total salary calculation
		for (int a = 0; a < atu.size(); a++)
		{
			totalSalary += atu[a].grossPay;
		}
		// Average salary calculation
		if (atu.size() > 0) 
		{
			averageSalary = totalSalary / atu.size();
		}
		else
		{
			averageSalary = 0;
		}
		// Used my old bubblesort and slightly altered it
		double temp;
		for (int a = 0; a < atu.size(); a++) {
			for (int b = 0; b < atu.size() - 1; b++) {
				if (atu[b].grossPay > atu[b + 1].grossPay) {
					temp = atu[b].grossPay;
					atu[b].grossPay = atu[b + 1].grossPay;
					atu[b + 1].grossPay = temp;
				}
			}
		}
		// Median salary calculation. Used modulus to find if the amount of employees was even or odd, then got the median by finding the center two numbers average if even or the center number if odd
		if (atu.size() % 2 == 0)
		{
			medianSalary = (atu[atu.size() / 2 - 1].grossPay + atu[atu.size() / 2].grossPay) / 2;
		}
		else
		{
			medianSalary = atu[atu.size() / 2].grossPay;
		}
		// Outputting the information here but calling the function in output so it outputs with everything else
		cout << "Total Salary: $" << totalSalary << endl;
		cout << "Average Salary: $" << averageSalary << endl;
		cout << "Median Salary: $" << medianSalary << endl;
	}
	void output(vector<employee>& atu)
	{
		for (int a = 0; a < atu.size(); a++)
		{
			cout << "Name: " << atu[a].lName << " " << atu[a].fName << endl;
			cout << "Job Title: " << atu[a].jobTitle << endl;
			cout << "Employee Number: " << atu[a].empNum << endl;
			cout << "Hourly Wage: $" << atu[a].wage << endl;
			cout << "Hours Worked: " << atu[a].hoursWorked << endl;
			cout << "Deductions Claimed: " << atu[a].ded << endl;
			if (atu[a].oTPay > 0)
			{
				cout << "Overtime Hours Worked: " << atu[a].oTHours << endl;
				cout << "Overtime Wage: $" << atu[a].oTWage << endl;
				cout << "Overtime Pay: $" << atu[a].oTPay << endl;
			}
			cout << "Gross Pay: $" << atu[a].grossPay << endl;
			cout << "Taxes Withheld: $" << atu[a].tax << endl;
			cout << "Net Pay: $" << atu[a].netPay << endl << endl;
		}
		salaryCalculation(atu);
	}

	// Creating Constructor
	employee()
	{
		fName = "Mike";
		lName = "Tyson";
	}
	// Creating Deconstructor
	~employee()
	{

	}

// Private Variables for this class
private:
	string fName, lName, jobTitle, empNum;
	double grossPay, netPay, oTWage, oTHours, oTPay, tax;
	double hoursWorked, wage, medianSalary;
	int ded; // deductions
};



int main()
{
	vector<employee> atu;
	employee temp;
	ifstream iFile;
	iFile.open("input.txt");

	cout << fixed << showpoint << setprecision(2);

	temp.fileCheck(iFile);
	temp.getData(iFile, atu);
	temp.calcOverTime(atu);
	temp.calcTax(atu);
	temp.calcNetPay(atu);
	temp.output(atu);

	iFile.close();
}