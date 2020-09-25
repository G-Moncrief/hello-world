//Submitted by Garrett Moncrief

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>

#include "coaches.h"
#include "teams.h"

using namespace std;

vector <Coaches> coachlist;
vector <Teams> teamlist;

void helpmenu ();										//displays help menu
void printcoach(vector <Coaches> C);		//prints coach info from vector
void printteam(vector<Teams> T);			//prints team info from vector
string removeplus (string s);						//removes + from cin input
void searchcoach (string s);						//for use with multi-field search_coaches 

int main ()
{
	bool run = true;
	cout << "\nThe mini-DB of NBA coaches and teams\n==============================" << endl;
	while (run == true){
		cout << "\nPlease enter a command. Enter 'help' for a list of commands" << endl;
		cout << "or 'exit' to quit program\n\n>";
		string usrsel;
		cin >> usrsel;
		//===================================================exits DB
		if (usrsel == "exit"){
			run = false;
			cout << "\n\nLeaving the database, goodbye!\n" << endl;
		}
		//===========================================displays help menu
		else if (usrsel == "help"){
			helpmenu();
		}
		//============================adds a new coach to the coaches vector
		else if (usrsel =="add_coach"){
			string ID, FN, LN, TEAM;
			int SEAS, SW, SL, PW, PL;
			cin >> ID >> SEAS >> FN >> LN >> SW >> SL >> PW >>PL >>TEAM;
			if (!cin){
				string dump;
				cout << endl << "Incorrect format, to add_coach please follow below example:\n\n" 
					<< "add_coach SAMPLE01 2018 John Doe 1 2 3 4 NYK\n\n"
					<< "Note: replace spaces in fields with a \"+\", eg van+Gundy.\n" << endl;
				cin.clear();
				cin >> dump;
			}
			else{
				ID=removeplus(ID);
				FN=removeplus(FN);
				LN=removeplus(LN);
				TEAM=removeplus(TEAM);
				coachlist.push_back(Coaches(ID,SEAS,FN,LN,SW,SL,PW,PL,TEAM));
			}
		}
		//==============================adds a new team to the teams vector
		else if (usrsel =="add_team"){
			string ID, LOC, NAME, LEG;
			cin >> ID >> LOC >> NAME >> LEG;
			if (!cin){
				string dump;
				cout << endl << "Incorrect format, to add_team please follow below example:\n\n"
					<< "add_team WA1 Washington Bullets N\n\n"
					<< "Note: replace spaces in fields with a \"+\", eg New+York.\n" << endl;
				cin.clear();
				cin >> dump;
			}
			else{
				ID = removeplus(ID);
				LOC = removeplus(LOC);
				NAME = removeplus(NAME);
				teamlist.push_back(Teams(ID,LOC,NAME,LEG));
			}
		}
		//================loads coaches from txt file by breaking up ',' seperated fields
		else if (usrsel == "load_coaches"){
			string loadcoach;
			cin >> loadcoach;
			ifstream coachtxt(loadcoach);
			if (coachtxt.is_open()){
				string line;
				while (getline(coachtxt, line))
				{
					int count = 0;
					string datafield[10];
					for (int i =0; i < line.length() ; i++){
						if (line[i] == ',')
							count ++;
						else
							datafield[count]+=line[i];
					}
					int convb, conve, convf, convg, convh; //converts strings to int
					stringstream b(datafield[1]);		b >> convb;
					stringstream e(datafield[5]);		e >> conve;
					stringstream f(datafield[6]);		 f >> convf;
					stringstream g(datafield[7]);		g >> convg;
					stringstream h(datafield[8]);		h >> convh;
					
					coachlist.push_back(Coaches(datafield[0],convb,datafield[3],datafield[4],conve,convf,convg,convh,datafield[9]));
				}
			}
			else{ 
				cout << "***File " << loadcoach <<" could not be located.\n"
					<< "Example input is: load_coaches coaches_season.txt please try again"<< endl;
			}	
		}
		//===================loads teams from txt file by breaking up ',' seperated fields
		else if (usrsel == "load_teams"){
			string loadteams;
			cin >> loadteams;
			ifstream teamtxt(loadteams);
			if (teamtxt.is_open()){
				string line;
				while (getline(teamtxt, line)){
					int count = 0;
					string datafield[4];
					for (int i = 0; i < line.length() ; i++){
						if (line[i] == ',')
							count ++;
						else
							datafield[count]+= line[i];
					}
					teamlist.push_back(Teams(datafield[0],datafield[1],datafield[2],datafield[3]));
				}
			}
			else{
				cout << "***File " << loadteams << " could not be located.\n"
					<< "Example input is: load_teams teams.txt please try again." << endl;
			}
		}
		//===========================================prints coaches vector
		else if (usrsel == "print_coaches"){
			if (coachlist.size() == 0)
				cout << "\nDatabase of coaches empty. Use add_coach or load_coaches\n"
				<< "to populate database. Enter \'help\' for more information." << endl;
			else
				printcoach(coachlist);
		}
		//==============================================prints teams vector
		else if (usrsel == "print_teams"){
			if(teamlist.size() == 0)
				cout << "\nDatabase of teams empty. Use add_team or load_teams\n"
				<< "to populate database. Enter \'help\' for more information." << endl;
			else
				printteam(teamlist);
		}
		//=============================prints coach(es) with specified last name
		else if (usrsel == "coaches_by_name")
		{
			string findname;
			cin >> findname;
			findname=removeplus(findname);
			vector <Coaches> byName;
			for (int i = 0; i < coachlist.size(); i++){
				if (coachlist[i].getd().find(findname)  != std::string::npos)
					byName.push_back(coachlist[i]);
			}
			printcoach(byName);
		}
		//====================================prints team(s) with specified city
		else if (usrsel == "teams_by_city")
		{
			string findcity;
			cin >> findcity;
			findcity = removeplus(findcity);
			vector <Teams> byCity;
			for (int i = 0; i < teamlist.size(); i++){
				if (teamlist[i].getb().find(findcity) !=std::string::npos)
					byCity.push_back(teamlist[i]);
			}
			printteam(byCity);
		}
		//=====================returns best coach for a given season calculated by
		//===================(season win - season loss) + (playoff win - playoff loss)
		else if (usrsel == "best_coach")
		{
			int findseas;
			cin >> findseas;
			if (!cin){
				string dump;
				cout << "Invalid entry. Enter a 4 digit season year to search for best\n"
				<< "coach of the given season." << endl;
				cin.clear();
				cin >> dump;
			}
			else{
				vector <Coaches> bySeas;
				for (int i = 0; i < coachlist.size() ; i++){
					if(coachlist[i].getb() == findseas)
						bySeas.push_back(coachlist[i]);
				}
				vector <int> score;
				for (int j = 0; j < bySeas.size(); j++)
					score.push_back((bySeas[j].gete() - bySeas[j].getf()) + (bySeas[j].getg() - bySeas[j].geth()));
				
				int currentbest = -500;
				vector <Coaches> tmp;
				for (int k = 0; k < score.size() ; k++){
					if (score[k] > currentbest){
						tmp.clear();
						currentbest = score[k];
						tmp.push_back(bySeas[k]);
					}
					else if (score[k] == currentbest)
						tmp.push_back(bySeas[k]);
				}
				printcoach(tmp);
			}
		}
		//==========================================search coaches by field
		else if (usrsel == "search_coaches"){
			string s;
			stringstream ss;
			getline(cin, s);
			searchcoach(s);
		}
		//====================================disp invalid selection notification
		else
			cout << "Invalid selection, try again." << endl;
	}
}

void helpmenu ()
{
	string border = "####################################################################";
	string divider = "--------------------------------------------------------------------";
	cout << border << endl << border<< endl;
	cout << "\n\t\t\t--==HELP MENU==--\n" << endl;
	cout << "-Replace all instances of brackets with the specified information" << endl;
	cout << "-Use '+' to join entries with a space, example: New+York\n" << endl;
	cout << border << endl << "########## ADDING TO DATABASES "
		<<"#####################################\n"<< border << endl;
	cout << "\nadd_coach [ID] [FIRST NAME] [LAST NAME] [SEASON WINS]\n"
		<< "\t  [SEASON LOSSES] [PLAYOFF_WINS] [PLAYOFF_LOSSES] [TEAM]\n" << divider << endl;
	cout <<"add_team  [ID] [LOCATION] [TEAM NAME] [LEAGUE]\n" <<divider <<  endl;
	cout << "load_coaches [FILENAME]\t| Bulk load of coach info from file\n" << divider << endl;
	cout << "load_teams [FILENAME]\t| Bulk load of team info from file\n\n" <<  border << endl;
	cout << "########## QUERYING DATABASES " <<"######################################\n"<< border << endl;
	cout << "print_coaches \t\t| Print a listing of all coaches\n"<<divider << endl;
	cout <<"print_teams \t\t| Print a listing of all teams\n"<< divider << endl;
	cout << "coaches_by_name [NAME] \t| List info of coaches with specified name\n" << divider << endl;
	cout << "teams_by_city [CITY] \t| List the teams in specified city\n" << divider << endl;
	cout << "best_coach [SEASON] \t| Find coach with most net wins in a season\n" << divider << endl;
	cout << "search_coaches \t\t| Print name of coach satisfying\n[field=VALUE]\t\t| specified conditions\n" << border <<endl;
	cout << border << endl;
}

void printcoach(vector<Coaches> C)
{
	for (int i = 0; i < C.size(); i++)
	{
			cout << left<< setw(10) <<C[i].geta();
			cout << left<< setw(4) <<C[i].getb();
			cout << right<< setw(10) << C[i].getc() << " ";
			cout << left<< setw(14) << C[i].getd();
			cout << right<<setw(4)<<C[i].gete();
			cout << right<<setw(4)<<C[i].getf();
			cout << right<<setw(4)<<C[i].getg();
			cout << right<<setw(4)<<C[i].geth() <<"   ";
			cout << left<<setw(4)<<C[i].geti() << endl;
	}
}

void printteam(vector<Teams> T)
{
	for (int i = 0; i < T.size(); i++)
	{
		cout <<left << setw(4)<<T[i].geta();
		cout << right << setw(15) << T[i].getb() << " ";
		cout << left << setw(20) << T[i].getc();
		cout << right <<setw(1) << T[i].getd() << endl;
	}
}

string removeplus (string s)
{
	string tmp; 
	for (int i = 0; i < s.length() ; i++){
		if (s[i] != '+')
			tmp+= s[i];
		else
			tmp +=" ";
	}
	return tmp;
}

void searchcoach (string s)
{
	vector <string> searchfields;
	string tmp;
	//first searchcoach finds individual fields that have been entered
	for (int i = 0; i < s.length(); i++){
		if (s[i] != ' ')
			tmp += s[i];
		else{
			searchfields.push_back(tmp);
			tmp ="";
		}
	}
	searchfields.push_back(tmp);
	//goes through each field that was found and checks to see if any entries match up
	//repeats this process with a continuously narrowing vector of coaches until all search
	//fields have been checked.
	vector <Coaches> C;
	vector <Coaches> aux;
	for (int j = 0; j < searchfields.size(); j++){
		if (searchfields[j].find("Coach_ID=") != std::string::npos){
			string tmp = searchfields[j].substr(searchfields[j].find("Coach_ID=")+9);
			if(C.empty()){
				for (int k = 0; k < coachlist.size(); k++)
					if (coachlist[k].geta().find(tmp)  != std::string::npos)
						C.push_back(coachlist[k]);
			}
			else{
				for (int k = 0; k < C.size(); k++)
					if (C[k].geta().find(tmp)  != std::string::npos)
						aux.push_back(C[k]);
				C.clear();
				C=aux;
				aux.clear();
			}
		}
		else if (searchfields[j].find("season=") != std::string::npos){
			string tmp = searchfields[j].substr(searchfields[j].find("season=")+7);
			int tmp2 = stoi (tmp);
			if(C.empty()){
				for (int k = 0; k < coachlist.size(); k++)
					if (coachlist[k].getb()==tmp2)
						C.push_back(coachlist[k]);
			}
			else{
				for (int k = 0; k < C.size(); k++)
					if (C[k].getb()==tmp2)
						aux.push_back(C[k]);
				C.clear();
				C=aux;
				aux.clear();
			}
		}
		else if (searchfields[j].find("first_name=") != std::string::npos){
			string tmp = searchfields[j].substr(searchfields[j].find("first_name=")+11);
			if(C.empty()){
				for (int k = 0; k < coachlist.size(); k++)
					if (coachlist[k].getc().find(tmp)  != std::string::npos)
						C.push_back(coachlist[k]);
			}
			else{
				for (int k = 0; k < C.size(); k++)
					if (C[k].getc().find(tmp)  != std::string::npos)
						aux.push_back(C[k]);
				C.clear();
				C=aux;
				aux.clear();
			}
		}
		else if (searchfields[j].find("last_name=") != std::string::npos){
			string tmp = searchfields[j].substr(searchfields[j].find("last_name=")+10);
			if(C.empty()){
				for (int k = 0; k < coachlist.size(); k++)
					if (coachlist[k].getd().find(tmp)  != std::string::npos)
						C.push_back(coachlist[k]);
			}
			else{
				for (int k = 0; k < C.size(); k++)
					if (C[k].getd().find(tmp)  != std::string::npos)
						aux.push_back(C[k]);
				C.clear();
				C=aux;
				aux.clear();
			}
		}
		else if (searchfields[j].find("season_win=") != std::string::npos){
			string tmp = searchfields[j].substr(searchfields[j].find("season_win=")+11);
			int tmp2 = stoi (tmp);
			if(C.empty()){
				for (int k = 0; k < coachlist.size(); k++)
					if (coachlist[k].gete()==tmp2)
						C.push_back(coachlist[k]);
			}
			else{
				for (int k = 0; k < C.size(); k++)
					if (C[k].gete()==tmp2)
						aux.push_back(C[k]);
				C.clear();
				C=aux;
				aux.clear();
			}
		}
		else if (searchfields[j].find("season_loss=") != std::string::npos){
			string tmp = searchfields[j].substr(searchfields[j].find("season_loss=")+12);
			int tmp2 = stoi (tmp);
			if(C.empty()){
				for (int k = 0; k < coachlist.size(); k++)
					if (coachlist[k].getf()==tmp2)
						C.push_back(coachlist[k]);
			}
			else{
				for (int k = 0; k < C.size(); k++)
					if (C[k].getf()==tmp2)
						aux.push_back(C[k]);
				C.clear();
				C=aux;
				aux.clear();
			}
		}
		else if (searchfields[j].find("playoff_win=") != std::string::npos){
			string tmp = searchfields[j].substr(searchfields[j].find("playoff_win=")+12);
			int tmp2 = stoi (tmp);
			if(C.empty()){
				for (int k = 0; k < coachlist.size(); k++)
					if (coachlist[k].getg()==tmp2)
						C.push_back(coachlist[k]);
			}
			else{
				for (int k = 0; k < C.size(); k++)
					if (C[k].getg()==tmp2)
						aux.push_back(C[k]);
				C.clear();
				C=aux;
				aux.clear();
			}
		}
		else if (searchfields[j].find("playoff_loss=") != std::string::npos){
			string tmp = searchfields[j].substr(searchfields[j].find("playoff_loss=")+13);
			int tmp2 = stoi (tmp);
			if(C.empty()){
				for (int k = 0; k < coachlist.size(); k++)
					if (coachlist[k].geth()==tmp2)
						C.push_back(coachlist[k]);
			}
			else{
				for (int k = 0; k < C.size(); k++)
					if (C[k].geth()==tmp2)
						aux.push_back(C[k]);
				C.clear();
				C=aux;
				aux.clear();
			}
		}
		else if (searchfields[j].find("team=") != std::string::npos){
			string tmp = searchfields[j].substr(searchfields[j].find("team=")+5);
			if(C.empty()){
				for (int k = 0; k < coachlist.size(); k++)
					if (coachlist[k].geti().find(tmp)  != std::string::npos)
						C.push_back(coachlist[k]);
			}
			else{
				for (int k = 0; k < C.size(); k++)
					if (C[k].geti().find(tmp)  != std::string::npos)
						aux.push_back(C[k]);
				C.clear();
				C=aux;
				aux.clear();
			}
		}
	}
	printcoach(C);
	if (C.empty())
	cout << "\nNo results found. An example search is:\n"
		<<"\"search_coaches last_name=Smith\"\n"
	<<"Possible search fields are:\n\nCoach_ID\nfirst_name\nlast_name\nseason_win\n"
	<<"season_loss\nplayoff_win\nplayoff_loss\nteam\n" << endl;
}

