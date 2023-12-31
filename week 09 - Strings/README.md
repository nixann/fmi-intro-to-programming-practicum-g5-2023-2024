﻿# Работа с низове
- Низовете са просто масиви от символи, **НО** има една единствена разлика между тях - низовете в края си **ЗАДЪЛЖИТЕЛНО** имат терминираща нула (това е символът `'\0'`, който има ASCII код 0).
    * *Пример:*
  
  ```c++
  // Това е низ
  char str[] = {'p', 'r', 'o', 'g', 'r', 'a', 'm', '\0'};
  
  // Това НЕ е низ
  char not_str[] = {'p', 'r', 'o', 'g', 'r', 'a', 'm'};
  ```

- Щом низовете са масиви от символи, то знаем, че масивите могат да са статични или динамични. Следователно можем да имаме статични или динамично заделени низове
    * *Пример:*

  ```c++
  // Статичен низ
  const unsigned MAX_SIZE = 5; // !! + 1 за терминиращата нула
  char str[MAX_SIZE] =  {'c', 'o', 'd', 'e'}; // Като сме сложили размер, остатъкът от масива автоматично ще бъде попълнен с 0, но тъй като ASCII кодът на '\0' е 0, то все едно автоматично ще ни бъдат сложени терминиращи нули

  // Този запис има и малко по-съкратена форма:
  char str[MAX_SIZE] = "code"; // "code" <=> {'c', 'o', 'd', 'e', '\0'}
  ```
  
  ```c++
  // Динамичен низ
  int n;
  std::cin >> n;

  char* str = new char[n + 1](); // + 1 за терминиращата нула!
  // Кръглите скоби тук запълват автоматично масива с 0, но отново за нас това са терминиращи нули

  ...

  // Не забравяме да изтрием паметта!
  delete[] str;
  ```

- Цялата идея на тази терминираща нула е да ни пази края на низа. Това означава, че можем лесно да намерим дължината на низа, когато си поискаме. Тогава няма нужда при подаване на низ във функция да подаваме допълнителна променлива с размер.
  * *Пример:*
  
   ```c++
   void func(char* str) {
      // Ако вече ни потрябва дължината на str, просто:
      unsigned length = std::strlen(str);
      ...
   }
   ```

- Въвеждане/извеждане:
    * *Пример:*
   ```c++
   unsigned n;
   std::cin >> n;

   // Ако след cin пишете cin.getline, нищо няма да се прочете
   // Затова след cin напишете това:
   std::cin.ignore();
   
   char* str = new char[n + 1]();

   // Тук подаваме дължината на низа + 1 за терминиращата нула
   std::cin.getline(str, n + 1);

   // Извеждането е просто със cout
   std::cout << str << std::endl;
   ```

- Всичко останало, свързано с работата при низове, е напълно еднакво с работата при масиви.
- Допълнителни функции за удобство при работа с низове, дефинирани в `<cstring>`:
    * `strlen` - Връща дължината на низа (хубаво е тази дължина да се съхранява в променлива от тип `unsigned` или `size_t`)
    * `strcpy` - Копира единия низ в другия заедно с терминиращата нула (Да се внимава с размерите!)
    * `strcat` - Конкатенира единия низ към другия
    *  Когато ползвате `strcat`/`strcpy`, пишете най-отгоре във файла `#define _CRT_SECURE_NO_WARNINGS` (Ако сте на Visual Studio)
    * `strcmp(const char* a, const char* b)` - Сравнява двата низа и връща:
        * -1 -> `a` е преди `b`
        * 0 -> `a` е равен на `b`
        * 1 -> `a` е след `b`
    * `strstr(const char* haystack, const char* needle)` - Връща началото на подниза, равен на `needle` в `haystack`. Ако няма такъв, връща `nullptr`
    * `atoi`/`atof`/`atoll` - Връща числото, с което започва низът
    <br>
# Задачи

## Задача 1
- Напишете програма, която въвежда неотрицателно цяло число $n$($n<=100$) и низ с дължина $n$. Нека програмата да извежда на екрана броя на цифрите, броя на буквите(малки и главни) и броя на всички останали символи в низа (т.е. броят на символите, които не са нито букви, нито цифри).

## Задача 2
- Напишете програма, която въвежда неотрицателно цяло число $n$($n<=100$) и низ с дължина $n$, съставен само от цифри. Нека програмата да извежда на екрана числото, което е записано в низа (без използване на `atoi`).
    * *Пример*:
  
   | Вход  | Изход |
   | ------------- | ------------- |
   |  <pre>n: 6<br>"47328"</pre>| <pre>47328 (Това е число, а не низ) </pre>  |

## Задача 3
- Променете задачи 1 и 2 така, че да работят, когато $n$ не е ограничено (т.е. низовете да са динамични).

## Задача 4 (Задача от изпит)
- Да се напише булева функция `convertToStrNumber`, която приема низ от малки латински
букви и го преобразува на място (inplace) като заменя всеки негов символ с броя на неговите срещания
в низа. Преобразуване на място означава, че замяната на символите се извършва директно в самия низ
и за преобразуването не е позволено използването на допълнителен низ или функциите `atoi`/`atof`. Низът се
представя чрез масив от символи с максимален размер 1024. Ако размерът на масива не е достатъчен
за преобразуването, функцията да връща стойност `false` и да не променя низа.
    * *Пример:*<br>
Вход: `aaabcaadcsmaabbbbsaaacc`
<br>Изход: `101010541010142110105555210101044` (`a - 10, b - 5, c - 4, d - 1, s - 2, m - 1`)
  
## Задача 5
- Напишете функция, която приема низ, който представлява едно изречение, думите в него са разделени с интервали. Нека функцията да връща масив от думите в това изречение (може да се повтарят).
    * *Пример:*

   | Вход  | Изход |
   | ------------- | ------------- |
   |  <pre>"Тhis is a valid sentence"</pre>| <pre>["Тhis", "is", "a", "valid", "sentence"]</pre>  |
  
## Задача 6
- Напишете функция, която приема изречение `sentence` и дадена дума `intruder` и която изтрива думата `intruder` от изречението `sentence`.
    * *Пример:*

   | Вход  | Изход |
   | ------------- | ------------- |
   |  <pre>intruder: "noot"<br>sentence: "**noot** now this **noot** **noot** sentence **noot** is normal **noot**"</pre>| <pre>"now this sentence is normal"</pre>  |

# Допълнителни задачи за упражнение

## Задача 7
- Имплементирайте функцията `strcat`, която приема низовете `src` и `dest` и долепя отзад на `dest` низа `src`. Приемете, че дължината на низовете може да бъде най-много половината от максималната дължина (за да може да се събере резултатът в `dest`).
    * *Пример:*

   | Вход  | Изход |
   | ------------- | ------------- |
   |  <pre>dest: "Hello"<br>src: ", World!"</pre>| <pre>dest: "Hello, World!"</pre>  |
- А сега ако приемем, че `dest` и `src` нямат максимален размер (т.е. са динамични). Тогава не може да сме сигурни, че резултатът ще се събере в `dest`. Как изглежда функцията тогава?
<details>
<summary>Жокер</summary>
<br>
Ще трябва да заделите за `dest` нова памет с размер дължината на `dest` + дължината на `src`. После след копиранията ще трябва да пренасочите `dest` към новата памет (нещо подобно на метода `resize` от практикума за динамични масиви).
<br>
</details>
  
## Задача 8
- Напишете програма, която въвежда неотрицателно цяло число $n$($n<=100$) и низ с дължина $n$ и отпечатва на екрана дължината на най-дългия подниз в низа, който няма повтарящи се букви.
    * *Пример*:
  
      | Вход  | Изход |
      | ------------- | ------------- |
      |  <pre>n: 11<br>"abcddefffd"</pre>| <pre>4 -> ("abcd")</pre>  |

## Задача 9
- Напишете функция, която приема два низа и връща дължината на най-дългата подредица от символи, която се намира и в двата низа.
    * *Пример*:
  
      | Вход  | Изход |
      | ------------- | ------------- |
      |  <pre>str1: "pqrjad"<br>str2: "usdqrf"</pre>| <pre>2 -> ("qr")</pre>  |

## Задача 10
- Напишете функция, която приема низ, който представлява изречение (думите са отделени с интервали), и отпечатва на екрана най-дългата и най-късата дума в низа. Ако има повече от една възможност да се отпечатат думата, която се среща по-късно в низа.

## Задача 11
- Напишете функция, която приема списък от думи и символ `c` и връща низ, който се състои от думите, съединени със символа `c`.
   * *Пример:*

   | Вход  | Изход |
   | ------------- | ------------- |
   |  <pre>words: ["Тhis", "is", "a", "valid", "sentence"]<br>c: ' '</pre>| <pre>"Тhis is a valid sentence"</pre>  |

## Задача 12*
- Напишете функция, която приема низ, който представлява изречение (думите са отделени с интервали) и връща низ, който съдържа думите от изречението (без дубликати), подредени в намаляващ ред според това колко пъти се срещат в изречението. Ако 2 думи се срещат еднакъв брой пъти, нека се подредят в нарастващ ред според дължината си.
    * *Пример:*

   | Вход  | Изход |
   | ------------- | ------------- |
   |  <pre>"this is not what it is"</pre>| <pre>"is it not this what"</pre>  |
  
  В този пример `is` се среща 2 пъти; `it`, `not`, `this`, `what` се срещат само по веднъж и в изхода са подредени според дължината си.

## Задача 13***
- Напишете функция, която приема низ, който представлява изречение (думите в това изречение са отделени с интервали) и заменя всяка дума `w`, която има дължина `n` с `n`-тата най-често срещана дума в изречението (приемаме, че всяка дума се среща различен брой пъти спрямо останалите). Ако `n` е толкова голямо, че няма `n` на брой различни думи в изречението, нека `w` се замести с най-рядко срещаната дума в изречението.
    * *Пример:*

   | Вход  | Изход |
   | ------------- | ------------- |
   |  <pre>"this is a is this is"</pre>| <pre>"a this is this a this"</pre>  |

  В този пример думите се замества по следния начин:<br>
  - `this` -> `a`, защото `this` има дължина 4, но тъй като няма 4 различни думи в изречението, `this` се замества с най-рядко срещаната дума, а тя е `a`.
  - `is` -> `this`, защото `is` има дължина 2, а `this` е втората най-често срещана дума.
  - `a` -> `is`, защото `a` има дължина 1, а `is` е първата най-често срещана дума.

## Задача 14*
- Напишете функция, която приема матрица, 2 неотрицателно цели числа `i` и `j`, 1 цяло число `dir` в интервала `[0, 3]` и 1 цяло неотрицателно число `numMoves`. Представяме си, че имаме човече, което се движи в матрицата по диагонали и на всяка стъпка боядисва квадратчето, на което се намира. Ако човечето се удари в стена, то все едно рикошира и продължава да боядисва. Нека в началото човечето се намира на клетката с индекси `(i, j)` и започва да се движи в посока `dir` (0 -> нагоре наляво, 1 -> надолу наляво, 2 -> надолу надясно, 3 -> нагоре надясно). Нека функцията да връща след `numMoves` хода колко квадратчета общо ще е боядисало човечето.
    * *Пример:* Тук `i = 5, j = 5, dir = 3, numMoves = 19`. Отговорът е 18.<br><br>
![Пример](https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExdXo4OGV4bHBmbmhtbnF5OXZjcTlhNmU0MG96YmF6NnZ3bmo4c3VpZyZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/pHrqo4P1uqLTI5BVZM/giphy.gif)