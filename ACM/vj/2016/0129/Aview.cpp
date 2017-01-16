#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int direct[4][2] = { -1, 0, 1, 0, 0, 1, 0, -1 };  /*定义方向， 左右，上下*/

char map[21][21];               /*输入的字符串*/
bool mark[21][21];              /*标记走过的路程*/
bool flag;
int W, H;
int Dx, Dy;            //记录起始位置@，从这里开始进行搜索
int ans;                //记录满足的个数。初始化为1，因为@也包含在内
/*****底下是核心算法，主要是从
上下左右这四个方向进行搜索，注意
满足搜索的条件是不能越界，不能是#，
还有就是没有搜索过的--》主要是靠mark[i][j]
来实现*******/
void DFS( int x, int y )
{
    mark[x][y] = true;
    for( int k = 0; k < 4; k ++ )
    {
        int p = x + direct[k][0];
        int q = y + direct[k][1];
        if( p >= 0 && q >= 0 && p < H && q < W && !mark[p][q] && map[p][q] != '#' )
        {
            ans ++;
            DFS( p, q );
        }
    }
    return;
}

int main()
{
    int i, j, k;
    while( cin >> W >> H && ( W || H ) )   // W -> column, H -> row;
    {
        memset( mark, false, sizeof( mark ) );
        for( i = 0; i < H; i ++ )
            for( j = 0; j < W; j ++ )
            {
                cin >> map[i][j];
                if( map[i][j] == '@' )
                {
                    Dx = i;
                    Dy = j;
                }
            }
        ans = 1;
        DFS( Dx, Dy );
        cout << ans << endl;
    }
}
