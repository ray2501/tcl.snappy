#
# Tcl package index file
#
package ifneeded snappy 0.3 \
    [list load [file join $dir libsnappy0.3.so] snappy]
