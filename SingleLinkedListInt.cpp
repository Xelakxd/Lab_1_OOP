#define _CRT_SECURE_NO_WARNINGS
#include "SingleLinkedListInt.h"
#include <iostream>

#define FILENAME "result_int.txt"


void SingleLinkedListInt::push(int value)
{
	SingleLinkedListInt* buf = create_element(value, first);
	buf->next = first;
	first = buf;
}

void SingleLinkedListInt::pop()
{
	SingleLinkedListInt* to_delete = first;
	first = first->next;
	delete to_delete;
}


void SingleLinkedListInt::print()
{
	SingleLinkedListInt* buf = first;
	while (buf)
	{
		std::cout << buf->value << " ";
		buf = buf->next;
	}
	std::cout << std::endl;
}

void SingleLinkedListInt::find(int value_to_find)
{
	SingleLinkedListInt* buf = first;
	bool is_found = false;
	while (buf)
	{
		if (buf->value == value_to_find)
		{
			is_found = true;
		}
		buf = buf->next;
	}
	if (is_found)
	{
		std::cout << "Element has been found";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Element has not been found";
		std::cout << std::endl;
	}


}

void SingleLinkedListInt::print_to_file()
{
	FILE* output = fopen(FILENAME, "w");
	if (!output)
	{
		throw std::exception();
	}

	SingleLinkedListInt* buf = first;
	char buf1[10];
	while (buf)
	{
		fprintf_s(output, _itoa(buf->value, buf1, 10));
		fprintf_s(output, " ");
		buf = buf->next;
	}
	fclose(output);
}

SingleLinkedListInt* SingleLinkedListInt::create_element(int value, SingleLinkedListInt* next)
{
	SingleLinkedListInt* result = new SingleLinkedListInt;
	result->value = value;
	result->next = next;
	return result;
}
