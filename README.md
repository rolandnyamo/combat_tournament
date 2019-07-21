# combat tournament
A cli-based fantasy combat tournament

## description
This game creates a lineup of two teams comprised of multiple players each.
The players each have specific attributes, attack strengths and defense strengths.

A circular linked structure is used to to store all the players, and another one used to store the losing players.

Every player that wins a game gets a little more strength points (recharges), but is sent to the end of the queue.

The game ends when one of the teams is empty (i.e. when the linked structure is empty, meaning all players on that team have lost).
