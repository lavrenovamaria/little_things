#include <stdio.h>

int main()
{
    const int q = 5;
    printf("First const int q is %d\n", q);
    printf("Address of q: %p\n", &q);
    printf("------------------------");
    printf("\n");
    int const* p = &q;
    printf("Second const* p itself is nothing %ls\n", p);
    printf("\n");
    printf("Second const* p after turn to 5(printed as *p): %d\n", *p);
    printf("Address of p: %p\n", &p);
    printf("------------------------");
    printf("\n");
    //Compilation error
    //*p = 7;
  
    const int q2 = 7;
    printf("Third const int q2 is %d\n", q2);
    printf("Address of q2: %p\n", &q2);
    //Valid
    p = &q2; 
    printf("Third const* p after turn to 7(printed as *p): %d\n", *p);
    printf("Third const* p itself is nothing %ls\n", p);
    printf("\n");
    printf("Address of p: %p\n", &p);
      
    return 0;
}