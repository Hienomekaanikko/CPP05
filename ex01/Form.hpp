/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:17:00 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/02 13:25:50 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string _name;
		bool _signed;
		const int _grade;
		const int _execGrade;
	public:
		Form();
		Form(const std::string& name, const int grade, const int execGrade);
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other) = delete;

		std::string getName() const;
		bool getSignedStatus() const;
		int getGrade() const;
		int getExecGrade() const;
		void beSigned(Bureaucrat& SuitGuy);
		int validateGrade(const int grade);

		class GradeTooHighException : public std::exception {
			const char *what() const noexcept override;
		};
		class GradeTooLowException : public std::exception {
			const char *what() const noexcept override;
		};
		class AlreadySignedException : public std::exception {
			const char *what() const noexcept override;
		};
};

std::ostream &operator<<(std::ostream& os, Form const &other);
