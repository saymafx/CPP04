/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidigov <tidigov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:11:26 by tidigov           #+#    #+#             */
/*   Updated: 2023/05/03 20:28:09 by tidigov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//BASE CLASS: ANIMAL

Animal::Animal(void)
{
	std::cout << "Default Animal constructor called" << std::endl;
	this->type = "Unspecified";
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
	return;
}

Animal::Animal(const std::string& target_name)
{
	(void)target_name;
	std::cout << "Animal constructor  called" << std::endl;
	this->type = "Unspecified";
}

Animal::Animal(Animal const &cpy)
{
	std::cout << "Animal copy constructor called " << std::endl;
    *this = cpy;
}

std::string const   Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "Animal sound???" << std::endl;
}

Animal &Animal::operator=(Animal const &rhs)
{
    if (this != &rhs)
        this->type = rhs.type;
    return (*this);
}

//SUBCLASS: CAT

Cat::Cat(void)
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->type = "Cat";
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	return;
}

Cat::Cat(const std::string& target_name)
{
	(void)target_name;
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(Cat const &cpy) : Animal(cpy)
{
	std::cout << "Cat copy constructor called " << std::endl;
    *this = cpy;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow, Pussy" << std::endl;
}

Cat &Cat::operator=(Cat const &rhs)
{
    if (this != &rhs)
        this->type = rhs.type;
    return (*this);
}

//SUBCLASS: DOG

Dog::Dog(void)
{
	std::cout << "Default Dog constructor called" << std::endl;
	this->type = "Dog";
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	return;
}

Dog::Dog(const std::string& target_name)
{
	(void)target_name;
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(Dog const &cpy) : Animal(cpy)
{
	std::cout << "Dog copy constructor called " << std::endl;
    *this = cpy;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof, Dawg" << std::endl;
}

Dog &Dog::operator=(Dog const &rhs)
{
    if (this != &rhs)
        this->type = rhs.type;
    return (*this);
}