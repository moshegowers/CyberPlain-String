#include "String.h"
#include <iostream>

void main(void)
{
	/*String s1;
	s1.Assign("aaa");
	String s2;
	s2.Assign("bbb");
	s1.Append(s2);
	s1.Append("ccc");
	s1.GetLength();*/

	String string;
	string.Assign("copy string");

	String stringArray[10];
	for (size_t i = 0; i < 10; i++)
	{
		stringArray[i] = string;
	}

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "The length of string is: " << stringArray[i].GetLength() << std::endl;
	}
}