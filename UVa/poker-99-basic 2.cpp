#include <iostream> 
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

void Display_playing_card(int status_quo, int pnum, int cnum, int number[][6], string color[][6], int t, int total_choice[]){
	for(int i=0;i<total_choice[(status_quo+i)%(pnum+cnum)];i++){
		if(number[(status_quo)%(pnum+cnum)][i]==4){
			cout<<"     V "<<(i+1)<<" : "<<color[(status_quo)%(pnum+cnum)][i]<<"4"<<endl;
		}else if(number[(status_quo)%(pnum+cnum)][i]==5){
			cout<<"     V "<<(i+1)<<" : "<<color[(status_quo)%(pnum+cnum)][i]<<"5"<<endl;
		}else if(number[(status_quo)%(pnum+cnum)][i]==13){
			cout<<"     V "<<(i+1)<<" : "<<color[(status_quo)%(pnum+cnum)][i]<<"K"<<endl;
		}else if(number[(status_quo)%(pnum+cnum)][i]==12){
			cout<<"     V "<<(i+1)<<" : "<<color[(status_quo)%(pnum+cnum)][i]<<"Q"<<endl;
		}else if(number[(status_quo)%(pnum+cnum)][i]==11){
			cout<<"     V "<<(i+1)<<" : "<<color[(status_quo)%(pnum+cnum)][i]<<"J"<<endl;
		}else if(number[(status_quo)%(pnum+cnum)][i]==10){
			cout<<"     V "<<(i+1)<<" : "<<color[(status_quo)%(pnum+cnum)][i]<<"10"<<endl;
		}else if(number[(status_quo)%(pnum+cnum)][i]==1 && color[(status_quo)%(pnum+cnum)][i]=="Spade   "){
			cout<<"     V "<<(i+1)<<" : "<<color[(status_quo)%(pnum+cnum)][i]<<"A"<<endl;
		}else if(number[(status_quo)%(pnum+cnum)][i]==1){
			if(t+1<100) cout<<"     V "<<(i+1)<<" : "<<color[(status_quo)%(pnum+cnum)][i]<<"A"<<endl;
			else cout<<"       "<<(i+1)<<" : "<<color[(status_quo)%(pnum+cnum)][i]<<"A"<<endl;
		}else{
			if(t+number[(status_quo)%(pnum+cnum)][i]<100) cout<<"     V "<<(i+1)<<" : "<<color[(status_quo)%(pnum+cnum)][i]<<number[(status_quo)%(pnum+cnum)][i]<<endl;
			else cout<<"       "<<(i+1)<<" : "<<color[(status_quo)%(pnum+cnum)][i]<<number[(status_quo)%(pnum+cnum)][i]<<endl;
		}
	}
}

void Choose_a_card_to_play(int status_quo, int pnum, int cnum, string players[], int number[][6], string color[][6], int &choice, int total_choice[7], int &played_num, string &played_color, int t){
	if(((status_quo)%(pnum+cnum))<pnum){
		if(total_choice[(status_quo)%(pnum+cnum)]==1){
			cout<<players[(status_quo)%(pnum+cnum)]<<" you only have one choice left."<<endl;
			choice=1;
		}else{
			cout<<players[(status_quo)%(pnum+cnum)]<<" your choice is (1~"<<total_choice[(status_quo)%(pnum+cnum)]<<") : ";
			cin>>choice;
			while(choice<1 && choice>total_choice[(status_quo)%(pnum+cnum)]){
				cout<<"Choose only from 1 to "<<total_choice[(status_quo)%(pnum+cnum)]<<" : ";
				cin>>choice;
			}
		}
	}else{
		choice=rand()%total_choice[(status_quo)%(pnum+cnum)]+1;
		while(true){ //�q������G�N�� (���b����) 
			if(number[(status_quo)%(pnum+cnum)][choice-1]==4){
				break;
			}else if(number[(status_quo)%(pnum+cnum)][choice-1]==5){
				break;
			}else if(number[(status_quo)%(pnum+cnum)][choice-1]==13){
				break;
			}else if(number[(status_quo)%(pnum+cnum)][choice-1]==12){
				break;
			}else if(number[(status_quo)%(pnum+cnum)][choice-1]==11){
				break;
			}else if(number[(status_quo)%(pnum+cnum)][choice-1]==10){
				break;
			}else if(number[(status_quo)%(pnum+cnum)][choice-1]==1 && color[(status_quo)%(pnum+cnum)][choice-1]=="Spade   "){
				break;
			}else{
				if(t+number[(status_quo)%(pnum+cnum)][choice-1]<100) break;
				else choice=rand()%total_choice[(status_quo)%(pnum+cnum)]+1;
			}
		}
	}	
	played_num=number[(status_quo)%(pnum+cnum)][choice-1];
	played_color=color[(status_quo)%(pnum+cnum)][choice-1];
	if(played_num==13) cout<<players[(status_quo)%(pnum+cnum)]<<" chose : "<<played_color<<"K"<<endl;
	else if(played_num==12) cout<<players[(status_quo)%(pnum+cnum)]<<" chose : "<<played_color<<"Q"<<endl;
	else if(played_num==11) cout<<players[(status_quo)%(pnum+cnum)]<<" chose : "<<played_color<<"J"<<endl;
	else if(played_num==1) cout<<players[(status_quo)%(pnum+cnum)]<<" chose : "<<played_color<<"A"<<endl;
	else cout<<players[(status_quo)%(pnum+cnum)]<<" chose : "<<played_color<<played_num<<endl;
}

void Draw_cards(int status_quo, int pnum, int cnum, int (&number)[8][6], string (&color)[8][6], int choice,int (&total_choice)[7], vector<int> &poker_num, vector<string> &poker_color){
	if(poker_num.size()<2){ //�n���̫�@�Ӧ�m�|�O0 
		for(int i=0;i<total_choice[(status_quo+i)%(pnum+cnum)]-choice;i++){ 
			number[(status_quo)%(pnum+cnum)][choice-1+i]=number[(status_quo)%(pnum+cnum)][choice-1+1+i];
			color[(status_quo)%(pnum+cnum)][choice-1+i]=color[(status_quo)%(pnum+cnum)][choice-1+1+i];
		}
		number[(status_quo)%(pnum+cnum)][total_choice[(status_quo)%(pnum+cnum)]]=0;
		color[(status_quo)%(pnum+cnum)][total_choice[(status_quo)%(pnum+cnum)]]="0";
		total_choice[(status_quo)%(pnum+cnum)]--;
	}else{
		int a=rand()%(poker_num.size()-1); //���T�w�n���n��@ ��F���|�� 
		number[(status_quo)%(pnum+cnum)][choice-1]=poker_num[a];
		color[(status_quo)%(pnum+cnum)][choice-1]=poker_color[a];
		poker_num.erase(poker_num.begin()+a);
		poker_color.erase(poker_color.begin()+a);
	}
} 

void Card_function_execution(int &status_quo, int pnum, int cnum,string players[], int played_num, string played_color, int &t, int &order, char &sign){
	if(played_num==13){
		t=99;
	}else if(played_num==12){
		if(((status_quo)%(pnum+cnum))<pnum){
			if(t+20>99) cout<<"+ or - (Caution : You can only choose - to not lose) : ";
			else if(t-20<0) cout<<"+ or - (Caution : You can only choose + to not lose) : ";
			else cout<<"+ or - : ";
			cin>>sign;
			while(sign!='-'&&sign!='+'){  //���b����A�קK���� 
				cout<<"Choose either + or - : ";
				cin>>sign;
			}
		}else{
			if(t+20>99) sign='-';
			else if(t-20<0) sign='+'; //���p�G���|�骺�ܹq���N�|�����ǤW�@�쪱�a����� 
		}
		if(sign=='+') t=t+20;
		else if(sign=='-') t=t-20;
	}else if(played_num==11){
		t=t;
	}else if(played_num==10){
		if(((status_quo)%(pnum+cnum))<pnum){
			if(t+10>99) cout<<"+ or - (Caution : You can only choose - to not lose) : ";
			else if(t-10<0) cout<<"+ or - (Caution : You can only choose + to not lose) : ";
			else cout<<"+ or - : ";
			cin>>sign;
			while(sign!='-'&&sign!='+'){  //���b����A�קK���� 
				cout<<"Choose either + or - : ";
				cin>>sign;
			}
		}else{
			if(t+10>99) sign='-';
			else if(t-10<0) sign='+'; //���p�G���|�骺�ܹq���N�|�����ǤW�@�쪱�a����� 
			cout<<"+ or - : "<<sign<<endl;
		}
		if(sign=='+') t=t+10;
		else if(sign=='-') t=t-10;
	}else if(played_num==5){
		int p;
		if(((status_quo)%(pnum+cnum))<pnum){  //�O���a���ܭn���L�� 
			cout<<"Designate the next player with arabic number (1 to "<<(pnum+cnum)<<") : "; //�i�H���w�ۤv�� 
			cin>>p;
			while(p<1 && p>(pnum+cnum)){  //���b����A�קK���� 
				cout<<"Choose only an arabic number from 1 to  "<<(pnum+cnum)<<" : ";
				cin>>p;
			}
		}else{  //�O�q�����ܭn�H����
			p=rand()%(pnum+cnum)+1;
			cout<<"The player designated to be the next player is : "<<players[p-1]<<endl;
		}
		if(order==1) status_quo=100000*(pnum+cnum)+p-1-1; //�@�ӬO��F���᭱�����Ǫ��ɭԥ[ �@�ӬO�]��status_quo�O0-5 
		else if(order==-1) status_quo=100000*(pnum+cnum)+p+1-1;
	}else if(played_num==4){
		if(order==1) order=-1;
		else if(order==-1) order=1;
	}else if(played_num==1 && played_color=="Spade   "){
		t=0;
	}else{
		t=t+played_num;
	}
}

void Losing_condition(int status_quo, int pnum, int cnum, int number[][6], string color[][6], int t, int &end, int &no_lose){
	no_lose=0; //�P�_�O�_�٦��i�X���P�A�S�����ܷ|�����鱼
	for(int i=0;i<5;i++){
		if(number[(status_quo)%(pnum+cnum)][i]==4) no_lose=1;
		else if(number[(status_quo)%(pnum+cnum)][i]==5) no_lose=1;
		else if(number[(status_quo)%(pnum+cnum)][i]==13) no_lose=1;
		else if(number[(status_quo)%(pnum+cnum)][i]==12) no_lose=1;
		else if(number[(status_quo)%(pnum+cnum)][i]==11) no_lose=1;
		else if(number[(status_quo)%(pnum+cnum)][i]==10) no_lose=1;
		else if(number[(status_quo)%(pnum+cnum)][i]==1 && color[(status_quo)%(pnum+cnum)][i]=="Spade   ") no_lose=1;
		else if(number[(status_quo)%(pnum+cnum)][i]==1 && t+1<100) no_lose=1;
		else if(t+number[(status_quo)%(pnum+cnum)][i]<100) no_lose=1;
	}
	
	if(t>99){
		end=1;
	}else if(t<0){
		end=1;
	}else if(no_lose=0){
		end=1;
	}else{
		end=0;
	}
}

int main(){
	srand(time(NULL));
	
	/*�]�w���a�Ӽ�*/
	int pnum; //���X�ӹ��骱�a 
	int cnum; //���X�ӹq�����a 
	cout<<"Enter the number of players : (it should be less than 3)"<<endl;
	cin>>pnum;
	while(pnum>3){
		cout<<"The number of players you entered is unavailable (it should be less than 3), please enter it again : "<<endl;
		cin>>pnum;
	}
	cout<<"Enter the number of computer players : (it should be less than 3)"<<endl;
	cin>>cnum;
	while(cnum>3){
		cout<<"The number of computer players you entered is unavailable (it should be less than 3), please enter it again : "<<endl;
		cin>>cnum;
	}
	string players[7];
	int status_quo=100000*(pnum+cnum); //�����{�b���X�P��H (�p�G�Ψ� 5 ���w�X�P��H�h��אּ���X�P��H�b������Ҧ����W�@�a)  0~5
	for(int i=0;i<pnum;i++){
		players[i]="PLAYER"+to_string(i+1);
	}
	for(int i=0;i<cnum;i++){
		players[i+pnum]="PLAYER"+to_string(i+pnum+1)+"(COM)";
	}
	
	/*�o�P*/ 
	vector <int> poker_num(53); //�P�諸�Ʀr 
	vector <string> poker_color(53); //�P�諸���
	int number[8][6]; //��P���Ʀr
	string color[8][6];
	int total_choice[7]={5,5,5,5,5,5,5}; //�@�}�l�j�a�@�w�������i�P 
	/*cout<<"Shuffling...press Enter if you want to stop the shuffle (Beware that the moment you press Enter matters)"<<endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');*/
	for(int i=0;i<13;i++){
		poker_num[i]=i+1;
		poker_num[i+13]=i+1;
		poker_num[i+26]=i+1;
		poker_num[i+39]=i+1;
	}
	for(int i=0;i<13;i++){
		poker_color[i]="Club    ";
		poker_color[i+13]="Diamond ";
		poker_color[i+26]="Heart   ";
		poker_color[i+39]="Spade   ";
	}
	for(int i=0;i<6;i++){
		for(int j=0;j<pnum+cnum;j++){
			int a=rand()%(poker_num.size()-1); //���T�w�n���n��@ ��F���|��  �n���n �]���̫�@��O0 
			number[j][i]=poker_num[a];
			color[j][i]=poker_color[a];
			poker_num.erase(poker_num.begin()+a);
			poker_color.erase(poker_color.begin()+a);
		}
	}
	 
	/*�}��*/
	int order=1; //���������V(1���ɰw -1�f�ɰw)  
	int t=0; //���W�ثe���I���`�M
	char sign; //for Q and 10
	int choice;
	string player_this_round;
	int played_num;
	string played_color;
	while(true){
		/*�L�P�i�X*/
		int end=0;
		int no_lose;
		Losing_condition(status_quo, pnum, cnum, number, color, t, end, no_lose);
		if(end==1){
			cout<<player_this_round<<" doesn't have any cards to play, so "<<player_this_round<<" Lose @_@"<<endl;
			break;
		} 
		
		cout<<"ORDER : ";
		if(order==1){ //���� 
			for(int i=0;i<(pnum+cnum-1);i++){
				cout<<players[(status_quo+i)%(pnum+cnum)]<<" -> ";
			}
			cout<<players[(status_quo+(pnum+cnum-1))%(pnum+cnum)]<<endl;
		}else if(order==-1){ //�f�� 
			for(int i=0;i<(pnum+cnum-1);i++){
				cout<<players[(status_quo-i)%(pnum+cnum)]<<" -> ";
			}
			cout<<players[(status_quo-(pnum+cnum-1))%(pnum+cnum)]<<endl;
		}
		
		cout<<players[(status_quo)%(pnum+cnum)]<<"'S TURN!"<<endl;
		
		player_this_round=players[(status_quo)%(pnum+cnum)]; //����status_quo���ȥi��Q�ק� 
		
		if(((status_quo)%(pnum+cnum))<pnum){  //�O���a���ܭn�G�P���L�� 
			cout<<"PLAYING CARD : (The cards that can be played will have a check mark infront)"<<endl;
			Display_playing_card(status_quo, pnum, cnum, number, color, t, total_choice);
		}
		
		cout<<"CURRENT POINT : "<<t<<endl;
		
		Choose_a_card_to_play(status_quo, pnum, cnum, players, number, color, choice, total_choice, played_num, played_color, t);
		
		Draw_cards(status_quo, pnum, cnum, number, color, choice, total_choice, poker_num, poker_color); //�ݭn�bcard execution �e�����M status_quo���ȷ|����
		
		Card_function_execution(status_quo, pnum, cnum, players, played_num, played_color, t, order, sign);
		
		/*�X�P���~*/
		end=0;
		Losing_condition(status_quo, pnum, cnum, number, color, t, end, no_lose);
		if(end==1){
			cout<<player_this_round<<" Lose @_@"<<endl;
			break;
		}else{
			cout<<endl<<endl<<"===================================================================="<<endl<<endl<<endl;
		}
		
		/*�X�����p*/
		int tie=1;
		for(int i=0;i<pnum+cnum;i++){
			if(total_choice[i]!=0) tie=0;
		}
		if(tie==1) cout<<"There's no more cards! You all win!"<<endl; 
		
		/*���U�@�a*/
		if(order==1) status_quo++;
		else if(order==-1) status_quo--;
	}
	return 0;
}
