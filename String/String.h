#ifndef STRING_H
#define STRING_H

class String {
public:
	String();
	String& convertCahrArrayToString(char* str);
	int GetLength() const;
	void Assign(const String &str);
	void Assign(char *str);
	char CharAt(size_t index) const;
	void Append(const String &str);
	void Append(char *str);
	int Compare(const String &str);
	bool IsEmpty();
	void Clear();

private:
	size_t length;
	char *content;
};

#endif
