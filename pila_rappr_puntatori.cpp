#ifndef PILA_PUNT
#define PILA_PUNT

# include "pila.cpp"
# include <iostream>

using namespace std;
template <class T>
class Pila_Punt : public Pila<T>
{
public:
    Pila_Punt();
    Pila_Punt(const Pila_Punt<T>&);
    ~Pila_Punt();
    void crea_pila();
    bool pila_vuota() const;
    T leggi_pila() const;
    void fuori_pila();
    void in_pila(T);

    void stampa_pila()
    {
        cout << "-> ";

        for(auto temp = top; temp != nullptr; temp = temp->getPrec())
        {
            cout << temp->getElemento();
            if (temp->getPrec() != nullptr)
                cout << ", ";
        }
        cout << "|\n";
    }

private:

    Cella<T>* top;
};

//implementazione metodi
template <class T>
Pila_Punt<T>::Pila_Punt()
{
    crea_pila();
}

template <class T>
Pila_Punt<T>::Pila_Punt(const Pila_Punt<T>& p)
{
    top = new Cella<T>;

    top->setElemento((p.top)->getElemento());

    //puntatori temporanei per scorrere
    auto temp_old = p.top;
    auto temp_new = top;

    while(temp_old->getPrec() != nullptr)
    {
        temp_old = temp_old->getPrec();

        auto new_cella = new Cella<T>;
        new_cella->setElemento(temp_old->getElemento());
        temp_new->setPrec(new_cella);

        temp_new = temp_new->getPrec();
    }

}

template <class T>
Pila_Punt<T>::~Pila_Punt()
{
    auto temp = top;

    while(top != nullptr)
    {
        top = top->getPrec();
        delete temp;
        temp = top;
    }

}

template <class T>
void Pila_Punt<T>::crea_pila()
{
    top = nullptr;
}

template <class T>
bool Pila_Punt<T>::pila_vuota() const
{
    return top == nullptr;
}

template <class T>
T Pila_Punt<T>::leggi_pila() const
{
    //check PRE
    if(pila_vuota())
        throw invalid_argument("Pila vuota\n");

    return top->getElemento();
}

template <class T>
void Pila_Punt<T>::fuori_pila()
{
    //check PRE
    if(pila_vuota())
        throw invalid_argument("Pila vuota\n");

    auto temp = top;

    top = top->getPrec();

    delete temp;
}

template <class T>
void Pila_Punt<T>::in_pila(T new_elem)
{
    auto new_cella = new Cella<T>;

    new_cella->setElemento(new_elem);
    new_cella->setPrec(top);
    top = new_cella;
}

#endif
