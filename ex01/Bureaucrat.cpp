/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:12:56 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/02 14:15:41 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
