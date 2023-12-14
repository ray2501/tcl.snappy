# -*- tcl -*-
# Tcl package index file, version 1.1
#
if {[package vsatisfies [package provide Tcl] 9.0-]} {
    package ifneeded snappy 0.12 \
	    [list load [file join $dir libtcl9snappy0.12.so] [string totitle snappy]]
} else {
    package ifneeded snappy 0.12 \
	    [list load [file join $dir libsnappy0.12.so] [string totitle snappy]]
}
