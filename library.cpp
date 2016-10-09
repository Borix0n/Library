//
//  library.cpp
//  library
//
//  Created by Izabela Borówka on 06.10.2016.
//  Copyright (c) 2016 Izabela Borówka. All rights reserved.
//

#include "library.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>


using namespace std;

 
void PrintOneBook( zbior it )
{
    cout<<it.id_book<<endl;
    cout<<it.author_name<<endl;
    cout<<it.author_sur<<endl;
    cout<<it.title<<endl;
    cout<<it.IBSM<<endl;
}

//------------------------------------------------------------

void PrintOutBooks( vector < zbior > *p )
{
    vector< zbior > ::iterator it=p->begin();
    
    for( ; it!= p->end(); it++ )
    {
        PrintOneBook( *it );
    }
    
}

//------------------------------------------------------------


void PrintOnePerson( person it2 )
{
    cout<<it2.name<<endl;
    cout<<it2.surname<<endl;
    cout<<it2.number<<endl;
}

//------------------------------------------------------------


void PrintOutPeople( vector < person > *c )
{
    vector< person > :: iterator it2=c->begin();
    
    for( ; it2!= c->end(); it2++ )
    {
        PrintOnePerson( *it2 );
    }
}

//------------------------------------------------------------

void PrintOneData( data it3 )
{
    cout<<it3.id_person<<endl;
    cout<<it3.id_Book<<endl;
    cout<<it3.day<<endl;
    cout<<it3.mounth<<endl;
    cout<<it3.year<<endl;

    
}
//------------------------------------------------------------


void PrintofData( vector < data > *d )
{
    vector < data > :: iterator it3=d->begin();
    for( ; it3!=d->end(); it3++ )
    {
        PrintOneData( *it3 );
    }
    
}

