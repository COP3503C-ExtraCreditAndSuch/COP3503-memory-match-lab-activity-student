## SFML Lab Activity



To be implemented in COP3503 probably nearer to the end of the class for extra credit.



##### Purpose:



The purpose of this lab activity is to familiarize the students with SFML concepts, like passing by reference and the white screen problem, before they have to dive head first during Project 3 (Minesweeper).



##### Activity:



The students will be required to do the following two steps for extra credit:

1. Review the given code given in the "main_original.cpp" file and then abstract the code, slightly, into three separate functions: `loadCardTextures()`, `buildDeck()`, and `setLayout()`. The purpose of this is to teach the students how to identify various parts of the SFML code and understand how to abstract it without breaking it (more on that later).
2. Create one of the following features in game: time elapsed display, strike counter, or percent completion tracker.



##### SET UP FOR TAS:



1. Create a new CLion project
2. Download the code off of GitHub and extract the contents into the root of the project folder
3. Send the `memory_match_students.zip` to the students
4. Compile and run the project making sure to build with `main_full.cpp` to demonstrate what the students are making
5. Explain what the students should do (see below)
6. If there is a specific feature you want to show/give to a student (like for example you want to show them the code for just the strike system), see file explanations



##### WHAT THE STUDENTS NEED TO DO:



1. Create a new CLion project
2. Unzip `memory_match_students.zip` and move the folder contents to the root directory of the project
3. Abstract the code in `main.cpp` and create 3 new functions: `loadCardTextures()`, `buildDeck()`, and `setLayout()`
4. If they run out of time and make a decent attempt at the above, send them the `main_abstracted.cpp` code for them to work with the next step
5. Attempt to implement one of the features, using online resources and documentation as necessary: time elapsed display, strike counter, or percent completion tracker
6. Examples of the above implementation can be found in the other files (see file explanations)
7. If the students make an honest attempt at making the implementations, and still don't do a great job, give them the extra credit





##### FILE EXPLANATIONS:

Included is a basic template for a memory matching card game, created using the SFML library. There is an assets folder with all of the card images, fonts, and other images. There is a `card` class (no touch plz), and there are 6 "main.cpp" files. The "main.cpp" files will be explained here:

* `main_original.cpp` <- the original unorganized game that needs to be reviewed and abstracted.
* `main_abstracted.cpp` <- base game without any features added, but the above functions are implemented.
* `main_time.cpp` <- `main_abstracted` with timer implemented.
* `main_strike.cpp` <- `main_abstracted` with strikes implemented.
* `main_percent.cpp` <- `main_abstracted` with percent completion implemented.
* `main_full.cpp` <- full game with all features implemented.



The students should first work on abstracting main\_original.cpp. This is to familiarize themselves with the code. If they are not able to get it to run without errors after a while, then give them main\_abstracted.cpp and tell them to work on implementing one of the features. Ideally, they should have put in effort to abstract the main\_original.cpp and gotten most of the way into implementing one of the features before lab time is over. If a student doesn't complete the feature to the fullest ability, it's fine; give them extra credit.



The `main_time.cpp`, `main_strike.cpp`, and `main_percent.cpp` don't have to be shown in class or given to the students. I included them mostly for documentation purposes so that it is better understood which part of the code does what (and also what some example code would look like for a student that chose to do one of the features). The `main_full.cpp` is the fully featured game so that we can show the students what the full game looks like in case they want to work on that later.

##### 

