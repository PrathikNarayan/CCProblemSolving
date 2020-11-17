#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,m=256,sa[200005],y[200005],u[200005],v[200005],o[200005],r[200005],h[200005],T;
int buf[200005],answer[200005];
char str[200005];
int arr[5005][5005];
const int modulo = 1e+9+7;

signed main()
{
    arr[0][0]=1;
    for(int i=1;i<=5000;i++)
    {
        arr[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            arr[i][j]=(arr[i-1][j]+arr[i-1][j-1])%modulo;
        }
    }
    scanf("%lld",&T);
    while(T--)
    {
        memset(sa,0,sizeof sa);
		memset(y,0,sizeof y);
		memset(u,0,sizeof u);
		memset(v,0,sizeof v);
		memset(o,0,sizeof o);
		memset(r,0,sizeof r);
		memset(h,0,sizeof h);
		memset(buf,0,sizeof buf);
		memset(answer,0,sizeof answer);
		memset(str,0,sizeof str);
        scanf("%lld%lld",&n,&q);
        scanf("%s",str+1);

        for(int i=1; i<=n; i++) u[str[i]]++;
        for(int i=1; i<=m; i++) u[i]+=u[i-1];
        for(int i=n; i>=1; i--) sa[u[str[i]]--]=i;
        r[sa[1]]=1;
        for(int i=2; i<=n; i++) r[sa[i]]=r[sa[i-1]]+(str[sa[i]]!=str[sa[i-1]]);

        for(int l=1; r[sa[n]]<n; l<<=1)
        {
            memset(u,0,sizeof u);
            memset(v,0,sizeof v);
            memcpy(o,r,sizeof r);
            for(int i=1; i<=n; i++) u[r[i]]++, v[r[i+l]]++;
            for(int i=1; i<=n; i++) u[i]+=u[i-1], v[i]+=v[i-1];
            for(int i=n; i>=1; i--) y[v[r[i+l]]--]=i;
            for(int i=n; i>=1; i--) sa[u[r[y[i]]]--]=y[i];
            r[sa[1]]=1;
            for(int i=2; i<=n; i++) r[sa[i]]=r[sa[i-1]]+((o[sa[i]]!=o[sa[i-1]])||(o[sa[i]+l]!=o[sa[i-1]+l]));
        }
        {
            int i,j,k=0;
            for(int i=1; i<=n; h[r[i++]]=k)
                for(k?k--:0,j=sa[r[i]-1]; str[i+k]==str[j+k]; k++);
        }
        buf[1]=n*(n+1ll)/2ll;
        for(int i=1; i<=n; i++) buf[1]-=h[i];
        for(int i=1; i<=n; i++)
        {
            int l=h[i],r=h[i+1];
            if(l<r)
            {
                ++l;
                for(int j=i+1; j<=n+1 && l<=r; j++)
                {
                    while(r>h[j]&&l<=r)
                    {
                        buf[j-i]++;
                        --r;
                    }
                }
            }
        }
        for(int i=2;i<=n;i++) buf[1] -= buf[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                (answer[i]+=(arr[j][i]*buf[j])%modulo) %= modulo;
            }
        }
        for(int i=1;i<=q;i++)
        {
            int tmp;
            scanf("%lld",&tmp);
            if(tmp<=n) printf("%lld\n",answer[tmp]);
            else printf("0\n");
        }
    }
}
