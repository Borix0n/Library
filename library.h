//
//  library.h
//  library
//
//  Created by Izabela Borówka on 06.10.2016.
//  Copyright (c) 2016 Izabela Borówka. All rights reserved.
//

#ifndef __library__library__
#define __library__library__

#include <stdio.h>
#include "library.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

class zbior
{
public:
    int id_book;
    string author_name;
    string author_sur;
    string title;
    string IBSM;
    
public:
    zbior( int xid_book, string xauthor_name, string xauthor_sur, string xtitle, string xISBM )
    {
        id_book=xid_book;
        author_name=xauthor_name;
        author_sur = xauthor_sur;
        title = xtitle;
        IBSM = xISBM;
    }
};

//----------------------------------------

class person
{
public:
    
    string name;
    string surname;
    int number;
    
public:
    person( string xname, string xsurname, int xnumber )
    {
        name=xname;
        surname=xsurname;
        number=xnumber;
    }
    
};

//----------------------------------------

class data
{
public:
    
    int id_person;
    int id_Book;
    int day;
    int mounth;
    int year;
    
    data( int qid_person, int id_dBook, int qday, int qmounth, int qyear )
    {
        id_person=qid_person;
        id_Book=id_dBook;
        day=qday;
        mounth=qmounth;
        year=qyear;
    }
};

//----------------------------------------


void PrintOneBook( zbior it );
void PrintOutBooks( vector < zbior > *p );
void PrintOnePerson( person it2 );
void PrintOutPeople( vector < person > *c );
void PrintOneData( data it3 );
void PrintofData( vector < data > *d );

#endif /* defined(__library__library__) */
