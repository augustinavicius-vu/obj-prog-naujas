#include <random>

int AtsitiktinisSkaicius(int min, int max)
{
    std::random_device seed;                                // Seed'as generatoriui
    std::mt19937 generator(seed());                         // Mersenne Twister algorythm
    std::uniform_int_distribution<int> distribution(min, max); // Random unsigned int'as tranformuojamas i int'a su numatytais reziais

    return distribution(generator);
}