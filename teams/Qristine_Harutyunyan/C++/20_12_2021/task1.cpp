#include <iostream>
#include <cstring>

class String{
    char* mString;
    int mSize;
    static int counter;
	public:

        int length() {
            int count = 0;
            for (int i = 0; mString[i] != '\0'; ++i){
                count++;
            }
	        return count;
        }

        void print() {
	        std::cout << mString << std::endl;
	    }

	    void concat(char* str2, int s) {
	        static char str3[30];
            int i = 0;
            int j = 0;
            while(mString[i] != '\0') {
                   str3[j] = mString[i];
                   ++i;
                   ++j;
            }
            i = 0;
            while(str2[i] != '\0') {
                  str3[j] = str2[i];
                  ++i;
                  ++j;
            }

            str3[j] = '\0';
	        mString = str3;
	        mSize =+ s;
	    }

        static int getObjectsCount() { 
            return counter;
	    }

        bool hasSubString(char* str, int s) {
            return 0;
	    }

        String(char* str, int s) {
	         mString = str; 
             mSize = s;	
	         counter++;
        }
};

int String::counter = 0;

int main() {
    char temp[] = "Hello";
    String str(temp, 5);
    str.print();
    char concat[] = " World";
    str.concat(concat, 6);
    str.print();
    std::cout << str.length() << std::endl;
    std::cout << String::getObjectsCount() << std::endl;
    char sub[] = "Hel";
    str.hasSubString(sub, 30);

    return 0;
}
