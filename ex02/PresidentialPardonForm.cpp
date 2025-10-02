/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:56:47 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/02 14:20:29 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("DefaultPersidentialPardon", 25, 5), _target("default_target"){
	std::cout << "PresidentialPardonForm with target " << _target << " was created"  << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm with " << _target << " was trown into bin"  << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("PresidentialPardon", 25, 5), _target(target){
	std::cout << "PresidentialPardonForm with target " << _target << " was created"  << std::endl;
}

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
