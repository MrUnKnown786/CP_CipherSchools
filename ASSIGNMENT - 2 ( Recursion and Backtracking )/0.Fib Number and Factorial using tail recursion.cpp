// Fib Number and Factorial using tail recursion

#include<bits/stdc++.h>
using namespace std;
 
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

int fact(int n)
{
	if(n==1) {
		return 1;
	}
	else {
		return n*fact(n-1);
	}
}
 
int main ()
{
    int n = 9;
    cout << "Fib Number : "<< fib(n) << endl;
    cout << "Factorial :"<< fact(n);
    return 0;
}
