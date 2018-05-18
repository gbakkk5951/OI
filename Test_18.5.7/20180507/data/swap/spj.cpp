#include<cstdio>
int n,A[200010],B[200010];
long long ans;
int judge(FILE*fout,FILE*flog){
	int t;
	if(fscanf(fout,"%d",&t)!=1)return fprintf(flog,"Unexpected EOF"),0;
	if(t<0)return fprintf(flog,"t = %d is negative",t),0;
	if(t>2*n)return fprintf(flog,"t = %d is greater than 2n = %d",t,2*n),0;
	long long cost=0;
	for(int i=1,x,y;i<=t;i++){
		if(fscanf(fout,"%d%d",&x,&y)!=2)return fprintf(flog,"Unexpected EOF"),0;
		if(x<0)return fprintf(flog,"In swap #%d i = %d is negative",i,x),0;
		if(x>n)return fprintf(flog,"In swap #%d i = %d is greater than n = %d",i,x,n),0;
		if(y<0)return fprintf(flog,"In swap #%d j = %d is negative",i,y),0;
		if(y>n)return fprintf(flog,"In swap #%d j = %d is greater than n = %d",i,y,n),0;
		int z=A[x];A[x]=A[y];A[y]=z;
		cost+=x>y?x-y:y-x;
	}
	for(int i=1;i<=n;i++)if(A[i]!=B[i])return fprintf(flog,"Wrong operations"),0;
	if(cost>ans)return fprintf(flog,"Total cost %lld is greater than minimum cost %lld",cost,ans),0;
	if(t>n)return fprintf(flog,"Total cost %lld is correct but t = %d is greater than n = %d",cost,t,n),2;
	return fprintf(flog,"Correct answer"),5;
}
int main(int argc,char*argv[]){
	FILE*fin=fopen(argv[1],"r"),
		*fout=fopen(argv[2],"r"),
		*fans=fopen(argv[3],"r"),
		*fscore=fopen(argv[5],"w"),
		*flog=fopen(argv[6],"w");
	fscanf(fin,"%d",&n);
	for(int i=1;i<=n;i++)fscanf(fin,"%d",A+i);
	for(int i=1;i<=n;i++)fscanf(fin,"%d",B+i);
	fclose(fin);
	fscanf(fans,"%lld",&ans);
	fclose(fans);
	fprintf(fscore,"%d",judge(fout,flog));
	fclose(fout);
	fclose(fscore);
	fclose(flog);
	return 0;
}
