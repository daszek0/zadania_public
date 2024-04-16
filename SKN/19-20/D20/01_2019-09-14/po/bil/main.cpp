#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	float amount, price;
	int amountPLN, amountGR, pricePLN, priceGR;
	int tickets;
	cin>>amountPLN>>amountGR;
	cin>>pricePLN>>priceGR;
	amount = amountPLN + (amountGR*0.01);
	price = pricePLN + (priceGR*0.01);
	tickets = floor(amount/price);
	cout<<tickets;
    return 0;
}
