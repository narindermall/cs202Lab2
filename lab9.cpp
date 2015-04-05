#include <iostream>
#include <fstream>
#include <stdexcept>
#include <exception>

using namespace std;

void check (int);
void good(fstream&);

int main(int argc, char* argv[])
{
	char temp[100];
	try
	{
		check( argc );
		fstream fin;
		fin.clear();
		fin.open(argv[1]);
		good(fin);
		while( fin >> temp )
		{
			cout << temp << " ";
		}
		cout << endl;
		fin.close();
	}
	catch(exception& e)
	{
		cout << e.what() <<  "\n";  
	}
	return 0;
}

void check (int num)
{
			if( num != 2 )
			{
				throw runtime_error ( "Invalid number of arguments \n" );
			}

}

void good(fstream& fin)
{
		if( !fin.good() )
		{
				throw runtime_error ( "Could not open file \n" );
		}
}
