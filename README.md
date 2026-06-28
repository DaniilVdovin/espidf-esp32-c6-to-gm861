# espidf-esp32-c6-to-gm861
Сканер штрих-кодов GM861-LED пример использования

<img width="704" height="339" alt="image" src="https://github.com/user-attachments/assets/3b9b8583-70c7-4d49-ae7f-bf99c5d012cc" />


Пару подсказок. 
- Шанс того что продаван написал правду в описании товара 0

- Даже если уверен что стоит режим UART все равно сканируй QR из мануала
<img width="93" height="105" alt="image" src="https://github.com/user-attachments/assets/87d7571b-c698-4148-a627-7bb43d2c99ae" />

- Если отсканировал (модуль моргнул зеленый) а ничего не происходит, поменяй пины RX TX местами 

- Помни что цвета занчения не имеют

- порядок соовтетвует мануалу, по крайней мере в моей версии, а вот цвета уже нет
<img width="610" height="231" alt="image" src="https://github.com/user-attachments/assets/46bc37f9-53e2-4cc1-9827-affc38f5f629" />

- питание 3.3V 

- нет led так просто не отключить 

- да почти любые пины подойдут под программый rx tx 

- лучше не вешать на те что указаны на плате как RX TX 

- если все еще не идет бери QR из мануала и вводи все по очереди для стандартный настроек

<img width="596" height="186" alt="image" src="https://github.com/user-attachments/assets/99cba75c-5087-4c25-b8a3-5d7b5062ba37" />

QR по названиям найдете в мануале 
