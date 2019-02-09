#ifndef POKEDEX_H
#define POKEDEX_H

#include "header.hpp"

class Pokedex{
	public:
		void login(){
			int i, admin=0, normal=0, task1=0, task2=0;
			string user, pass;
			
			cout<<"username: ";
			user = trap.noBlank();
			user = to_lower(user);
			cout<<"password: ";
			pass = trap.noBlank();
			
			for(i=0;i<masters;i++){
				if(pokemonMaster[i].checkCredentials(user, pass)){
					admin=1;
					break;
				}
			}
			
			/*CHECK IF USER IS MASTER OR TRAINER*/
			if(admin==1){
				system("cls");
				task1 = pokemonMaster[i].menu(masters,trainers,pokemons);
			}
			else{
				for(i=0;i<trainers;i++){
					if(pokemonTrainer[i].checkCredentials(user, pass)){
						normal=1;
						break;
					}
				}
				if(normal==1){
					system("cls");
					task2 = pokemonTrainer[i].menu();
				}
				else{
					cout<<"invalid credentials press any key to return";
					getch();
					return;
				}
			}
			
			/*DO WHAT THE TRAINER OR MASTER WANTS TO DO*/
			if(task1>0){
				tasks1(task1, i);
			}
			else if(task2>0){
				tasks2(task2, i);
			}
		}
		void update(){
			int line=0, id=0, idBig=0;
			
			/*UPDATE STATIC DATA*/
			masters = masDB.count_no_masters();
			trainers = traDB.count_no_trainers();
			pokemons = pokDB.count_no_pokemon();
			
			/*UPDATE MASTERS*/
			for(int i=0;i<masters;i++){
				line = pokemonMaster[i].update(line);
			} line=0;
			
			/*UPDATE TRAINERS*/
			for(int i=0;i<trainers;i++){
				line = pokemonTrainer[i].update(line);
			}line=0;
			
			/*UPDATE POKEMON*/
			for(int i=0;i<pokemons;i++){
				line = pokemon[i].update(line);
			}
			
			/*GET LATEST ID NUMBER*/			
			latest_id = idDB.getID();
		}
	//---------------------------------------------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------------------------------------------
	
	private:
		int accounts, masters, trainers, latest_id, pokemons;
		
		PokemonMaster pokemonMaster[16];
		PokemonTrainer pokemonTrainer[16];
		Pokemon pokemon[152];
		
		/*TASKS FOR POKEDEX TASKS FOR POKEDEX TASKS FOR POKEDEX TASKS FOR POKEDEX TASKS FOR POKEDEX TASKS FOR POKEDEX TASKS FOR POKEDEX */
		//TASKS FOR MASTERS
		void tasks1(int task, int account){					
			do{
				if(task==1){
					cout<<"create master";
					createMaster();
				}
				else if(task==2){
					cout<<"create trainer"<<endl;
					createTrainer();
				}
				else if(task==3){
					cout<<"delete user"<<endl;
					deleteUser(account, task);
				}
				else if(task==5){
					displayAll();
				}
				else if(task==6){
					cout<<"catch a pokemon"<<endl;
					catchPokemon(account, 1);
				}
				else if(task==7){
					cout<<"create a pokemon"<<endl;
					createPokemon();					
				}
				else if(task==8){
					cout<<"delete a pokemon"<<endl;
					deletePokemon();					
				}
				else if(task==9){
					displayAll_pokemon(account,1);
				}
				
				getch();
				system("cls");
				if(task>0){task = pokemonMaster[account].menu(masters,trainers,pokemons);}		
			}while(task>0);
		}
		//TASKS FOR TRAINERS
		void tasks2(int task, int account){					
			do{
				if(task==2){
					cout<<"catch a pokemon"<<endl;
					catchPokemon(account, 0);
				}
				else if(task==3){
					displayAll_pokemon(account,0);
				}
				
				getch();
				system("cls");
				if(task>0){task = pokemonTrainer[account].menu();}
			}while(task>0);
		}
		/*END OF TASKS END OF TASKS END OF TASKS END OF TASKS END OF TASKS END OF TASKS END OF TASKS END OF TASKS*/
		
		/*FUNCTIONS FOR TASK FUNCTIONS FOR TASK FUNCTIONS FOR TASK FUNCTIONS FOR TASK FUNCTIONS FOR TASK FUNCTIONS FOR TASK */
		//---------------------------------------------------------------------------------------------------------------------
		/*CREATE*/
		void createMaster(){
			string username, id_for_user;
			id_for_user = to_string(++latest_id);
			
			cout<<"id: "<<id_for_user<<endl;
			
			username = getUser();
			pokemonMaster[masters++].create(username, id_for_user);
			
			writeMasters();
			writeID();
		}
		void createTrainer(){	
			string username, id_for_user;
			id_for_user = to_string(++latest_id);
			
			cout<<"id: "<<id_for_user<<endl;
			
			username = getUser();
			pokemonTrainer[trainers++].create(username, id_for_user);
			
			writeTrainers();
			writeID();
		}
		void createPokemon(){	
			int available;
			string poke_number;
			string pokemonName;
			
			cout<<"id: "<<pokemons+1<<endl;
			do{
				available=0;
				cout<<"name: ";
				pokemonName = trap.getInput();
				
				for(int i=0;i<pokemons;i++){
					if(pokemon[i].checkCredentials(pokemonName)){
						available=1;
						cout<<"name already taken!"<<endl;
						break;
					}
				}
			}while(available==1);
			
			poke_number = to_string(pokemons+1);
			pokemon[pokemons].create(pokemonName, poke_number);
			pokemons++;
			writePokemons();
		}
		//---------------------------------------------------------------------------------------------------------------------
		
		/*CATCH*/
		void catchPokemon(int account, int admin){
			string pokemonName;
			
			pokemonName = getPokemon(account, admin);
			if(admin){
				pokemonMaster[account].catchPoke(pokemonName);
				writeMasters();
			}
			else{
				pokemonTrainer[account].catchPoke(pokemonName);
				writeTrainers();
			}
			
			cout<<"pokemon caught! press any key to continue";
		}
		//---------------------------------------------------------------------------------------------------------------------
		
		/*DISPLAY*/
		void displayAll(){
			setcolor(5);
			cout<<"------------------------POKEMON MASTERS------------------------"<<endl;
			setcolor(7);
			
			for(int i=0;i<masters;i++){
				pokemonMaster[i].print();
				cout<<endl;
			}
			
			setcolor(5);
			cout<<"------------------------POKEMON TRAINERS------------------------"<<endl;
			setcolor(7);
			
			for(int i=0;i<trainers;i++){
				pokemonTrainer[i].print();
				cout<<endl;
			}
		}
		void displayAll_pokemon(int account, int admin){
			string pokeName_tocheck;
			int captured;
			
			cout<<"------------------------POKEMEN------------------------"<<endl;
			
			if(admin){
				for(int i=0;i<pokemons;i++){
					pokeName_tocheck = pokemon[i].checkCredentials();
					captured = pokemonMaster[account].checkPokemon(pokeName_tocheck);
					pokemon[i].print(captured);
					cout<<endl;
				}
			}
			else{
				for(int i=0;i<pokemons;i++){
					pokeName_tocheck = pokemon[i].checkCredentials();
					captured = pokemonTrainer[account].checkPokemon(pokeName_tocheck);
					pokemon[i].print(captured);
					cout<<endl;
				}
			}
			
			cout<<"press any key to go back..";
		}
		//---------------------------------------------------------------------------------------------------------------------
		
		/*DELETE*/
		int deleteUser(int account, int task){
			int i, if_available=0, is_admin=0;
			string username;

			cout<<"username: ";
			username = trap.noBlank();
			username = to_lower(username);
			
			for(i=0;i<masters;i++){
				if(pokemonMaster[i].checkCredentials(username)){
					if_available=1;
					is_admin=1;
					break;
				}
			}
			if(if_available==0){
				for(i=0;i<trainers;i++){
					if(pokemonTrainer[i].checkCredentials(username)){
						if_available=1;
						break;
					}
				}
			}
				
			/*DELETING THE USER*/
			if(if_available==1){
				/*ERROR TRAP SO THAT NUMBER DOES NOT GET TO NEGATIVE*/
				if(is_admin==1 && masters==1){
					cout<<"must have atleast one admin!"<<endl;
				}
				else{						
					if(i==account){											 //RETURN TO MENU IF SELF DELETE
						task=0;
					}
					
					if(is_admin==1){
						for(i;i<masters;i++){
							pokemonMaster[i] = pokemonMaster[i+1];
						}
						masters--;
						writeMasters();
					}
					else{
						for(i;i<trainers;i++){
							pokemonTrainer[i] = pokemonTrainer[i+1];
						}
						trainers--;
						writeTrainers();
					}
					
					cout<<username<<" deleted! press any key to return";
				}
			}
			else{
				cout<<"username not found! press any key to return";
			}
			
			return task;
		}
		void deletePokemon(){
			int i, if_available=0;
			string pName;

			cout<<"name: ";
			pName = trap.noBlank();
			pName = to_lower(pName);
			
			for(i=0;i<pokemons;i++){
				if(pokemon[i].checkCredentials(pName)){
					if_available=1;
					break;
				}
			}
				
			/*DELETING THE USER*/
			if(if_available==1){						
				for(i;i<pokemons;i++){
					pokemon[i] = pokemon[i+1];
					pokemon[i].updateNumber(i+1);
				}
				pokemons--;
				writePokemons();
				
				cout<<pName<<" deleted! press any key to return";
			}
			else{
				cout<<"pokemon not found! press any key to return";
			}
		}
		//---------------------------------------------------------------------------------------------------------------------
		//---------------------------------------------------------------------------------------------------------------------
		
		/*TECHNICAL STUFF TECHNICAL STUFF TECHNICAL STUFF TECHNICAL STUFF TECHNICAL STUFF TECHNICAL STUFF TECHNICAL STUFF TECHNICAL STUFF */
		string getUser(){
			string username;
			int repeat=0;
			
			do{
				repeat=0;
				cout<<"username: ";
				username = trap.noBlank();
				username = to_lower(username);
				
				for(int i=0;i<masters;i++){
					if(pokemonMaster[i].checkCredentials(username)){
						repeat=1;
						break;
					}
				}
				if(repeat==0){
					for(int i=0;i<trainers;i++){
						if(pokemonTrainer[i].checkCredentials(username)){
							repeat=1;
							break;
						}
					}
				}
				if(repeat==1){
					cout<<"username already taken!"<<endl;
				}
			}while(repeat>0);
			
			return username;
		}
		string getPokemon(int account, int admin){
			string pokemonName;
			int available;
			
			do{
				available=0;
				cout<<"pokemon name: ";
				pokemonName = trap.noBlank();
				
				pokemonName = to_lower(pokemonName);
				
				for(int i=0;i<pokemons;i++){
					if(pokemon[i].checkCredentials(pokemonName)){
						available=1;
						break;
					}
				}
				
				if(available==1){
					if(admin){
						if(pokemonMaster[account].checkPokemon(pokemonName)){
							available=2;
						}
					}
					else{
						if(pokemonTrainer[account].checkPokemon(pokemonName)){
							available=2;
						}
					}
				}
				
				if(available==0){
					cout<<"pokemon name not found!"<<endl;
				}
				else if(available==2){
					cout<<"pokemon already caught!"<<endl;
				}
			}while(available==0 || available==2);
			
			return pokemonName;
		}
		//---------------------------------------------------------------------------------------------------------------------
		//---------------------------------------------------------------------------------------------------------------------
		
		/*DB WRITING STUFF*/
		writeTrainers(){
			traDB.clear();
			for(int i=0;i<trainers;i++){
				pokemonTrainer[i].write();
			}
			traDB.write(trainers);
		}
		writeMasters(){
			masDB.clear();
			for(int i=0;i<masters;i++){
				pokemonMaster[i].write();
			}
			masDB.write(masters);
		}
		writePokemons(){
			pokDB.clear();
			for(int i=0;i<pokemons;i++){
				pokemon[i].write();
			}
		}
		writeID(){
			idDB.clear();
			idDB.write(latest_id);
		}
		//---------------------------------------------------------------------------------------------------------------------
		//---------------------------------------------------------------------------------------------------------------------
};

#endif
