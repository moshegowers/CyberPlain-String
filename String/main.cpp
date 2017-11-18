#include "String.h"
#include <iostream>

using namespace StringNamespace;

void main(void)
{
	String<wchar_t> s1;
	s1.Assign(L"aaa", wcslen(L"aaa") + 1);
	s1.Print();
	String<char> s2;
	s2.Assign("bbb", strlen("bbb") + 1);
	s2.Print();
}