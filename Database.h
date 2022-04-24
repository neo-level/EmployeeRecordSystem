//
// Created by Frederik Desmet on 19/04/2022.
//
#pragma once
#include <iostream>
#include <vector>
#include "Employee.h"

namespace Records
{
	const int FirstEmployeeNumber{ 1000 };
	class Database
	{
	public:
		/**
		 * Creates an Employee object with the given firstname and lastname,
		 * auto assigns an employee number in the process.
		 * @param firstName The surname of the new employee.
		 * @param lastName The name of the new employee.
		 * @return Reference to the new Employee object.
		 */
		Employee& addEmployee(const std::string& firstName,
			const std::string& lastName);

		/**
		 * Gets the employee object from the corresponding employee number.
		 * @param employeeNumber Number of the employee you want to retrieve.
		 * @return Reference to the Employee object correlated to the employee number.
		 */
		Employee& getEmployee(int employeeNumber);

		/**
		 * Gets the employee object from the corresponding surname and name.
		 * @param firstName The surname of the new employee.
		 * @param lastName The name of the new employee.
		 * @return Reference to the Employee object correlated to the given surname and name.
		 */
		Employee& getEmployee(const std::string& firstName,
			const std::string& lastName);

		/**
		 * Displays all the Employees.
		 */
		void displayAll() const;

		/**
		 * Displays all the current Employees.
		 */
		void displayCurrent() const;

		/**
		 * Displays all the former Employees.
		 */
		void displayFormer() const;
	private:
		std::vector<Employee> _employees;
		int _nextEmployeeNumber = FirstEmployeeNumber;
	};
}

