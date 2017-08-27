// testcode.cpp
// this file is a test of cpp and git
// by knewyousir

#include <iostream>
#include <iomanip>

using namespace std;

int main (void)
{
cout << endl;
cout << "SOME IMPORTANT NUMBERS:\n" << endl;
for (int count(0); count < 10; count++){
	for (int count2(0); count2 < 10; count2++){
		std::cout << std::setw(2);
		cout << (count2 + (count * 10)) << " ";
		if (count2 == 9)
			cout << "\n";
	}
}
cout << endl
	<< "THANK YOU FOR YOUR ATTENTION\n"
		<< endl;

return 0;
}
