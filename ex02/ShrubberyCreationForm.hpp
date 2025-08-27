/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:24:01 by lgrisel           #+#    #+#             */
/*   Updated: 2025/08/27 15:25:38 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <cstring>
#include "AForm.hpp"

#define ASCII_TREE \
"⠀⠀⠀⠀⠀⠀⠀⢀⣀⡀⠀⠀⠀⢀⡀⡀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⡠⠇⠀⠈⢙⠉⠐⠅⠀⠀⡦⢄⠀⠀\n\
⠀⠀⠀⠀⢰⠁⠀⠑⠐⠀⠀⠀⠀⠀⠀⠀⠀⠾⢄⠀\n\
⠀⠀⠀⠊⠀⠀⠀⠀⠀⠀⠀⠄⢄⠀⠀⠀⠀⢀⡜⠁\n\
⠀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠀⠀⠀⠀⠀⡸⠀\n\
⠸⠀⠀⠀⠀⠀⠀⠀⠀⢀⠴⢠⡌⣀⠐⠀⠈⠘⠁⡄\n\
⠀⠄⠀⡀⠀⠀⠀⢠⣾⣃⠀⠁⠀⢙⣶⣀⠀⠀⠘⡧\n\
⠀⠀⠀⠀⠀⠔⠀⠘⠛⠀⠀⠀⢸⡾⠏⠀⠯⠀⠏⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠃⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠨⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⢠⡔⠂⠀⡀⠀⣀⠑⠤⢀⡀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠁⠀⠀⠈⠀⠀⠀⠀\n"


class ShrubberyCreationForm: public AForm
{
	protected:
		std::string	_target;

		void		doAction() const;

	public:
		ShrubberyCreationForm(const std::string &target = "nowhere");
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();

		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &copy);
};