#include "String.h"
using namespace StringNamespace;

void main(void)
{
	String s1;
	s1.Assign("aaa");
	String s2;
	s2.Assign("bbb");
	s1.Append(s2);
	s1.Append("ccc");
	s1.GetLength();
}