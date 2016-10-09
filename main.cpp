//
//  main.cpp
//  library
//
//  Created by Izabela Borówka on 30.09.2016.
//  Copyright (c) 2016 Izabela Borówka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "library.h"

using namespace std;


int main(int argc, const char * argv[])
{
    
    vector < zbior > SPIS;
    vector< zbior > ::iterator it=SPIS.begin();
    
    ifstream file("Zbior.txt", ios::in ) ;
    
    if( file.good() == false )
    {
        cout<<"nie istnieje";
        exit(0);
    }
    string line;
    unsigned long int aLen;   // dlugosc danego slowa do znaku ';'
    string aWord; // przechowuje dane słowo
    unsigned long int aLen2;
    string aWord2;
    unsigned long int aLen3;
    string aWord3;
    unsigned long int aLen4;
    string aWord4;
    unsigned long int aLen5;
    string aWord5;
    
    while( !file.eof() )
    {
        getline( file, line );
        aLen = line.find_first_of( ';' , 0 );
        aWord = line.substr( 0, aLen );
        // ------------------------
        aLen2= line.find_first_of( ';' , aLen+1);
        aWord2= line.substr( aLen+1 , aLen2-aLen-1 );
        // ------------------------
        aLen3= line.find_first_of( ';' , aLen2+1 );
        aWord3= line.substr( aLen2+1 , aLen3-aLen2-1 );
        // ------------------------
        aLen4= line.find_first_of( ';' , aLen3+1 );
        aWord4= line.substr( aLen3+1 , aLen4-aLen3-1 );
        // ------------------------
        aLen5= line.size();
        aWord5= line.substr( aLen4+1 , aLen5 );
        
        
        const char *a=aWord.c_str();
        int aNumber=atoi( a );
        //cout<<aNumber<<endl;
        
        //const char *b=aWord5.c_str();
        // int bNumber= atoi(b);
        //cout<<bNumber<<endl;
        
        SPIS.push_back( zbior( aNumber, aWord2, aWord3, aWord4, aWord5 ) );
    }
    
    file.close();
    
    //----------------SEPARATE---FILES-------------------------//
    
    
    vector < person > ListOfPeople;
    vector < person > :: iterator it2=ListOfPeople.begin();
    
    ifstream file2("SpisOsob.txt", ios::in ) ;
    
    if( file2.good() == false )
    {
        cout<<"nie istnieje";
        exit(0);
    }
    string line2;
    unsigned long int Len;   // dlugosc danego slowa do znaku ';'
    string Word; // przechowuje dane słowo
    unsigned long int Len2;
    string Word2;
    unsigned long int Len3;
    string Word3;
    
    
    while( !file2.eof() )
    {
        getline( file2, line2 );
        Len=line2.find_first_of( ';' , 0 );
        Word=line2.substr( 0, Len );
        //-----------------------
        Len2=line2.find_first_of( ';' , Len+1 );
        Word2=line2.substr( Len+1 , Len2-Len-1 );
        //-----------------------
        Len3=line2.size();
        Word3=line2.substr( Len2+1, Len3-Len2-1 );
        //-----------------------
        
        const char *a=Word3.c_str();
        int aNumber=atoi( a );
        
        
        ListOfPeople.push_back( person( Word, Word2, aNumber ) );
        
    }
    
    file2.close();
    
   // PrintOutPeople( &ListOfPeople );


    //----------------SEPARATE---FILES-------------------------//

    
    vector < data > DataOfPeople;
    vector < data > :: iterator it3=DataOfPeople.begin();
    
    ifstream file3("KtoCO.txt", ios::in ) ;
    
    if( file3.good() == false )
    {
        cout<<"nie istnieje";
        exit(0);
    }

    string line3;
    unsigned long int len;   // dlugosc danego slowa do znaku ';'
    string word; // przechowuje dane słowo
    unsigned long int len2;
    string word2;
    unsigned long int len3;
    string word3;
    unsigned long int len4;
    string word4;
    unsigned long int len5;
    string word5;

    while( !file3.eof() )
    {

        getline( file3, line3 );
        len = line3.find_first_of( ';' , 0 );
        word = line3.substr( 0, len );
        //---------------------------------
        len2 = line3.find_first_of( ';' , len+1 );
        word2 = line3.substr( len+1 , len2-len-1 );
        //---------------------------------
        len3 = line3.find_first_of( ';' , len2+1 );
        //cout<<len3<<endl;
        word3 = line3.substr( len2+1 , len3-len2-1 );
        //---------------------------------
        len4 = line3.find_first_of( ';' , len3+1 );
        word4 = line3.substr( len3+1 , len4-len3-1 );
        //---------------------------------
        len5 = line3.find_first_of( ';' , len4+1 );
        word5 = line3.substr( len4+1 , len5-len4-1 );
        
        const char *a=word.c_str();
        int id = atoi( a );
        
        const char *b=word2.c_str();
        int id_b =atoi( b );
        
        const char *c=word3.c_str();
        int day=atoi( c );

        
        const char *d=word4.c_str();
        int mounth=atoi( d );

        const char *e=word5.c_str();
        int year=atoi( e );


        
       DataOfPeople.push_back( data( id, id_b, day, mounth, year ) );
        
    }
    
    file3.close();

   // PrintofData( &DataOfPeople );
 
    
    //----------------SEPARATE---FILES-------------------------//

  
    cout<<"MAIN MENU: "<<endl;
    cout<<"1. My profile "<<endl;
    cout<<"2. Browse collection of books"<<endl;
    cout<<"3. Look for the books"<<endl;
    cout<<"4. Borrow a book"<<endl;
    
    int tmp;
    cin>>tmp;

    switch( tmp )
    {
            
        case 1:
        {
    
            cout<<"Writte your ID: "<<endl;
            int id;
            cin>>id;
    
            it2=ListOfPeople.begin();
    for( ; it2!=ListOfPeople.end(); it2++ )
    {
        
            if( id == it2->number )
            {
                cout<<it2->name<<" "<<it2->surname<<endl;

                it3=DataOfPeople.begin();
                for( ; it3!=DataOfPeople.end(); it3++ )
                {
                    if( id == it3->id_person )
                    {
                        cout<<it3->day<<"/"<<it3->mounth<<"/"<<it3->year<<endl;
                        
                        it=SPIS.begin();
                        for( ; it!=SPIS.end(); it++ )
                        {
                            if( it3->id_Book == it->id_book )
                            {
                                cout<<it->author_name<<" "<<it->author_sur<<" "<<it->title<<endl;
                            }
                        }
                        
                    }
                }
            }
    }
            
            break;
   
        }
            
        
//****************************************************************

        case 2:
        {
            PrintOutBooks( &SPIS );
            break;
        }
    
    
            
//****************************************************************

        case 3:
        {
    
    
   // for(auto i = SPIS.begin(); i != SPIS.end(); i++)
 
  //vector< zbior > ::iterator it=SPIS.begin();
   
    //PrintOutBooks( &SPIS );
    
            cout<<"How do you want to chose your book? "<<endl<<endl;
            cout<<"1. NAME "<<endl;
            cout<<"2. SURNAME "<<endl;
            cout<<"3. TITLE "<<endl;
    
            int zm;
            cin>>zm;
            string word;
            char title[100];
            bool BookIsInCase=false;
    
                switch( zm )
                {
                    case 1:
                    {
                        cout<<"Write name: "<<endl;
                        cin>>word;
            
                        it=SPIS.begin();
                        for( ; it!= SPIS.end(); it++ )
                        {
                if( strcmp( word.c_str(), it->author_name.c_str()  ) == 0 )
                {
                    PrintOneBook( *it );
                    BookIsInCase = true;

                }
                        }
                        if( !BookIsInCase )
                        {
                           cout<<" There is no book of this author"<<endl ;
                        }
                break;
                }
        
    // ------------------------

        case 2:
        {
            cout<<"Write surname: "<<endl;
            cin>>word;
           
            it=SPIS.begin();

            for( ; it!= SPIS.end(); it++ )
            {
                if( strcmp( word.c_str(), it->author_sur.c_str()  ) == 0 )
                {
             
                     PrintOneBook( *it );
                    BookIsInCase = true;

                }
                
            }
            if( !BookIsInCase )
            {
                cout<<" There is no book of this author"<<endl ;
            }
            break;
        }
    
    // ------------------------

        case 3:
        {
            cout<<"Write title: ";
            cin>>title;
            
            it=SPIS.begin();

            for( ; it!= SPIS.end(); it++ )
            {
                if( strcmp( title, it->title.c_str()  ) == 0 )
                {
                    
                    PrintOneBook( *it );
                    BookIsInCase = true;

                }
            }
            if( !BookIsInCase )
            {
                cout<<" There is no book of this author"<<endl ;
            }
            break;
    
            }
   
            break;
}
        }
    }
    // ------------------------------------------------------------------------------


    
            return 0;
        }
