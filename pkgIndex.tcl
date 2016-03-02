#
# Tcl package index file
#
package ifneeded snappy 0.1 \
    [list load [file join $dir libsnappy0.1.so] snappy]
