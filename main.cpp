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

      void flip() {
        for (int i = 0; i < (size + (sizeof(int) * 8) - 1) / (sizeof(int) * 8); ++i) {
            v[i] = ~v[i];
        }
     }

      bool check() {
        for (int i = 0; i < (size + (sizeof(int) * 8) - 1) / (sizeof(int) * 8); ++i) {
          if (v[i] != -1) {
           return false;
         }
        }
       return true;
       }

      bool checkOne(){
        for (int i = 0; i < (size + (sizeof(int) * 8) - 1) / (sizeof(int) * 8); ++i) {
          if (v[i] != 0) {
           return true;
         }
        }
        return false;
      }


   int countOne() {
    int count = 0;
    for (int i = 0; i < (size + (sizeof(int) * 8) - 1) / (sizeof(int) * 8); i++) {
        int current = v[i];
        while (current != 0) {
            count += current & 1;
            current >>= 1;
        }
    }
    return count;
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
