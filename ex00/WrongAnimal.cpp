/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidigov <tidigov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:16:00 by tidigov           #+#    #+#             */
/*   Updated: 2023/05/03 17:16:54 by tidigov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//BASE CLASS: Wrong ANIMAL

WrongAnimal::WrongAnimal(void)
{
	std::cout << "Default  Wrong Animal constructor called" << std::endl;
	this->type = "Unspecified";
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Wrong Animal destructor called" << std::endl;
	return;
}

WrongAnimal::WrongAnimal(const std::string& target_name)
{
	(void)target_name;
	std::cout << "Wrong Animal constructor  called" << std::endl;
	this->type = "Unspecified";
}

WrongAnimal::WrongAnimal(WrongAnimal const &cpy)
{
	std::cout << "Wrong Animal copy constructor called " << std::endl;
    *this = cpy;
}

std::string const   WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong Animal sound???" << std::endl;
}

//SUBCLASS: CAT

WrongCat::WrongCat(void)
{
	std::cout << "Default Wrong Cat constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::~WrongCat(void)
{
	std::cout << "Wrong Cat destructor called" << std::endl;
	return;
}

WrongCat::WrongCat(const std::string& target_name)
{
	(void)target_name;
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
}

WrongCat::WrongCat(WrongCat const &cpy) : WrongAnimal(cpy)
{
	std::cout << "Wrong Cat copy constructor called " << std::endl;
    *this = cpy;
}
