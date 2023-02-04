
- Why Template is needed?
  While implementing the function, 3 things are done: fn declaration, fn definition & fn call. While declaring the function, the function parameter list parameter's data type if committed while writing src code, then while calling that fn, if logic is to be implemented on the multiple values of same data type as of parameter list's parameter then everything will work fine, but if data type changes then in principle/on paper logic this will not work because of type system barrier.
  For example, while writing fn for sorting the elements in an array of certain specific data types, Logic remains the same, but while implementing, one has to write a different piece of code for handling different data types of elements if the template is not used.
  If we have implemented this logic, suppose by taking a ptr, then we have typecast that ptr to the type it will point, which can be diff if diff data types of params are used.
  While declaring/defining the fn one can give (void* ptr) then ptr[i] cannot be interpreted by the compiler, but while implementing the logic it has to be typecasted. When this fn will be called when defined with (void* ptr), then in the current fn call, the data type of the arr passed cannot be identified by C Compiler. Hence typecasting is necessary.
 
- In simple terms,
  In generic programming, void* can be given -> but the value can't be interpreted by the compiler bcz of its design until it is typecasted to the type to type of data to which it's pointing. 
  So, in order to use it in fn logic implementation, one has to typecast that ptr to that specific data type based on the need, & hence it can't be generic.
- The solution to this problem is why Template is introduced and used.

- To overcome this repetition of the writing src based on the data type, in C++ we have a paradigm implemented named generic programming paradigm.
This paradigm has two features:
  - Function Template: generic algorithm can be implemented using this.
  - Class Template: generic datatype can be implemented using this.
 
- Binding: Mapping/Association of an abstract entity with a relatively more concrete entity.
  Types of Binding:
    - Very Early Binding: Phase when src code is being written.
    - Early Binding:      Phase when src code is compiled/build.  (Eg. Static linked Library)
    - Late Binding:       Phase when the executable is running.   (Eg. Dynamic Linked Library)

- Formal parameters provide the prevention of early binding of the variables in terms of which algorithm is written & the actual data named by those variables.
- But early binding of the variable name and variable type cannot be prevented by formal parameters, cz it is essentially is data definition statement.
- Very early binding of variable names in which fns are written and it's data type, because of which we are not getting reusability across the type -> This is the main ROOT CAUSE bcz of which we face this issue and hence Function Template is required.
- Function Template: It allows us to differ the binding of formal parameters & it's data type until the fn call.

- Template is a keyword in C++ and while writing template<> and adding a parameter list inside <> separated with a comma, that is called a Template Parameter List.

- If typename is a type annotation in a template parameter list, then you are a type parameter in a template parameter list.
- Template is Brahmastra of C++.
- If it can't be done using Template then you can’t do it in C++.

test<Call parameter>();
parameter list variable ni template i.e., the template parameter list is used at RHS, used to assign to another variable at LHS.

What happens internally when using a template?
- When template func is called in the program, the compiler replaces all <T> with the data type that is used while fn is called and a new function is made with that data type.
- If fn has the same name, but diff <T> values, then diff many new fn will be created & at that instance fn overloading kicks in, as the data type of the newly formed fn’s formal list parameters will be diff & hence their mangled name will be diff and will be called as required with the values passed while that fn call.

- Main points to be noted for template:
  - Difference between Class template, class, & class object:
    array -> class template 
    array<int, ARRAY_LENGTH> -> class 
    array<int, ARRAY_LENGTH> -> iarr -> OBJECT 
  - Method for Class template instantiation:
    For fn/class template instantiation: Give call parameter to each parameter of the parameter list params of the class/fn template.
    And if the parameter is type parameter, then define that type in your program serves as call parameter.
    If Non-type parameter, then const integer expression serves as class parameter.
  - Syntax of class template instantiation is == class name. This can be used exactly like we use data type while declaring object, ptr, reference,           return type annotation, rvalue reference and all.
  
