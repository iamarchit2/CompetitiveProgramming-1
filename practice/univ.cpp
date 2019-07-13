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

	ull energy = LIMIT;
	std::vector<vector<vector<int> > > v(x, vector<vector<int> >(y), vector<int>(z));

	

	for(int i=1; i<x; ++i){
		for(int j=1; j<y; ++j){
			for(int k=1; k<z; ++k){
				v[i][j][k] = min(v[i-1][j][k],);
			}
		}
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