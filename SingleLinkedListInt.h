#pragma once

class SingleLinkedListInt
{
public:
	SingleLinkedListInt* first = nullptr;
	SingleLinkedListInt* next;
	int value;

	SingleLinkedListInt()
	{
		first = nullptr;
		next = nullptr;
		value = 0;
	}

	~SingleLinkedListInt()
	{
		SingleLinkedListInt* buf = first;
		while (buf)
		{
			SingleLinkedListInt* to_delete = buf;
			buf = buf->next;
			delete to_delete;
		}
	}


	void push(int value);
	void pop();
	void print();
	void find(int value_to_find);
	void print_to_file();
	SingleLinkedListInt* create_element(int value, SingleLinkedListInt* next);
	

};

