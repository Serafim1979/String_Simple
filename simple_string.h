#ifndef SIMPLE_STRING_H_
#define SIMPLE_STRING_H_
#include<iostream>
///////////////////////////////////////////////
using std::ostream;
using std::istream;
///////////////////////////////////////////////
class Simple_String
{
private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	Simple_String(const char* s);
	Simple_String();
	Simple_String(const Simple_String&);
	~Simple_String();
	int length()const
	{
		return len;
	}

	Simple_String& operator=(const Simple_String&);
	Simple_String& operator=(const char*);
	char& operator[](int i);
	const char& operator[](int i)const;

	friend bool operator<(const Simple_String& st1, const Simple_String& st2);
	friend bool operator>(const Simple_String& st1, const Simple_String& st2);
	friend bool operator==(const Simple_String& st, const Simple_String& st2);
	friend ostream& operator<<(ostream& os, const Simple_String& st);
	friend istream& operator>>(istream& is, Simple_String& st);

	static int HowMany();

};

#endif // !SIMPLE_STRING_H_

