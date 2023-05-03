/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidigov <tidigov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:12:26 by tidigov           #+#    #+#             */
/*   Updated: 2023/05/03 17:18:18 by tidigov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Brain::Brain(void) : _ideas(new std::string[100])
{
	std::cout << "Default Brain constructor called" << std::endl;
	return;
}

Brain::~Brain(void)
{
	delete [] this->_ideas;
	std::cout << "Brain destructor called" << std::endl;
	return;
}

Brain::Brain(const std::string& target_name) : _ideas(new std::string[100])
{
	(void)target_name;
	std::cout << "Brain constructor called" << std::endl;
	return;
}

Brain::Brain(const Brain &cpy) : _ideas(new std::string[100])
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = cpy;
	return; 
}

std::string     *Brain::get_ideas(void) const
{
	return (this->_ideas);
}


Brain    &Brain::operator = (Brain const &op)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = op.get_ideas()[i];
	return *this;
}