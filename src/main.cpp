
#include <iostream>
#include "roundrobin.h"

using namespace std;

int main(int argc, char * argv[])
{

if(argc<3)
{
	cout << "usage: " << argv[0] << " <team_1> <team_2> ... <team_n>" << endl;
	cout << "minimum 2 teams provided" << endl;
	return -1;
}

// set team list
vector<string> teams;
for(unsigned i=1; i<argc; i++)
{
teams.push_back(argv[i]);
}

// prepare empty schedule
vector< vector<STeamPair> > schedule;

roundrobin_schedule(teams, schedule);
roundrobin_arrange_home_and_away(schedule);

// leg-1
for(unsigned i=0; i<schedule.size(); i++)
{
	cout << endl << "Week-" << i+1 << ": " << endl;
	for(unsigned j=0; j<schedule[i].size(); j++)
	{
		cout << schedule[i][j].iTeam1 << " vs " << schedule[i][j].iTeam2 << endl;
	}
}

// leg-2
roundrobin_swap_home_and_away(schedule);
for(unsigned i=0; i<schedule.size(); i++)
{
	cout << endl << "Week-" << i+1+schedule.size() << ": " << endl;
	for(unsigned j=0; j<schedule[i].size(); j++)
	{
		cout << schedule[i][j].iTeam1 << " vs " << schedule[i][j].iTeam2 << endl;
	}
}
cout << endl;

return 0;
}
