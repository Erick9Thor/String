#include "String.h"
#include <iostream>;

using namespace std;

String GetMeAString() { return String("another string"); }

int main() {
	String a("hello");
	
	std::cout << a << "\n";
	
	String b(a);

	std::cout << b << "\n";

	String c = a + b;

	std::cout << c << "\n";

	if (c == "hellohello") printf("works!\n");
	
	std::cout << c.length() << "\n";

	c.clear();
	/*
	String d = GetMeAString();

	std::cout << d;*/
}