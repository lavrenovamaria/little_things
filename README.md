# little_things

<details>
  <summary> Что именно является константой? “Что” — это всегда то, что находится перед квалификатором const </summary>

## int const*(лучше) и const int * это указатель на константный инт

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


## const int* const и int const* const — константный указатель на константное целое число
Это означает, что объявляемая переменная является константным указателем, указывающим на 		постоянное целое число. По сути, это означает, что постоянный указатель указывает на постоянное 	значение. Следовательно, ни указатель не должен указывать на новый адрес, ни значение, на которое 	указывает указатель, не должно изменяться.
Первое ключевое слово const может находиться в любой части типа данных, поэтому const int* const 	эквивалентно int const* const.
</details>



<details>
  <summary> О жабе </summary>

## Метод свойства Java setProperty()
	
Метод setProperty() используется для установки заданного элемента значения (val_ele), связанного с заданным ключевым элементом (key_ele), когда ни один элемент значения не связан ранее, в противном случае он заменяет старое значение заданным значением для данного ключа этого свойства.

```public Object setProperty(String key, String value)```

Строка key_ele — представляет ключевой элемент, для которого должно быть установлено значение.
	
Строка val_ele — представляет элемент значения для данного ключа.

Тип возвращаемого значения метода — Object , он возвращает старое значение, связанное с данным ключом, если он существует, в противном случае он возвращает null.

```java
import java.io.*;
import java.util.*;

public class SetPropertyOfProperties {
	public static void main(String arg[]) throws Exeption {
	Properties prop = new Properties();
	prop.put("10", "C");
	prop.put("20", "C++");
	prop.put("30", "JAVA");
	prop.put("40", "PHP");
	prop.put("50", "SDFC");
	
	Object ob = prop.setProperty("20", "OOPS")
	
	System.out.println("prop.setProperty(20, OOPS): " + ob);
	
	prop.list(System.out);
	}
}
```

```
prop.setProperty(20, OOPS): C++
--listing properties--
50=SFDC
40=PHP
30=JAVA
20=OOPS
10=C
```
	
</details>
