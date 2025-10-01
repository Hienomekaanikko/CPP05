/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:56:47 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/01 09:51:55 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("DefaultPersidentialPardon", 25, 5), _target("default_target"){}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("PresidentialPardon", 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): _target(other._target){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other)
		_target = other._target;
	return *this;
}

void PresidentialPardonForm::action() const {
	std::cout <<  "\033[1;36m" << _target << " has been pardoned by Zaphod Beeblebrox" << "\033[0m" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const {
	return _target;
}
