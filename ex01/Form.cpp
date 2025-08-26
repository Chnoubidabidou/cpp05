/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:24:34 by lgrisel           #+#    #+#             */
/*   Updated: 2025/08/26 15:15:57 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char  *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high exception");
}

const char  *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low exception");
}

Form::Form(const std::string &name, bool signed_, int signGrade, int execGrade): _name(name), _signed(signed_), _signGrade(signGrade), _execGrade(execGrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw (Form::GradeTooHighException());
	if (_signGrade > 150 || _execGrade > 150)
		throw (Form::GradeTooLowException());
}

Form::Form(const Form &copy): _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
}

Form::~Form(void)
{
}

Form	&Form::operator=(const Form &copy)
{
	this->_signed = copy._signed;
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, const Form &form)
{
	stream << "form " << form.getName() << std::endl
	<< "is signed : " << form.getSigned() << std::endl
	<< "minimum grade to sign : " << form.getSignGrade() << std::endl
	<< "minimum grade to execute : " << form.getExecGrade();
	return (stream);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

const std::string	&Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

int	Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	Form::getExecGrade(void) const
{
	return (this->_execGrade);
}