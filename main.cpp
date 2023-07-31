#include <iostream>


class Bitset{
    private:
     unsigned int size;
     int* v;
    public:
     Bitset(int size) : size(size){
        v = new int[(size + (sizeof(int) * 8 - 1) ) / (sizeof(int) * 8)];
        for (int i = 0; i < (size + 31) / 32; i++) {
            v[i] = 0;
        }
     }
     void set(int position){
       int index = position / (sizeof(int) * 8);
       int pos = position % (sizeof(int) * 8);
       v[index] |= (1 << pos);
     }

     void reset(int position){
        int index = position / (sizeof(int) * 8);
       int pos = position % (sizeof(int) * 8);
       v[index] &= ~(1 << pos);
     }

     void print() {
          for (int i = (size + (sizeof(int) * 8) - 1) / (sizeof(int) * 8) - 1; i >= 0; i--) {
            for (int j = (sizeof(int) * 8) - 1; j >= 0; j--) {
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