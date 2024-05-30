create_project prj -part xc7v585t-ffg1761-2 -force
set_property target_language verilog [current_project]
set vivado_ver [version -short]
set COE_DIR "../../syn/verilog"
source "/home/yzy/MachSuite/spmv/crs/spmv_syn/solution/syn/verilog/spmv_dmul_64ns_64ns_64_5_max_dsp_1_ip.tcl"
source "/home/yzy/MachSuite/spmv/crs/spmv_syn/solution/syn/verilog/spmv_dadd_64ns_64ns_64_5_full_dsp_1_ip.tcl"
