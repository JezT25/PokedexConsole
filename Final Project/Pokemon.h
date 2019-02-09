#ifndef POKEMON_H
#define POKEMON_H

#include "header.hpp"

class Pokemon{
	private:
		string name, prevEvo, nextEvo, type1, type2, desc, id;
		
		string getType(int type_pors){
			int error; string type;
			
			if(type_pors==1){
				do{
					cout<<"type 1 (cannot be none): ";
					type = trap.getInput();
					type = to_lower(type);
					if(type=="bug" || type=="dark" || type=="dragon" || type=="electric" || type=="fairy" || type=="fighting" || type=="fire" || type=="flying" || type=="ghost" || type=="grass" || type=="ground" || type=="ice" || type=="normal" || type=="poison" || type=="psychic" || type=="rock" || type=="steel" || type=="water"){
						error=0;	
					}
					else if(type=="none"){
						error=1;
						cout<<"invalid type enter again!"<<endl;
					}
					else{
						error=1;
						cout<<"invalid type enter again!"<<endl;
					}
				}while(error==1);
			}
			else{
				do{
					error=0;
					cout<<"type 2 (write none if no secondary type): ";
					type = trap.getInput();
					type = to_lower(type);
					if(type=="none" || type=="bug" || type=="dark" || type=="dragon" || type=="electric" || type=="fairy" || type=="fighting" || type=="fire" || type=="flying" || type=="ghost" || type=="grass" || type=="ground" || type=="ice" || type=="normal" || type=="poison" || type=="psychic" || type=="rock" || type=="steel" || type=="water"){
						error=0;	
					}
					else{
						error=1;
						cout<<"invalid type enter again!"<<endl;
					}
					if(type==type1){
						error=1;
						cout<<"cannot have same type as previous enter again!"<<endl;
					}
				}while(error==1);
			}
			
			return type;
		}
		
	public:
		/*FUNCTIONS*/
		void print(int captured){
			if(captured==1){
				setcolor(10);
				cout<<"--POKEMON CAPTURED--"<<endl;	
				setcolor(7);
			}
			cout<<"id: "<<to_upper(id)<<'\t';
			cout<<"name: "<<to_upper(name)<<endl;
			cout<<"previous evolution: "<<to_upper(prevEvo)<<'\t';
			cout<<"next evolution: "<<to_upper(nextEvo)<<endl;
			cout<<"type 1: "<<to_upper(type1)<<'\t';
			cout<<"type 2: "<<to_upper(type2)<<endl;
			cout<<"desc: "<<to_upper(desc)<<endl;
		}
		void create(string pName, string pokemonid){
			id = pokemonid;
			name = pName;
			cout<<"previous evolution: ";
			prevEvo = trap.getInput();
			cout<<"next evolution: ";
			nextEvo = trap.getInput();
			type1 = getType(1);
			type2 = getType(2); 
			cout<<"desc: ";
			desc = trap.noBlank();
			
			cout<<"press any to continue";
		}
		void updateNumber(int pokemon_no){
			string number;
			
			number = to_string(pokemon_no);
			id = number;
		}
		//---------------------------------------------------------------------------------------------------------------------
		//---------------------------------------------------------------------------------------------------------------------
		
		/*CHECKING AND GETTING*/
		int checkCredentials(string pName){
			if(pName==name){
				return 1;
			}
			else{
				return 0;
			}
		}
		string checkCredentials(){
			return name;
		}
		//---------------------------------------------------------------------------------------------------------------------
		//---------------------------------------------------------------------------------------------------------------------
		
		/*DATABASE AND CREDENTIALS STUFF*/
		int update(int line){
			name = pokDB.getData(++line);
			prevEvo = pokDB.getData(++line);
			nextEvo = pokDB.getData(++line);
			type1 = pokDB.getData(++line);
			type2 = pokDB.getData(++line);
			desc = pokDB.getData(++line);
			id = pokDB.getData(++line);
			return line;
		}
		void write(){
			pokDB.write(name);
			pokDB.write(prevEvo);
			pokDB.write(nextEvo);
			pokDB.write(type1);
			pokDB.write(type2);
			pokDB.write(desc);
			pokDB.write(id);
		}
};

#endif
