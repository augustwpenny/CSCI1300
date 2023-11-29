#include<sstream>
#include<fstream>
#include<vector>
#include<iostream>

using namespace std;

vector<string> teamsInTournament(string scores_file, int ws, int gs);

int main()
{
    string fileName="";
    int wins=0;
    int goals=0;
    cout << "Enter teamscores filename" << endl;
    cin >> fileName;
    cout << "Enter number of wins required" << endl;
    cin >> wins;
    cout << "Enter number of goals scored for tie-breaker" << endl;
    cin >> goals;
    vector<string> ret = teamsInTournament(fileName, wins, goals);
    // vector<string> ret = teamsInTournament("ts1.txt", 20, 20);
    int len=ret.size();
    for(int i=0;i<len;i++)
    {
        cout << ret.at(i) << endl;
    }
}


vector<string> teamsInTournament(string scores_file, int ws, int gs)
{
    ifstream filein;
    filein.open(scores_file);
    vector<int> goals;
    vector<int> wins;
    vector<string> allTeams;
    vector<string> tournamentTeams;
    int length=0;
    
    

    if(filein.fail())
    {
        cout << "Failed to open team scores file\n" << "No qualifying teams found" << endl;
        return tournamentTeams;
    }
    
    string team;
    string wis;
    string gls;
    while(!filein.eof())
    {
        getline(filein, team, ',');
        allTeams.push_back(team);

        getline(filein, wis, ',');
        wins.push_back(stoi(wis));
        
        getline(filein, gls);
        goals.push_back(stoi(gls));

        length++;
    }

    


    
    for(int i=0;i<length;i++)
    {
        if(wins.at(i)>ws) tournamentTeams.push_back(allTeams.at(i));

        if(wins.at(i)==ws)
        {
            if(goals.at(i)>=gs) tournamentTeams.push_back(allTeams.at(i));
        }
        ;
    }
    
    
    if(tournamentTeams.size()==0)
    {
        cout << "No qualifying teams found" << endl;
        return tournamentTeams;
    }
    cout << "Qualified teams are" << endl;
    return tournamentTeams;
}
