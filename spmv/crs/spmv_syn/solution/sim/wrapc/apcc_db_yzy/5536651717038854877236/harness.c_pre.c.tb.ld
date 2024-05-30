#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/yzy/MachSuite/spmv/crs/spmv_syn/solution/sim/wrapc/apcc_db_yzy/5536651717038854877236/harness.c_pre.c.tb.ld.bc ${1+"$@"}
