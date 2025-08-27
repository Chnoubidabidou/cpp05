/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:23:58 by lgrisel           #+#    #+#             */
/*   Updated: 2025/08/27 15:12:13 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("Robotomy Request", false, 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm(copy), _target(copy._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	*static_cast<AForm *>(this) = copy;
	this->_target = copy._target;
	return (*this);
}

void	RobotomyRequestForm::doAction(void) const
{
	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized" << std::endl;
	else
		std::cout << "The robotomy has failed" << std::endl;
}