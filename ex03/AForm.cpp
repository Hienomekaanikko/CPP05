/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:17:02 by msuokas           #+#    #+#             */
/*   Updated: 2025/09/30 10:52:30 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("defaultForm"), _signed(false), _grade(1), _execGrade(10) {
	std::cout << "AForm " << _name << " was created"  << std::endl;
}

int AForm::validateGrade(const int grade) {
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	return grade;
}

AForm::AForm(const std::string& name, const int grade, const int execGrade):
	_name(name),
	_grade(validateGrade(grade)),
	_execGrade(validateGrade(execGrade)) {
		_signed = false;
		std::cout << "AForm " << _name << " was created"  << std::endl;
	}

AForm::~AForm() {
	std::cout << "AForm " << _name << " was thrown into bin"  << std::endl;
}

AForm::AForm(const AForm& other):
	_name(other._name),
	_signed(other._signed),
	_grade(other._grade),
	_execGrade(other._execGrade) {}

std::string AForm::getName() const {
	return _name;
}

bool AForm::getSignedStatus() const {
	return _signed;
}

int AForm::getGrade() const {
	return _grade;
}

int AForm::getExecGrade() const {
	return _execGrade;
}

const char* AForm::GradeTooLowException::what() const noexcept  {
	return "grade too low";
}

const char* AForm::GradeTooHighException::what() const noexcept  {
	return "grade too high";
}

const char* AForm::FormNotSignedException::what() const noexcept  {
	return "form is not signed for execution";
}

const char* AForm::AlreadySignedException::what() const noexcept {
	return "the form is already signed";
}

void AForm::beSigned(Bureaucrat& SuitGuy) {
	if (SuitGuy.getGrade() > _grade)
		throw GradeTooLowException();
	if (_signed == true)
		throw AlreadySignedException();
	_signed = true;
	std::cout <<  "\033[1;36m" << SuitGuy.getName() << " signed the " << _name << "\n" << "\033[0m";
}

std::ostream &operator<<(std::ostream &os, AForm const &other)
{
	os << "\033[1;36m"
	<< "Form status: "
	<< other.getName()
	<< ", signing grade: "
	<< other.getGrade()
	<< ", execution grade: "
	<< other.getExecGrade()
	<< ", signed status: "
	<< other.getSignedStatus()
	<< "\033[0m" << std::endl;
	return (os);
}

void AForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	if (getSignedStatus() == false)
		throw FormNotSignedException();
	action();
	std::cout << "\033[1;36m" << executor.getName() << " excecuted " << getName() << "\033[0m" << std::endl;
}
