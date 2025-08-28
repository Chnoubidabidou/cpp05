/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:57:55 by lgrisel           #+#    #+#             */
/*   Updated: 2025/08/28 11:37:35 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "\n--- Testing ShrubberyCreationForm ---" << std::endl;
	try
	{
		Bureaucrat gardener("Gardener", 130);
		ShrubberyCreationForm shrub("home");

		gardener.signForm(shrub);
		gardener.executeForm(shrub);
	}
	catch (const std::exception &e)
	{
		std::cerr << "❌ Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Testing RobotomyRequestForm ---" << std::endl;
	try
	{
		Bureaucrat technician("Technician", 45);
		RobotomyRequestForm robot("Bender");

		technician.signForm(robot);
		for (int i = 0; i < 3; ++i)
			technician.executeForm(robot);
	}
	catch (const std::exception &e)
	{
		std::cerr << "❌ Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Testing PresidentialPardonForm ---" << std::endl;
	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Ford Prefect");

		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (const std::exception &e)
	{
		std::cerr << "❌ Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Testing form not signed ---" << std::endl;
	try
	{
		Bureaucrat junior("Junior", 1);
		PresidentialPardonForm unsignedForm("Nobody");
		junior.executeForm(unsignedForm);
	}
	catch (const std::exception &e)
	{
		std::cerr << "❌ Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Testing insufficient execution grade ---" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		ShrubberyCreationForm shrub("office");

		intern.signForm(shrub);
		intern.executeForm(shrub);
	}
	catch (const std::exception &e)
	{
		std::cerr << "❌ Error: " << e.what() << std::endl;
	}
}