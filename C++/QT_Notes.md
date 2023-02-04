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
