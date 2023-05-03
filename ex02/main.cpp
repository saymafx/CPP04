/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidigov <tidigov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:09:32 by tidigov           #+#    #+#             */
/*   Updated: 2023/05/03 17:21:46 by tidigov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

int main()
{   
    Animal *lol = new Animal ();
    lol->makeSound();
    // Animal* animals[10];
    // for (int i = 0; i < 5; i++) {
    //     animals[i] = new Dog();
    //     animals[i+5] = new Cat();
    // }

    // for (int i = 0; i < 10; i++) {
    //     animals[i]->makeSound();
    //     delete animals[i];
    // }
    return 0;
}