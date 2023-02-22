#include <iostream>
#include <string>

typedef struct {
    int         a;
    std::string b;
}   Data;

uintptr_t   serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data    *deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}

int main(void) {
    Data    d = { .a = 42, .b = "Hello World !", };
    Data    *p = &d; 

    std::cout << "p a: " << p->a << "; b: " << p->b << std::endl;
    std::cout << "p: " << p << std::endl;

    uintptr_t   u = serialize(p);
    std::cout << "u: " << u << std::endl;

    Data    *p2 = deserialize(u);
    std::cout << "p2 a: " << p2->a << "; b: " << p2->b << std::endl;
    std::cout << "p2: " << p2 << std::endl;
}