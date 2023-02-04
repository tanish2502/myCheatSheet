C++ Notes

C++ Progrmmming Language Book.

Chap-> Tour of C++;
C++ Support for Modular Programmming.

https://www.techopedia.com/definition/25972/modular-programming

Modularity can be acheived by practicing these below given way for example.

3 files:
abc.h        -> only function declarations -> also can be called as interface
abc.c        -> defination of all the function present in abc.h
abc_client.c -> using the above functions as needed by the client.


Static keyword: Used while function declaration & function defination enables the function call of that function only in the file where it is defined & can't be called outside the file where it is defined.
Used in the server side in case of above example server code.

- In C++, the size of the null class is 1 because it is the smallest possible size that a class can have. 
This is due to the way that the C++ compiler is designed. When a class is defined, the compiler automatically adds a null terminator to the end of the class, which is a special character that indicates the end of the class definition. This null terminator takes up one byte of memory, which is why the 
size of the null class is 1.

- However, it's important to note that the size of the null class is not always 1. It can vary depending on the implementation of the C++ compiler. 
Some compilers may use a different method for defining classes, which could result in a different size for the null class. 
Additionally, the size of the null class may be different for different data types. 
For example, the size of the null class for an int data type may be different from the size of the null class for a char data type.

- C++ is a multi-paradigm language &  supports all 7 paradigms:
1.  Procedural Programming  (Captured in C Language)
2.  Object Oriented Programming
3.  Generic Programming
4.  Functional Programming
5.  Meta Programming
6.  Aspect Oriented Programming
7.  Modular Programming

- Generic Info: How printf works?
fn call of printf() -> write syscall -> writeconsole syscall -> goes into kernel -> kernel calls consoledriver -> and console driver is responsible for showing text on console given in printf() fn.
