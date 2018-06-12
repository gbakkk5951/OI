#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

#define EVAL_OUTPUT_FILE "/tmp/_eval.score"


FILE *fpin, *fpout, *fpeval;
/* Output message and exit */
void output (const char *s, int d)
{
	if (fpeval) {
		fprintf (fpeval, "%.4lf %s\n", d / 10.0, s);
		fclose(fpeval);
	}
	exit(0);
}

/* Open files and check */
void open_files(const char *in, const char *out, const char *eval_output)
{
	if ((fpeval = fopen (eval_output, "w")) == NULL) {
		fprintf (stderr, "Can not open %s!\n", EVAL_OUTPUT_FILE);
		output ("<strong>FAIL</strong> Can not open eval record file!", 0);
	}
	
	if ((fpin = fopen (in, "r")) == NULL) {
		fprintf (stderr, "Can not open %s!\n", in);
		output ("<strong>FAIL</strong> Can not open input file!", 0);
	}

	if ((fpout = fopen (out, "r")) == NULL) {
		fprintf (stderr, "Can not open %s!\n", out);
		output ("<strong>FAIL</strong> Can not open player's output file!", 0);
	}
}

#include <sstream>
#include <string>
#include <map>
char line[1 << 23];

int main (int argc, char *argv[])
{
	if (argc < 2) {
		fprintf (stderr, "Usage: mason_e <in> <out> <ans>\n");
		output ("<strong>FAIL</strong> Invalid Call!", 0);
	}
	open_files (argv[1], argv[2], argv[4]);
	
	std::map<std::pair<int, int>, int> cnt;
	int N, M; 
	if(fscanf(fpin, "%d%d", &N, &M) != 2)
		output("<strong>FAIL</strong> Incomplete input file (0)!", 0);
	while(M--)
	{
		int x, y, v;
		if(fscanf(fpin, "%d%d%d", &x, &y, &v) != 3)
			output("<strong>FAIL</strong> Incomplete input file (1)!", 0);
		cnt[std::make_pair(x, y)] += v;
	}
	
	while(fgets(line, 1 << 23, fpout))
	{
		std::stringstream in; in.str(line);
		int p, q; in >> p;
		if(p != 1) output("<strong>FAIL</strong> Wrong answer (0)!", 0);
		while((q = p, in >> p))
			if(!cnt[std::make_pair(q, p)]--)
				output("<strong>FAIL</strong> Wrong answer (1)!", 0);
		if(p != N) output("<strong>FAIL</strong> Wrong answer (2)!", 0);
	}
	
	std::map<std::pair<int, int>, int>::iterator k = cnt.begin(), e = cnt.end();
	for(; k != e; ++k) if(k->second) output("<strong>FAIL</strong> Wrong answer (3)!", 0);
	output("<strong>OK</strong> Correct!!!", 10);
}

