IHP
===
Intelligent Honeypot Project

**IHP** is a security research project, which try to implement a serivce who can:
- Accept connections on a specific port(s): **Server core** and **client module**
- Analyze connection status (source, destinations, ...): **Firewall module**
- Analyze packets content and detect security issues: **IDS module**
- Redirect packets to the correct service or to a honeypot: **IDS module** and/or **honeypot module**

**IHP** architecture is modulable: the server load a **client** module (~= proxy), which handle the incoming connections and load necessary modules (**firewall** and **IDS** for instance).

## Compilation and installation ##

### libKNM ###
This project use the [libKNM](https://github.com/jpclipffel/libKNM).
A copy of this library is provided at `sources/libKNM/libKNM.so.1.0.0`. 
Headers files are provided in the directory `sources/libKNM/includes`.
You don't have to include headers using their full path: for instance, if you
want to include `KError.hh`, do:

    #include <KError.hh>


### IHP server ###
To compile the server, please use the provided Makefile as following:

    $> make


### IHP modules ###
You have to compile each module by yourself. All modules should have
a makefile in their own directory. Perform the following operations to
compile and install the needed modules:

    $> make
    $> make install

If you want to clean the temporay files after an installation, do:

    $> make fclean
