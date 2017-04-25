# Лабораторная работа №25-26. Команда QUEUE. #
## Автоматизация сборки программ модульной структуры на языке Си с использованием утилиты make. ##
## Абстрактные типы данных. Рекурсия. Модульное программирование на языке Си. ##

***

### План: ###

<p>Составить и отладить модуль определений и модуль реализации по заданной схеме модуля определений для абстрактного(пользовательского) типа данных(стека, очереди, списка или дека).
Составить программный модуль, сортирующий экземпляр указанного абстрактного типа данных заданным методом, используя только операции, импортированные из модуля UUDT.</p>

***

### Задание: ###

***Процедура***: поиск в очереди двух элементов, идущих подряд, первый из которых больше второго. Если такие элементы найдены, их перестановка.

<p></p>

***Метод***: сортировка методом пузырька.

***

### О программе: ###

<p>Программа реализует АТД === очередь. Программа имеет следующие функции: создание очереди, заносит число в очередь, выводит число из очереди, сортирует очередь методом пузырька, создает новую очередь, печатает очередь, меню помощи,  выход из программы.</p>

***

### Запуск программы: ###

1. Скачать файлы к себе в папку на ПК.
2.a. Если вы хотите собрать программу без статической библиотеки, если в папке больше нет файлов с названием "Makefile*", то выполнить команду `make`, иначе `make -f Makefile*`.
3.a. Запустить программу командой `./start`.

2.б. Чтобы собрать и запустить программу со статической библиотекой небоходим лишь выполнить команду `./runlib.sh`, но перед этим дать программе права на запуск - `chmod +x runlib.sh`.

***

### Правила пользования программой: ###

<li>`create num` или `c num` === создает очередь размером num.</li>
<li> `put num1 num2 ...`, либо `p num1 num2 ...` == добавляет num1, num2 ... в очередь.</li>
<li>`get` или `g` == выводит элемент из очереди.</li>
<li>`sort` или `s` == сортирует очередь методом пузырька.</li>
<li>`new num` или `n num` === создает новую очередь размером num.</li>
<li>`print` или `pr` === печатает очередь.</li>
<li>`help` == помощь по использованию программы.</li>
<li>`quit` или `q` == для выхода из программы.</li>

***
