set SynModuleInfo {
  {SRCNAME spmv_Pipeline_spmv_2 MODELNAME spmv_Pipeline_spmv_2 RTLNAME spmv_spmv_Pipeline_spmv_2
    SUBMODULES {
      {MODELNAME spmv_dadd_64ns_64ns_64_5_full_dsp_1 RTLNAME spmv_dadd_64ns_64ns_64_5_full_dsp_1 BINDTYPE op TYPE dadd IMPL fulldsp LATENCY 4 ALLOW_PRAGMA 1}
      {MODELNAME spmv_dmul_64ns_64ns_64_5_max_dsp_1 RTLNAME spmv_dmul_64ns_64ns_64_5_max_dsp_1 BINDTYPE op TYPE dmul IMPL maxdsp LATENCY 4 ALLOW_PRAGMA 1}
      {MODELNAME spmv_flow_control_loop_pipe_sequential_init RTLNAME spmv_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME spmv_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME spmv MODELNAME spmv RTLNAME spmv IS_TOP 1}
}
