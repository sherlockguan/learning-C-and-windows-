#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>
using namespace std;

namespace HA
{
	int baby = 1;
}	

namespace girl
{
	int baby = 10;
}

namespace A
{
	namespace B
	{
		int b = 5;
	}
}
int main()
{
	
	printf("%d\n", HA::baby);
	printf("%d\n", girl::baby);

	using namespace girl;
	printf("%d\n", baby);
	//onion
	printf("%d\n", A::B::b);

	using namespace A::B;
	printf("%d\n", b);

	return 0;
}
