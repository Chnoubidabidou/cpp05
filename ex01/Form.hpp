/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:24:32 by lgrisel           #+#    #+#             */
/*   Updated: 2025/08/26 15:15:55 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	class GradeTooHighException : public std::exception
	{
		public:
			char const	*what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			char const	*what() const throw();
	};

	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

	public:
		Form(const std::string &name = "unnamed", bool signed_ = false, int signGrade = 1, int execGrade = 1);
		Form(const Form &copy);
		~Form();

		Form	&operator=(const Form &copy);

		const std::string	&getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		void				beSigned(const Bureaucrat &bureaucrat);

};
std::ostream	&operator<<(std::ostream &stream, const Form &form);
