#include <Windows.h>

void checkAndPress(int hexKey, const char* str, char* argv) {
	if (strcmp(argv, str) == 0) {
		keybd_event(hexKey, 0, 0, 0);
	}
}

void checkAndRelease(int hexKey, const char* str, char* argv) {
	if (strcmp(argv, str) == 0) {
		keybd_event(hexKey, 0, KEYEVENTF_KEYUP, 0);
	}
}

int main(int argc, char** argv) {
	if (argc != 2) return 1;

	//Explanation:
	// the hex value is the virtual key code
	// the da means press a down, ua would mean release a
	checkAndPress(0x41, "da", argv[1]);
	checkAndPress(0x42, "db", argv[1]);
	checkAndPress(0x43, "dc", argv[1]);
	checkAndPress(0x44, "dd", argv[1]);
	checkAndPress(0x45, "de", argv[1]);
	checkAndPress(0x46, "df", argv[1]);
	checkAndPress(0x47, "dg", argv[1]);
	checkAndPress(0x48, "dh", argv[1]);
	checkAndPress(0x49, "di", argv[1]);
	checkAndPress(0x4A, "dj", argv[1]);
	checkAndPress(0x4B, "dk", argv[1]);
	checkAndPress(0x4C, "dl", argv[1]);
	checkAndPress(0x4D, "dm", argv[1]);
	checkAndPress(0x4E, "dn", argv[1]);
	checkAndPress(0x4F, "do", argv[1]);
	checkAndPress(0x50, "dp", argv[1]);
	checkAndPress(0x51, "dq", argv[1]);
	checkAndPress(0x52, "dr", argv[1]);
	checkAndPress(0x53, "ds", argv[1]);
	checkAndPress(0x54, "dt", argv[1]);
	checkAndPress(0x55, "du", argv[1]);
	checkAndPress(0x56, "dv", argv[1]);
	checkAndPress(0x57, "dw", argv[1]);
	checkAndPress(0x58, "dx", argv[1]);
	checkAndPress(0x59, "dy", argv[1]);
	checkAndPress(0x5A, "dz", argv[1]);
	//numbers
	checkAndPress(0x30, "d0", argv[1]);
	checkAndPress(0x31, "d1", argv[1]);
	checkAndPress(0x32, "d2", argv[1]);
	checkAndPress(0x33, "d3", argv[1]);
	checkAndPress(0x34, "d4", argv[1]);
	checkAndPress(0x35, "d5", argv[1]);
	checkAndPress(0x36, "d6", argv[1]);
	checkAndPress(0x37, "d7", argv[1]);
	checkAndPress(0x38, "d8", argv[1]);
	checkAndPress(0x39, "d9", argv[1]);

	//util keys
	checkAndPress(VK_TAB, "dTab", argv[1]);
	checkAndPress(VK_LWIN, "dMeta", argv[1]);
	checkAndPress(VK_ESCAPE, "dEscape", argv[1]);
	checkAndPress(VK_SHIFT, "dShift", argv[1]);
	checkAndPress(VK_CONTROL, "dControl", argv[1]);
	checkAndPress(VK_CAPITAL, "dCapsLock", argv[1]);

	//Releases
	checkAndRelease(0x41, "ua", argv[1]);
	checkAndRelease(0x42, "ub", argv[1]);
	checkAndRelease(0x43, "uc", argv[1]);
	checkAndRelease(0x44, "ud", argv[1]);
	checkAndRelease(0x45, "ue", argv[1]);
	checkAndRelease(0x46, "uf", argv[1]);
	checkAndRelease(0x47, "ug", argv[1]);
	checkAndRelease(0x48, "uh", argv[1]);
	checkAndRelease(0x49, "ui", argv[1]);
	checkAndRelease(0x4A, "uj", argv[1]);
	checkAndRelease(0x4B, "uk", argv[1]);
	checkAndRelease(0x4C, "ul", argv[1]);
	checkAndRelease(0x4D, "um", argv[1]);
	checkAndRelease(0x4E, "un", argv[1]);
	checkAndRelease(0x4F, "uo", argv[1]);
	checkAndRelease(0x50, "up", argv[1]);
	checkAndRelease(0x51, "uq", argv[1]);
	checkAndRelease(0x52, "ur", argv[1]);
	checkAndRelease(0x53, "us", argv[1]);
	checkAndRelease(0x54, "ut", argv[1]);
	checkAndRelease(0x55, "uu", argv[1]);
	checkAndRelease(0x56, "uv", argv[1]);
	checkAndRelease(0x57, "uw", argv[1]);
	checkAndRelease(0x58, "ux", argv[1]);
	checkAndRelease(0x59, "uy", argv[1]);
	checkAndRelease(0x5A, "uz", argv[1]);
	//numbers
	checkAndRelease(0x30, "u0", argv[1]);
	checkAndRelease(0x31, "u1", argv[1]);
	checkAndRelease(0x32, "u2", argv[1]);
	checkAndRelease(0x33, "u3", argv[1]);
	checkAndRelease(0x34, "u4", argv[1]);
	checkAndRelease(0x35, "u5", argv[1]);
	checkAndRelease(0x36, "u6", argv[1]);
	checkAndRelease(0x37, "u7", argv[1]);
	checkAndRelease(0x38, "u8", argv[1]);
	checkAndRelease(0x39, "u9", argv[1]);

	//util keys
	checkAndRelease(VK_TAB, "uTab", argv[1]);
	checkAndRelease(VK_LWIN, "uMeta", argv[1]);
	checkAndRelease(VK_ESCAPE, "uEscape", argv[1]);
	checkAndRelease(VK_SHIFT, "uShift", argv[1]);
	checkAndRelease(VK_CONTROL, "uControl", argv[1]);
	checkAndRelease(VK_CAPITAL, "uCapsLock", argv[1]);
}