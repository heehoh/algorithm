#include <stdio.h>

int main(void)
{
    int h, m, c;
    scanf("%d %d %d", &h, &m, &c);
    h += c / 60;
    m += c % 60;
    if (m >= 60)
    {
        ++h;
        m -= 60;
    }
    if (h >= 24)
        h -= 24;
    printf("%d %d", h, m);
}