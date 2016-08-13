#include <iostream>
#include <sys/time.h>
#include "die.h"

Die::Die( const int n )
{
    this->sides = n; // how many sides the die has
}

int Die::roll() const
{
    // number between 1 and sides
    return 1 + (int) ( double(sides) * (std::rand() / (RAND_MAX + 1.0)));
}

void Die::initDie()
{
    // good info here:
    // http://stackoverflow.com/questions/322938/recommended-way-to-initialize-srand
    struct timeval tv;
    gettimeofday(&tv, 0);
    long int seed = tv.tv_sec ^ tv.tv_usec;
    Die::initDie(seed);
}

void Die::initDie( int seed )
{
    srand(seed);
}
