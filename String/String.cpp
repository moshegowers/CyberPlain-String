#include "String.h"
#include <string.h>

String::String(){}

int String::GetLength()
{
	return length;
}

void String::Assign(String *str)
{
	if (str == NULL || str->GetLength() <= 0)
	{
		return;
	}
	
	if (this->content != NULL)
	{
		delete this->content;
	}

	size_t str_len = str->GetLength();
	this->content = new char[str_len];
	this->length = str_len;
	
	for (size_t i = 0; i < str_len; i++)
	{
		this->content[i] = str->CharAt(i);
	}
}

char String::CharAt(size_t index)
{
	if (this->length > index)
	{
		return content[index];
	}
	else
	{
		return '\0';
	}
}

void String::Append(String *str)
{
	if (this->length <= 0 || this->content == NULL)
	{
		this->Assign(str);
	}
	else
	{
		size_t len = this->length + str->GetLength();
		String *str_tmp = new String;
		str_tmp->content = new char[len];
		str_tmp->length = len;
		strcpy_s(str_tmp->content, this->length, this->content);
		strcat_s(str_tmp->content, str->length, str->content);
		this->Assign(str_tmp);

		if (str_tmp != NULL)
		{
			delete str_tmp;
		}
	}
}

int String::Compare(String *str)
{
	if (str == NULL || str->content == NULL)
	{
		return 1;
	}
	if (this->content == NULL)
	{
		return -1;
	}
	return strcmp(this->content, str->content);
}

bool String::IsEmpty()
{
	return this->content == NULL || this->length <= 0;
}

void String::Clear()
{
	if (this->content != NULL)
	{
		delete this->content;
	}
	this->length = 0;
}