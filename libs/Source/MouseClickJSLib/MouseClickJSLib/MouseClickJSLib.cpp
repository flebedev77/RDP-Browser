#include <iostream>
#include <Windows.h>

int main(int argc, char** argv)
{
	if (argc != 2) return 1;
	
	if (strcmp(argv[1], "dl") == 0) { // Down left
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	} else if (strcmp(argv[1], "dr") == 0) { // Down right
		mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
	} else if (strcmp(argv[1], "ul") == 0) { // Up left
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	} else if (strcmp(argv[1], "ur") == 0) { // Up right
		mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
	}
}

