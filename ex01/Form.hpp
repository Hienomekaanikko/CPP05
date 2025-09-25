/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:26:01 by msuokas           #+#    #+#             */
/*   Updated: 2025/09/25 12:23:51 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int _grade;
		const int _execGrade;
	public:
		Form();
		Form(const std::string& name, const bool status, const int grade, const int execGrade);
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);

		std::string getName() const;
		bool getStatus() const;
		int getGrade() const;
		void beSigned(Bureaucrat& suitguy);
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class AlreadySignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream & os, Form const &other);
