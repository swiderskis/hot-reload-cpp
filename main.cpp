#include "dynlib.hpp"

#include <iostream>
#include <windows.h>

HMODULE lib = nullptr;
squared_t squared = nullptr;

bool reload_lib()
{
    if (lib != nullptr) {
        FreeLibrary(lib);
    }

    if (!CopyFile("dynlib.dll", "dynlib_temp.dll", false)) {
        std::cout << "bad thing happen when copying dll\n";

        return false;
    }

    lib = LoadLibrary("dynlib_temp");
    if (lib == nullptr) {
        std::cout << "bad thing happen when loading lib\n";

        return false;
    }

    squared = (squared_t)GetProcAddress(lib, "squared");
    if (squared == nullptr) {
        std::cout << "bad thing happen when loading squared\n";

        return false;
    }

    std::cout << "good fortunes come your way!\n";

    return true;
}

int main()
{
    int num = 0;
    if (!reload_lib()) {
        return -1;
    }

    while (true) {
        std::cout << "Input number: ";
        std::cin >> num;

        if (num == 0) {
            if (!reload_lib()) {
                return -1;
            }
        } else {
            std::cout << "Squared: " << squared(num) << "\n";
        }
    }

    return 0;
}
