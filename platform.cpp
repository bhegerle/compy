#include "platform.h"

#ifdef _WIN32
#include <windows.h>

void platform_init() {
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);
}
#else
void platform_init() {}
#endif