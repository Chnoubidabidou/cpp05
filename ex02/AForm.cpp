/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:24:34 by lgrisel           #+#    #+#             */
/*   Updated: 2025/08/27 15:10:38 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high exception");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low exception");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed exception");
}

AForm::AForm(const std::string &name, bool signed_, int signGrade, int execGrade): _name(name), _signed(signed_), _signGrade(signGrade), _execGrade(execGrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw (AForm::GradeTooHighException());
	if (_signGrade > 150 || _execGrade > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(const AForm &copy): _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
}

AForm::~AForm(void)
{
}

AForm	&AForm::operator=(const AForm &copy)
{
	this->_signed = copy._signed;
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, const AForm &form)
{
	stream << "form " << form.getName() << std::endl
	<< "is signed : " << form.getSigned() << std::endl
	<< "minimum grade to sign : " << form.getSignGrade() << std::endl
	<< "minimum grade to execute : " << form.getExecGrade();
	return (stream);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (!_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	this->doAction();
}

const std::string	&AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSigned(void) const
{
	return (this->_signed);
}

int	AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	AForm::getExecGrade(void) const
{
	return (this->_execGrade);
}