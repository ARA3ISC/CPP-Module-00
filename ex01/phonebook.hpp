#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include <iostream>
#include <iomanip>

# define RED "\033[31m"
#define GREEN "\033[92m"
#define RESET "\033[0m"
#define CYAN "\033[96m"



class Contacts {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darksetSecret;

	public:
		void	fillattr();
		std::string get_var(std::string var);
};

class PhoneBook {
	private:
		Contacts contacts[8];
	public:
		int			contactsCount;
		void		add();
		void		search();
		void		showFullBook();
		std::string	getField(std::string field, int i);
		void	putOnScreen(int i);
		void	printContactByIndex(int index);

	PhoneBook() {
		contactsCount = 0;
	}
};


#endif
