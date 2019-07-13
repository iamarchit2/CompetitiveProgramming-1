#include<bits/stdc++.h>
using namespace std;

#define ull long long int
#define LIMIT INT_MAX

ull get_add(ull x, ull a, ull b, ull c){
	switch(x){
		case 1: return a;
		case 2: return b;
		case 3: return c;
		default: return -1;
	}	
}

ull min_energy(ull x, ull y, ull z, ull a, ull b, ull c){
	
	if(x==0 && y==0 && z==0)
		return 0;

	if(x<0 || y<0 || z<0)
		return LIMIT;

	int xC[] = {1,0,0,1,0,1,1};
	int yC[] = {0,1,0,1,1,0,1};
	int zC[] = {0,0,1,0,1,1,1};

	ull energy = LIMIT;
	
	for(int i=0; i<7; ++i){
		energy = min(energy, min_energy(x-xC[i], y-yC[i], z-zC[i], a, b, c) + get_add(xC[i]+yC[i]+zC[i], a, b, c));
	}

	return energy;
}
int main(){
	// cout<<LIMIT<<endl;
	int t;
	cin>>t;
	while(t--){
		ull x,y,z,a,b,c;
		cin>>x>>y>>z>>a>>b>>c;

		cout<<min_energy(x,y,z,a,b,c)<<endl;

	}

}