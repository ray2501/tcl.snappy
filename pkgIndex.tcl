#
# Tcl package index file
#
package ifneeded snappy 0.2 \
    [list load [file join $dir libsnappy0.2.so] snappy]
