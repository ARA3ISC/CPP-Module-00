/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:48:21 by maneddam          #+#    #+#             */
/*   Updated: 2023/06/06 23:36:46 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <string>

std::string	getdata()
{
	std::string str;
	getline(std::cin, str);
	return str;
}

void	Contacts::fillattr()
{
	firstName = getdata();
	std::cout << "done\n";
}
