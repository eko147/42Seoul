#include "Zombie.hpp"

int main()
{
    Zombie myZombie("stack1");
    randomChump("stack2");
    Zombie *heap = newZombie("heap");
    heap->announce();
    delete heap;
    return (0);
}