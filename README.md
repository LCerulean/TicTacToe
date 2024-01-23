# TicTacToe

This was an assignment for the Codecademy "Learn C++" course.  It was a fun project to complete, as I have made similar games with Python, and it was interesting to see how it differed building it in another language.

The player inputs their name and chooses their mark (X or O).  They then play against the computer, which makes a random move on it's turn.  Every time a turn is made, the used space is added to a vector that stores all the used spaces so that it can be determined if a choice made is valid, or if the board is full.  After each turn, the program checks if the last move resulted in 3 in a row, and ends the game if so, or switches turns if not.
