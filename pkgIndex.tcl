#
# Tcl package index file
#
package ifneeded snappy 0.10 \
    [list load [file join $dir libsnappy0.10.so] snappy]
