#ifndef POKEMONTRAINER_H
#define POKEMONTRAINER_H

#include "header.hpp"

class PokemonTrainer: private PokemonMaster{	
	public:
		int menu(){
			int choice=1;
			
			for(;;){
				if(choice==1){cout<<"[X] display profile\n";}else{cout<<"[ ] display profile\n";}
				if(choice==2){cout<<"[X] catch pokemon\n";}else{cout<<"[ ] catch pokemon\n";}
				if(choice==3){cout<<"[X] display pokemon\n";}else{cout<<"[ ] display pokemon\n";}
				if(choice==4){cout<<"[X] logout\n";}else{cout<<"[ ] logout\n";}
				
				choice = trap.arrow4(choice);
				
				if(choice>10){ choice-=10;
					system("cls");
					
					if(choice==1){
						print();
						getch();
					}
					else if(choice==2){
						return 2;
					}
					else if(choice==3){
						return 3;
					}
					else if(choice==4){
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
			//cout<<"password: "<<password<<endl;
			cout<<"id: "<<id<<endl;
			cout<<"first name: "<<to_upper(firstName)<<endl;
			cout<<"last name: "<<to_upper(lastName)<<endl;
			cout<<"bday: "<<to_upper(bday)<<endl;
			cout<<"sex: "<<to_upper(sex)<<endl;
			cout<<"address: "<<to_upper(address)<<endl;
			cout<<"contact: "<<contact<<endl;
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
			username = traDB.getData(++line);
			password = traDB.getData(++line);
			id = traDB.getData(++line);
			firstName = traDB.getData(++line);
			lastName = traDB.getData(++line);
			bday = traDB.getData(++line);
			sex = traDB.getData(++line);
			address = traDB.getData(++line);
			contact = traDB.getData(++line);
			pokemons = traDB.getDataNum(++line);
			for(int i=0;i<pokemons;i++){
				pokemon[i]=traDB.getData(++line);
			}
			return line;
		}
		void write(){
			traDB.write(username);
			traDB.write(password);
			traDB.write(id);
			traDB.write(firstName);
			traDB.write(lastName);
			traDB.write(bday);
			traDB.write(sex);
			traDB.write(address);
			traDB.write(contact);
			traDB.write(pokemons);
			for(int i=0;i<pokemons;i++){
				traDB.write(pokemon[i]);
			}
		}
};

#endif
