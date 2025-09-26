/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 10:16:04 by msuokas           #+#    #+#             */
/*   Updated: 2025/09/26 14:05:50 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyDefaultForm", 145, 137), _target("DefaultTarget") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) {
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	_target = other._target;
	return *this;
}

const char* ShrubberyCreationForm::ShrubberyException::what() const throw() {
	return "ShrubberyCreation failed";
}

void ShrubberyCreationForm::action() const {
	std::ofstream outFile(_target + "_shrubbery");
	if (!outFile)
		throw std::runtime_error("Failed to create file");
	outFile << "                                                 ▍▌▌▋▋▋" << std::endl;
	outFile << "                                               ▊▋▋▎▎▌ ▊▁▊" << std::endl;
	outFile << "                                             ▍▍▁▏      ▎▊▃▊▏▏" << std::endl;
	outFile << "                                           ▏▌▉▍▏        ▏▉▅█▆▎" << std::endl;
	outFile << "                                          ▌▉▍▏         ▍▍▄████▉" << std::endl;
	outFile << "                                         ▏▊▁▏         ▎▅███████▃▍▊▎" << std::endl;
	outFile << "                                      ▏▋▊▁▌▏     ▏ ▏▍▊▇███████████▃" << std::endl;
	outFile << "                                    ▍▋▂▋ ▎▎▊▂▂▊▉▉▅▃▆██████████████▅▋▏" << std::endl;
	outFile << "                                 ▏▏▉▊ ▎     ▌▃████▆▄███████████████▇▍" << std::endl;
	outFile << "                                ▎▉▌▋▎        ▎▋▄▂▅█████████████████▄▋" << std::endl;
	outFile << "                               ▎▂▎             ▏▏▋▇███████████████▅▌" << std::endl;
	outFile << "                               ▋▉ ▏▏         ▏▍▋▇███████████████████▅▄▆▁" << std::endl;
	outFile << "                           ▍▏▋▊▉▄▂▄▆▊▏▋▎▏▏▊▅▍▉▇████████████████████████▇▆▍" << std::endl;
	outFile << "                        ▌▉▉▋▍▍▌▎ ▏▏▊▃▆▂▌▉▍▋▊████████████████████████████▇▍" << std::endl;
	outFile << "                     ▋▋▂▉ ▏         ▍▆███▅▆████▆▋▁████████████▆██████████▆▍▏▍▏" << std::endl;
	outFile << "                   ▍▉▊▏ ▎▏          ▏▃██████████████████▇█▅▊▏▌▌██████████▇▄▆█▂▎" << std::endl;
	outFile << "                  ▏▋▁▏            ▏▋▃██████▇████████▅▅▅█▊▅▍▌▌▌▋███████████████▉▎" << std::endl;
	outFile << "                  ▉▋▏            ▎▅███▂▊▊▉▌▏▉▄█████▃▌▊▅█▆▅███▇█████████████████▇▄▅▊▏" << std::endl;
	outFile << "                 ▎▃▍▋▎▏ ▏▏    ▎▋▂▉▇█▂▏▏    ▏ ▃█████████████████████████████████████▂" << std::endl;
	outFile << "               ▏▍▊▉▉▋▌▅▅▁▋▍▎▋▂▇███▅▍▏     ▏▉▅██████████████████████████████████████▄▎" << std::endl;
	outFile << "             ▌▉▋▉▍    ▎▃███████▃▊▁▁▏ ▎▏▏▏▋▆█▅▇██████████████████████████████████████▆▎" << std::endl;
	outFile << "           ▏▍▉▌        ▏▉████▄▎   ▏▌▂▆▊▃██▅▁▏▊██████████████████████████████████████▂▏" << std::endl;
	outFile << "           ▍▉▏        ▏▏▂▆███▄▏    ▎▉▅██▄▋▍▋▂███████████████████████████████████████▄▏" << std::endl;
	outFile << "           ▏▁       ▏▎▎▌▋▅█▊▏       ▌█████▇████▆█████████████████████████████████████▂" << std::endl;
	outFile << "        ▏▎▌▊▄▊▎▏▏▊▏▁▊▉▇███▃▎      ▌▌▎▉███████████████████████████████████████████████▇▄▌" << std::endl;
	outFile << "        ▁▍▎▏▏▏▃▃▇█████████▇▅▆▄▋▎▊▁▅▆▆█████████████████████▇█▃▅▃█████████████████████████▆▂▏" << std::endl;
	outFile << "      ▌▊▊▏     ▉████████████████████████████████████████▁▏▏▍▎  ▏▉▂████████████████████████▊▏▏" << std::endl;
	outFile << "      ▌▉▏ ▏▏▌▍▉▄▇▃▌▍▍▏▁▃█████████████████▅████████████▁▏        ▏▋██████████████████████████▃▊" << std::endl;
	outFile << "     ▏▌▅▄▎▁▆██▂▍▏     ▏▍▂▆██████████▄▋▍▍▋▉████████▂▍▁▌      ▏  ▌▂▇████████████████████████████▉" << std::endl;
	outFile << "    ▏▂▍▏▋▇██▇▉▏   ▏▍▎▌▍▉▅██████▇▇▅▉▉▏   ▍████████▅▎       ▏ ▍▅▄▆██████████████████████████████▄▎" << std::endl;
	outFile << "    ▊▋  ▎▄██▊    ▍▉▊▄█████████▆▍▏     ▏▋▆█████████▃▊▉▍▏ ▎▊▉▊▁▇██████████████████████████████████▉" << std::endl;
	outFile << "    ▂▅▌▌▇███▄▃▁▊▃▅███████████▇▉▎      ▌▇████████████▇█▅▃▇▁▇▄▁▏▋▅████████████████████████████████▉" << std::endl;
	outFile << "    ▍▅███████████████████████▅▍▌▌▏  ▍▄▅▇███████████████████▅▆▇▆████████████████████████████████▆▏" << std::endl;
	outFile << "     ▊▃▄▄▇███████████████████████▆▇▅████████████████████████████████████████████████████████▇▇▇▁▋▏▏" << std::endl;
	outFile << "          ▋▋▋▋▊▅▅▅▅▅▅▅▆█████████████████████████████████████████████████████████▇▆▆▆▅▅▅▅▅▅▊▌" << std::endl;
	outFile << "                      ▏▍▍▌▌▌▌▌▁▃▃▃▃▃▃▄▄▄▄▄▄▄▅▆▇▇▇▆▅▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▃▃▃▃▂▋▋▋▋▌▌▌▌▍▎▏▎" << std::endl;
	outFile.close();
}

std::string& ShrubberyCreationForm::getTarget() {
	return _target;
}
