/* Generated by libdrgn/build-aux/gen_arch_inc_strswitch.py. */

#include "arch_register_layout.h" // IWYU pragma: export

static const struct drgn_register registers[] = {
	{
		.names = (const char * const []){
			"rax",
		},
		.num_names = 1,
		.regno = DRGN_REGISTER_NUMBER(rax),
	},
	{
		.names = (const char * const []){
			"rdx",
		},
		.num_names = 1,
		.regno = DRGN_REGISTER_NUMBER(rdx),
	},
	{
		.names = (const char * const []){
			"rcx",
		},
		.num_names = 1,
		.regno = DRGN_REGISTER_NUMBER(rcx),
	},
	{
		.names = (const char * const []){
			"rbx",
		},
		.num_names = 1,
		.regno = DRGN_REGISTER_NUMBER(rbx),
	},
	{
		.names = (const char * const []){
			"rsi",
		},
		.num_names = 1,
		.regno = DRGN_REGISTER_NUMBER(rsi),
	},
	{
		.names = (const char * const []){
			"rdi",
		},
		.num_names = 1,
		.regno = DRGN_REGISTER_NUMBER(rdi),
	},
	{
		.names = (const char * const []){
			"rbp",
		},
		.num_names = 1,
		.regno = DRGN_REGISTER_NUMBER(rbp),
	},
	{
		.names = (const char * const []){
			"rsp",
		},
		.num_names = 1,
		.regno = DRGN_REGISTER_NUMBER(rsp),
	},
	{
		.names = (const char * const []){
			"r8",
		},
		.num_names = 1,
		.regno = DRGN_REGISTER_NUMBER(r8),
	},
	{
		.names = (const char * const []){
			"r9",
		},
		.num_names = 1,
		.regno = DRGN_REGISTER_NUMBER(r9),
	},
	{
		.names = (const char * const []){
			"r10",
		},
		.num_names = 1,
		.regno = DRGN_REGISTER_NUMBER(r10),
	},
	{
		.names = (const char * const []){
			"r11",
		},
		.num_names = 1,
		.regno = DRGN_REGISTER_NUMBER(r11),
	},
	{
		.names = (const char * const []){
			"r12",
		},
		.num_names = 1,
		.regno = DRGN_REGISTER_NUMBER(r12),
	},
	{
		.names = (const char * const []){
			"r13",
		},
		.num_names = 1,
		.regno = DRGN_REGISTER_NUMBER(r13),
	},
	{
		.names = (const char * const []){
			"r14",
		},
		.num_names = 1,
		.regno = DRGN_REGISTER_NUMBER(r14),
	},
	{
		.names = (const char * const []){
			"r15",
		},
		.num_names = 1,
		.regno = DRGN_REGISTER_NUMBER(r15),
	},
	{
		.names = (const char * const []){
			"rip",
		},
		.num_names = 1,
		.regno = DRGN_REGISTER_NUMBER(rip),
	},
};

static const struct drgn_register *register_by_name(const char *name)
{
	/* Generated by libdrgn/build-aux/gen_strswitch.py. */
	switch (1) {
	default: {
		#define strswitch0_args(str) \
			const char *strswitch0_str = (str);
		strswitch0_args(
	            name
		)
		#undef strswitch0_args
		if (strswitch0_str[0] == 'r') {
			if (strswitch0_str[1] == '1') {
				if (strswitch0_str[2] == '0') {
					if (strswitch0_str[3] == '\0') {
						strswitch0_case10:
		return &registers[10];
						goto strswitch0_case11;
					} else {
						goto strswitch0_default;
					}
				} else if (strswitch0_str[2] == '1') {
					if (strswitch0_str[3] == '\0') {
						strswitch0_case11:
		return &registers[11];
						goto strswitch0_case12;
					} else {
						goto strswitch0_default;
					}
				} else if (strswitch0_str[2] == '2') {
					if (strswitch0_str[3] == '\0') {
						strswitch0_case12:
		return &registers[12];
						goto strswitch0_case13;
					} else {
						goto strswitch0_default;
					}
				} else if (strswitch0_str[2] == '3') {
					if (strswitch0_str[3] == '\0') {
						strswitch0_case13:
		return &registers[13];
						goto strswitch0_case14;
					} else {
						goto strswitch0_default;
					}
				} else if (strswitch0_str[2] == '4') {
					if (strswitch0_str[3] == '\0') {
						strswitch0_case14:
		return &registers[14];
						goto strswitch0_case15;
					} else {
						goto strswitch0_default;
					}
				} else if (strswitch0_str[2] == '5') {
					if (strswitch0_str[3] == '\0') {
						strswitch0_case15:
		return &registers[15];
						goto strswitch0_case16;
					} else {
						goto strswitch0_default;
					}
				} else {
					goto strswitch0_default;
				}
			} else if (strswitch0_str[1] == '8') {
				if (strswitch0_str[2] == '\0') {
					strswitch0_case8:
		return &registers[8];
					goto strswitch0_case9;
				} else {
					goto strswitch0_default;
				}
			} else if (strswitch0_str[1] == '9') {
				if (strswitch0_str[2] == '\0') {
					strswitch0_case9:
		return &registers[9];
					goto strswitch0_case10;
				} else {
					goto strswitch0_default;
				}
			} else if (strswitch0_str[1] == 'a') {
				if (strswitch0_str[2] == 'x' && strswitch0_str[3] == '\0') {
		return &registers[0];
					goto strswitch0_case1;
				} else {
					goto strswitch0_default;
				}
			} else if (strswitch0_str[1] == 'b') {
				if (strswitch0_str[2] == 'p') {
					if (strswitch0_str[3] == '\0') {
						strswitch0_case6:
		return &registers[6];
						goto strswitch0_case7;
					} else {
						goto strswitch0_default;
					}
				} else if (strswitch0_str[2] == 'x') {
					if (strswitch0_str[3] == '\0') {
						strswitch0_case3:
		return &registers[3];
						goto strswitch0_case4;
					} else {
						goto strswitch0_default;
					}
				} else {
					goto strswitch0_default;
				}
			} else if (strswitch0_str[1] == 'c') {
				if (strswitch0_str[2] == 'x' && strswitch0_str[3] == '\0') {
					strswitch0_case2:
		return &registers[2];
					goto strswitch0_case3;
				} else {
					goto strswitch0_default;
				}
			} else if (strswitch0_str[1] == 'd') {
				if (strswitch0_str[2] == 'i') {
					if (strswitch0_str[3] == '\0') {
						strswitch0_case5:
		return &registers[5];
						goto strswitch0_case6;
					} else {
						goto strswitch0_default;
					}
				} else if (strswitch0_str[2] == 'x') {
					if (strswitch0_str[3] == '\0') {
						strswitch0_case1:
		return &registers[1];
						goto strswitch0_case2;
					} else {
						goto strswitch0_default;
					}
				} else {
					goto strswitch0_default;
				}
			} else if (strswitch0_str[1] == 'i') {
				if (strswitch0_str[2] == 'p' && strswitch0_str[3] == '\0') {
					strswitch0_case16:
		return &registers[16];
					goto strswitch0_default;
				} else {
					goto strswitch0_default;
				}
			} else if (strswitch0_str[1] == 's') {
				if (strswitch0_str[2] == 'i') {
					if (strswitch0_str[3] == '\0') {
						strswitch0_case4:
		return &registers[4];
						goto strswitch0_case5;
					} else {
						goto strswitch0_default;
					}
				} else if (strswitch0_str[2] == 'p') {
					if (strswitch0_str[3] == '\0') {
						strswitch0_case7:
		return &registers[7];
						goto strswitch0_case8;
					} else {
						goto strswitch0_default;
					}
				} else {
					goto strswitch0_default;
				}
			} else {
				goto strswitch0_default;
			}
		} else {
			strswitch0_default:
		return NULL;
		}
	}
	}
}

#define DRGN_ARCHITECTURE_REGISTERS \
	.register_layout = register_layout, \
	.dwarf_regno_to_internal = dwarf_regno_to_internal, \
	.registers = registers, \
	.num_registers = 17, \
	.register_by_name = register_by_name
