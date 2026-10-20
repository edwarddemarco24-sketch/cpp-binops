#include <iostream>
#include <iterator>
#include <fstream>
#include <stdexcept> 
using namespace std;

class BinOp{

private:
double num1;
char op;
double num2;

public:
void setNum1(double n){
num1 = n;

};
void setNum2(double n){
num2 = n;

};
void setOp(char o){
op = o;

};

double getNum1(){
return num1;

};
double getNum2(){
return num2;

};
char getOp(){
return op;

};


};

double evaluate(BinOp b){
if (b.getOp()=='+'){
return b.getNum1()+b.getNum2();

}
else if (b.getOp()=='-'){
return b.getNum1()-b.getNum2();

}
else if (b.getOp()=='*'){
return b.getNum1()*b.getNum2();}

else if (b.getOp()=='/'){
    if (b.getNum2()==0){
    throw runtime_error("Division by zero!");

    }
return b.getNum1()/b.getNum2();}

else {
throw runtime_error("Wrong shithead");};

    
}
int main(){
int i=0;    
int j=0;
double what;


BinOp* Three = new BinOp[3];
for (i=0;i<3;i++){
cin>>what;
Three[i].setNum(what);
cin>>Three[i].op;
cin>>Three[i].num2;
}


 ofstream myfile;
  myfile.open ("results.txt");
  for (j=0;j<3;j++){
  
    try {  
  
        myfile << evaluate(Three[j])<<endl;
  
    } 
    catch(const exception& e) {
    cerr<<e.what()<<endl;

  } 
  myfile.close();
delete[] Three;
return 0;  
}





