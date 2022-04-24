//
// Created by Frederik Desmet on 19/04/2022.
//
#include <iostream>
#include <stdexcept>
#include "Database.h"

namespace Records
{
	Employee& Database::addEmployee(const std::string& firstName, const std::string& lastName)
	{
		Employee newEmployee(firstName, lastName);
		newEmployee.setEmployeeNumber(_nextEmployeeNumber++);
		newEmployee.hire();
		_employees.push_back(newEmployee);
		return _employees.back();
	}
	Employee& Database::getEmployee(int employeeNumber)
	{
		for (auto& employee : _employees)
		{
			if (employee.getEmployeeNumber() == employeeNumber)
				return employee;
		}
		throw std::logic_error("No employee found with this employee number.");
	}
	Employee& Database::getEmployee(const std::string& firstName, const std::string& lastName)
	{
		for (auto& employee : _employees)
		{
			if (employee.getFirstName() == firstName && employee.getLastName() == lastName)
				return employee;
		}
		throw std::logic_error("No employee found with the provided first and last name.");
	}
	void Database::displayAll() const
	{
		for (const auto& employee : _employees)
			employee.display();
	}
	void Database::displayCurrent() const
	{
		for (const auto& employee : _employees)
		{
			if (employee.isHired())
				employee.display();
		}
	}
	void Database::displayFormer() const
	{
		for (const auto& employee : _employees)
		{
			if (!employee.isHired())
				employee.display();
		}
	}
}
