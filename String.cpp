#include "String.h"
#include <string.h>

String::String(const char* string) {
	size = strlen(string);
	buffer = new char[size + 1]; // '\0' keeping 

	strncpy_s(buffer, size + 1, string, size);
}

String::String(const String& string) {
	size = string.size;
	buffer = new char[size + 1];

	strncpy_s(buffer, size + 1, string.buffer, size);
}

String::String(String&& dyingString) noexcept
{
	cleanBuffer();

	size = dyingString.size;
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

	size = dyingString.size;
	buffer = dyingString.buffer;
	dyingString.buffer = nullptr;

	return *this;
}

String& String::operator=(const String& string)
{
	cleanBuffer();

	size = string.size;
	buffer = new char[size + 1];

	strncpy_s(buffer, size + 1, string.buffer, size);

	return *this;
}

String String::operator+(const String& string)
{
	String result;
	result.size = size + string.size;
	result.buffer = new char[result.size + 1];

	strncpy_s(result.buffer, size + 1, buffer, size);
	strncpy_s(result.buffer + size, string.size + 1, string.buffer, string.size);

	return result;
}

char String::operator[](int index) const
{
	if (index >= size) throw 1;
	return buffer[index];
}

void String::clear()
{
	delete[] buffer;
	size = 0;
	buffer = new char[size]();
}

bool operator==(const String& lhs, const String& rhs)
{
	if (lhs.size != rhs.size) return false;

	int lhs_length = lhs.size;
	int index = 0;

	while ((index < lhs_length) && (lhs[index] == rhs[index])) ++index;

	return (index == lhs_length);

}

ostream& operator<<(ostream& cout, const String& obj)
{
	cout << obj.buffer;
	return cout;
}
