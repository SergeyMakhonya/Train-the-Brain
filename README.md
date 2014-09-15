Train-the-Brain
===============

Эти программы будут тренировать ваши мозги...

Введение
----------------

Как известно, человеческий мозг при отсутствии необходимости запоминать НОВУЮ информацию, постепенно теряет навык к запоминанию. Данная программа направлена на тренировку мозга запоминать новую информацию. Приложение демонстрирует некую последовательность, и через некоторое время просит воспроизвести ее, результаты теста заносятся в базу данных, для последующего составления графика прогресса.

Задумка
===============

Версия на C++ (Идея Sergey Makhonya)
----------------

После запуска программы открывается форма. На ней есть опции программы и красивый цветной линейный график с результатами ежедневного тестирования. В опциях есть возможность поставить галочку для того что бы разрешить программе показывать в углу экрана окошечко с рандомным вопросом, которое будет появлятся через определённый интервал времени или по расписанию. На главной форме, где отображается график, есть "красная" кнопка. Если на неё нажать, рядом с ней же откроется что то типа дверки потайного ящика (прямо как платформа в стене из игры Portal 2). В этот ящик можно будет скинуть файл с вопросами и ответами, например по математическому анализу. После этого программа будет знает о чём нас ещё можно спросить :)

Версия на Delphi (Идея Vlad Kudelko)
----------------

Открывается форма, там кнопка старт, кнопка статистика и 2 текстовых поля. 1-ое - скорость просмотра. 2-ое - количество чисел. При нажатии кнопки старт, открывается 2-ая форма. На ней отображаются рандомные наборы чисел с заданными параметрами и промежутком времени, одновременно занося к себе в буфер все эти числа. Потом эта форма закрывается, и открывается другая форма со счетчиком: подождите Х секунд (время пропорционально количеству показаной информации). После окончания счетчика, открывается Memo. В него вводите туда все что вспомните. Потом программа проходит по тексту и смотрит процент совпадений с исходным буфером. Этот процент и данные о скорости с количеством заносятся в БД. Если на главной форме нажать кнопку статистика, то появится график, составленный при помощи данных из БД.

Параметры
===============

* Язык программирования: C++12
* IDE: Visual Studio 2013 Express Desktop
* [SFML Latest Version from GitHub repository](https://github.com/LaurentGomila/SFML) (Скомпилирована компилятором Visual C++12)

Ссылки
===============

* [Visual Studio](http://www.visualstudio.com/downloads/download-visual-studio-vs)
* [SFML](http://sfml-dev.org/index.php)

Лицензия
===============

[GNU General Public License (GPL) version 3](http://www.gnu.org/copyleft/gpl.html)

![gnu gpl v3](http://www.gnu.org/graphics/gplv3-127x51.png)
