############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################
open_project -reset topK
set_top topK
add_files topK.cpp
add_files -tb main.cpp
open_solution -reset "final"
set_part {xq7vx690trf1157-2i} -tool vivado
create_clock -period 5 -name default
config_rtl -register_reset
config_interface -m_axi_addr64
config_schedule -relax_ii_for_timing
csynth_design -skip_cdt
