#include <iostream>
#include <cmath>
using namespace std;

int main() {
	setlocale(0, "Rus");
	int task;
	cout << "Введите номер задания(1 - первое, 2 - второе, 3 - третье, 4 - четвертое, 0 - остановить программу): ";
	while (true) {
		cin >> task;
		if (task == 0) 
			break;
		switch (task) {
		case 1:
			cout << "Под тип данных int отводится " << sizeof(int) << " байта." << "\n";
			cout << "Под тип данных short int отводится " << sizeof(short int) << " байта." << "\n";
			cout << "Под тип данных long int отводится " << sizeof(long int) << " байта." << "\n";
			cout << "Под тип данных float отводится " << sizeof(float) << " байта." << "\n";
			cout << "Под тип данных double отводится " << sizeof(double) << " байт." << "\n";
			cout << "Под тип данных long double отводится " << sizeof(long double) << " байт." << "\n";
			cout << "Под тип данных bool отводится " << sizeof(bool) << " байт." << "\n";
			cout << "Под тип данных char отводится " << sizeof(char) << " байт." << "\n";
			break;
		case 2:
		{
			int value;
			unsigned order = sizeof(int) * 8, mask = 1 << (order - 1);
			cout << "Введите целое число: ";
			cin >> value;
			cout << "Ваше число представляется в памяти в виде: ";
			for (int i = 1; i <= order; ++i)
			{
				putchar(value & mask ? '1' : '0');
				mask >>= 1;
				if (i % 8 == 0)
				{
					putchar(' ');
				}
				if (i % order - 1 == 0)
				{
					putchar(' ');
				}
			}
			cout << endl;
			break;
		}
		case 3:
		{
			union {
				float numb_f;
				int value;
			};
			unsigned order = sizeof(float) * 8, mask = 1 << order - 1;
			cout << "Введите вещественное число: ";
			cin >> numb_f;
			cout << "Ваше число представляется в памяти в виде: ";
			for (int i = 1; i <= order; ++i)
			{
				if (i == 2 || i == 10)
				{
					putchar(' ');
				}
				putchar(value & mask ? '1' : '0');
				mask >>= 1;
			}
			cout << endl;
			break;
		}
		case 4:
		{
			union {
				double numb_d;
				int values[2];
			};
			unsigned order = sizeof(double) * 8, mask = 1 << (order - 1);
			cout << "Введите вещественное число с плавающей точкой: ";
			cin >> numb_d;
			cout << "Ваше число представляется в памяти в виде: ";
			for (int j = 1; j >= 0; j--) {
				for (int i = 1; i <= order / 2; i++)
				{
					putchar(values[j] & mask ? '1' : '0');
					values[j] <<= 1;
					if ((i == 1 || i == 12) && j == 1) {               // ((i % 8 == 0 || i == 1) && j == 1 || i % 8 == 0)
						putchar(' ');
					}
				}
			}
			cout << endl;
			break;
		}
		}
	}
}
