void RI (int& x){
	x = 0;
	char c = getchar ();
	while (!(c>='0' && c<='9' || c=='-'))     c = getchar ();
	bool flag = 1;
	if (c == '-'){
		flag = 0;
		c = getchar ();
	}
	while (c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar ();
	}
	if (!flag)      x = -x;
}
//fread 读取字符串，然后解析


////////////////读入挂///////////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char *ch, *ch1, buf[40*1024000+5], buf1[40*1024000+5];

bool read(int &x) {
	for (++ch; (*ch) && !(((*ch) >= '0' && (*ch) <= '9') || (*ch) == '-' ); ++ch);
	if(!(*ch)) return false;
	bool sign = 0;
	if((*ch) == '-') { sign = 1; ++ch; }
	for (x = 0; '0' <= *ch; ch++)	x = x * 10 + *ch - '0';
	if(sign) x = -x;
	return true;
}

void out(int x)
{
	if (!x)	*(++ch1) = '0';
	else
    {
		char *ch0 = ch1, *ch = ch1 + 1;
        bool sign = 0;
        if(x < 0) { sign = 1; x = -x; }
		while (x)
		{
			*(++ch0) = x % 10 + '0';
			x /= 10;
		}
		if(sign)
            *(++ch0) = '-';
		ch1 = ch0;
		while (ch <= ch0)	swap(*(ch++), *(ch0--));
	}
	*(++ch1) = '\n';
}


int main()
{
  //  freopen("./test.txt","r",stdin);
    ch = buf - 1;
	ch1 = buf1 - 1;
	fread(buf, 1, 1000 * 35 * 1024, stdin);
    int n;
    while(read(n))
    {
        out(n);
    }
    puts(buf1);

}
///////////////////////////////////




//Hash容错表
void init()
{
    memset(head,-1,sizeof(head));
}

int modhash(int x)
{
    int sum = 0;
    for(int i = 0;i < 6;++i)
        sum += save[x][i];
    return sum%hashsize;
}

bool insert(int x)
{
    int h = modhash(x);
    int u = head[h];
    while(u != -1)
    {
        if(judge(u,x)) return false;
        u = nxt[u];
    }
    nxt[x] = head[h];
    head[h] = x;
    return true;
}


///////////////////分块暴力/////////////////////
 for(int i = L;i <= R;)
    {
        if(i%BLOCK == 0 && i + BLOCK -1 <= R)
        {
            diff[i/BLOCK] += x;
            i += BLOCK;
        }
        else
        {
            save[i] += x;
            i++;
        }
    }
