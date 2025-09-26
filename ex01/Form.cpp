/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:26:03 by msuokas           #+#    #+#             */
/*   Updated: 2025/09/26 10:47:37 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

static int validateGrade(int grade) {
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
	return grade;
}

Form::Form(): _name("default"), _isSigned(0), _grade(0), _execGrade(0) {}

Form::Form(const std::string& name, const int grade, const int execGrade): _name(name), _isSigned(false), _grade(validateGrade(grade)), _execGrade(validateGrade(execGrade)) {}

Form::~Form() {}

Form::Form(const Form& other): _name(other._name), _isSigned(other._isSigned), _grade(other._grade), _execGrade(other._execGrade) {}

Form& Form::operator=(const Form& other) {
	if (this != &other){
		_isSigned = other._isSigned;
	}
	return *this;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

std::string Form::getName() const {
	return _name;
}

bool Form::getStatus() const {
	return _isSigned;
}

int Form::getGrade() const {
	return _grade;
}

void Form::beSigned(Bureaucrat& suitguy) {
	if (suitguy.getGrade() <= _grade)
	{
		_isSigned = true;
		std::cout << suitguy.getName() << " signed " << this->getName() << std::endl;
	}
	else
	{
		std::cout << "Failed: ";
		throw GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &os, Form const &other)
{
	os << other.getName() << ", grade required to sign: " << other.getGrade() << ", signature status: " << other.getStatus() << ", grade required for execution: " << other.getExecGrade() << "\n";
	return (os);
}

int Form::getExecGrade() const {
	return _execGrade;
}
