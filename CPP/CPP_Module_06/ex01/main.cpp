#include "Serializer.hpp"

int main()
{
    Data *data = new Data();
    data->name = "EJ";

    uintptr_t ptr = Serializer::serialize(data);
    std::cout << ptr << std::endl;

    Data *data_after = Serializer::deserialize(ptr); 
    std::cout << data_after->name << std::endl; 

    delete data;
    return 0;
}

