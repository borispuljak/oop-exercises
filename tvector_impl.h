// *******************************************************************
//  tvector klasa - podskup standardne C++ klase vector class
// *******************************************************************

#include <cstdlib>
#include <iostream>
using namespace std;

template <class T>
tvector<T>::tvector()
//POST: Kapacitet vektora == 0 elemenata 
    : m_size(0),  m_capacity(0),  m_arr(0)
{ }

template <class T>
tvector<T>::tvector(int size)
//     PRED:: size >= 0
//     POST: kapacitet/velièina vektora == size 
   : m_size(size),  m_capacity(size), m_arr(new T[size])
{  }

template <class T>
tvector<T>::tvector(int size, const T & fillValue)
//     PRED:: size >= 0
//     POST: Kapacitet/velièina vektora == size, svi elementi se iniciraju
//                    na fillValue nakon operacija konstruktora
    : m_size(size), m_capacity(size), m_arr(new T[size])
{
    for(int k = 0; k < size; k++)
            m_arr[k] = fillValue;
}

template <class T>
tvector<T>::tvector(const tvector<T> & vec)
//     Opis: kopirni konstruktor
//     POST: vector je  kopija od vec
    : m_size(vec.size()),
      m_capacity(vec.capacity()),
      m_arr(new T[m_capacity])
{
    for(int k = 0; k < m_size; k++)
        m_arr[k] = vec.m_arr[k];
}

template <class T>
tvector<T>::~tvector ()
// destruktor
{
    delete [] m_arr;
    m_arr = 0;       // assure
}

template <class T>
const tvector<T> &
tvector<T>::operator = (const tvector<T> & rhs)
//     POST: pridjela vrijednosti od rhs;
//           ako se razlikuju velièine ova dva vektora
//           vrši se promjena velièine na rhs.size()
{
    if (this != &rhs)                           // don't assign to self!
    {
        delete [] m_arr;                       // get rid of old storage
        m_capacity = rhs.capacity();
        m_size =     rhs.size();
        m_arr = new T [m_capacity];         // allocate new storage
        for(int k=0; k < m_size; k++)
            m_arr[k] = rhs.m_arr[k];
    }
    return *this;                               // permit a = b = c = d
}

template <class T>
int tvector<T>::capacity() const
//     POST: vraæa broj æelija alociranih za vektor 
{
    return m_capacity;
}

template <class T>
int tvector<T>::size() const
{
    return m_size;
}


template <class T>
void tvector<T>::push_back(const T& t)
//  POST: umeæe element t na poziciji size()
//        ako je size>= capacity dvostruko poveæava kapacitet
{
    if (m_size >= m_capacity)
    {
        reserve(m_capacity == 0 ? 2 : 2*m_capacity);
    }
    m_arr[m_size] = t;
    m_size++;
}

template <class T>
void tvector<T>::pop_back()
// POST: odstranjuje element s pozicije size(), smanuje velièinu za 1 
{
    if (m_size > 0)
    {
        m_size--;
    } 
}


template <class T>
T & tvector<T>::operator [] (int k)
//     Opis: Dobava k-tog elementa, uz kontrolu indeksa 
//     PRED: 0 <= k < capacity()
//     POST: vraæa k-ti element
{

    if (k < 0 || m_capacity <= k)
    {
        cerr << "Nedozvoljen index: " << k << " max index = ";
        cerr << (m_size-1) << endl;
        exit(1);
    }
    return m_arr[k];
}

template <class T>
const T & tvector<T>::operator [] (int k) const
// vraæa const reference 
{
    if (k < 0 || m_capacity <= k)
    {
        cerr << "Nedozvoljen index: " << k << " max index = ";
        cerr << (m_size-1) << endl;
        exit(1);
    }
    return m_arr[k];
}

template <class T>
void tvector<T>::resize(int newSize)
//     Opis:  promjena velièine vektora u newSize
//     PRED:  newSize >= 0, kapacitet je capacity, a velièina je size()
//     POST:  1. size() == newSize; Ako je newSize > size() tada i capacity=newSize
//             inaèe se kapacitet ne mijenja
//            2. za 0 <= k <= min(size(), newSize), vector[k]
//           je kopija originala; ostali elementi se iniciraju
//           pomoæu predodreðenog T konstruktora
//           Nota: ako je newSize < size(), gube se neki elementi
{    
    if (newSize < m_size)
    {
        m_size = newSize;   // capacity doesn't "shrink"
        return;
    }
         // alociraj novu mem.  i kopiraj elemente 

    int k;
    T * newArr = new T[newSize];
    for(k=0; k < m_size; k++)
    {
        newArr[k] = m_arr[k];
    }
    delete [] m_arr;                      // deealociraj staru memoriju
    m_capacity = m_size = newSize;         // ažuriraj capacity/size
    m_arr = newArr;
}

template <class T>
void tvector<T>::reserve(int size)
{
    // punt to resize in current implementation
    
    int oldSize = m_size;
    if (size > m_capacity)
    {
        resize(size);
    }
    m_size = oldSize;
}

template <class T>
void tvector<T>::clear()
{
    m_size = 0;
}
