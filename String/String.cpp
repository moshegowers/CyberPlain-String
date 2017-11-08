#include "String.h"
#include <string.h>

String::String():length(0) {}

String::String(const String &string)
{
	length = string.length;
	content = new char[length];
	strcpy_s(content, length, string.content);
}

String* String::convertCahrArrayToString(char* str)
{
	size_t len = strlen(str) + 1;
	String *strTmp = new String;
	strTmp->content = new char[len];
	strcpy_s(strTmp->content, len, str);
	strTmp->length = len;

	return strTmp;
}

int String::GetLength() const
{
	return length;
}

void String::Assign(const String &str)
{
	if (str.GetLength() <= 0)
	{
		return;
	}

	size_t str_len = str.GetLength();
	this->content = new char[str_len];
	this->length = str_len;

	for (size_t i = 0; i < str_len; i++)
	{
		this->content[i] = str.CharAt(i);
	}
}

void String::Assign(char *str)
{
	String *s = convertCahrArrayToString(str);
	Assign(*s);
}

char String::CharAt(size_t index) const
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

void String::Append(const String &str)
{
	if (this->length <= 0 || this->content == NULL)
	{
		this->Assign(str);
	}
	else
	{
		size_t len = this->length + str.GetLength();
		String strTmp;
		strTmp.content = new char[len];
		strTmp.length = len;
		strcpy_s(strTmp.content, this->length, this->content);
		strcat_s(strTmp.content, strTmp.length, str.content);
		this->Assign(strTmp);
	}
}

void String::Append(char *str)
{
	String *s = convertCahrArrayToString(str);
	Append(*s);
}

int String::Compare(const String &str)
{
	if (str.content == NULL)
	{
		return 1;
	}
	if (this->content == NULL)
	{
		return -1;
	}
	return strcmp(this->content, str.content);
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