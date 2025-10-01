/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:12:56 by msuokas           #+#    #+#             */
/*   Updated: 2025/09/30 10:55:11 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
	}
	catch (std::exception &e) {
		std::cout << "Couldn't sign " << form.getName() << "because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other)
{
	os << other.getName()
	<< ", bureaucrat grade "
	<< other.getGrade()
	<< std::endl;
	return (os);
}
