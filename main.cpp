#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace Records;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
void doDemote(Database& db);

int main()
{
	Database employeeDB;

	bool isDone{};
	while (!isDone)
	{
		int selection = displayMenu();
		switch (selection)
		{
		case 0:
			isDone = true;
			break;
		case 1:
			doHire(employeeDB);
			break;
		case 2:
			doFire(employeeDB);
			break;
		case 3:
			doPromote(employeeDB);
			break;
		case 4:
			doDemote(employeeDB);
			break;
		case 5:
			employeeDB.displayAll();
			break;
		case 6:
			employeeDB.displayCurrent();
			break;
		case 7:
			employeeDB.displayFormer();
			break;
		default:
			std::cerr << "Unknown Command, please provide a valid number." << std::endl;
			break;
		}
	}
	return 0;
}

/**
 * Displays the menu where the user can select from.
 * @return int The users selection.
 */
int displayMenu()
{
	int selection;
	std::cout << std::endl;
	std::cout << "Employee Database" << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << "1) Hire a new employee" << std::endl;
	std::cout << "2) Fire an employee" << std::endl;
	std::cout << "3) Promote an employee" << std::endl;
	std::cout << "4) Demote an employee" << std::endl;
	std::cout << "5) List all employees" << std::endl;
	std::cout << "6) List all current employees" << std::endl;
	std::cout << "7) List all former employees" << std::endl;
	std::cout << "0) Quit" << std::endl;
	std::cout << std::endl;
	std::cout << "---> ";
	std::cin >> selection;
	return selection;
}

/**
 * Hires the Employee based on the provided first and last name.
 * @param db Database object.
 */
void doHire(Database& db)
{
	std::string firstName{};
	std::string lastName{};

	std::cout << "First name? ";
	std::cin >> firstName;

	std::cout << "Last name? ";
	std::cin >> lastName;

	db.addEmployee(firstName, lastName);
}

/**
 * Fires the employee based on the provided employee number.
 * @param db Database object.
 */
void doFire(Database& db)
{
	int employeeNumber{};

	std::cout << "Employee number? ";
	std::cin >> employeeNumber;

	try
	{
		Employee& employee = db.getEmployee(employeeNumber);
		employee.fire();
		std::cout << "Employee " << employeeNumber << " has been fired." << std::endl;
	}
	catch (const std::logic_error& exception)
	{
		std::cerr << "Unable to fire the employee: " << exception.what() << std::endl;
	}
}

/**
 * Promotes the given Employee.
 * @param db Database object.
 */
void doPromote(Database& db)
{
	int employeeNumber{};
	int raiseAmount{};

	std::cout << "Employee number? ";
	std::cin >> employeeNumber;

	std::cout << "How much of a raise? ";
	std::cin >> raiseAmount;

	try
	{
		Employee& employee = db.getEmployee(employeeNumber);
		employee.promote(raiseAmount);
	}
	catch (const std::logic_error& exception)
	{
		std::cerr << "Unable to promote employee: " << exception.what() << std::endl;
	}
}

/**
 * Demotes the given Employee.
 * @param db Database object.
 */
void doDemote(Database& db)
{
	int employeeNumber{};
	int demoteAmount{};

	std::cout << "Employee number? ";
	std::cin >> employeeNumber;

	std::cout << "How much of a demote? ";
	std::cin >> demoteAmount;

	try
	{
		Employee& employee = db.getEmployee(employeeNumber);
		employee.demote(demoteAmount);
	}
	catch (const std::logic_error& exception)
	{
		std::cerr << "Unable to demote employee: " << exception.what() << std::endl;
	}
}
