#include <iostream>


class Bitset{
    private:
     unsigned int size;
     int* v;
    public:
     Bitset(int size) : size(size){
        v = new int[(size + 31 ) / 32];
        for (int i = 0; i < (size + 31) / 32; i++) {
            v[i] = 0;
        }
     }
     void set(int position){
       int index = position / 32;
       int pos = position % 32;
       v[index] |= (1 << pos);
     }

     void reset(int position){
        int index = position / 32;
       int pos = position % 32;
       v[index] &= ~(1 << pos);
     }

     void print() {
          for (int i = (size + 31) / 32 - 1; i >= 0; i--) {
            for (int j = 31; j >= 0; j--) {
                int bit = (v[i] >> j) & 1;
                std::cout << bit;
            }
        }
    }

     ~Bitset(){
        delete[] v;
     }
};


int main()
{
    Bitset bitset(32);  
    bitset.set(4);
    bitset.set(25);
    bitset.set(5);
    bitset.reset(4);
    bitset.print();
    return 0;

}