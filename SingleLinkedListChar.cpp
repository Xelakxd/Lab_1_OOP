#define _CRT_SECURE_NO_WARNINGS
#include "SingleLinkedListChar.h"
#include <iostream>

#define FILENAME2 "result_char.txt"


void SingleLinkedListChar::push(char value)
{
	SingleLinkedListChar* buf = create_element(value, first);
	buf->next = first;
	first = buf;
}

void SingleLinkedListChar::pop()
{
	SingleLinkedListChar* to_delete = first;
	first = first->next;
	delete to_delete;
}


void SingleLinkedListChar::print()
{
	SingleLinkedListChar* buf = first;
	while (buf)
	{
		std::cout << buf->value << " ";
		buf = buf->next;
	}
	std::cout << std::endl;
}

void SingleLinkedListChar::find(char value_to_find)
{
	SingleLinkedListChar* buf = first;
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

void SingleLinkedListChar::print_to_file()
{
	FILE* output = fopen(FILENAME2, "w");
	if (!output)
	{
		throw std::exception();
	}

	SingleLinkedListChar* buf = first;
	while (buf)
	{
		const char* buf1 = &(buf->value);
		fprintf_s(output, buf1);
		buf = buf->next;
	}
	fclose(output);
}

SingleLinkedListChar* SingleLinkedListChar::create_element(char value, SingleLinkedListChar* next)
{
	SingleLinkedListChar* result = new SingleLinkedListChar;
	result->value = value;
	result->next = next;
	return result;
}
