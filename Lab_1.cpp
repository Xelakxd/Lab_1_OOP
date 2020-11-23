#include <iostream>
#include <exception>
#include "SingleLinkedListInt.h"
#include "SingleLinkedListChar.h"
#include <string>

void print_menu();

int get_int(const std::string& message);
int atoi(const std::string& str, int* res);


int main()
{
	SingleLinkedListInt int_list;
	SingleLinkedListChar char_list;

	while (true)
	{
		system("cls");
		print_menu();

		std::string input;
		std::getline(std::cin, input);

		if (input.size() != 1)
		{
			continue;
		}

		switch (input[0])
		{
		case '1':
		{
			int value = get_int("Enter the value:");
			int_list.push(value);
			std::cout << "Element has been added " << std::endl;
			system("pause");
			break;

		}
		case '2':
		{
			int_list.pop();
			std::cout << "Element has been deleted " << std::endl;
			system("pause");
			break;
		}
		case '3':
		{
			int_list.print();
			int_list.print_to_file();
			system("pause");
			break;
		}
		case '4':
		{
			int value = get_int("Enter the value:");
			int_list.find(value);
			system("pause");
			break;
		}
		case '5':
		{
			char value;
			std::cout << "Enter the element:" << std::endl;
			std::cin >> value;
			char_list.push(value);
			std::cout << "Element has been added " << std::endl;
			system("pause");
			break;
		}
		case '6':
		{
			char_list.pop();
			std::cout << "Element has been deleted " << std::endl;
			system("pause");
			break;
		}
		case '7':
		{
			char_list.print();
			char_list.print_to_file();
			system("pause");
			break;
		}
		case '8':
		{
			char value;
			std::cout << "Enter the element:" << std::endl;
			std::cin >> value;
			char_list.find(value);
			system("pause");
			break;
		}
		case '0':
		{
			return 0;
		}

		}
	}
}

int get_int(const std::string& message)
{
	int result;
	std::string buf;

	do
	{
		system("cls");
		std::cout << message;
		std::getline(std::cin, buf);
	} while (atoi(buf, &result));

	return result;
}

int atoi(const std::string& str, int* res)
{
	if (str.empty())
	{
		return 1;
	}

	bool is_negative = false;
	int i = 0;

	if (str[i] == '-')
	{
		++i;
		is_negative = true;
	}
	else if (str[i] == '+')
	{
		++i;
	}

	int number = 0;
	for (i; i < str.size(); ++i)
	{
		if (str[i] < '0' || str[i]>'9')
		{
			return 1;
		}
		int prev = number;
		number = number * 10 + str[i] - '0';
	}

	if (is_negative)
	{
		number *= -1;
	}

	*res = number;
	return 0;
}

void print_menu()
{
	std::cout << "1 - Add to the int list              " << std::endl;
	std::cout << "2 - Delete from the int list         " << std::endl;
	std::cout << "3 - Print the int list               " << std::endl;
	std::cout << "4 - Find an element in the int list  " << std::endl;
	std::cout << "5 - Add to the char list             " << std::endl;
	std::cout << "6 - Delete from the char list        " << std::endl;
	std::cout << "7 - Print the char list              " << std::endl;
	std::cout << "8 - Find an element in the char list " << std::endl;
	std::cout << "0 - Exit                             " << std::endl;
}
