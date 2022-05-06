# little_things

<details>
  <summary> ### “Что именно является константой?” “Что” — это всегда то, что находится перед квалификатором const </summary>

## int const* и const int * это указатель на константный инт

Это означает, что объявляемая переменная является указателем, указывающим на постоянное целое число. По сути, это означает, что указатель указывает на значение, которое не следует изменять. Квалификатор ```const``` не влияет на указатель в этом сценарии, поэтому указатель может указывать на какой-либо другой адрес.
```c
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
```
![Screenshot from 2022-05-06 11-58-41](https://user-images.githubusercontent.com/84707645/167103544-74c852e3-00dd-4a8c-8625-37350317c481.png)

## int *const это константный указатель на int
```c
int main()
{
    int a = 5, b = 10, c = 15;

	const int* foo;
	// pointer to constant int.
	foo = &a;
	// assignment to where foo points to.

	/* dummy statement*/
	*foo = 6;
	// the value of a can´t get changed through the pointer.

	foo = &b;
	// the pointer foo can be changed.



	int *const bar = &c;
	// constant pointer to int 
	// note, you actually need to set the pointer 
	// here because you can't change it later ;)

	*bar = 16;            // the value of c can be changed through the pointer.    

	/* dummy statement*/
	bar = &a;             // not possible because bar is a constant pointer.  
}
```

</details>
