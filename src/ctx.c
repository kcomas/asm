
#pragma once

#include <stdint.h>

#define FIELD_TYPE(NAME) FIELD_TYPE_##NAME

typedef enum {
    FIELD_TYPE(REG8),
    FIELD_TYPE(REG16),
    FIELD_TYPE(REG32),
    FIELD_TYPE(REG64),
    FIELD_TYPE(M8),
    FIELD_TYPE(M16),
    FIELD_TYPE(M32),
    FIELD_TYPE(M64),
    FIELD_TYPE(IMM8),
    FIELD_TYPE(IMM16),
    FIELD_TYPE(IMM32),
    FIELD_TYPE(IMM64),
    FIELD_TYPE(REL8),
    FIELD_TYPE(REL16),
    FIELD_TYPE(REL32)
} field_type;

#define REG_FIELD(NAME) REG_FIELD_##NAME

typedef enum {
    REG_FIELD(RAX),
    REG_FIELD(RBX),
    REG_FIELD(RCX),
    REG_FIELD(RDX),
    REG_FIELD(RSI),
    REG_FIELD(RDI),
    REG_FIELD(RBP),
    REG_FIELD(RSP),
    REG_FIELD(R8),
    REG_FIELD(R9),
    REG_FIELD(R10),
    REG_FIELD(R11),
    REG_FIELD(R12),
    REG_FIELD(R13),
    REG_FIELD(R14),
    REG_FIELD(R15)
} reg_64;

typedef struct {
    field_type type;
    union {
        reg_64 r64;
        uint8_t m8, imm8, rel8;
        uint16_t m16, imm16, rel16;
        uint32_t m32, imm32, rel32;
        uint64_t m64, imm64;
    } value;
} field;

#define INST(NAME) INST_##NAME

typedef enum {

} inst_type;

typedef struct {
    inst_type type;
    size_t bcode_idx, bcode_len, field_len;
    field fields[];
} inst;

typedef struct {
    size_t len, size;
    inst *insts[];
} text_section;

typedef struct {
    size_t bcode_size;
    text_section *text;
    void* bcode;
} ctx;
