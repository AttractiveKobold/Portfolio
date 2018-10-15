//Developer: Jacob Mangia
//Date: 12/3/17
//Purpose: To allow the user to process their customer's loans and to allow the user to see a report of the loans their customers have.

#include <iostream>
#include <string>
#include <array>
#include <fstream>

using namespace std;
int menuInput;
char charInput;

void MainMenu();
void DisplayReport();
void ProcessLoan();

array<string, 999> custNames;
array<float, 999> loanAmounts;
array<int, 999> loanLengths;
array<float, 999> interestRates;
array<float, 999> paymentAmounts;

int maxIndex = 0;

ofstream outStream;
ifstream instream;
const char fileName[] = "Customer Information.txt";

void main()
{

	instream.open(fileName);

	int whichArray = 1;
	string line;

	while (!instream.eof())
	{
		getline(instream, line, '#');
		switch (whichArray)
		{
		case 1:
			custNames[maxIndex] = line; break;
		case 2:
			loanAmounts[maxIndex] = stof(line); break;
		case 3:
			loanLengths[maxIndex] = stoi(line); break;
		case 4:
			interestRates[maxIndex] = stof(line); break;
		case 5:
			paymentAmounts[maxIndex] = stof(line);
			maxIndex++;
			whichArray = 0;
			break;
		}
		whichArray++;
	}

	instream.close();

	MainMenu();

}

void ProcessLoan()
{
	double loanAmount, interestRate, paymentAmount, ratePerPeriod = 0;
	int loanLength;
	string custName;

	charInput = 'a';

	//This commented out code is a feture that was going to be added, but caused some issues I did not have enough time to fix.
	/*do
	{
		system("CLS");

		cout << "Are we working with an existing customer (E) or a new customer (N)?" << endl;
		cin >> charInput;
	} while (!(toupper(charInput) == 'E' || toupper(charInput) == 'N') || cin.fail());

	if (toupper(charInput) == 'E')
	{
		do
		{
			system("cls");
			menuInput = 0;
			cout << "Which customer are you working with?" << endl << endl;

			for (int i = 1; i <= custNames.size(); i++)
			{
				cout << i << ": " << custNames[i - 1] << endl;
			}

			cin >> menuInput;

			if (menuInput > 0 && menuInput < 5)
			{
				custName = custNames[menuInput - 1];
			}
			else
			{
				menuInput = 0;
				cout << "That is not a valid choice." << endl;
				system("pause");
			}

		} while (menuInput == 0);
	}
	else
	{*/
		system("cls");

		cout << "Please enter the following information." << endl << endl << "Customer Name: ";
		cin.ignore();
		getline(cin, custName);
		cout << "Loan Amount: ";
		cin >> loanAmount;

		while (loanAmount <= 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Loan amount must be a number greater than 0" << endl << endl << "Loan Amount: ";
			cin >> loanAmount;
		}

		cout << "Length of loan (in years): ";
		cin >> loanLength;

		while (loanLength <= 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Loan length must be an integer greater than zero" << endl << endl << "Loan Length: ";
		}

		cout << "Interest Rate (as a decimal): ";
		cin >> interestRate;

		while (interestRate < 0 || interestRate > 1 || cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Interest rate must be a decimal between 0 and 1" << endl << endl << "Interest Rate: ";
			cin >> interestRate;
		}

		double i = interestRate / 12;
		int n = loanLength * 12;

		paymentAmount = (loanAmount * pow(i + 1, n) * i) / (pow(i + 1, n) - 1);

		paymentAmount = roundf(paymentAmount * 100) / 100;

		outStream.open(fileName, ofstream::app);

		if (outStream.is_open())
		{
			outStream << custName << "#" << loanAmount << "#" << loanLength << "#" << interestRate << "#" << paymentAmount << "#";
		}

		outStream.close();

		cout.precision(2);

		cout << custName << "'s payment amount is $" << fixed << paymentAmount << endl;

		cout << "Program must be restarted before report can be generated for this loan" << endl;

	system("pause");
}

void DisplayReport()
{
	
	int customerIndex = 0;

	do
	{
		system("cls");

		cout << "What customer will we be working with?" << endl << endl;

		for (int i = 0; i < maxIndex; i++)
		{
			cout << i + 1 << ") " << custNames[i] << endl;
		}

		cin >> menuInput;

	} while (menuInput <= 0 || menuInput > maxIndex + 1 || cin.fail());

	customerIndex = menuInput - 1;

	
	double loanAmount = loanAmounts[customerIndex], interestRate = interestRates[customerIndex], paymentAmount = paymentAmounts[customerIndex];
	int loanLength = loanLengths[customerIndex];
	
	double principal[999];
	double interest[999];
	double totalInterest[999];
	double loanBalance[999];

	paymentAmount = round(paymentAmount * 100) / 100;

	interest[0] = loanAmount * (interestRate / 12);
	interest[0] = round(interest[0] * 100) / 100;
	
	principal[0] = paymentAmount - interest[0];
	totalInterest[0] = interest[0];
	loanBalance[0] = loanAmount - principal[0];

	for (int i = 1; i < loanLength*12; i++)
	{
		loanAmount = loanBalance[i - 1];
		interest[i] = loanAmount * (interestRate / 12);
		interest[i] = round(interest[i] * 100) / 100;
		principal[i] = paymentAmount - interest[i];
		totalInterest[i] = interest[i-1] + interest[i];
		loanBalance[i] = loanBalance[i-1] - principal[i];
	}
	do
	{
		do
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			menuInput = 0;
			system("CLS");

			cout << "What month would you like to look at on the amortization table? (1 - " << loanLength*12 << ") (0 to exit)" << endl;

			cin >> menuInput;
		} while (menuInput < 0 || menuInput > loanLength*12 || cin.fail());

		if (menuInput != 0)
		{
			system("CLS");

			cout << "Month: " << menuInput << endl;
			cout << "Customer Name: " << custNames[customerIndex] << endl;
			cout << "Payment Amount: " << paymentAmounts[customerIndex] << endl;
			cout << "Principal: " << principal[menuInput - 1] << endl;
			cout << "Interest: " << interest[menuInput - 1] << endl;
			cout << "Total Interest: " << totalInterest[menuInput - 1] << endl;
			cout << "Loan Balance: " << loanBalance[menuInput - 1] << endl;

			system("pause");
		}

	} while (menuInput != 0);
}

void MainMenu()
{
	while (true)
	{
		system("cls");

		cout << "Main Menu" << endl << "1) Process Loan" << endl << "2) Display Report" << endl << "3) Exit" << endl;

		cin >> menuInput;

		switch (menuInput)
		{

		case 1:
			ProcessLoan();
			break;
		case 2:
			DisplayReport();
			break;
		case 3:
			exit(0);
			break;
		default:
			cout << endl << "That is not a valid option." << endl;
			system("pause");
			break;
		}
	}
}
