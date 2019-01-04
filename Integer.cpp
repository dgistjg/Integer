#include "Integer.h"

void Integer::init() {
    length = 1;
    cap = 1;
    pos = true;
    ptr = new unsigned long long[1];
 }

void Integer::alloc(int n) {
    if (length + n > cap) {
        cap <<= 1;
        unsigned long long* next_ptr = new unsigned long long[cap];
        length += n;

        for (int i = 0; i < length; ++i) {
            next_ptr[i] = this->ptr[i];
        }

        delete[] ptr;
        ptr = next_ptr;
    }
}

Integer::Integer(bool initial_value) {
    init();
    if (initial_value) *ptr = 1;
    else *ptr = 0;
}

Integer::Integer(char initial_value) {
    init();
    if (initial_value & (1 << (sizeof(char) * 8 - 1))) {
        pos = false;
        *ptr = -initial_value;
    }
    else *ptr = initial_value;
}

Integer::Integer(short initial_value) {
    init();
    if (initial_value & (1 << (sizeof(short) * 8 - 1))) {
        pos = false;
        *ptr = -initial_value;
    }
    else *ptr = initial_value;
}

Integer::Integer(long initial_value) {
    init();
    if (initial_value & (1L << (sizeof(long) * 8 - 1))) {
        pos = false;
        *ptr = -initial_value;
    }
    else *ptr = initial_value;
}

Integer::Integer(int initial_value) {
    init();
    if (initial_value & (1 << (sizeof(int) * 8 - 1))) {
        pos = false;
        *ptr = -initial_value;
    }
    else *ptr = initial_value;
}

Integer::Integer(long long initial_value) {
    init();
    if (initial_value & (1LL << (sizeof(long long) * 8 - 1))) {
        pos = false;
        *ptr = -initial_value;
    }
    else *ptr = initial_value;
}

Integer::~Integer() {
    delete[] ptr;
}