#ifndef TDALISTAINVERTIDA_H
#define TDALISTAINVERTIDA_H


class TdaListaInvertida
{
private:
    int key;
    int pos;
public:
    TdaListaInvertida();
    int getKey() const;
    void setKey(int value);
    int getPos() const;
    void setPos(int value);
};

#endif // TDALISTAINVERTIDA_H
