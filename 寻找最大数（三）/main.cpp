#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100 + 10;

char str[20];
int k;
int main()
{
    while(scanf("%s%d",str,&k) !=EOF){
        int len = strlen(str);
        int t;
        //寻找在规定变换范围内的最大值
        for(int i = 0;i<len&&k!=0;i++){
            t = i;
            for(int j = i;j<=i+k&&j<len;j++){
                if(str[j]>str[t]){
                    t = j;
                }
            }

            for(int j = t;j > i;j--){
                swap(str[j],str[j-1]);
            }
            //减去移动的步数
            k -= (t-i);
        }
        printf("%s\n",str);
    }
    return 0;
}
