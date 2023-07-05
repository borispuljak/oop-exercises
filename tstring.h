// Datoteka: TString.h
#ifndef _TSTRING_H
#define _TSTRING_H

#include <iostream>
using namespace std;

class TString
{
  public:

  static const int npos;  // koristi se kao oznaka: 
                        // nije pozicija u stringu

  // konstruktori/destruktor

    TString( );                         // konstruktor praznog stringa ""
    TString( const char * s );          // lkonstruktor iz literalnog str.
    TString( const TString & str );     // kopirni konstruktor
    ~TString( );                        // destruktor

  // pridjela vrijednosti

    const TString & operator = ( const TString & str ); // str objekt
    const TString & operator = ( const char * s );       // ASCIIZ string
    const TString & operator = ( char ch );              // znak ch

  // pristupnici

    int    length( )const;                     // broj znakova
    int    find( const TString & str ) const;  // indeks pojave stringa
                                               // str u stringu this
    int    find( char ch ) const;              // indeks pojave znaka ch
    TString substr( int pos, int len ) const;  // substring duljine len
                                               // od pozicije  pos

    const char * c_str( ) const {return m_cstr;} // vraæa char * 
    operator char* ( ) const {return m_cstr;}  // pretvorba u  char *

  // indeksirani pristup

    char   operator[ ]( int k ) const;   
    char & operator[ ]( int k );  

  // mutatori - dopuna stringa  stringom str i znakom ch

    const TString & operator += ( const TString & str );
    const TString & operator += ( char ch );            

  private:
      int m_length;              // duljina stringa (broj znakova)
      int m_capacity;            // kapacitet stringa - u bajtima
      char * m_cstr;             // pokativaè na ASCIIZ string
};

// Neèlanske funkcije
//
// ulazni/izlazne operacije

ostream & operator << ( ostream & os, const TString & str );
istream & operator >> ( istream & is, TString & str );
istream & getline( istream & is, TString & str );

// relacijski operatori:

bool operator == ( const TString & lhs, const TString & rhs );
bool operator != ( const TString & lhs, const TString & rhs );
bool operator <  ( const TString & lhs, const TString & rhs );
bool operator <= ( const TString & lhs, const TString & rhs );
bool operator >  ( const TString & lhs, const TString & rhs );
bool operator >= ( const TString & lhs, const TString & rhs );

// operator + (dopuna stringa)

TString operator + ( const TString & lhs, const TString & rhs );
TString operator + ( char ch, const TString & str );
TString operator + ( const TString & str, char ch );

#endif //_TSTRING_H