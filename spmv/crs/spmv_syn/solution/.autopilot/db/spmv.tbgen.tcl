set moduleName spmv
set isTopModule 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set hasInterrupt 0
set DLRegFirstOffset 0
set DLRegItemOffset 0
set C_modelName {spmv}
set C_modelType { void 0 }
set C_modelArgList {
	{ val_r int 64 regular {array 1666 { 1 3 } 1 1 }  }
	{ cols int 32 regular {array 1666 { 1 3 } 1 1 }  }
	{ rowDelimiters int 32 regular {array 495 { 1 1 } 1 1 }  }
	{ vec int 64 regular {array 494 { 1 3 } 1 1 }  }
	{ out_r int 64 regular {array 494 { 0 3 } 0 1 }  }
}
set hasAXIMCache 0
set AXIMCacheInstList { }
set C_modelArgMapList {[ 
	{ "Name" : "val_r", "interface" : "memory", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "cols", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "rowDelimiters", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "vec", "interface" : "memory", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "out_r", "interface" : "memory", "bitwidth" : 64, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 25
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ val_r_address0 sc_out sc_lv 11 signal 0 } 
	{ val_r_ce0 sc_out sc_logic 1 signal 0 } 
	{ val_r_q0 sc_in sc_lv 64 signal 0 } 
	{ cols_address0 sc_out sc_lv 11 signal 1 } 
	{ cols_ce0 sc_out sc_logic 1 signal 1 } 
	{ cols_q0 sc_in sc_lv 32 signal 1 } 
	{ rowDelimiters_address0 sc_out sc_lv 9 signal 2 } 
	{ rowDelimiters_ce0 sc_out sc_logic 1 signal 2 } 
	{ rowDelimiters_q0 sc_in sc_lv 32 signal 2 } 
	{ rowDelimiters_address1 sc_out sc_lv 9 signal 2 } 
	{ rowDelimiters_ce1 sc_out sc_logic 1 signal 2 } 
	{ rowDelimiters_q1 sc_in sc_lv 32 signal 2 } 
	{ vec_address0 sc_out sc_lv 9 signal 3 } 
	{ vec_ce0 sc_out sc_logic 1 signal 3 } 
	{ vec_q0 sc_in sc_lv 64 signal 3 } 
	{ out_r_address0 sc_out sc_lv 9 signal 4 } 
	{ out_r_ce0 sc_out sc_logic 1 signal 4 } 
	{ out_r_we0 sc_out sc_logic 1 signal 4 } 
	{ out_r_d0 sc_out sc_lv 64 signal 4 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "val_r_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "val_r", "role": "address0" }} , 
 	{ "name": "val_r_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "val_r", "role": "ce0" }} , 
 	{ "name": "val_r_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "val_r", "role": "q0" }} , 
 	{ "name": "cols_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "cols", "role": "address0" }} , 
 	{ "name": "cols_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "cols", "role": "ce0" }} , 
 	{ "name": "cols_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "cols", "role": "q0" }} , 
 	{ "name": "rowDelimiters_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "rowDelimiters", "role": "address0" }} , 
 	{ "name": "rowDelimiters_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "rowDelimiters", "role": "ce0" }} , 
 	{ "name": "rowDelimiters_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "rowDelimiters", "role": "q0" }} , 
 	{ "name": "rowDelimiters_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "rowDelimiters", "role": "address1" }} , 
 	{ "name": "rowDelimiters_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "rowDelimiters", "role": "ce1" }} , 
 	{ "name": "rowDelimiters_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "rowDelimiters", "role": "q1" }} , 
 	{ "name": "vec_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "vec", "role": "address0" }} , 
 	{ "name": "vec_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vec", "role": "ce0" }} , 
 	{ "name": "vec_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "vec", "role": "q0" }} , 
 	{ "name": "out_r_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "out_r", "role": "address0" }} , 
 	{ "name": "out_r_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "out_r", "role": "ce0" }} , 
 	{ "name": "out_r_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "out_r", "role": "we0" }} , 
 	{ "name": "out_r_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "out_r", "role": "d0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1"],
		"CDFG" : "spmv",
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
			{"Name" : "val_r", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_spmv_Pipeline_spmv_2_fu_94", "Port" : "val_r", "Inst_start_state" : "3", "Inst_end_state" : "4"}]},
			{"Name" : "cols", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_spmv_Pipeline_spmv_2_fu_94", "Port" : "cols", "Inst_start_state" : "3", "Inst_end_state" : "4"}]},
			{"Name" : "rowDelimiters", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "vec", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_spmv_Pipeline_spmv_2_fu_94", "Port" : "vec", "Inst_start_state" : "3", "Inst_end_state" : "4"}]},
			{"Name" : "out_r", "Type" : "Memory", "Direction" : "O"}],
		"Loop" : [
			{"Name" : "spmv_1", "PipelineType" : "no",
				"LoopDec" : {"FSMBitwidth" : "5", "FirstState" : "ap_ST_fsm_state2", "LastState" : ["ap_ST_fsm_state5"], "QuitState" : ["ap_ST_fsm_state2"], "PreState" : ["ap_ST_fsm_state1"], "PostState" : ["ap_ST_fsm_state1"], "OneDepthLoop" : "0", "OneStateBlock": ""}}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_spmv_Pipeline_spmv_2_fu_94", "Parent" : "0", "Child" : ["2", "3", "4"],
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
	{"ID" : "2", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_spmv_Pipeline_spmv_2_fu_94.dadd_64ns_64ns_64_5_full_dsp_1_U1", "Parent" : "1"},
	{"ID" : "3", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_spmv_Pipeline_spmv_2_fu_94.dmul_64ns_64ns_64_5_max_dsp_1_U2", "Parent" : "1"},
	{"ID" : "4", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_spmv_Pipeline_spmv_2_fu_94.flow_control_loop_pipe_sequential_init_U", "Parent" : "1"}]}


set ArgLastReadFirstWriteLatency {
	spmv {
		val_r {Type I LastRead 1 FirstWrite -1}
		cols {Type I LastRead 1 FirstWrite -1}
		rowDelimiters {Type I LastRead 2 FirstWrite -1}
		vec {Type I LastRead 2 FirstWrite -1}
		out_r {Type O LastRead -1 FirstWrite 4}}
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
	, {"Name" : "Interval", "Min" : "0", "Max" : "0"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	val_r { ap_memory {  { val_r_address0 mem_address 1 11 }  { val_r_ce0 mem_ce 1 1 }  { val_r_q0 mem_dout 0 64 } } }
	cols { ap_memory {  { cols_address0 mem_address 1 11 }  { cols_ce0 mem_ce 1 1 }  { cols_q0 mem_dout 0 32 } } }
	rowDelimiters { ap_memory {  { rowDelimiters_address0 mem_address 1 9 }  { rowDelimiters_ce0 mem_ce 1 1 }  { rowDelimiters_q0 mem_dout 0 32 }  { rowDelimiters_address1 MemPortADDR2 1 9 }  { rowDelimiters_ce1 MemPortCE2 1 1 }  { rowDelimiters_q1 MemPortDOUT2 0 32 } } }
	vec { ap_memory {  { vec_address0 mem_address 1 9 }  { vec_ce0 mem_ce 1 1 }  { vec_q0 mem_dout 0 64 } } }
	out_r { ap_memory {  { out_r_address0 mem_address 1 9 }  { out_r_ce0 mem_ce 1 1 }  { out_r_we0 mem_we 1 1 }  { out_r_d0 mem_din 1 64 } } }
}

set maxi_interface_dict [dict create]

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
