// datoteka TString.cpp 
// ***********************************************************************
//  standard C++ string class subset
// ***********************************************************************

#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include "TString.h"

const int TString::npos = -1;

TString::TString()
// POST: string je prazan
{
    m_length = 0;
    m_capacity = 1;
    m_cstr = new char[m_capacity];
    m_cstr[0] = '\0';           // cstring nulte duljine
}


TString::TString(const char * s)
//    Opis: konstruktor iz literalnog stringa, pr. "abcd"
//    PRE:  s je '\0'-terminirani ASCIIZ string
//    POST: formira se kopija od s
{
    assert (s != 0);               //  provjera: cstring not NULL?

    m_length = strlen(s);
    m_capacity = m_length + 1;      // dodaj bajt za '\0'
    m_cstr = new char[m_capacity];
    strcpy(m_cstr,s);
}

TString::TString(const TString & str)
//    Opis:   kopirni konstruktor
//    POST: formira se kopija od str
{
    m_length = str.length();
    m_capacity = m_length + 1;
    m_cstr = new char[m_capacity];
    strcpy(m_cstr,str.m_cstr);
}

TString::~TString()
//    Opis:   destruktor
//    POST: dealocira se string
{
    delete[] m_cstr;                // dealociraj memoriju
}

const TString& TString::operator =(const TString & rhs)
//    POST: pridjela kopiranjem string objekta
{
    if (this != &rhs)                          // provjeri da li je
    {                                          // s=s;
        if (m_capacity < rhs.length() + 1)     // procijeni da li treba
        {                                      // poveæati memoriju
            delete[] m_cstr;                // dealociraj stari string
            m_capacity = rhs.length() + 1;     // dodaj 1 bajt za '\0'
            m_cstr = new char[m_capacity];
        }
        m_length = rhs.length();
        strcpy(m_cstr,rhs.m_cstr);
    }
    return *this;
}
const TString& TString::operator = (const char * s)
//    Opis:   pridjela literalnog stringa 
//    PRE:  s je ASCIIZ string 
//    POST: pridjela s dubokim kopiranjem
{

    assert(s != 0);                 // provjeri da li je s !=NULL
    int len = strlen(s);            // duljina stringa

    // free old string if necessary

    if (m_capacity < len + 1)
    {
      delete[] m_cstr;          // dealociraj stari string
      m_capacity = len + 1;        // dodaj 1 bajt za '\0'
      m_cstr = new char[m_capacity];
    }
    m_length = len;
    strcpy(m_cstr,s);
    return *this;
}

const TString& TString::operator = (char ch)
//    Opis:   pridjela jednog znaka 
//    POST: string sadrži jedan znak 
{
    if (m_capacity < 2)
    {
        delete [] m_cstr;
        m_capacity = 2;
        m_cstr = new char[m_capacity];
    }
    m_length = 1;
    m_cstr[0] = ch;             // string za smještaj jednog znaka
    m_cstr[1] = '\0';
    return *this;
}


char& TString::operator[](int k)
//    PRE:  0 <= k < length()
//    POST: vraæa referencu k-tog znaka
//    Nota: ako se ova referenca koristi za upis '\0'
//          daljni resultati su nedefinirani
//
{
    if (k < 0 || m_length <= k)
    {
        cerr << "Indeks izvan dozvoljenog intervala: " 
             << k << " string: " << m_cstr
             << endl;
        exit(1);
    }
    return m_cstr[k];
}

char TString::operator[](int k) const
//    PRE:  0 <= k < length()
//    POST: vraæa k-ti znak
{
    if (k < 0 || m_length <= k)
    {
        cerr << "Indeks izvan dozvoljenog intervala: " 
             << k << " string: " << m_cstr
             << endl;
        exit(1);
    }
    return m_cstr[k];
}

ostream& operator <<(ostream & os, const TString & str)
//    POST: str se šelje izlaznom toku os
{
    return os << str.c_str();
}

istream& operator >>(istream & is, TString & str)
//    PRE:  ulazni tok je otvoren 
//    POST: dobavlja se string iz ulaznog toka i sprema u str
{
    char ch;
    str = "";    // prazan string, dodavat æemo znak po znak
    is >> ch;    // dobavi prvi ne-bijeli znak ch
    
    if (! is.fail())
    {
        do
        {
            str += ch;
            is.get(ch);
        } while (! is.fail() && ! isspace(ch));
        
        if (isspace(ch))    // vrati razmak u stream
            is.putback(ch);             
    }
    return is;
}

int TString::length( )const
{
	return m_length;
}


istream & getline(istream & is, TString & str)
//    Opis: dobavlja liniju teksta iz ulaznog toka u string str
//    PRE:  ulazni tok je otvoren 
//    POST: više znakova zakljuèno s '\n' se oèitava s ulaznog toka
//          i sprema u str ('\n' se ne sprema u str)
{

    char ch;
    str = "";     
    
    while (is.get(ch) && ch != '\n')
    {
        str += ch;
    }
    return is;
}

const TString& TString::operator +=(const TString & str)
//    POST: dodaje kopiju str stringa na kraj this stringa
{

    TString copystring(str);         // napravi kopiju stringa

    int newLength = length() + str.length(); // procijeni duljinu
    int lastLocation = length();      // položaj  '\0' znaka

    // provjeri da li treba poveæati memoriju
    if (newLength >= m_capacity)
    {
        m_capacity = newLength + 1;
        if (str.length() == 1)  // specijalni sluèaj- dodaje se jedan znak
        {                       
            m_capacity *= 2;
        }
        char * newBuffer = new char[m_capacity];
        strcpy(newBuffer,m_cstr); // kopiraj u novi buffer
        delete [] m_cstr;         // dealociraj stari string
        m_cstr = newBuffer;
    }

    // sada dodaj str (copystring) na kraj od m_cstr
    strcpy(m_cstr+lastLocation, copystring.c_str() );
    m_length = newLength;           // upiši novu duljinu stringa

    return *this;
}

const TString & TString::operator += ( char ch )
//    POST: dodaje znak ch na kraj this stringa
{
    TString temp;   // napravi string koj sadrži znak ch
    temp = ch;
    *this += temp;
    return *this;
}

TString operator +(const TString & lhs, const TString & rhs)
//    POST: vraæa string koji se sastoji od lhs dopunjenog s rhs
{
    TString result(lhs);  // kopira lhs u result
    result += rhs;         // dopunjuje rhs
    return result;         // vraæa result
}

TString operator + ( char ch, const TString & str )
//    POST: vraæa string koji se sastoji znaka ch i stringa str
{
    TString result; // napravi string koj sadrži znak ch
    result = ch;
    result += str;
    return result;
}

TString operator + ( const TString & str, char ch )
//    POST: vraæa string koji se sastoji stringa str dopunjenog znakom ch
{
    TString result(str);
    result += ch;
    return result;
}


TString TString::substr(int pos, int len) const
//    Opis:   vraæa substring duljine len poèevši od indeksa pos
//    PRE:  this string sadrži c0, c1, ..., c(n-1), uz uvjet
//                         0 <= pos <= pos + len - 1 < n.
//    POST: vraæa string koji sadrži
//                   c(pos), c(pos+1), ..., c(pos+len-1)
{
    if (pos < 0)                       // start at front when pos < 0
        pos = 0;
    
    if (pos >= m_length) return "";     // prazni string

    int lastIndex = pos + len - 1;      // zadnji index koji kopiramo
    if (lastIndex >= m_length)          // budi unutar stringa?
    {
        lastIndex = m_length-1;
    }

    TString result(*this);   // alociraj dovoljno memorije
    int j,k;
    for(j=0,k=pos; k <= lastIndex; j++,k++)
    {
        result.m_cstr[j] = m_cstr[k];
    }
    result.m_cstr[j] = '\0';       // terminiraj cstring
    result.m_length = j;              // i zabilježi duljinu
    return result;
}

int TString::find(const TString & str)  const
//    Opis:   pronalazi pojavu stringa str u this stringu
//            i vraæa indeks prvog znaka. Ako this string ne sadrži
//            string str, tada vraæa npos.
//    PRE:  this string sadrži c0, c1, ..., c(n-1)
//          str sadrži s0, s1, ...,s(m-1)
//    POST: ako je s0 == ck0, s1 == ck1, ..., s(m-1) == ck(m-1) i ako
//          ne postoji j < k0 takovi da je s0 = cj, ...., sm == c(j+m-1),
//              tada vraæa k0;
//              u suprotnonm sluèaju vraæa npos
{
    int len = str.length();
    int lastIndex = length() - len;
    int k;
    for(k=0; k <= lastIndex; k++)
    {
        if (strncmp(m_cstr + k,str.c_str(),len) == 0) return k;
    }
    return npos;
}

int TString::find( char ch ) const
//    Opis:   pronalazi prvu pojavu znaka u this stringu i vraæa indeks
//            Ako znak chnije u this stringu, tada vraæa npos.
//    PRE:  this string sadrži c0, c1, ..., c(n-1)
//    POST: ako je ch == ck, i ako ne postoji j < k takovi da je ch == cj
//                   tada vraæa k;
//                   u suprotnonm sluèaju vraæa npos
{
    int k;
    for(k=0; k < m_length; k++)
    {
        if (m_cstr[k] == ch)
               return k;
    }
    return npos;
}


bool operator == ( const TString & lhs, const TString & rhs )
{
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator != ( const TString & lhs, const TString & rhs )
{
    return ! (lhs == rhs);
}

bool operator <  ( const TString & lhs, const TString & rhs )
{
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator <= ( const TString & lhs, const TString & rhs )
{
    return !( rhs < lhs );
}
bool operator >  ( const TString & lhs, const TString & rhs )
{
    return rhs < lhs;
}

bool operator >= ( const TString & lhs, const TString & rhs )
{
    return ! ( lhs < rhs );
}


