#pragma once

#include "Nuzhnoe.h"

class reader 
{

private:
	reader* next;
	reader* prev;

	void swapAndDelClients	(reader*& head, reader*& tail, reader*& readers);
	void transform			(reader*& head, reader*& tail, reader*& readers);
	void show				();

public:

	class Data
	{

	public:

		string	Surname;
		string	Name;
		string	Patronymic;
		string	NumberTicket;
		string	BookName;
		string	RefoundPeriod;
		int 	MaxRefoundPeriod;
	
		Data()
		{
			Surname				 = { "None" };
			Name				 = { "None" };
			Patronymic			 = { "None" };
			NumberTicket		 = { "None" };
			BookName			 = { "None" };
			RefoundPeriod		 = { "None" };
			MaxRefoundPeriod	 = 0;

		}		
		
		Data(const Data& other)
		{
			this->Surname				= other.Surname;
			this->Name					= other.Name;
			this->Patronymic			= other.Patronymic;
			this->NumberTicket			= other.NumberTicket;
			this->BookName				= other.BookName;
			this->RefoundPeriod			= other.RefoundPeriod;
			this->MaxRefoundPeriod		= other.MaxRefoundPeriod;
		}

		void SortData		(reader*& head, reader*& tail, reader*& clients);

	} DATA;

	reader() 
	{

		this->next						= NULL;
		this->prev						= NULL;

		this->DATA.Name					= { "None" };
		this->DATA.Surname				= { "None" };
		this->DATA.Patronymic			= { "None" };
		this->DATA.NumberTicket			= { "None" };
		this->DATA.BookName				= { "None" };
		this->DATA.RefoundPeriod		= { "None" };
		this->DATA.MaxRefoundPeriod		= 0;
	}

	reader(string Surname, string Name, string Patronymic, string NumberTicket, string BookName, string RefoundPeriod, int MaxRefoundPeriod)
	{
		this->next = this;
		this->prev = this;

		this->DATA.Name						= Name;
		this->DATA.Surname					= Surname;
		this->DATA.Patronymic				= Patronymic;
		this->DATA.NumberTicket				= NumberTicket;
		this->DATA.BookName					= BookName;
		this->DATA.RefoundPeriod			= RefoundPeriod;
		this->DATA.MaxRefoundPeriod			= MaxRefoundPeriod;

		cout << "\nФИО: " << this->DATA.Surname << " " << this->DATA.Name << " " << this->DATA.Patronymic
			 << " Номер билета: " << this->DATA.NumberTicket
			 << "\nНазвание книги: " << this->DATA.BookName
			 << " День возврата: " << this->DATA.RefoundPeriod
			 << " Max. возврата: " << this->DATA.MaxRefoundPeriod;

		_getch();
		system("cls");
	}

	~reader()
	{
		if (this)
		{
			while (true)
			{
				if (this->prev)
				{
					this == this->prev;
				}
			}

			if (this->next)
			{
				this == this->next;
				delete this->prev;
			}

			else
			{
				delete this;
			}
		}
	}

	void addReaders			(reader*& head, reader*& tail, reader*& readers);

	void sortReaders		(reader*& head, reader*& tail, reader*& readers);

	void transformReaders	(reader*& head, reader*& tail, reader*& readers);
		
	void delReaders			(reader*& head, reader*& tail, reader*& readers);

	void showReaders		(reader*& head, reader*& tail, reader*& readers);

	void searchReaders		(reader*& head, reader*& tail, reader*& readers);

	void saveReaders		(reader*& head, reader*& tail, reader*& readers);

	void downloadReaders	(reader*& head, reader*& tail, reader*& readers);
};