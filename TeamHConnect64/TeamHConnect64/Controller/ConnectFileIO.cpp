#include "..\ConnectFileIO.h"
#using<system.dll>
using namespace System;
using namespace System::IO;

namespace Controller{
	ConnectFileIO::ConnectFileIO()
	{
		
	}

	void ConnectFileIO::ReadFile(String^ fileName)
	{
		try
		{
			StreamReader^ din = File::OpenText(fileName);

			String^ str;
			int count = 0;
			while ((str = din->ReadLine()) != nullptr)
			{
				if (count != 0)
				{
					array<String^>^ values;
					values = str->Split(',');
					int x = Int32::Parse(values[0]);
					int y = Int32::Parse(values[1]);;
					int value = Int32::Parse(values[2]);;
					this->board->setTile(x, y, value);
				} else
				{
					array<String^>^ values;
					values = str->Split(',');
					this->puzzleNumber = Int32::Parse(values[0]);
					this->board = gcnew Board(this->puzzleNumber);
				}
				count++;
			}
		}
		catch (Exception^ e)
		{
			if (dynamic_cast<FileNotFoundException^>(e))
				Console::WriteLine("file '{0}' not found", fileName);
			else
				Console::WriteLine("problem reading file '{0}'", fileName);
		}

	}

	Board^ ConnectFileIO::GetBoard()
	{
		return this->board;
	}

	int ConnectFileIO::GetPuzzleNumber()
	{
		return this->puzzleNumber;
	}

}