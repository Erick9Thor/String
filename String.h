#ifndef __String__
#define __String__

#include <iostream>;
using namespace std;

class String
{
	private:
		char* buffer = nullptr;
		unsigned int length = 0;

		inline void cleanBuffer() {
			if (buffer != nullptr) delete[] buffer;
			length = 0;
		};

	public:
		String(): buffer(nullptr), length(0) {}
		String(const char* string);
		String(const String& string);
		String(String&& dyingString) noexcept; 

		~String();
		

		String& operator=(String&& dyingString) noexcept;
		String& operator=(const String& string);
		String operator+(const String& string);

		friend ostream& operator<<(ostream& cout, const String& obj);

		
};

#endif //__String__