#include <cstdio>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <climits>
 
using namespace std;
 
#define MAXN 100000
#define LOGN 17
 
struct node {
	int newid;
	int parent[LOGN+1];
	list<int> ch;//children
	int level;
} A[MAXN + 1];
 
int n,m;
 
struct levelnodes {
	vector<int> nodes;
} levels[MAXN+1] ;
 
void dfs(int root,int level){
	static int newidS = 1;
	A[root].level = level;
	A[root].newid = newidS;//normalize node numbers
	levels[level].nodes.push_back(newidS);
	newidS++;
	//every child in the subtree has newid > this->newid
	for(list<int>::iterator it = A[root].ch.begin(); it!=A[root].ch.end(); it++)
		dfs(*it,level+1);
}
 
vector<int> root;
 
int lca(int id,int goup){//go up
	//printf("lca up=%d on %d: %d %d %d\n",goup,id,A[id].parent[0],A[id].parent[1],A[id].parent[2]);
	while(goup>0){
		for(int i=LOGN;i>=0;i--){
			if(A[id].parent[i] == 0)
				continue;
			if(goup >= (1 << i)){
				goup -= (1 << i);
				id = A[id].parent[i];
				//printf("\t 1<<%d -> goup = %d, newid = %d\n",i,goup,id);
				break;
			}
		}
		if(A[id].parent[0] == 0 && goup)
			return -1;
	}
	return id;
}
 
int count(vector<int>& vec,int a,int b){
	vector<int>::iterator it0 = lower_bound(vec.begin(),vec.end(),a);
	//assert(it0 != vec.end());
	vector<int>::iterator it1 = lower_bound(vec.begin(),vec.end(),b);
	int c = (it1-vec.begin()) - (it0-vec.begin());
	//assert(c>0);
	return c;
}
 
int main(){
	for(int p,i=(scanf("%d",&n),1);i<=n;i++){
		scanf("%d",&p);
		if(p==0)root.push_back(i);//new tree found
		A[i].parent[0] = p;
		A[p].ch.push_back(i);//add child in parent's list
	}
	//renum nodes and store in corresponding level arrays
	for(int i=0;i<root.size();i++)
		dfs(root[i],1);
	//precalc lca
	for(int i=1;i<=LOGN;i++){
		for(int j=1;j<=n;j++){
			if(A[j].parent[i-1])
				A[j].parent[i] = A[A[j].parent[i-1]].parent[i-1];
		}
	}
 
	//queries
	for(int p,v,i=(scanf("%d",&m),0);i<m;i++){
		scanf("%d%d",&v,&p);
		int oldid = lca(v,p);
		if(oldid < 0 || p == 0){
			printf("0 ");
		} else {
			//find cound of children of lca on level
			vector<int> &lca_level = levels[A[oldid].level].nodes;
			vector<int> &cous_level = levels[A[v].level].nodes;
			
			int 	newidstart = A[oldid].newid, 
				newidstop = INT_MAX;
			{
				vector<int>::iterator lca_pos = lower_bound(lca_level.begin(),lca_level.end(),A[oldid].newid);
				assert(lca_pos!=lca_level.end());
				if(lca_pos!=lca_level.end()){
					lca_pos++;
					if(lca_pos!=lca_level.end()) newidstop = *lca_pos;
				}
			}				
			//find nodeids in levels[req_level] and count them
			//should be bounded by lca.newid and lca rightmost brother's newid
			printf("%d ",count(cous_level,newidstart,newidstop)-1);
		}
	}
	printf("\n");
	return 0;
}