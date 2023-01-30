#include<bits/stdc++.h>
using namespace std;

void findPrimeTillN(int N, vector<int> &primes){
	int limit = sqrt(N) + 1;
	bool b[limit+1];
        memset(b, true, sizeof(b));
        b[0]=false;
        b[1]=false;
        for(int i=2;i<=limit;i++){
            if(b[i]){
                for(int j=2*i;j<=limit;j+=i)
                    b[j]=false;
                primes.push_back(i);
            }
        }
    }

void findPrimesFromMToN(int M, int N, vector<int> &primes, vector<int> &ans){

        bool isPrime[N-M+1];
        memset(isPrime, true, sizeof(isPrime));
        if(M==1)
            isPrime[0]=false;

        for(auto prime: primes){
            // cout<<prime<<" ";
            int currDivisor = ((M+prime-1)/prime)*prime;
            for(int i=currDivisor;i<=N;i+=prime){
                if(i!=prime)
                    isPrime[i-M]=false;
            }
        }
        for(int i=0;i<(N-M+1);i++){
            if(isPrime[i])
                ans.push_back(i+M);
        }
    }

vector<int> primeRange(int M, int N) {
        vector<int> primes;
        vector<int> ans;
        findPrimeTillN(N, primes);
        findPrimesFromMToN(M, N, primes, ans);
        return ans;
    }

int main() {
}
