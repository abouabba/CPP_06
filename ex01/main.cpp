# include <iostream>
# include "Serializer.hpp"
int main() {

    Data data;
    data.i = 1337;
    data.string = "abouabba";

    uintptr_t uint = 0;

    std::cout << "before serialization" << std::endl;
    std::cout << uint << std::endl;

    uint = Serializer::serialize(&data);

    std::cout << "after serialization" << std::endl;
    std::cout << uint << std::endl;

    Data* dada = Serializer::deserialize(uint);

    std::cout << dada->i << std::endl;
    std::cout << dada->string << std::endl;
}