#include <cstdio>
#include <cassert>
#include <cstring>

FILE *fout, *fans, *fres, *fmem, *fcod;

const int Tasks = 4;
const int CodeLim = 100 * 1024;
const int caseCount[Tasks] = {10, 10, 10, 10};
char out[1 << 25], ans[1 << 25], code[CodeLim + 5];

bool wa()
{
	for( ; ; )
	{
		int a = fscanf(fout, "%s", out);
		int b = fscanf(fans, "%s", ans);
		if(a != b) return 1;
		if(a == -1) return 0;
		if(strcmp(out, ans)) return 1;
	}
}

int main(int argc, char **argv)
{
	assert(fout = fopen(argv[2], "r"));
	assert(fans = fopen(argv[3], "r"));
	assert(fres = fopen(argv[4], "w"));
	assert(fcod = fopen("test.cpp", "r"));
	if(fread(code, 1, sizeof code, fcod) > CodeLim)
	{
		fprintf(fres, "0 <span style='color:red'>Code length limit excceeded.</span>");
		fclose(fres);
		return 0;
	}
	
	if(wa()) 
	{
		fprintf(fres, "0 <span style='color:red'>Wrong Answer</span>");
		fclose(fres);
		return 0;
	}
	int count = 0;
	if((fmem = fopen("test.mem", "r")))
	{
		fscanf(fmem, "%d", &count);
		fclose(fmem);
	}
	fmem = fopen("test.mem", "w");
	++count;

	int caseId, sum = 0;
	sscanf(argv[5], "%d", &caseId);
	for(int i = 0; i != Tasks; ++i)
	{
		sum += caseCount[i];
		if(caseId == sum)
		{
			bool passed = (caseCount[i] == count);
			fprintf(fres, "%d <span style='color:green'>Passed!</span><br/><span style='color:%s'>Subtask #%d : %d / %d %s</span>", passed, passed ? "green" : "red", i + 1, count, caseCount[i], passed ? "Passed!" : "Failed.");
			count = 0;
			goto ___;
		}
	}
	fprintf(fres, "1 Passed!");

	___:
	fprintf(fmem, "%d", count);
	fclose(fmem);
	fclose(fres);
}


