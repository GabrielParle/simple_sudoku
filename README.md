# simple_sudoku
A terminal based sudoku game written in c.


should just be able to clone one file (drawgrid.c ) and build with gcc or whatever you use and run in the terminal.
Seeds the grid with "random numbers".
Then it solves the grid using a backtracking algorithim. 
It works by building out possible branches of the of solutions and following them to either a complete solution or a dead end. Then backtracking to the previous number it filled in and trying the next valid number. It does this recursivley which can be a little slow also the random nubers can whilst being checked to vaid( sudokoly) can create an unsolvable grid so it does have to regenrate the random numbers someimes. and the rand numbers can sometimes generate a grid which is very hard to solve so it can take a few second to generate a solved grid or if its an easy grid a few ms. on the plus side this should generate very unique puzzles.

todo ///
iplenment the solver (2) option.
clean it up can probably cut two hudred lines with some refactoring.

ensure the provided grid can onlyhave one solution . it seems likely that the grids provided only have one solution but i dont verfiy it.
