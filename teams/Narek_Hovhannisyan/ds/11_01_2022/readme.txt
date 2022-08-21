Hi all.
To execute the program you should run following commands

// will be more tidy to create "build" directory
// and build the application there, so your steps
//then you are in ".../Narek_Hovhannisyan/ds/11_01_2022" directory


```
mkdir build
cd build
cmake .. .
make
./main
```

so you have ".../build/main" executable file which contains a function 
named isStringCorrect to check if a string containing only ( ) { } [ ] 
symbols correct or not, , and Vector class implementation.
Vector class has following methods.
    int getSize() const;
    int getCapacity() const;
    void push(int);
    void pop();
    void insert(int, int);
    void vDelete(int);
    int operator [] (int);
    void print() const;
    void autoFill(int, int);
    void autoFill();
Fill free to use them, Thanks.