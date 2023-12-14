# -*- tcl -*-
# Tcl package index file, version 1.1
#
if {[package vsatisfies [package provide Tcl] 9.0-]} {
    package ifneeded snappy 0.11 \
	    [list load [file join $dir libtcl9snappy0.11.so] [string totitle snappy]]
} else {
    package ifneeded snappy 0.11 \
	    [list load [file join $dir libsnappy0.11.so] [string totitle snappy]]
}
