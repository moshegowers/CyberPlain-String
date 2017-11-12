#ifndef STRING_H
#define STRING_H

namespace StringNamespace
{
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

		friend bool operator== (const String &lhs, const String &rhs);
		friend bool operator!= (const String &lhs, const String &rhs);

	private:
		size_t length;
		char *content;
	};
}

#endif
