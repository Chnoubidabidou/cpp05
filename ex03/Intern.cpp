/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:40:26 by lgrisel           #+#    #+#             */
/*   Updated: 2025/08/27 15:44:03 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern::~Intern(void)
{
}

Intern	&Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

static AForm	*createShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}


static AForm	*createRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm    *createPardon(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
	const FormMap forms[] = {
		{"Shrubbery Creation", createShrubbery},
		{"Robotomy Request", createRobotomy},
		{"Presidential Pardon", createPardon},
		{NULL, NULL}
	};

	for (size_t i = 0; forms[i].name != NULL; ++i)
	{
		if (forms[i].name == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return forms[i].create(target);
		}
	}
	std::cout << "Intern could not create " << name << ": form doesn't exist" << std::endl;
	return NULL;
}