/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidigov <tidigov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:16:27 by tidigov           #+#    #+#             */
/*   Updated: 2023/05/03 17:16:39 by tidigov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal(void);
		virtual ~WrongAnimal(void);
		WrongAnimal(const std::string& target_name);
		WrongAnimal(WrongAnimal const &cpy);

		virtual void        makeSound() const;
        std::string const   getType() const;
};

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		~WrongCat(void);
		WrongCat(const std::string& target_name);
		WrongCat(WrongCat const &cpy);
};