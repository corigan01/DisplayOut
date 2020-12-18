#include "displayout.h"

displayout dis;

int main() {


	for (int i = 0 ; i < 1000 ; i++)
		dis.out(D_DEBUG, "Hello World: " + std::to_string(i));

	std::cout << D_COLOR::redM << "DONE WITH MAIN!" << D_COLOR::defM << "\n";
	
	while(true) {};
}
