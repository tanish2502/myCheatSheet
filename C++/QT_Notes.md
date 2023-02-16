### About QT
* Q_OBJECT: 
  QT has language and feature-wise extensions that are called QT MetaObject System.

* Those classes who wanted to use QT MetaObject System must use this Macro Q_OBJECT.

* explicit constructor introduced in C++ 11.
  In this implicit type conversion are strictly prohibited.
  
* Some functions that are implemented inside OS, but called from application level. These are called as system calls. And what OS provides is called as system call interface.

- Qt direct makes call to XToolKit then XLib interface.
- QT->XToolKit->XLib
- QT->XLib
- QT->NativeOS
- All these above flow of calls is suported.
- QT's API directly calls Win32's API directly, be it graphical or non-graphical.
- Windows has self implemented GUI(Graphical User Interface) system called as GDI(Graphics Device Interface).
- Any Device that help in image rendering is called as Graphics Device. And Medium for the same is called as Interface.

### QT Project Info
- QT, using C++ Features provided by Standard C++ Compiler has built additional language tools/features like Signals/Slots called meta-programming code.
- This meta-programming code is to be included in every application of the QT project/Application. 
OR can say language extensions implemented by QT how?
- There is 1 Programming Paradigm, named Meta-Programming.

### What is Meta Programming?
- Programming the programming Language!!
- In X Programming lang, writing src code such that the constructed behaviour of that prog lang X modifies as per our need/code changes.
- Without changing the compiler or interpreter, making src code changes such that one can alter the behaviour of a few statements as per need.
- In QT, we have 2 novel concepts named Signals & Slot for event handling. That is not equal to any callback function.
- If GUI programming is to be done using QT, then only Signals & Slot feature can be used else not needed, hence it can be said that its usage is very niche.
- And it’s not okay to provide these features to all across C++ when that usage is very niche.
- The same Meta-Programming can be done using Meta Class in Python.
- Template Meta-Programming in C++: Using Template Meta Programming can be done in C++. (Book: C++ Template Meta-Programming by A-Press Publication).

### Why Q_OBJECT Macro in QT Project?
- If in any user-defined class, we want to use QT implemented Meta Programming extension, then we have to use include the Macro Q_OBJECT in each class in which we want to implement this feature.
- QT’s Meta Programming Extension is called a Meta-Object System.

### Why While compiling QT Project, the compiler doesn’t throw an error while the src code has words like slots & signals?
- In QT’s bin dir,  we have 1 file “moc.exe” -> QT’s Meta Object Compiler. 
- 1st the QT’s meta-object system project/src code has to be passed/compiled properly through “moc.exe”, then can proceed ahead.
- QT Src Code -> “MOC.exe” -> Pure C++ Src Code -> C++ Compiler -> Final Build.
- The point to note is, 1st PreProcessor Directive will kick in and do their process then moc.exe comes into to picture to process QT src code then flow continues, because if Q_OBJECT will expand in preprocessing stage, then only moc.exe can work.

### Contents of (filename).pro file
 - A group of logically related files have assembled together to form a lib file.
- So, while writing QT += (libname) in Pro(QT Project File). All the files linked to the name here will be linked and the final proper working project will be created.
-  HEADERS += (all the headerfiles) in the project.
- SOURCES += (all the src code) in the project including main.cpp

### Contents of project source code:
*standardWindow.h*
```
#ifndef STANDARDWINDOW_H
#define STANDARDWINDOW_H

#include <QMainWindow>

class StandardWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit StandardWindow(QWidget *parent = nullptr);

signals:

};

#endif // STANDARDWINDOW_H
```

*standardWindow.cpp*
```
#include "standardwindow.h"

StandardWindow::StandardWindow(QWidget *parent)
    : QMainWindow{parent}
{

}
```
*main.cpp*
```
include <QApplication>

#include "standardwindow.h"

iint main(int argc, char *argv[])
{
    QApplication app(argc, argv);                 // this app object captures the process
    StandardWindow wnd;                           // creation of “wnd” object of type StandardWindow, having an object of QMainWindow
    wnd.setWindowTitle("THE STANDARD WINDOW!!");  // char string of title window of QMainWindow	is set with this char string given
    wnd.show();                                   // window assigned with this memory for this object gets rendered and displayed
    return app.exec();                            // till the window is destroyed/closed until then this function doesn’t ends/returns. 
                                                  //Once application terminates, one can exit from exec() and return from this main() function
}
```
- In QT class named Application, that class captures Runtime Process Entity. 
- app object of Application runs till our process runs, and destroys only with the process’s termination.
- Sometimes below these lines of code don’t work:
```
    StandardWindow wnd;
    wnd.show();
    wnd.setWindowTitle("THE STANDARD WINDOW!!");
```
- This issue can be faced sometimes if the Q_OBJECT macro is not added in the header file because of which Meta Object Compiler isn’t included, hence Q_OBJECT in QMainWindow Class can’t be processed because of the absence of MOC.exe and the program doesn’t compiles/works.
- In QT, GUI components through which we interact in the program window like a push button, radio button, checkbox, dropdown list, etc. All these are special types of windows called “Widgets”(Window Gadgets).
- All Widgets have some properties in common, hence they have created a common base Class for the same named, QWidget. Hence it can be said that all widgets are QWidget.
- Now, in the class name StandardWindow, there are 2 possibilities for the type of widget:
  1. ***Top Level Widget***: Widget that gets rendered into the independent window. (Parent of this widget is nullptr)
  2. ***Embeddable Widget***: Widget that gets rendered in another main/independent widget window.
- If in the line of code given below, if the value of the parent is not nullptr, then that widget will be rendered into the parent widget’s independent window & this widget will be an embeddable widget of that parent.
```
explicit StandardWindow(QWidget *parent = nullptr);
```
### Control Flow Difference
- ***Console-Based App***: The application knows what is to be done from Start to End. Characteristic feature:  Has absolute clarity of what is to be done next. The only condition is if a call is made to blocking fn, & if its unblocking is not dependent on the user’s input then it can be indefinitely blocked. For example, scanf().
- ***Graphical-Based App***:  The application has the behaviour like Console-Based App until a certain point but after that point based upon the input from the user or input devices in the client GUI window. The process follows the process based on the inputs provided. And is called event-driven architecture. 1 of these events propels the application to close/terminate itself(like clicking on a close button).
- This event-driven Architecture can be implemented in 2 ways:
  1. Using CallBack Mechanism
  2. Using Signal & Slot Mechanism (Specific to QT)

### More on QT
- QT is not an interpreter.
- In an interpreted programming language, interpreter is present at run-time, to handle callback fn OS is present for the same at Runtime.
- In case of QT, it's not present in run-time, but the QT libraries are present/loaded in process's virtual address space. But QT as an entity is not present.
- Whenever signal is emitted, which slot is to be called for that corresponding signal. This type of calls that are statically resolved, that calls has to be placed statically. And few calls are resolved at runtime only.
- Like, as Derived Class Object's function is called on the Base Class Object of that Derived class object in runtime, same technique is used to call/execute SLOT using RTTI.
- In statically type language, using RTTI to pull off this is really skillful stuff.
- RTTI: In C++, RTTI (Run-time type information) is a mechanism that exposes information about an object’s data type at runtime and is available only for the classes which have at least one virtual function. It allows the type of an object to be determined during program execution.
- NOTE: QT is not an interpreter or OS, that decides at runtime that a signal has emitted, and corresponding SLOT is to be executed for the same at runtime.
- QT is present in the form of libraries. 
- QT's MOC.exe is divine and plays the crucial role. As whenever signal is emitted, corresponding SLOT call is placed at either compile time or which signal is to be emitted is decided at runtime then the SLOT for the same is determined & run/executed at runtime. This leads to the conclusion, of what high level RTTI is implemented & used in QT.
- And Since RTTI is used here, QT program is a bit slower as compared to pure cpp program because of usage of RTTI.

### Signals & Slots
- In which class, the signal is created. Every Object of that class can emmit that signal. And each emission of the signal from diff objects of that class will be considered differently and will be handled accordingly with context of that object that emitted the signal.
- Now, this signal can be emit in 2 ways:
  - When an object wants to emit a signal, then that object must call a member function that internally uses an emit statement to emit a signal.
  - Signals are emitted by objects when they change their state in a way that may be interesting to the outside world. This is all the object does to communicate.

- In Class of QT: explore these stuff:
	- Member Functions
	- Inherited From
	- Signals
	- Slots
	
- Can be done:
	Can implement self QLineEdit class, named cppQLineEdit;
- Slots are public member functions.
- object created from QWidget class, it takes form of window bcz it is a container widget, in which window with client area gets created.
- This object gets created in memory, with QWidget type.
- There can be delay in creating memory for a object, & rendering that object from the memory.

- While creating QT Project for Gravitational Calculator. 
	- It is inherited fron the Base Class named QDialog, & have added Q_OBJECT while declaring the class in the project.
- There are 3 principal stratergies named Layout, Grid & Geometry by which a programmer can describe/specify how a widget should be laid on the container widget.
- Grid is easy and widely used in professional domain.
