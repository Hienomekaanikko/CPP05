/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:56:51 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/01 15:06:28 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("DefaultShrubberyRequestForm", 145, 137), _target("DefaultTarget"){}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyRequestForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): _target(other._target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		_target = other._target;
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const {
	return _target;
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
