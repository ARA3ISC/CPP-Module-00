/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:54:04 by maneddam          #+#    #+#             */
/*   Updated: 2023/06/09 15:21:50 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
	PhoneBook book;
	std::string choice;
	while (1)
	{
		std::cout << "\033[33mEnter your choice (ADD | SEARCH | EXIT) : " << RESET;
		if (getline(std::cin, choice).eof())
			exit(555);
		else if (choice == "ADD") {
			book.add();
			book.contactsCount++;
		}
		else if (choice == "SEARCH") {
			if (book.contactsCount > 0)
				book.search();
			else
				std::cout<< RED << " -> The book is Empty! Add some contacts.\n" << RESET;
		}
		else if (choice == "EXIT")
			exit(EXIT_SUCCESS);
		else
			std::cout << RED << " -> Wrong choice\n" << RESET;

	}
}
