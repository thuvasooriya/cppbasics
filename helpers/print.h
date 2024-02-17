#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/*
prints with style
@param color
30 black
31 red
32 green
33 yellow
34 blue
35 magenta
36 cyan
37 white
0  reset
@param txt text to print
*/
void pp(const int color, const char txt[])
{
    printf("\033[1;%dm%s\033[1;0m", color, txt);
}

/*
prints a line with style
@param color
30 black
31 red
32 green
33 yellow
34 blue
35 magenta
36 cyan
37 white
0  reset
@param txt text to print
@return nothing, just prints a line
*/
void ppl(const int color, const char txt[])
{
    printf("\033[1;%dm%s\033[1;0m\n", color, txt);
}

void ppi(const int color, const int data)
{
    printf("\033[1;%dm%d\033[1;0m", color, data);
}
void pprp(const int color, int pass, const int arr[10])
{
    int loop;
    // pp(color, ": [");
    ppi(color, pass);
    printf("\033[1;%dm: [ ", color);
    for (loop = 0; loop < 10; loop++)
        printf("%d, ", arr[loop]);
    printf("]\033[1;0m\n");
}
// void ppl(const char *style, ...)
// {
//     va_list args;
//     va_start(args, style);

//     const char *text = va_arg(args, const char *);
//     int i = 0;

//     while (text != NULL)
//     {
//         if (style[i] != '\0')
//         {
//             int color = 30 + (style[i] - 'a');
//             printf("\033[1;%dm%s\033[1;0m ", color, text);
//         }
//         else
//         {
//             printf("%s ", text);
//         }

//         i = (i + 1) % strlen(style);

//         text = va_arg(args, const char *);
//     }

//     printf("\n");

//     va_end(args);
// }
