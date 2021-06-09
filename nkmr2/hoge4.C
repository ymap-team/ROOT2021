#include "TH1.h"
int main(){
  TH1D *h = new TH1D("h","h",10,0,10);
  h->Fill(5);
  h->Draw();
}
