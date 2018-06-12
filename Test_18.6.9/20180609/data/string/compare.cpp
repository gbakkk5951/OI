#include <cstdio>
#include <cassert>
#include <cstring>

FILE *fout, *fans, *fres, *fmem;
char out[500000], ans[500000];

const int Tasks = 10;
const int caseCount[Tasks + 1] = {0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
int Sum[Tasks + 1];

bool Correct = 1;
void Check()
{
	while (1)
	{
		if (fscanf(fout, "%s", out) == -1) out[0] = 0;
		if (fscanf(fans, "%s", ans) == -1) ans[0] = 0;
		if (strcmp(out, ans)) { Correct = 0; return; }
		if (!out[0] || !ans[0]) break;
	}
}

int main(int argc, char **argv)
{
	for (int i = 1; i <= Tasks; i++) Sum[i] = Sum[i - 1] + caseCount[i];
	assert(fout = fopen(argv[2], "r"));
	assert(fans = fopen(argv[3], "r"));
	assert(fres = fopen(argv[4], "w"));
	Check();
	
	// read part and count from test
	int cid = 0, count = 0;
	if((fmem = fopen("test.mem", "r")))
	{
		fscanf(fmem, "%d %d", &cid, &count);
		fclose(fmem);
	}
	
	// read caseId and get partId
	int caseId, partId = -1;
	sscanf(argv[5], "%d", &caseId);
	for (int i = 1; i <= Tasks; ++i)
		if (Sum[i - 1] + 1 <= caseId && caseId <= Sum[i])
		{
			partId = i;
			break;
		}
	if (partId == -1) { fprintf(fres, "0 Spj Error:: Can't Find partId for %d\n", caseId); }
	
	if (!Correct)
	{
		// wrong answer
		if (cid != partId) count = 0;
		fprintf(fres, "0 <span style='color:red'>Failed Read \"%s\" but expected \"%s\".</span>", out, ans);
		if (caseId == Sum[partId])
		{
			// if is the last case in part print score
			fprintf(fres, "<br/> <span style='color:red'>Subtask #%d : %d / %d Failed.</span>", partId, count, caseCount[partId]);
		}
		fclose(fres);
	}
	else
	{
		// passed this test
		if (cid != partId) count = 0;
		++count;
		if (caseId == Sum[partId])
		{
			// if is the last case in part print score
			bool passed = (caseCount[partId] == count);
			fprintf(fres, "%d <span style='color:green'>Case %d in Part %d Passed.</span> <br/> <span style='color:%s'>Subtask #%d : %d / %d %s</span>", passed, caseId - Sum[partId - 1], partId, passed ? "green" : "red", partId, count, caseCount[partId], passed ? "Passed." : "Failed.");
		}
		else
			fprintf(fres, "1 <span style='color:green'>Case %d in Part %d Passed.</span>", caseId - Sum[partId - 1], partId);
		fclose(fres);
	}
	
	// remember
	fmem = fopen("test.mem", "w");
	fprintf(fmem, "%d %d", partId, count);
	fclose(fmem);
	return 0;
}


