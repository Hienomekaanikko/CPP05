/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:17:02 by msuokas           #+#    #+#             */
/*   Updated: 2025/09/30 10:52:30 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("defaultForm"), _signed(false), _grade(1), _execGrade(10) {}

int Form::validateGrade(const int grade) {
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	return grade;
}

Form::Form(const std::string& name, const int grade, const int execGrade):
	_name(name),
	_grade(validateGrade(grade)),
	_execGrade(validateGrade(execGrade)) {
		_signed = false;
	}

Form::~Form() {}

Form::Form(const Form& other):
	_name(other._name),
	_signed(other._signed),
	_grade(other._grade),
	_execGrade(other._execGrade) {}

std::string Form::getName() const {
	return _name;
}

bool Form::getSignedStatus() const {
	return _signed;
}

int Form::getGrade() const {
	return _grade;
}

int Form::getExecGrade() const {
	return _execGrade;
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form: Grade too low";
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form: Grade too high";
}

void Form::beSigned(Bureaucrat& SuitGuy) {
	if (SuitGuy.getGrade() > _grade)
		throw GradeTooLowException();
	_signed = true;
	std::cout << SuitGuy.getName() << " signed the " << _name << "\n";
}

std::ostream &operator<<(std::ostream &os, Form const &other)
{
	os << other.getName()
	<< ", signing grade: "
	<< other.getGrade()
	<< ", execution grade: "
	<< other.getExecGrade()
	<< ", signed status: "
	<< other.getSignedStatus() << std::endl;
	return (os);
}
