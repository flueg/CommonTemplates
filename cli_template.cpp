//
//  main.cpp
//  sudoku
//
//  Created by Flueg H.G. Lau on 6/28/15.
//  Copyright (c) 2015 Flueg H.G. Lau. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include <getopt.h>

void getOptions(int argc, char * argv[]);

class MyOpt
{
public:
    std::string inputFile;
    std::string ouputFile;
    
    MyOpt():inputFile("sudoku.input"), ouputFile("sudoku.output") { };
};

MyOpt myOpt;

/* options descriptor */
static struct option longOpts[] = {
    { "input-file",     required_argument,      NULL,           'i' },
    { "output-file",    required_argument,      NULL,           'o' },
    { "help",           no_argument,            NULL,           'h' },
    { NULL,             0,                      NULL,           0 }
};

void usage(int rc)
{
    exit (rc);
}

void getOptions(int argc, char* argv[])
{
    char ch;
    while ((ch = getopt_long(argc, argv, "i:o:h", longOpts, NULL)) != -1)
        switch (ch) {
            case 'i':
                myOpt.inputFile = optarg;
                break;
            case 'o':
                myOpt.ouputFile = optarg;
                break;
            case 'h':
                usage(0);
                break;
            default:
                usage(7);
        }
}

int main(int argc, char * argv[])
{
    
    getOptions(argc, argv);
    std::cout << "myOpt: " << std::endl
                << "input: " << myOpt.inputFile << std::endl
                << "output:" << myOpt.ouputFile;
    return 0;
}
