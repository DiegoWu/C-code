#include<bits/stdc++.h> 

using namespace std; 

int sz, st; 
vector<string> used; 
string des[4]= {"UP", "DOWN", "LEFT", "RIGHT"}; 
int dirx[4]= {0, 0, -1, 1},  diry[4]= {-1, 1, 0, 0};

vector<string> createBoard(int boardType){ // returns an array, initialized according to a specific board type
	if(boardType==1){
		vector<string> arr(10); 
		sz= 8;
			arr[0]= "123456789"; 
			arr[1]= "1###@@@###"; 
			arr[2]= "2###@@@###"; 
			arr[3]= "3@@@@@@@@@"; 
			arr[4]= "4@@@@-@@@@";
			arr[5]= "5@@@@@@@@@"; 
			arr[6]= "6###@@@###"; 
			arr[7]= "7###@@@###"; 		 
		return arr; 
	}
	else if(boardType== 2){
		vector<string> arr(7); 
		sz= 7; 
		arr[0]= "123456"; 
		arr[1]= "1#-@@-#"; 
		arr[2]= "2-@@@@-"; 
		arr[3]= "3@@@@@@";
		arr[4]= "4@@@@@@";
		arr[5]= "5-@@@@-"; 
		arr[6]= "6#-@@-#"; 
		return arr; 
	} 
	else if(boardType== 3){
		sz= 5; 
		vector<string> arr(5); 
		arr[0]= "123456789"; 
		arr[1]= "1###-@-###"; 
		arr[2]= "2##-@@@-##"; 
		arr[3]= "3#-@@-@@-#"; 
		arr[4]= "4-@@@@@@@-"; 
		return arr; 
	}
	else{
		sz= 6; 
		vector<string> arr(6);
		arr[0]= "12345"; 
		arr[1]= "1-----"; 
		arr[2]= "2-@@@-"; 
		arr[3]= "3--@--"; 
		arr[4]= "4--@--"; 
		arr[5]= "5-----"; 
		return arr; 
	}
};

int readValidInt(string prompt, int mn, int mx){ // returns a valid integer from the user
	string a; 
	int b; 
	while(true){
		getline(cin, a);  
		b= a[0]-'0';  
		if(a.size()>1|| b< mn|| b> mx) cout<<prompt<<mn<< " and "<<mx<< ":"<<endl;
		else break; 
	}
	return b; 
}; 
 
void displayBoard(vector<string> a){ // prints out the contents of a board to for the player to see
	for(int i=0; i<sz; i++) cout<<a[i]<<endl; 
}; 

bool isValidMove(vector<string> board, int row, int col, int dir){ // checks move validity
	//cout<<row+ diry[dir-1]*2<<" "<<col+ dirx[dir-1]*2<<endl;
	if(board[row][col]!= '@') return 0;  
	else if(row+ diry[dir-1]*2< 0 || row+ diry[dir-1]*2> board[0].size()|| col+ dirx[dir-1]*2< 0 || col+ dirx[dir-1]*2> board[0].size()) return 0;  
	else if (board[row+diry[dir-1]][col+dirx[dir-1]]!= '@'|| board[row+ diry[dir-1]*2][col+dirx[dir-1]*2]!= '-') return 0; 
	else return 1; 
}; 
vector<string> performMove(vector<string> board, int rw, int col, int dir){ // applies move to a board
	board[rw+ diry[dir-1]*2][col+ dirx[dir-1]*2]= '@'; 
	board[rw][col]= '-'; 
	board[rw+ diry[dir-1]][col+ dirx[dir-1]]= '-'; 
	return board; 
}; 

void  readValidMove(vector<string> board){// reads a single peg jump move in from the user
	int col, rw, dir; 

	while(true){
		cout<<"Choose the COLUMN of a peg you'd like to move: "<<endl;
		col= readValidInt("Please enter your choice as an integer between ", 1, board[0].size());
		cout<<"Choose the ROW of a peg you'd like to move:"<<endl;
		rw= readValidInt("Please enter your choice as an integer between ", 1, sz-1);
		cout<<"Choose a DIRECTION to move that peg 1) UP, 2) DOWN, 3) LEFT, or 4) RIGHT:"<<endl; 
		dir= readValidInt("Please enter your choice as an integer between ", 1, 4); 
		if(!isValidMove(used, rw, col, dir)) cout<<"Moving a peg from row "<<rw<<" and column "<<col<<" "<< des[dir-1] <<" is not currently a legal move."<<endl;
		else break; 
		
	}
	used= performMove(board, rw, col, dir); 
}; 

int countPegsRemaining(vector<string> board){ // returns the number of pegs left on a board
	int cnt= 0; 
	for(int i=0; i<sz; i++)
		for(auto x: board[i]) if(x== '@') cnt++; 

	return cnt; 
}; 

int countMovesAvailable(vector<string> board){ // returns the number of possible moves available on a board
	int cnt= 0; 
	for(int i=0; i<sz; i++){
		for(int j=0; j<board[i].size(); j++){
			if(board[i][j]=='@'){
				for(int k=0; k<4; k++){ 
					if(i+ diry[k]*2< 0 || i+ diry[k]*2> board[0].size()|| j+ dirx[k]*2< 0 || j+ dirx[k]*2> board[0].size()) continue;  
					else if (board[i+diry[k]][j+dirx[k]]!= '@'|| board[i+ diry[k]*2][j+dirx[k]*2]!= '-') continue; 
					else cnt++; 
				}
			}
		}
	}
	return cnt; 
}; 

int main(){ // drives the entire game application
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL);
	 
	cout<<"WELCOME TO CS300 PEG SOLITAIRE!"<<endl;
	cout<<"==============================="<<endl;
	cout<<endl;
	cout<<"Board Style Menu"<<endl;
	cout<<"1) Cross"<<endl;
	cout<<"2) Circle"<<endl;
	cout<<"3) Triangle"<<endl;
	cout<<"4) Simple T"<<endl;
	cout<<"Choose a board style: "; 
	cout<<endl;
	st= readValidInt("Please enter your choice as an integer between ", 1, 4); 
	used= createBoard(st); 
	displayBoard(used);
	while(true){
		readValidMove(used); 
		displayBoard(used);
		if(!countMovesAvailable(used)){
			if(countPegsRemaining(used)) cout<<"Congrats, you won!"<<endl;
			else cout<<"It looks like there are no more legal moves.  Please try again."<<endl;
			break; 
		} 
	}
	cout<<endl;
	cout<<"=========================================="<<endl;
	cout<<"THANK YOU FOR PLAYING CS300 PEG SOLITAIRE!"<<endl;
			
	return 0; 
}