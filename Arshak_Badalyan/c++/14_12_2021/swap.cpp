#include <iostream>

class  Swap {
public:
	void swap(int *a, int *b) {
		int pSwap = *a;
    		*a = *b;
    		*b = pSwap;
	}
	
	void swap(float *a, float *b) {
    		float pSwap = *a;
    		*a = *b;
    		*b = pSwap;
	}
	void swap(double *a, double *b) {
    		double pSwap = *a;
    		*a = *b;
    		*b = pSwap;
	}
	void swap(char *a, char *b) {
    		char pSwap = *a;
    		*a = *b;
    		*b = pSwap;
	}
	void swap(short *a, short *b) {
    		short pSwap = *a;
    		*a = *b;
    		*b = pSwap;
	}
};

int main() {
    	Swap item;

	int a = 7;
    	int b = 9;	
	float c = 5.2;
    	float d = 6.3;	
	double e = 8.5;
    	double f = 7.9;	
	char g = 'a';
    	char h = 'b';	
	short l = 2;
    	short m = 3;	

	std::cout << "Before int swapping." << std::endl;
	std::cout << "\t " << a << " " << b << std::endl;
	item.swap(&a, &b);
	std::cout << "After int swapping." << std::endl;
	std::cout << "\t " << a << " " << b << std::endl;

	std::cout << "\nBefore float swapping." << std::endl;
	std::cout << "\t " << c << " " << d << std::endl;
	item.swap(&c, &d);
	std::cout << "After float swapping." << std::endl;
	std::cout << "\t " << c << " " << d << std::endl;

	std::cout << "\nBefore double swapping." << std::endl;
	std::cout << "\t " << e << " " << f << std::endl;
	item.swap(&e, &f);
	std::cout << "After double swapping." << std::endl;
	std::cout << "\t " << e << " " << f << std::endl;

	std::cout << "\nBefore short swapping." << std::endl;
	std::cout << "\t " << l << " " << m << std::endl;
	item.swap(&l, &m);
	std::cout << "After short swapping." << std::endl;
	std::cout << "\t " << l << " " << m << std::endl;

	std::cout << "\nBefore char swapping." << std::endl;
	std::cout << "\t " << g << " " << h << std::endl;
	item.swap(&g, &h);
	std::cout << "After char swapping." << std::endl;
	std::cout << "\t " << g << " " << h << std::endl;

    return 0;
}
