class base
{
    public:
    virtual void f1() = 0; 
    virtual void f2() { }
};

class derived : public base
{
    public:
    void f1() { }
    void f2() { }
};

int main()
{
    return 0;
}
