#include <iostream>

void swapVoid(void* a, void* b) {
	double swap = *(double *)a;
	*(double *)a = *(double *)b;
	*(double *)b = swap;
}

int main(){
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
	swapVoid(&a, &b);
	std::cout << "After int swapping." << std::endl;
	std::cout << "\t " << a << " " << b << std::endl;

	std::cout << "\nBefore float swapping." << std::endl;
	std::cout << "\t " << c << " " << d << std::endl;
	swapVoid(&c, &d);
	std::cout << "After float swapping." << std::endl;
	std::cout << "\t " << c << " " << d << std::endl;

	std::cout << "\nBefore double swapping." << std::endl;
	std::cout << "\t " << e << " " << f << std::endl;
	swapVoid(&e, &f);
	std::cout << "After double swapping." << std::endl;
	std::cout << "\t " << e << " " << f << std::endl;

	std::cout << "\nBefore short swapping." << std::endl;
	std::cout << "\t " << l << " " << m << std::endl;
	swapVoid(&l, &m);
	std::cout << "After short swapping." << std::endl;
	std::cout << "\t " << l << " " << m << std::endl;

	std::cout << "\nBefore char swapping." << std::endl;
	std::cout << "\t " << g << " " << h << std::endl;
	swapVoid(&g, &h);
	std::cout << "After char swapping." << std::endl;
	std::cout << "\t " << g << " " << h << std::endl;
    
	return 0;
}
