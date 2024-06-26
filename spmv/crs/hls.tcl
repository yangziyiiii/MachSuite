open_project spmv_syn

add_files spmv.c
add_files input.data
add_files check.data
add_files -tb ../../common/harness.c
add_files support.c
add_files support.h
add_files local_support.c

set_top spmv

open_solution -reset solution
set_part virtex7
create_clock -period 10
source ./spmv_dir
csynth_design
cosim_design -rtl verilog -tool xsim 

exit
