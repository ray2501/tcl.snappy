#
# Tcl package index file
#
package ifneeded snappy 0.5 \
    [list load [file join $dir libsnappy0.5.so] snappy]
