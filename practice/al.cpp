#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
ll x=1;
bool comp(string temp,vector<string> &a)
{
	for(ll i=0;i<a.size();++i)
	{
		if(a[i]==temp)
		{
			a.erase(a.begin()+i);
			return true;
		}
	}
	cout<<"Case #"<<x<<": "<<temp<<endl;
	//cout<<temp;
	return false;
}
int main()
{
	ll t;
	cin>>t;

	while(t--)
	{
		string temp;
		ll n,l;
		cin>>n>>l;
		vector<string> a(n);
		for(ll i=0;i<n;++i)
			cin>>a[i];
		vector<set<char> > b(l);
		set<char> tem;
		set<char>:: iterator it;
		
		vector<vector<char> > c(l);
		for(ll i=0;i<n;++i)
		{
			for(ll j=0;j<l;++j)
			{
				b[j].insert(a[i][j]);
			}
		}
		for(ll i=0;i<l;++i)
		{
			vector<char> d;
			tem=b[i];
			for(it=tem.begin();it!=tem.end();it++)
			{
				d.push_back(*it);
			}
			c[i]=d;
		}
		// for(ll i=0;i<l;++i)
		// {
		// 	for(ll j=0;j<c[i].size();++j)
		// 	{
		// 		cout<<c[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		ll flag=0;
		
		while(a.size())
		{	
			
			if(l==1)
			{
				flag=0;
				break;
			}
			
			//for(ll i=0;i<l;++i)
			//{
				
			//}

			for(ll j=0;j<c[0].size() && flag==0;++j)
			{
				temp+=c[0][j];
				//cout<<"aaa";
				for(ll j1=0;j1<c[1].size() && flag==0;++j1)
				{
					temp+=c[1][j1];
					if(l>2)
					{
						for(ll j2=0;j2<c[2].size() && flag==0;++j2)
						{
							temp+=c[2][j2];
							if(l>3)
							{
								for(ll j3=0;j3<c[3].size() && flag==0;++j3)
								{
									temp+=c[3][j3];
									if(l>4)
									{
										for(ll j4=0;j4<c[4].size() && flag==0;++j4)
										{
											temp+=c[4][j4];
											if(l>5)
											{
												for(ll j5=0;j5<c[5].size() && flag==0;++j5)
												{
													temp+=c[5][j5];
													if(l>6)
													{
														for(ll j6=0;j6<c[6].size() && flag==0;++j6)
														{
															temp+=c[6][j6];
															if(l>7)
															{
																for(ll j7=0;j7<c[7].size() && flag==0;++j7)
																{
																	temp+=c[7][j7];
																	if(l>8)
																	{
																		for(ll j8=0;j8<c[8].size() && flag==0;++j8)
																		{
																			temp+=c[8][j8];
																			if(l>9)
																			{
																				for(ll j9=0;j9<c[9].size() && flag==0;++j9)
																				{
																					temp+=c[9][j9];
																					if(!comp(temp,a))
																					{
																						flag=1;
																						break;
																					}
																					temp.erase(temp.end()-1);
																				}
																			}
																			else if(!comp(temp,a))
																			{
																				flag=1;
																				break;
																			}
																			temp.erase(temp.end()-1);
																		}
																	}
																	else if(!comp(temp,a))
																	{
																		flag=1;
																		break;

																	}
																	temp.erase(temp.end()-1);
																}
															}
															else if(!comp(temp,a))
															{
																flag=1;
																break;
															}
															temp.erase(temp.end()-1);
														}
													}
													else if(!comp(temp,a))
													{
														flag=1;
														break;
													}
													temp.erase(temp.end()-1);
												}
											}
											else if(!comp(temp,a))
											{
												flag=1;
												break;
											}
											temp.erase(temp.end()-1);
										}

									}
									else if(!comp(temp,a))
									{
										flag=1;
										break;
									}
									temp.erase(temp.end()-1);
								}
							}
							else if(!comp(temp,a))
							{
								flag=1;
								break;
							}
							temp.erase(temp.end()-1);
						}
					}
					else if(!comp(temp,a))
					{
						flag=1;
						break;
					}
					temp.erase(temp.end()-1);
				}
				temp.erase(temp.end()-1);
			}
		}
		if(flag==0)
		{
			cout<<"Case #"<<x<<": -"<<endl;
		}
		else
		{
			// cout<<"Case #"<<x<<": "<<temp<<endl;
		}
		x++;
	}
}