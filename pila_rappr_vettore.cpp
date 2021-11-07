#ifndef PILA_VETT
#define PILA_VETT
# include "pila.cpp"
# include <iostream>

using namespace std;
template <class T>
class Pila_Vett : public Pila<T>
{
public:
    Pila_Vett();
    Pila_Vett(const Pila_Vett<T>&);
    ~Pila_Vett();
    void crea_pila();
    bool pila_vuota() const;
    T leggi_pila() const;
    void fuori_pila();
    void in_pila(T);

    void stampa_pila()
    {
        cout << "| ";

        for(int i = 0; i < top; i++)
        {
            cout << vett[i];
            if (i+1 != top)
                cout << ", ";
        }
        cout << "<-\n";
    }

private:
    int SIZE = 512;
    T* vett;
    int top;
};

//implementazione metodi

template <class T>
Pila_Vett<T>::Pila_Vett()
{
    crea_pila();
}

template <class T>
Pila_Vett<T>::Pila_Vett(const Pila_Vett<T>& p)
{
    SIZE = p.SIZE;
    top = p.top;
    vett = new T[SIZE];

    for(int i = 0; i < top; i++)
        vett[i] = p.vett[i];
}

template <class T>
Pila_Vett<T>::~Pila_Vett()
{
    delete[] vett;
}

template <class T>
void Pila_Vett<T>::crea_pila()
{
    vett = new T[SIZE];
    top = 0;
}

template <class T>
bool Pila_Vett<T>::pila_vuota() const
{
    return top == 0;
}

template <class T>
T Pila_Vett<T>::leggi_pila() const
{
    //check PRE
    if(pila_vuota())
        throw invalid_argument("Pila vuota\n");

    return vett[top - 1];
}

template <class T>
void Pila_Vett<T>::fuori_pila()
{
    //check PRE
    if(pila_vuota())
        throw invalid_argument("Pila vuota\n");

    top--;
}

template <class T>
void Pila_Vett<T>::in_pila(T new_elem)
{
    vett[top] = new_elem;
    top++;
}

#endif


