/*
  Пример настройки точного вольтметра на внутреннем опорном напряжении.
  Константа вольтметра (по умолчанию 1100) зависит от температуры и отличается в МК из разных партий.
  Удобно настроить константу можно через constantWizard:
    - Вызываем функцию constantWizard()
    - Отправляем ей реальное напряжение питания в милливольтах (измерить между GND и 5V)
    - Будет посчитана константа и предложено записать её в EEPROM (Y - согласиться, N - отказаться)
    - При согласии будет предложено выбрать адрес ячейки, отправляем (0 - 1022) константа займёт 2 ячейки!
    - Удаляем или комментируем функцию constantWizard(), она больше не нужна
    - Для автоматического восстановления константы вызываем restoreConstant(address) при запуске скетча
      - address должен быть таким же, какой вы выбрали в constantWizard =)
      - Всё, теперь функция getVCC() возвращает точное опорное напряжение!
        Для большей точности можно делать среднее по 50 измерениям или фильтровать
    - Константу можно менять вручную, это переменная vcc_const. Например пишем в сетапе vcc_const = 1080
*/

#include "GyverHacks.h"

void setup() {
  Serial.begin(9600);
  
  constantWizard();           // помошник по калибровке константы
  //restoreConstant(1000);    // восстановить из памяти
    
  Serial.println(getVCC());
}

void loop() {

}
