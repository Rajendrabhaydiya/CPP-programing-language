/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include <iostream>
#include <stdio.h>

using namespace std;

const int M = 1000000007;
const int maxn = 1000;

long long T[maxn + 1][maxn + 1];
long long B[maxn + 1], G[maxn + 1];

void init()
{
    T[1][0] = 1;
    for (int j = 1; j <= maxn; j++)
    {
        T[1][j] = T[1][j - 1];
        if (j >= 2) T[1][j] += T[1][j - 2];
        if (j >= 3) T[1][j] += T[1][j - 3];
        if (j >= 4) T[1][j] += T[1][j - 4];
        T[1][j] %= M ;
    }
    for (int i = 2; i <= maxn; i++)
        for (int j = 1; j <= maxn; j++) 
        {
            T[i][j] = T[i - 1][j] * T[1][j];
            T[i][j] %= M ;
        }
}

int main()
{
    init();    
    int cs, n, m;
    cin >> cs ;
    while (cs--)
    {
        cin >> n >> m;
        B[1] = 0;
        G[1] = 1;
        for (int j = 2; j <= m; j++)
        {
            B[j] = 0;
            for (int k = 1; k < j; k++)
            {
                B[j] += T[n][j - k] * G[k];
                B[j] %= M ;
            }
            G[j] = (T[n][j] + M - B[j]) % M ;
        }
        cout << G[m] << endl;
    }    
}
