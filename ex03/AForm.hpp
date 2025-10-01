/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:17:00 by msuokas           #+#    #+#             */
/*   Updated: 2025/09/29 16:03:59 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

class AForm {
	private:
		const std::string _name;
		bool _signed;
		const int _grade;
		const int _execGrade;
		virtual void action() const = 0;
	public:
		AForm();
		AForm(const std::string& name, const int grade, const int execGrade);
		~AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other) = delete;

		std::string getName() const;
		bool getSignedStatus() const;
		int getGrade() const;
		int getExecGrade() const;
		void beSigned(Bureaucrat& SuitGuy);
		int validateGrade(const int grade);
		void execute(Bureaucrat const & executor) const;

		class GradeTooHighException : public std::exception {
			const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char *what() const throw();
		};
		class FormNotSignedException : public std::exception {
			const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream& os, AForm const &other);
