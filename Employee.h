//
// Created by Frederik Desmet on 19/04/2022.
//

#pragma once
#include <string>

namespace Records
{
	const int DefaultStartingSalary{ 30000 };
	const int DefaultRaiseAndDemeritAmount{ 1000 };
	class Employee
	{
	public:
		Employee() = default;
		Employee(const std::string& firstName,
			const std::string& lastName);

		/**
		 * Raises the salary of the Employee.
		 * @param raiseAmount The amount to raise the salary, defaults to 1000.
		 */
		void promote(int raiseAmount = DefaultRaiseAndDemeritAmount);

		/**
		 * Decreases the salary of the Employee.
		 * @param demeritAmount The amount to decrease the salary, defaults to 1000.
		 */
		void demote(int demeritAmount = DefaultRaiseAndDemeritAmount);

		/**
		 * Sets the Employees hired state to true.
		 */
		void hire();

		/**
		 * Sets the Employees hired state to false.
		 */
		void fire();

		/**
		 * Displays the current information from the employee.
		 */
		void display() const;

		/**
		 * Sets the employee name to the given input.
		 * @param firstname The new name of the employee.
		 */
		void setFirstName(const std::string& firstname);

		/**
		 * Gets the first name of the employee.
		 * @return string employees first name.
		 */
		[[nodiscard]] const std::string& getFirstName() const;

		/**
		 * Sets the employees last name to the given input.
		 * @param lastName The new last name of the employee.
		 */
		void setLastName(const std::string& lastName);

		/**
		 * Gets the last name of the employee.
		 * @return string employees last name.
		 */
		[[nodiscard]] const std::string& getLastName() const;

		/**
		 * Sets the employees number.
		 * @param employeenumber number for the employee.
		 */
		void setEmployeeNumber(int employeenumber);

		/**
		 * Gets the employees number.
		 * @return int Number of the employee.
		 */
		[[nodiscard]] int getEmployeeNumber() const;

		/**
		 * Sets the salary of the employee.
		 * @param newSalary amount that represents the new salary.
		 */
		void setSalary(int newSalary);

		/**
		 * Gets the employees salary.
		 * @return int amount of salary from the employee.
		 */
		[[nodiscard]] int getSalary() const;

		/**
		 * Gets the employees current state could be hired or fired.
		 * @return bool The employees current state.
		 */
		[[nodiscard]] bool isHired() const;
	private:
		std::string _firstName;
		std::string _lastName;
		int _employeeNumber = -1;
		int _salary = DefaultStartingSalary;
		bool _isHired = false;

	};
}


