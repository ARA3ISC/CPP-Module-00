#include <iostream>

int main(int argc, char *argv[])
{
	int i;

	if (argc > 1) {
		i  = 1;
		char ch;
		while (i < argc)
		{
			for (size_t c = 0; c < std::strlen(argv[i]); c++)
			{
				ch = std::toupper(argv[i][c]);
				std::cout << ch;
			}
			std::cout << " ";
			i++;
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}

}
