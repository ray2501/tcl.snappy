#
# Tcl package index file
#
package ifneeded snappy 0.11 \
    [list load [file join $dir libsnappy0.11.so] snappy]
