#include "header.hpp"

int main(int argc, char** argv) {
	Pokedex pokedex;
	int choice=1;
	
	pokedex.update();

	for(;;){	
		if(choice==1){cout<<"[X] Login\n";}else{cout<<"[ ] Login\n";}
		if(choice==2){cout<<"[X] Exit\n";}else{cout<<"[ ] Exit\n";}
		
		choice = trap.arrow2(choice);
		
		if(choice>10){ choice-=10;
			system("cls");
			
			if(choice==1){
				pokedex.login();
			}
			else if(choice==2){
				return 0;
			}
		}
		system("cls");
	}
}
