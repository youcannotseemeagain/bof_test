#include <windows.h>
#include <stdint.h>
#include "bofdefs.h"

#pragma region error_handling
#define print_error(msg, hr) _print_error(__FUNCTION__, __LINE__, msg, hr)
BOOL _print_error(char* func, int line,  char* msg, HRESULT hr) {
#ifdef BOF
	BeaconPrintf(CALLBACK_ERROR, "(%s at %d): %s 0x%08lx", func, line,  msg, hr);
#else
	//////printf("[-] (%s at %d): %s 0x%08lx", func, line, msg, hr);
#endif // BOF

	return FALSE;
}
#pragma endregion
//=====================================


//======================================

#ifdef BOF
void go(char* buff, int len) {

	datap parser;

	char* pa;

	BeaconDataParse(&parser, buff, len);
	pa = BeaconDataExtract(&parser, NULL);
	//system("notepad");
	BeaconPrintf(CALLBACK_OUTPUT, "Hello %s", pa);

}


#else

void main(int argc, char* argv[]) {
	
}

#endif