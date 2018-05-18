
#include <iostream>
#include <vector>
#include <assert.h>
#include <fstream>

using namespace std;

typedef vector<vector<int> > Sudoku;

bool resolverSudoku(Sudoku &s, int x=0, int y=0);
void printSudoku(Sudoku s);
Sudoku leerSudoku(string path, int n);

int main(int argc, char **argv){

	assert(argc == 2);

	//Archivo de sudokus de:
	//http://www.printable-sudoku-puzzles.com/wfiles/

	Sudoku s = leerSudoku( string("data.txt"), atoi(argv[1]) );

	cout << "\n\t ORIGINAL";
	printSudoku(s);
	resolverSudoku(s);

	cout << "\n\t SOLUCION";
	printSudoku(s);
}

Sudoku leerSudoku(string path, int n){

	n--;

	assert(n>=0 && n < 10000);

	ifstream imput(path.c_str());

	for(int i=0; i < n; i++)
		imput.ignore(100, '\n');

	Sudoku s;

	assert(imput.good());

	vector<int> row;
	char v;
	for(int i=0; i < 9; i++){
		for(int j=0; j < 9; j++){
			imput >> v;
			row.push_back(atoi(&v));
		}
		s.push_back(row);
		row.clear();
	}

	return s;
}

void printSudoku(Sudoku s){
	cout << endl;
	cout << "┏━━━━━━━┳━━━━━━━┳━━━━━━━┓" << endl;

	for(int i=0; i < 9; i++){

		if(i == 3 || i == 6){
			cout << "┣━━━━━━━╋━━━━━━━╋━━━━━━━┫" << endl;	
		}

		cout << "┃ ";

		for(int j=0; j < 9; j++){
			if(j==3 || j==6) cout << "┃ ";

			cout << s[j][i] << " ";
		}
		
		cout << "┃" << endl;
	}

	cout << "┗━━━━━━━┻━━━━━━━┻━━━━━━━┛" << endl;

}


bool incrXY(int &x, int &y){

	if(x+1==9)
		if(y+1==9)
			return false;
		else{
			x=0;
			++y;
		}
	else
		++x;

	return true;
}

bool checkRow( Sudoku &s, int x, int y ){

	for(int i=0; i < 9; i++){
		if (i == x) continue;
		if (s[x][y] == s[i][y]) return false;
	}
	return true;
}

bool checkCol( Sudoku &s, int x, int y ){

	for(int i=0; i < 9; i++){
		if (i == y) continue;
		if (s[x][y] == s[x][i]) return false;
	}
	return true;
}

bool checkGroup( Sudoku &s, int x, int y){

	int groupX = x/3;
	int groupY = y/3;

	int iniX = groupX*3;
	int iniY = groupY*3;

	for(int i = iniX; i < iniX+3; i++)
		for(int j = iniY; j < iniY+3; j++){
			if(i == x && j == y) continue;
			if(s[i][j] == s[x][y]) return false;
		}

	return true;
}


bool resolverSudoku(Sudoku &s, int x, int y){

	while(s[x][y] != 0)
		if(!incrXY(x, y)) 
			return true;
	
	for(int i=1; i <= 9; i++){
		
		s[x][y] = i;

		if(checkRow(s,x,y) && checkCol(s,x,y) && checkGroup(s,x,y))
			if (resolverSudoku(s,x,y))
				return true;

		s[x][y] = 0;
	}

	return false;
}