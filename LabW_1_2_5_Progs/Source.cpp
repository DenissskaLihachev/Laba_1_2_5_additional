#include "Nuzhnoe.h"
#include "Class.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	reader* head = NULL;
	reader* tail = NULL;
	reader* readers = NULL;

	while (true)
	{
		cout << "\n1) Добавить читателя";
		cout << "\n2) Сортировать читателя";
		cout << "\n3) Изменить данные читателя";
		cout << "\n4) Удалить читателя";
		cout << "\n5) Вывести читателя";
		cout << "\n6) Поиск читателя";

#if VER == 2

		cout << "\n7) Сохранить данные в файл";
		cout << "\n8) Загрузить данные из файла";
		cout << "\n\nВыбор: ";

#endif

		int choice;
		cin >> choice;
		system("cls");

		readers = head;

		switch (choice)
		{
		case (1):
		{
			try
			{
				readers->addReaders(head, tail, readers);
			}
			catch (const exception& err)
			{
				cout << err.what() << " ... ";
				_getch();
				system("cls");
				//break;
			}
			continue;
		}

		case (2):
		{
			try
			{
				readers->sortReaders(head, tail, readers);
			}
			catch (const exception& err)
			{
				cout << err.what() << " ... ";
				_getch();
				system("cls");
				//break;
			}
			continue;
		}

		case (3):
		{
			try
			{
				readers->transformReaders(head, tail, readers);
			}
			catch (const exception& err)
			{
				cout << err.what() << " ... ";
				_getch();
				system("cls");
			}
			continue;
		}

		case (4):
		{
			try
			{
				readers->delReaders(head, tail, readers);
			}
			catch (const exception& err)
			{
				cout << err.what() << " ... ";
				_getch();
				system("cls");
			}
			continue;
		}

		case (5):
		{
			try
			{
				readers->showReaders(head, tail, readers);
			}
			catch (const exception& err)
			{
				cout << err.what() << " ... ";
				_getch();
				system("cls");
				//break;
			}
			continue;
		}

		case (6):
		{
			try
			{
				readers->searchReaders(head, tail, readers);
			}
			catch (const exception& err)
			{
				cout << err.what() << " ... ";
				 _getch();
				system("cls");
				//break;
			}
			continue;
		}

#if VER == 2

		case (7):
		{
			try
			{
				readers->saveReaders(head, tail, readers);
			}
			catch (const exception& err)
			{
				cout << err.what() << " ... ";
				_getch();
				system("cls");
			}
			continue;
		}

		case (8):
		{
			try {
				readers->downloadReaders(head, tail, readers);
			}
			catch (const exception& err)
			{
				cout << err.what() << " ... ";
				_getch();
				system("cls");
			}
			continue;
		}

#endif
		default:
		{
			throw exception("Введено неверное значение, нажмите любую клавишу для продолжения... ");
		}

		}
	}
}