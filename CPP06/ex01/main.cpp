#include "Serializer.hpp"

int main()
{
    Data a(1, 2);

    Data* ptr = &a;

    std::cerr << "Data's address before serialize = " << &a << std::endl;

    uintptr_t intPtr = Serializer::serialize(ptr);

    std::cerr << "Data's address after serialize = " << Serializer::deserialize(intPtr) << std::endl;
}