/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:57:55 by lgrisel           #+#    #+#             */
/*   Updated: 2025/08/27 15:46:26 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "\n=== Intern Tests ===\n";
	Intern intern;

	AForm* f1 = intern.makeForm("Shrubbery Creation", "tree");
	if (f1)
	{
		Bureaucrat gardener("Gardener", 137);
		gardener.signForm(*f1);
		gardener.executeForm(*f1);
		delete f1;
	}

	AForm* f2 = intern.makeForm("Robotomy Request", "Marvin");
	if (f2)
	{
		Bureaucrat roboguy("Robo", 45);
		roboguy.signForm(*f2);
		roboguy.executeForm(*f2);
		delete f2;
	}

	AForm* f3 = intern.makeForm("Presidential Pardon", "Zoidberg");
	if (f3)
	{
		Bureaucrat prez("Prez", 1);
		prez.signForm(*f3);
		prez.executeForm(*f3);
		delete f3;
	}

	AForm* fail = intern.makeForm("FormThatDoesNotExist", "Nobody");
	if (!fail)
		std::cout << "Returned nullptr for unknown form as expected.\n";

	std::cout << "\n✅ All tests completed.\n";
}