tcl.snappy
=====

[Snappy] (http://google.github.io/snappy/) is a compression/decompression library. It does not aim for maximum
compression, or compatibility with any other compression library; instead,
it aims for very high speeds and reasonable compression.

This extension is a Tcl extension for snappy library.


License
=====

2-Clause BSD license


UNIX BUILD
=====

Building under most UNIX systems is easy, just run the configure script
and then run make. For more information about the build process, see
the tcl/unix/README file in the Tcl src dist. The following minimal
example will install the extension in the /opt/tcl directory.

	$ cd tcl.snappy
	$ export CC=g++
	$ ./configure --prefix=/opt/tcl
	$ make
	$ make install
	
If you need setup directory containing tcl configuration (tclConfig.sh),
below is an example:

	$ cd tcl.snappy
	$ export CC=g++
	$ ./configure --with-tcl=/opt/activetcl/lib
	$ make
	$ make install


WINDOWS BUILD
=====

The recommended method to build extensions under windows is to use the
Msys + Mingw build process. This provides a Unix-style build while
generating native Windows binaries. Using the Msys + Mingw build tools
means that you can use the same configure script as per the Unix build
to create a Makefile.


Implement commands
=====

snappy::compress - accepts a string to compress.  
snappy::decompress - accepts a string to decompress.


Example
=====

    package require snappy

    set test0 "##### Hello snappy @@@@@, @@@@@ I am tickle #####"
    set test1 [snappy::compress $test0]
    set test2 [snappy::decompress $test1]

    if {[string equal $test0 $test2]==1} {
        puts "OK, get the same thing."
    }
