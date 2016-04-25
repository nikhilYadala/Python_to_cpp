#Python to C++ Translator
===========================================

This is code for a *automatic* **Python** to **C++** translator.We're trying to make simple python 
scripts fast by converting to C++.Before using this code or any of its libraries please have a look 
at the LICENSE file supplied alongwith.


Running the code
==================
Go into the folder containing the package, make it (cmd: make). The code would have got built and
to convert a python code to c++ code, send the python code as an input argument to ./translator


cmd:  ./translator <<path to the input python file>>

There shall be a output file created with the same file name but with an extension of cpp
Please Note that the output c++ code is in accordance with C++ code, and remeber to 
add the std flag to use the cpp 11 standards, if not done before


Users  Docs
===========================

Elaborate user documentation can be found in docs folder "index.html" or in Latex format.
Since project is currently under heavy development documentation is not ready yet.



Developer Docs
=======================
If you're a developer look to hack into the code,welcome!

Most of the code resides in Source directory with no prior dependencies involved except for
Google C++ testing framework.Code is very much commented and self-explanatory, still if you want to help with 
documentation or code please have a look at repo.
