/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:57:55 by lgrisel           #+#    #+#             */
/*   Updated: 2025/08/26 15:17:07 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "\n--- Default Form creation ---" << std::endl;
	Form def;
	std::cout << def << std::endl;

	std::cout << "\n--- Valid Form creation ---" << std::endl;
	Form taxForm("TaxForm", false, 50, 25);
	std::cout << taxForm << std::endl;

	std::cout << "\n--- Bureaucrat signs the form (success) ---" << std::endl;
	Bureaucrat alice("Alice", 30);
	alice.signForm(taxForm);
	std::cout << taxForm << std::endl;

	std::cout << "\n--- Bureaucrat tries to sign already signed form (should still work) ---" << std::endl;
	alice.signForm(taxForm);

	std::cout << "\n--- Bureaucrat too low to sign ---" << std::endl;
	Bureaucrat bob("Bob", 60);
	Form ndaForm("NDAForm", false, 50, 20);
	bob.signForm(ndaForm);
	std::cout << ndaForm << std::endl;

	std::cout << "\n--- Invalid Form creation (sign grade too high) ---" << std::endl;
	try {
		Form illegalForm("IllegalForm", false, 0, 20);
	} catch (const std::exception &e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- Invalid Form creation (exec grade too low) ---" << std::endl;
	try {
		Form illegalForm("IllegalForm", false, 50, 151);
	} catch (const std::exception &e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- Copy constructor and assignment operator ---" << std::endl;
	Form original("OriginalForm", true, 42, 24);
	Form copy = original;
	std::cout << "Copy (via copy constructor):\n" << copy << std::endl;

	Form assigned("AssignedForm", false, 100, 100);
	assigned = original;
	std::cout << "Assigned (via operator=):\n" << assigned << std::endl;
}