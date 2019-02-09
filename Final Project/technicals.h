#ifndef TECHINICALS_H
#define TECHNICALS_H

#include "header.hpp"

class errorTrap{
	public:
		int arrow2(int choice){																//arrow menu thingy
			char ch = getch();
		
			if(tolower(ch)=='w' || ch==72){
				if(choice>1){choice--;}else if(choice==1){choice = 2;}
			}
			else if(tolower(ch)=='s' || ch==80){
				if(choice<2){choice++;}else if(choice==2){choice = 1;}
			}
			else if(ch==13 || ch==32){
				choice = choice + 10;			
			}
			return choice;
		}
		int arrow4(int choice){																//arrow menu thingy
			char ch = getch();
		
			if(tolower(ch)=='w' || ch==72){
				if(choice>1){choice--;}else if(choice==1){choice = 4;}
			}
			else if(tolower(ch)=='s' || ch==80){
				if(choice<4){choice++;}else if(choice==4){choice = 1;}
			}
			else if(ch==13 || ch==32){
				choice = choice + 10;			
			}
			return choice;
		}
		int arrow10(int choice){															//arrow menu thingy
			char ch = getch();
		
			if(tolower(ch)=='w' || ch==72){
				if(choice>1){choice--;}else if(choice==1){choice = 10;}
			}
			else if(tolower(ch)=='s' || ch==80){
				if(choice<10){choice++;}else if(choice==10){choice = 1;}
			}
			else if(ch==13 || ch==32){
				choice = choice + 10;			
			}
			return choice;
		}
		int getInput(int min, int max){														//get number min and max
			int x;
			cin>>x;
			while(cin.fail() || x<min || x>max) {
		        cin.clear();
		        cin.ignore(256,'\n');
		        cout << "Enter again: ";
		        cin >> x;
		    }
		    return x;
		}
		string getInput(){																	//input string
			fflush(stdin);
			string x;
			int i=0;		
			do{
				getline(cin,x);
				for(i=0;i<x.length();i++){
					if((x[i]!=32 && x[i]<65) || (x[i]>90 && x[i]<97) || x[i]>122 || x[0]==' '){
						i=0;
						break;
					}
				}
				if(i==0){
					cout<<"Enter again: ";
				}
			}while(x[i]!='\0' || i==0);
			
			return x;
		}
		string noBlank(){																	//input but no blanks allowed
			fflush(stdin);	
			string x;
			do{
				getline(cin,x);
				if(x.length()==0 || x[0]==' '){
					cout<<"Enter again: ";
				}
			}while(x.length()==0 || x[0]==' ');
			
			return x;
		}
		string getNumber(){																	//input string number only
			fflush(stdin);
			string x;
			int i=0;		
			do{
				getline(cin,x);
				for(i=0;i<x.length();i++){
					if(x[i]<48 || x[i]>57){
						i=0;
						break;
					}
				}
				if(i==0){
					cout<<"Enter again: ";
				}
			}while(x[i]!='\0' || i==0);
			
			return x;
		}
};

string to_string(int i){
    stringstream ss;
    ss << i;
    return ss.str();
}

string to_lower(string data){
	locale loc;
	for (int i=0; i<data.length(); i++){
		data[i] = tolower(data[i],loc);
	}
	return data;
}

string to_upper(string data){
	locale loc;
	data[0] = toupper(data[0],loc);
	return data;
}

void setcolor(int ForgC){
     WORD wColor;

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
}


#endif
