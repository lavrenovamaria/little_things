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

[Дополнительно](https://blog.csdn.net/ligel136738/article/details/113448427)

</details>

<details>
  <summary> ApplicationEventMulticaster </summary>
ApplicationEventMulticaster — это интерфейс трансляции событий в spring, который отвечает за трансляцию и публикацию событий.

Если внутри контейнера есть bean-компонент с именем applicationEventMulticaster, это устанавливает этот bean-компонент в качестве распространителя событий в контексте.
	
Если в контейнере нет компонента, он будет по умолчанию SimpleApplicationEventMulticaster.

</details> 


<details>
  <summary> @ConfigurationPropertiesScan </summary>
В проектах SpringBoot нам часто нужно привязать некоторые элементы конфигурации с определенными префиксами к классу конфигурации. В настоящее время мы можем использовать @EnableConfigurationPropertiesаннотацию @ConfigurationPropertiesдля достижения. Аннотации также добавлены в SpringBoot 2.2.0 @ConfigurationPropertiesScan, чтобы помочь нам упростить регистрацию класса конфигурации как Bean. Далее в основном объясняется использование и реализация исходного кода этих трех аннотаций.
	
Существуют следующие элементы конфигурации, которые мы используем @ConfigurationProperties и @EnableConfigurationProperties чтобы привязать их к классам конфигурации, и эти классы конфигурации будут фактически зарегистрированы как bean-компоненты.

</details> 

<details>
  <summary> org.springframework.stereotype.Service </summary>
org.springframework.stereotype.Service — это аннотация Spring, используемая для обозначения компонентов бизнес-уровня (службы).
Отмеченный компонент должен иметь такую конфигурацию в конфигурационном файле 
```java
	< context : component-scan base-package = " имя пакета" > < /context:component-scan > 
```

Также может указывать на то, что класс является «Фасадом бизнес-службы» (в смысле шаблонов Core J2EE) или чем-то подобным. Эта аннотация является стереотипом общего назначения, и отдельные группы могут сузить свою семантику и использовать ее по мере необходимости.
</details>

		
<details>
  <summary> org.springframework.transaction.annotation.Transactional </summary>
Transactional — это аннотация транзакции, определенная в Spring, которая добавляется к методу или классу для запуска транзакции. Он в основном получает информацию об аннотациях bean-компонентов посредством отражения и использует АОП для инкапсуляции и реализации программных транзакций.
	
В некоторых бизнес-сценариях, если в запросе необходимо записать данные из нескольких таблиц или выполнить несколько SQL-запросов одновременно, чтобы обеспечить атомарность операции (одновременное успешное или неудачное выполнение) и избежать несогласованности данных, мы используем транзакции. обычно используются; в среде Spring мы часто используем аннотацию @Transactional для управления транзакциями.
	
[Транзакция](https://blog.csdn.net/minghao0508/article/details/124374637?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166317290016800182714431%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166317290016800182714431&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-2-124374637-null-null.142^v47^pc_rank_34_default_2,201^v3^control_1&utm_term=%40interface%20Transactional&spm=1018.2226.3001.4187) относится к логической группе операций, и единицы, составляющие эту группу операций, либо все успешны, либо все неудачны, ниже вводятся основные понятия, связанные с транзакциями.
	
ACID относится к четырем характеристикам, которыми должна обладать система управления базами данных ( СУБД ), чтобы гарантировать правильность и надежность транзакции в процессе записи или обновления данных : ACID (от англ. atomicity, consistency, isolation, durability) — набор требований к транзакционной системе, обеспечивающий наиболее надёжную и предсказуемую её работу — атомарность[⇨], согласованность[⇨], изоляция[⇨], устойчивость[⇨]; сформулированы в конце 1970-х годов Джимом Греем.

Spring предоставляет богатую функциональную поддержку для управления транзакциями. Управление транзакциями Spring делится на два способа: программный и декларативный:

1) Программная транзакция : позволяет пользователям точно определить границу транзакции в коде и реализовать ее самостоятельно, когда это необходимо бизнес-логике, через программный код с меньшей степенью детализации;

Для программного управления транзакциями используйте TransactionTemplate или непосредственно базовый PlatformTransactionManager; для программного управления транзакциями Spring рекомендует использовать TransactionTemplate;

2) Декларативная транзакция : основана на Spring AOP(Аспе́ктно-ориенти́рованное программи́рование), реализуется с помощью аннотаций или конфигурации XML, помогает пользователям отделить операции от правил транзакций;

Суть его заключается в том, чтобы перехватить метод до и после, а затем создать или присоединиться к транзакции до запуска целевого метода, и зафиксировать или откатить транзакцию в соответствии с выполнением после выполнения целевого метода; также есть два распространенных способа декларативного управление транзакциями, один из них - Сделать соответствующие объявления правил транзакций в файле конфигурации XML, а другой основан на аннотации @Transactional.Очевидно, что метод на основе аннотаций проще в использовании.

Очевидно, что декларативные транзакции лучше, чем программные транзакции, которые являются ненавязчивым методом разработки, поддерживаемым Spring ; декларативное управление транзакциями защищает бизнес-код от загрязнения, а метод нуждается в поддержке транзакций, просто добавьте аннотации;

По сравнению с программными транзакциями декларативные транзакции также имеют недостатки, поскольку на основе Spring AOP (динамический прокси) самые мелкие декларативные транзакции могут действовать только на уровне метода и не могут действовать на уровне блока кода, как программные транзакции. конечно, блоки кода, которые нуждаются в управлении транзакциями, также могут быть разделены на методы, кроме того, вызовы между аналогичными методами не будут перехватываться АОП, что приводит к недопустимым аннотациям транзакций.
	
Атрибуты транзакций можно понимать как некоторые базовые конфигурации транзакций, описывающие, как политики транзакций применяются к методам; атрибуты транзакций включают несколько аспектов: поведение распространения, правила изоляции, правила отката, тайм-аут транзакции, только для чтения или нет;

```
TransactionDefinition.PROPAGATION_REQUIRED(если есть текущая транзация, присоединить к транзакции, если текущей транзакции нет, то создайте новую транзакцию. Это значение по умолчанию)
	
TransactionDefinition.PROPAGATION_REQUIRES_NEW(создайте новую транзакцию и, если текущая транзакция существует, приостановите транзакцию)
	
TransactionDefinition.PROPAGATION_SUPPORTS(если в данный момент существует транзакция, присоединить к транзакии, если нет, то продолжать работать без транзакции)
	
TransactionDefinition.PROPAGATION_NOT_SUPPORTED(выполняется без транзакций. Если есть текущая транзакция, текущая транзакция приостанавливается)
	
TransactionDefinition.PROPAGATION_NEVER(выполняется нетранзакционным способом, если в данный момент существует транзакция, генерируется исключение)
	
TransactionDefinition.PROPAGATION_MANDATORY(если есть текущая транзакция, присоединитесь к транзакции, если текущей транзакции нет, генерируется исключение)
	
TransactionDefinition.PROPAGATION_NESTED(если транзакция существует в данный момент, создайте транзакцию для выполенения как вложенную транзакцию текущей транзакции, если в данный момент транзакции нет, то значение эквивалентно TransactionDefinition.PROPAGATION_REQUIRED)
```

</details> 

		
<details>
  <summary> @EnableWebSecurity </summary>
Во-первых, аннотация EnableWebSecurity является составной аннотацией, в которой используется аннотация @EnableGlobalAuthent

Во-первых, класс конфигурации WebSecurityConfiguration активируется в 1. В этом классе конфигурации вводится очень важный bean-компонент SpringSecurityFilterChain, который является основным фильтром Spring Secuity, который является записью аутентификации для запроса.
	
В этой аннотации активирован класс конфигурации AuthenticationConfiguration. Этот класс используется для настройки основных классов, связанных с аутентификацией. Основная функция этого класса — внедрить AuthenticationManagerBuilder в контейнер Spring. AuthenticationManagerBuilder фактически использует режим построителя, который может создавать AuthenticationManager Как упоминалось ранее, этот класс является точкой входа для аутентификации личности.

Итак, на данный момент аннотация EnableWebSecurity выполняет две функции: 1. Загрузить класс конфигурации WebSecurityConfiguration и настроить стратегию аутентификации безопасности. 2: Загружается AuthenticationConfiguration и настраивается информация аутентификации.
</details>

<details>
  <summary> API + Swagger </summary>
	
Open API - это спецификация, но только для версии 3.0 и выше. Swagger - всё остальное(но иногда и спецификация). [Лекция](https://www.youtube.com/watch?v=lYjm2w8-ERI)
	
![image](https://user-images.githubusercontent.com/84707645/190857090-9ac60e62-069a-440b-a9dd-681cae6cb4c2.png)

![image](https://user-images.githubusercontent.com/84707645/190857444-1e080c6a-f192-4319-8740-ec404474b624.png)
	
![image](https://user-images.githubusercontent.com/84707645/190857324-e567a169-8893-4dae-a8fd-4851be96c07d.png)

![image](https://user-images.githubusercontent.com/84707645/190857413-fcce81f9-0539-40bb-80bd-01c74289dbdc.png)


</details>


<details>
  <summary> SOLID </summary>
	
<img width="710" alt="Screen Shot 2022-09-26 at 3 59 26 PM" src="https://user-images.githubusercontent.com/84707645/192282807-a563837b-a264-4c35-80b0-581bf19dce62.png">

Последняя трактовка принципов SOLID by Robert C. Martin от 2022-07-06
	
### The Single Responsibility Principle (SRP) - принцип единой ответственности утверждает, что класс или модуль
должен иметь одну — и только одну — причину для изменения. Попытки идентификации ответственностей (причин для изменения) часто помогают выявить и создать более качественные абстракции для нашего кода. Каждый класс инкапсулирует одну ответственность, имеет одну причину для изменения и взаимодействует с другими классами для реализации желаемого поведения системы. Если класс берет на себя несколько обязанностей, то
у него появляется несколько причин для изменения. 
	
У класса Rectangle есть два метода. Один рисует прямоугольник на экране, другой вычисляет площадь прямоугольника(trouble trouble)

<img width="710" alt="Screen Shot 2022-09-26 at 4 11 19 PM" src="https://user-images.githubusercontent.com/84707645/192285277-362b7abd-d7d7-4331-b24e-866949e27890.png">

Более правильный подход к дизайну состоит в том, чтобы распределить обязанности по двум разным классам, как показано на рисунке ниже. Теперь вычислительная часть Rectangle помещена в класс GeometricRectangle и изменения в алгоритме рисования прямоугольников не могут повлиять на приложение ComputationalGeometryApplication
	
<img width="710" alt="Screen Shot 2022-09-26 at 4 12 57 PM" src="https://user-images.githubusercontent.com/84707645/192285822-a65d0ebd-a58c-49e0-ac91-9b0d9f2b6d29.png">
	
Например, есть интерфейс Modem. У него две обязанности: управление соединением (методы Dial и Hangup) и передача данных (методы Send и Recv).
	
```
public interface Modem. 
{
 	public void Dial(string pno);
 	public void Hangup();
 	public void Send(char c);
 	public char Recv();
}
```

Следует ли разделить эти обязанности? Все зависит от того, как именно изменяется приложение. Если модификация подразумевает изменение сигнатуры методов управления соединением, то дизайн начинает быть жестким, так как классы, вызывающие Send и Recv, придется повторно компилировать и развертывать чаще, чем хотелось бы -> значит обязанности лучше разделить. 
	
Если приложение не модифицируют таким образом, что эти обязанности изменяются порознь, то и разделять их нет необходимости. Более того, разделение в этом случае будет излишне сложным. Ось изменения становится таковой, только если изменение имеет место. Неразумно применять SRP – как и любой другой принцип, – если для того нет причин.

🔴Gather together those things that change for the same reasons and at the same times. Separate those things that change for different reasons or at different times.
	
### The Open-Closed Principle (OCP) - принцип открытого-закрытого, отделяйте модули, которые часто меняются, от модулей, которые меняются реже, с помощью уровня абстракции.
	
Если единственное изменение в каком-то месте программы приводит к каскаду изменений в зависимых модулях, то дизайн жёсткий. Принцип OCP рекомендует переработать систему так, чтобы в будущем аналогичные изменения можно было реализовать путем добавления нового кода, а не изменения уже работающего.

На рисунке ниже изображен простой дизайн, нарушающий принцип OCP. Классы Client и Server конкретные. Класс Client использует класс Server. Если мы захотим, чтобы объект Client использовал другой серверный объект, то класс Client придется изменить, указав в нем имя нового серверного класса.

<img width="420" alt="Screen Shot 2022-09-26 at 5 37 22 PM" src="https://user-images.githubusercontent.com/84707645/192304848-f078ea8b-24d0-4f5e-8f5e-7c4b1e6fe102.png">

На рисунке ниже всё согласуется с OCP(Паттерн Стратегия: класс Client является одновременно открытым и закрытым). В данном случае класс ClientInterface абстрактный и содержит только абстрактные методы. Класс Client использует эту абстракцию. Однако объекты класса Client будут пользоваться объектами производного класса Server. Если мы захотим, чтобы объекты Client пользовались другим серверным классом, то сможем создать новый класс, производный от ClientInterface. Сам класс Client при этом не изменится.

<img width="420" alt="Screen Shot 2022-09-26 at 5 37 27 PM" src="https://user-images.githubusercontent.com/84707645/192304984-c410d5f2-2a3f-444c-8300-072cf9c13a19.png">

Ниже показана альтернативная структура на основе паттерна Шаблонный метод (Template Method) (Паттерн Шаблонный метод: базовый класс является одновременно открытым и закрытым). В классе Policy есть набор открытых конкретных методов, реализующих некоторую политику; они аналогичны методам класса Client на рис. 9.2. Как и раньше, эти методы описывают определенные функции в терминах абстрактных интерфейсов. Но теперь эти абстрактные интерфейсы являются частью самого класса Policy.
	
<img width="420" alt="Screen Shot 2022-09-26 at 5 51 07 PM" src="https://user-images.githubusercontent.com/84707645/192309185-4d1c0c4b-aa17-4245-a765-7c736469b5a2.png">

Задача с рисованием кругов и квадратов: 
```
enum ShapeType {circle, square};
struct Shape
{
 	ShapeType itsType;
};
```
Суть в том, что если я захочу туда добавить рисование треугольника, то пришлось бы добавить его в enum, модифицировать весь код. И так для каждого нового вида фигур(плохо плохо)
	
Решение, которое соблюдает OCP:
```
public interface Shape
{
 	void Draw();
}
	
public class Square : Shape
{
 	public void Draw()
 	{
 		// нарисовать квадрат
 	}
}
	
public class Circle : Shape
{
 	public void Draw()
 	{
 		// нарисовать круг
 	}
}
	
public void DrawAllShapes(IList shapes)
{
 	foreach(Shape shape in shapes)
 	shape.Draw();
}
```
Если мы захотим расширить поведение метода DrawAllShapes, чтобы он умел рисовать еще один вид фигур, то достаточно будет
добавить новый класс, производный от Shape(вуаля)

🔴Separate modules that frequently change from modules that change less frequently with a layer of abstraction.

### The Liskov Substitution Principle (LSP) - реализация интерфейса никогда не должна нарушать контракт между этим интерфейсом и его пользователями(Должна быть возможность вместо базового типа подставить любой его подтип). The implementation of an interface must never violate the contract between that interface and its users.
	
```
struct Point {double x, y;}
public enum ShapeType {square, circle};
public class Shape
	
{
     private ShapeType type;
     public Shape(ShapeType t){type = t;}
     public static void DrawShape(Shape s)
     {
         if(s.type == ShapeType.square)
		(s as Square).Draw();
 	 else if(s.type == ShapeType.circle)
 		(s as Circle).Draw();
     }
}
	
public class Circle : Shape
{
     private Point center;
     private double radius;
     public Circle() : base(ShapeType.circle) {}
     public void Draw() {/* рисует круг */}
}
	
public class Square : Shape
{
     private Point topLeft;
     private double side;
     public Square() : base(ShapeType.square) {}
     public void Draw() {/* рисует квадрат */}
}
```
Метод DrawShape	нарушает принцип OCP. Он должен знать обо всех классах, производных от Shape, и при каждом появлении нового производного класса его придется изменять. 
	
Рассмотрим инженера Васю. Он изучал объектно-ориентированные технологии и пришел к выводу, что затраты на полиморфизм слишком велики. Поэтому он определил класс Shape без абстрактных методов. Классы Square и Circle являются производными от Shape, и в них есть методы Draw(), но они не переопределяют одноименный метод в классе Shape. Так как Circle и Square невозможно подставить вместо Shape, то DrawShape должна определять тип переданного ей параметра и вызывать подходящий метод Draw.
Тот факт, что Square и Circle нельзя подставить вместо Shape, – нарушение принципа LSP. И вызвано оно отходом от принципа OCP в методе DrawShape. Таким образом, нарушение LSP – это латентное нарушение OCP.

### The Interface Segregation Principle (ISP) - не полагайтесь на то, что вам не нужно.(Клиенты не должны вынужденно зависеть от методов, которыми не пользуются)

Рассмотрим охранную систему, в которой объекты Door (Дверь) можно запирать и отпирать, а также узнавать, открыта дверь или закрыта. Тип Door закодирован в виде интерфейса, чтобы клиенты могли использовать объекты, согласованные с интерфейсом двери, не зная о деталях конкретной реализации.

```
public interface Door
{
     void Lock();
     void Unlock();
     bool IsDoorOpen();
}
```
	
Теперь предположим, что одна такая реализация, TimedDoor, должна подавать звуковой сигнал, если дверь остается открытой слишком долго. Для этого TimedDoor взаимодействует с объектом Timer.
	
```
public class Timer
{
 	public void Register(int timeout, TimerClient client)
 	{/* код */}
}
	
public interface TimerClient
{
 	void TimeOut();
}
```
	
Если объект желает получать уведомление об истечении тайм-аута, он вызывает метод Register объекта Timer. Этому методу в качестве аргументов передаются величина тайм-аута и ссылка на объект TimerClient, метод TimeOut которого нужно вызвать, когда тайм-аут истечет.
Как организовать взаимодействие класса TimerClient с классом TimedDoor таким образом, чтобы некий код внутри TimedDoor мог получать уведомления о тайм-ауте? Есть несколько вариантов. На рисунке ниже(Класс TimerClient на вершине иерархии) показано наиболее распространенное решение. Мы производим класс Door, а значит, и TimedDoor от TimerClient. Тем самым гарантируется, что TimerClient может зарегистрировать себя в объекте Timer и получить сообщение TimeOut.
	
<img width="557" alt="Screen Shot 2022-09-27 at 5 47 46 PM" src="https://user-images.githubusercontent.com/84707645/192559281-d4a1cbf6-cbeb-45aa-a914-3e28ce80943c.png">

Проблема этого решения в том, что класс Door теперь зависит от TimerClient. Но не всем разновидностям Door необходимо следить за временем. На самом деле первоначальная абстракция Door вообще ничего не знала об отсчете времени. При создании производных от Door классов, не интересующихся временем, нам придется включать вырожденные реализации метода TimeOut, то есть идти на нарушение принципа LSP. К тому же приложения, в которых используются такие производные классы, должны будут импортировать определение класса TimerClient, хотя оно им и не нужно. Это попахивает ненужной сложностью и ненужным повторением.
	
🔴Don't depend on things you don’t need.

### The Dependency Inversion Principle (DIP) - политики более низкого уровня должны зависеть от политик более высокого уровня. 
	
Но в правильно спроектированной объектно-ориентированной программе структура зависимостей «инвертирована» по отношению к той, что возникает в результате применения традиционных процедурных методик. модули верхнего уровня, определяющие стратегию, должны влиять на модули нижнего уровня, а не наоборот. Модули, которые содержат высокоуровневые бизнесправила, должны быть приоритетнее модулей, определяющих детали реализации, и независимы от них. Модули верхнего уровня вообще никак не должны зависеть от модулей более низкого уровня.

Иногда это называют принципом Голливуда: «Не звоните нам, мы сами позвоним». Модули нижнего уровня предоставляют реализацию интерфейсов, объявленных на более высоком уровне и оттуда же вызываемых.
	
<img width="420" alt="Screen Shot 2022-09-27 at 6 32 02 PM" src="https://user-images.githubusercontent.com/84707645/192570122-4a9be409-0d51-4da8-bbd7-6e0133e9a240.png">

Благодаря инверсии владения слой PolicyLayer невосприимчив к любым изменениям слоев MechanismLayer и UtilityLayer. Более того, PolicyLayer можно повторно использовать в любом контексте, где определены модули нижнего уровня, согласованные с интерфейсом PolicyServiceInterface. Таким образом, обратив зависимости, мы создали структуру, одновременно более гибкую, прочную и подвижную.
	
🔴Lower level policies should depend on higher level policies.
	
</details>
		
<details>
  <summary> GRASP. DESIGNING OBJECTS WITH RESPONSIBILITIES(general responsibility assignment software patterns — общие шаблоны распределения ответственностей) </summary>
  
[General Responsibility Assignment Software Patterns](https://gist.github.com/dimabory/56e36474a1bb5573c08f26805a978fb5)

| Принцип | Решение | Решаемая проблема |  Похожий паттерн | 
| ----------- | ----------- | ----------- | ----------- |
| Information Expert(информационный эксперт) | Обязанности назначаются классу, который имеет информацию, необходимую для их выполнения | Каков основной принцип распределения обязанностей между объектами при ООП? | Low Coupling, High Cohesion |
| Creator(Создатель) | Как правило, возлагайте на класс B ответственность за создание объекта A, если применимо одно или, предпочтительно, несколько из следующего: -B содержат или составно объединяют экземпляры A -B записывает экземпляры A -B тесно используют экземпляры A -B имеют инициализирующую информацию для экземпляров A и передают ее при создании. | Кто создает объект А? | Low Coupling, Factory pattern |
| Controller(Контроллер) | Контроллер варианта использования должен использоваться для обработки всех системных событий варианта использования и может использоваться более чем для одного варианта использования. Например, для вариантов использования «Создать пользователя» и «Удалить пользователя» можно использовать один класс с именем UserController вместо двух отдельных контроллеров вариантов использования. | Кто должен нести ответственность за обработку событий системы ввода? | Command, Facade, Layers, Pure Fabrication |
| Low coupling(Низкое сцепление) | Связь — это мера того, насколько сильно один элемент связан с другими элементами, знает о них или полагается на них. Низкая связанность — это оценочный паттерн, который диктует, как распределять обязанности для получения следующих преимуществ: -более низкая зависимость между классами, изменение в одном классе оказывает меньшее влияние на другие классы, более высокий потенциал повторного использования. | Как уменьшить влияние изменений? | ? | 
| High cohesion(Высокая связность) | Высокая связность — это оценочный паттерн, который пытается удерживать объекты надлежащим образом сфокусированными, управляемыми и понятными. Высокая сплоченность обычно используется для поддержки низкой связанности. Высокая связность означает, что обязанности данного набора элементов тесно связаны между собой и сильно сосредоточены на довольно конкретной теме. Разбиение программ на классы и подсистемы, если оно выполнено правильно, является примером действий, повышающих связность названных классов и подсистем. В качестве альтернативы низкая связность — это ситуация, в которой набор элементов, например подсистема, имеет слишком много несвязанных обязанностей. Подсистемы с низкой связностью между составляющими их элементами часто страдают от того, что их трудно понять, повторно использовать, поддерживать и изменять в целом. | Как сделать объекты сфокусированными, понятными и управляемыми и, как побочный эффект, поддерживать Low Coupling? | ? |
| Polymo­rphism(Полиморфизм) | Когда связанные альтернативы или поведение различаются по типу (классу), назначьте ответственность за поведение — с помощью полиморфных операций — тем типам, для которых поведение различается. (Полиморфизм имеет несколько связанных значений. В данном контексте это означает «назначение одного и того же имени службам в разных объектах».) | Как обрабатывать альтернативы на основе типа? Как создавать подключаемые программные компоненты? | ? |
| Pure fabric­ation(Чистая выдумка) | Чистая фабрикация — это класс, который не представляет концепцию в проблемной области, специально созданный для достижения низкой связанности, высокой связности и полученного потенциала повторного использования (когда решение, представленное шаблоном информационного эксперта, не соответствует). Этот тип класса называется «службой» в доменно-ориентированном дизайне. | ? | Low Coupling, High Cohesion. |
| Indire­ction(Перенаправление) | Назначьте промежуточному объекту ответственность за посредничество между другими компонентами или службами, чтобы они не были связаны напрямую. Посредник создает косвенную связь между другими компонентами. | Где возложить ответственность, чтобы избежать прямой связи между двумя (или более) вещами? Как отделить объекты, чтобы поддерживалась низкая связанность, а потенциал повторного использования оставался выше? | ? |
| Protected variations(Устойчивость к инзменениям) | Выявление точек прогнозируемой вариации или нестабильности; распределите обязанности, чтобы создать вокруг них стабильный интерфейс. | Как проектировать объекты, подсистемы и системы так, чтобы вариации или нестабильность этих элементов не оказывали нежелательного влияния на другие элементы? | ? |



</details>
		
<details>
  <summary> Threads, Concurrency, Dead Locks, Race Conditions </summary>
</details>

<details>
  <summary> JVM Memory Model, Stack, Heap, Eden, Old Generation, New Generation </summary>
</details>
		
<details>
  <summary> Garbage Collection, Reachable and Unreanhable Objects </summary>
</details>
		
<details>
  <summary> Patterns </summary>
</details>
		
<details> 
  <summary> Spring Proxy Mechanisms and Spring Proxy Object(@Transactional) </summary>
</details>
		
<details>
  <summary> Pojo/Hibernate Proxy Object </summary>
</details>
