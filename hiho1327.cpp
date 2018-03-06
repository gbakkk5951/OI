using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
namespace OI {
char str[100010];
struct _Main {
	int cnt[26];
	_Main() {	
		int len;
		scanf("%s", str);
		len = strlen(str);
		for (int i = 0; i < len; i++) {
			cnt[str[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (cnt[i] > (len + 1 >> 1)) {
				printf("INVALID");
				return;
			}
		}
		for (int i = 0; i < len; i++) {
			str[i] = 0;
			for (int j = 0; j < 26; j++) {
				if (cnt[j] > (len - i >> 1)) {
					str[i] = 'a' + j;
					cnt[j]--;
					break;
				}
			}
			if (str[i]) continue;
			for (int j = 0; j < 26; j++) {
				if (cnt[j] && (i == 0 || str[i - 1] != 'a' + j)) {
					str[i] = 'a' + j;
					cnt[j]--;
					break;
				}
			}
		}
		str[len] = '\0';
		printf("%s", str);
	}
}hiho1327;
}

