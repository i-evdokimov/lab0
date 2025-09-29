#include <iostream>
#include "module1.h"
#include "module2.h"
#include "module3.h"

using std::cout;
using std::endl;

int main(int argc, char** argv)
{
	std::cout <<  "Hello world!" << "\n";

	// Явные вызовы
	std::cout << Module1::getMyName() << "\n";
	std::cout << Module2::getMyName() << "\n";
	std::cout << Module3::getMyName() << "\n";

	cout << "1"<< "\n";

	// Исключение вероятности пересечения имён
	cout << Module1::getMyName() << endl; 
    cout << Module2::getMyName() << endl;
    cout << Module3::getMyName() << endl;

	cout << "2"<< "\n";

	using namespace Module1; // (A) берётся функция из module1 / подключаются все имена
	std::cout << getMyName() << "\n";

	std::cout << Module2::getMyName() << "\n";

	std::cout << Module3::getMyName() << "\n";

	cout << "3"<< "\n";

	//using namespace Module2; // (B)
	//std::cout << getMyName() << "\n"; // COMPILATION ERROR (C)

	//error: reference to 'getMyName' is ambiguous , тк getMyName есть и в module1 и module2

	using Module2::getMyName; // (D) берётся только функция из module2
	std::cout << getMyName() << "\n";

	std::cout << Module1::getMyName() << "\n";

	std::cout << Module3::getMyName() << "\n";
}