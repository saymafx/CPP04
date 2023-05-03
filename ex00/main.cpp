/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidigov <tidigov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:09:22 by tidigov           #+#    #+#             */
/*   Updated: 2023/05/03 17:17:31 by tidigov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"

int	main()
{
	const Animal* meta = new Animal();
    const Animal* i = new Cat();
    const Animal* j = new Dog();

    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

	delete meta;
	delete i;
	delete j;

	const WrongAnimal* metaa = new WrongCat();
    metaa->makeSound();
    delete metaa;
	
	return 0;
}