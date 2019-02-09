#ifndef POKEMONMASTER_H
#define POKEMONMASTER_H

#include "header.hpp"

class PokemonMaster{
	protected:
		string username, password, id, firstName, lastName, bday, sex, address, contact, pokemon[200];
		int pokemons;
		
	public:
		int menu(int masters, int trainers, int no_pokemon){
			int choice=1;
			
			for(;;){
				if(choice==1){cout<<"[X] create master\n";}else{cout<<"[ ] create master\n";}
				if(choice==2){cout<<"[X] create trainer\n";}else{cout<<"[ ] create trainer\n";}
				if(choice==3){cout<<"[X] delete user\n";}else{cout<<"[ ] delete user\n";}
				if(choice==4){cout<<"[X] display user\n";}else{cout<<"[ ] display user\n";}	
				if(choice==5){cout<<"[X] display all users\n";}else{cout<<"[ ] display all users\n";}
				if(choice==6){cout<<"[X] catch a pokemon\n";}else{cout<<"[ ] catch a pokemon\n";}
				if(choice==7){cout<<"[X] create pokemon\n";}else{cout<<"[ ] create pokemon\n";}
				if(choice==8){cout<<"[X] delete pokemon\n";}else{cout<<"[ ] delete pokemon\n";}
				if(choice==9){cout<<"[X] display pokemons\n";}else{cout<<"[ ] display pokemons\n";}
				if(choice==10){cout<<"[X] logout\n";}else{cout<<"[ ] logout\n";}
				
				choice = trap.arrow10(choice);
				
				if(choice>10){ choice-=10;
					system("cls");
					
					if(choice==1){					//CREATE MASTER
						if(masters<15){
							return 1;
						}
						else{
							cout<<"number of masters that can be created reached! press any key to continue";
							getch();
						}
					}
					else if(choice==2){				//CREATE TRAINER
						if(trainers<15){
							return 2;
						}
						else{
							cout<<"number of trainers that can be created reached! press any key to continue";
							getch();
						}
					}
					else if(choice==3){				//DELETE USER
						return 3;
					}
					else if(choice==4){				//DISPLAY USER
						print();
						getch();
					}
					else if(choice==5){				//DISPLAY ALL USERS
						return 5;
					}
					else if(choice==6){				//CATCH POKEMON
						return 6;
					}
					else if(choice==7){				//CREATE POKEMON
						if(no_pokemon<151){
							return 7;
						}
						else{
							cout<<"number of pokemon that can be created reached! press any key to continue";
							getch();
						}
					}
					else if(choice==8){				//DELETE POKEMON
						return 8;
					}
					else if(choice==9){				//DISPLAY ALL POKEMONS
						return 9;
					}
					else if(choice==10){			//LOGOUT
						return 0;
					}
				}
				system("cls");
			}	
		}
		//---------------------------------------------------------------------------------------------------------------------
		//---------------------------------------------------------------------------------------------------------------------
		
		void print(){
			cout<<"username: "<<to_upper(username)<<endl;
			//cout<<"password: "<<password<<endl;			//OPTED TO HIDE PASSWORD
			cout<<"id: "<<id<<endl;
			cout<<"first name: "<<to_upper(firstName)<<endl;
			cout<<"last name: "<<to_upper(lastName)<<endl;
			cout<<"bday: "<<to_upper(bday)<<endl;
			cout<<"sex: "<<to_upper(sex)<<endl;
			cout<<"address: "<<to_upper(address)<<endl;
			cout<<"contact: "<<to_upper(contact)<<endl;
		}
		void create(string user, string latest_id){
			id = latest_id;
			username = user;
			cout<<"password: ";
			password = trap.noBlank();
			cout<<"first name: ";
			firstName = trap.getInput();
			cout<<"last name: ";
			lastName = trap.getInput();
			cout<<"bday: ";
			bday = trap.noBlank(); 
			cout<<"sex: ";
			sex = trap.getInput();
			cout<<"address: ";
			address = trap.noBlank();
			cout<<"contact: ";
			contact = trap.getNumber();
			pokemons=0;
			
			cout<<"press any to continue";
		}
		void catchPoke(string pokemonName){
			pokemon[pokemons]=pokemonName;
			pokemons++;
		}
		//---------------------------------------------------------------------------------------------------------------------
		//---------------------------------------------------------------------------------------------------------------------
		
		/*CHECKING AND GETTING*/
		int checkCredentials(string user, string pass){
			if(user==username && pass==password){
				return 1;
			}
			else{
				return 0;
			}
		}
		int checkCredentials(string user){
			if(user==username){
				return 1;
			}
			else{
				return 0;
			}
		}
		int checkPokemon(string pokemonName){
			int captured=0;
			
			for(int i=0;i<pokemons;i++){
				if(pokemonName==pokemon[i]){
					captured=1;
					break;
				}
			}
			
			return captured;
		}
		//---------------------------------------------------------------------------------------------------------------------
		//---------------------------------------------------------------------------------------------------------------------
		
		/*DATABASE AND CREDENTIALS STUFF*/
		int update(int line){
			username = masDB.getData(++line);
			password = masDB.getData(++line);
			id = masDB.getData(++line);
			firstName = masDB.getData(++line);
			lastName = masDB.getData(++line);
			bday = masDB.getData(++line);
			sex = masDB.getData(++line);
			address = masDB.getData(++line);
			contact = masDB.getData(++line);
			pokemons = masDB.getDataNum(++line);
			for(int i=0;i<pokemons;i++){
				pokemon[i]=masDB.getData(++line);
			}
			return line;
		}
		void write(){
			masDB.write(username);
			masDB.write(password);
			masDB.write(id);
			masDB.write(firstName);
			masDB.write(lastName);
			masDB.write(bday);
			masDB.write(sex);
			masDB.write(address);
			masDB.write(contact);
			masDB.write(pokemons);
			for(int i=0;i<pokemons;i++){
				masDB.write(pokemon[i]);
			}
		}
};

#endif
