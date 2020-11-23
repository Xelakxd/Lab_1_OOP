#pragma once

class SingleLinkedListChar
{
public:
	SingleLinkedListChar* first = nullptr;
	SingleLinkedListChar* next;
	char value;

	SingleLinkedListChar()
		{
			first = nullptr;
			next = nullptr;
			value = '0';
		}

	~SingleLinkedListChar()
		{
			SingleLinkedListChar* buf = first;
			while (buf)
			{
				SingleLinkedListChar* to_delete = buf;
				buf = buf->next;
				delete to_delete;
			}
		}


	void push(char value);
	void pop();
	void print();
	void find(char value_to_find);
	void print_to_file();
	SingleLinkedListChar* create_element(char value, SingleLinkedListChar* next);


};

