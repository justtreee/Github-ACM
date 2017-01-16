#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int direct[4][2] = { -1, 0, 1, 0, 0, 1, 0, -1 };  /*���巽�� ���ң�����*/

char map[21][21];               /*������ַ���*/
bool mark[21][21];              /*����߹���·��*/
bool flag;
int W, H;
int Dx, Dy;            //��¼��ʼλ��@�������￪ʼ��������
int ans;                //��¼����ĸ�������ʼ��Ϊ1����Ϊ@Ҳ��������
/*****�����Ǻ����㷨����Ҫ�Ǵ�
�����������ĸ��������������ע��
���������������ǲ���Խ�磬������#��
���о���û����������--����Ҫ�ǿ�mark[i][j]
��ʵ��*******/
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
