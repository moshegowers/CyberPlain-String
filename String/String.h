#ifndef STRING_H
#define STRING_H

class String {
public:
	String();
	String* convertCahrArrayToString(char* str);
	int GetLength();
	void Assign(String *str);
	void Assign(char *str);
	char CharAt(size_t index);	void Append(String *str);
	void Append(char *str);
	int Compare(String *str);
	bool IsEmpty();
	void Clear();

private:
	size_t length;
	char *content;
};

#endif
