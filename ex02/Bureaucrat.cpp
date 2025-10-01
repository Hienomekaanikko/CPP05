/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:12:56 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/01 11:17:21 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(1) {}

Bureaucrat::Bureaucrat(const std::string& name, const int grade): _name(name), _grade(grade){
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::increment() {
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::decrement() {
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

const std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Buraeucrat: Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat: Grade is too low";
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
	}
	catch (std::exception &e) {
		std::cout << "Couldn't sign " << form.getName() << "because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other)
{
	os << "\033[1;36m"
	<< "Bureaucrat status: "
	<< other.getName()
	<< ", bureaucrat grade "
	<< other.getGrade()
	<< "\033[0m"
	<< std::endl;
	return (os);
}

void Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
