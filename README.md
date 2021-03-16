# ENGG1340-GP Proposal
Liu Tianjia (3035729370)
He Zixuan (3035827861)

Game description:
We hope to create a turn-based, text-based game where multiple players can choose their roles (e.g. fighter/mage/support) and use various skills to fight against bosses. When the HP of the boss becomes 0, players win; when the HPs of all the players become 0, players lose. 

Features Included:
1.Single or multiple players are allowed to play.
2.Players can choose different roles with 6 different skills each.
3.There are several different bosses for players to fight against.
4.At each turn, players are randomly given 3 skills out of 6 skills. The damage values of some skills for each round are randomly set within a range. This is to make the gameplay more uncertain and challenging.
5.Players could choose to save the current game status and exit after each round. The status information will be stored in their computer as a file. For the next play, they could choose to load the last saved game.
6.After the end of each game, players could choose to start a new game or exit.

Coding requirements:
1.Generation of random game sets or events:
  Support features 3 and 4
2.Data structures for storing game status:
  Arrays are used to store the skills, HPs and MPs of players and bosses
3.Dynamic memory management:
  We will use varibles to store the game status 
4.File input/output (e.g., for loading/saving game status):
  Support feature 5
5.Program codes in multiple files:
  Each section of the codes will be stored separately in different files.
