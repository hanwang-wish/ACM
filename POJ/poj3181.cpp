#include <cstdio>
const int MAX_N = 1000;
const int MAX_K = 100;
const long long pow18 = 1000000000000000000ll;
struct BigInt{
	long long hi, lo;
	BigInt() : hi(0), lo(0){};
	void operator+=(BigInt& x){
		lo += x.lo;
		if(lo >= pow18){
			lo -= pow18;
			hi += 1;
		}
		hi += x.hi;
	}
	void print(){
		if(hi)
			printf("%lld%018lld\n", hi, lo);
		else
			printf("%lld\n", lo);
	};
};
int main() {
	
	/*def*/
	BigInt dp[MAX_N + 1][MAX_K + 1];
	int N, K;
		
	/*input*/
	scanf("%d%d", &N, &K);
	
	/*init*/
	dp[0][K].lo = 1;;
	
	/*dp*/
	for(int i = 1;i<=N;i++)
		for(int j = 1;j<=K;j++){
			BigInt sum;
			if(i >= j)
				for(int m = j;m<=K;m++)
					sum += dp[i-j][m];
			dp[i][j] = sum;
		}
		
	/*output*/
	BigInt res;
	for(int i = 1;i<=K;i++)
		res += dp[N][i];
	res.print();
	return 0;
}
