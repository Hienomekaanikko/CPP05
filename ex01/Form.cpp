/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:26:03 by msuokas           #+#    #+#             */
/*   Updated: 2025/09/19 14:33:40 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("default"), _isSigned(0), _grade(0) {}

Form::Form(const std::string& name, const bool status, const int grade): _name(name), _isSigned(status) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}

Form::~Form() {}

Form::Form(const Form& other): _name(other._name), _isSigned(other._isSigned), _grade(other._grade) {}

Form& Form::operator=(const Form& other) {
	if (this != &other){
		_isSigned = other._isSigned;
		_grade = other._grade;
	}
	return *this;
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
		_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, Form const &other)
{
	os << other.getName() << ", grade required " << other.getGrade() << ", signature status " << other.getStatus() << "\n";
	return (os);
}
