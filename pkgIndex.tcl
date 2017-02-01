#
# Tcl package index file
#
package ifneeded snappy 0.4 \
    [list load [file join $dir libsnappy0.4.so] snappy]
