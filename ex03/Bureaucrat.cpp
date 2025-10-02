/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:12:56 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/02 14:33:57 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(1) {
	std::cout << "Bureaucrat " << getName() << " was created successfully!" << "\n";
}

Bureaucrat::Bureaucrat(const std::string& name, const int grade): _name(name), _grade(grade){
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	std::cout << "Bureaucrat " << getName() << " was created successfully!" << "\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << getName() << " got fired" << "\n";
}

void Bureaucrat::increment() {
	std::cout << "Trying to increment the grade of " << _name << " by 1" << std::endl;
	if (_grade == 1)
		throw GradeTooHighException();
	std::cout << "Incremented the grade of " << _name << " by 1"  << std::endl;
	_grade--;
}

void Bureaucrat::decrement() {
	std::cout << "Trying to decrement the grade of " << _name << " by 1" << std::endl;
	if (_grade == 150)
		throw GradeTooLowException();
	std::cout << "Decremented the grade of " << _name << " by 1" << std::endl;
	_grade++;
}

const std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return "grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return "grade is too low";
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
	}
	catch (std::exception &e) {
		std::cout << "Exception: could not sign " << form.getName() << " because " << e.what() << std::endl;
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
		std::cout << "Exception: cannot execute because " << e.what() << std::endl;
	}
}
