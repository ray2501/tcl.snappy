#
# Tcl package index file
#
package ifneeded snappy 0.8 \
    [list load [file join $dir libsnappy0.8.so] snappy]
