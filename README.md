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
  <summary> Метод свойства Java setProperty() </summary>
	
	
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

<details>
  <summary> Менеджер безопасности Java SecurityManager </summary>
  
SecurityManager — это механизм управления безопасностью, предоставляемый java, который можно использовать для контроля разрешений на некоторые операции каждого из наших классов.

При запуске неизвестной Java-программы в программе может быть вредоносный код (удаление системных файлов, перезагрузка системы и т. д.) Для того чтобы запуск вредоносного кода не повлиял на систему, необходимо контролировать разрешения запущенного кода. В это время необходимо включить Java Security Manager.

Например, если в сервлете tomcat есть такой код, как System.exit(), то будет отправлен запрос, который приведет к выключению нашей виртуальной машины, и tomcat тоже будет закрыт. мы можем установить разрешения. , потому что в методе System.exit() он будет проверять, есть ли у вызываемого класса разрешение, и если разрешения нет, ему будет отказано.
	
</details>


<details>
  <summary> public static native long nanoTime() </summary>
	
  Возвращает текущее значение источника времени с высоким разрешением работающей виртуальной машины Java в наносекундах.
	
  ```
  For example, to measure how long some code takes to execute:
 	long startTime = System.nanoTime();  
	// ... the code being measured ...  
	long elapsedNanos = System.nanoTime() - startTime;
  ```
	
System.nanoTime() основан на тактовом цикле ядра процессора, и время его запуска неизвестно, в интернете есть статья о том, что оно рассчитывается от времени запуска ядра процессора, есть скрытые опасности в использовании System.nanoTime() для измерения времени. Например, при работе на многоядерном процессоре разные вызовы могут получать время разных ядер и время запуска различных ядер многоядерного процессора Вероятно, не совсем согласованно, что может привести к ошибкам синхронизации.
	
</details>

<details>
  <summary> ConfigurableApplicationContext </summary>
	
ApplicationContext определяет базовые спецификации расширенных контейнеров, это главный интерфейс спринга, описывающий контейнер внедрения зависимостей. Фактически, он не наследует напрямую базовый контейнер BeanFactory. Видно, что прямой родительский интерфейс ApplicationContext значительно расширяет BeanFactory, в том числе:

Регистрация и публикация событий
Парсинг сообщений
Парсинг ресурсов
Hierarchical Bean Factory
Listener
Благодаря вышеприведенному расширению мы можем в основном узнать характеристики расширенного контейнера IOC(Инверсия управления (англ. Inversion of Control, IoC)), что также является ключевой частью изучения всего контейнера ApplicationContext.
	

![image](https://user-images.githubusercontent.com/84707645/190183639-132fd544-b34f-4dba-9390-94c16d164f68.png)
	
1. [ApplicationContext](https://blog.csdn.net/ligel136738/article/details/113533132?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166316207716782388017187%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166316207716782388017187&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_click~default-1-113533132-null-null.142^v47^pc_rank_34_default_2,201^v3^control_1&utm_term=ConfigurableApplicationContext&spm=1018.2226.3001.4187)
- Inherited from ListableBeanFactory interface: factory methods for accessing application components
	
- Inherited from the ResourceLoader interface: load file resources in a generic way
	
- Inherited from the ApplicationEventPublisher interface: registering and publishing events
	
- Inherited from the MessageSource interface: process messages, support internationalization

Определенный из контекста родительского приложения всегда будет иметь приоритет в дочернем контексте.

2. ConfigurableApplicationContext
ConfigurableApplicationContext является подклассом ApplicationContext, и основная задача этого интерфейса — настроить функцию контекста приложения.
	


</details>
