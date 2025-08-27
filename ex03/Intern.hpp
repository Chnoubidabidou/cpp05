/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:40:25 by lgrisel           #+#    #+#             */
/*   Updated: 2025/08/27 15:43:25 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	protected:
		typedef AForm*	(*FormFactory)(const std::string &target);

		struct FormMap
		{
			const char *name;
			FormFactory create;
		};
		
	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();

		Intern	&operator=(const Intern &copy);

		static AForm	*makeForm(const std::string &name, const std::string &target);
};