// Jakub Daszkiewicz
// zadanie lot check

#include <cstdio>
#include <random>

using namespace std;

unsigned randomize(unsigned x)
{
	for(unsigned i=0;i<100000;++i)
	{
		std::mt19937 gen(x);
		unsigned tmp=std::uniform_int_distribution<unsigned>(0,4294967295)(gen);
		x=(tmp^(tmp>>26)^x)&(67108863);
	}
	x^=12404060;
	return x;
}

int main()
{
    unsigned res = randomize(0U);
    unsigned check;
    unsigned input = 0U;
    for (unsigned i = 1; i <= 10; i++)
    {
        check = randomize(i);
        if (check > res)
        {
            input = i;
        }
    }
    printf("%u %u\n", input, res);
    return 0;
}