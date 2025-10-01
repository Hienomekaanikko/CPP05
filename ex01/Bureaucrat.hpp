/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:13:24 by msuokas           #+#    #+#             */
/*   Updated: 2025/09/29 16:05:18 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Form;

class Bureaucrat {
	private:
		const std::string	_name;
		int	_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, const int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other) = delete;
		~Bureaucrat();

		const std::string getName() const;
		int getGrade() const;
		void increment();
		void decrement();
		void signForm(Form& form);

		class GradeTooHighException : public std::exception {
			const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream& os, Bureaucrat const &other);
