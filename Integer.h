class Integer {
    private:
    unsigned int length;
    unsigned int cap;
    bool pos;
    unsigned long long* ptr;
    void alloc(int n);
    void init();
    bool isZero();

    public:
    long long size() {
        if (pos) return *ptr;
        else return -*ptr;
    }
    unsigned int capacity() { return cap; }
    Integer() { init(); }
    Integer(bool);
    Integer(unsigned char initial_value) { init(); *ptr = initial_value; }
    Integer(char);
    Integer(unsigned short initial_value) { init(); *ptr = initial_value; }
    Integer(short);
    Integer(unsigned long initial_value) { init(); *ptr = initial_value; }
    Integer(long);
    Integer(unsigned int initial_value) { init(); *ptr = initial_value; }
    Integer(int);
    Integer(unsigned long long initial_value) { init(); *ptr = initial_value; }
    Integer(long long);
    Integer(const char*);
    ~Integer();

    bool operator==(Integer&);
    bool operator!=(Integer& A) { return !this->operator==(A); }
    bool operator<(Integer& A) { return !this->operator>=(A); }
    bool operator>(Integer& A) { return !this->operator<=(A); }
    bool operator<=(Integer&);
    bool operator>=(Integer&);

    Integer operator+(Integer& A);
};