g++ -fPIC -shared -o dynlib.dll dynlib.cpp 
g++ main.cpp -o main -I. 
