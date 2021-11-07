#ifndef PILA_ASTRACT
#define PILA_ASTRACT
# include "cella.cpp"
template<class T>
class Pila
{
public:
    virtual void crea_pila() = 0;
    virtual bool pila_vuota() const = 0;
    virtual T leggi_pila() const = 0;
    virtual void fuori_pila() = 0;
    virtual void in_pila(T) = 0;
};

#endif