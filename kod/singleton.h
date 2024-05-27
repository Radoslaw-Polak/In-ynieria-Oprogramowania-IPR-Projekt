#ifndef SINGLETON
#define SINGLETON

/// @brief Klasa definiująca pojedynczą instancję singletonu
class singleton {
protected:
    singleton();
public:
    /// @brief Metoda zwracająca jedyną instancję singletonu
    static singleton& getInstance();

};

#endif