/*******************************************************************************
#  Copyright (C) 2021 Xilinx, Inc
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.
#
# *******************************************************************************/

#include "hls_stream.h"
#include "ap_int.h"
#include<iostream>

using namespace hls;
using namespace std;

void hostctrl(	ap_uint<32> scenario,
				ap_uint<32> len,
				ap_uint<32> comm,
				ap_uint<32> root_src_dst,
				ap_uint<32> function,
				ap_uint<32> msg_tag,
				ap_uint<32> buf0_type,
				ap_uint<32> buf1_type,
				ap_uint<64> addra,
				ap_uint<64> addrb,
				stream<ap_uint<32>> &cmd,
				stream<ap_uint<32>> &sts
);

int main(){
	int nerrors = 0;
	ap_uint<64> addrb;
	addrb(31,0) = 5;
	addrb(63,32) = 7;
	stream<ap_uint<32>> cmd;
	stream<ap_uint<32>> sts;
	sts.write(1);
	hostctrl(0, 1, 2, 3, 4, 5, 6, 7, 8, addrb, cmd, sts);
	nerrors += (cmd.read() != 0);
	nerrors += (cmd.read() != 1);
	nerrors += (cmd.read() != 2);
	nerrors += (cmd.read() != 3);
	nerrors += (cmd.read() != 4);
	nerrors += (cmd.read() != 5);
	nerrors += (cmd.read() != 6);
	nerrors += (cmd.read() != 7);
	nerrors += (cmd.read() != 8);
	nerrors += (cmd.read() != 0);
	nerrors += (cmd.read() != addrb(31,0));
	nerrors += (cmd.read() != addrb(63,32));
	
	return nerrors;
}
