# The-Adventures-of-JRP
A text adventure created for a our Object Oriented Programming Class

demo.txt

To compile you will need to type 
'g++ -Wall -std=gnu++0x *.cpp -o adventure'
into the terminal while in the folder.
If you have any problems with compilation please email me
at jmm15f@acu.edu

Move Functionality Finished Check

Combat Functionality Finished Check

Look Functionality Finished Check

Debug Mode Finished 

View Current Stats Finished  Check

Map Finished Check

Dungeon Finished Check

Room Finished Check

Items Finished Check

Stat-Altering through Items Finished Check

Curios Finished

Added Parser Finished Check


You will start in a room.

To see all the different commands type "Help".

To show movement simply type "Move North".

To see your current stats type "Stats"

To test item functionality you will want to type "Look" to see any items in any room. There should be a dagger in your current room. You can take the dagger by typing "Take Dagger". This will automatically increase your attack by 5.

To see your updated stats type "Stats" again.

To see combat functionality type "Move North" and you will be pulled into combat with a Mutated Rat. Now you can type "Attack" and you should win this battle.

To help with testing curio functionality type "Look" to see that there is a Bronze Key in this room. Type "Take Bronze Key" to take the key. You can see what items you have picked up by typing "Inventory".

To see that the parser does in fact work type "iNveNtOry" instead of "Inventory" and it will still pull up your current inventory.

Now to test Debug mode simply type "up,up,down,down,left,right,left,right,b,a,start" or you can simply type "yeet"

Now to test the curio you will need to "Move East", "Move East", "Attack" until the guard is dead, "Move North", then "Use Bronze Key".

To test death functionality type "Exit", then start the program over and follow these instructions.

"Move North"
"Move North"
"Attack"
"Move East"
"Move East"
"Attack"
"Attack"
"Attack"
"Attack"

Now you will have died. If you wish to continue playing the game you are more than welcome to but this is all the basic functionality that you need see.
