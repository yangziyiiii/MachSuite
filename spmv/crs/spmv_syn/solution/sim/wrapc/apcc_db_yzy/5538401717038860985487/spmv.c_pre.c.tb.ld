#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/yzy/MachSuite/spmv/crs/spmv_syn/solution/sim/wrapc/apcc_db_yzy/5538401717038860985487/spmv.c_pre.c.tb.ld.bc ${1+"$@"}
