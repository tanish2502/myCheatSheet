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
