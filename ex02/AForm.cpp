/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:26:03 by msuokas           #+#    #+#             */
/*   Updated: 2025/09/26 10:03:22 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

static int validateGrade(int grade) {
	if (grade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > 150)
		throw AForm::GradeTooLowException();
	return grade;
}

AForm::AForm(): _name("default"), _isSigned(0), _grade(0), _execGrade(0) {}

AForm::AForm(const std::string& name, const int grade, const int execGrade): _name(name), _isSigned(false), _grade(validateGrade(grade)), _execGrade(validateGrade(execGrade)) {}

AForm::~AForm() {}

AForm::AForm(const AForm& other): _name(other._name), _isSigned(other._isSigned), _grade(other._grade), _execGrade(other._execGrade) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other){
		_isSigned = other._isSigned;
	}
	return *this;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

std::string AForm::getName() const {
	return _name;
}

bool AForm::getStatus() const {
	return _isSigned;
}

int AForm::getGrade() const {
	return _grade;
}

void AForm::beSigned(Bureaucrat& suitguy) {
	if (suitguy.getGrade() <= _grade)
	{
		_isSigned = true;
		std::cout << suitguy.getName() << " signed " << this->getName() << std::endl;
	}
	else
	{
		std::cout << suitguy.getName() << " cannot sign: ";
		throw GradeTooLowException();
	}
}

void AForm::execute(Bureaucrat const& executor) const {
	if (this->_isSigned)
	{
		if (this->_execGrade >= executor.getGrade())
		{
			std::cout << executor.getName() << " executed " << this->getName() << "\n";
			this->action();
		}
		else
			std::cout << "Cannot execute " << this->getName() << ": Too low grade for execution.";
	}
	else
		std::cout << "Cannot execute " << this->getName() << ": Not signed.\n";
}

std::ostream &operator<<(std::ostream &os, AForm const &other)
{
	os << other.getName() << ", grade required to sign: " << other.getGrade() << ", signature status: " << other.getStatus() << ", grade required for execution: " << other.getExecGrade() << "\n";
	return (os);
}

int AForm::getExecGrade() const {
	return _execGrade;
}
