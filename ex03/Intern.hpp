/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:13:26 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/01 13:40:12 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

class Intern : public Bureaucrat {
	public:
		Intern();
		~Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other) = delete;

		AForm* makeForm(const std::string& formName, const std::string& formTarget);
		class InternException : public std::exception {
			const char *what() const throw();
		};
};
