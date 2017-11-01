#include "String.h"
#include <string.h>

String::String(){}

String* String::convertCahrArrayToString(char* str)
{
	size_t len = strlen(str);
	String *strTmp = new String;
	strTmp->content = new char[len];
	strcpy_s(strTmp->content, len, str);
	strTmp->length = len;

	return strTmp;
}

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

void String::Assign(char *str)
{
	String* s = convertCahrArrayToString(str);
	Assign(s);
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

void String::Append(char *str)
{
	String* s = convertCahrArrayToString(str);
	Append(s);
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