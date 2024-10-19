#include <stdio.h>
#include <string.h>

char zigzag(char *s,int numRows)
{
    int len = strlen(s), x = 0,y = 0;
    char a[numRows][len];

    if(numRows % 2 == 0)
    {
        for(int i = 0; i < len ; i++)
        {
            y++;
            for(int j = 0 ; j < numRows; j++)
            {
                if(i % 2 != 0 && x < len)
                {
                    if(j ==  numRows / 2 || j == (numRows / 2) - 1)
                    {
                        if(j % 2 != 0)
                        {
                            a[j][i] = s[x + 1];
                            x += 1;
                        }else
                        {
                            a[j][i] = s[x - 1];
                            x++;
                        }
                    }else
                    {
                        a[j][i] = '0';
                    }
                }else if(x < len)
                {
                    a[j][i] = s[x];
                    x++; 
                }
            }
            if(x >= len)
            {
                x = 0;
                break;
            }
        }
    }else
    {
        for(int i = 0; i < len ; i++)
        {
            y++;
            for(int j = 0 ; j < numRows; j++)
            {
                if(i % 2 != 0)
                {
                    if(j ==  numRows / 2)
                    {
                        a[j][i] = s[x];
                        x++;
                    }else
                    {
                        a[j][i] = '0';
                    }
                }else
                {
                    a[j][i] = s[x];
                    x++; 
                }
            }
            if(x >= len)
            {
                x = 0;
                break;
            }
        }
    }

    for(int i = 0; i < numRows ; i++)
    {
        for(int j = 0 ; j < y; j++)
        {
            if(a[i][j] != '0')
            {
                s[x] = a[i][j];
                x++;
            }
        }
    }
    
}

int main()
{
    char s[30];
    int numRows;

    printf("Enter a string : ");
    scanf("%s",s);

    printf("Enter the number of rows : ");
    scanf("%d",&numRows);

    zigzag(s,numRows);

    printf("%s",s);
}
