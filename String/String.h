#ifndef STRING_H
#define STRING_H

class String {
	size_t length;
	char *content;
public:
	String();
	int GetLength();
	void Assign(String *str);
	char CharAt(size_t index);	void Append(String *str);
	int Compare(String *str);
	bool IsEmpty();
	void Clear();
};

#endif
