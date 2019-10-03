#include <iostream>
#include <stdlib.h>
using namespace std;

int recPow(int a, int b)
{
	if(a==1 || b==1)
		return a;
	else if(b%2==0)
		return recPow(a*a,b/2);
	else if(b>2 && b%2!=0)
		return a*recPow(a*a, (b-1)/2);
}

int main(int argc, char *argv[])
{
	cout<<recPow(atoi(argv[1]),atoi(argv[2]))<<endl;
	return 0;
}

/*
Compilation and execution :
$g++ recPow.cpp -o recPow
$./recPow <int> <int>
*/
