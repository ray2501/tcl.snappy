#
# Tcl package index file
#
package ifneeded snappy 0.9 \
    [list load [file join $dir libsnappy0.9.so] snappy]
