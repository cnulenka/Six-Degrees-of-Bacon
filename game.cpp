#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
int main()
{
	ll parent[12000];
	memset(parent,-1,sizeof(parent));
	map<ll,string> map1;
	map<string,ll> map12;
	cout<<"\nReading actors.......\n\n";
	ifstream ifile;
	ifile.open("actors.txt");
	string line;ll n;char c;
	while(ifile>>n)
	{	//cout<<n;
		ifile>>c;
		getline(ifile,line);
		//cout<<line<<"\n";
		map1.insert(pair<ll,string>(n,line));
		map12.insert(pair<string,ll>(line,n));
	}
	ifile.close();
	map<ll,string>::iterator it;
	 /*for(it=map1.begin();it!=map1.end();it++)   ////Display map1
    	{cout<<it->first<<" "<<it->second<<"\n";}*/
    cout<<"\nReading movies.......\n\n";
    map<ll,string> map2;
	ifile.open("movies.txt");
	while(ifile>>n)
	{	//cout<<n;
		ifile>>c;
		getline(ifile,line);
		//cout<<line<<"\n";
		map2.insert(pair<ll,string>(n,line));
	}
	ifile.close();
	cout<<"\nReading Parent.......\n\n";
	ifile.open("parent.txt");
	ll n1,n2;
	map<pair<ll,ll>,ll > info;
	while(ifile>>n)
	{	ifile>>n1>>n2;
		parent[n]=n1;
		info.insert(pair<pair<ll,ll>,ll>(make_pair(n,n1),n2));
	}
	cout<<"\nLets Start The Game....\n\n";
	while(1)
	{cout<<"Enter the Name of actor[Name Format: Aaaa Bbbb Cccc]or 'stop' to quit:\n";
		char str[30];
		scanf("%[^\n]s",str);
		if(strcmp(str,"stop")==0)
			break;
		map<string,ll>::iterator l;
		cout<<"\n";
		l=map12.find(str);
		if(l!=map12.end())
			{ll key=l->second;
				ll count=0;
					while(parent[key]!=-1)
				{count++;
					ll p=parent[key];
					cout<<map1[key]<<" was with "<<map1[p]<<" in "<<map2[info[make_pair(key,p)]]<<"\n";
					key=p;		
				}
				cout<<"Degree or Bacon number is: "<<count<<"\n\n";
				getchar();
			}
		else
			{cout<<"Actor not in data base/Check the name format:\n\n";
						getchar();}
	}

	cout << "\nThanks for playing!\n\n";
	return 0;
}