#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/yzy/MachSuite/spmv/crs/spmv_syn/solution/sim/wrapc/apcc_db_yzy/5539041717038863948386/support.c_pre.c.tb.ld.bc ${1+"$@"}
