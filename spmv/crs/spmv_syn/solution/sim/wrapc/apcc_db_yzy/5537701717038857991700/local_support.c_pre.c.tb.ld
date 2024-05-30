#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/yzy/MachSuite/spmv/crs/spmv_syn/solution/sim/wrapc/apcc_db_yzy/5537701717038857991700/local_support.c_pre.c.tb.ld.bc ${1+"$@"}
