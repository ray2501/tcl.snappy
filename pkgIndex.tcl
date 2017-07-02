#
# Tcl package index file
#
package ifneeded snappy 0.6 \
    [list load [file join $dir libsnappy0.6.so] snappy]
