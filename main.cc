 while (!GETOUT && Exit == false)
                                // Loop for the Buttons 
        {
                                // Taken from the prelab this detects a button press
            if (!pb1) {
                                // This is the Button that exits the Program 
                Exit = true;    // Sets the Exit value to be true and exits the loop
                GETOUT = true; 
                uLCD.cls();     // Clears the screen
                t.stop();       // stops the timer
                data.exit();    // Displays the data on Exit 
                wait(2.0);      // Waits two seconds so you read the data 
                break;

            }

            else if (!pb2) {
                                    // This is the button that selects the left bin
                GETOUT = true;
                t.stop();           // Stops the timer
                uLCD.cls();         // Clears the Screen 
                screen.CompareLR(); // Compares the right and left bin
                data.winRatio();    // This displays the data of the winRatio Member function 
                wait(2.0);          // Waits 2 so the user can see the information 
                screen.DisplayAll();// Runs the next trial.
                break;
            }

            else if(!pb3) {
                                    // This is the button that selects the right bin
                GETOUT = true;
                t.stop();           // Stops the timer
                uLCD.cls();         // Clears the Screen 
                screen.CompareRL(); // Compares the right and left bin
                data.winRatio();    // This displays the data of the winRatio Member function 
                wait(2.0);          // Waits 2 so the user can see the information 
                screen.DisplayAll();// Runs the next trial.
                break;
            }
        }
    }
}



