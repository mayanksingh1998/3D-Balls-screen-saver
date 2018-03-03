*** Screensaver ***
- The application displays variable number of balls bouncing on the screen according to the laws of defined physics. 

*** Features ***
- The position, speed and colour of each ball is initially random.  
- The balls collide elastically with the walls and also with each other.
- The speed of balls can be increased or decreased by the user. The user can also pause or play the application.


*** System Requirements ***
ScreenSaver runs on Linux system it requires the following packages :
- GNU gcc compiler
- OPENGL library
- pthread library
- SDL2 library

*** Usage Instuctions ***

-To run the main program:

--open terminal in makefile folder

--then run the command-->"make execute"

---then enter the number of balls you want to see

Inside the GUI window, an user defined number of bouncing balls will be seen on the screen and 8 buttons are there for interaction.

--Buttons are as follows:-

-   Exit button (Esc key): Pressing this key will close the window.

-	Pause/Play button (P Key): Pressing this button once will pause the movement of all the balls and terrain. Pressing it again will resume their movement.

-	Speed+ button(W Key): This button is used to increase the speed of  balls.
	* On pressing this button on times it  increments the speed of the ball by a 0.05. 
	
-	Speed- button(S Key): This button decreases the speed of balls.
	* On pressing this button the speed is divided by a factor of 1.2 on each press

-	Camera movement:-
	* Press "->" :to rotate the camera right side.
	* Press "<-" :to rotate the camera left side.
    * Press UP   : to zoom in.
    * Press down : to zoom out.
