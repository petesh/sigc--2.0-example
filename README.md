Functional examples for libsigc++-2.0
-------------------------------------

Simple example code based on the examples from the web.

example1.cpp contains code that invokes a plain-old void function.

example2.cpp contains code that invokes a member function that takes
a single parameter.

example3.cpp is similar to example2.cpp, but shows the delivery of
signals from each connected item, as well as the removal of the
connection. by remembering the sigc::connection from each connect
invocation.
