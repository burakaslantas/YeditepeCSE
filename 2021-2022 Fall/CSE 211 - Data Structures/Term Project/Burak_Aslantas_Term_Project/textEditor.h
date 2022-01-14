/* @Author
 * Student Name: Burak Aslantas
 * Student ID: 20190702029
 * Date: 28.12.2021
 */
#include <iostream>
#include "IntSLList.h"
#include <fstream>
#include <string>
#include <utility>
using namespace std;

class textEditor
{
    private:
        bool error;
        IntSLList *fileContents; // keeps all contents line by line in a linkedlist,
        //every node in the linkedlist is a line in the text.
        int fileSize; // contains number of lines in the text
        int maxVisiblePage;
        int currentPage;
        
    public:
        explicit textEditor( const string& filename )
        {
            string line;
            ifstream file;
            file.open(filename.c_str());
            
            if( !file.is_open() )
            {
                cout << "Sorry, we couldn't open the file\n"
                        "Tip: Maybe you entered filename in wrong format or file extension doesn't supported\n"
                        "     Please keep in mind, filename should be formatted as correctly, some examples: \"pointer_editor.txt\", \"is_created_with_love_in_istanbul.txt\", etc.\n"
                        "     Only supported extension is \".txt\"\n";
                maxVisiblePage = 0;
                currentPage = 0;
                error = true;
                return;
            }
            
            error = false;
            fileContents = new IntSLList();
            
            while(!file.eof())
            {
                getline(file, line);
                fileContents->addToTail(line);
            }
            
            fileSize = fileContents->GetSize();
            maxVisiblePage = (fileSize / 10) + 1;
            currentPage = 1;
        }

        ~textEditor()
        {
            if( error )
            {
                return;
            }
            delete fileContents;
            fileContents = nullptr;
            fileSize = 0;
            maxVisiblePage = 0;
            currentPage = 0;
        }

        string saveFile(const string& filename)
        {
            /*
            The program should write the contents of the linked list 
            to the file whose name is provided in the `filename` field.
            */
            ofstream outputFile(filename);

            if( !outputFile.is_open() )
            {
                error = true;
                return  "Sorry, we couldn't open the file\n"
                        "Tip: Maybe you entered filename in wrong format or file extension doesn't supported\n"
                        "     Please keep in mind, filename should be formatted as correctly, some examples: \"pointer_editor.txt\", \"is_created_with_love_in_istanbul.txt\", etc.\n"
                        "     Only supported extension is \".txt\"\n";
            }
            
            int i = 1;
            for( ; i < fileSize; i++)
            {
                outputFile << fileContents->GetAt(i) << endl;
            }

            outputFile << fileContents->GetAt(i);
            return filename + " saved successfully!";
        }

        string insertLine(int index, const string& line)
        {
            /*
            The program should insert a new line in the text at the nth line,
            which contains the string provided in the field `text`. For example,
            if the user enters “insert 5 hello my friend”, your program should 
            insert a new line at line position 5, and put “hello my friend” in that line.
            
            If the file already contains more than n lines, it should insert thin new line
            between lines n-1 and n, putting the newly inserted text at line n.
            If the file contains less than n lines, it should fill the gap with blank lines
            until the newly inserted line becomes at position n.
            */
            if( index > fileSize )
            {
                while( fileSize < index - 1 )
                {
                    fileContents->addToTail( "" );
                    fileSize++;
                    maxVisiblePage = (fileSize / 10) + 1;
                }

                fileContents->addToTail( line );
                fileSize++;
                maxVisiblePage = (fileSize / 10) + 1;
            }
            else
            {
                fileSize++;
                maxVisiblePage = (fileSize / 10) + 1;

                if( index == 1 ) // the line at beginning of file
                {
                    fileContents->addToHead( line );
                }
                else if( index == fileSize ) // the line at end of file
                {
                    fileContents->addToTail( line );
                }
                else // the line at middle of file
                {
                    fileContents->addToMiddle( index, line );
                }
            }

            return "The new line successfully inserted!";
        }

        string deleteLine(int index) // BU FONKSİYON TEST EDİLECEK, Bazı caselerde duzgun calismiyor
        {
            /*
            The program should delete the line at position n
            */
            if( index > fileSize )
            {
                return "This is not a valid index, please enter a valid index!";
            }
            else
            {
                if(fileSize == 1) // the line, only line of file
                {
                    replaceLine(1, ".:: PAGE END ::.");
                }
                else if( index == 1 ) // the line at beginning of file
                {
                    fileContents->deleteFromHead();
                }
                else if( index == fileSize ) // the line at end of file
                {
                    fileContents->deleteFromTail();
                }
                else // the line at middle of file
                {
                    fileContents->deleteNode( fileContents->GetAt(index) );
                }
            }

            fileSize--;
            maxVisiblePage = (fileSize / 10) + 1;
            return "The line successfully deleted!";
        }

        string moveLine(int fromIndex, int toIndex)
        {
            /*
            The program should move the line at position n to position m
            */
            if( fromIndex >= 1 && fromIndex <= fileSize )
            {
                if( toIndex >= 1 && toIndex <= fileSize )
                {
                    string hash = "0cb7c3e488b4184f68801f9898e63b4471dfe1d72487e3046de60c105cc4b043";

                    if( hash != fileContents->GetAt(fromIndex) && hash != fileContents->GetAt(toIndex) )
                    {
                        string temp = fileContents->GetAt( fromIndex );
                        deleteLine( fromIndex );
                        insertLine( toIndex, temp );
                        return "The line successfully moved!";
                    }
                    return "Moving operation could not be performed!";
                }
                return "This is not a valid toIndex, please enter a valid toIndex";
            }
            return "This is not a valid fromIndex, please enter a valid fromIndex";
        }

        string replaceLine(int index, string line)
        {
            /*
            The program should replace the text inside line n with the string provided in `text`.
            */
            if( index > fileSize )
            {
                return "This is not a valid index, please enter a valid index!";
            }

            fileContents->ReplaceInfoAtNode(index, std::move(line));
            return "The line's text successfully replaced!";
        }

        string nextPage()
        {
            /*
            Contents of the file should not change, but the program should display the next page
            */
            if( currentPage < maxVisiblePage )
            {
                currentPage++;
                return "";
            }
            else
            {
                return "This is the last page of the file.";
            }
        }

        string prevPage()
        {
            /*
            Contents of the file should not change, but the program should display the previous page.
            */
            if( currentPage > 1 )
            {
                currentPage--;
                return "";
            }
            else
            {
                return "This is the first page of the file.";
            }
        }

        int page() const
        {
            return currentPage;
        }

        int size() const
        {
             return fileSize;
        }

        string line(int index)
        {
            return fileContents->GetAt(index);
        }
};
