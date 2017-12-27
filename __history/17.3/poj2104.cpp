#include<cstdio>
#include<cctype>
#include<algorithm>
#include<functional>
using namespace std;
const int len=131072;//131072;
struct tp_node{
	int l,r,mid;
	int sum;
	tp_node *lc,*rc;
	
	
}tree[len*24+10];
//int buffer[20000];
int n,q;

tp_node *forest[len+10];
int cnt;
tp_node *null=&tree[0];
int a[100010];
int b[100010];
int index[100010];
int in1,in2,in3;
int ans;
int rd(){
	int ret=0;
	int sy=1;
	char in;
	while((in=getchar())==' '||in=='\n');
	if(in=='-')sy=-1;
	else{ret+=in-'0';
	}while(isdigit(in=getchar())){
		ret=ret*10+in-'0';
	} 
	return sy*ret;
}

void builde(int root=1){
	int i,j,k;
//	printf("l=%d r=%d;",tree[root].l,tree[root].r );
	if(tree[root].l==tree[root].r){
	
		return;
	}
	else{
		tree[root].lc=&tree[cnt];
		tree[cnt].l=tree[root].l;
		tree[cnt].mid=(tree[root].l+tree[root].mid)>>1;
		tree[cnt].r=tree[root].mid;
		cnt++;
		builde(cnt-1);
		tree[root].rc=&tree[cnt];
		tree[cnt].l=tree[root].mid+1;
		tree[cnt].mid=(tree[root].r+tree[root].mid+1)>>1;
		tree[cnt].r=tree[root].r;
		
		cnt++;
		builde(cnt-1);	

//		printf("cnt=%d ",cnt);	
	}
}

void buildchain(int nu,tp_node *root,tp_node *last){
	if(root->l==root->r ){
//		printf("[%d]=%d ",root->l,nu);
		root->sum =1;
		return;
	}
	if(index[nu]<=root->mid){
		root->rc=last->rc;
		root->lc=&tree[cnt++];
			
		root->lc->l =root->l;
		root->lc->mid =(root->l+root->mid )>>1;		
		root->lc->r =root->mid;
		buildchain(nu,root->lc,last->lc);
		root->sum =root->lc->sum+root->rc->sum;	
	}else{
		root->lc=last->lc;
		root->rc=&tree[cnt++];
		root->rc->l =root->mid+1;
		root->rc->mid =(root->r+root->mid +1)>>1;		
		root->rc->r =root->r;
		buildchain(nu,root->rc,last->rc);
		root->sum =root->lc->sum+root->rc->sum;	
				
	}
	
}

void build(){
	int i;
	cnt=2;
	tree[1].l=1;
	tree[1].r=len;
	tree[1].mid=(tree[1].l+tree[1].r)>>1;
	forest[0]=&tree[1];
	builde();

	for(i=1;i<=n;i++){
		forest[i]=&tree[cnt++];
		forest[i]->l=1;
		forest[i]->r=len;
		forest[i]->mid=(1+len)>>1;
		buildchain(i-1,forest[i],forest[i-1]);
	}

}

int query(){
	int i;
	tp_node *s,*tb;
	s=forest[in1-1],tb=forest[in2];
	while(s->l!=s->r ){
	//	printf("l%d r%d k%d ",s->l,s->r,in3);
		
		if(tb->lc->sum-s->lc->sum >=in3){
	//		printf(" 1b%d s%d  |",b->lc->sum,s->lc->sum );	
			s=s->lc;
			tb=tb->lc;
		}else{
	//		printf(" 2b%d s%d  |",b->lc->sum,s->lc->sum );	
			in3-=tb->lc->sum-s->lc->sum  ;
			s=s->rc;
			tb=tb->rc;
		}
	}
	printf("%d\n",b[s->l-1]);

}




void rd3(){
	in1=rd();
	in2=rd();
	in3=rd();
}

int main(){

	n=rd();

	q=rd();
	int i=0;
	int j,k;
	for(i=0;i<n;i++){
		a[i]=rd();
		b[i]=a[i];
	}
	sort(b,b+n);

	for(i=0;i<n;i++){
		index[i]=lower_bound(b,b+n,a[i])-b+1;
	//	printf("index[%d]=%d ",i,index[i]);
	}
	build();

	for(i=0;i<q;i++){
		rd3();
		query();
	}


}













