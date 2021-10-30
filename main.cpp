#include "String.h"
#include <iostream>;

using namespace std;

int main() {
	String a("hello");
	
	std::cout << a << "\n";
	
	String b(a);

	std::cout << b << "\n";

	String c = a + b;

	std::cout << c << "\n";
	
}