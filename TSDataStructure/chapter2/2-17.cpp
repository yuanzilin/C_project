#include <stdio.h>
#include <string.h>
#define size 20

using namespace std;

class String{
    private:
        char a[size];
    public:
        String(char a[]){
            strcpy(this->a,a);
        }
        int operator < (const String& s){
            int result=strcmp(this->a,s.a);
            if(result>0){
                return false;
            }
            if(result==0){
                return false;
            }
            if(result<0){
                return true;
            }
        }
};

int main(){
    String a = String("123");
    String b = String("234");
    printf("%d",b<b);
}