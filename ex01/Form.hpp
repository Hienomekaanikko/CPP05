/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:26:01 by msuokas           #+#    #+#             */
/*   Updated: 2025/09/19 14:31:03 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

class Form: public Bureaucrat {
	private:
		const std::string _name;
		bool _isSigned;
		int _grade;
	public:
		Form();
		Form(const std::string& name, const bool status, const int grade);
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);

		std::string getName() const;
		bool getStatus() const;
		int getGrade() const;
		void beSigned(Bureaucrat& suitguy);
};

std::ostream &operator<<(std::ostream & os, Form const &other);
