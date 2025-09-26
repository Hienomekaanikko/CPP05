/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 10:15:55 by msuokas           #+#    #+#             */
/*   Updated: 2025/09/26 14:04:45 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonDefaultForm", 25, 5), _target("DefaultTarget") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("PresidentialPardon", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) {
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	_target = other._target;
	return *this;
}

const char* PresidentialPardonForm::PardonException::what() const throw() {
	return "Presidential pardon failed";
}

void PresidentialPardonForm::action() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << "\n";
}

std::string& PresidentialPardonForm::getTarget() {
	return _target;
}
