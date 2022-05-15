#pragma once

#include "Nuzhnoe.h"
#include "Class.h"

void reader::Data::SortData		(reader*& head, reader*& tail, reader*& readers)
{
	readers = head;

	int counter = 1;
	reader* temp = new reader;
	
	while (true) 
	{
		counter++;
		readers = readers->next;
		if (readers == tail) break;
	}

	readers = head;

	for (int i = 1; i < counter; i++)
	{
		readers = head;

		for (int j = 0; j < counter - i; j++)
		{
			if (readers->DATA.MaxRefoundPeriod > readers->next->DATA.MaxRefoundPeriod)
			{
				temp->DATA = readers->DATA;
				readers->DATA = readers->next->DATA;
				readers->next->DATA = temp->DATA;
			}
			readers = readers->next;
		}
	}
	std::cout << "\nОперация завершена";

	_getch();
	std::system("cls");
	return;
	
}

void reader::addReaders			(reader*& head, reader*& tail, reader*& readers)
{
	string	newSurname = { "None" };
	string	newName = { "None" };
	string	newPatronymic = { "None" };
	string	newNumberTicket = { "None" };
	string	newBookName = { "None" };
	string	newRefoundPeriod = { "None" };
	char	newMaxRefoundPeriod[100];

	std::cout << "\nВведите данные клиента\n";
	std::cout << "\nФамилия: "; 	cin.get();			getline(cin, newSurname);
	std::cout << "\nИмя: ";								getline(cin, newName);
	std::cout << "\nОтчество: ";						getline(cin, newPatronymic);
	std::cout << "\nНомер билета: ";					getline(cin, newNumberTicket);
	std::cout << "\nНазвание книги: ";					getline(cin, newBookName);
	std::cout << "\nДень возврата: ";					getline(cin, newRefoundPeriod);
	std::cout << "\nMax. возврата: ";					cin.getline(newMaxRefoundPeriod, 100); ;

	std::system("cls");

	int newSum = isInteger_l(newMaxRefoundPeriod);

	if (tail == NULL && head == NULL)
	{
		tail = new reader;
		readers = tail;
		head = tail;
	}

	else
	{
		readers = tail;
		readers->next = new reader;
		readers->next->prev = readers;
		readers = readers->next;
		tail = readers;
	}

	readers->DATA.Surname				 = newSurname;
	readers->DATA.Name					 = newName;
	readers->DATA.Patronymic			 = newPatronymic;
	readers->DATA.NumberTicket			 = newNumberTicket;
	readers->DATA.BookName				 = newBookName;
	readers->DATA.RefoundPeriod			 = newRefoundPeriod;
	readers->DATA.MaxRefoundPeriod		 = newSum;

	_getch();
	std::system("cls");
	return;
}

void reader::sortReaders		(reader*& head, reader*& tail, reader*& readers)
{
	if (tail == NULL && head == NULL)
		throw exception("\n\n\tНет данных клиентов для сортировки...");

	if (readers == head && readers == tail)
		throw exception("\n\n\tМало данных клиентов для сортировки...");

	std::cout << "\nСортировать по\n\n1) Фамилии\t2) Имя\n\nВыбор: ";

	char choice;
	cin >> choice;

	readers = head;
	int counter = 1;
	reader* temp = NULL;
	temp = new reader;

	while (true)
	{
		counter++;
		readers = readers->next;
		if (readers == tail) break;
	}

	readers = head;

	std::system("cls");

	switch (choice)
	{
		case(1):
		{
			for (int i = 1; i < counter; i++)
			{
				readers = head;

				for (int j = 0; j < counter - i; j++)
				{
					if (readers->DATA.Surname > readers->next->DATA.Surname)
					{
						temp->DATA = readers->DATA;
						readers->DATA = readers->next->DATA;
						readers->next->DATA = temp->DATA;
					}
					readers = readers->next;
				}
			}
			std::cout << "\nОперация завершена";

			_getch();
			std::system("cls");
			return;
		}

		case(2):
		{
			for (int i = 1; i < counter; i++)
			{
				readers = head;
				for (int j = 0; j < counter - i; j++)
				{
					if (readers->DATA.Name > readers->next->DATA.Name)
					{
						temp->DATA = readers->DATA;
						readers->DATA = readers->next->DATA;
						readers->next->DATA = temp->DATA;
					}
					readers = readers->next;
				}
			}
			cout << "\nОперация завершена";

			_getch();
			system("cls");
			return;
		}

		default:
		{
			throw exception("\nВведено неверное значение");
		}
	}

	system("cls");
}

void reader::transform			(reader*& head, reader*& tail, reader*& readers)
{
	std::cout << "1. Фамилия - " << readers->DATA.Surname
			 << "\n2. Имя - " << readers->DATA.Name
			 << "\n3. Отчество - " << readers->DATA.Patronymic
			 << "\n4. Номер билета - " << readers->DATA.NumberTicket
			 << "\n5. Название книги - " << readers->DATA.BookName
			 << "\n6. День возврата - " << readers->DATA.RefoundPeriod
			 << "\n7. Max. возврата - " << readers->DATA.MaxRefoundPeriod;
	int choice;
	cin >> choice;

	switch (choice)
	{
		case(1): {std::cout << "\nВведите Фамилию: ";				cin.get(); getline(cin, readers->DATA.Surname); 		break; }
		case(2): {std::cout << "\nВведите Имя: ";					cin.get(); getline(cin, readers->DATA.Name); 			break; }
		case(3): {std::cout << "\nВведите Отчество: ";				cin.get(); getline(cin, readers->DATA.Patronymic);		break; }
		case(4): {std::cout << "\nВведите Номер билета: ";			cin.get(); getline(cin, readers->DATA.NumberTicket); 	break; }
		case(5): {std::cout << "\nВведите Название книги: ";			cin.get(); getline(cin, readers->DATA.BookName); 		break; }
		case(6): {std::cout << "\nВведите День возврата: ";			cin.get(); getline(cin, readers->DATA.RefoundPeriod);	break; }
		case(7): {std::cout << "\nВведите Max. возврата: ";			cin.get(); cin >> readers->DATA.MaxRefoundPeriod;		break; }
		default: {
			throw exception("\nВведено неверное значение");
		}
	}
	std::system("cls");
}
void reader::transformReaders	(reader*& head, reader*& tail, reader*& readers)
{
	if (tail == NULL && head == NULL)
		throw exception("\n\n\tНет данных клиентов для изменения...");

	std::cout << "\n\n\tИзменить данные клиента\n\n\t\tПоиск по \n\n\t1. ФИО\t2. Счёту в базе\t0. Выход\n\n\t";
	char choice;
	cin >> choice;

	std::system("cls");

	readers = head;

	switch (choice)
		{

		case(1):
		{
			std::cout << "\nВведите Фамилию или Имя или Отчество\nВыбор: ";
			string str;
			cin >> str;
			std::system("cls");

			if (str == "0") { return; }

			int searchID = -1;
			int couErr = 0;
			int id = 1;
			while (true) 
			{
				if (str == readers->DATA.Surname)		{ searchID = id; couErr++; }
				if (str == readers->DATA.Name)			{ searchID = id; couErr++; }
				if (str == readers->DATA.Patronymic)	{ searchID = id; couErr++; }
				if (readers->next == NULL) break;
				readers = readers->next;
				id++;
			}
			if (couErr > 1) 
				throw exception("\nНайдено много совпадений");

			if (searchID == -1) 
				throw exception("\nНе найдено ");
				
			if (searchID >= 0)
			{
				readers = head;

				for (int i = 0; i < searchID - 1; i++)
				{
					readers = readers->next;
				}
				transform(head, tail, readers);

				return;
				
			}
		}

		case(2):
		{
			std::cout << "\nВведите номер\nВыбор: ";
			int inputInt;
			cin >> inputInt;


			for (int i = 0; i < inputInt - 1; i++) 
			{
				readers = readers->next;
			}

			std::system("cls");

			transform(head, tail, readers);

			return;

		}
	}

	std::system("cls");
}

void reader::swapAndDelClients	(reader*& head, reader*& tail, reader*& readers)
{
	if (readers != head && readers != tail) {
		readers->prev->next = readers->next;
		readers->next->prev = readers->prev;
		delete readers;
	}
	else if (readers == head && readers != tail) {
		head = readers->next;
		head->prev = NULL;
		delete readers;
	}
	else if (readers == tail && readers != head) {
		tail = readers->prev;
		tail->next = NULL;
		delete readers;
	}
	else {
		head = NULL;
		tail = NULL;

	}
}
void reader::delReaders			(reader*& head, reader*& tail, reader*& readers)
{
	if (tail == NULL && head == NULL)
		throw exception("\n\n\tНет данных клиентов для удаления...");

	readers = head;
	while (true) {
		if (readers->next == NULL) break;
		readers = readers->next;
		tail = readers;
	}
	while (true) {
		if (readers->prev == NULL) break;
		readers = readers->prev;
		head = readers;
	}
	cout << "\nУдалить данные по \n1. ФИО\t2. Счёту\nВыбор: ";

	int choice;
	cin >> choice;

	system("cls");

	readers = head;

	switch (choice)
	{
		case(1):
		{
			cout << "\nВведите Фамилию или Имя или Отчество\nВвод: ";

			string inputStr;
			cin >> inputStr;

			system("cls");

			int id = 1;
			int searchID = -1;
			int couErr = 0;

			while (true)
			{
				if (inputStr == readers->DATA.Surname) { searchID = id; couErr++; }
				if (inputStr == readers->DATA.Name) { searchID = id; couErr++; }
				if (inputStr == readers->DATA.Patronymic) { searchID = id; couErr++; }
				if (readers == tail) break;
				readers = readers->next;
				id++;
			}
			if (couErr > 1)
				throw exception("\nНайдено много совпадений");

			if (searchID == -1)
				throw exception("\nНе найдено");

			if (searchID >= 0) 
			{
				readers = head;
				for (int i = 1; i < searchID; i++)
					readers = readers->next;

				system("cls");

				swapAndDelClients(head, tail, readers);
				cout << "\nОперация завершена";

				_getch();
				system("cls");
				return;

			}
		}

		case(2):
		{
			cout << "\nВведите номер\nВвод: ";

			int vvod;
			cin >> vvod;

			readers = head;

			for (int i = 0; i < vvod - 1; i++)
			{
				readers = readers->next;
			}
			system("cls");

			swapAndDelClients(head, tail, readers);
			cout << "\nОперация завершена";

			_getch();
			system("cls");
			return;

		}

		default:
		{
			throw exception("\nВведено неверное значение");
		}

	}
	readers = head;
	system("cls");
}

void reader::showReaders		(reader*& head, reader*& tail, reader*& readers)
{
	if (tail == NULL && head == NULL)
		throw exception("\nНет данных");

	int maxLenSurname				= 7;
	int maxLenName					= 3;
	int maxLenPatronymic			= 8;
	int maxLenNumberTicket			= 15;
	int maxLenBookName				= 16;
	int maxLenRefoundPeriod			= 11;
	int maxLenMaxRefoundPeriod		= 13;

	int maxMaxRefoundPeriod			= 0;

	readers	= head;

	while (true)
	{
		int LenSurname				= readers->DATA.Surname.length();
		int LenName					= readers->DATA.Name.length();
		int LenPatronymic			= readers->DATA.Patronymic.length();
		int LenNumberTicket			= readers->DATA.NumberTicket.length();
		int LenBookName				= readers->DATA.BookName.length();
		int LenRefoundPeriod		= readers->DATA.RefoundPeriod.length();
		int LenMaxRefoundPeriod		= 0;
		int MaxRefoundPeriod		= readers->DATA.MaxRefoundPeriod;
		int g						= 0;
		while (MaxRefoundPeriod > 0)	{ MaxRefoundPeriod /= 10; LenMaxRefoundPeriod++; }
		maxMaxRefoundPeriod				+= readers->DATA.MaxRefoundPeriod;

		int sravn = readers->DATA.MaxRefoundPeriod;    //вычисление максимального срока возрата
		for (int i = 0; i < 10; i++)
		{
			if (sravn > readers->DATA.MaxRefoundPeriod)
				sravn = readers->DATA.MaxRefoundPeriod;
		}

		maxMaxRefoundPeriod = sravn;

		if (LenSurname					> maxLenSurname)			{ maxLenSurname				= LenSurname;		}
		if (LenName						> maxLenName)				{ maxLenName				= LenName;			}
		if (LenPatronymic				> maxLenPatronymic)			{ maxLenPatronymic			= LenPatronymic;	}
		if (LenNumberTicket				> maxLenNumberTicket)		{ maxLenNumberTicket		= LenNumberTicket;		}
		if (LenBookName					> maxLenBookName)			{ maxLenBookName			= LenBookName;		}
		if (LenRefoundPeriod			> maxLenRefoundPeriod)		{ maxLenRefoundPeriod		= LenRefoundPeriod;		}
		if (LenMaxRefoundPeriod			> maxLenMaxRefoundPeriod)	{ maxLenMaxRefoundPeriod	= LenMaxRefoundPeriod;			}
		if (readers == tail) break;
		readers				= readers->next;
	}

	readers = head;

	int maxLength = maxLenSurname + maxLenName + maxLenPatronymic
		+ maxLenNumberTicket + maxLenBookName + maxLenRefoundPeriod + maxLenMaxRefoundPeriod + 22;



	cout << "\t";
	for (int i = 0; i < maxLength; i++) { cout << "-"; }
	cout << endl;

	printf_s("\t| %*s | %*s | %*s | %*s | %*s | %*s | %*s |",
		maxLenSurname,				"Фамилия",
		maxLenName,					"Имя",
		maxLenPatronymic,			"Отчество",
		maxLenNumberTicket,			"Номер билета",
		maxLenBookName,				"Название книги",
		maxLenRefoundPeriod,		"День возврата",
		maxLenMaxRefoundPeriod,		"Max.возврата");
	cout << "\n\t";

	for (int i = 0; i < maxLength; i++) { cout << "-"; }
	cout << "\n";

	while (true) 
	{
		printf_s(
			"\t| %*s | %*s | %*s | %*s | %*s | %*s | %*d |",
			maxLenSurname,				readers->DATA.Surname.c_str(),
			maxLenName,					readers->DATA.Name.c_str(),
			maxLenPatronymic,			readers->DATA.Patronymic.c_str(),
			maxLenNumberTicket,			readers->DATA.NumberTicket.c_str(),
			maxLenBookName,				readers->DATA.BookName.c_str(),
			maxLenRefoundPeriod,		readers->DATA.RefoundPeriod.c_str(),
			maxLenMaxRefoundPeriod,		readers->DATA.MaxRefoundPeriod
		);

		cout << "\n\t";

		for (int i = 0; i < maxLength; i++) { cout << "-"; }
		cout << endl;
		if (readers->next == NULL) break;
		readers = readers->next;
	}

	readers = head;

	cout << "\t";
	for (int i = 0; i < maxLength - (maxLenRefoundPeriod + 6); i++) { cout << " "; }
	printf_s("| %*d |", maxLenMaxRefoundPeriod, maxMaxRefoundPeriod); cout << "\n\t";
	for (int i = 0; i < maxLength - (maxLenRefoundPeriod + 6); i++) { cout << " "; }
	for (int i = 0; i < maxLenRefoundPeriod + 6; i++) { cout << "-"; }

	_getch();
	system("cls");
}

void reader::show				()
{
	cout << "\nФИО: " << this->DATA.Surname << " " << this->DATA.Name << " " << this->DATA.Patronymic 
		<< "\nНомер билета: "<< this->DATA.NumberTicket 
		<< "\nНазвание книги: " << this->DATA.BookName 
		<< "\nДень возврата: " << this->DATA.RefoundPeriod 
		<< "\nMax. возврата: " << this->DATA.MaxRefoundPeriod;
}
void reader::searchReaders		(reader*& head, reader*& tail, reader*& readers)
{
	if (tail == NULL && head == NULL)
		throw exception("\nНет данных");

	cout << "\nВведите Фамилию или Имя или Отчество\nВвод: ";

	string vvod;
	cin >> vvod;

	system("cls");

	if (vvod == "0") { return; }

	readers = head;

	bool searchID = false;
	while (true)
	{
		if (vvod == readers->DATA.Surname)		 { searchID = true; show(); }
		if (vvod == readers->DATA.Name)			 { searchID = true; show(); }
		if (vvod == readers->DATA.Patronymic)	 { searchID = true; show(); }
		if (readers->next == NULL) break;
		readers = readers->next;
	}

	readers = head;

	if (searchID == true) { _getch(); system("cls");  return; }
	if (searchID == false) { cout << "\nКлиент не найден"; _getch(); system("cls"); return; }

	system("cls");
}

void reader::saveReaders		(reader*& head, reader*& tail, reader*& readers)
{
	if (tail == NULL && head == NULL)
		throw exception("\nНет данных");

	string defaultFileName = (INDIVID_OUTPUT_FILE_LOCATION);
	cout << "\n1) Сохранить в файле по умолчанию\n2) Сохранить в свой файл\nВыбор: ";

	int choice;
	cin >> choice;

	system("cls");

	switch (choice)
	{
		case(1):
		{
			ofstream outClients(INDIVID_OUTPUT_FILE_LOCATION);

			readers = head;

			while (true)
			{
				outClients << "ФИО: " << readers->DATA.Surname << " " << readers->DATA.Name << " "
					<< readers->DATA.Patronymic << " Номер билета: " << readers->DATA.NumberTicket << " Название книги.: "
					<< readers->DATA.BookName << " День возврата: " << readers->DATA.RefoundPeriod << " Max. возврата: "
					<< readers->DATA.MaxRefoundPeriod << endl;
				if (readers == tail) break;
				readers = readers->next;
			}
			cout << "\nСохранение завершено";

			_getch();
			system("cls");
			break;
		}

		case(2):
		{
			cout << "\nВведите навание файла: ";

			string fileName;
			cin.get();
			getline(cin, fileName);
			fileName += ".txt";

			system("cls");

			ofstream outClients(fileName);

			readers = head;

			while (true)
			{
				outClients << "ФИО: " << readers->DATA.Surname << " " << readers->DATA.Name << " "
					<< readers->DATA.Patronymic << " Номер билета: " << readers->DATA.NumberTicket << " Название книги.: "
					<< readers->DATA.BookName << " День возврата: " << readers->DATA.RefoundPeriod << " Max. возврата: "
					<< readers->DATA.MaxRefoundPeriod << endl;
				if (readers == tail) break;
				readers = readers->next;
			}
			cout << "\nСохранение завершено";

			_getch();
			system("cls");
			break;
		}

		default:
		{
			throw exception("\n\n\tВведено невенрое значение...");
		}

	}
}

void reader::downloadReaders	(reader*& head, reader*& tail, reader*& readers)
{
	cout << "\n1) Загрузтиь из файла по умолчанию\n2) Загрузить из своего файла\nВыбор: ";

	int choice;
	cin >> choice;

	system("cls");

	switch (choice)
	{
		case(1):
		{
			ifstream inClients(INDIVID_INPUT_FILE_LOCATION);

			if (inClients.bad())
				throw exception("\n\tОшибка ввода-вывода при чтении");

			if (inClients.eof())
				throw exception("\n\tДостигнут конец файла");

			if (inClients.fail())
				throw exception("\n\tНеверный формат данных");

			int size = 0;
			inClients >> size;

			for (int i = 0; i < size; i++)
			{
				if (readers == NULL) {
					readers = new reader;
					head = readers;
					tail = readers;
				}

				else {
					readers = tail;
					readers->next = new reader;
					readers->next->prev = readers;
					readers = readers->next;
					tail = readers;
				}

				inClients.get();
				getline(inClients, readers->DATA.Surname);
				getline(inClients, readers->DATA.Name);
				getline(inClients, readers->DATA.Patronymic);
				getline(inClients, readers->DATA.NumberTicket);
				getline(inClients, readers->DATA.BookName);
				getline(inClients, readers->DATA.RefoundPeriod);
				inClients >> readers->DATA.MaxRefoundPeriod;
			}

			cout << "\nЗагрузка завершена";

			 _getch();
			system("cls");
			break;
		}

		case(2):
		{
			cout << "\nВведите навание файла: ";

			string newName;
			cin.get();
			getline(cin, newName);
			newName += ".txt";

			system("cls");

			ifstream inClients(newName);

			if (inClients.bad())
				throw exception("\n\tОшибка ввода-вывода при чтении");


			if (inClients.eof())
				throw exception("\n\tДостигнут конец файла");


			if (inClients.fail())
				throw exception("\n\tНеверный формат данных");

			int size = 0;
			inClients >> size;

			readers = new reader;
			head = readers;

			for (int i = 0; i < size; i++)
			{
				if (readers == NULL)
				{
					readers = new reader;
					head = readers;
				}
				else {
					readers = readers->next = new reader;
					tail = readers;
				}
				inClients.get();
				getline(inClients, readers->DATA.Surname);
				getline(inClients, readers->DATA.Name);
				getline(inClients, readers->DATA.Patronymic);
				getline(inClients, readers->DATA.NumberTicket);
				getline(inClients, readers->DATA.BookName);
				getline(inClients, readers->DATA.RefoundPeriod);
				inClients >> readers->DATA.MaxRefoundPeriod;
			}

			cout << "\nЗагрузка завершена";

			_getch();
			system("cls");
			break;
		}

		default:
		{
			throw exception("\nВведено невенрое значение");
		}
	}
}
