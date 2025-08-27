/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:24:00 by lgrisel           #+#    #+#             */
/*   Updated: 2025/08/27 15:11:39 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("Shrubbery Creation", false, 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm(copy), _target(copy._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	*static_cast<AForm *>(this) = copy;
	this->_target = copy._target;
	return (*this);
}

void	ShrubberyCreationForm::doAction(void) const
{
	std::string		filename(this->_target + "_shrubbery");
	std::ofstream	file;

	file.open(filename.c_str());
	if (!file.is_open())
		std::cerr << "shrubbery: " << filename << ": " << std::strerror(errno) << std::endl;
	else
		file << ASCII_TREE;
}