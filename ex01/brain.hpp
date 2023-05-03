/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidigov <tidigov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:12:24 by tidigov           #+#    #+#             */
/*   Updated: 2023/05/03 17:18:32 by tidigov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
    public:
        Brain(void);
        ~Brain(void);
		Brain(const std::string& target_name);
        Brain(const Brain &cpy);

        Brain           &operator=(Brain const& eq);
        std::string     *get_ideas(void) const;
        
    protected:
        std::string  *_ideas;
};