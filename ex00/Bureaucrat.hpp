/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:57:54 by lgrisel           #+#    #+#             */
/*   Updated: 2025/07/17 16:48:15 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat
{
	class GradeTooHighException : public std::exception
	{
		public:
			char const  *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			char const  *what() const throw();
	};

	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(std::string name = "unamed", int grade = 150);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();

		Bureaucrat	&operator=(const Bureaucrat &copy);

		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade(void);
		void		decrementGrade(void);

};

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &bureaucrat);