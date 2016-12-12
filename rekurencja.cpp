int pow(int a, int n){
	if(n==0) return 1;
	else return a*pow(a,n-1);
}
int wielomian(int N,int *a,int x){
	if(N==0) return *(a);
	else return *(a+N)*pow(x,N) + wielomian(N-1,a,x);
}
long long int newton(int N,int K){
	if(N<K) return 0;
	if(N>33 || K>33) return -1;
	if(K==0 || K==N) return 1;
	return N*newton(N-1, K)/(N-K);
}
int* maximum(int N,int* t){
	if(N<=0) return 0;
	if(t==0) return 0;
	N--;
	if(N>0){
		int *max = maximum(N,t);
		if(*max>=*(t+N)) return max;
	}
	return (t+N);
}
