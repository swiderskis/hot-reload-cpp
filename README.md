# Hot Reloading in C++

A simple demonstration on how to implement hot reloading in C++ using the Windows API.

Assuming you have the `g++` compiler set up, this can be run using the commands

```
./build.sh && ./main.exe
```

Modifying the `squared` function in `dynlib.cpp` and running `./build_dll.sh`, providing an input of `0` to the program will load the updated function without needing to reload the entire program.
