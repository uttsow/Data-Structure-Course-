README

Ant File:
The fight method  decided the winner based on a random
number generator from 1-100. If the number was greater than 50
then the ant wins the fight, else it loses. If it wins the
fight, the method returns 1, indicating winner, or 2 other wise
This will be used in the AntHill file to determine if the
ant dies or stays alive; This was all done in the
move method because each time a ant moves, it has a
chance of getting into a fight as described in the
assignment.

AntHill File:
I again used a simple number generator for this as well.
This time, the number was between 0-100. if the number
was under 25, then the anthill was attacked. When it was
attacked, i went through all current_ants, checked if
they were within half the gridmax in the x and y coordinate
and added the number of ants that were in the range to a
variable. Then i got the amount of number of attackers,
compared the two, and if there were more defenders, then the
hill was saved and no ant or food was lost. Else,
the food was lost and all the ants that were within that
grid range was deleted from both linked list and array;
I also tracked the number of wins and losses as well;

LinkedList file:

Iteration of the linked list was done through the creation
of a temp, head, and curr node. The head node was just used
to keep track of the head while the temp and curr node
did the iteration for all the other methods.
Each time, the list was deleted, all 3 nodes would be set to
null

in each linked list, i stored the ant pointers, hence
i used *aAnt all through the code;

The linked list required a destructor while the node didn't.
I learned this after trying to make a copy list and deleting
objects however, i would get a maloc free pointer error
since every time i deleted an a node from the list, it would
delete the thing it was holding as well, so double delete
of ants object results in trying to delete something that
was already deleted.

Reference:
stackoverflow for the linked list copy constructor,
however, i forgot to save the page and cannot find the page again

Misc:
This assignment was difficult and took a long time to debug
