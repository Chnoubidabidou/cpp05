/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:24:32 by lgrisel           #+#    #+#             */
/*   Updated: 2025/08/27 15:46:55 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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

	class FormNotSignedException : public std::exception
	{
		public:
			const char	*what() const throw();
	};

	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

	protected:
		virtual void	doAction() const = 0;

	public:
		AForm(const std::string &name = "unnamed", bool signed_ = false, int signGrade = 1, int execGrade = 1);
		AForm(const AForm &copy);
		virtual ~AForm();

		AForm	&operator=(const AForm &copy);

		const std::string	&getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		void				beSigned(const Bureaucrat &bureaucrat);
		void				execute(const Bureaucrat &executor) const;

};
std::ostream	&operator<<(std::ostream &stream, const AForm &form);
