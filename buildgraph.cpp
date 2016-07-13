#include<bits/stdc++.h>
using namespace std;
#define MAP map<ll,set<ll> > 
#define ll long long int
bool visited[12000];ll parent[12000],edgedata[12000][12000];
void bfs(MAP adj,ll st)
{
	queue<ll> q;
	q.push(st);
	visited[st]=true;
	while(q.size())
	{
		ll v=q.front();
		q.pop();
		set<ll> s1=adj[v];
		set <ll>::iterator it;
			 for(it = s1.begin();it != s1.end();++it)
			 {
			 	if(visited[*it]==false)
			 	{
			 		parent[*it]=v;
			 		visited[*it]=true;
			 		q.push(*it);
			 	}
			 }
	}
}
int main()
{	memset(visited,false,sizeof(visited));
memset(parent,-1,sizeof(parent));
	map<ll,string> map1;
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
	 /*for(it=map2.begin();it!=map2.end();it++) /////Display map2
    	{cout<<it->first<<" "<<it->second<<"\n";}*/

	cout<<"\nReading movie-actor.......\n\n";
	map<ll,set<ll> > map3;
	ll n1=0,k,flag=1;set<ll> s;
	ifile.open("movie-actors.txt");
	while(ifile>>n)
	{	//cout<<n;
		if(n!=n1 )
			{map3.insert(pair<ll,set<ll> >(n1,s));
						n1=n;
						s.clear();}
		ifile>>c;
		ifile>>k;
		s.insert(k);
	}
	ifile.close();
	
	map<ll,set<ll> >::iterator it1;
	/*for(it1=map3.begin();it1!=map3.end();it1++)     ///Display map3
    	{cout<<it1->first<<" ";
			set<ll> s1=it1->second;
			 set <ll>::iterator it;
			 for(it = s1.begin();it != s1.end();++it)
        cout << *it << ' ';
    	cout<<"\n";
			}*/

	cout<<"\nMaking Adjacencey List.......\n\n";			
	map<ll,set<ll> > adj;	
	for(it1=map3.begin();it1!=map3.end();it1++)
    	{	k=it1->first;
    		set<ll> s1=it1->second;
			 set <ll>::iterator it,ij;
			 for(it = s1.begin();it != s1.end();++it)
			 	{  ij=it;
			 	advance(ij,1);
			 		for(;ij != s1.end();++ij)
			 	        			{//cout << *it <<" "<<*ij<<"\n";
			 	        		adj[*it].insert(*ij);
			 	        		adj[*ij].insert(*it);
			 	        		edgedata[*it][*ij]=k;
			 	        		edgedata[*ij][*it]=k;
			 	        	}
			 	        	}
			}
			/*cout<<"\n";
			cout<<"\n";
			for(it1=adj.begin();it1!=adj.end();it1++)    ///Display Adjacencylist
    	{cout<<it1->first<<"->";
			set<ll> s1=it1->second;
			 set <ll>::iterator it;
			 for(it = s1.begin();it != s1.end();++it)
        cout << *it <<"->";
    	cout<<"\n";
			}*/
	cout<<"\nApplying BFS.......\n\n";		
	bfs(adj,63);
	cout<<"\nWriting parent array.......\n\n";	
	ofstream ofile;
	ofile.open("parent.txt");
	for(int i=0;i<12000;i++)
	if(parent[i]!=-1)
		ofile<<i<<" "<<parent[i]<<" "<<edgedata[i][parent[i]]<<"\n";	
	cout<<"THE END\n";		
	ofile.close();			
	return 0;
}