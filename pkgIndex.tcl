#
# Tcl package index file
#
package ifneeded snappy 0.7 \
    [list load [file join $dir libsnappy0.7.so] snappy]
