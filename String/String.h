#include <iostream>
#include <string>
#ifndef STRING_H
#define STRING_H

namespace StringNamespace
{
	template <typename T>
	class String {
	public:
		String()
		{
		}
		String<T>& convertCahrArrayToString(const T* str, size_t len)
		{
			String strTmp;;
			strTmp.content = new T[len];
			if (std::is_same<wchar_t, T>::value)
			{
				wcscpy_s((wchar_t*)strTmp.content, len, (wchar_t*)str);
			}
			else
			{
				strcpy_s((char*)strTmp.content, len, (char*)str);
			}
			strTmp.length = len;

			return strTmp;
		}

		int GetLength() const
		{
			return length;
		}

		void Assign(const String<T> &str)
		{
			if (str.GetLength() <= 0)
			{
				return;
			}

			size_t str_len = str.GetLength();
			this->content = new T[str_len];
			this->length = str_len;

			for (size_t i = 0; i < str_len; i++)
			{
				this->content[i] = str.CharAt(i);
			}
		}

		void Assign(T *str, size_t len)
		{
			String s = convertCahrArrayToString(str, len);
			Assign(s);
		}

		T CharAt(size_t index) const
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

		void Append(const String<T> &str)
		{
			if (this->length <= 0 || this->content == NULL)
			{
				this->Assign(str);
			}
			else
			{
				size_t len = this->length + str.GetLength();
				String strTmp;
				strTmp.content = new T[len];
				strTmp.length = len;
				strcpy_s(strTmp.content, this->length, this->content);
				strcat_s(strTmp.content, strTmp.length, str.content);
				this->Assign(strTmp);
			}
		}

		void Append(T *str, size_t len)
		{
			String s = convertCahrArrayToString(str, len);
			Append(s);
		}

		int Compare(const String<T> &str)
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

		bool IsEmpty()
		{
			return this->content == NULL || this->length <= 0;
		}

		void Clear()
		{
			if (this->content != NULL)
			{
				delete this->content;
			}
			this->length = 0;
		}

		void Print()
		{
			if (this->content == NULL || this->length <= 0)
			{
				std::cout << "The string is null or empty";
				return;
			}
			if (std::is_same<char, T>::value)
			{
				std::cout << "Hello, " << this->content << std::endl;
			}
			else if (std::is_same<wchar_t, T>::value)
			{
				std::wcout << L"Hello, " << this->content << std::endl;
			}
		}

		void operator=(const String<T> & str)
		{
			length = str.length;
			content = new T[strlen(str.content)];
			strcpy_s(content, sizeof(content), str.content);
		}

		void operator+=(const String<T> & str)
		{
			if (str.content == NULL || str.length <= 0)
			{
				return;
			}

			T *tmp = new T[length];
			if (length >= 0)
			{
				strcpy_s(tmp, length + 1, content);
			}

			length += str.length;
			content = new T[length];
			strcpy_s(content, length, tmp);
			strcat_s(content, length, str.content);

		}

		friend bool operator==(const String<T> & lhs, const String<T> & rhs)
		{
			return *lhs.content == *rhs.content;
		}

		friend bool operator!=(const String<T> & lhs, const String<T> & rhs)
		{
			return !(lhs == rhs);
		}


	private:
		size_t length;
		T *content;
	};
}

#endif

