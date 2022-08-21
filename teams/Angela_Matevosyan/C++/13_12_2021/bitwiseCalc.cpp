#include <iostream>
void bitwiseAnd(int a, int b)
{
	std::cout << a << " & " << b << " = " << (a&b) << std::endl;
}
void  bitwiseOr(int a, int b)
{
	std::cout << a << " | " << b << " = " << (a|b) << std::endl;
}
void  bitwiseXor(int a, int b)
{
	std::cout << a << " ^ " << b << " = " << (a^b) << std::endl;
}
void  bitwiseLeftShift(int a, int b)
{
	std::cout << a << " << " << b << " = " << (a<<b) << std::endl;
}
void  bitwiseRightShift(int a, int b)
{
	std::cout << a << " >> " << b << " = " << (a>>b) << std::endl;
}
void bitwiseCalc(int a, int b, int c)
{
	switch(c)
	{
		case 1:
			bitwiseAnd(a,b);
			break;
		case 2:
			bitwiseOr(a,b);
			break;
		case 3:
			bitwiseXor(a,b);
			break;
		case 4:
			bitwiseLeftShift(a,b);
			break;
	        case 5:
			bitwiseRightShift(a,b);
			break;
	}
}
int main()
{
	int a,b,c;
	std::cout << "Input first operand: ";
	std::cin >> a;
	std::cout << "Input second operand: ";
	std::cin >> b;
	std::cout << "Choose an operator:" << std::endl;
	std::cout << "1.AND(&)\n2.OR(|)\n3.XOR(^)\n4.Left Shift(<<)\n5.Right Shift(>>)" << std::endl;
	std::cin >> c;
	bitwiseCalc(a,b,c);
	return 0;
}
