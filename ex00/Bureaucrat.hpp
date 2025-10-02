/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:13:24 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/02 10:28:16 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

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

		class GradeTooHighException : public std::exception {
			const char *what() const noexcept override;
		};
		class GradeTooLowException : public std::exception {
			const char *what() const noexcept override;
		};
};

std::ostream &operator<<(std::ostream& os, Bureaucrat const &other);
