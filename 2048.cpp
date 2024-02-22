#include <iostream>
#include <ctime>
#include <random>
#include <conio.h>
#include <iomanip>
#include <string>


using namespace std;
int cnt = 0;
int SCORE = 0;

struct datas{
    int score;
    string name;
};
datas data[50];

void leaderboard(){
    
    for(int i = 1; i <= cnt ; i++){
        for (int j = 1; j <= cnt - i; j++) {
            if (data[j].score > data[j + 1].score) {
                swap(data[j] , data[j+1]);

            }
        }  
    }
    
    int num = 1;
    for(int i = cnt ; i > 0 ; i--){
        cout << num << "." << data[i].name << " : " << data[i].score << endl;
        num++;
    }

}







bool GameOver = false;
int table_2048[4][4];
int counter = 0;


void Random() {
    int array[] = {2, 2, 2, 4};
    int a = rand() % 4;

    int emptyindexes = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (table_2048[i][j] == 0) {
                emptyindexes++;
            }
        }
    }

    if (emptyindexes == 0) {
        return;
    }

    int randIndex = rand() % emptyindexes + 1;
    int amount = array[a];

    int count= 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (table_2048[i][j] == 0) {
                count++;
                if (count == randIndex) {
                    table_2048[i][j] = amount;
                    return;
                }
            }
        }
    }
}





void printtable_2048(){
	
            for(int i = 0 ; i < 4 ; i++){
                for(int j = 0 ; j < 4 ; j++){
                    table_2048[i][j] = 0;
                }
            }

            int array[] = {2 , 2 , 2 , 4};//to find the rand num from 2 or 4 for the base amount of the game
            //because we said that the possibility of geing 2 is tree times more than 4
            
            
            int a = rand() % 4;  // why exactly we use from % because if the arraysize be 4 it will get % the remains of 4 can be 0 or 1 or 2 or 3 and in this case it will find a random num from 0 to 3
            int b = rand() % 4;

            while(a == b){
                b = rand() % 4;
            }
            
           
            
                
            int array_i[] = {0 , 1 , 2 , 3}; // to find the random index of the array
            
            int randi = array_i[rand() % 4];
            int array_j[] = {0 , 1 , 2 , 3};
            int randj = array_j[rand() % 4];
            
            int array2_i[] = {0 , 1 , 2 , 3};
            
            int rand2i = array2_i[rand() % 4];
            int array2_j[] = {0 , 1 , 2 , 3};
            int rand2j = array2_j[rand() % 4];
            while(table_2048[randi][randj] == table_2048[rand2i][rand2j]){ // we chack they shouldnt same because we need two random indexes
             
                rand2i = array2_i[rand() % 4];
                rand2j = array2_j[rand() % 4];
                counter++;
                if(counter > 1000){
                    break;
                }
            }
            table_2048[randi][randj] = array[a];
            table_2048[rand2i][rand2j] = array[b];



for(int i = 0 ; i < 4 ; i++){
    for(int j = 0 ; j < 4 ; j++){   
        if(table_2048[i][j] == 0){
            cout << "[" << setw(4) << " " << "]";
        }
        else{
            cout << "[" << setw(4) << table_2048[i][j] << "]" ;
        }
        
    }

    cout << endl;
}
}

void showthegame(){
    system("cls");
    
for(int i = 0 ; i < 4 ; i++){
    for(int j = 0 ; j < 4 ; j++){   
        if(table_2048[i][j] == 0){
            cout << "[" << setw(4)<< " " << "]";
        }
        else
        {
            cout << "[" << setw(4)<< table_2048[i][j] << "]";
        }
        if(table_2048[i][j]==2048){
            cout << "Winner!!" ;
            exit(0);
        }
  
    }

    cout << endl;
}

cout << endl;

}


void Move(char move){

   
    if(move == 'W' || move == 'w'){

    for(int j = 0 ; j < 4 ; j++){ //we started the row from 1 because the first row doesnt need to move
        for(int i = 1 ; i < 4 ; i++){
            if(table_2048[i][j] != 0){
                int k = i;
                while(k > 0 && (table_2048[k-1][j] == 0 || table_2048[k-1][j] == table_2048[k][j])){
                    if(table_2048[k-1][j] == 0){
                        table_2048[k-1][j]=table_2048[k][j];
                        table_2048[k][j] = 0;
                        k--;
                    }
                    else if(table_2048[k-1][j] == table_2048[k][j]){
                        table_2048[k-1][j]*=2;
                        
                        SCORE+=table_2048[k-1][j];
                        

                        table_2048[k][j] = 0;
                        break;
                    }
                }
            }

        }
        
    }
       Random(); 
    }
    else if(move == 'A' || move == 'a'){

        for(int i = 0 ; i < 4 ; i++){
            for(int j = 1 ; j < 4 ; j++){
                if(table_2048[i][j] != 0){
                    int k = j;
                    while(k > 0 && (table_2048[i][k-1] == 0 || table_2048[i][k-1] == table_2048[i][k])){
                        if(table_2048[i][k-1] == 0){
                            table_2048[i][k-1] = table_2048[i][k];
                            table_2048[i][k] = 0;
                            k--;   
                        }
                        else if(table_2048[i][k-1] == table_2048[i][k]){
                            table_2048[i][k-1]*=2;
                        
                        SCORE+=table_2048[k-1][j];
                        
                            table_2048[i][k]=0;
                            break;
                        }
                    }
                }
            }
        }
        Random();
        
    }
    else if(move == 'S' || move == 's'){

    for(int j = 0 ; j < 4 ; j++){
    for(int i = 2 ; i >=0 ; i--){
        if(table_2048[i][j] != 0){
            int k = i;
            while(k < 3 && (table_2048[k+1][j] == 0 || table_2048[k+1][j] == table_2048[k][j])){
                if(table_2048[k+1][j] == 0){
                   table_2048[k+1][j] = table_2048[k][j];
                   table_2048[k][j] = 0;
                    k++;
                }
                else if(table_2048[k+1][j] == table_2048[k][j]){
                    table_2048[k+1][j]*=2;
                        
                        SCORE+=table_2048[k-1][j];
                        

                    table_2048[k][j] = 0;
                    break;
                }
            }
        }
    }
    
}
    Random();   
    }
    else if(move == 'D' || move == 'd'){

        for(int i = 0 ; i < 4 ; i++){
            for(int j = 2 ; j >= 0 ; j--){
                if(table_2048[i][j] != 0){
                    int k = j;
                    while(k < 3 && (table_2048[i][k+1] == 0 || table_2048[i][k+1]==table_2048[i][k])){
                        if(table_2048[i][k+1] == 0 ){
                            table_2048[i][k+1]=table_2048[i][k];
                            table_2048[i][k]=0;
                            k++;
                        }
                        else if(table_2048[i][k+1]==table_2048[i][k]){
                        table_2048[i][k+1]*=2;
                        SCORE+=table_2048[k-1][j];
                        

                            table_2048[i][k] = 0;
                            break;

                        }
                    }
                }
            }
        }
        Random();
        
    }
    else if(move == 'Q' || move == 'q'){
        exit(0);
    }

}

bool isGameOver() {
   
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (table_2048[i][j] == 0) {
                return false;  
            }
        }
    }

  
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            
            if (j < 3 && table_2048[i][j] == table_2048[i][j + 1]) {
                return false;  
            }

            
            if (i < 3 && table_2048[i][j] == table_2048[i + 1][j]) {
                return false;  
            }
        }
    }

    return true;  
}
void NewGame(){


    
    printtable_2048();
    char move;
    
    while(!GameOver){
        char move = getch();
        Move(move);
        showthegame();

            cout << SCORE << endl;
            
        
            if (isGameOver()) {
            cout << "Game Over!" << endl;
            GameOver = true;
        }
         else if (move == 'Q' || move == 'q') {
            cout << "Game Exited!" << endl;
            GameOver = true;
        }
        
    }
}








int main(){
    while(true){
    srand(time(nullptr));
    char choice;
    string name;
    GameOver = false;

    cout << "Choose one of this options :" << endl;
    cout << "a.New Game (if you want to start a new game)" << "\n" << "b.LeaderBoard (if you want to see the result)" << "\n" << "c.Exit (if you want to leave the game)" <<"\n";
    choice = getch();

    
    if(choice == 'a'){
        cout << "what is your name : " << endl;
        getline(cin , name);
        SCORE = 0;
        NewGame();
        cnt++;
        data[cnt].name = name;
        data[cnt].score = SCORE;
        


        
        
        
    }
    else if(choice=='b'){
        leaderboard();
    }
    else if(choice=='c'){
        return 0;
    } 
    else{
        cout << "invalid" << endl;

    }
    }
    
}