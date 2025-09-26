/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 10:16:01 by msuokas           #+#    #+#             */
/*   Updated: 2025/09/26 12:58:34 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>
#include <time.h>

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
		virtual void action() const;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		std::string& getTarget();
		class RobotomizationException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};
