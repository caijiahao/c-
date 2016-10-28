#include <iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

//定义结构体
struct Node{
    int start,end;
}arr[102];

//排序器的编写
bool cmp(Node a,Node b){
    return a.end<b.end;
}
/*
 *非洲小孩
时间限制：1000 ms  |  内存限制：65535 KB
难度：2
描述
家住非洲的小孩，都很黑。为什么呢？
第一，他们地处热带，太阳辐射严重。
第二，他们不经常洗澡。（常年缺水，怎么洗澡。）
现在，在一个非洲部落里，他们只有一个地方洗澡，并且，洗澡时间很短，瞬间有木有！！（这也是没有的办法，缺水啊！！）
每个小孩有一个时间段能够洗澡。并且，他们是可以一起洗的（不管你是男孩是女孩）。
那么，什么时间洗澡，谁应该来洗，由谁决定的呢？那必然是他们伟大的“澡”神啊。“澡”神有一个时间表，记录着该部落的小孩，什么时候段可以洗澡。现在，“澡”神要问你，一天内，他需要最少开启和关闭多少次洗澡的水龙头呢？因为，开启和关闭一次水龙头是非常的费力气的，即便，这也是瞬间完成的。
输入
多组数据
第一行一个0<n<=100。
接下来n行，每行一个时间段。H1H1:M1M1-H2H2:M2M2，24小时制。
保证该时间段是在一天之内的。但是，不保证，H1H1:M1M1先于H2H2:M2M2。
输出
题目描述，“澡”神最少需要开启和关闭多少次水龙头呢？
样例输入
1
00:12-12:12
2
00:12-12:12
14:00-12:00
样例输出
1
1
区间选点：（右端排序）给n个闭区间[ai,bi], 在数轴上选尽量少的点,使每个区间内至少有一个点。NYOJ1036
区间覆盖：（左端排序）给n个闭区间[ai,bi],
求有多少块连续区间。
 */
int main()
{
    int n,h,m,h2,m2,ans,flag;
    while(scanf("%d",&n) == 1){
        for(int i=0;i<n;i++){
            scanf("%d:%d-%d:%d",&h,&m,&h2,&m2);
            m += h*60;
            m2+= h2*60;
            if(m>m2){
                ans = m ;
                m=m2;
                m2 = ans;
            }
            arr[i].start = m;
            arr[i].end = m2;
        }
            sort(arr,arr+n,cmp);
            ans = 1;
            flag = arr[0].end;
            for(int i=1;i<n;i++){
                if(flag<arr[i].start){
                    ans++;
                    flag = arr[i].end;
                }
            }
            printf("%d\n",ans);
    }
    return 0;
}
