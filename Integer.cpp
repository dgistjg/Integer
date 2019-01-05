#include "Integer.h"

void Integer::init() {
    length = 1;
    cap = 1;
    pos = true;
    ptr = new unsigned long long[1];
    *ptr = 0;
 }

bool Integer::isZero() {
    if (length == 1 && *ptr == 0) return true;
    else return false;
}

void Integer::alloc(int n) {
    if (length + n > cap) {
        cap <<= 1;
        unsigned long long* next_ptr = new unsigned long long[cap];
        length += n;

        for (unsigned int i = 0; i < length; ++i) {
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

Integer::Integer(const char*) {

}

Integer::~Integer() {
    delete[] ptr;
}

bool Integer::operator==(Integer& A) {
    if (this->pos != A.pos) {
        if (this->isZero() && A.isZero()) return true;
        else return false;
    }
    else {
        if (this->length == A.length) {
            for (unsigned int i = 0; i < this->length; ++i) {
                if (this->ptr[i] != A.ptr[i]) return false;
            }
            return true;
        }
        else return false;
    }
}

bool Integer::operator<=(Integer& A) {
    if (this->pos) {
        if (A.pos) {
            if (this->length == A.length) {
                for (unsigned int i = this->length - 1; ; --i) {
                    if (this->ptr[i] != A.ptr[i]) return this->ptr[i] < A.ptr[i];
                    if (i == 0) return true;
                }
                return true;
            }
            else return this->length < A.length;
        }
        else {
            if (this->isZero() && A.isZero()) return true;
            else return false;
        }
    }
    else {
        if (A.pos) return true;
        else {
            if (this->length == A.length) {
                for (unsigned int i = this->length - 1; ; --i) {
                    if (this->ptr[i] != A.ptr[i]) return this->ptr[i] > A.ptr[i];
                    if (i == 0) return true;
                }
                return true;
            }
            else return this->length > A.length;
        }
    }
}

bool Integer::operator>=(Integer& A) {
    if (this->pos) {
        if (A.pos) {
            if (this->length == A.length) {
                for (unsigned int i = this->length - 1; ; --i) {
                    if (this->ptr[i] != A.ptr[i]) return this->ptr[i] > A.ptr[i];
                    if (i == 0) return true;
                }
            }
            else return this->length > A.length;
        }
        else return true;
    }
    else {
        if (A.pos) {
            if (this->isZero() && A.isZero()) return true;
            else return false;
        }
        else {
            if (this->length == A.length) {
                for (unsigned int i = this->length - 1; ; --i) {
                    if (this->ptr[i] != A.ptr[i]) return this->ptr[i] < A.ptr[i];
                    if (i == 0) return true;
                }
                return true;
            }
            else return this->length < A.length;
        }
    }
}

Integer Integer::operator+(Integer& A) {
    if (this->pos == A.pos) {
        Integer ret;
        ret.pos = this->pos;

        unsigned int up, down;
        up = this->length > A.length ? this->length : A.length;
        down = this->length < A.length ? this->length : A.length;
        
        ret.alloc(up);
        
        bool carry = false;
        for (unsigned int i = 0; i < down; ++i) {
            ret.ptr[i] = this->ptr[i] + A.ptr[i];
            if (carry) {
                if (ret.ptr[i] < this->ptr[i]) {
                    ret.ptr[i]++;
                }
                else {
                    ret.ptr[i]++;
                    if (ret.ptr[i]) carry = false;
                }
            }
            else {
                if (ret.ptr[i] < this->ptr[i]) carry = true;
            }
        }
    }
    else {
        //return operator-(Integer& A);
    }
}