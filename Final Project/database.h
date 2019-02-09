#ifndef DATABASE_H
#define DATABASE_H

#include "header.hpp"

/*DATABASE FOR MASTERS*/
class masterDB{
	public:
		int count_no_masters(){
			string y; int x=0;
			ifstream db("master.txt");
			if(db.is_open() && !(db.peek() == ifstream::traits_type::eof())){
				while (!db.eof()){
			      db>>y;
			    }
			    stringstream z(y);		//string to int
			   	z >> x;

				db.close();
				return x;
			}
			else{
				system("cls");
				cout<<"error with master database please check...";
				getch();
				system("cls");
			}			
		}
		string getData(int z){
			string x;
			ifstream db("master.txt");
			if(db.is_open()){
				for(int y=0;y<z;y++){
					getline(db,x);
				}
				db.close();
				return x;
			}
			else{
				system("cls");
				cout<<"error with master database please check...";
				getch();
				system("cls");
			}
		}
		int getDataNum(int z){
			string a; int x;
			ifstream db("master.txt");
			if(db.is_open()){
				for(int y=0;y<z;y++){
					getline(db,a);
				}
				
				stringstream z(a);		//string to int
			   	z >> x;
				
				db.close();
				return x;
			}
			else{
				system("cls");
				cout<<"error with master database please check...";
				getch();
				system("cls");
			}
		}
		void write(string data){
			ofstream db("master.txt", ios::app);
				if(db.is_open()){
					db << data << endl;	
					db.close();
				}
				else{
					system("cls");
					cout<<"error with master database please check...";
					getch();
					system("cls");
				}
		}
		void write(int data){
			ofstream db("master.txt", ios::app);
				if(db.is_open()){
					db << data << endl;	
					db.close();
				}
				else{
					system("cls");
					cout<<"error with master database please check...";
					getch();
					system("cls");
				}
		}
		void clear(){
			ofstream db("master.txt");
			db.close();
		}
};
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------

/*DATABASE FOR TRAINER*/
class trainerDB{
	public:
		int count_no_trainers(){
			string y; int x=0;
			ifstream db("trainer.txt");
			if(db.is_open() && !(db.peek() == ifstream::traits_type::eof())){
				while (!db.eof()){
			      db>>y;
			    }
			    stringstream z(y);		//string to int
			   	z >> x;

				db.close();
				return x;
			}
			else{
				system("cls");
				cout<<"error with trainer database please check...";
				getch();
				system("cls");
			}			
		}
		string getData(int z){
			string x;
			ifstream db("trainer.txt");
			if(db.is_open()){
				for(int y=0;y<z;y++){
					getline(db,x);
				}
				db.close();
				return x;
			}
			else{
				system("cls");
				cout<<"error with trainer database please check...";
				getch();
				system("cls");
			}
		}
		int getDataNum(int z){
			string a; int x;
			ifstream db("trainer.txt");
			if(db.is_open()){
				for(int y=0;y<z;y++){
					getline(db,a);
				}
				
				stringstream z(a);		//string to int
			   	z >> x;
				
				db.close();
				return x;
			}
			else{
				system("cls");
				cout<<"error with trainer database please check...";
				getch();
				system("cls");
			}
		}
		void write(string data){
			ofstream db("trainer.txt", ios::app);
				if(db.is_open()){
					db << data << endl;	
					db.close();
				}
				else{
					system("cls");
					cout<<"error with trainer database please check...";
					getch();
					system("cls");
				}
		}
		void write(int data){
			ofstream db("trainer.txt", ios::app);
				if(db.is_open()){
					db << data << endl;	
					db.close();
				}
				else{
					system("cls");
					cout<<"error with trainer database please check...";
					getch();
					system("cls");
				}
		}
		void clear(){
			ofstream db("trainer.txt");
			db.close();
		}
};
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------


/*DATABASE FOR POKEMON*/
class pokemonDB{
	public:
		int count_no_pokemon(){
			string y; int x=0;
			ifstream db("pokemon.txt");
			if(db.is_open() && !(db.peek() == ifstream::traits_type::eof())){
				while (!db.eof()){
			      db>>y;
			    }
			    stringstream z(y);		//string to int
			   	z >> x;

				db.close();
				return x;
			}
			else{
				system("cls");
				cout<<"error with pokemon database please check...";
				getch();
				system("cls");
			}			
		}
		string getData(int z){
			string x;
			ifstream db("pokemon.txt");
			if(db.is_open()){
				for(int y=0;y<z;y++){
					getline(db,x);
				}
				db.close();
				return x;
			}
			else{
				system("cls");
				cout<<"error with pokemon database please check...";
				getch();
				system("cls");
			}
		}
		void write(string data){
			ofstream db("pokemon.txt", ios::app);
				if(db.is_open()){
					db << data << endl;	
					db.close();
				}
				else{
					system("cls");
					cout<<"error with pokemon database please check...";
					getch();
					system("cls");
				}
		}
		void write(int data){
			ofstream db("pokemon.txt", ios::app);
				if(db.is_open()){
					db << data << endl;	
					db.close();
				}
				else{
					system("cls");
					cout<<"error with pokemon database please check...";
					getch();
					system("cls");
				}
		}
		void clear(){
			ofstream db("pokemon.txt");
			db.close();
		}
};
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------

/*DATABASE FOR ID*/
class IDDB{
	public:
		int getID(){
			string y; int x=1;
			ifstream db("id.txt");
			if(db.is_open() && !(db.peek() == ifstream::traits_type::eof())){
				while (!db.eof()){
			      db>>y;
			    }
			    stringstream z(y);		//string to int
			   	z >> x;

				db.close();
				return x;
			}
			else{
				system("cls");
				cout<<"error with id database please check...";
				getch();
				system("cls");
			}			
		}
		void write(int data){
			ofstream db("id.txt", ios::app);
				if(db.is_open()){
					db << data << endl;	
					db.close();
				}
				else{
					system("cls");
					cout<<"error with id database please check...";
					getch();
					system("cls");
				}
		}
		void clear(){
			ofstream db("id.txt");
			db.close();
		}
};

#endif
