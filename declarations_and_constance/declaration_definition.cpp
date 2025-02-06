//2.7 2:
char ch;
int count = 2;
char* name = "Aleh";
struct complex {float x, y;};
complex cvar;
extern complex sqrt(complex p) { int a = p.x*p.y;};
extern int error_number = -1;
typedef complex point;
float read(complex* p) {return p->y;}
const double pi = 3.141592;
struct user {char name;};
template<class T> int abs(T a) {return a<0 ? -a : a;}
enum beer {Carlsberg, Tuborg, Thor};

int count;
float read(complex*);


//2.7 3:
char* n;
int numbers[10];
int* t = numbers;
int (&num)[10] = numbers; 
char* lines[10];
char** nPointer = &n;
const int sol = 235;
const int& ar = sol; 
const int* psol = &sol;


int main(){

}