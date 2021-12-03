# D. Наполненность котятами
https://contest.yandex.ru/contest/29396/problems/D/

Ограничение времени

2 секунды

Ограничение памяти

256Mb

### Ввод

стандартный ввод или input.txt

### Вывод

стандартный вывод или output.txt

На прямой в точках <math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><msub><mrow><mi>a</mi></mrow><mrow><mn>1</mn></mrow></msub><mo>,</mo><msub><mrow><mi>a</mi></mrow><mrow><mn>2</mn></mrow></msub><mo>,</mo><mo>…</mo><mo>,</mo><msub><mrow><mi>a</mi></mrow><mrow><mi>n</mi></mrow></msub></math> (возможно, совпадающих) сидят <math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math> котят. На той же прямой лежат <math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mi>m</mi></math> отрезков <math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mrow><mo>[</mo><mrow><msub><mrow><mi>l</mi></mrow><mrow><mn>1</mn></mrow></msub><mo>,</mo><msub><mrow><mi>r</mi></mrow><mrow><mn>1</mn></mrow></msub></mrow><mo>]</mo></mrow><mo>,</mo><mrow><mo>[</mo><mrow><msub><mrow><mi>l</mi></mrow><mrow><mn>2</mn></mrow></msub><mo>,</mo><msub><mrow><mi>r</mi></mrow><mrow><mn>2</mn></mrow></msub></mrow><mo>]</mo></mrow><mo>,</mo><mo>…</mo><mo>,</mo><mrow><mo>[</mo><mrow><msub><mrow><mi>l</mi></mrow><mrow><mi>m</mi></mrow></msub><mo>,</mo><msub><mrow><mi>r</mi></mrow><mrow><mi>m</mi></mrow></msub></mrow><mo>]</mo></mrow></math>. Нужно для каждого отрезка узнать его наполненность котятами — сколько котят сидит на отрезке.

## Формат ввода

На первой строке <math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math> и <math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mi>m</mi></math> (<math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn> <mo>≤</mo> <mi>n</mi><mo>,</mo><mi>m</mi> <mo>≤</mo> <mn>1</mn><msup><mrow><mn>e</mn></mrow><mrow><mn>5</mn></mrow></msup></math>). На второй строке <math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math> целых чисел <math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><msub><mrow><mi>a</mi></mrow><mrow><mi>i</mi></mrow></msub></math> (<math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn> <mo>≤</mo> <msub><mrow><mi>a</mi></mrow><mrow><mi>i</mi></mrow></msub> <mo>≤</mo> <mn>1</mn><msup><mrow><mn>e</mn></mrow><mrow><mn>9</mn></mrow></msup></math>). Следующие <math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mi>m</mi></math> строк содержат пары целых чисел <math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><msub><mrow><mi>l</mi></mrow><mrow><mi>i</mi></mrow></msub><mo>,</mo><msub><mrow><mi>r</mi></mrow><mrow><mi>i</mi></mrow></msub></math> (<math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn> <mo>≤</mo> <msub><mrow><mi>l</mi></mrow><mrow><mi>i</mi></mrow></msub> <mo>≤</mo> <msub><mrow><mi>r</mi></mrow><mrow><mi>i</mi></mrow></msub> <mo>≤</mo> <mn>1</mn><msup><mrow><mn>e</mn></mrow><mrow><mn>9</mn></mrow></msup></math>).

## Формат вывода

Выведите m<math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mi>m</mi></math> целых чисел. <math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mi>i</mi></math>-е число — наполненность котятами <math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mi>i</mi></math>-го отрезка.