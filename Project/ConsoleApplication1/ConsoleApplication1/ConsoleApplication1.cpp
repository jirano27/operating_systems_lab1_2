#include <iostream>
#include <string>
#include <Windows.h>


#define BUFF_LEN 1024
int main()
{
    /*This X is used for the main menu function and will allow you to pick which option you want to pick*/
    int x;
   

    /*This DO function acts as the menu and will keep cycling through any option the user wants until
    you want to quit and you quit by typing 0*/
    do
    {
        std::cout << "Press 0 to quit." << std::endl
            << "1. To run DIR" << std::endl
            << "2. Help" << std::endl
            << "3. Vol" << std::endl
            << "4. Path" << std::endl
            << "5. Tasklist" << std::endl
            << "6. Notepad" << std::endl
            << "7. Echo" << std::endl
            << "8. Color" << std::endl
            << "9. Ping\n" << std::endl;

        /*User input on what they want*/
        std::cin >> x ;
        std::cout << "\n";
      
        /*These 2 if functions need to be here in the beginning so if you were to press 7 or 8 it will go through these if statements first. If they were at the end
        they wouldn't work.*/

        /*Reason why these If statements are here and not part of the switch is because when we define some things here if they were in a case function then 
        the system will believe we are skipping cases. Example if x==7 was written as case 7 then the code will believe that we're trying to skip case 8,9.
        To avoid this we just put them in the beginning as if statements and we no longer have case 7 or 8. Case 9 stays at the bottom because there are no 
        more cases after 9 so no need to make that into an if statement*/
        if (x == 7)
        {
            /*Every system("cls") in this code just clears the cmd to make it look more clean*/
            system("cls");
            std::cout << "You've chosen the echo command type anything:\n";

            /*This defines echo_test variable for when you are going to type in anything for this function it'll draw from this*/
            char echo_test[256];

            /*Puts whatever the user typed into the previously assigned variable*/
            std::cin >> echo_test;
            /*This defines the string and with it will call the echo command*/
            std::string echo_test_string = "cmd /c echo ";

            /*This combines whatever the user wrote into the previous code*/
            echo_test_string.append(echo_test);
            /*This allows the cmd /c echo code to run but c.str() allows for whatever the user typed as well to run along with it*/
            system(echo_test_string.c_str());
            std::cout << "\n";
        }
        if (x == 8)     /*This basically runs the same as if x==7 */
        {
            system("cls");
            char color_test[256];
            std::cout << "Enter color:  \n";

            /*A list of colors you can change cmd into*/
            std::cout << "0 = Black       8 = Gray\n"
                "1 = Blue        9 = Light Blue\n"
                "2 = Green       A = Light Green\n"
                "3 = Aqua        B = Light Aqua\n"
                "4 = Red         C = Light Red\n"
                "5 = Purple      D = Light Purple\n"
                "6 = Yellow      E = Light Yellow\n"
                "7 = White       F = Bright White\n";
            std::cin >> color_test;
            std::string color_test_string = "cmd /c color ";

            color_test_string.append(color_test);
            system(color_test_string.c_str());
        }
        /*This switch will just function as "if" so when we type 0-6,9 it will just jump to that function
        it takes x (the user input) as the variable to which case to go to.*/
        switch (x)
        {
            case 0:
                /*This is the designated quit case*/
                std::cout << "Sorry to see you leave but Hopefully you come back! ( 'O')/\n\n";
                /*Each case from here to the bottom just calls the system() funcation which just puts in whatever you type in the () into cmd*/
                system("exit");

                /*Each case will just break rather than return cause then it will just end the application*/
                break;
            case 1:
                system("cls");
                std::cout << "You've picked to run the DIR\n\n";
                /*Calls the director and shows you where this program resides*/
                system("dir");
                std::cout << "\n";
                
                break;
            case 2:
                system("cls");
                std::cout << "You've picked Help\n\n";
                /*Calls help so you know different funtions of the cmd prompt*/
                system("help");
                
                break;
            case 3:
                system("cls");
                std::cout << "You've picked Vol\n\n";
                /*Tells you what drive this program is in*/
                system("vol");
                std::cout << "\n";

                break;
            case 4:
                system("cls");
                std::cout << "You've picked to run the Path\n\n";
                /*Tells MS-DOS where to look for this application*/
                system("path");
                std::cout << "\n";
                
                break;
            case 5:
                system("cls");
                std::cout << "You've picked to see the Tasklist\n\n";
                /*Shows you what task is running in the backgroun*/
                system("Tasklist");
                std::cout << "\n";

                break;
            case 6:
                system("cls");
                std::cout << "You've picked to open Notepad\n\n";
                /*Opens up notepad*/
                system("Notepad");
                std::cout << "\n";

                break;
            case 9:
                system("cls");
                /*This is define outside of main. This is size 1024 because I don't know what the user will be looking for and it might be big.
                I just call it test for now*/
                char test[BUFF_LEN];// = { 0, };
                std::cout << "Enter ping Host or IP: \n";
                std::cin >> test;
               /*Same as the if statements above*/
                std::string test_string = "cmd /c ping ";

                /*This part of the program will run if the user typed in nothing when it prompted them to (just hit enter)*/
                if (test[0] == '\0')
                {
                    /*Randomly set it bing.com*/
                    strcpy_s(test, "bing.com");
                }
                /*Adds whatever the user typed into cmd /c ping*/
                test_string.append(test);
                /*Calls the cmd and runs cmd /c ping and .c_str() allows it to take in the input of the user as well
                without .c_str() this wouldn't work*/
                system(test_string.c_str());

                std::cout << "\n";

                break;

        }
    } while (x != 0); /*This will continue to run until 0 is pressed*/
    
   

}

