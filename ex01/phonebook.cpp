#include "phonebook.hpp"

std::string exitProgramCtrlD(std::string buffer)
{
	if (getline(std::cin, buffer).eof())
		exit(3);
	return buffer;
}

bool checkPhoneNumber(std::string phoneNumber)
{

	int i = 0;
	while (phoneNumber[i])
	{
		if (!std::isdigit(phoneNumber[i]))
			return (false);
		i++;
	}
	return (true);
}

bool isWhiteSpaces(std::string str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isspace(str[i]))
			return false;
	}
	return true;
}

std::string getData(std::string data)
{
	std::string str;
	do
	{
		std::cout << " -> Give the " << data << ": ";
		str = exitProgramCtrlD(str);
		if (str.length() == 0 || isWhiteSpaces(str))
			std::cout << RED << " -> Field must be filled !\n" << RESET;
	} while (str.length() == 0 || isWhiteSpaces(str));

	if (data == "phone number" && !checkPhoneNumber(str))
	{
		do
		{
			if (!checkPhoneNumber(str))
				std::cout << RED << " -> Invalid phone number !\n" << RESET;
			std::cout << " -> Give the " << data << ": ";
			str = exitProgramCtrlD(str);
		} while (!checkPhoneNumber(str));
	}
	return str;
}
void Contacts::fillattr()
{

	firstName = getData("first name");
	lastName = getData("last name");
	nickName = getData("nick name");
	phoneNumber = getData("phone number");
	darksetSecret = getData("darkset secret");
}

void PhoneBook::add()
{

	static int i;

	if (i == 8)
		i = 0;
	contacts[i].fillattr();
	if (i < 8)
		i++;
	std::cout << CYAN <<"\n -> Added successfuly \n\n" << RESET;
}

std::string Contacts::get_var(std::string var)
{

	if (var == "firstName")
		return firstName;
	if (var == "lastName")
		return lastName;
	if (var == "nickName")
		return nickName;
	if (var == "phoneNumber")
		return phoneNumber;
	if (var == "darksetSecret")
		return darksetSecret;
	return NULL;
}

std::string PhoneBook::getField(std::string field, int i)
{

	if (field == "firstName")
		return contacts[i].get_var("firstName");
	else if (field == "lastName")
		return contacts[i].get_var("lastName");
	else if (field == "nickName")
		return contacts[i].get_var("nickName");
	return NULL;
}

void printDots(std::string str)
{

	if (str.length() > 10)
		std::cout << std::setw(9) << str.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << str.substr(0, 9) << "|";
}

void PhoneBook::putOnScreen(int i)
{

	std::cout << "|" << std::setw(10) << i << "|";
	printDots(PhoneBook::getField("firstName", i));
	printDots(PhoneBook::getField("lastName", i));
	printDots(PhoneBook::getField("nickName", i));
	std::cout << std::endl;
}

int getContactIndex(int contactCount)
{

	std::string str;
	do
	{
		std::cout << " -> Enter index : ";
		str = exitProgramCtrlD(str);
		if (str.length() == 0 || !checkPhoneNumber(str))
			std::cout << RED << " -> Enter a valid index\n" << RESET;
	} while (str.length() == 0 || !checkPhoneNumber(str));

	do
	{
		if (atoi(str.c_str()) > contactCount - 1)
		{
			std::cout << RED << " -> Wrong index ! try again ..\n" << RESET;
			std::cout << " -> Enter index : ";
			str = exitProgramCtrlD(str);
		}
		if (atoi(str.c_str()) < 0)
		{
			std::cout << RED << " -> Index must be positive!\n" << RESET;
			std::cout << " -> Enter index : ";
			str = exitProgramCtrlD(str);
		}
	} while (atoi(str.c_str()) < 0 || atoi(str.c_str()) > contactCount - 1);
	return atoi(str.c_str());
}

void PhoneBook::printContactByIndex(int index)
{

	std::cout << "First name   : " << contacts[index].get_var("firstName") << std::endl;
	std::cout << "Last name    : " << contacts[index].get_var("lastName") << std::endl;
	std::cout << "Nick name    : " << contacts[index].get_var("nickName") << std::endl;
	std::cout << "Phone number : " << contacts[index].get_var("phoneNumber") << std::endl;
	std::cout << "Dark secret  : " << contacts[index].get_var("darksetSecret") << std::endl;
}

void PhoneBook::showFullBook()
{

	int index;
	std::cout << GREEN << "---------------------------------------------\n";
	std::cout << "|  index   |first name| last name| nick name|\n";
	std::cout << "---------------------------------------------\n";
	int i = 0;
	for (int i = 0; i < contactsCount; i++)
		putOnScreen(i);
	std::cout << RESET;
	index = getContactIndex(contactsCount);
	printContactByIndex(index);
}

void PhoneBook::search()
{

	showFullBook();
}
