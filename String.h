#ifndef __String__
#define __String__

#include <iostream>;
using namespace std;

class String
{
	private:
		char* buffer = nullptr;
		unsigned int size = 0;

		inline void cleanBuffer() {
			if (buffer != nullptr) delete[] buffer;
			size = 0;
		};

	public:
		String(): buffer(nullptr), size(0) {}
		String(const char* string);
		String(const String& string);
		String(String&& dyingString) noexcept; 

		~String();

		
		String& operator=(String&& dyingString) noexcept;
		String& operator=(const String& string);
		String operator+(const String& string);

		char  operator[] (int index) const;

		friend bool operator== (const String& lhs, const String& rhs);
		friend ostream& operator<<(ostream& cout, const String& obj);

		inline unsigned int length() { return size; }
		void clear();
};

#endif //__String__