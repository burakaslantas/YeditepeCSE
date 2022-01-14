/* @Author
 * Student Name: Burak Aslantas
 * Student ID: 20190702029
 * Date: 28.12.2021
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "textEditor.h"
using namespace std;

int main()
{
    cout << "     ____        _       __              \n"
            "    / __ \\____  (_)___  / /____  _____  \n"
            "   / /_/ / __ \\/ / __ \\/ __/ _ \\/ ___/\n"
            "  / ____/ /_/ / / / / / /_/  __/ /       \n"
            " /_/ ___\\____/_/_/ /_/\\__/\\___/_/     \n"
            "    / ____/___/ (_) /_____  _____        \n"
            "   / __/ / __  / / __/ __ \\/ ___/       \n"
            "  / /___/ /_/ / / /_/ /_/ / /            \n"
            " /_____/\\__,_/_/\\__/\\____/_/          \n\n"
            "Created by Burak Aslantas  .: ver0.1.1 :.\n"
            "with <3 in Istanbul (not San Francisco)\n\n\n";
    cout << "         ..::: COMMANDS :::..         \n"
            "######################################\n"
            "# Command Type #    Example Usage    #\n"
            "######################################\n"
            "# 1)   open    #     open abc.txt    #\n"
            "# 2)   save    #     save abc.txt    #\n"
            "# 3)  insert   #   insert 5 hello!   #\n"
            "# 4)  delete   #      delete 3       #\n"
            "# 5)   move    #      move 3 5       #\n"
            "# 6)  replace  #   replace 3 hello!  #\n"
            "# 7)   next    #        next         #\n"
            "# 8)   prev    #        prev         #\n"
            "# 9)   undo    #        undo         #\n"
            "######################################\n"
            "All commands should be contains lower-case characters.\n"
            "Formats below are NOT ALLOWED\n\n\n";

    textEditor* textPtr; // Points to the textEditor's object
    string command;
    string operationState; // Given command's operation state
    int currentPage;
    int maxVisibleLines; // Number of lines in the text
    string filename; // filename in "abc.txt" format
    cout << "What's the filename? (Please enter it in \"abc.txt\" format, replace \"abc\" with file name)" << endl;
    getline(cin,filename);
    textPtr = new textEditor(filename);
    maxVisibleLines = textPtr->size();
    operationState = filename + " openned successfully!";
    
    // All stacks related with "undo" command
    vector<string> commandKeywordStack;
    vector<string> deletedLineStack;
    vector<string> replaceStack;
    vector<int> moveStack;
    vector<int> insertIndexStack;
    vector<int> deleteIndexStack;
    vector<int> replaceIndexStack;

    while(true)
    {
        currentPage = textPtr->page(); // This is the page which is visible to user now
        cout << "############################################################" << endl;

        for(int i = (10 * (currentPage - 1) ) + 1; i < ( 10 * currentPage ) + 1; i++) // In this for loop, print 10 line from text to the screen
        {
            if( i <= maxVisibleLines && textPtr->line(i) != "0cb7c3e488b4184f68801f9898e63b4471dfe1d72487e3046de60c105cc4b043" ) // If there are lines to be printed and these are valid lines (see hash part in IntSLList.cpp), then print them
            {    
                cout << "# " << i << ") " << textPtr->line(i) << endl;
            }
            else //If there are no lines left to be printed, print ".:: PAGE END ::."
            {
                cout << "# " << i << ") " << ".:: PAGE END ::." << endl;
            }
        }

        cout << "# \n# \n# --- Page " << currentPage << " ---" << endl; // Prints, currentPage
        cout << "############################################################" << endl;
        cout << operationState << endl;
        cout << "Enter a command: " << endl;
        getline(cin, command);
        string buffer;
        stringstream ss(command);
        vector<string> commandTokens;

        while (ss >> buffer)
            commandTokens.push_back(buffer);
        
        if( !commandTokens.empty() )
        {
            string commandKeyword = commandTokens.at(0);

            if( "next" == commandKeyword )
            {
                commandKeywordStack.push_back(commandKeyword);
                operationState = textPtr->nextPage();
            }
            else if( "prev" == commandKeyword )
            {
                commandKeywordStack.push_back(commandKeyword);
                operationState = textPtr->prevPage();
            }
            else if( "open" == commandKeyword )
            {
                filename = commandTokens.at(1);
                delete textPtr;
                textPtr = NULL;
                textPtr = new textEditor(filename);
                maxVisibleLines = textPtr->size();

                //Empty all stacks related with "undo" opearation
                commandKeywordStack.clear();
                deletedLineStack.clear();
                replaceStack.clear();
                moveStack.clear();
                insertIndexStack.clear();

                operationState = filename + " openned successfully!";
            }
            else if( "save" == commandKeyword )
            {
                filename = commandTokens.at(1);
                operationState = textPtr->saveFile( filename );
            }
            else if( "replace" == commandKeyword )
            {
                // Takes "nObj" as a string from "commandTokens" and converts it as a "n" to integer value.
                stringstream nObj(commandTokens.at(1));
                int n;
                nObj >> n;
                
                // For "undo" command
                replaceIndexStack.push_back(n);
                replaceStack.push_back( textPtr->line(n) );
                commandKeywordStack.push_back(commandKeyword);
                
                // Takes given "text" from commandTokens  
                string text;
                vector<string> lineToken = vector<string>(commandTokens.begin() + 2, commandTokens.end());
                
                for(auto i: lineToken)
                {
                    string buf = i + " ";
                    text.append(buf);
                }
                
                // Replace nth line with given text
                operationState = textPtr->replaceLine( n, text );
            }
            else if( "move" == commandKeyword )
            {
                // Takes "fromObj" as a string from "commandTokens" and converts it as a "from" to integer value.
                stringstream fromObj(commandTokens.at(1));
                int from;
                fromObj >> from;
                
                // Takes "toObj" as a string from "commandTokens" and converts it as a "to" to integer value.
                stringstream toObj(commandTokens.at(2));
                int to;
                toObj >> to;
                
                // For "undo" command
                moveStack.push_back(from);
                moveStack.push_back(to);
                commandKeywordStack.push_back(commandKeyword);
                
                // Move the line at "from" index, to the "to" index
                operationState = textPtr->moveLine( from, to );
            }
            else if( "delete" == commandKeyword )
            {
                // Takes "nObj" as a string from "commandTokens" and converts it as a "n" to integer value.
                stringstream nObj(commandTokens.at(1));
                int n;
                nObj >> n;
                
                // For "undo" command
                deleteIndexStack.push_back(n);
                deletedLineStack.push_back( textPtr->line(n) );
                commandKeywordStack.push_back(commandKeyword);
                
                // Delete nth line
                operationState = textPtr->deleteLine(n);
                maxVisibleLines = textPtr->size();
            }
            else if( "insert" == commandKeyword )
            {
                // Takes "nObj" as a string from "commandTokens" and converts it as a "n" to integer value.
                stringstream nObj(commandTokens.at(1));
                int n;
                nObj >> n;
                
                // For "undo" command
                insertIndexStack.push_back(n);
                commandKeywordStack.push_back(commandKeyword);
                
                // Takes given "text" from commandTokens
                string text;
                vector<string> lineToken = vector<string>(commandTokens.begin() + 2, commandTokens.end());
                
                for(auto i: lineToken)
                {
                    string buf = i + " ";
                    text.append(buf);
                }
                
                operationState = textPtr->insertLine( n, text );
                maxVisibleLines = textPtr->size();
            }
            else if( "undo" == commandKeyword )
            {
                if( commandKeywordStack.empty() )
                {
                    operationState = "This is the initial state of the file. Undo command can not be performed!";
                }
                else
                {
                    operationState = "";
                    string lastPerformedCommand = commandKeywordStack.back();
                    commandKeywordStack.pop_back();

                    if( "next" == lastPerformedCommand )
                    {
                        // To perform undo action for "next" command, run "prev" command
                        textPtr->prevPage();
                    }
                    else if( "prev" == lastPerformedCommand )
                    {
                        // To perform undo action for "prev" command, run "next" command
                        textPtr->nextPage();
                    }
                    else if( "insert" == lastPerformedCommand )
                    {
                        // To perform undo action for "insert n text" command, run "delete n" command
                        textPtr->deleteLine( insertIndexStack.back() );
                        insertIndexStack.pop_back();
                        maxVisibleLines = textPtr->size();
                    }
                    else if( "delete" == lastPerformedCommand )
                    {
                        // To perform undo action for "delete n" command, run "insert n text" command, text is top of the deletedLineStack
                        textPtr->insertLine( deleteIndexStack.back(), deletedLineStack.back() );
                        deleteIndexStack.pop_back();
                        deletedLineStack.pop_back();
                        maxVisibleLines = textPtr->size();
                    }
                    else if( "move" == lastPerformedCommand )
                    {
                        // To perform undo action for "move from to" command, run "move to from" command
                        int from;
                        int to;
                        from = moveStack.back();
                        moveStack.pop_back();
                        to = moveStack.back();
                        moveStack.pop_back();
                        textPtr->moveLine( from, to );
                    }
                    else if( "replace" == lastPerformedCommand )
                    {
                        // To perform undo action for "replace n text" command, run "replace n originalText" command, originalText is top of the replaceStack
                        textPtr->replaceLine( replaceIndexStack.back(), replaceStack.back() );
                        replaceIndexStack.pop_back();
                        replaceStack.pop_back();
                    }
                    else
                    {
                        operationState = "Undo command could not perform!";
                    }
                }
            }
            else
            {
                operationState = "You entered not valid command, please enter a valid command";
            }
        }
    }
    return 0;
}
