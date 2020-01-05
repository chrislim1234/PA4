CSCI 103 Programming Assignment 4, A Mazeing BFS

Name: Chris Lim    

Email Address: chrislim@usc.edu

NOTE: You can delete the questions, we only need your responses.

NOTE: It is helpful if you write at most 80 characters per line,
and avoid including special characters, so we can read your responses.

Please summarize the help you found useful for this assignment, which
may include office hours, discussion with peers, tutors, et cetera.
Saying "a CP on Tuesday" is ok if you don't remember their name.
If none, say "none".

:CP MONDAY, other students
=============================== Prelab ==================================

1. What data structure will you use to remember which cells have
already been added to the queue or not?

:The data strucutre I will use is dynamic 2D memory array. To check which
cells have already been added to the queue I will create a 2D array which
list down all the cells that have been visited before, hence making sure
that it remembers which cells have been added to queue

2. At what step of the BFS algorithm do you have to mark a cell as visited?

:We have to mark a cell as visited after we have added it to the queue.
Whenever we look at neighboring cells and it is open and unvisited, 
we add it to the queue before adding the current cell as visited and 
then also adding the predecesssor for the neighboring cell. 

=============================== Review ==================================

1. Describe your "mymaze.txt" test file. It should have multiple paths
of different distances. When you ran your program on it, did your program 
behave as expected?

:Yes it behaved as expected, eventhough it had multiple paths of different
distances, it gave one of the path with the shortest distance. This works
as appropriately because the shorter path reaches F quicker which means
that path's predecessor will be called and help find that path. If there 
are mutliple paths that are equal distances, it finds the top path first 
before the bottom,left and right. This is because in my code, I check for
the top path first before bottom left and right, hence the path starting
from the top path would reach the finish point earlier, hence returning
that path.

============================== Remarks ==================================

Filling in anything here is OPTIONAL.

Approximately how long did you spend on this assignment?

:

Were there any specific problems you encountered? This is especially 
useful to know if you turned it in incomplete.

:

Do you have any other remarks?

:

