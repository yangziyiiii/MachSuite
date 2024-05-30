set moduleName spmv_Pipeline_spmv_2
set isTopModule 0
set isCombinational 0
set isDatapathOnly 0
set isPipelined 1
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set hasInterrupt 0
set DLRegFirstOffset 0
set DLRegItemOffset 0
set C_modelName {spmv_Pipeline_spmv_2}
set C_modelType { void 0 }
set C_modelArgList {
	{ sext_ln16 int 32 regular  }
	{ wide_trip_count int 32 regular  }
	{ val_r int 64 regular {array 1666 { 1 3 } 1 1 }  }
	{ cols int 32 regular {array 1666 { 1 3 } 1 1 }  }
	{ vec int 64 regular {array 494 { 1 3 } 1 1 }  }
	{ sum_out double 64 regular {pointer 1}  }
}
set hasAXIMCache 0
set AXIMCacheInstList { }
set C_modelArgMapList {[ 
	{ "Name" : "sext_ln16", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "wide_trip_count", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "val_r", "interface" : "memory", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "cols", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "vec", "interface" : "memory", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "sum_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 19
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ sext_ln16 sc_in sc_lv 32 signal 0 } 
	{ wide_trip_count sc_in sc_lv 32 signal 1 } 
	{ val_r_address0 sc_out sc_lv 11 signal 2 } 
	{ val_r_ce0 sc_out sc_logic 1 signal 2 } 
	{ val_r_q0 sc_in sc_lv 64 signal 2 } 
	{ cols_address0 sc_out sc_lv 11 signal 3 } 
	{ cols_ce0 sc_out sc_logic 1 signal 3 } 
	{ cols_q0 sc_in sc_lv 32 signal 3 } 
	{ vec_address0 sc_out sc_lv 9 signal 4 } 
	{ vec_ce0 sc_out sc_logic 1 signal 4 } 
	{ vec_q0 sc_in sc_lv 64 signal 4 } 
	{ sum_out sc_out sc_lv 64 signal 5 } 
	{ sum_out_ap_vld sc_out sc_logic 1 outvld 5 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "sext_ln16", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "sext_ln16", "role": "default" }} , 
 	{ "name": "wide_trip_count", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "wide_trip_count", "role": "default" }} , 
 	{ "name": "val_r_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "val_r", "role": "address0" }} , 
 	{ "name": "val_r_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "val_r", "role": "ce0" }} , 
 	{ "name": "val_r_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "val_r", "role": "q0" }} , 
 	{ "name": "cols_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "cols", "role": "address0" }} , 
 	{ "name": "cols_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "cols", "role": "ce0" }} , 
 	{ "name": "cols_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "cols", "role": "q0" }} , 
 	{ "name": "vec_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "vec", "role": "address0" }} , 
 	{ "name": "vec_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vec", "role": "ce0" }} , 
 	{ "name": "vec_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "vec", "role": "q0" }} , 
 	{ "name": "sum_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "sum_out", "role": "default" }} , 
 	{ "name": "sum_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "sum_out", "role": "ap_vld" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3"],
		"CDFG" : "spmv_Pipeline_spmv_2",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "sext_ln16", "Type" : "None", "Direction" : "I"},
			{"Name" : "wide_trip_count", "Type" : "None", "Direction" : "I"},
			{"Name" : "val_r", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "cols", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "vec", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "sum_out", "Type" : "Vld", "Direction" : "O"}],
		"Loop" : [
			{"Name" : "spmv_2", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "4", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter0", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage1", "LastStateIter" : "ap_enable_reg_pp0_iter3", "LastStateBlock" : "ap_block_pp0_stage1_subdone", "QuitState" : "ap_ST_fsm_pp0_stage1", "QuitStateIter" : "ap_enable_reg_pp0_iter3", "QuitStateBlock" : "ap_block_pp0_stage1_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dadd_64ns_64ns_64_5_full_dsp_1_U1", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dmul_64ns_64ns_64_5_max_dsp_1_U2", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.flow_control_loop_pipe_sequential_init_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	spmv_Pipeline_spmv_2 {
		sext_ln16 {Type I LastRead 0 FirstWrite -1}
		wide_trip_count {Type I LastRead 0 FirstWrite -1}
		val_r {Type I LastRead 1 FirstWrite -1}
		cols {Type I LastRead 1 FirstWrite -1}
		vec {Type I LastRead 2 FirstWrite -1}
		sum_out {Type O LastRead -1 FirstWrite 9}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "-1", "Max" : "-1"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	sext_ln16 { ap_none {  { sext_ln16 in_data 0 32 } } }
	wide_trip_count { ap_none {  { wide_trip_count in_data 0 32 } } }
	val_r { ap_memory {  { val_r_address0 mem_address 1 11 }  { val_r_ce0 mem_ce 1 1 }  { val_r_q0 mem_dout 0 64 } } }
	cols { ap_memory {  { cols_address0 mem_address 1 11 }  { cols_ce0 mem_ce 1 1 }  { cols_q0 in_data 0 32 } } }
	vec { ap_memory {  { vec_address0 mem_address 1 9 }  { vec_ce0 mem_ce 1 1 }  { vec_q0 mem_dout 0 64 } } }
	sum_out { ap_vld {  { sum_out out_data 1 64 }  { sum_out_ap_vld out_vld 1 1 } } }
}
