#ENGG1340 Group Project
Liu Tianjia (3035729370) 
He Zixuan (3035827861)

Description and rule of game:
ENGG1340 Adventure is a turn-based, text-based game where multiple players can choose their roles (fighter/mage/support) and use various skills to fight against boss --- ENGG1340Fail.

Different roles have different skills. The following is a brief introduction of each role:
1.	fighter
feature: Making a lot of damage
defect: No skill to recover mp (magic point) or hp (health point)

2.	mage
feature: Recover mp
defect: No skill to recover hp and damage to boss is low

3.	support
feature: Recover hp and provide shield for players
defect: No skill to recover mp and damage to boss is very low
*shield could prevent players from boss’s next hit

When a player does not have enough mp to use some skill, using that skill will automatically skip that round.

Hence, teamwork is needed in OC dmx, different roles could make the most of themselves only with their team members.

The game is full of randomness. The damage or healing value of some skills is generated randomly within a range, and there are two buff and two debuff that player have chance to get each round, the following is buff & debuff included.
Buff included: 
	1. ALL players recover 500hp.   
	2. ALL players' mp become double
Debuff included:
	3. ALL players lose 50% mp
	4. ALL players fall asleep, players' rounds end.

The user can first choose a language (English is preferable because the Chinese version still contains some English).

The target of players is defeating boss, 1340Fail. When the HP of the boss becomes 0, players win; when the HPs of all the players become 0, players lose.


Features Included:
1.Single or multiple players are allowed to play.
2.Each players ca input their own name.
3.Players can choose different roles with multiply skills each.
4.The damage values of some skills for each round are randomly set within a range. This is to make the gameplay more uncertain and challenging.
5.At the beginning of each round, there are chance for players to get random event, which will bring them buff or debuff.
6.Dynamic struct and dynamic struct array are used to store status of players and boss.
7.Players could choose to save the current game status and exit after every 5 rounds. The status information will be stored in their computer as a file. For the next play, they could choose to load the last saved game. When playing the game, at the beginning of each round, there will be a notice to inform you how much rounds are there until the next chance to save.
8.Motion effects and programming pause for certain seconds to make the game more interesting.

Code Requirement:
1.	Generation of random game sets or events
Support features 4 and 5 
2.	Data structures for storing game status
Support feature 6
3.	Dynamic memory management
Support feature 6
4.	File input/output (e.g., for loading/saving game status)
Support feature 7
5.	Program codes in multiple files
Each section of the codes will be stored separately in different files.
6.	Proper indentation and naming styles
Could be seen in the code
7.	In-code documentation
Could be seen in the code

Non-standard c++ library used:
#include <unistd.h>
Function used in this library: sleep()
To support feature 8

Compilation and execution instructions:
