//
// Created by Frederik Desmet on 19/04/2022.
//
#include <iostream>
#include "Employee.h"

namespace Records
{
	Employee::Employee(const std::string& firstName,
		const std::string& lastName)
		: _firstName(firstName), _lastName(lastName)
	{
	}

	void Employee::promote(int raiseAmount)
	{
		setSalary(getSalary() + raiseAmount);
	}
	void Employee::demote(int demeritAmount)
	{
		setSalary(getSalary() - demeritAmount);
	}
	void Employee::hire()
	{
		_isHired = true;
	}
	void Employee::fire()
	{
		_isHired = false;
	}

	void Employee::display() const
	{
		std::cout << "Employee: " << getLastName() << ", " << getFirstName() << std::endl;
		std::cout << "-------------------------" << std::endl;
		std::cout << (isHired() ? "Current Employee" : "Former Employee") << std::endl;
		std::cout << "Employee Number: " << getEmployeeNumber() << std::endl;
		std::cout << "Salary: $" << getSalary() << std::endl;
		std::cout << std::endl;
	}

	void Employee::setSalary(int newSalary)
	{
		_salary = newSalary;
	}
	int Employee::getSalary() const
	{
		return _salary;
	}

	void Employee::setFirstName(const std::string& firstname)
	{
		_firstName = firstname;
	}
	const std::string& Employee::getFirstName() const
	{
		return _firstName;
	}
	void Employee::setLastName(const std::string& lastName)
	{
		_lastName = lastName;
	}
	const std::string& Employee::getLastName() const
	{
		return _lastName;
	}
	void Employee::setEmployeeNumber(int employeenumber)
	{
		_employeeNumber = employeenumber;
	}
	int Employee::getEmployeeNumber() const
	{
		return _employeeNumber;
	}
	bool Employee::isHired() const
	{
		return _isHired;
	}
}




