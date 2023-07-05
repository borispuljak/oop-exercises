#ifndef _TVECTOR_H
#define _TVECTOR_H

// *******************************************************************
// based on the Vector class in Tapestry, first edition
// and on the AP vector class.  However, this class mirrors
// the STL vector with push_back, pop_back, size(), resize(), reserve()
// This vector does NOT support STL-style iterators; it does do range
// checking on operator []
//
// *******************************************************************

template <class T>
class tvector
{
  public:
    tvector( );               // predodre�eni konstruktor - size==0
    tvector( int size );      // konstruktor za size veli�inu
    tvector( int size, const T & fill ); // po�etna vrijednost = fill
    tvector( const tvector & vec );   // kopirni konstruktor
    ~tvector( );                      // destruktor

    const tvector & operator = ( const tvector & vec );

    int  length( )   const;        // podr�ka za stare programs, ra�e
    int  capacity( ) const;        // koisti umjesti length()
    int  size( )     const;        // # elementata 

    T &  operator [ ] ( int index );   // indeksni pristup
    const T & operator [ ] ( int index ) const; 

    void resize( int newSize );     // promjena veli�ine niza;
    void reserve(int size);         // rezervira kapacitet=size
    void push_back(const T& t);     // dodaj na kraj niza
    void pop_back();                // odstrani zadnji element
    void clear();                   // size == 0, kapacitet nepromijenjen
                                                
  private:

    int  m_size;                    // broj elemenata u nizu
    int  m_capacity;                // maks. kapacitet niza
    T * m_arr;                      // pok. stvarne memorije niza
};

#include "tvector_impl.h"
#endif
