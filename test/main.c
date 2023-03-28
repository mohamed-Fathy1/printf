#include "../main.h"
int main(void)
{
    int len;
    int len2;
    unsigned int ui;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    len =_printf("Length:[%d, %i]\n", len, len);
    len2 = printf("Length:[%d, %i]\n", len2, len2);
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    len = _printf("Negative:[%d]\n", 0);
    len2 = printf("Negative:[%d]\n", 0);
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    len = _printf("Character:[%c]\n", 'H');
    len2 = printf("Character:[%c]\n", 'H');
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    len = _printf("Percent:[%%%% %%% % %]\n");
    len2 = printf("Percent:[%%%% %%% % %]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
   len = _printf("Unsigned:[%u]\n", ui);
   len2 = printf("Unsigned:[%u]\n",  ui);
   _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    return (0);
}
