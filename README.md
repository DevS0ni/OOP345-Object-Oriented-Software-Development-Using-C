# OOP345 - Object-Oriented Software Development Using C

* Introduction – 8%
    * basic concepts
        * Object-Oriented paradigm
        * terminology (type, declaration, definition, scope, storage duration, linkage, cv qualifiers)
        * namespaces (declaration, visibility, anonymous, good parctice)
        * interface with operating system
    * compilation
        * platforms (Visual Studio, GCC)
        * pre-processing directives
        * macros (object-like, function-like, pre-defined, good design)
        * incude
        * conditional (logical, definitional)
* Types – 16%
    * fundamental types
        * integer types (standard signed, unsigned standard, boolean, character - char, wchar_t, char16_t, char32_t)
        * floating-point types - IEEE 754 - (float, double, long double)
        * void type
    * compound types
        * pointer types (nullptr, void)
        * references (lvalue, rvalue)
        * enumerations
        * enumerations
        * arrays (one-dimensional, two-dimensional, ragged)
        * classes (declarations, definitions, data initialization, move-constructors, move assignment-operators, class variables and functions, structs, unions)
* Class Relationships - 16%
    * inheritance
        * simple inheritance (abstract and concrete classes, completing the abstract class)
        * polymorphic objects (copying operations (cloning), specializing operations for a dynamic type, run-time dynamic type identification)
        * multiple inheritance (multiple base classes, virtual inheirtance)
    * templates
        * template syntax
        * function templates (specialization, ambiguities)
        * class templates (template parameters, static members)
        * variadic templates
    * composition, aggregation, association
* Logic – 16%
    * expressions
        * precedence
        * lvalues and rvalues
        * post-fix (subscripting, member selection, increment, decrement, typeid)
        * pre-fix (increment, decrement,
        * unary (sizeof, logical, bit-wise negation, arithmetic negation, arithmetic plus, address of, indirection, cast, noexcept, throw)
        * binary (arithmetic, bit-shifting, relational, bit-wise and, bit-wise or, bit-wise exclusive-or, logical, assignment, sequential, mixed-type expressions, good design)
        * ternary
    * functions
        * simplifying syntax (auto, trailing return type, range-based for)
        * linkage
        * recursive
        * pointers to functions (arrays of pointers)
        * function objects
        * lambda expressions
    * error handling
        * exceptions (reporting and handling, standard, no exceptions)
        * standard exists (normal, abnormal)
* Memory Model - 8%
    * raw pointers
        * C-style character strings (addresses, string literals)
        * expressions (arithmetic, post-fix)
        * pointers to arrays (one-dimensional, two-dimensional)
    * smart pointers
        * exception handling (raw pointer solution, taking ownership)
        * exclusive ownership (unique_ptr)
        * shared ownership (shared_ptr)
* Standard Template Library - 16%
    * introduction to linked lists
        * overview of the STL
        * concept of a linked list (collections, nodes)
        * stack
        * queue
    * sequential containers
        * containers (vector, deque, list)
        * adapters (stack, queue)
        * iterators (inserting, removing)
    * algorithm libraries
        * functional (wrapper templates, functions, operator classes)
        * algorithms (queries, modifiers, manipulators)
        * numeric (accumulate, partial sum)
* Performance– 10%
    * multi-threading
        * performance
        * processes and threads
    * thread classes
        * thread class (member functions)
        * future library (futures, providers)
        * thread local storage duration
* Related Topics - 10%
    * file stream objects
        * class hierarchy (ios, wios)
        * file objects (connections, direct access, reading, writing)
        * binary access (input, output)
    * string class
    * platform-dependent input and output
    * comparison of C++11 and C11 syntax
    * break, continue, goto
    * C++14 and C++17
