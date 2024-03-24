#include <iostream>
#include <Windows.h>

int main(int argc, char** argv)
{
	if (argc != 3) return 1;
	SetCursorPos(atoi(argv[1]), atoi(argv[2]));
	//std::cout << "My command line arguments: ";
	//for (int i = 0; i < argc; i++) {
	//	std::cout << " " << argv[i];
	//}
	//std::cin.get();
}

