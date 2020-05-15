#define mod 1000000007

void multiply(unsigned long long A[2][2],unsigned long long M[2][2]){

	unsigned long long firstValue = (A[0][0] * M[0][0] + A[0][1] * M[1][0]) % mod;
	unsigned long long secondValue = (A[0][0] * M[0][1] + A[0][1] * M[1][1])% mod;
	unsigned long long thirdValue = (A[1][0] * M[0][0] + A[1][1] * M[1][0])% mod;
	unsigned long long fourthValue = (A[1][0] * M[0][1] + A[1][1] * M[1][1])% mod;

	A[0][0] =firstValue;
	A[0][1] = secondValue;
	A[1][0] = thirdValue;
	A[1][1] = fourthValue;
	
}
void power(unsigned long long A[2][2],unsigned long long n){
	if(n==1){
		return;
	}
	power(A,n/2);
	multiply(A,A);
	if(n%2 !=0){
		unsigned long long F[2][2] = {{1,1},{1,0}};
		multiply(A,F);
	}
}
unsigned long long fib(unsigned long long n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }
    unsigned long long A[2][2] = {{1,1},{1,0}};
	power(A,n-1);
	return A[0][0];
}

unsigned long long fiboSum(unsigned long long n,unsigned long long m)
{

    return ( fib(m+2) - fib(n+1)  + mod) % mod;
}
