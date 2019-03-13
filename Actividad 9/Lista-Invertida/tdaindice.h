#ifndef TDAINDICE_H
#define TDAINDICE_H


class TdaIndice
{
private:
    int key;
    long long pos;
public:
    TdaIndice();
    int getKey() const;
    void setKey(int value);
    long long getPos() const;
    void setPos(long long value);
};

#endif // TDAINDICE_H
