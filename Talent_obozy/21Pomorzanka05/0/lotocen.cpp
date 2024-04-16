#include <stdio.h>
#include <random>

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
	unsigned x;
	scanf("%u",&x);
	if(x>67108863)
	{
		printf("POZA ZAKRESEM\n");
		return 0;
	}
	unsigned wyn=randomize(x);
	printf("%u\n",wyn);
}
