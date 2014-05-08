Compilation and installation
============================

libKNM
------
This project use the libKNM.
A copy of this library is provided at 'sources/libKNM/libKNM.so.1.0.0'. 
Headers files are provided in the directory 'sources/libKNM/includes'.
You don't have to include headers using their full path: for instance, if you
want to include 'KError.hh', do:

    #include <KError.hh>


IHP server
----------
To compile the server, please use the provided Makefile as following:
$> make


IHP modules
-----------
You have to compile each module by yourlsef. All modules should have
a makefile in their own directory. Perform the following operations to
compile and install the needed modules:
$> make
$> make install

