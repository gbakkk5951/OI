#include<cstdio>
int n,A[200010],B[200010];
long long ans;
int judge(FILE*fout,FILE*flog){
	int t;
	if(fscanf(fout,"%d",&t)!=1)return fprintf(flog,"0 Unexpected EOF");
	if(t<0)return fprintf(flog,"0 t = %d is negative",t);
	if(t>2*n)return fprintf(flog,"0 t = %d is greater than 2n = %d",t,2*n);
	long long cost=0;
	for(int i=1,x,y;i<=t;i++){
		if(fscanf(fout,"%d%d",&x,&y)!=2)return fprintf(flog,"0 Unexpected EOF");
		if(x<0)return fprintf(flog,"0 In swap #%d i = %d is negative",i,x);
		if(x>n)return fprintf(flog,"0 In swap #%d i = %d is greater than n = %d",i,x,n);
		if(y<0)return fprintf(flog,"0 In swap #%d j = %d is negative",i,y);
		if(y>n)return fprintf(flog,"0 In swap #%d j = %d is greater than n = %d",i,y,n);
		int z=A[x];A[x]=A[y];A[y]=z;
		cost+=x>y?x-y:y-x;
	}
	for(int i=1;i<=n;i++)if(A[i]!=B[i])return fprintf(flog,"0 Wrong operations");
	if(cost>ans)return fprintf(flog,"0 Total cost %lld is greater than minimum cost %lld",cost,ans);
	if(t>n)return fprintf(flog,"0.4 Total cost %lld is correct but t = %d is greater than n = %d",cost,t,n);
	return fprintf(flog,"1 Correct answer");
}
int main(int argc,char*argv[]){
	FILE*fin=fopen(argv[1],"r"),
		*fout=fopen(argv[2],"r"),
		*fans=fopen(argv[3],"r"),
		*flog=fopen(argv[4],"w");
	fscanf(fin,"%d",&n);
	for(int i=1;i<=n;i++)fscanf(fin,"%d",A+i);
	for(int i=1;i<=n;i++)fscanf(fin,"%d",B+i);
	fclose(fin);
	fscanf(fans,"%lld",&ans);
	fclose(fans);
	judge(fout,flog);
	fclose(fout);
	fclose(flog);
	return 0;
}
