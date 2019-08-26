#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include"simple_string.h"
using std::cin;
using std::cout;
//////////////////////////////////////////////////////
int Simple_String::num_strings = 0;
//////////////////////////////////////////////////////
int Simple_String::HowMany()
{
	return num_strings;
}
//////////////////////////////////////////////////////
Simple_String::Simple_String(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}
//////////////////////////////////////////////////////
Simple_String::Simple_String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}
/////////////////////////////////////////////////////
Simple_String::Simple_String(const Simple_String& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}
/////////////////////////////////////////////////////
Simple_String::~Simple_String()
{
	--num_strings;
	delete[]str;
}
/////////////////////////////////////////////////////
Simple_String& Simple_String::operator=(const Simple_String& st)
{
	if (this == &st)
		return *this;
	delete[]str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}
/////////////////////////////////////////////////////
Simple_String& Simple_String::operator=(const char* s)
{
	delete[]str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}
/////////////////////////////////////////////////////
char& Simple_String::operator[](int i)
{
	return str[i];
}
/////////////////////////////////////////////////////
const char& Simple_String::operator[](int i)const
{
	return str[i];
}
/////////////////////////////////////////////////////
bool operator<(const Simple_String& st1, const Simple_String& st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}
/////////////////////////////////////////////////////
bool operator>(const Simple_String& st1, const Simple_String& st2)
{
	return st2.str < st1.str;
}
/////////////////////////////////////////////////////
bool operator==(const Simple_String& st1, const Simple_String& st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}
/////////////////////////////////////////////////////
ostream& operator<<(ostream& os, const Simple_String& st)
{
	os << st.str;
	return os;
}
/////////////////////////////////////////////////////
istream& operator>>(istream& is, Simple_String& st)
{
	char temp[Simple_String::CINLIM];
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}