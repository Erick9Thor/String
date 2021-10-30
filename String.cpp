#include "String.h"
#include <string.h>

String::String(const char* string) {
	length = strlen(string);
	buffer = new char[length + 1]; // '\0' keeping 

	strncpy_s(buffer, length + 1, string, length);
}

String::String(const String& string) {
	length = string.length;
	buffer = new char[length + 1];

	strncpy_s(buffer, length + 1, string.buffer, length);
}

String::String(String&& dyingString) noexcept
{
	cleanBuffer();

	length = dyingString.length;
	buffer = dyingString.buffer;
	dyingString.buffer = nullptr;
}

String::~String()
{
	cleanBuffer();
}

String& String::operator=(String&& dyingString) noexcept
{
	cleanBuffer();

	length = dyingString.length;
	buffer = dyingString.buffer;
	dyingString.buffer = nullptr;

	return *this;
}

String& String::operator=(const String& string)
{
	cleanBuffer();

	length = string.length;
	buffer = new char[length + 1];

	strncpy_s(buffer, length + 1, string.buffer, length);

	return *this;
}

String String::operator+(const String& string)
{
	String result;
	result.length = length + string.length;
	result.buffer = new char[result.length + 1];

	strncpy_s(result.buffer, length + 1, buffer, length);
	strncpy_s(result.buffer + length, string.length + 1, string.buffer, string.length);

	return result;
}

ostream& operator<<(ostream& cout, const String& obj)
{
	cout << obj.buffer;
	return cout;
}
